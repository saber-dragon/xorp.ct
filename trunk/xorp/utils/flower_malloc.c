/*
 * Library interposer to collect malloc/calloc/realloc statistics 
 * 
 * To compile use:  
 *     gcc -shared -fpic -o flower_malloc.so flower_malloc.c
 *
 * To run use (in BASH):
 *     LD_PRELOAD=$cwd/flower_malloc.so <your application here>
 * 
 * The results will be in ./flower_report.<prog_name>.<pid> for each
 * process invoked by current application.
 *
 * How to use it...
 *
 * Start your application as mentioned above, and send it SIGUSR2 whenever you
 * want to examine the state of the different allocation points in your
 * program.  
 * 
 * If you see that one of the tracked allocation points growing suspciously,
 * create a file called flower_limits.cfg, with the same format a the report
 * file generated by flower_malloc.  When a SIGUSR2 signal is sent to
 * flower_malloc, it checks for such a file, and if found, it will load the
 * limits specified therein for 'allocs' and 'total size' (the other fields are
 * ignored).  When any tracker exceeds those limits, the program will abort.
 * For instance, if your flower_report looks like this:
 *

    ***********************************************
    allocs/watermark  total size/watermark avg size  tracker_id   
    0/120                0/252000         2100           3bab4           
    300/300            90000/90000         300           3d55c +        
    4/5             280000/350000        70000           3d7ac +          
    3/3              20480/20480          6826           4d3a9           

 * and you are worried about the allocation tracked by tracker_id 3d55c, you
 * can edit the columns 'allocs' and/or 'total size' on the file to be:

    ***********************************************
    allocs/watermark  total size/watermark avg size   tracker_id   
    200/300            80000/90000           300          3d55c +         
 *                
 * and save it as flower_limits.cfg.  You must remove the trackers you are not
 * interested on.  The next time you run your program, it will abort when there
 * are 200 outstanding allocations or 80 kbytes from that point in your
 * program.  If the limits you provide have already been exceeded by the time
 * you send the SIGUSR2 signal, flower_malloc will abort the next time an
 * allocation happens from the execution point identified by the tracker.
 *
 *
 * Sending a SIGUSR2 will also force flower_malloc to read your
 * limits configuration file, so you will not need to restart your application.
 * 
 * SIGUSR1 can be used to reset all trackers.
 */

#include "config.h"
#ifdef HOST_OS_FREEBSD   

#include <dlfcn.h>
#include <memory.h>
#include <assert.h>
#ifdef APPL_IS_MULTITHREADED
#include <thread.h>
#endif				/* APPL_IS_MULTITHREADED */
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define BACKTRACE_DEPTH 4
#define HASH_TABLE_SIZE 343051  /* prime, max 31 bits */
#define ADMIN_DATA_SIZE 2 * sizeof(uint32_t)

typedef struct alloc_tracker {
    uint32_t count;
    uint32_t max_count;
    uint32_t last_read_max;
    uint32_t total_size;
    uint32_t watermark;
} alloc_tracker_t;

typedef struct limit_tracker {
    uint32_t  enabled;
    uint32_t count;
    uint32_t total_size;
} limit_tracker_t;


static FILE *output = NULL;
static int pid;
static char path[64] = "uninitialized";
static alloc_tracker_t tracker_table[HASH_TABLE_SIZE];
static limit_tracker_t limits_table[HASH_TABLE_SIZE];
static int32_t no_tracking;

/* prototypes */
static uint32_t within_limits (uint32_t trk_idx);
static void init_flower_malloc(void);

/***************************************************************************
 * print_data - dumps the state of the alloc tracking table
 *
 */
static void 
print_data(void)
{
    int i;
    char growing[2] = " ";

    no_tracking = 1; /* prevent mallocs in fprintf from spoiling our report */

    fprintf(output, "***********************************************\n");
    fprintf(output, "allocs/watermark  total size/watermark");
    fprintf(output, "     avg size  tracker_id [+]\n");
    for (i=0; i < HASH_TABLE_SIZE; i++)
	if (tracker_table[i].watermark) {
	    fprintf(output, "%8u/%-8u  %10u/%-10u ",
		tracker_table[i].count, tracker_table[i].max_count,
		tracker_table[i].total_size, tracker_table[i].watermark);
	    if (tracker_table[i].count)
		fprintf(output, "%8u ", 
		tracker_table[i].total_size / tracker_table[i].count);
	    else /* use watermark to determine avg size */
		fprintf(output, "%8u ", 
		tracker_table[i].watermark / tracker_table[i].max_count);
	    if (tracker_table[i].max_count > tracker_table[i].last_read_max) {
		if (tracker_table[i].last_read_max) growing[0] = '+';
		tracker_table[i].last_read_max = tracker_table[i].max_count;
	    } else growing[0] = ' ';
	    fprintf(output, "%8x %s\n", i, growing);
	}
    fflush(output);  /* untentionally leaving file open */

    no_tracking = 0;
}

/***************************************************************************
 * read_config - read flower_malloc config file
 *
 */
static void
read_config(void)
{
    unsigned long trk_idx, count, max_count, total_size, watermark, avg_size;
    int assig;
    FILE *config;
    #define MAX_CFG_LINE_WIDTH 80
    char ignored[MAX_CFG_LINE_WIDTH];


    config = fopen("./flower_limits.cfg","r");

    if (!config) return;

    no_tracking = 1; /* prevent mallocs in fprintf from spoiling our report */

    do {
	assig = fscanf(config, "%8lu/%8lu %10lu/%10lu %8lu %8lx %*[+ ]\n", 
	    &count, &max_count, &total_size, &watermark, &avg_size, &trk_idx);
	if (assig == 6) {
	    fprintf(output, "Abort if tracker %8lx exceeds %8lu outst "
		"allocs or %10lu bytes\n", trk_idx, count, total_size);
	    fflush(stdout);
	    limits_table[trk_idx].enabled = 1;
	    limits_table[trk_idx].count = count;
	    limits_table[trk_idx].total_size = total_size;
	} else {
	    fgets(ignored, MAX_CFG_LINE_WIDTH, config);
	}
	
    } while (assig != EOF);
    fclose(config);

    no_tracking = 0;
}

/***************************************************************************
 * sigusr1_handler - handler for the SIGUSR1 signal
 *
 * This signal is used to reset the tracker and limits tables
 */
static void 
sigusr1_handler(int unused)
{
    uint32_t i;
    unused = unused;

    for (i=0; i < HASH_TABLE_SIZE; i++) {
	tracker_table[i].count = 0;
	tracker_table[i].max_count = 0;
	tracker_table[i].last_read_max = 0;
	tracker_table[i].total_size = 0;
	tracker_table[i].watermark = 0;
	limits_table[i].enabled = 0;
	limits_table[i].count = 0;
	limits_table[i].total_size = 0;
    }
	
}

/***************************************************************************
 * sigusr2_handler - handler for the SIGUSR2 signal
 *
 * This signal is used to dump the current state of the alloc tracking table to
 * the output file.
 */
static void 
sigusr2_handler(int unused)
{
    unused = unused;
    read_config();
    print_data();
}

/***************************************************************************
 * within_limits - check if a tracker is within its configured limits
 *
 * Return zero if not
 */ 
static uint32_t
within_limits (uint32_t trk_idx)
{
    if (!limits_table[trk_idx].enabled) return 1;

    return (tracker_table[trk_idx].count <= limits_table[trk_idx].count &&
	tracker_table[trk_idx].total_size <= limits_table[trk_idx].total_size);
}

/***************************************************************************
 * hash - calculate hash value based on backtrace stack
 *
 * This will be used to assign the same tracker to all the allocations that are
 * made from the same point in a program.
 */ 
static uint32_t
hash (void ** addr_array, size_t depth)
{
    uint32_t i;
    uint32_t hash_value = 0;
    for (i=0; i<depth; i++)
	hash_value ^= ((uint32_t) addr_array[i] << (i+1));
    hash_value %= HASH_TABLE_SIZE;
    return hash_value;
}

/***************************************************************************
 * get_backtrace - copy the current stack backtrace onto ret_addr array
 *
 * This function uses gcc built-in function __builtin_return_address to fetch
 * the return addresses from the stack.  Since this function only accepts
 * constant integers as arguments, we must use ugly preprocessor tricks to
 * allow for configurable backtrace depths.
 */

static void 
get_backtrace(void ** ret_addr)
{
    ret_addr[0] = __builtin_return_address(1);    
#if BACKTRACE_DEPTH > 1
    ret_addr[1] = __builtin_return_address(2);    
#if BACKTRACE_DEPTH > 2
    ret_addr[2] = __builtin_return_address(3);    
#if BACKTRACE_DEPTH > 3
    ret_addr[3] = __builtin_return_address(4);    
#if BACKTRACE_DEPTH > 4
    ret_addr[4] = __builtin_return_address(5);    
#if BACKTRACE_DEPTH > 5
    ret_addr[5] = __builtin_return_address(6);    
#if BACKTRACE_DEPTH > 6
    ret_addr[6] = __builtin_return_address(7);    
#if BACKTRACE_DEPTH > 7
    ret_addr[7] = __builtin_return_address(8);    
#if BACKTRACE_DEPTH > 8
    ret_addr[8] = __builtin_return_address(9);    
#if BACKTRACE_DEPTH > 9
    ret_addr[9] = __builtin_return_address(10);    
#if BACKTRACE_DEPTH > 10
#error "maximum supported BACKTRACE_DEPTH is 10"
#endif /*  1 */
#endif /*  2 */
#endif /*  3 */
#endif /*  4 */
#endif /*  5 */
#endif /*  6 */
#endif /*  7 */
#endif /*  8 */
#endif /*  9 */
#endif /* 10 */
}

static void
init_flower_malloc()
{
    char procbuf[32];
    char procname[20];
    char prog_name[32];
    int fd;
    static int initialized = 0;

    if (initialized) return;

    /*
     * Get current executable's name using proc(4) interface
     */
    pid = (int)getpid ();
    (void)sprintf (procbuf, "/proc/%ld/status", (long)pid);
    if ((fd = open (procbuf, O_RDONLY)) != -1) {
	if (read (fd, procname, sizeof (procname)) == sizeof (procname)) {
	    strtok (procname, " ");
	    sprintf (prog_name, "%s.%d", procname, pid);
	} else
	    sprintf (prog_name, "%s.%d", "unknown", pid);
    } else
	sprintf (prog_name, "%s.%d", "unknown", pid);
    sprintf (path, "%s%s", "./flower_report.",
	prog_name);

    if (!output) {
	output = fopen (path, "a");
	if (!output) {
	    fprintf(stderr, "unable to write to file %s\n", path);
	    /* invoke original exit(), not the one we implement here */
	    (*((void (*) (int))dlsym (RTLD_NEXT, "exit"))) (-1);
	}
    }

    fprintf(output, "flower_malloc report for program %s\n\n", prog_name);
    fflush(output);

    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);
    initialized = 1;
    
    return;
}
 

/***************************************************************************
 * track_alloc - track a new allocation
 *
 * This function updates the allocation tracker for this new allocation, and
 * marks the new memory block with the tracker index, and the size of the
 * requested memory block.  Those two values are stored in the allocated memory
 * block, this is why the function requires ptr to point to a fresh memory
 * block of size req_size + 8 bytes.  
 * 
 * The function returns a pointer to the memory immediately following the marks
 * which should be returned to the user.
 *
 *     +---------+---------+---------+---------+---------+----
 *     | trk_idx | size    |  (memory block of size req_size) ...
 *     +---------+---------+---------+---------+---------+----
 *         ^                   ^
 *         |                   |
 *        ptr           returned ptr 
 */
static void *
track_alloc (void *ptr, size_t req_size)
{
    uint32_t trk_idx; 
    void * ret_addr[BACKTRACE_DEPTH];

    if (no_tracking) return ptr;

    get_backtrace(ret_addr);
    
    trk_idx = hash(ret_addr,BACKTRACE_DEPTH);

    tracker_table[trk_idx].count++;
    tracker_table[trk_idx].total_size += req_size;
    if (tracker_table[trk_idx].total_size > tracker_table[trk_idx].watermark) 
	tracker_table[trk_idx].watermark = tracker_table[trk_idx].total_size;
    if (tracker_table[trk_idx].count >  tracker_table[trk_idx].max_count) 
	tracker_table[trk_idx].max_count = tracker_table[trk_idx].count;

    if (!within_limits(trk_idx)) {
	fprintf(output,"\nTracker %x exceeding limits - ABORTING\n", trk_idx);
	print_data();
	abort();
    }

    * (uint32_t*) ptr = trk_idx; 
    (uint32_t) ptr += sizeof(uint32_t);
    * (uint32_t*) ptr = req_size;
    (uint32_t) ptr += sizeof(uint32_t);
    return ptr;
}

/***************************************************************************
 * track_free - track a free
 *
 * This function updates the allocation tracker for this free operation.
 * 
 * The function takes the pointer to the memory passed by the user, and returns
 * the pointer that is to be freed
 *
 *     +---------+---------+---------+---------+---------+----
 *     | trk_idx | size    |  (memory block of size req_size) ...
 *     +---------+---------+---------+---------+---------+----
 *         ^                   ^
 *         |                   |
 *    returned ptr            ptr
 */
static void *
track_free (void *ptr)
{
    uint32_t trk_idx, req_size; 

    if (no_tracking) return ptr;

    (uint32_t) ptr -= sizeof(uint32_t);
    req_size = * (uint32_t*) ptr;
    (uint32_t) ptr -= sizeof(uint32_t);
    trk_idx = * (uint32_t*) ptr;

    if (tracker_table[trk_idx].count) tracker_table[trk_idx].count--; 
    if (tracker_table[trk_idx].total_size >= req_size)
	tracker_table[trk_idx].total_size -= req_size;

    return ptr;
}


void exit (int status)
{
    /*
     * (Re)open the file here since the shell closes all file descriptors
     * before calling exit()
     */
    output = fopen (path, "a");
    if (output)
	print_data();
    (*((void (*) (int))dlsym (RTLD_NEXT, "exit"))) (status);

    abort();    /* should never get here */
}

void *
malloc (size_t size)
{
    static void *(*func) (size_t);
    void *ret;

    if (!func) {
	func = (void *(*) (size_t))dlsym (RTLD_NEXT, "malloc");
	init_flower_malloc();
    }
    ret = func (size + ADMIN_DATA_SIZE);

    return (track_alloc (ret, size));
}

#if ORIGINAL_CALLOC_DOES_NOT_CALL_MALLOC
void *
calloc (size_t nelem, size_t elsize)
{
    static void *(*func) (size_t, size_t);
    void *ret;
    int i;

    if (!func) {
	func = (void *(*) (size_t, size_t))dlsym (RTLD_NEXT, "calloc");
	init_flower_malloc();
    }

    ret = func (elsize * nelem + ADMIN_DATA_SIZE, 1);

    return (track_alloc(ret, elsize * nelem));
}
#endif

void *
realloc (void *ptr, size_t size)
{
    static void *(*func) (void *, size_t);
    void *ret;

    if (!func) {
	func = (void *(*) (void *, size_t))dlsym (RTLD_NEXT, "realloc");
	init_flower_malloc();
    }

    ret = func (track_free(ptr), size + ADMIN_DATA_SIZE);

    return (track_alloc(ret, size));

}

void
free (void *ptr)
{
    static void (*func) (void *);

    if (!func) {
        func = (void (*) (void *))dlsym (RTLD_NEXT, "free");
	init_flower_malloc();
    }

    func (track_free(ptr));

    return;
}

#endif /* HOST_OS_FREEBSD */

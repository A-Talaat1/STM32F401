#ifndef RUNNABLES_H_ // Header guard to prevent double inclusion
#define RUNNABLES_H_

#define SCHED_PERODICITY_MS 1UL // Schedule Periodicity

// Enumeration of available runnables
typedef enum
{
    LCD,   // LCD task
    fun1,  // Function 1 task
    
    _Runnables_Max, // Maximum number of runnables
} Runnables_t;

#endif /* RUNNABLES_H_ */ // End of header guard and file

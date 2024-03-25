#ifndef SCHEDULER_H_ // Header guard to prevent double inclusion
#define SCHEDULER_H_

#include "SVC/Scheduler/Runnables.h" // Including Runnables header file
#include "../../../lib/Error/Error.h" // Including error handling library
#include "../../../lib/StdTypes.h"    // Including standard data types library

// Function pointer type for callback function
typedef void (* CB_t) (void);

// Structure representing a runnable task
typedef struct
{
    u32 Periodicity;    // Periodicity of the task
    u32 First_Delay_mS; // Initial delay before the task starts
    CB_t CB;            // Callback function to be executed by the task
} Runnable_t;

/**
 * @brief Start the scheduler.
 * 
 * @return Error_t Error status.
 */
Error_t Sched_Start(void);

#endif /* SCHEDULER_H_ */ // End of header guard and file

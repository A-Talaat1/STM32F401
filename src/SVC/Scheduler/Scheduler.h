#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "SVC/Scheduler/Runnables.h"
#include "../../../lib/Error/Error.h"
#include "../../../lib/StdTypes.h"

typedef void (* CB_t) (void);

typedef struct
{
    
    u32 Periodicity;
    u32 First_Delay_mS;
    CB_t CB;

}Runnable_t;

Error_t Sched_Start(void);

#endif /*SCHEDULER_H_*/
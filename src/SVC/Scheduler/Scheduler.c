#include "SVC/Scheduler/Scheduler.h"
#include "MCAL/SYSTICK/SYSTICK.h"

typedef struct
{
    Runnable_t Runnable;
    u32 Remaining_Time_mS;
}Runnable_Info_t;

extern Runnable_t Runnables [_Runnables_Max];

Runnable_Info_t Runnables_Info [_Runnables_Max];

volatile static u32 Pending_Ticks = 1;

/*Static APIs*/
static void Sched (void);
static Error_t Sched_Init(void);
static void Sched_Ticks_CB(void);

Error_t Sched_Start(void)
{
    Error_t Error_State = ERROR_Ok;

    Error_State = Sched_Init();
    while (1)
    {
    if (Pending_Ticks)
    {
        --Pending_Ticks;
        Sched();
    }
    }
    
    return Error_State;
} 

static void Sched (void)
{
    u32 Priority = 0;

    for (Priority = 0; Priority < _Runnables_Max; ++Priority)
    {
        if (Runnables_Info[Priority].Runnable.CB && Runnables_Info[Priority].Remaining_Time_mS == 0)
        {
            Runnables_Info[Priority].Runnable.CB();
            Runnables_Info[Priority].Remaining_Time_mS = Runnables_Info[Priority].Runnable.Periodicity;
        }
        Runnables_Info[Priority].Remaining_Time_mS -= SCHED_PERODICITY_MS;
    }
}

static void Sched_Ticks_CB(void)
{
    ++Pending_Ticks;
}

static Error_t Sched_Init(void)
{
    u32 Priority = 0;
    Error_t Error_State = ERROR_Ok;
    
    for (Priority = 0; Priority < _Runnables_Max; ++Priority)
    {
        Runnables_Info[Priority].Runnable = Runnables[Priority];
        Runnables_Info[Priority].Remaining_Time_mS = Runnables[Priority].First_Delay_mS;
    }

    Error_State = SYSTICK_Set_Time_mS(SCHED_PERODICITY_MS);
    Error_State = SYSTICK_Set_CB(Sched_Ticks_CB);

    return Error_State;
}
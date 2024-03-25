#include "Runnables.h"
#include "SVC/Scheduler/Scheduler.h"

extern void LCD_Task(void);
// extern void func(void);
// extern void func2(void);


const Runnable_t Runnables [_Runnables_Max] = 
{
    [LCD] = 
    {
        .Periodicity = 1UL,
        .First_Delay_mS = 0,
        .CB = LCD_Task,
    },
    [fun1] = 
    {
        .Periodicity = 1000UL,
        .First_Delay_mS = 0,
        //.CB = func,
    },

};
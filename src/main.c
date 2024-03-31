#include "MCAL/RCC/RCC.h"
#include "MCAL/GPIO/GPIO.h"
#include "MCAL/SYSTICK/SYSTICK.h"
#include "HAL/LED/LED.h"
#include "SVC/Scheduler/Scheduler.h"
#include "HAL/Switch/SWITCH.h"
#include "HAL/LCD/LCD.h"
#include "../lib/StdTypes.h"


int main(int argc, char const *argv[])
{
    RCC_Enable_Clock(RCC_ENABLE_SYSTEM_CLOCK_HSI);
    RCC_Set_Main_System_Clock(RCC_SYSTEM_CLOCK_HSI);
    RCC_Enable_AHB1_Peripheral_Clock(PERIPHERAL_AHB1_GPIOA);
    RCC_Enable_AHB1_Peripheral_Clock(PERIPHERAL_AHB1_GPIOB);
    
    Sched_Start();
    
    
    return 0;
}

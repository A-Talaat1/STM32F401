#include "MCAL/RCC/RCC.h"
#include "MCAL/GPIO/GPIO.h"
#include "MCAL/SYSTICK/SYSTICK.h"
#include "HAL/LED/LED.h"
#include "SVC/Scheduler/Scheduler.h"
#include "HAL/Switch/SWITCH.h"
#include "HAL/LCD/LCD.h"
#include "../lib/StdTypes.h"

u8 op=1,clr=1,set=2,wrt=3,time=0;
//u8 op1=1,clr1=1,set1=2,wrt1=3,time1=0;

int main(int argc, char const *argv[])
{
    RCC_Enable_Clock(RCC_ENABLE_SYSTEM_CLOCK_HSI);
    RCC_Set_Main_System_Clock(RCC_SYSTEM_CLOCK_HSI);
    RCC_Enable_AHB1_Peripheral_Clock(PERIPHERAL_AHB1_GPIOA);
    RCC_Enable_AHB1_Peripheral_Clock(PERIPHERAL_AHB1_GPIOB);
    
    Sched_Start();
    
    
    return 0;
}

void func(void)
{
    time++;
   switch (op)
   {
   case 1:
    
    if (time == 1)
    {
       LCD_Clear(LCD1);
        
    }
    else if (time == 2)
    {
        LCD_Clear(LCD2);
    }
    
    
    else
    {
        time=0;
        op=set;
    }
    
    
    break;

    case 2:
    if (time == 1)
    {
       LCD_Set_Cursor(LCD1,1,3);
        
    }
    else if (time == 2)
    {
        LCD_Set_Cursor(LCD2,1,3);
    }
    
    else
    {
        op=wrt;
        time=0;
    }
    
    
    
    break;

    case 3:
    if (time==1)
    {
       LCD_Write_String(LCD1,"Hi");
        
    }
    else if (time == 2)
    {
        /* code */
    }
    else if (time == 3)
    {
        LCD_Write_String(LCD2,"Hello");
    }
    else if (time == 4)
    {
        /* code */
    }
    else
    {
        time=0;
        op=clr;
    }
    
    break;
   
   default:
   time=0;
   op=clr;
    break;
   }
}

#include "../lib/StdTypes.h"
#include "SVC/Scheduler/Runnables.h"
#include "HAL/LED/LED.h"

u8 state = 0, prev;
u32  s=0;

typedef enum
{
    G,
    y,
    R,

}traffic_t;


void traffic(void)
{ 
    s += SCHED_PERODICITY_MS;
    
    switch (state)
    {
    case G:
        if (s == 3000)
        {

            LED_Set_State(Green,LED_ON);
            LED_Set_State(Yellow,LED_OFF);
            LED_Set_State(Red,LED_OFF);

            state = y;
            prev = G;
            s=0;
        }
        
        break;
    
    case y:
        if (s == 3000 && prev == G)
        {

            LED_Set_State(Green,LED_OFF);
            LED_Set_State(Yellow,LED_ON);
            LED_Set_State(Red,LED_OFF);

            state = R;
            //prev = y;
            s=0;
        }
        else
        if (s== 300 && prev == R)
        {
            LED_Set_State(Green,LED_OFF);
            LED_Set_State(Yellow,LED_ON);
            LED_Set_State(Red,LED_OFF);
            state = G;
            //prev = y;
            s=0;
        }
        break;

    case R:
        if (s==3000)
        {

            LED_Set_State(Green,LED_OFF);
            LED_Set_State(Yellow,LED_OFF);
            LED_Set_State(Red,LED_ON);

            state=y;
            prev=R;
            s=0;
        }
    default:
        break;
    }
}
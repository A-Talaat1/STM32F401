#include "MCAL/GPIO/GPIO.h"
#include "HAL/Switch/SWITCH.h"
#include "HAL/LED/LED.h"

u8 Counter = 0;
u8 Cur_State, Prev_State, State;

void Debounce (void)
{
    SWITCH_Get_State(SWITCH_1, &Cur_State);

    if( (Cur_State) == Prev_State )
    {
        ++Counter;
    }

    if (Counter == 5)
    {
        State = Cur_State;
        Counter = 0;
    }

    Prev_State = Cur_State;
}

void tled (void)
{

    if ( State == Switch_Pressed)
    {
       // LED_Toggle(LED_1);
    }
    else
    {
        //LED_Set_State(LED_1,LED_OFF);
    }
}
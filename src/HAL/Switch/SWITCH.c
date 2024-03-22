#include "HAL/Switch/SWITCH.h"
#include "MCAL/GPIO/GPIO.h"

extern const SWITCH_Confg_t SWITCH_Confg [SWITCH_Number];

Error_t SWITCH_Init (void)
{
    Error_t Error_state = ERROR_Ok;
    GPIO_Pin_Confg_t SWITCH;
    SWITCH.mode  = GPIO_CONFG_INPUT_PU;
    SWITCH.speed = GPIO_PIN_MID_SPEED;

    for (u8 Counter = 0; Counter < SWITCH_Number; ++Counter)
    {
        SWITCH.port = SWITCH_Confg[Counter].Port;
        SWITCH.pin  = SWITCH_Confg[Counter].Pin;
        GPIO_Init_Pin(&SWITCH);
    }
    return Error_state;
}

Error_t SWITCH_Get_State(SWITCH_Names_t SWITCH_Name, u8 *SWITCH_State)
{
    Error_t Error_State = ERROR_Ok;

    Error_State = GPIO_Get_Pin_State(SWITCH_Confg[SWITCH_Name].Port, SWITCH_Confg[SWITCH_Name].Pin, SWITCH_State);

    return Error_State;
}
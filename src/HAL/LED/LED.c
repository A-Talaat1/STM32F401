#include "HAL/LED/LED.h"
#include "MCAL/GPIO/GPIO.h"

extern LED_Confg_t LED_Confg [LED_Number];

/*Validation Nedded*/
Error_t LED_Init (void)
{
    Error_t Error_State = ERROR_Ok;
    GPIO_Pin_Confg_t led;
    led.mode  = GPIO_CONFG_OUTPUT_PP;

    for (u8 Counter = 0; Counter < LED_Number; ++Counter)
    {
        led.port = LED_Confg[Counter].Port;
        led.pin  = LED_Confg[Counter].Pin;
        Error_State = GPIO_Init_Pin(&led);
        Error_State = GPIO_Set_Pin_State(LED_Confg[Counter].Port, LED_Confg[Counter].Pin, LED_Confg[Counter].Connection ^ GPIO_PIN_ON );
    }
    
    return Error_State;
}

Error_t LED_Set_State(LED_Names_t LED_Name, u8 LED_State)
{
    Error_t Error_State = ERROR_Ok;
    Error_State = GPIO_Set_Pin_State(LED_Confg[LED_Name].Port, LED_Confg[LED_Name].Pin, (LED_Confg[LED_Name].Connection ^ LED_State) );
    return Error_State;
}

Error_t LED_Toggle(LED_Names_t LED_Name)
{
    Error_t Error_State = ERROR_Ok;
    u8 Current_State;
    GPIO_Get_Pin_State(LED_Confg[LED_Name].Port, LED_Confg[LED_Name].Pin, &Current_State);
    GPIO_Set_Pin_State(LED_Confg[LED_Name].Port, LED_Confg[LED_Name].Pin, Current_State ^ LED_ON);
    return Error_State;
}
#include "HAL/LED/LED.h"
#include "HAL/LED/LED_Confg.h"

const LED_Confg_t LED_Confg [LED_Number] = 
{
    [Green] = 
    {
        .Port = LED_PORT_A,
        .Pin  = LED_PIN_0,
        .Connection  = LED_CONNECT_FORWARD, 

    },
    [Yelllow] =
    {
        .Port = LED_PORT_B,
        .Pin  = LED_PIN_1,
        .Connection = LED_CONNECT_FORWARD,
    },
    [Red] =
    {
        .Port = LED_PORT_B,
        .Pin  = LED_PIN_2,
        .Connection = LED_CONNECT_FORWARD,
    },

};
#include "HAL/LED/LED.h" // Include LED module header file
#include "HAL/LED/LED_Confg.h" // Include LED configuration header file

// Array to hold LED configurations
const LED_Confg_t LED_Confg[LED_Number] = 
{
    [Green] = // Configuration for Green LED
    {
        .Port = LED_PORT_A, // Port A
        .Pin  = LED_PIN_0,  // Pin 0
        .Connection  = LED_CONNECT_FORWARD,  // Forward connection
    },
    [Yellow] = // Configuration for Yellow LED
    {
        .Port = LED_PORT_B, // Port B
        .Pin  = LED_PIN_1,  // Pin 1
        .Connection = LED_CONNECT_FORWARD, // Forward connection
    },
    [Red] = // Configuration for Red LED
    {
        .Port = LED_PORT_B, // Port B
        .Pin  = LED_PIN_2,  // Pin 2
        .Connection = LED_CONNECT_FORWARD, // Forward connection
    },
};

#include "HAL/Switch/SWITCH.h" // Include the switch module header file
#include "MCAL/GPIO/GPIO.h"    // Include the GPIO module header file

extern const SWITCH_Confg_t SWITCH_Confg[SWITCH_Number]; // External declaration of the switch configuration array

// Function to initialize switches
Error_t SWITCH_Init(void)
{
    Error_t Error_state = ERROR_Ok; // Variable to hold error state, initialized to no error
    GPIO_Pin_Confg_t SWITCH;        // GPIO pin configuration structure for switches

    SWITCH.mode = GPIO_CONFG_INPUT_PU; // Set the mode of the GPIO pins to input with pull-up resistor
    SWITCH.speed = GPIO_PIN_MID_SPEED; // Set the speed of the GPIO pins to medium speed

    // Loop through all switches to initialize them
    for (u8 Counter = 0; Counter < SWITCH_Number; ++Counter)
    {
        SWITCH.port = SWITCH_Confg[Counter].Port; // Set the GPIO port for the current switch
        SWITCH.pin = SWITCH_Confg[Counter].Pin;   // Set the GPIO pin for the current switch
        GPIO_Init_Pin(&SWITCH);                   // Initialize the GPIO pin for the current switch
    }

    return Error_state; // Return the error state
}

// Function to get the state of a switch
Error_t SWITCH_Get_State(SWITCH_Names_t SWITCH_Name, u8 *SWITCH_State)
{
    Error_t Error_State = ERROR_Ok; // Variable to hold error state, initialized to no error

    // Get the state of the GPIO pin corresponding to the specified switch
    Error_State = GPIO_Get_Pin_State(SWITCH_Confg[SWITCH_Name].Port, SWITCH_Confg[SWITCH_Name].Pin, SWITCH_State);

    return Error_State; // Return the error state
}

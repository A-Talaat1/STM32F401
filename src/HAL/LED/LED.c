#include "HAL/LED/LED.h" // Include LED module header file
#include "MCAL/GPIO/GPIO.h" // Include GPIO module header file

extern LED_Confg_t LED_Confg[LED_Number]; // External declaration of LED configuration array

// Function to initialize LEDs
/*Validation Needed*/
Error_t LED_Init(void)
{
    Error_t Error_State = ERROR_Ok; // Variable to hold error state, initialized to no error
    GPIO_Pin_Confg_t led; // GPIO pin configuration structure
    led.mode = GPIO_CONFG_OUTPUT_PP; // Set GPIO pin mode to output push-pull

    // Loop through each LED in the configuration array
    for (u8 Counter = 0; Counter < LED_Number; ++Counter)
    {
        led.port = LED_Confg[Counter].Port; // Set GPIO port from LED configuration
        led.pin = LED_Confg[Counter].Pin;   // Set GPIO pin from LED configuration

        // Initialize GPIO pin with the specified configuration
        Error_State = GPIO_Init_Pin(&led);

        // Set initial state of the LED based on its configuration (considering connection type)
        Error_State = GPIO_Set_Pin_State(LED_Confg[Counter].Port, LED_Confg[Counter].Pin, LED_Confg[Counter].Connection ^ GPIO_PIN_ON);
    }

    return Error_State; // Return the error state after LED initialization
}

// Function to set the state of a specific LED
Error_t LED_Set_State(LED_Names_t LED_Name, u8 LED_State)
{
    Error_t Error_State = ERROR_Ok; // Variable to hold error state, initialized to no error

    // Set the state of the LED based on its configuration (considering connection type)
    Error_State = GPIO_Set_Pin_State(LED_Confg[LED_Name].Port, LED_Confg[LED_Name].Pin, (LED_Confg[LED_Name].Connection ^ LED_State));

    return Error_State; // Return the error state after setting LED state
}

// Function to toggle the state of a specific LED
Error_t LED_Toggle(LED_Names_t LED_Name)
{
    Error_t Error_State = ERROR_Ok; // Variable to hold error state, initialized to no error
    u8 Current_State; // Variable to hold the current state of the LED

    // Get the current state of the LED
    GPIO_Get_Pin_State(LED_Confg[LED_Name].Port, LED_Confg[LED_Name].Pin, &Current_State);

    // Toggle the state of the LED
    GPIO_Set_Pin_State(LED_Confg[LED_Name].Port, LED_Confg[LED_Name].Pin, Current_State ^ LED_ON);

    return Error_State; // Return the error state after toggling LED state
}

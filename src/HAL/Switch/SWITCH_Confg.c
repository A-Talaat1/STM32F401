#include "HAL/Switch/SWITCH.h" // Include the switch module header file

// Define the configuration array for switches
const SWITCH_Confg_t SWITCH_Confg[SWITCH_Number] = 
{
    [SWITCH_1] = // Configuration for SWITCH_1
    {
        .Port = SWITCH_PORT_B, // Port B is used for SWITCH_1
        .Pin  = SWITCH_PIN_1,  // Pin 1 is used for SWITCH_1
    },
}; // End of configuration array


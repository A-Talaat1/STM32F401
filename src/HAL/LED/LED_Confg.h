#ifndef LED_CONFG_H_ // Header guard to prevent multiple inclusion of the header file
#define LED_CONFG_H_

#include "../../lib/StdTypes.h" // Include standard types header file
#include "../../lib/Error/Error.h" // Include error handling header file

// Enumeration defining LED names/types
typedef enum {
    Green,     // Green LED
    Yellow,   // Yellow LED 
    Red,       // Red LED

    LED_Number, // Total number of LEDs
} LED_Names_t;

#endif // End of header guard and file

#ifndef LED_H_ // Header guard to prevent multiple inclusion of the header file
#define LED_H_

#include "../../lib/StdTypes.h" // Include standard types header file
#include "../../lib/Error/Error.h" // Include error handling header file
#include "HAL/LED/LED_Confg.h" // Include LED configuration header file

// Define ports for the LEDs
#define LED_PORT_A 0x00000000 // Port A
#define LED_PORT_B 0x00000001 // Port B
#define LED_PORT_C 0x00000002 // Port C

// Define pins for the LEDs
#define LED_PIN_0  0x00000000 // Pin 0
#define LED_PIN_1  0x00000001 // Pin 1
#define LED_PIN_2  0x00000002 // Pin 2
#define LED_PIN_3  0x00000003 // Pin 3
#define LED_PIN_4  0x00000004 // Pin 4
#define LED_PIN_5  0x00000005 // Pin 5
#define LED_PIN_6  0x00000006 // Pin 6
#define LED_PIN_7  0x00000007 // Pin 7
#define LED_PIN_8  0x00000008 // Pin 8
#define LED_PIN_9  0x00000009 // Pin 9
#define LED_PIN_10 0x0000000A // Pin 10
#define LED_PIN_11 0x0000000B // Pin 11
#define LED_PIN_12 0x0000000C // Pin 12
#define LED_PIN_13 0x0000000D // Pin 13
#define LED_PIN_14 0x0000000E // Pin 14
#define LED_PIN_15 0x0000000F // Pin 15

// Define LED connection types
#define LED_CONNECT_REVERSE 0x00000001 // Reverse connection
#define LED_CONNECT_FORWARD 0x00000000 // Forward connection

// Define LED states
#define LED_ON  0x00000001 // LED ON state
#define LED_OFF 0x00000000 // LED OFF state

// Structure to hold LED configuration
typedef struct {
    u32 Port;         // Port to which the LED is connected
    u32 Pin;          // Pin number of the LED
    u32 Connection;   // Connection type of the LED (reverse or forward)
} LED_Confg_t;

// Function prototypes

/**
 * @brief Initialize the LED module
 * 
 * @return Error_t: Error code indicating success or failure
 */
Error_t LED_Init(void);

/**
 * @brief Set the state of a specific LED
 * 
 * @param LED_Name: Name of the LED to control
 * @param LED_State: State to set for the LED (LED_ON or LED_OFF)
 * @return Error_t: Error code indicating success or failure
 */
Error_t LED_Set_State(LED_Names_t LED_Name, u8 LED_State);

/**
 * @brief Toggle the state of a specific LED
 * 
 * @param LED_Name: Name of the LED to toggle
 * @return Error_t: Error code indicating success or failure
 */
Error_t LED_Toggle(LED_Names_t LED_Name);

#endif /* LED_H_ */ // End of header guard and file
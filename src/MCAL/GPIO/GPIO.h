#ifndef GPIO_H_
#define GPIO_H_

#include "../../../lib/Error/Error.h" // Include the error handling header file
#include "../../../lib/StdTypes.h"    // Include the standard types header file

/* PORTS */

#define GPIO_PORT_A 0x00000000 // Define GPIO port A
#define GPIO_PORT_B 0x00000001 // Define GPIO port B
#define GPIO_PORT_C 0x00000002 // Define GPIO port C

/* PINS */

#define GPIO_PIN_0  0x00000000 // Define GPIO pin 0
#define GPIO_PIN_1  0x00000001 // Define GPIO pin 1
#define GPIO_PIN_2  0x00000002 // Define GPIO pin 2
#define GPIO_PIN_3  0x00000003 // Define GPIO pin 3
#define GPIO_PIN_4  0x00000004 // Define GPIO pin 4
#define GPIO_PIN_5  0x00000005 // Define GPIO pin 5
#define GPIO_PIN_6  0x00000006 // Define GPIO pin 6
#define GPIO_PIN_7  0x00000007 // Define GPIO pin 7
#define GPIO_PIN_8  0x00000008 // Define GPIO pin 8
#define GPIO_PIN_9  0x00000009 // Define GPIO pin 9
#define GPIO_PIN_10 0x0000000A // Define GPIO pin 10
#define GPIO_PIN_11 0x0000000B // Define GPIO pin 11
#define GPIO_PIN_12 0x0000000C // Define GPIO pin 12
#define GPIO_PIN_13 0x0000000D // Define GPIO pin 13
#define GPIO_PIN_14 0x0000000E // Define GPIO pin 14
#define GPIO_PIN_15 0x0000000F // Define GPIO pin 15

/* PIN MODES */

#define GPIO_CONFG_INPUT_FLOATING 0x00000000 // Define GPIO input floating mode
#define GPIO_CONFG_INPUT_PU       0x00000001 // Define GPIO input pull-up mode
#define GPIO_CONFG_INPUT_PD       0x00000002 // Define GPIO input pull-down mode
#define GPIO_CONFG_ANALOG         0x00000003 // Define GPIO analog mode
#define GPIO_CONFG_OUTPUT_OD      0x00000004 // Define GPIO output open-drain mode
#define GPIO_CONFG_OUTPUT_OD_PU   0x00000005 // Define GPIO output open-drain with pull-up mode
#define GPIO_CONFG_OUTPUT_OD_PD   0x00000006 // Define GPIO output open-drain with pull-down mode
#define GPIO_CONFG_OUTPUT_PP      0x00000007 // Define GPIO output push-pull mode
#define GPIO_CONFG_OUTPUT_PP_PU   0x00000008 // Define GPIO output push-pull with pull-up mode
#define GPIO_CONFG_OUTPUT_PP_PD   0x00000009 // Define GPIO output push-pull with pull-down mode
#define GPIO_CONFG_AF_OD          0x0000000A // Define GPIO alternative function open-drain mode
#define GPIO_CONFG_AF_OD_PU       0x0000000B // Define GPIO alternative function open-drain with pull-up mode
#define GPIO_CONFG_AF_OD_PD       0x0000000C // Define GPIO alternative function open-drain with pull-down mode
#define GPIO_CONFG_AF_PP          0x0000000D // Define GPIO alternative function push-pull mode
#define GPIO_CONFG_AF_PP_PU       0x0000000E // Define GPIO alternative function push-pull with pull-up mode
#define GPIO_CONFG_AF_PP_PD       0x0000000F // Define GPIO alternative function push-pull with pull-down mode

/*Alternative Functions*/
#define GPIO_AF00         (0UL)
#define GPIO_AF01         (1UL)
#define GPIO_AF02         (2UL)
#define GPIO_AF03         (3UL)
#define GPIO_AF04         (4UL)
#define GPIO_AF05         (5UL)
#define GPIO_AF06         (6UL)
#define GPIO_AF07         (7UL)
#define GPIO_AF08         (8UL)
#define GPIO_AF09         (9UL)
#define GPIO_AF10         (10UL)
#define GPIO_AF11         (11UL)
#define GPIO_AF12         (12UL)
#define GPIO_AF13         (13UL)
#define GPIO_AF14         (14UL)
#define GPIO_AF15         (15UL)
#define GPIO_AF_DISABLED  (16UL)

/* PIN SPEED */

#define GPIO_PIN_LOW_SPEED   0xFFFFFFFF // Define GPIO pin low speed
#define GPIO_PIN_MID_SPEED   0x00000001 // Define GPIO pin medium speed
#define GPIO_PIN_HIGH_SPEED  0x00000002 // Define GPIO pin high speed
#define GPIO_PIN_VHIGH_SPEED 0x00000003 // Define GPIO pin very high speed

/* PIN STATE */
#define GPIO_PIN_ON  0x00000001UL // Define GPIO pin ON state
#define GPIO_PIN_OFF 0x00000000UL // Define GPIO pin OFF state

typedef struct
{
    u32 port;   // GPIO port
    u32 pin;    // GPIO pin
    u32 speed;  // GPIO pin speed
    u32 mode;   // GPIO pin mode
    u32 AF;
} GPIO_Pin_Confg_t; // Structure to hold GPIO pin configuration

/* Function prototypes */

/**
 * @brief Initialize a GPIO pin with the provided configuration.
 * 
 * @param Pin_Config Pointer to the GPIO pin configuration structure.
 * @return Error_t Error code indicating success or failure of the operation.
 */
Error_t GPIO_Init_Pin(GPIO_Pin_Confg_t *Pin_Config);

/**
 * @brief Set the state of a GPIO pin.
 * 
 * @param GPIO_PORT GPIO port of the pin.
 * @param GPIO_PIN GPIO pin number.
 * @param GPIO_State Desired state of the pin (GPIO_PIN_ON or GPIO_PIN_OFF).
 * @return Error_t Error code indicating success or failure of the operation.
 */
Error_t GPIO_Set_Pin_State(u32 GPIO_PORT, u32 GPIO_PIN, u32 GPIO_State);

/**
 * @brief Get the state of a GPIO pin.
 * 
 * @param GPIO_PORT GPIO port of the pin.
 * @param GPIO_PIN GPIO pin number.
 * @param Pin_State Pointer to a variable where the pin state will be stored (GPIO_PIN_ON or GPIO_PIN_OFF).

@return Error_t Error code indicating success or failure of the operation.
*/
Error_t GPIO_Get_Pin_State(u8 GPIO_PORT, u8 GPIO_PIN, u8 *Pin_State);
#endif /* GPIO_H_ */

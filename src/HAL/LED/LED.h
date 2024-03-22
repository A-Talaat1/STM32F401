#ifndef LED_H_
#define LED_H_
#include "../../lib/StdTypes.h"
#include "../../lib/Error/Error.h"
#include "HAL/LED/LED_Confg.h"

#define LED_PORT_A 0x00000000
#define LED_PORT_B 0x00000001
#define LED_PORT_C 0x00000002 

#define LED_PIN_0  0x00000000
#define LED_PIN_1  0x00000001
#define LED_PIN_2  0x00000002
#define LED_PIN_3  0x00000003
#define LED_PIN_4  0x00000004
#define LED_PIN_5  0x00000005
#define LED_PIN_6  0x00000006
#define LED_PIN_7  0x00000007
#define LED_PIN_8  0x00000008
#define LED_PIN_9  0x00000009
#define LED_PIN_10 0x0000000A
#define LED_PIN_11 0x0000000B
#define LED_PIN_12 0x0000000C
#define LED_PIN_13 0x0000000D
#define LED_PIN_14 0x0000000E
#define LED_PIN_15 0x0000000F

#define LED_CONNECT_REVERSE 0x00000001
#define LED_CONNECT_FORWARD 0x00000000

/*PIN STATE*/
#define LED_ON  0x00000001
#define LED_OFF 0x00000000

typedef struct 
{
    
    u32 Port;
    u32 Pin;
    u32 Connection;

}LED_Confg_t;

/**
 * 
*/
Error_t LED_Init (void);

Error_t LED_Set_State(LED_Names_t LED_Name, u8 LED_State);

Error_t LED_Toggle(LED_Names_t LED_Name);

#endif /*LED_H_*/
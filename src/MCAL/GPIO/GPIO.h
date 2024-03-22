#ifndef GPIO_H_
#define GPIO_H_

#include "../../../lib/Error/Error.h"
#include "../../../lib/StdTypes.h"

/*PORTS*/

#define GPIO_PORT_A 0x00000000
#define GPIO_PORT_B 0x00000001
#define GPIO_PORT_C 0x00000002

/*PINS*/

#define GPIO_PIN_0  0x00000000
#define GPIO_PIN_1  0x00000001
#define GPIO_PIN_2  0x00000002
#define GPIO_PIN_3  0x00000003
#define GPIO_PIN_4  0x00000004
#define GPIO_PIN_5  0x00000005
#define GPIO_PIN_6  0x00000006
#define GPIO_PIN_7  0x00000007
#define GPIO_PIN_8  0x00000008
#define GPIO_PIN_9  0x00000009
#define GPIO_PIN_10 0x0000000A
#define GPIO_PIN_11 0x0000000B
#define GPIO_PIN_12 0x0000000C
#define GPIO_PIN_13 0x0000000D
#define GPIO_PIN_14 0x0000000E
#define GPIO_PIN_15 0x0000000F


/*PIN MODES*/

#define GPIO_CONFG_INPUT_FLOATING 0x00000000
#define GPIO_CONFG_INPUT_PU       0x00000001
#define GPIO_CONFG_INPUT_PD       0x00000002

#define GPIO_CONFG_ANALOG         0x00000003

#define GPIO_CONFG_OUTPUT_OD      0x00000004
#define GPIO_CONFG_OUTPUT_OD_PU   0x00000005
#define GPIO_CONFG_OUTPUT_OD_PD   0x00000006
#define GPIO_CONFG_OUTPUT_PP      0x00000007
#define GPIO_CONFG_OUTPUT_PP_PU   0x00000008
#define GPIO_CONFG_OUTPUT_PP_PD   0x00000009

#define GPIO_CONFG_AF_OD          0x0000000A
#define GPIO_CONFG_AF_OD_PU       0x0000000B
#define GPIO_CONFG_AF_OD_PD       0x0000000C
#define GPIO_CONFG_AF_PP          0x0000000D
#define GPIO_CONFG_AF_PP_PU       0x0000000E
#define GPIO_CONFG_AF_PP_PD       0x0000000F

/*PIN SPEED*/
#define GPIO_PIN_LOW_SPEED   0xFFFFFFFF
#define GPIO_PIN_MID_SPEED   0x00000001
#define GPIO_PIN_HIGH_SPEED  0x00000002
#define GPIO_PIN_VHIGH_SPEED 0x00000003

/*PIN STATE*/
#define GPIO_PIN_ON  0x00000001UL
#define GPIO_PIN_OFF 0x00000000UL

typedef struct
{
    
    u32 port;
    u32 pin;
    u32 speed;
    u32 mode;

}GPIO_Pin_Confg_t;

/**
 * 
*/
Error_t GPIO_Init_Pin (GPIO_Pin_Confg_t * Pin_Config);

/**
 * 
*/
Error_t GPIO_Set_Pin_State(u32 GPIO_PORT, u32 GPIO_PIN, u32 GPIO_State);

/**/
Error_t GPIO_Get_Pin_State(u8 GPIO_PORT, u8 GPIO_PIN, u8 *Pin_State);

#endif /*GPIO_H_*/
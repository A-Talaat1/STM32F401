#ifndef SWITCH_H_
#define SWITCH_H_
#include "../../lib/StdTypes.h"
#include "../../lib/Error/Error.h"
#include "HAL/Switch/SWITCH_Confg.h"

#define SWITCH_PORT_A 0x00000000
#define SWITCH_PORT_B 0x00000001
#define SWITCH_PORT_C 0x00000002 

#define SWITCH_PIN_0  0x00000000
#define SWITCH_PIN_1  0x00000001
#define SWITCH_PIN_2  0x00000002
#define SWITCH_PIN_3  0x00000003
#define SWITCH_PIN_4  0x00000004
#define SWITCH_PIN_5  0x00000005
#define SWITCH_PIN_6  0x00000006
#define SWITCH_PIN_7  0x00000007
#define SWITCH_PIN_8  0x00000008
#define SWITCH_PIN_9  0x00000009
#define SWITCH_PIN_10 0x0000000A
#define SWITCH_PIN_11 0x0000000B
#define SWITCH_PIN_12 0x0000000C
#define SWITCH_PIN_13 0x0000000D
#define SWITCH_PIN_14 0x0000000E
#define SWITCH_PIN_15 0x0000000F

#define SWITCH_CONNECT_REVERSE 0x00000000
#define SWITCH_CONNECT_FORWARD 0x00000001

typedef struct 
{
    
    u32 Port;
    u32 Pin;

}SWITCH_Confg_t;

typedef enum
{
    Switch_Pressed,
    Switch_Released,
    
}Switch_State_t;

Error_t SWITCH_Init (void);

Error_t SWITCH_Get_State(SWITCH_Names_t SWITCH_Name, Switch_State_t *SWITCH_State);

#endif /*SWITCH_H_*/
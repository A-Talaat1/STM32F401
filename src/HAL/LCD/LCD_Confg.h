#ifndef LCD_CONFG_H_
#define LCD_CONFG_H_

#include "../lib/StdTypes.h"

/*PORTS*/

#define LCD_PORT_A 0x00000000
#define LCD_PORT_B 0x00000001
#define LCD_PORT_C 0x00000002

/*PINS*/

#define LCD_PIN_0  0x00000000
#define LCD_PIN_1  0x00000001
#define LCD_PIN_2  0x00000002
#define LCD_PIN_3  0x00000003
#define LCD_PIN_4  0x00000004
#define LCD_PIN_5  0x00000005
#define LCD_PIN_6  0x00000006
#define LCD_PIN_7  0x00000007
#define LCD_PIN_8  0x00000008
#define LCD_PIN_9  0x00000009
#define LCD_PIN_10 0x0000000A
#define LCD_PIN_11 0x0000000B
#define LCD_PIN_12 0x0000000C
#define LCD_PIN_13 0x0000000D
#define LCD_PIN_14 0x0000000E
#define LCD_PIN_15 0x0000000F

typedef enum
{
    LCD1,
	LCD2,


    LCD_Num,

}LCD_Modules_t;

typedef struct
{
    u8 Port;
    u8 Pin;
}LCD_Pins_Connection_t;


/*LCD Module pins*/
typedef enum
{
	/*Register Selection*/
	LCD_RS,
	
	/*Read/Write Selection*/
	LCD_RW,
	
	/*Enable Signal*/
	LCD_E,
	
	/*Low-Order Bi-Directional data bus*/
	 LCD_DB0,
	 LCD_DB1,
	 LCD_DB2,
	 LCD_DB3,
	
	/*High-Order Bi-Directional data bus*/
	 LCD_DB4,
	 LCD_DB5,
	 LCD_DB6,
	 LCD_DB7,


     LCD_Pins_Num,
	
}LCD_Pins_t;



typedef struct
{
    
    LCD_Pins_Connection_t LCD_arr[LCD_Pins_Num];

}LCD_PortPin_t;


#endif /*LCD_CONFG_H_*/
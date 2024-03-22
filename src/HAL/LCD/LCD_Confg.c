#include "LCD_Confg.h"

const LCD_PortPin_t LCD_Pins_Arr [LCD_Num] = 
{
    [LCD1] = 
    {
        .LCD_arr[LCD_RS].Port  = LCD_PORT_B,
        .LCD_arr[LCD_RS].Pin   = LCD_PIN_0 ,

        .LCD_arr[LCD_RW].Port  = LCD_PORT_B,
        .LCD_arr[LCD_RW].Pin   = LCD_PIN_1 ,

        .LCD_arr[LCD_E].Port   = LCD_PORT_B,
        .LCD_arr[LCD_E].Pin    = LCD_PIN_2 ,

        .LCD_arr[LCD_DB0].Port = LCD_PORT_B,
        .LCD_arr[LCD_DB0].Pin  = LCD_PIN_3 ,

        .LCD_arr[LCD_DB1].Port = LCD_PORT_B,
        .LCD_arr[LCD_DB1].Pin  = LCD_PIN_4 ,

        .LCD_arr[LCD_DB2].Port = LCD_PORT_B,
        .LCD_arr[LCD_DB2].Pin  = LCD_PIN_5 ,

        .LCD_arr[LCD_DB3].Port = LCD_PORT_B,
        .LCD_arr[LCD_DB3].Pin  = LCD_PIN_6 ,

        .LCD_arr[LCD_DB4].Port = LCD_PORT_B,
        .LCD_arr[LCD_DB4].Pin  = LCD_PIN_7 ,

        .LCD_arr[LCD_DB5].Port = LCD_PORT_B,
        .LCD_arr[LCD_DB5].Pin  = LCD_PIN_8 ,

        .LCD_arr[LCD_DB6].Port = LCD_PORT_B,
        .LCD_arr[LCD_DB6].Pin  = LCD_PIN_9 ,

        .LCD_arr[LCD_DB7].Port = LCD_PORT_B,
        .LCD_arr[LCD_DB7].Pin  = LCD_PIN_10,
    },
    [LCD2] = 
    {
        .LCD_arr[LCD_RS].Port  = LCD_PORT_A,
        .LCD_arr[LCD_RS].Pin   = LCD_PIN_0 ,

        .LCD_arr[LCD_RW].Port  = LCD_PORT_A,
        .LCD_arr[LCD_RW].Pin   = LCD_PIN_1 ,

        .LCD_arr[LCD_E].Port   = LCD_PORT_A,
        .LCD_arr[LCD_E].Pin    = LCD_PIN_2 ,

        .LCD_arr[LCD_DB0].Port = LCD_PORT_A,
        .LCD_arr[LCD_DB0].Pin  = LCD_PIN_3 ,

        .LCD_arr[LCD_DB1].Port = LCD_PORT_A,
        .LCD_arr[LCD_DB1].Pin  = LCD_PIN_4 ,

        .LCD_arr[LCD_DB2].Port = LCD_PORT_A,
        .LCD_arr[LCD_DB2].Pin  = LCD_PIN_5 ,

        .LCD_arr[LCD_DB3].Port = LCD_PORT_A,
        .LCD_arr[LCD_DB3].Pin  = LCD_PIN_6 ,

        .LCD_arr[LCD_DB4].Port = LCD_PORT_A,
        .LCD_arr[LCD_DB4].Pin  = LCD_PIN_7 ,

        .LCD_arr[LCD_DB5].Port = LCD_PORT_A,
        .LCD_arr[LCD_DB5].Pin  = LCD_PIN_8 ,

        .LCD_arr[LCD_DB6].Port = LCD_PORT_A,
        .LCD_arr[LCD_DB6].Pin  = LCD_PIN_9 ,

        .LCD_arr[LCD_DB7].Port = LCD_PORT_A,
        .LCD_arr[LCD_DB7].Pin  = LCD_PIN_10, 
    },
};





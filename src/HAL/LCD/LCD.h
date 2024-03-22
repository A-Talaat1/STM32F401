#ifndef LCD_H_
#define LCD_H_

#include "LCD_Confg.h"


void LCD_Clear(LCD_Modules_t LCD_Name);


void LCD_Set_Cursor(LCD_Modules_t LCD_Name ,u8 Row, u8 Col);


void LCD_Write_String(LCD_Modules_t LCD_Name ,const char *string);


#endif /*LCD_H_*/
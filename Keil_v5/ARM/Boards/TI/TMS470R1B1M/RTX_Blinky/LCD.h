/*----------------------------------------------------------------------------
 *      RL-ARM - Library
 *----------------------------------------------------------------------------
 *      Name:    LCD.H
 *      Purpose: LCD module 2x16 driver definitions
 *      Rev.:    V4.20
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/


extern void LCD_init      (void);
extern void LCD_clear     (void);
extern void LCD_cursor    (unsigned char state, unsigned char blink);
extern void LCD_backlight (unsigned char state);
extern void LCD_gotoxy    (unsigned char x, unsigned char y);
extern void LCD_putc      (char c);
extern void LCD_print     (unsigned char x, unsigned char y, char *string);
extern void LCD_bargraph  (unsigned char x, unsigned char y, unsigned char size, unsigned char val);


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

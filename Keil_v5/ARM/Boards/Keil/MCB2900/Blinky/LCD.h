/******************************************************************************/
/* LCD.h Text LCD function prototypes                                         */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2007 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/


extern void LCD_init (void);
extern void LCD_gotoxy (unsigned char x, unsigned char y);
extern void LCD_cls (void);
extern void LCD_cur_off (void);
extern void LCD_putc (unsigned char c);
extern void LCD_print (unsigned char x, unsigned char y, unsigned char *string);
extern void LCD_bargraph (unsigned char x, unsigned char y, unsigned char size, unsigned char val);


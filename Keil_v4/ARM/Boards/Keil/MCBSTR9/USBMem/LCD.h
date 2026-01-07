/*----------------------------------------------------------------------------
 * Name:    lcd.h
 * Purpose: LCD function prototypes
 * Version: V1.20
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2008 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

extern void lcd_write_cmd (unsigned char c);
extern void lcd_write_data (unsigned char c);
extern void lcd_init (void);
extern void lcd_clear (void);
extern void lcd_putchar (char c);
extern void set_cursor (unsigned char column, unsigned char line);
extern void lcd_print (unsigned char const *string);

/******************************************************************************/


/*----------------------------------------------------------------------------
 *      RL-ARM - USB
 *----------------------------------------------------------------------------
 *      Name:    LCD.h
 *      Purpose: LCD function prototypes
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

extern void lcd_init    (void);
extern void lcd_clear   (void);
extern void lcd_putchar (char c);
extern void set_cursor  (unsigned char column, unsigned char line);
extern void lcd_print   (unsigned char const *string);

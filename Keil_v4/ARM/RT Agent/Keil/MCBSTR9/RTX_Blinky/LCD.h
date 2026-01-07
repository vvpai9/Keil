/*----------------------------------------------------------------------------
 *      R T L   K e r n e l   E x a m p l e
 *----------------------------------------------------------------------------
 *      Name:    LCD.H
 *      Purpose: LCD module 2x16 driver function definitions
 *      Rev.:    V3.04a / 17-jan-2007
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2007 KEIL - An ARM Company. All rights reserved. 
 *---------------------------------------------------------------------------*/


extern void LCD_init (void);
extern void LCD_load (U8 *fp, U32 cnt);
extern void LCD_gotoxy (U32 x, U32 y);
extern void LCD_cls (void);
extern void LCD_cur_off (void);
extern void LCD_on (void);
extern void LCD_putc (U8 c);
extern void LCD_puts (U8 *sp);
extern void LCD_bargraph (U32 val, U32 size);

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/


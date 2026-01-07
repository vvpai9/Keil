/*----------------------------------------------------------------------------
 * Name:    GLCD.h
 * Purpose: MCBSTM32E low level Graphic LCD (320x240 pixels) prototypes
 * Version: V1.00
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/

#ifndef _GLCD_H
#define _GLCD_H

#include <stdint.h>



/*------------------------------------------------------------------------------
  color coding.
  GLCD is coded:   15..11 red, 10..5 green, 4..0 blue  (unsigned short)  GLCD_R5, GLCD_G6, GLCD_B5   
  original coding: 17..12 red, 11..6 green, 5..0 blue                    ORG_R6,  ORG_G6,  ORG_B6

  ORG_R1..5 = GLCD_R0..4,  ORG_R0 = GLCD_R4
  ORG_G0..5 = GLCD_G0..5,
  ORG_B1..5 = GLCD_B0..4,  ORG_B0 = GLCD_B4
 *------------------------------------------------------------------------------*/
                            
/* GLCD RGB color definitions */
#define Black           0x0000      /*   0,   0,   0 */
#define Navy            0x000F      /*   0,   0, 128 */
#define DarkGreen       0x03E0      /*   0, 128,   0 */
#define DarkCyan        0x03EF      /*   0, 128, 128 */
#define Maroon          0x7800      /* 128,   0,   0 */
#define Purple          0x780F      /* 128,   0, 128 */
#define Olive           0x7BE0      /* 128, 128,   0 */
#define LightGrey       0xC618      /* 192, 192, 192 */
#define DarkGrey        0x7BEF      /* 128, 128, 128 */
#define Blue            0x001F      /*   0,   0, 255 */
#define Green           0x07E0      /*   0, 255,   0 */
#define Cyan            0x07FF      /*   0, 255, 255 */
#define Red             0xF800      /* 255,   0,   0 */
#define Magenta         0xF81F      /* 255,   0, 255 */
#define Yellow          0xFFE0      /* 255, 255, 0   */
#define White           0xFFFF      /* 255, 255, 255 */



extern void GLCD_init           (void);
extern void GLCD_setTextColor   (unsigned short color);
extern void GLCD_setBackColor   (unsigned short color);







/* LCD RGB color definitions */
#define LCD_BLACK           0x0000    /*   0,   0,   0 */
#define LCD_NAVY            0x000F      /*   0,   0, 128 */
#define LCD_DARK_GREEN      0x03E0      /*   0, 128,   0 */
#define LCD_DARK_CYAN       0x03EF      /*   0, 128, 128 */
#define LCD_MAROON          0x7800      /* 128,   0,   0 */
#define LCD_PURPLE          0x780F      /* 128,   0, 128 */
#define LCD_OLIVE           0x7BE0      /* 128, 128,   0 */
#define LCD_LIGHT_GRAY      0xC618      /* 192, 192, 192 */
#define LCD_DARK_GRAY       0x7BEF      /* 128, 128, 128 */
#define LCD_BLUE            0x001F      /*   0,   0, 255 */
#define LCD_GREEN           0x07E0      /*   0, 255,   0 */
#define LCD_CYAN            0x07FF      /*   0, 255, 255 */
#define LCD_RED             0xF800      /* 255,   0,   0 */
#define LCD_MAGENTA         0xF81F      /* 255,   0, 255 */
#define LCD_YELLOW          0xFFE0      /* 255, 255, 0   */
#define LCD_WHITE           0xFFFF      /* 255, 255, 255 */


#define FONT_WIDTH            8
#define FONT_HEIGHT          13
#define FONT_FIRST_BIT        8



/* LCD display dimension */
#define LCD_WIDTH           240
#define LCD_HEIGHT          320

#define REG_HOR_GRAM        0x20
#define REG_VER_GRAM        0x21
#define REG_DAT_GRAM        0x22

/* LCD RGB color definitions */
#define LCD_BLACK           0x0000    /*   0,   0,   0 */
#define LCD_NAVY            0x000F      /*   0,   0, 128 */
#define LCD_DARK_GREEN      0x03E0      /*   0, 128,   0 */
#define LCD_DARK_CYAN       0x03EF      /*   0, 128, 128 */
#define LCD_MAROON          0x7800      /* 128,   0,   0 */
#define LCD_PURPLE          0x780F      /* 128,   0, 128 */
#define LCD_OLIVE           0x7BE0      /* 128, 128,   0 */
#define LCD_LIGHT_GRAY      0xC618      /* 192, 192, 192 */
#define LCD_DARK_GRAY       0x7BEF      /* 128, 128, 128 */
#define LCD_BLUE            0x001F      /*   0,   0, 255 */
#define LCD_GREEN           0x07E0      /*   0, 255,   0 */
#define LCD_CYAN            0x07FF      /*   0, 255, 255 */
#define LCD_RED             0xF800      /* 255,   0,   0 */
#define LCD_MAGENTA         0xF81F      /* 255,   0, 255 */
#define LCD_YELLOW          0xFFE0      /* 255, 255, 0   */
#define LCD_WHITE           0xFFFF      /* 255, 255, 255 */





extern volatile unsigned short TextColor, BackColor;
extern const unsigned short lcd_font[224][13];



/* Note: LCD /CS is CE4 - Bank 4 of NOR/SRAM Bank 1~4 */
#define LCD_BASE        (0x60000000UL | 0x0C000000UL)
#define LCD_REG16  (*((volatile unsigned short *)(LCD_BASE  ))) 
#define LCD_DAT16  (*((volatile unsigned short *)(LCD_BASE+2)))


/*******************************************************************************
* Write command to LCD controller                                              *
*   Parameter:    c:      command to be written                                *
*   Return:                                                                    *
*******************************************************************************/

static __inline void wr_cmd (unsigned char c) {

  LCD_REG16 = c;
}


/*******************************************************************************
* Write data to LCD controller                                                 *
*   Parameter:    c:      data to be written                                   *
*   Return:                                                                    *
*******************************************************************************/

static __inline void wr_dat (unsigned short c) {

  LCD_DAT16 = c;
}


/*******************************************************************************
* Write to LCD register                                                        *
*   Parameter:    reg:    register to be read                                  *
*                 val:    value to write to register                           *
*******************************************************************************/

static __inline void wr_reg (unsigned char reg, unsigned short val) {

  wr_cmd(reg);
  wr_dat(val);
}


/*******************************************************************************
* Set LCD Cursor in RAM                                                        *
*   Parameter:    x, y: Pixel-Position to write to                             *
*******************************************************************************/
static __inline GLCD_SetCursor(int x, int y)
{    
    wr_reg(0x20, y);
    wr_reg(0x21, x);
    wr_cmd(0x22);
}


static __inline GLCD_WritePixel(short color)
{
  wr_dat(color);
}

#endif /* _GLCD_H */

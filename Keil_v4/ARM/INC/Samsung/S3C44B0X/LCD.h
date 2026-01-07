/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  LCD.H:  Header file for LCD Controller                                    */
/*          Samsung S3C44B0X                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef __LCD_H
#define __LCD_H


#define LCD_BASE    0x01F00000  // LCD Controller Base Address


// LCD Controller Registers
typedef struct {
  reg32 LCDCON1;    // LCD Control 1
  reg32 LCDCON2;    // LCD Control 2
  reg32 LCDSADDR1;  // Frame Upper Buffer Start Address 1
  reg32 LCDSADDR2;  // Frame Lower Buffer Start Address 2
  reg32 LCDSADDR3;  // Virtual Screen Address
  reg32 REDLUT;     // RED Lookup Table
  reg32 GREENLUT;   // GREEN Lookup Table
  reg32 BLUELUT;    // BLUE Lookup Table
  reg32 DP1_2;      // Dithering Pattern Duty 1/2
  reg32 DP4_7;      // Dithering Pattern Duty 4/7
  reg32 DP3_5;      // Dithering Pattern Duty 3/5
  reg32 DP2_3;      // Dithering Pattern Duty 2/3
  reg32 DP5_7;      // Dithering Pattern Duty 5/7
  reg32 DP3_4;      // Dithering Pattern Duty 3/4
  reg32 DP4_5;      // Dithering Pattern Duty 4/5
  reg32 DP6_7;      // Dithering Pattern Duty 6/7
  reg32 LCDCON3;    // LCD Control 3
  reg32 DITHMODE;   // Dithering Mode
} regLCD;

#define pLCD ((regLCD *)LCD_BASE)


#endif /* __LCD_H */

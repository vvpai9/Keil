/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  LCDC.H:  Header file for LCD Controller (LCDC)                            */
/*           Sharp LH754xx                                                    */
/*                                                                            */
/******************************************************************************/

#ifndef __LCDC_H
#define __LCDC_H


#define LCDC_BASE      0xFFFF4000               /* LCDC Base Address */

#define LCDPALETTE     0x0200                   /* LCD Palette Offset */

#define LCDTiming0     REG32(LCDC_BASE + 0x00)  /* Horizontal Timing Control */
#define LCDTiming1     REG32(LCDC_BASE + 0x04)  /* Vertical Timing Control */
#define LCDTiming2     REG32(LCDC_BASE + 0x08)  /* Clock and Signal Polarity */
#define LCDUPBASE      REG32(LCDC_BASE + 0x10)  /* Upper Panel Frame Base */
#define LCDLPBASE      REG32(LCDC_BASE + 0x14)  /* Lower Panel Frame Base */
#define LCDINTRENABLE  REG32(LCDC_BASE + 0x18)  /* Interrupt Enable Mask */
#define LCDControl     REG32(LCDC_BASE + 0x1C)  /* LCD Control */
#define LCDStatus      REG32(LCDC_BASE + 0x20)  /* Raw Interrupt Status */
#define LCDInterrupt   REG32(LCDC_BASE + 0x24)  /* Final masked Interrupts */
#define LCDUPCURR      REG32(LCDC_BASE + 0x28)  /* Upper Panel current Addr. */
#define LCDLPCURR      REG32(LCDC_BASE + 0x2C)  /* Lower Panel current Addr. */

#define LCDPalette     ((reg16 *)(LCDC_BASE + LCDPALETTE))


#endif /* __LCDC_H */

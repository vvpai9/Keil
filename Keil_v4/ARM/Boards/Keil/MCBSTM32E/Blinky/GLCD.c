/*----------------------------------------------------------------------------
 * Name:    GLCD.c
 * Purpose: MCBSTM32E low level Graphic LCD (320x240 pixels) functions
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

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "stm32f10x_lib.h"

#include "glcd.h"
#include "font.h"


/*********************** Hardware specific configuration **********************/

/*------------------------- Speed dependant settings -------------------------*/

/* If processor works on high frequency delay has to be increased, it can be 
   increased by factor 2^N by this constant                                   */
#define DELAY_2N    18

/*---------------------- Graphic LCD size definitions ------------------------*/

#define WIDTH       320                 /* Screen Width (in pixels)           */
#define HEIGHT      240                 /* Screen Hight (in pixels)           */
#define BPP         16                  /* Bits per pixel                     */
#define BYPP        ((BPP+7)/8)         /* Bytes per pixel                    */

/*--------------- Graphic LCD interface hardware definitions -----------------*/

/* Note: LCD /CS is CE4 - Bank 4 of NOR/SRAM Bank 1~4 */
#define LCD_BASE        (0x60000000UL | 0x0C000000UL)
#define LCD_REG16  (*((volatile unsigned short *)(LCD_BASE  ))) 
#define LCD_DAT16  (*((volatile unsigned short *)(LCD_BASE+2)))
 
/*---------------------------- Global variables ------------------------------*/

/******************************************************************************/
static volatile unsigned short TextColor = Black, BackColor = White;
static volatile unsigned short DriverCode;


/************************ Local auxiliary functions ***************************/

/*******************************************************************************
* Delay in while loop cycles                                                   *
*   Parameter:    cnt:    number of while cycles to delay                      *
*   Return:                                                                    *
*******************************************************************************/

static void delay (int cnt) {

  cnt <<= DELAY_2N;
  while (cnt--);
}


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
* Read data from LCD controller                                                *
*   Parameter:                                                                 *
*   Return:               read data                                            *
*******************************************************************************/

static __inline unsigned short rd_dat (void) {

  return (LCD_DAT16);                                    /* return value */
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
* Read from LCD register                                                       *
*   Parameter:    reg:    register to be read                                  *
*   Return:               value read from register                             *
*******************************************************************************/

static unsigned short rd_reg (unsigned char reg) {

  wr_cmd(reg);
  return (rd_dat());
}


/************************ Exported functions **********************************/

/*******************************************************************************
* Initialize the Graphic LCD controller                                        *
*   Parameter:                                                                 *
*   Return:                                                                    *
*******************************************************************************/

void GLCD_init (void) { 

/* Configure the LCD Control pins --------------------------------------------*/
  RCC->APB2ENR |= 0x000001ED;                         /* enable GPIOA,D..G, AFIO clock */

  /* PD.00(D2),  PD.01(D3),  PD.04(NOE), PD.05(NWE) */ 
  GPIOD->CRL &= ~0x00FF00FF;                          /* clear Bits */
  GPIOD->CRL |=  0x00BB00BB;                          /* alternate function output Push-pull 50MHz */
  /* PD.08(D13), PD.09(D14), PD.10(D15), PD.14(D0), PD.15(D1) */
  GPIOD->CRH &= ~0xFF000FFF;                          /* clear Bits */
  GPIOD->CRH |=  0xBB000BBB;                          /* alternate function output Push-pull 50MHz */
   
  /* PE.07(D4) */ 
  GPIOE->CRL &= ~0xF0000000;                          /* clear Bits */
  GPIOE->CRL |=  0xB0000000;                          /* alternate function output Push-pull 50MHz */
  /* PE.08(D5), PE.09(D6),  PE.10(D7), PE.11(D8), PE.12(D9), PE.13(D10), PE.14(D11), PE.15(D12) */
  GPIOE->CRH &= ~0xFFFFFFFF;                          /* clear Bits */
  GPIOE->CRH |=  0xBBBBBBBB;                          /* alternate function output Push-pull 50MHz */

  /* PF.00(A0 (RS)) */ 
  GPIOF->CRL &= ~0x0000000F;                          /* clear Bits */
  GPIOF->CRL |=  0x0000000B;                          /* alternate function output Push-pull 50MHz */

  /* PG.12(NE4 (LCD/CS)) - CE3(LCD /CS) */
  GPIOG->CRH &= ~0x000F0000;                          /* clear Bits */
  GPIOG->CRH |=  0x000B0000;                          /* alternate function output Push-pull 50MHz */

  /* PA.08(LCD Backlight */
  GPIOA->BRR |=  0x00000100;                          /* Backlight off */
  GPIOA->CRH &= ~0x0000000F;                          /* clear Bits */
  GPIOA->CRH |=  0x00000003;                          /*                    output Push-pull 50MHz */

/*-- FSMC Configuration ------------------------------------------------------*/
/*----------------------- SRAM Bank 4 ----------------------------------------*/
  RCC->AHBENR  |= (1<<8);                             /* enable FSMC clock */

  FSMC_Bank1->BTCR[FSMC_Bank1_NORSRAM4+1] =           /* Bank1 NOR/SRAM timing register configuration */
                                         (0 << 28) |  /* FSMC AccessMode A */
                                         (0 << 24) |  /* Data Latency */
                                         (0 << 20) |  /* CLK Division */
                                         (0 << 16) |  /* Bus Turnaround Duration */
                                         (1 <<  8) |  /* Data SetUp Time */
                                         (0 <<  4) |  /* Address Hold Time */
                                         (0 <<  0);   /* Address SetUp Time */
  FSMC_Bank1->BTCR[FSMC_Bank1_NORSRAM4  ] =           /* Control register */
                                         (0 << 19) |  /* Write burst disabled */
                                         (0 << 15) |  /* Async wait disabled */
                                         (0 << 14) |  /* Extended mode disabled */
                                         (0 << 13) |  /* NWAIT signal is disabled */ 
                                         (1 << 12) |  /* Write operation enabled */
                                         (0 << 11) |  /* NWAIT signal is active one data cycle before wait state */
                                         (0 << 10) |  /* Wrapped burst mode disabled */
                                         (1 <<  9) |  /* Wait signal polarity active low */
                                         (0 <<  8) |  /* Burst access mode disabled */
                                         (1 <<  4) |  /* Memory data  bus width is 16 bits */
                                         (0 <<  2) |  /* Memory type is SRAM */
                                         (0 <<  1) |  /* Address/Data Multiplexing disable */
                                         (1 <<  0);   /* Memory Bank enable */

  delay(5);                             /* Delay 50 ms                        */
  DriverCode = rd_reg(0x00);

  /* Start Initial Sequence --------------------------------------------------*/
  wr_reg(0xE5, 0x8000);                 /* Set the internal vcore voltage     */
  wr_reg(0x00, 0x0001);                 /* Start internal OSC                 */
  wr_reg(0x01, 0x0100);                 /* Set SS and SM bit                  */
  wr_reg(0x02, 0x0700);                 /* Set 1 line inversion               */
  wr_reg(0x03, 0x1030);                 /* Set GRAM write direction and BGR=1 */
  wr_reg(0x04, 0x0000);                 /* Resize register                    */
  wr_reg(0x08, 0x0202);                 /* 2 lines each, back and front porch */
  wr_reg(0x09, 0x0000);                 /* Set non-disp area refresh cyc ISC  */
  wr_reg(0x0A, 0x0000);                 /* FMARK function                     */
  wr_reg(0x0C, 0x0000);                 /* RGB interface setting              */
  wr_reg(0x0D, 0x0000);                 /* Frame marker Position              */
  wr_reg(0x0F, 0x0000);                 /* RGB interface polarity             */

  /* Power On sequence -------------------------------------------------------*/
  wr_reg(0x10, 0x0000);                 /* Reset Power Control 1              */
  wr_reg(0x11, 0x0000);                 /* Reset Power Control 2              */
  wr_reg(0x12, 0x0000);                 /* Reset Power Control 3              */
  wr_reg(0x13, 0x0000);                 /* Reset Power Control 4              */
  delay(20);                            /* Discharge cap power voltage (200ms)*/
  wr_reg(0x10, 0x17B0);                 /* SAP, BT[3:0], AP, DSTB, SLP, STB   */
  wr_reg(0x11, 0x0137);                 /* DC1[2:0], DC0[2:0], VC[2:0]        */
  delay(5);                             /* Delay 50 ms                        */
  wr_reg(0x12, 0x0139);                 /* VREG1OUT voltage                   */
  delay(5);                             /* Delay 50 ms                        */
  wr_reg(0x13, 0x1D00);                 /* VDV[4:0] for VCOM amplitude        */
  wr_reg(0x29, 0x0013);                 /* VCM[4:0] for VCOMH                 */
  delay(5);                             /* Delay 50 ms                        */
  wr_reg(0x20, 0x0000);                 /* GRAM horizontal Address            */
  wr_reg(0x21, 0x0000);                 /* GRAM Vertical Address              */

  /* Adjust the Gamma Curve --------------------------------------------------*/
  wr_reg(0x30, 0x0006);
  wr_reg(0x31, 0x0101);
  wr_reg(0x32, 0x0003);
  wr_reg(0x35, 0x0106);
  wr_reg(0x36, 0x0B02);
  wr_reg(0x37, 0x0302);
  wr_reg(0x38, 0x0707);
  wr_reg(0x39, 0x0007);
  wr_reg(0x3C, 0x0600);
  wr_reg(0x3D, 0x020B);
  
  /* Set GRAM area -----------------------------------------------------------*/
  wr_reg(0x50, 0x0000);                 /* Horizontal GRAM Start Address      */
  wr_reg(0x51, (HEIGHT-1));             /* Horizontal GRAM End   Address      */
  wr_reg(0x52, 0x0000);                 /* Vertical   GRAM Start Address      */
  wr_reg(0x53, (WIDTH-1));              /* Vertical   GRAM End   Address      */
  wr_reg(0x60, 0x2700);                 /* Gate Scan Line                     */
  wr_reg(0x61, 0x0001);                 /* NDL,VLE, REV                       */
  wr_reg(0x6A, 0x0000);                 /* Set scrolling line                 */

  /* Partial Display Control -------------------------------------------------*/
  wr_reg(0x80, 0x0000);
  wr_reg(0x81, 0x0000);
  wr_reg(0x82, 0x0000);
  wr_reg(0x83, 0x0000);
  wr_reg(0x84, 0x0000);
  wr_reg(0x85, 0x0000);

  /* Panel Control -----------------------------------------------------------*/
  wr_reg(0x90, 0x0010);
  wr_reg(0x92, 0x0000);
  wr_reg(0x93, 0x0003);
  wr_reg(0x95, 0x0110);
  wr_reg(0x97, 0x0000);
  wr_reg(0x98, 0x0000);

  /* Set GRAM write direction and BGR = 1
     I/D=10 (Horizontal : increment, Vertical : increment)
     AM=1 (address is updated in vertical writing direction)                  */
  wr_reg(0x03, 0x1038);

  wr_reg(0x07, 0x0173);                 /* 262K color and display ON          */
  GPIOA->BSRR = 0x00000100;         /* Turn backlight on */
}


void GLCD_putPixel(unsigned int x, unsigned int y) {
  wr_reg(0x20, x);
  wr_reg(0x21, y);
  wr_cmd(0x22);
  wr_dat(TextColor);
}


/*******************************************************************************
* Set foreground color                                                         *
*   Parameter:    color:  color for clearing display                           *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_setTextColor(unsigned short color) {
  TextColor = color;
}


/*******************************************************************************
* Set background color                                                         *
*   Parameter:    color:  color for clearing display                           *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_setBackColor(unsigned short color) {
  BackColor = color;
}


/*******************************************************************************
* Clear display                                                                *
*   Parameter:    color:  color for clearing display                           *
*   Return:                                                                    *
*******************************************************************************/

void GLCD_clear (unsigned short color) {
  unsigned int   i;

  wr_reg(0x20, 0);
  wr_reg(0x21, 0);
  wr_cmd(0x22);
  for(i = 0; i < (WIDTH*HEIGHT); i++)
    wr_dat(color);
}


/*******************************************************************************
* Draw character on given position (line, coloum                               *
*   Parameter:     x :        horizontal position                              *
*                  y :        vertical position                                *
*                  c*:        pointer to color value                           *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_drawChar(unsigned int x, unsigned int y, unsigned short *c) {
  unsigned int index = 0;
  int  i = 0;
  unsigned int Xaddress = 0;
   
  Xaddress = x;
  
  wr_reg(0x20, Xaddress);
  wr_reg(0x21, y);
  
  for(index = 0; index < 24; index++)
  {
    wr_cmd(0x22);              /* Prepare to write GRAM */
    for(i = 15; i >= 0; i--)
//    for(i = 0; i < 16; i++)
    {
      if((c[index] & (1 << i)) == 0x00) {
        wr_dat(BackColor);
      } else {
        wr_dat(TextColor);
      }
    }
    Xaddress++;
    wr_reg(0x20, Xaddress);
    wr_reg(0x21, y);
  }
}


/*******************************************************************************
* Disply character on given line                                               *
*   Parameter:     c :        ascii character                                  *
*                  ln:        line number                                      *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_displayChar(unsigned int ln, unsigned int col, unsigned char  c) {
  c -= 32;
  GLCD_drawChar(ln, col, &ASCII_Table[c * 24]);
}


/*******************************************************************************
* Disply string on given line                                                  *
*   Parameter:     s*:        pointer to string                                *
*                  ln:        line number                                      *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_displayStringLn(unsigned int ln, unsigned char *s) {
  unsigned int i = 0;
  unsigned int refcolumn = (WIDTH/*-1*/)-16;

  while ((*s != 0) & (i < 20))                   /* write the string character by character on lCD */
  {
    GLCD_displayChar(ln, refcolumn, *s);         /* Display one character on LCD */
    refcolumn -= 16;                             /* Decrement the column position by 16 */
    s++;                                         /* Point on the next character */
    i++;                                         /* Increment the character counter */
  }
}


/*******************************************************************************
* Clear given line                                                             *
*   Parameter:     ln:        line number                                      *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_clearLn(unsigned int ln) {
  GLCD_displayStringLn(ln, "                    ");
}


/*******************************************************************************
* Display graphical bitmap image at position x horizontally and y vertically   *
* (This function is optimized for 16 bits per pixel format, it has to be       *
*  adapted for any other bits per pixel format)                                *
*   Parameter:      x:        horizontal position                              *
*                   y:        vertical position                                *
*                   w:        width of bitmap                                  *
*                   h:        height of bitmap                                 *
*                   bitmap:   address at which the bitmap data resides         *
*   Return:                                                                    *
*******************************************************************************/

void GLCD_bitmap (unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned char *bitmap) {
  unsigned int   i;
  unsigned int   len = w*h;
  unsigned short *bitmap_ptr = (unsigned short *)bitmap;

  wr_reg(0x50, y);                      /* Horizontal GRAM Start Address      */
  wr_reg(0x51, y+h-1);                  /* Horizontal GRAM End   Address (-1) */
  wr_reg(0x52, x);                      /* Vertical   GRAM Start Address      */
  wr_reg(0x53, x+w-1);                  /* Vertical   GRAM End   Address (-1) */

  wr_reg(0x20, y);
  wr_reg(0x21, x);

  wr_cmd(0x22);
  for (i = 0; i < len; i++) {
    wr_dat(*bitmap_ptr++);
  }
}


/******************************************************************************/

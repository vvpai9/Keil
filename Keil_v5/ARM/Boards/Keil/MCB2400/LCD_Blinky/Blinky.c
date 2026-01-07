/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: Graphic Demo
 * Note(s): 
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2008-2012 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/
                  
#include <LPC23xx.H>                    /* LPC23xx/LPC24xx definitions        */
#include "GLCD.h"

extern unsigned char Bg_16bpp_t[];
extern unsigned char Bg_16bpp_l[];
extern unsigned char Bg_16bpp_r[];
extern unsigned char Bg_16bpp_b[];
extern unsigned char ARM_Ani_16bpp[];


/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) {                       /* Main Program                       */
  int pic     =  0;
  int i;

  GLCD_Init();

  GLCD_Clear  (White);
  GLCD_Bitmap (  0,   0, 320,  69, Bg_16bpp_t+70);
  GLCD_Bitmap (  0,  69,   4, 102, Bg_16bpp_l+70);
  GLCD_Bitmap (316,  69,   4, 102, Bg_16bpp_r+70);
  GLCD_Bitmap (  0, 171, 320,  69, Bg_16bpp_b+70);

  for (;;) {                            /* Loop forever                       */
    i = 400000;
    while (i--) __nop();
    if (pic++ > 8) pic = 0;
      GLCD_Bitmap (99, 99, 120, 45, &ARM_Ani_16bpp[pic*(120*45*2)]);
  }
}

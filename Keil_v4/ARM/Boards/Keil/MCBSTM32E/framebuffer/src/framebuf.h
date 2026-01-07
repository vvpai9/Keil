/******************************************************************************
 * @file:    framebuf.h
 * @purpose: Driver for framebuffer using glcd and external SRAM
 * @version: V1.0
 * @date:    14. Aug 2009
 *----------------------------------------------------------------------------
 *
 * Copyright (C) 2009 ARM Limited. All rights reserved.
 *
 * ARM Limited (ARM) is supplying this software for use with Cortex-Mx 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/
 
 
#ifndef __FRAMEBUF_H__
#define __FRAMEBUF_H__

#include "ext_sram.h"

#define DISP_SIZE     (LCD_WIDTH * LCD_HEIGHT)     // 320 * 240 = 76800, 0x12C00
#define FB_SIZE       (256*1024)

#if (FB_SIZE > EXT_SRAM_SIZE) 
  #error Size for Framebuffer is too high!   FB_SIZE > EXT_SRAM_SIZE
#endif


#define FB_START            (1<<0)
#define FB_UPD              (1<<1)



// prototypes
int  FrameBuf_Init          (void);
void FrameBuf_WriteDisp     (void);
void FrameBuf_PutChar       (unsigned int x, unsigned int y, char  c,    unsigned int color);
void FrameBuf_PutStr        (unsigned int x, unsigned int y, char *pStr, unsigned int color);
void FrameBuf_ClearScreen   (void);
void FrameBuf_Scroll        (signed int nLines);
void FrameBuf_LoadBackG     (const unsigned short *backSrc, unsigned int pictWidth, int x_offs, int y_offs);
void FrameBuf_ForceUpdate   (void);
void FrameBuf_Update        (void);
void FrameBuf_MoveTextArea  (signed int nLines);


#endif


/******************************************************************************
 * @file:    drv_glcd0.h
 * @purpose: IO driver layer for GLCD
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

#ifndef __DRV_GLCD0_H__
#define __DRV_GLCD0_H__


// Prototypes
// ----------------------   IO   -------------------------------
         int  Open_GLCD0    (void);
unsigned int  Output_GLCD0  (const unsigned char *buf, unsigned int len);
unsigned int  Input_GLCD0   (unsigned char *buf, unsigned int len);
         int  Close_GLCD0   (void);
         
// ----------------------   Driver   -------------------------------
int glcd0_putchar_retarget (const unsigned char *buf, unsigned int len);



#endif

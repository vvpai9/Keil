/******************************************************************************
 * @file:    retarget.h
 * @purpose: retargeting layer for GLCD
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


#ifndef __RETARGET_H__
#define __RETARGET_H__


/* Standard IO device handles - arbitrary, but any real filesystem handles must be
   less than 0x8000. */
#define STDIN             0x8001    // Standard Input Stream
#define STDOUT            0x8002    // Standard Output Stream
#define STDERR            0x8003    // Standard Error Stream

#define ITM_STREAM        0x8010      // ITM   Output Stream
#define GLCD0_STREAM      0x8011      // GLCD0 Output Stream

// FILE struct
struct __FILE 
{
  int handle;
  /* Add whatever you need here */
};



void SystemReset (void);

#endif


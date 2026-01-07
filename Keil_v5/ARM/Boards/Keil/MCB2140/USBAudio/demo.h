/*----------------------------------------------------------------------------
 * Name:    demo.h
 * Purpose: USB Audio Demo Definitions
 * Version: V1.20
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2008 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

/* Clock Definitions */
#define CPU_CLOCK 60000000          /* CPU Clock */
#define VPB_CLOCK (CPU_CLOCK/1)     /* VPB Clock */

/* Audio Definitions */
#define DATA_FREQ 32000             /* Audio Data Frequency */
#define P_S       32                /* Packet Size */
#if USB_DMA
#define P_C       4                 /* Packet Count */
#else
#define P_C       1                 /* Packet Count */
#endif
#define B_S       (8*P_C*P_S)       /* Buffer Size */

/* Push Button Definitions */
#define PB_INT0         0x00004000  /* P0.14 */

/* LED Definitions */
#define LED_MSK         0x00FF0000  /* P1.16..23 */

/* Audio Demo Variables */
extern U8  Mute;                    /* Mute State */
extern U32 Volume;                  /* Volume Level */
extern U16 VolCur;                  /* Volume Current Value */
extern U32 InfoBuf[P_C];            /* Packet Info Buffer */
extern S16 DataBuf[B_S];            /* Data Buffer */
extern U16 DataOut;                 /* Data Out Index */
extern U16 DataIn;                  /* Data In Index */
extern U8  DataRun;                 /* Data Stream Run State */

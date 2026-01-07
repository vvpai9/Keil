/******************************************************************************/
/* TS.h: Touch-Screen function prototypes                                     */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#ifndef _TS_H
#define _TS_H

extern void         TS_Init   (void);
extern void         TS_Write  (unsigned char reg, unsigned char num, unsigned int val);
extern unsigned int TS_Read   (unsigned char reg, unsigned char num);

#endif /* _TS_H */

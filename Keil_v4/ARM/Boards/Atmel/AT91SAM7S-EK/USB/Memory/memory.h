/*----------------------------------------------------------------------------
 *      Name:    MEMORY.H
 *      Purpose: USB Memory Storage Demo Definitions
 *      Version: V1.10
 *----------------------------------------------------------------------------
 *      This file is part of the uVision/ARM development tools.
 *      Copyright (c) 2005-2006 Keil Software. All rights reserved.
 *      This software may only be used under the terms of a valid, current,
 *      end user licence from KEIL for a compatible version of KEIL software
 *      development tools. Nothing else gives you the right to use it.
 *---------------------------------------------------------------------------*/

/* MSC Disk Image Definitions */
#define MSC_ImageSize   0x00001000

extern const unsigned char DiskImage[MSC_ImageSize];   /* Disk Image */

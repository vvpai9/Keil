/*----------------------------------------------------------------------------
 * Name:    KBD.h
 * Purpose: AT91SAM3U-EK low level Push Button definitions
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
 * Copyright (c) 2008 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/

#ifndef __KBD_H
#define __KBD_H


#define KBD_MASK        0x03
#define KBD_PB0         0x01         /* Push Button 0 */
#define KBD_PB1         0x02         /* Push Button 1 */

extern uint32_t KBD_val;             

extern void     KBD_init(void);
extern uint32_t KBD_get (void);

#endif

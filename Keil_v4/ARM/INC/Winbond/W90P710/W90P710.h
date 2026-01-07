/****************************************************************************** 
 *  This file is part of the uVision/ARM development tools                    * 
 *  Copyright KEIL ELEKTRONIK GmbH 2002-2007                                  * 
 ****************************************************************************** 
 *                                                                            * 
 *  W90P710.H: Header file for Winbond W90P710                                * 
 *                                                                            * 
 ******************************************************************************/

#ifndef __W90P710_H
#define __W90P710_H

#include "710defs.h"

/* Register access definitions                                                */
#define Reg8(adr)  (*((volatile unsigned char  *) (adr)))
#define Reg16(adr) (*((volatile unsigned short *) (adr)))
#define Reg32(adr) (*((volatile unsigned long  *) (adr)))

#endif /* __W90P710_H */

/***********************************************************************
 * $Id:: lh7a404_pwm.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 PWM definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         Pulse Width Modulators
 *
 ***********************************************************************
 * Software that is described herein is for illustrative purposes only  
 * which provides customers with programming information regarding the  
 * products. This software is supplied "AS IS" without any warranties.  
 * NXP Semiconductors assumes no responsibility or liability for the 
 * use of the software, conveys no license or title under any patent, 
 * copyright, or mask work right to the product. NXP Semiconductors 
 * reserves the right to make changes in the software without 
 * notification. NXP Semiconductors also make no representation or 
 * warranty that such application will be suitable for the specified 
 * use without further testing or modification. 
 **********************************************************************/

#ifndef LH7A404_PWM_H
#define LH7A404_PWM_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * PWM Register Structure
 **********************************************************************/

/* PWM base module Register Structure */ 
typedef struct 
{
    volatile UNS_32 pwmtcount;    /* PWM terminal count register */ 
    volatile UNS_32 pwmdcycle;    /* PWM suty cycle register */ 
    volatile UNS_32 pwmenable;    /* PWM enable register */ 
    volatile UNS_32 pwminvert;    /* PWM invert register */ 
    volatile UNS_32 pwmsync;      /* PWM synchronous mode register */
    volatile UNS_32 rsvd[3];      /* PWM reserved */
} PWM_BASE_REGS_T;

/* PWM Module Register Structure */ 
typedef struct 
{
    PWM_BASE_REGS_T pwmregs[2];   /* PWM base registers */ 
} PWM_REGS_T;

/***********************************************************************
 * PWM terminal count register definitions
 **********************************************************************/

/* PWM terminal count load macro */
#define PWM_TC(n)        ((n) & 0x0000FFFF)

/***********************************************************************
 * PWM duty cycle register definitions
 **********************************************************************/

/* PWM duty cycle load macro */
#define PWM_DC(n)        ((n) & 0x0000FFFF)

/***********************************************************************
 * PWM enable register definitions
 **********************************************************************/

/* PWM enable register enable bit */
#define PWM_ENABLE       0x00000001

/***********************************************************************
 * PWM invert register definitions
 **********************************************************************/

/* PWM invert register invert enable bit */
#define PWM_INVERT       0x00000001

/***********************************************************************
 * PWM synchronous mode register definitions
 **********************************************************************/

/* PWM synchronous mode sychronous mode enable bit */
#define PWM_SYNC         0x00000001
/* PWM synchronous mode normal mode */
#define PWM_NORMAL       0x00000000
/* PWM synchronous mode select sync0 as sync source */
#define PWM_USE_SYNC0    0x00000000

/* Macro pointing to DC to DC converter registers */
#define PWM    ((PWM_REGS_T *)(PWM_BASE))

#endif /* LH7A404_PWM_H */ 

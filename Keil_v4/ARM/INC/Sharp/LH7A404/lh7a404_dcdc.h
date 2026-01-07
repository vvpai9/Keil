/***********************************************************************
 * $Id:: lh7a404_dcdc.h 14 2007-08-28 16:08:18Z kevinw                 $
 *
 * Project: LH7A404 DCDC definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         DC-DC Converter (configurable dual-output)
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

#ifndef LH7A404_DCDC_H
#define LH7A404_DCDC_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * DC-DC Converter Register Structure
 **********************************************************************/

/* DCDC Module Register Structure */ 
typedef struct 
{
    volatile UNS_32 pmpcon;    /* DCDC Drive 0/1 config register */ 
    volatile UNS_32 reserved;  /* Reserved */
    volatile UNS_32 pmpfreq;   /* DCDC Frequency config register */ 
} DCDC_REGS_T;

/***********************************************************************
 * DC-DC duty cycle configuration register definitions
 **********************************************************************/

/* Drive 0, high drive state (nEXTPWR) duty cycle load macro */
#define DCDC_PMP_DRV0_DTYHI(n)   _SBF(0, ((n) & 0xF))
/* Drive 0, low drive state (nEXTPWR) duty cycle load macro */
#define DCDC_PMP_DRV0_DTYLO(n)   _SBF(4, ((n) & 0xF))
/* Drive 1, high drive state (nEXTPWR) duty cycle load macro */
#define DCDC_PMP_DRV1_DTYHI(n)   _SBF(8, ((n) & 0xF))
/* Drive 1, low drive state (nEXTPWR) duty cycle load macro */
#define DCDC_PMP_DRV1_DTYLO(n)   _SBF(12, ((n) & 0xF))

/***********************************************************************
 * DC-DC frequency configuration register definitions
 **********************************************************************/

/* Drive 0, high drive state (nEXTPWR) prescaler load macro */
#define DCDC_FREQ_DRV0_PREHI(n)  _SBF(0, ((n) & 0x7))
/* Drive 0, low drive state (nEXTPWR) prescaler load macro */
#define DCDC_FREQ_DRV0_PRELO(n)  _SBF(4, ((n) & 0x7))
/* Drive 1, high drive state (nEXTPWR) prescaler load macro */
#define DCDC_FREQ_DRV1_PREHI(n)  _SBF(8, ((n) & 0x7))
/* Drive 1, low drive state (nEXTPWR) prescaler load macro */
#define DCDC_FREQ_DRV1_PRELO(n)  _SBF(12, ((n) & 0x7))

/* Macro pointing to DC to DC converter registers */
#define DCDC    ((DCDC_REGS_T *)(DCDC_BASE))

#endif /* LH7A404_DCDC_H */ 

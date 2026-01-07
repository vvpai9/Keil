/***********************************************************************
 * $Id:: lh7a404_csc_driver.h 14 2007-08-28 16:08:18Z kevinw           $
 *
 * Project: LH7A404 CSC driver
 *
 * Description:
 *     This file contains driver support for the CSC module on the
 *     LH7A404
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

#ifndef LH7A404_CSC_DRIVER_H
#define LH7A404_CSC_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_csc.h"

/***********************************************************************
 * CSC driver enumerations
 **********************************************************************/

/* CSC low power states */
typedef enum {STANDBY, HALT} CSC_POWER_T;

/* CSC interrupt clear request enumerations */
typedef enum {BATTLOWINT, MEDCHGINT, TICKINT} CSC_INT_CLEAR_T;

/* CSC status request enumerations */
typedef enum {
    RTCDIV,
    MEDIACHG,
    DCDETECT,
    WAKEUPDIR,
    WAKEUPON,
    NEWBATT,
    USERRESET,
    POWERFAIL,
    COLDSTART,
    PLL2LOCK,
    WDTFLAG,
    CHIPID,
    CHIPMAN
} CSC_STATUS_T;

/* Possible CSC clock types for frequency query */
typedef enum {CPUCLK, AHBCLK, APBCLK} CSC_CLOCK_T;

/* CSC DMA channel types */
typedef enum
{
   DMA_M2P_CH1 = 0,
   DMA_M2P_CH0,
   DMA_M2P_CH3,
   DMA_M2P_CH2,
   DMA_M2P_CH5,
   DMA_M2P_CH4,
   DMA_M2P_CH7,
   DMA_M2P_CH6,
   DMA_M2P_CH9,
   DMA_M2P_CH8,
   DMA_M2M_CH0,
   DMA_M2M_CH1
} CSC_DMA_CHANNEL_T;

/* CSC USB reset enumeration type */
typedef enum {
    USB_IO = CSC_USBRESET_IO,
    USB_CONTROL = CSC_USBRESET_CONTROL} CSC_USB_RESET_T;
  
/***********************************************************************
 * CSC driver functions
 **********************************************************************/
/* Return the current HCLK settings */
UNS_32 csc_get_hclk(void);

/* Return the current CPU CLOCK settings */
UNS_32 csc_get_cpuclk(void);

/* Return the current PCLK settings */
UNS_32 csc_get_pclk(void);

/* Enter the chip low power state */
void csc_enter_low_power_state(CSC_POWER_T state);

/* Clear a CSC interrupt */
void csc_clear_interrupt(CSC_INT_CLEAR_T interrupts);

/* Clear misc CSC status bits */
void csc_clear_misc_status(void);

/* Return a status value from the PWRSR register in the CSC */
INT_32 csc_get_status(CSC_STATUS_T status);

/* Get CPU, AHB Bus, or APB bus clock speed */
UNS_32 csc_get_clock(CSC_CLOCK_T clock);

/* Set the CSC CLKSET register */
void csc_clock_set(UNS_32 clkset_register_setting);

/* Enable or disable the wakeup signal */
void csc_stby_wakeup_enable(BOOL_32 enable);

/* Set the PGMCLK divisor (> 1) or disable it (= 0) */
void csc_set_pgmclk_divisor(UNS_8 div);

/* Enable or disable a DMA controller channel clock */
void csc_enable_dma_clock(CSC_DMA_CHANNEL_T channel, BOOL_32 enable);

/* Issue a USB IO or control reset */
void csc_usb_reset(CSC_USB_RESET_T reset);

/***********************************************************************
 * The csc_compute_divide is a convienence function and not really part
 * of the CSC driver. So many functions base their clocks of a divided
 * value of a CSC derived clock that this function is really useful as
 * part of this driver.
 **********************************************************************/

/* Compute the closest divider to the passed input frequency and desired
   target frequency */
INT_32 csc_compute_divider(UNS_32 input_freq,
                           UNS_32 desired_freq);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_CSC_DRIVER_H */

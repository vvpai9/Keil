/***********************************************************************
 * $Id:: lh7a404_adc.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 ADC definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for LH7A404 component:
 *         Analog to Digital Converter / Touchscreen Controller
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

#ifndef LH7A404_ADC_H
#define LH7A404_ADC_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * ADC Module Register Structure
 **********************************************************************/

/* ADC Module Register Structure */ 
typedef struct 
{
    volatile UNS_32 adchiword;  /* ADC control bank high word
                                   register */
    volatile UNS_32 adcloword;  /* ADC control bank low word register */
    volatile UNS_32 adcresults; /* ADC results register */
    volatile UNS_32 adcie;      /* ADC interrupt enable register */
    volatile UNS_32 adcpcr;     /* ADC power configuation register */
    volatile UNS_32 adcgencfg;  /* ADC general configuration register */
    volatile UNS_32 adcgensts;  /* ADSC general status register */
    volatile UNS_32 adcrawint;  /* ADC raw interrupt status register */
    volatile UNS_32 adcfifosts; /* ADC FIFO status register */
    volatile UNS_32 adchicl[16]; /* ADC high control bank registers */
    volatile UNS_32 adclocl[16]; /* ADC low control bank registers */
    volatile UNS_32 adcidlehi;  /* ADC idle high word register */
    volatile UNS_32 adcidlelo;  /* ADC idle low word register */
    volatile UNS_32 adcmis;     /* ADC masked interrupt status
                                   register */
    volatile UNS_32 adcic;      /* ADC interrupt clear register */
} ADC_REGS_T;

/***********************************************************************
 * ADC control bank high word register defines
 * ADC IN+ MUX definitions used with ADC_INP_MASK
 **********************************************************************/

#define ADC_INP_AN0        0x00000000  /* ADC analog 0 input (UL/X+) */
#define ADC_INP_AN1        0x00000008  /* ADC analog 1 input (UR/X-) */
#define ADC_INP_AN2        0x00000010  /* ADC analog 2 input (LL/Y+) */
#define ADC_INP_AN3        0x00000018  /* ADC analog 3 input (LL/Y-) */
#define ADC_INP_AN4        0x00000020  /* ADC analog 4 input (WIPER) */
#define ADC_INP_AN5        0x00000028  /* ADC analog 5 (reserved) */
#define ADC_INP_AN6        0x00000030  /* ADC analog 6 input */
#define ADC_INP_AN7        0x00000038  /* ADC analog 7 (reserved) */
#define ADC_INP_AN8        0x00000040  /* ADC analog 8 input */
#define ADC_INP_AN9        0x00000048  /* ADC analog 9 input */
#define ADC_INP_AN10       0x00000050  /* ADC analog 10 input (VREF-) */

/***********************************************************************
 * ADC control bank high word register defines
 * ADC REF+ MUX definitions used with ADC_REF_MASK
 **********************************************************************/

#define ADC_REF_VREFP      0x00000000  /* Reference is VREF+ */
#define ADC_REF_AN0        0x00000001  /* Reference is AN0 */
#define ADC_REF_AN2        0x00000002  /* Reference is AN2 */
#define ADC_REF_AN8        0x00000003  /* Reference is AN8 */

/***********************************************************************
 * ADC control bank high word register defines
 **********************************************************************/

#define ADC_REF_MASK       0x00000003  /* ADC reference mask */
#define ADC_INM_MASK       0x00000004  /* ADC negative input mask bit */
#define ADC_INM_GND        0x00000004  /* ADC negative input ground
                                          bit */
#define ADC_INP_MASK       0x00000078  /* ADC positive input mask */
#define ADC_STIME_MASK     0x0000FF80  /* ADC settling time mask */
/* ADC control high bank settling time load macro */
#define ADC_SETTIME(n)     ((n & 0x1F) << 7)
/* ADC control high bank positive input MUX selection load macro */
#define ADC_INPSEL(n)      ((n & 0xF) << 3)
/* ADC control high bank negative input MUX selection load macro */
#define ADC_INNSEL(n)      ((n & 0x1) << 2)
/* ADC control high bank positive reference selection load macro */
#define ADC_REFP_SEL(n)    (n & 0x3)

/***********************************************************************
 * ADC control bank low word register defines
 **********************************************************************/

#define ADC_REF_VREFN      0x00000000  /* Reference is VREF- */
#define ADC_REF_AN1        0x00000001  /* Reference is AN1 */
#define ADC_REF_AN3        0x00000002  /* Reference is AN3 */
#define ADC_REF_AN9        0x00000003  /* Reference is AN9 */
/* ADC control low bank negative reference selection load macro */
#define ADC_REFN_SEL(n)    (n & 0x3)
/* ADC FET bit location for Analog 0 line pullup to VDDA */
#define ADC_FET_AN0_VDDA   0x00000004
/* ADC FET bit location for Analog 0 line pullup via 100K (penirq) */
#define ADC_FET_AN0_VDDA1K 0x00001000
/* ADC FET bit location for Analog 1 line pullup to VDDA */
#define ADC_FET_AN1_VDDA   0x00000008
/* ADC FET bit location for Analog 1 line pulldown to GND */
#define ADC_FET_AN1_GND    0x00000010
/* ADC FET bit location for Analog 2 line pullup to VDDA */
#define ADC_FET_AN2_VDDA   0x00000020
/* ADC FET bit location for Analog 2 line pulldown to GND */
#define ADC_FET_AN2_GND    0x00000040
/* ADC FET bit location for Analog 3 line pulldown to GND */
#define ADC_FET_AN3_GND    0x00000080
/* ADC FET bit location for Analog 4 line pullup via 100K (penirq) */
#define ADC_FET_AN4_VDDA1K 0x00002000
/* ADC FET bit location for Analog 4 line pulldown to GND */
#define ADC_FET_AN4_GND    0x00000100
#define ADC_BIASC_MASK     0x00003FFC  /* ADC bias control bit mask */

/***********************************************************************
 * ADC results register defines
 **********************************************************************/

#define ADC_CBANKTAG       0x0000000F  /* ADC control bank tag mask */
/* Macro for shifting and reading the ADC converter output value */
#define ADC_READ_OUTPUT(n) ((n & 0x000FFC0) >> 6)

/***********************************************************************
 * ADC interrupt enable register defines
 **********************************************************************/

#define ADC_FIFO_OV_INT    0x00000001  /* ADC FIFO overrun enable and
                                          status bit */
#define ADC_WATERM_INT     0x00000002  /* ADC watermark enable and
                                          status bit */
#define ADC_EOS_INT        0x00000004  /* ADC end of sequence enable
                                          and status bit */
#define ADC_PEN_INT        0x00000008  /* ADC pen interrupt enable and
                                          status bit */
#define ADC_BROWN_IRQ_INT  0x00000010  /* ADC brownout interrupt enable
                                          bit (IRQ) */
#define ADC_BROWN_FIQ_INT  0x00000020  /* ADC brownout interrupt enable
                                          bit (FIQ) */
#define ADC_GLOBAL_INT     0x00000040  /* ADC global interrupt enable
                                          bit */

/***********************************************************************
 * ADC power configuation register defines
 **********************************************************************/

/* ADC number of conversions in sequence load mask */
#define ADC_NOC_SET(n)     ((n - 1) & 0xf)
#define ADC_NOC_MASK       0x0000000F  /* ADC number of conversions bit
                                          mask */
#define ADC_REF_ENABLE     0x00000020  /* ADC internal reference buffer
                                          enable bit */
#define ADC_PWM_MASK       0x000000C0  /* ADC power mode bitfield
                                          mask */
#define ADC_PWM_ALL_OFF    0x00000000  /* ADC power mode and clock
                                          off */
#define ADC_PWM_STANDBY    0x00000040  /* ADC standby mode */
#define ADC_PWM_RUN        0x00000080  /* ADC run (always on) mode */
#define ADC_CLKSEL_MASK    0x00000700  /* ADC clock selection bitfield
                                          mask */
#define ADC_CLKSEL_DIV1    0x00000000  /* ADC clock is divide by 1 */
#define ADC_CLKSEL_DIV2    0x00000100  /* ADC clock is divide by 2 */
#define ADC_CLKSEL_DIV4    0x00000200  /* ADC clock is divide by 4 */
#define ADC_CLKSEL_DIV8    0x00000300  /* ADC clock is divide by 8 */
#define ADC_CLKSEL_DIV16   0x00000400  /* ADC clock is divide by 16 */
#define ADC_CLKSEL_DIV32   0x00000500  /* ADC clock is divide by 32 */
#define ADC_CLKSEL_DIV64   0x00000600  /* ADC clock is divide by 64 */
#define ADC_CLKSEL_DIV128  0x00000700  /* ADC clock is divide by 128 */
/* ADC clock divider load macro, clock divider = 2^n */
#define ADC_CLKSEL_SET(n)  ((n & 0x7) << 8)

/***********************************************************************
 * ADC general configuration register defines
 **********************************************************************/

#define ADC_SSM_MASK       0x00000003  /* ADC sequence start mode
                                          mask */
#define ADC_SSM_SSB_PEN    0x00000000  /* ADC SSB or pen interrupt
                                          starts new conversions */
#define ADC_SSM_PEN        0x00000001  /* ADC Pen interrupt starts new
                                          conversions */
#define ADC_SSM_SSB        0x00000002  /* ADC SSB starts new
                                          conversions */
#define ADC_SSM_CONT       0x00000003  /* ADC Continuous conversions */
#define ADC_SSB_START      0x00000004  /* ADC SSB conversion sequence
                                          start enable bit */
#define ADC_WM_MASK        0x00000078  /* ADC watermark mask */
/* ADC load macro to set the watermark level for the conversion FIFO */
#define ADC_WM_SET(n)      (((n - 1) & 0xF) << 3)

/***********************************************************************
 * ADC general status register defines
 **********************************************************************/

#define ADC_CBTAG_MASK     0x0000000F  /* ADC current conversion number
                                          tag mask */
#define ADC_SM_MASK        0x000000F0  /* ADC control bank state machine
                                          status mask */
#define ADC_SM_IDLE        0x00000010  /* ADC state machine idle */
#define ADC_SM_GETDATA     0x00000020  /* ADC state machine is getting
                                          data */
#define ADC_SM_WAITCONV    0x00000040  /* ADC state machine is waiting
                                          for conversion */
#define ADC_SM_EOS         0x00000080  /* ADC state machine at end of
                                          sequence */
#define ADC_PENINT         0x00000100  /* ADC pen raw interrupt status
                                          bit */
#define ADC_BROWNOUTINT    0x00000200  /* ADC brownout raw interrupt
                                          status bit */

/***********************************************************************
 * ADC raw and masked interrupt status register defines
 **********************************************************************/

#define ADC_FIFO_OV_IRQ    0x00000001  /* ADC FIFO overrun raw interrupt
                                          is active */
#define ADC_WATERM_IRQ     0x00000002  /* ADC FIFO watermark raw
                                          interrupt is active */
#define ADC_EOS_IRQ        0x00000004  /* ADC FIFO endo of sequence raw
                                          interrupt is active */
#define ADC_PEN_IRQ        0x00000008  /* ADC FIFO pen raw interrupt is
                                          active */
#define ADC_BROWNOUT_IRQ   0x00000010  /* ADC FIFO brownout raw
                                          interrupt is active */

/***********************************************************************
 * ADC FIFO status register defines
 **********************************************************************/

#define ADC_FIFO_GTEWM     0x00000001  /* ADC FIFO is at or above
                                          watermark level */
#define AFC_FIFO_OV        0x00000002  /* ADC FIFO has overrun */
#define ADC_FIFO_EMPTY     0x00000004  /* ADC FIFO is empty */
#define ADC_FIFO_FULL      0x00000008  /* ADC FIFO is full */
/* ADC FIFO read pointer load macro */
#define ADC_FIFO_RDPTR(n)  ((n & 0x000000F0) >> 4)
/* ADC FIFO write pointer load macro */
#define ADC_FIFO_WRPTR(n)  ((n & 0x00000F00) >> 8)

/***********************************************************************
 * ADC interrupt clear register defines
 **********************************************************************/

#define ADC_EOS_CLR        0x00000001 /* ADC EOS interrupt clear bit */
#define ADC_PEN_CLR        0x00000002 /* ADC pen interrupt clear bit */
#define ADC_BROWNOUT_CLR   0x00000004 /* ADC brownout interrupt clear
                                         bit */

/***********************************************************************
 * ADC miscellaneous defines
 **********************************************************************/

/* Number of ADC clocks needed to perform a conversion */
#define ADC_SAMPLE_CLKS    17

/* Macro pointing to ADC registers */
#define ADC ((ADC_REGS_T *)(ADC_BASE))

#endif /*LH7A404_ADC_H */

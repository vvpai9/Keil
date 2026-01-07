/***********************************************************************
 * $Id:: lh79524_adc.h 27 2007-08-31 19:35:06Z kevinw                  $
 *
 * Project: LH79524 ADC definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for LH79524 component:
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

#ifndef LH79524_ADC_H
#define LH79524_ADC_H

#include "lpc_types.h"
#include "lh79524_chip.h"

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

#define ADC_INP_AN0        _SBF(3,0x00)  /* ADC analog 0 input (UL/X+) */
#define ADC_INP_AN1        _SBF(3,0x01)  /* ADC analog 1 input (UR/X-) */
#define ADC_INP_AN2        _SBF(3,0x02)  /* ADC analog 2 input (LL/Y+) */
#define ADC_INP_AN3        _SBF(3,0x03)  /* ADC analog 3 input (LL/Y-) */
#define ADC_INP_AN4        _SBF(3,0x04)  /* ADC analog 4 input (WIPER) */
#define ADC_INP_AN5        _SBF(3,0x05)  /* ADC analog 5 (reserved) */
#define ADC_INP_AN6        _SBF(3,0x06)  /* ADC analog 6 input */
#define ADC_INP_AN7        _SBF(3,0x07)  /* ADC analog 7 (reserved) */
#define ADC_INP_AN8        _SBF(3,0x08)  /* ADC analog 8 input */
#define ADC_INP_AN9        _SBF(3,0x09)  /* ADC analog 9 input */
#define ADC_INP_AN10       _SBF(3,0x0A)  /* ADC analog 10 input (VREF-) */

/***********************************************************************
 * ADC control bank high word register defines
 * ADC REF+ MUX definitions used with ADC_REF_MASK
 **********************************************************************/

#define ADC_REF_VREFP      _SBF(0,0x00)  /* Reference is VREF+ */
#define ADC_REF_AN0        _SBF(0,0x01)  /* Reference is AN0 */
#define ADC_REF_AN2        _SBF(0,0x02)  /* Reference is AN2 */
#define ADC_REF_AN8        _SBF(0,0x03)  /* Reference is AN8 */

/***********************************************************************
 * ADC control bank high word register defines
 **********************************************************************/
/* ADC reference mask */
#define ADC_REF_MASK       _BITMASK(2)  
/* ADC negative input mask bit */
#define ADC_INM_MASK       _BIT(2)    
/* ADC negative input ground bit */
#define ADC_INM_GND        _BIT(2)    
/* ADC positive input mask */                                        
#define ADC_INP_MASK       _SBF(3,_BITMASK(4))
                                             
/* ADC settling time  mask */
#define ADC_STIME_MASK     _SBF(7,_BITMASK(9))
/* ADC control high bank settling time load macro */
#define ADC_SETTIME(n)     (((n) & 0x1FF) << 7)
/* ADC settling time bitfield width */
#define ADC_SETTIME_WIDTH   9  

/* ADC control high bank positive input MUX selection load macro */
#define ADC_INPSEL(n)      (((n) & 0xF) << 3)
/* ADC control high bank negative input MUX selection load macro */
#define ADC_INNSEL(n)      (((n) & 0x1) << 2)
/* ADC control high bank positive reference selection load macro */
#define ADC_REFP_SEL(n)    ((n) & 0x3)

/***********************************************************************
 * ADC control bank low word register defines
 **********************************************************************/

#define ADC_REF_VREFN      _SBF(0,0x00)  /* Reference is VREF- */
#define ADC_REF_AN1        _SBF(0,0x01)  /* Reference is AN1 */
#define ADC_REF_AN3        _SBF(0,0x02)  /* Reference is AN3 */
#define ADC_REF_AN9        _SBF(0,0x03)  /* Reference is AN9 */
/* ADC control low bank negative reference selection load macro */
#define ADC_REFN_SEL(n)    ((n) & 0x3)
/* ADC FET bit location for Analog 0 line pullup to VDDA */
#define ADC_FET_AN0_VDDA   _BIT(2)
/* ADC FET bit location for Analog 0 line pullup via 100K (penirq) */
#define ADC_FET_AN0_VDDA1K _BIT(12)
/* ADC FET bit location for Analog 1 line pullup to VDDA */
#define ADC_FET_AN1_VDDA   _BIT(3)
/* ADC FET bit location for Analog 1 line pulldown to GND */
#define ADC_FET_AN1_GND    _BIT(4)
/* ADC FET bit location for Analog 2 line pullup to VDDA */
#define ADC_FET_AN2_VDDA   _BIT(5)
/* ADC FET bit location for Analog 2 line pulldown to GND */
#define ADC_FET_AN2_GND    _BIT(6)
/* ADC FET bit location for Analog 3 line pulldown to GND */
#define ADC_FET_AN3_GND    _BIT(7)
/* ADC FET bit location for Analog 4 line pullup via 100K (penirq) */
#define ADC_FET_AN4_VDDA1K _BIT(13)
/* ADC FET bit location for Analog 4 line pulldown to GND */
#define ADC_FET_AN4_GND    _BIT(8)
/* ADC bias control bit mask */
#define ADC_BIASC_MASK     _SBF(2,_BITMASK(12)) 

/***********************************************************************
 * ADC results register defines
 **********************************************************************/
/* ADC control bank tag mask */
#define ADC_CBANKTAG       _BITMASK(4)  
/* Macro for shifting and reading the ADC converter output value */
#define ADC_READ_OUTPUT(n) (((n) >> 6) & _BITMASK(10))

/***********************************************************************
 * ADC interrupt enable register defines
 **********************************************************************/
/* ADC FIFO overrun enable and status bit */
#define ADC_FIFO_OV_INT    _BIT(0)  
/* ADC watermark enable and status bit */                                         
#define ADC_WATERM_INT     _BIT(1)  
/* ADC end of sequence enable  and status bit */                                      
#define ADC_EOS_INT        _BIT(2)  
/* ADC pen interrupt enable and status bit */                                     
#define ADC_PEN_INT        _BIT(3)  
/* ADC brownout interrupt enable bit (IRQ) */                                        
#define ADC_BROWN_IRQ_INT  _BIT(4)  
/* ADC brownout  interrupt independent of the combined TSCINTR 
   interrupt enable bit*/                                         
#define ADC_BROWN_ISE_INT  _BIT(5)  
/* ADC global interrupt enable bit */                                 
#define ADC_GLOBAL_INT     _BIT(6)  
                                          

/***********************************************************************
 * ADC power configuation register defines
 **********************************************************************/

/* ADC number of conversions in sequence load mask */
#define ADC_NOC_SET(n)     (((n) - 1) & _BITMASK(4))
/* ADC number of conversions bit mask */
#define ADC_NOC_MASK       _BITMASK(4) 
/* ADC Battery Control enable bit */
#define ADC_BAT_ENABLE     _BIT(4)    
/* ADC internal reference buffer enable bit */                                       
#define ADC_REF_ENABLE     _BIT(5)     
/* ADC power mode bitfield mask */                                       
#define ADC_PWM_MASK       _SBF(6,_BITMASK(2))
/* ADC power mode and clock off */                                      
#define ADC_PWM_ALL_OFF    _SBF(6,0x0)  
/* ADC standby mode */                                         
#define ADC_PWM_STANDBY    _SBF(6,0x1)
/* ADC run (always on) mode */  
#define ADC_PWM_RUN        _SBF(6,0x2)  
/* ADC clock selection bitfield mask */
#define ADC_CLKSEL_MASK    _SBF(8,_BITMASK(3))  
/* ADC clock selection bitfield width */
#define ADC_CLKSEL_WIDTH   3  
                                         
#define ADC_CLKSEL_DIV1    _SBF(8,0x0) /* ADC clock is divide by 1 */
#define ADC_CLKSEL_DIV2    _SBF(8,0x1) /* ADC clock is divide by 2 */
#define ADC_CLKSEL_DIV4    _SBF(8,0x2) /* ADC clock is divide by 4 */
#define ADC_CLKSEL_DIV8    _SBF(8,0x3) /* ADC clock is divide by 8 */
#define ADC_CLKSEL_DIV16   _SBF(8,0x4) /* ADC clock is divide by 16 */
#define ADC_CLKSEL_DIV32   _SBF(8,0x5) /* ADC clock is divide by 32 */
#define ADC_CLKSEL_DIV64   _SBF(8,0x6) /* ADC clock is divide by 64 */
#define ADC_CLKSEL_DIV128  _SBF(8,0x7) /* ADC clock is divide by 128 */
/* ADC clock divider load macro, clock divider = 2^n */
#define ADC_CLKSEL_SET(n)  (((n) & 0x7) << 8)
#define ADC_CLKSEL_GET(n)   (((n) & ADC_CLKSEL_MASK) >> 8)

/***********************************************************************
 * Physical limits on the ADC clock (Hz)
 **********************************************************************/
#define ADC_MAX_CLK 2000000
#define ADC_MIN_CLK 200000

/***********************************************************************
 * ADC general configuration register defines
 **********************************************************************/
/* ADC sequence start mode mask */
#define ADC_SSM_MASK       _BITMASK(2)  
/* ADC SSB or pen interrupt starts new conversions */                                        
#define ADC_SSM_SSB_PEN    _SBF(0,0x0)  
/* ADC Pen interrupt starts new conversions */                                         
#define ADC_SSM_PEN        _SBF(0,0x1)  
/* ADC SSB starts new conversions */                                         
#define ADC_SSM_SSB        _SBF(0,0x2)
/* ADC Continuous conversions */  
#define ADC_SSM_CONT       _SBF(0,0x3)
/* ADC SSB conversion sequence start enable bit */ 
#define ADC_SSB_START      _BIT(2)  
/* ADC watermark mask */                                         
#define ADC_WM_MASK        _SBF(3,_BITMASK(4))  
/* ADC load macro to set the watermark level for the conversion FIFO */
#define ADC_WM_SET(n)      ((((n) - 1) & 0xF) << 3)

/***********************************************************************
 * ADC general status register defines
 **********************************************************************/
/* ADC current conversion number tag mask */
#define ADC_CBTAG_MASK     _BITMASK(4) 
/* ADC control bank state machine status mask */                                         
#define ADC_SM_MASK        _SBF(4,_BITMASK(4))  
/* ADC state machine idle */                                         
#define ADC_SM_IDLE        _SBF(4,0x00)
/* ADC state machine is getting data */ 
#define ADC_SM_GETDATA     _SBF(4,0x02)  
/* ADC state machine is waiting for conversion */                                        
#define ADC_SM_WAITCONV    _SBF(4,0x04)  
/* ADC state machine at end of sequence */                                        
#define ADC_SM_EOS         _SBF(4,0x08)  
/* ADC pen raw interrupt status bit */                                         
#define ADC_PENINT         _BIT(8)  
/* ADC brownout raw interrupt status bit */                                         
#define ADC_BROWNOUTINT    _BIT(9)  
                                         

/***********************************************************************
 * ADC raw and masked interrupt status register defines
 **********************************************************************/

#define ADC_FIFO_OV_IRQ    _BIT(0)  /* ADC FIFO overrun raw interrupt
                                          is active */
#define ADC_WATERM_IRQ     _BIT(1)  /* ADC FIFO watermark raw
                                          interrupt is active */
#define ADC_EOS_IRQ        _BIT(2)  /* ADC FIFO endo of sequence raw
                                          interrupt is active */
#define ADC_PEN_IRQ        _BIT(3)  /* ADC FIFO pen raw interrupt is
                                          active */
#define ADC_BROWNOUT_IRQ   _BIT(4)  /* ADC FIFO brownout raw
                                          interrupt is active */

/***********************************************************************
 * ADC FIFO status register defines
 **********************************************************************/

#define ADC_FIFO_GTEWM     _BIT(0)  /* ADC FIFO is at or above
                                          watermark level */
#define AFC_FIFO_OV        _BIT(1)  /* ADC FIFO has overrun */
#define ADC_FIFO_EMPTY     _BIT(2)  /* ADC FIFO is empty */
#define ADC_FIFO_FULL      _BIT(3)  /* ADC FIFO is full */
/* ADC FIFO read pointer load macro */
#define ADC_FIFO_RDPTR(n)  _SBF(4,((n) & _BITMASK(4)))
/* ADC FIFO write pointer load macro */
#define ADC_FIFO_WRPTR(n)  _SBF(8,((n) & _BITMASK(4)))

/***********************************************************************
 * ADC interrupt clear register defines
 **********************************************************************/

#define ADC_EOS_CLR        _BIT(0) /* ADC EOS interrupt clear bit */
#define ADC_PEN_CLR        _BIT(1) /* ADC pen interrupt clear bit */
#define ADC_BROWNOUT_CLR   _BIT(2) /* ADC brownout interrupt clear
                                         bit */

/***********************************************************************
 * ADC miscellaneous defines
 **********************************************************************/

/* Number of ADC clocks needed to perform a conversion */
#define ADC_SAMPLE_CLKS    17

/* Macro pointing to ADC registers */
#define ADC ((ADC_REGS_T *)(ADC_BASE))

#endif /*LH79524_ADC_H */

/***********************************************************************
 * $Id:: lh79524_timer.h 27 2007-08-31 19:35:06Z kevinw                $
 *
 * Project: LH79524 headers
 *
 * Description:
 *      This file contains the structure definitions and manifest
 *      constants for LH79524 component:
 *          TIMER0, TIMER1 & TIMER2
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

#ifndef LH79524_TIMER_H
#define LH79524_TIMER_H


/***********************************************************************
 * Timer 0 Module Register Structure
 **********************************************************************/

typedef struct TIMER0_REGS_S
{
/* Control register */
   volatile UNS_32 ctrl;         
/* Compare/Capture control */
   volatile UNS_32 cmp_cap_ctrl; 
/* Interrupt control */
   volatile UNS_32 int_ctrl;     
/* Status register */
   volatile UNS_32 status;       
/* Counter register */
   volatile UNS_32 cnt;          
/* Compare register 0 */
   volatile UNS_32 cmp0;         
/* Compare register 1 */
   volatile UNS_32 cmp1;         
/* Capture register 0 */
   volatile UNS_32 cap0;         
/* Capture register 1 */
   volatile UNS_32 cap1;        
/* Capture register 2 */ 
   volatile UNS_32 cap2;        
/* Capture register 3 */
   volatile UNS_32 cap3;        
/* Capture register 4 */ 
   volatile UNS_32 cap4;        
} TIMER0_REGS_T, *PTIMER0_REGS_T;


/***********************************************************************
 * Timer 1 & 2 Module Register Structure
 **********************************************************************/

typedef struct TIMER_REGS_S
{
/* Control register */
  volatile UNS_32 ctrl;    
/* Interrupt control */     
  volatile UNS_32 int_ctrl;
/* Status register */
  volatile UNS_32 status;
/* Counter register */
  volatile UNS_32 cnt;
/* Compare register 0 */ 
  volatile UNS_32 cmp0;
/* Compare register 1 */
  volatile UNS_32 cmp1;
/* Capture register 0 */
  volatile UNS_32 cap0;
/* Capture register 1 */
  volatile UNS_32 cap1;
} TIMER_REGS_T, *PTIMER_REGS_T;

/***********************************************************************
 * Timer 0 Control Register Bit Field constants
 * All other bits in the Timer Control Register must be written as
 * zero
 **********************************************************************/
#define TM0_CTRL_CCL         _BIT(0)
#define TM0_CTRL_CS          _BIT(1)
#define TM0_CTRL_SEL_BIT     2
#define TM0_CTRL_SEL(n)      _SBF(2, (n) & _BITMASK(3))
#define TM0_CTRL_CTCLK       7

/***********************************************************************
 * Timer 0 Capture Compare Control Register Bit Field constants
 **********************************************************************/

#define TM0_CMPCAP_CAP0_RE   _SBF(0,1) /* Rising edge of CTCAP0A */
#define TM0_CMPCAP_CAP0_FE   _SBF(0,2) /* Falling edge of CTCAPOA */
#define TM0_CMPCAP_CAP0_BE   _SBF(0,3) /* Both edges of CTCAP0A */
#define TM0_CMPCAP_CAP0_NA   _SBF(0,0) /* Ignore Capture input CTCAP0A*/

#define TM0_CMPCAP_CAP1_RE   _SBF(2,1) /* Rising edge of CTCAP0B */
#define TM0_CMPCAP_CAP1_FE   _SBF(2,2) /* Falling edge of CTCAPOB */
#define TM0_CMPCAP_CAP1_BE   _SBF(2,3) /* Both edges of CTCAP0B */
#define TM0_CMPCAP_CAP1_NA   _SBF(2,0) /* Ignore Capture input CTCAP0B*/

#define TM0_CMPCAP_CAP2_RE   _SBF(4,1) /* Rising edge of CTCAP0C */
#define TM0_CMPCAP_CAP2_FE   _SBF(4,2) /* Falling edge of CTCAPOC */
#define TM0_CMPCAP_CAP2_BE   _SBF(4,3) /* Both edges of CTCAP0C */
#define TM0_CMPCAP_CAP2_NA   _SBF(4,0) /* Ignore Capture input CTCAP0C*/

#define TM0_CMPCAP_CAP3_RE   _SBF(6,1) /* Rising edge of CTCAP0D */
#define TM0_CMPCAP_CAP3_FE   _SBF(6,2) /* Falling edge of CTCAPOD */
#define TM0_CMPCAP_CAP3_BE   _SBF(6,3) /* Both edges of CTCAP0D */
#define TM0_CMPCAP_CAP3_NA   _SBF(6,0) /* Ignore Capture input CTCAP0D*/

#define TM0_CMPCAP_CAP4_RE   _SBF(8,1) /* Rising edge of CTCAP0E */
#define TM0_CMPCAP_CAP4_FE   _SBF(8,2) /* Falling edge of CTCAPOE */
#define TM0_CMPCAP_CAP4_BE   _SBF(8,3) /* Both edges of CTCAP0E */
#define TM0_CMPCAP_CAP4_NA   _SBF(8,0) /* Ignore Capture input CTCAP0E*/

#define TM0_CMPCAP_CMP0_BIT   10
/* Output '0' on CTCMP0A */
#define TM0_CMPCAP_CMP0_LOW   _SBF(TM0_CMPCAP_CMP0_BIT,1)
/* Output '1' on CTCMPOA */
#define TM0_CMPCAP_CMP0_HIGH  _SBF(TM0_CMPCAP_CMP0_BIT,2)
/* Toggle state of CTCMP0A */
#define TM0_CMPCAP_CMP0_TGL   _SBF(TM0_CMPCAP_CMP0_BIT,3)
/* No change on CTCMP0A */
#define TM0_CMPCAP_CMP0_NA    _SBF(TM0_CMPCAP_CMP0_BIT,0)

#define TM0_CMPCAP_CMP1_BIT   12
/* Output '0' on CTCMP0B */
#define TM0_CMPCAP_CMP1_LOW   _SBF(TM0_CMPCAP_CMP1_BIT,1)
/* Output '1' on CTCMPOB */
#define TM0_CMPCAP_CMP1_HIGH  _SBF(TM0_CMPCAP_CMP1_BIT,2)
/* Toggle state of CTCMP0B */
#define TM0_CMPCAP_CMP1_TGL   _SBF(TM0_CMPCAP_CMP1_BIT,3)
/* No change on CTCMP0B */
#define TM0_CMPCAP_CMP1_NA    _SBF(TM0_CMPCAP_CMP1_BIT,0)

/* clear count on CMP1 match */
#define TM0_CMPCAP_TC       _BIT(14)
/* Timer is in PWM mode */
#define TM0_CMPCAP_PWM      _BIT(15)

/***********************************************************************
 * Timer 0 Interrupt Control Register Bit Field constants
 * Timer 0 Status Register Bit Field constants
 **********************************************************************/
#define TM0_INTCTRL_OVF     _BIT(0)
#define TM0_INTCTRL_CMP0    _BIT(1)
#define TM0_INTCTRL_CMP1    _BIT(2)
#define TM0_INTCTRL_CAP0    _BIT(3)
#define TM0_INTCTRL_CAP1    _BIT(4)
#define TM0_INTCTRL_CAP2    _BIT(5)
#define TM0_INTCTRL_CAP3    _BIT(6)
#define TM0_INTCTRL_CAP4    _BIT(7)
#define TM0_INTCTRL_ALL     (TM0_INTCTRL_OVF | \
                             TM0_INTCTRL_CMP0 | \
                             TM0_INTCTRL_CMP1 | \
                             TM0_INTCTRL_CAP0 | \
                             TM0_INTCTRL_CAP1 | \
                             TM0_INTCTRL_CAP2 | \
                             TM0_INTCTRL_CAP3 | \
                             TM0_INTCTRL_CAP4)


/***********************************************************************
 * Timer 1, 2 Control Register Bit Field constants
 **********************************************************************/
#define TM12_CTRL_CCL        _BIT(0)
#define TM12_CTRL_CS         _BIT(1)
#define TM12_CTRL_SEL_BIT    2
#define TM12_CTRL_SEL(n)     _SBF(2, ((n)&_BITMASK(3)))
#define TM12_CTRL_CTCLK      7

#define TM12_CTRL_CAP0_BIT   5
/* Rising edge of CTCAP1A */
#define TM12_CTRL_CAP0_RE    _SBF(TM12_CTRL_CAP0_BIT,1)
/* Falling edge of CTCAP1A */
#define TM12_CTRL_CAP0_FE    _SBF(TM12_CTRL_CAP0_BIT,2)
/* Both edges of CTCAP1A */
#define TM12_CTRL_CAP0_BE    _SBF(TM12_CTRL_CAP0_BIT,3)
/* Ignore Capture input CTCAP1A*/
#define TM12_CTRL_CAP0_NA    _SBF(TM12_CTRL_CAP0_BIT,0)

#define TM12_CTRL_CAP1_BIT   7
/* Rising edge of CTCAP1B */
#define TM12_CTRL_CAP1_RE    _SBF(TM12_CTRL_CAP1_BIT,1)
/* Falling edge of CTCAP1B */
#define TM12_CTRL_CAP1_FE    _SBF(TM12_CTRL_CAP1_BIT,2)
/* Both edges of CTCAP1B */
#define TM12_CTRL_CAP1_BE    _SBF(TM12_CTRL_CAP1_BIT,3)
/* Ignore Capture input CTCAP1B*/
#define TM12_CTRL_CAP1_NA    _SBF(TM12_CTRL_CAP1_BIT,0)

/* Output '0' on CTCMP0A */
#define TM12_CTRL_CMP0_BIT   9
#define TM12_CTRL_CMP0_LOW   _SBF(TM12_CTRL_CMP0_BIT,1)
/* Output '1' on CTCMPOA */
#define TM12_CTRL_CMP0_HIGH  _SBF(TM12_CTRL_CMP0_BIT,2)
/* Toggle state of CTCMP0A */
#define TM12_CTRL_CMP0_TGL   _SBF(TM12_CTRL_CMP0_BIT,3)
/* No change on CTCMP0A */
#define TM12_CTRL_CMP0_NA    _SBF(TM12_CTRL_CMP0_BIT,0)

#define TM12_CTRL_CMP1_BIT   11
/* Output '0' on CTCMP0B */
#define TM12_CTRL_CMP1_LOW   _SBF(TM12_CTRL_CMP1_BIT,1)
/* Output '1' on CTCMPOB */
#define TM12_CTRL_CMP1_HIGH  _SBF(TM12_CTRL_CMP1_BIT,2)
/* Toggle state of CTCMP0B */
#define TM12_CTRL_CMP1_TGL   _SBF(TM12_CTRL_CMP1_BIT,3)
/* No change on CTCMP0B */
#define TM12_CTRL_CMP1_NA    _SBF(TM12_CTRL_CMP1_BIT,0)

/* clear count on CMP1 match */
#define TM12_CTRL_TC         _BIT(13)
/* Timer is in PWM mode */
#define TM12_CTRL_PWM        _BIT(14)

/***********************************************************************
 * Timer 1, 2 Interrupt Control Register Bit Field constants
 * Timer 1, 2 Status Register Bit Field constants
 **********************************************************************/
#define TM12_INTCTRL_OVF     _BIT(0)
#define TM12_INTCTRL_CMP0    _BIT(1)
#define TM12_INTCTRL_CMP1    _BIT(2)
#define TM12_INTCTRL_CAP0    _BIT(3)
#define TM12_INTCTRL_CAP1    _BIT(4)
#define TM12_INTCTRL_ALL    (TM12_INTCTRL_OVF | \
                             TM12_INTCTRL_CMP0 | \
                             TM12_INTCTRL_CMP1 | \
                             TM12_INTCTRL_CAP0 | \
                             TM12_INTCTRL_CAP1)


#define N_TIMER0             1
#define N_TIMER              2
#define MSECS_PER_SEC        (1000)
#define USECS_PER_SEC        (1000 * MSECS_PER_SEC)

/* Macro pointing to timer registers at timer 0 base address */
#define TIMER0 ((TIMER0_REGS_T *)(TIMER0_BASE))
/* Macro pointing to timer registers at timer 1 base address */
#define TIMER1 ((TIMER_REGS_T *)(TIMER1_BASE))
/* Macro pointing to timer registers at timer 2 base address */
#define TIMER2 ((TIMER_REGS_T *)(TIMER2_BASE))


#endif /* LH79524_TIMER_H */

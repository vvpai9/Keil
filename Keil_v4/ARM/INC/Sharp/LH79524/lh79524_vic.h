/**********************************************************************
 * $Id:: lh79524_vic.h 27 2007-08-31 19:35:06Z kevinw                  $
 *
 *  Project: LH79520 VIC controller header file
 *
 *  Description:
 *      This file contains the definitions for VIC controller on
 *      LH79520
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
 *********************************************************************/

#if !defined LH79520_VIC_H
#define LH79520_VIC_H

#include "lh79524_chip.h"

/*
 * Vectored Interrupt Controller Module Register Structure
 */ 
typedef struct 
{
    volatile UNS_32 irqstatus;
    volatile UNS_32 fiqstatus;
    volatile UNS_32 rawintr;
    volatile UNS_32 intselect;
    volatile UNS_32 intenable;
    volatile UNS_32 intenclear;
    volatile UNS_32 softint;
    volatile UNS_32 softintclear;
    volatile UNS_32 reserved1[4];
    volatile UNS_32 vectoraddr;     
    volatile UNS_32 defvectaddr;
    volatile UNS_32 reserved2[50];
    volatile UNS_32 vectaddr[16];   /* name arranged as array */ 
    volatile UNS_32 reserved3[48];
    volatile UNS_32 vectcntl[16];   /* name arranged as array */ 
    volatile UNS_32 reserved4[51];
    volatile UNS_32 itop1;
} VIC_REGS_TYPE;

/**********************************************************************
 * Vectored Interrupt Controller Register Bit Fields
 *********************************************************************/ 

/**********************************************************************
 * The bit fields of the following registers have implementation
 * specific meaning, and must be defined at the implementation level.
 *
 *      irqstatus   - VICIRQStatus
 *      fiqstatus   - VICFIQStatus
 *      rawintr     - VICRawIntr
 *      intselect   - VICIntSelect
 *      intenable   - VICIntEnable
 *      intenclear  - VICIntEnClear
 *      softint     - VICSoftInt
 *      softintclear- VICSoftIntClear
 *
 * The following definitions for these registers are generic,
 * i.e., they are implementation independent. They can be used to
 * create implementation specific macros.
 *********************************************************************/ 

/**********************************************************************
 * VIC Interrupt Select Register Bit Fields
 *********************************************************************/ 
/* The following can be OR'd with the IntSelect Register to select
 * an interrupt as FIQ. */ 
#define VIC_INTSELECT_FIQ(n)    _BIT((n) & _BITMASK(5))
/* The following can be AND'd with the IntSelect Register to select
 * an interrupt as IRQ. */ 
#define VIC_INTSELECT_IRQ(n)    ~(_BIT((n) & _BITMASK(5)))

/* constant for IRQ type */
#define VIC_INT_TYPE_IRQ    0
/* constant for FIQ type */
#define VIC_INT_TYPE_FIQ    1

/**********************************************************************
 * VIC Interrupt Enable, Interrupt Enable Clear Register Bit Fields
 * VIC Soft Interrupt, Soft Interrupt Clear Register Bit Fields
 *********************************************************************/ 
/* bit field definition for VIC interruption enable */
#define VIC_INT_ENABLE(n)       _BIT((n) & _BITMASK(5))
/* bit field definition for VIC interruption clear */
#define VIC_INT_CLEAR(n)        _BIT((n) & _BITMASK(5))

/**********************************************************************
 * VIC Vector Address Clear Register 
 *********************************************************************/ 
#define VIC_VECTORADDR_CLEAR    0

/**********************************************************************
 * VIC Vector Control Register Bit Fields
 *********************************************************************/ 

/* To revise a Vector Control Register, clear the register, then 
 * use the SELECT macro to associate a line and enable the vector 
 * with the same operation.
 * The ENABLE macro is provided for completeness.
 * Use this register to enable and disable the VECTOR feature;
 * use the intenable register to enable the interrupt
 * itself, and the intenclear register to clear the interrupt. */ 
#define VIC_VECTCNTL_SELECT(n)  (_SBF(0,((n) & _BITMASK(5))) | _BIT(5))
/* vic vector control register enable bit */
#define VIC_VECTCNTL_ENABLE     _BIT(5)

/**********************************************************************
 * Vectored Interrupt Controller Register ITOP1   - Test Output 1
 * (used for debugging)
 *********************************************************************/ 
/* vic interruption ITOP1 register bits - FIQ */
#define VIC_ITOP1_FIQ         _BIT(6)
/* vic interruption ITOP1 register bits - IRQ */
#define VIC_ITOP1_IRQ         _BIT(7)

/***********************************************************************
 * VIC Vectors
 **********************************************************************/
/* vectored interruption number - VIC 0 */ 
#define VIC_VECT_0          0
/* vectored interruption number - VIC 1 */ 
#define VIC_VECT_1          1
/* vectored interruption number - VIC 2 */ 
#define VIC_VECT_2          2
/* vectored interruption number - VIC 3 */ 
#define VIC_VECT_3          3
/* vectored interruption number - VIC 4 */ 
#define VIC_VECT_4          4
/* vectored interruption number - VIC 5 */ 
#define VIC_VECT_5          5
/* vectored interruption number - VIC 6 */ 
#define VIC_VECT_6          6
/* vectored interruption number - VIC 7 */ 
#define VIC_VECT_7          7
/* vectored interruption number - VIC 8 */ 
#define VIC_VECT_8          8
/* vectored interruption number - VIC 9 */ 
#define VIC_VECT_9          9
/* vectored interruption number - VIC 10 */ 
#define VIC_VECT_10         10
/* vectored interruption number - VIC 11 */ 
#define VIC_VECT_11         11
/* vectored interruption number - VIC 12 */ 
#define VIC_VECT_12         12
/* vectored interruption number - VIC 13 */ 
#define VIC_VECT_13         13
/* vectored interruption number - VIC 14 */ 
#define VIC_VECT_14         14
/* vectored interruption number - VIC 15 */ 
#define VIC_VECT_15         15
/* vectored interruption number - VIC MAX */ 
#define VIC_VECT_MAX        VIC_VECT_15
/* vectored interruption number - VIC default */ 
#define VIC_VECT_DEFAULT    ~(0)

/***********************************************************************
 * LH79520 VIC Interrupt Sources
 **********************************************************************/
typedef enum
{
  VIC_WDT = 0,      /* Watchdog timer interrupt */
  VIC_RESERVED1,    /* Unused; can be used as SWI */
  VIC_COMRX,        /* Debug comm channel receive interrupt */
  VIC_COMTX,        /* Debug comm channel transmit interrupt */
  VIC_TIMER0,       /* Timer 0 interrupt */
  VIC_TIMER1,       /* Timer 1 interrupt */
  VIC_TIMER2,       /* Timer 2 interrupt */
  VIC_EXINT0,       /* External interrupt 0 */ 
  VIC_EXINT1,       /* External interrupt 1 */
  VIC_EXINT2,       /* External interrupt 2 */
  VIC_EXINT3,       /* External interrupt 3 */
  VIC_EXINT4,       /* External interrupt 4 */
  VIC_EXINT5,       /* External interrupt 5 */
  VIC_EXINT6,       /* External interrupt 6 */
  VIC_EXINT7,       /* External interrupt 7 */
  VIC_RTCINT,       /* Real-time Clock interrupt */
  VIC_ADCTSC,       /* ADC combined interrupt */
  VIC_ADCBO,        /* ADC brown-out detector interrupt */
  VIC_ADCPEN,       /* ADC pen-down detector interrupt */
  VIC_CLCD,         /* Color LCD controller combined interrupt */
  VIC_DMA0,         /* DMA Stream 0 interrupt */
  VIC_DMA1,         /* DMA Stream 1 interrupt */
  VIC_DMA2,         /* DMA Stream 2 interrupt */
  VIC_DMA3,         /* DMA Stream 3 interrupt */
  VIC_SSPI2S,       /* SSP w/ I2S combined interrupt */
  VIC_ETHERNET,     /* Ethernet combined interrupt */
  VIC_USB,          /* USB interrupt */
  VIC_UARTINT0,     /* UART0 combined interrupt */
  VIC_UARTINT1,     /* UART1 combined interrupt */
  VIC_UARTINT2,     /* UART2 combined interrupt */
  VIC_USBDMA,       /* USB DMA interrupt */
  VIC_I2C,          /* I2C interrupt */
   VIC_BAD_SOURCE  /* Invalid source; drivers return this on error */
} INT_SOURCE;

/* Macro pointing to VIC registers */
#define VIC         ((VIC_REGS_TYPE *)(VIC_BASE))
/* Macro pointing to VIC mirror registers */
#define VICMIRROR   ((VIC_REGS_TYPE *)(VIC_BASE_MIRROR))

#endif /* LH79520_VIC_H */ 

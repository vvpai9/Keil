/**********************************************************************
 * $Id:: lh79524_rcpc.h 27 2007-08-31 19:35:06Z kevinw                 $
 *
 *  Project: LH79524 RCPC controller header file
 *
 *  Description:
 *      This file contains the definitions for RCPC controller on
 *      LH79524
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

#ifndef LH79524_RCPC_H
#define LH79524_RCPC_H

#include "lh79524_chip.h"

/**********************************************************************
 * Reset, Clock, and Power Controller Register Structure
 *********************************************************************/ 
typedef struct 
{
  volatile UNS_32 rcpcctrl;        /* RCPC Control */ 
  volatile UNS_32 identification;  /* ID Register */ 
  volatile UNS_32 remap;           /* Remap Control */ 
  volatile UNS_32 softreset;       /* Soft Reset */ 
  volatile UNS_32 resetstatus;     /* Reset Status */ 
  volatile UNS_32 resetstatusclr;  /* Reset Status Clear */ 
  volatile UNS_32 hclkprescale;    /* HCLK Prescale */ 
  volatile UNS_32 cpuclkprescale;  /* Core Clock Prescale */ 
  volatile UNS_32 reserved1;        
  volatile UNS_32 periphclkctrl0;  /* Peripheral Clock Ctrl 0*/ 
  volatile UNS_32 periphclkctrl1;  /* Peripheral Clock Ctrl 1*/
  volatile UNS_32 ahbclkctrl;      /* AHB Clock Ctrl */ 
  volatile UNS_32 pclksel0;    
  volatile UNS_32 pclksel1;
  volatile UNS_32 reserved3;    
  volatile UNS_32 siliconrev;    
  volatile UNS_32 lcdclkprescale;  /* LCD clock Prescale */
  volatile UNS_32 sspclkprescale;  /* SSP clock Prescale */
  volatile UNS_32 adcclkprescale;  /* ADC clock Prescale */
  volatile UNS_32 usbclkprescale;  /* USB clock Prescale */
  volatile UNS_32 reserved4[12];   
  volatile UNS_32 intconfig;       /* Ext. Interrupt Config */
  volatile UNS_32 intclear;        /* Ext. Interrupt Clear  */
  volatile UNS_32 coreclkconfig;   /* Core Clock Config */
  volatile UNS_32 reserved5[13];   
  volatile UNS_32 systempllctrl;   /* System PLL Control Register */
  volatile UNS_32 usbpllctrl;   /* USB PLL Control Register */
} RCPC_REGS_T;

/**********************************************************************
 * Reset, Clock, and Power Controller Register Bit Fields
 *********************************************************************/ 

/**********************************************************************
 * rcpcctrl - RCPCCtrl Register Bit Fields
 *********************************************************************/ 
/* bit fields for power down mode */
#define RCPC_CTRL_PWRDWNSEL(n)  _SBF(2,(n)) /* Power Down Mode Sel*/ 
/* bit fields for power down mode - active mode*/
#define RCPC_PWRDWNSEL_ACTIVE    RCPC_CTRL_PWRDWNSEL(0)
/* bit fields for power down mode - standby mode*/
#define RCPC_PWRDWNSEL_STANDBY   RCPC_CTRL_PWRDWNSEL(1)
/* bit fields for power down mode - sleep mode */
#define RCPC_PWRDWNSEL_SLEEP     RCPC_CTRL_PWRDWNSEL(2)
/* bit fields for power down mode - stop1 mode */
#define RCPC_PWRDWNSEL_STOP1     RCPC_CTRL_PWRDWNSEL(3)
/* bit fields for power down mode - stop2 mode */
#define RCPC_PWRDWNSEL_STOP2     RCPC_CTRL_PWRDWNSEL(4)

/* bit fields for output selection field */
#define RCPC_CTRL_OUTSEL(n)     _SBF(5,(n))
/* bit fields for clock output selection - System Clock Oscillator Clock */
#define RCPC_OUTSEL_CLK_SYSOSC   RCPC_CTRL_OUTSEL(0)
/* bit fields for clock output selection field - clock use fclk */
#define RCPC_OUTSEL_FCLK_CPU     RCPC_CTRL_OUTSEL(2)
/* bit fields for clock output selection field - clock use hclk */
#define RCPC_OUTSEL_HCLK         RCPC_CTRL_OUTSEL(3)

/* bit fields for RCPC controller write lock bit - locked */
#define RCPC_CTRL_WRTLOCK_LOCKED    _SBF(9,0)
/* bit fields for RCPC controller write lock bit - unlocked */
#define RCPC_CTRL_WRTLOCK_UNLOCKED   _SBF(9,1)

/**********************************************************************
 * remap - Remap Control Register Bit Fields
 *********************************************************************/ 
/* bit fields for remap register - set nCS1 static memory at address 0x0 */
#define RCPC_REMAP_CS1MEM0    (0)
/* bit fields for remap register - set nDCS0 SDRAM at address 0x0 */
#define RCPC_REMAP_DCS0MEM0   (1)
/* bit fields for remap register - set internal SRAM at address 0x0 */
#define RCPC_REMAP_IMEM0      (2)
/* bit fields for remap register - set nCS0 static memory at address 0x0 */
#define RCPC_REMAP_CS0MEM0    (3)

/**********************************************************************
 * softreset - Soft Reset Register Bit Fields
 *********************************************************************/ 
/* bit fields for software reset register - reset all */
#define RCPC_SOFTRESET_ALL  (0xDEAD)

/**********************************************************************
 * resetstatus, resetstatusclr - Reset Status Register Bit Fields
 *********************************************************************/ 
/* bit fields for reset status register - reset from external */
#define RCPC_RESET_STATUS_EXT   _BIT(0)
/* bit fields for reset status register - reset from watch dog timer */
#define RCPC_RESET_STATUS_WDTO  _BIT(1)

/**********************************************************************
 * hclkPrescale - HCLK Prescaler Register Bit Fields
 * cpuclkPrescale - Core Clock Prescaler Register Bit Fields
 * sparePrescale - Spare Prescaler Register Bit Fields
 * Note: not all constants are applicable to all registers.
 *  See Reference.
 *********************************************************************/ 
/* bit fields for prescaler divider value - divider is 1 */
#define RCPC_PRESCALER_DIV1     _SBF(0,0)
/* bit fields for prescaler divider value - divider is 2 */
#define RCPC_PRESCALER_DIV2     _SBF(0,1)
/* bit fields for prescaler divider value - divider is 4 */
#define RCPC_PRESCALER_DIV4     _SBF(0,2)
/* bit fields for prescaler divider value - divider is 6 */
#define RCPC_PRESCALER_DIV6     _SBF(0,3)
/* bit fields for prescaler divider value - divider is 8 */
#define RCPC_PRESCALER_DIV8     _SBF(0,4)
/* bit fields for prescaler divider value - divider is 16 */
#define RCPC_PRESCALER_DIV16    _SBF(0,8)
/* bit fields for prescaler divider value - divider is 30 */
#define RCPC_PRESCALER_DIV30    _SBF(0,15)
/* bit fields for prescaler divider value - divider is 32 */
#define RCPC_PRESCALER_DIV32    _SBF(0,16)
/* bit fields for prescaler divider value - divider is 64 */
#define RCPC_PRESCALER_DIV64    _SBF(0,32)
/* bit fields for prescaler divider value - divider is 128 */
#define RCPC_PRESCALER_DIV128   _SBF(0,64)
/* bit fields for prescaler divider value - divider is 256 */
#define RCPC_PRESCALER_DIV256   _SBF(0,128)
/* bit fields for prescaler divider value - divider is 65534 */
#define RCPC_PRESCALER_DIV65534 (0xFFFF)

#define RCPC_HCLK_PRESCALER()      (RCPC->hclkprescale & _BITMASK(4))
#define RCPC_CPUCLK_PRESCALER()    (RCPC->cpuclkprescale & _BITMASK(4))
#define RCPC_ADCCLK_PRESCALER()    (RCPC->adcclkprescale & _BITMASK(8))
#define RCPC_LCDCLK_PRESCALER()    (RCPC->lcdclkprescale & _BITMASK(8))
#define RCPC_SSPCLK_PRESCALER()    (RCPC->sspclkprescale & _BITMASK(8))

/**********************************************************************
 * periphclkctrl - Peripheral Clock Control Register Bit Fields
 * spareclkctrl - Spare Clock Control Register Bit Fields
 * ahbclkctrl - AHB Clock Control Register Bit Fields
 * Writing a "0" to a bit in these registers enables the
 *  corresponding clock
 *********************************************************************/ 
/* clock disable bit field definition - Uart 0 disable */
#define RCPC_CLKCTRL0_U0_DISABLE         _BIT(0)
/* clock disable bit field definition - Uart 1 disable */
#define RCPC_CLKCTRL0_U1_DISABLE         _BIT(1)
/* clock disable bit field definition - Uart 2 disable */
#define RCPC_CLKCTRL0_U2_DISABLE         _BIT(2)
/* clock disable bit field definition - RTC disable */
#define RCPC_CLKCTRL0_RTC_DISABLE        _BIT(9)

/* clock disable bit field definition - LCD disable */
#define RCPC_CLKCTRL1_LCD_DISABLE        _BIT(0)
/* clock disable bit field definition - SSP disable */
#define RCPC_CLKCTRL1_SSP_DISABLE        _BIT(1)
/* clock disable bit field definition - ADC disable */
#define RCPC_CLKCTRL1_ADC_DISABLE        _BIT(2)
/* clock disable bit field definition - USB disable */
#define RCPC_CLKCTRL1_USB_DISABLE        _BIT(3)

/* clock disable bit field definition - DMA disable */
#define RCPC_AHBCLKCTRL_DMA_DISABLE      _BIT(0)
/* clock disable bit field definition - SDRAMC disable */
#define RCPC_AHBCLKCTRL_SDRAMC_DISABLE   _BIT(1)
/* clock disable bit field definition - ETHERNET disable */
#define RCPC_AHBCLKCTRL_ETHERNET_DISABLE _BIT(2)
/* clock disable bit field definition - USB disable */
#define RCPC_AHBCLKCTRL_USB_DISABLE      _BIT(3)
/* clock disable bit field definition - LCD disable */
#define RCPC_AHBCLKCTRL_LCD_DISABLE      _BIT(4)

/**********************************************************************
 * periphclksel0 - Peripheral Clock Select Register Bit Fields
 * Writing a "0" to U0-U2 in this register enables the
 *  System Clock Oscillator as the clock source
 * Writing a "1" to U0-U2 in this register enables the
 *  HCLK as the clock source
 *********************************************************************/ 
/* clock source select bit field - Uart 0 as external */
#define RCPC_PCLKSEL0_U0_HCLK     _BIT(0) /* U0 Clock Source */ 
/* clock source select bit field - Uart 1 as external */
#define RCPC_PCLKSEL0_U1_HCLK     _BIT(1) /* U1 Clock Source */ 
/* clock source select bit field - Uart 2 as external */
#define RCPC_PCLKSEL0_U2_HCLK     _BIT(2) /* U2 Clock Source */ 

/**********************************************************************
 * periphclksel1 - Peripheral Clock Select Register Bit Fields
 *********************************************************************/ 
/* clock source select bit field - Counter 0 as external 
 * Writing a "0" to RCPC_PCLKSEL1_SSP_SCOC in this register enables 
 * the HCLK as the clock source else Writing a "1" selects System 
 * Clock Oscillator as the clock source
 */
#define RCPC_PCLKSEL1_SSP_SCOC    _BIT(1) /* SSP Clock Source */ 
/* clock source select bit field - Counter 1 as external */
#define RCPC_PCLKSEL1_ADC_SCOC    _BIT(2) /* ADC Clock Source */ 
/* clock source select bit field - Counter 2 as external 
 * Writing a "0" to RCPC_PCLKSEL1_USB_PLL in this register enables 
 * the HCLK as the clock source else Writing a "1" selects USB 
 * PLL clock as the clock source
 */
#define RCPC_PCLKSEL1_USB_PLL     _BIT(3) /* USB Clock Source */ 


/**********************************************************************
 * intconfig - External Interrupt Configuration Register Bit Fields
 *********************************************************************/ 
/* macro definition for Intconfig register */
#define RCPC_INTCONFIG(f,v)     _SBF((f),(v))
/* RCPC_INTCONFIG arguments for 'f' parameter */ 
/* bit field - RCPC intconfig select INT 0 */
#define RCPC_INT0       0
/* bit field - RCPC intconfig select INT 1 */
#define RCPC_INT1       2
/* bit field - RCPC intconfig select INT 2 */
#define RCPC_INT2       4
/* bit field - RCPC intconfig select INT 3 */
#define RCPC_INT3       6
/* bit field - RCPC intconfig select INT 4 */
#define RCPC_INT4       8
/* bit field - RCPC intconfig select INT 5 */
#define RCPC_INT5       10
/* bit field - RCPC intconfig select INT 6 */
#define RCPC_INT6       12
/* bit field - RCPC intconfig select INT 7 */
#define RCPC_INT7       14
/* RCPC_INTCONFIG arguments for 'v' parameter */ 
/* bit fields for external INT trigger level - low level */
#define RCPC_INT_LLT    0       /* Low Level Trigger */ 
/* bit fields for external INT trigger level - high level */
#define RCPC_INT_HLT    1       /* High Level Trigger */ 
/* bit fields for external INT trigger level - falling edge */
#define RCPC_INT_FET    2       /* Falling Edge Trigger */ 
/* bit fields for external INT trigger level - rising edge */
#define RCPC_INT_RET    3       /* Rising Edge Trigger */ 

/**********************************************************************
 * intclear - External Interrupt Clear Register Bit Fields
 *********************************************************************/ 
/* macro for intclear register bit fields */
#define RCPC_INTCLEAR(n)    _BIT(n) /* Clear Edge Interrupt 'n' */ 

/**********************************************************************
 * coreclkconfig - Core Clock Configuration Register Bit Fields
 *********************************************************************/ 
/* bit fields for coreclkconfig register - standard mode, async */
#define RCPC_CCC_STDASYNCH      0 /* Standard Mode, Asynch operation */
/* bit fields for coreclkconfig register - fast bus mode */
#define RCPC_CCC_FASTBUS        1 /* Fast Bus Extension Mode */
/* bit fields for coreclkconfig register - standard mode, sync */
#define RCPC_CCC_STDSYNCH       2 /* Standard Mode, Synch operation */

/**********************************************************************
 * SystemPLLCtrl - System PLL Control Register Bit Fields
 *********************************************************************/ 
#define RCPC_SPC_FR_100_TO_305      _BIT(12)
#define RCPC_SPC_MS(x)              ((x >> 6) & _BITMASK(6))
#define RCPC_SPC_NS(x)              (x & _BITMASK(6))
#define RCPC_SPC_SET_MS(x)          ((x & _BITMASK(6)) << 6)
#define RCPC_SPC_SET_NS(x)          (x & _BITMASK(6))


/* Macro pointing to RCPC registers */
#define RCPC    ((RCPC_REGS_T *)(RCPC_BASE))

/**********************************************************************
 *  Macros to compute system clocks based on XTALIN
 *********************************************************************/
#define RCPC_GET_SYSPLL(X)      \
    ((UNS_64)((X) * RCPC_SPC_NS(RCPC->systempllctrl))/\
    RCPC_SPC_MS(RCPC->systempllctrl))

#define RCPC_GET_HCLK(X)        \
    (RCPC_GET_SYSPLL(X)/(1 << RCPC_HCLK_PRESCALER()))
 
#define RCPC_GET_CPUCLK(X)      \
    (RCPC_GET_SYSPLL(X)/(1 << RCPC_CPUCLK_PRESCALER()))
 

#endif /* LH79524_RCPC_H */ 

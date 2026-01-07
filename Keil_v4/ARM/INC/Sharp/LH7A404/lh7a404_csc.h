/***********************************************************************
 * $Id:: lh7a404_csc.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 Clock and State Controller (CSC) definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         Clock and State Controller
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

#ifndef LH7A404_CLKSC_H
#define LH7A404_CLKSC_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * CSC Module Register Structure
 **********************************************************************/

/* Clock and State Controller Module Register Structure */ 
typedef struct
{
    volatile UNS_32 pwrsr;    /* CSC Power/state control status */
    volatile UNS_32 pwrcnt;   /* CSC Clock/debug control status */
    volatile UNS_32 halt;     /* CSC Read to Enter Idle mode */
    volatile UNS_32 stby;     /* CSC Read to Enter Standby mode */
    volatile UNS_32 bleoi;    /* CSC Clear low battery interrupt */
    volatile UNS_32 mceoi;    /* CSC Clear media changed interrupt */
    volatile UNS_32 teoi;     /* CSC Clear tick interrupt */
    volatile UNS_32 stfclr;   /* CSC clr Nbflg, rstflg, pfflg, cldflg */
    volatile UNS_32 clkset;   /* CSC Clock speed control */
    volatile UNS_32 rsvd[7];
    volatile UNS_32 scrreg0;  /* CSC Scratch Register 0 */
    volatile UNS_32 scrreg1;  /* CSC Scratch Register 1 */
    volatile UNS_32 clktest;  /* CSC TEST register */
    volatile UNS_32 usbreset; /* CSC reset of USB APB and I/O */
    volatile UNS_32 apbwait;  /* CSC Peripheral bus wait (do not set) */
    volatile UNS_32 bmar;     /* CSC Bus master arbitration */
    volatile UNS_32 bootclr;  /* CSC boot ROM disable */
} CSC_REGS_T;

/***********************************************************************
 * CSC power and reset register definitions
 **********************************************************************/

#define CSC_RTCDIV_MASK         0x0000003F /* CSC RTC divider mask */
/* CSC media change direct read status bit */
#define CSC_PWRSR_MCDR          0x00000040
/* CSC direct current detect status bit */
#define CSC_PWRSR_DCDET         0x00000080
/* CSC wakeup direct read status bit */
#define CSC_PWRSR_WUDR          0x00000100
/* CSC wakeup on status bit */
#define CSC_PWRSR_WUON          0x00000200
/* CSC new battery status bit */
#define CSC_PWRSR_NBFLG         0x00000400
/* CSC user reset status bit */
#define CSC_PWRSR_RSTFLG        0x00000800
/* CSC power fail status bit */
#define CSC_PWRSR_PFFLG         0x00001000
/* CSC cold start status bit */
#define CSC_PWRSR_CLDFLG        0x00002000
/* CSC PLL2 lock status bit */
#define CSC_PWRSR_LCKFLG        0x00004000
/* CSC Chip ientification mask */
#define	CSC_PWRSR_CHIPID        0x00FF0000
/* CSC Chip manufacturer mask */
#define CSC_PWRSR_CHIPMAN       0xFF000000

/***********************************************************************
 * CSC power control register definitions
 **********************************************************************/

/* CSC watchdog timer reset selection bit */
#define	CSC_WDTRFES_SEL         0x00000001
#define	CSC_PWRCNT_WAKEDIS      0x00000002 /* CSC Wakeup disable bit */
/* CSC PGMCLK divider load value macro */
#define CSC_PWRCNT_PGMCLK(n)    _SBF(8, ((n) & 0x000000FF))
 /* CSC DMA peripheral channel 1 enable bit */
#define CSC_PWRCNT_DMAPCH1      0x00010000
 /* CSC DMA peripheral channel 0 enable bit */
#define CSC_PWRCNT_DMAPCH0      0x00020000
 /* CSC DMA peripheral channel 3 enable bit */
#define CSC_PWRCNT_DMAPCH3      0x00040000
 /* CSC DMA peripheral channel 2 enable bit */
#define CSC_PWRCNT_DMAPCH2      0x00080000
 /* CSC DMA peripheral channel 5 enable bit */
#define CSC_PWRCNT_DMAPCH5      0x00100000
 /* CSC DMA peripheral channel 4 enable bit */
#define CSC_PWRCNT_DMAPCH4      0x00200000
 /* CSC DMA peripheral channel 7 enable bit */
#define CSC_PWRCNT_DMAPCH7      0x00400000
 /* CSC DMA peripheral channel 6 enable bit */
#define CSC_PWRCNT_DMAPCH6      0x00800000
 /* CSC DMA peripheral channel 9 enable bit */
#define CSC_PWRCNT_DMAPCH9      0x01000000
 /* CSC DMA peripheral channel 8 enable bit */
#define CSC_PWRCNT_DMAPCH8      0x02000000
 /* CSC DMA memory to memory channel 0 enable bit */
#define CSC_PWRCNT_DMAMMCH0     0x04000000
 /* CSC DMA memory to memory channel 1 enable bit */
#define CSC_PWRCNT_DMAMMCH1     0x08000000
/* CSC 'all DMA channels' enable bits */
#define CSC_PWRCNT_DMA_ALL      0x0FFF0000
/* CSC USB host enable bit */
#define CSC_USBH_ENABLE         0x10000000
/* CSC UART clock rate selection bit */
#define CSC_UART_14M_CLKSEL     0x20000000

/***********************************************************************
 * CSC clock set register definitions
 **********************************************************************/

/* CSC main divider 1 load macro */
#define CSC_MAINDIV1(n)         _SBF(7, ((n) & 0x0F))
/* CSC main divider 2 load macro */
#define CSC_MAINDIV2(n)         _SBF(11, ((n) & 0x1F))
/* CSC predivider load macro */
#define CSC_PREDIV(n)           _SBF(2, ((n) & 0x1F))
/* CSC HLCK divider of 1 value macro */
#define CSC_HCLKDIV1            0x00000000
/* CSC HLCK divider of 2 value macro */
#define CSC_HCLKDIV2            0x00000001
/* CSC HLCK divider of 3 value macro */
#define CSC_HCLKDIV3            0x00000002
/* CSC HLCK divider of 4 value macro */
#define CSC_HCLKDIV4            0x00000003
/* CSC PLCK divider of 2 value macro */
#define CSC_PCLKDIV2            0x00000000
/* CSC PLCK divider of 4 value macro */
#define CSC_PCLKDIV4            0x00010000
/* CSC PLCK divider of 8 value macro */
#define CSC_PCLKDIV8            0x00020000
/* CSC PS value of 0 (divide by 1) value macro */
#define CSC_PS0                 0x00000000
/* CSC PS value of 1 (divide by 2) value macro */
#define CSC_PS1                 0x00040000
/* CSC PS valu of 2 (divide by 4) value macro */
#define CSC_PS2                 0x00080000
/* CSC PS value of 3 (divide by 8) value macro */
#define CSC_PS3                 0x000C0000
/* CSC disable HCLK to static memory controller on halt bit */
#define CSC_SMCROM              0x01000000

/***********************************************************************
 * CSC USB reset register definitions
 **********************************************************************/

/* CSC USB IO reset bit */
#define CSC_USBRESET_IO         0x00000001
/* CSC USB bus/control reset bit */
#define CSC_USBRESET_CONTROL    0x00000002

/***********************************************************************
 * CSC bus master arbitration register definitions
 **********************************************************************/

/* CSC macro for selecting DMA priority order, USB host before DMA */
#define CSC_BMAR_USBH_DMA       0x00000004
/* CSC macro for selecting DMA priority order, DMA before USB host */
#define CSC_BMAR_DMA_USBH       0x00000001
/* CSC bit for allowing granting ARM core cycles between DMA masters */
#define CSC_BMAR_PRICORE        0x00000008
/* CSC bit for degranting DMA during an IRQ */
#define CSC_BMAR_ENIRQ          0x00000010
/* CSC bit for degranting DMA during an FIQ */
#define CSC_BMAR_ENFIQ          0x00000020

/***********************************************************************
 * Clock Set Codes for CLKSC->clktest register
 * 
 * Use the following manifest constants to set the CPU, AHB, and APB
 * clocking to the indicated frequencies.
 **********************************************************************/

/* CSC macro for CPU: 33 MHz; AHB: 33 MHz; APB: 8.25 MHz (/4) */
#define CSC_33_33_8 (CSC_HCLKDIV1 | \
                     CSC_MAINDIV1(15) | \
                     CSC_MAINDIV2(8) | \
                     CSC_PREDIV(17) | \
                     CSC_PS2 | \
                     CSC_PCLKDIV4)

/* CSC macro for CPU: 33 MHz; AHB: 33 MHz; APB: 16.5 MHz (/2) */
#define CSC_33_33_16 (CSC_HCLKDIV1 | \
                      CSC_MAINDIV1(15) | \
                      CSC_MAINDIV2(8) | \
                      CSC_PREDIV(17) | \
                      CSC_PS2 | \
                      CSC_PCLKDIV2)

/* CSC macro for CPU: 50 MHz; AHB: 50 MHz; APB: 12.5 MHz (/4) */
#define CSC_50_50_12 (CSC_HCLKDIV1 | \
                      CSC_MAINDIV1(11) | \
                      CSC_MAINDIV2(10) | \
                      CSC_PREDIV(21) | \
                      CSC_PS1 | \
                      CSC_PCLKDIV4)

/* CSC macro for CPU: 50 MHz; AHB: 50 MHz; APB: 25 MHz (/2) */
#define CSC_50_50_25 (CSC_HCLKDIV1 | \
                      CSC_MAINDIV1(11) | \
                      CSC_MAINDIV2(10) | \
                      CSC_PREDIV(21) | \
                      CSC_PS1 | \
                      CSC_PCLKDIV2)

/* CSC macro for CPU: 66 MHz; AHB: 33 MHz; APB: 8.25 MHz (/4) */
#define CSC_66_33_8 (CSC_HCLKDIV2 | \
                     CSC_MAINDIV1(15) | \
                     CSC_MAINDIV2(8) | \
                     CSC_PREDIV(17) | \
                     CSC_PS1 | \
                     CSC_PCLKDIV4)

/* CSC macro for CPU: 66 MHz; AHB: 33 MHz; APB: 16.5 MHz (/2) */
#define CSC_66_33_16 (CSC_HCLKDIV2 | \
                      CSC_MAINDIV1(15) | \
                      CSC_MAINDIV2(8) | \
                      CSC_PREDIV(17) | \
                      CSC_PS1 | \
                      CSC_PCLKDIV2)

/* CSC macro for CPU: 66 MHz; AHB: 66 MHz; APB: 16.5 MHz (/4) */
#define CSC_66_66_16 (CSC_HCLKDIV1 | \
                      CSC_MAINDIV1(15) | \
                      CSC_MAINDIV2(8) | \
                      CSC_PREDIV(17) | \
                      CSC_PS1 | \
                      CSC_PCLKDIV4)

/* CSC macro for CPU: 66 MHz; AHB: 66 MHz; APB: 33 MHz (/2) */
#define CSC_66_66_33 (CSC_HCLKDIV1 | \
                      CSC_MAINDIV1(15) | \
                      CSC_MAINDIV2(8) | \
                      CSC_PREDIV(17) | \
                      CSC_PS1 | \
                      CSC_PCLKDIV2)

/* CSC macro for CPU: 75 MHz; AHB: 75 MHz; APB: 18.75 MHz (/4) */
#define CSC_75_75_19 (CSC_HCLKDIV1 | \
                      CSC_MAINDIV1(11) | \
                      CSC_MAINDIV2(16) | \
                      CSC_PREDIV(21) | \
                      CSC_PS1 | \
                      CSC_PCLKDIV4)

/* CSC macro for CPU: 75 MHz; AHB: 75 MHz; APB: 37.5 MHz (/2) */
#define CSC_75_75_37 (CSC_HCLKDIV1 | \
                      CSC_MAINDIV1(11) | \
                      CSC_MAINDIV2(16) | \
                      CSC_PREDIV(21) | \
                      CSC_PS1 | \
                      CSC_PCLKDIV2)

/* CSC macro for CPU: 100 MHz; AHB: 50 MHz; APB: 12.5 MHz (/4) */
#define CSC_100_50_12 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(5) | \
                       CSC_MAINDIV2(29) | \
                       CSC_PREDIV(14) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV4)

/* CSC macro for CPU: 100 MHz; AHB: 50 MHz; APB: 25 MHz (/2) */
#define CSC_100_50_25 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(5) | \
                       CSC_MAINDIV2(29) | \
                       CSC_PREDIV(14) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 100 MHz; AHB: 100 MHz; APB: 12.5 MHz (/8) */
#define CSC_100_100_12 (CSC_HCLKDIV1 | \
                        CSC_MAINDIV1(5) | \
                        CSC_MAINDIV2(29) | \
                        CSC_PREDIV(14) | \
                        CSC_PS1 | \
                        CSC_PCLKDIV8)

/* CSC macro for CPU: 100 MHz; AHB: 100 MHz; APB: 50 MHz (/2) */
#define CSC_100_100_50 (CSC_HCLKDIV1 | \
                        CSC_MAINDIV1(5) | \
                        CSC_MAINDIV2(29) | \
                        CSC_PREDIV(14) | \
                        CSC_PS1 | \
                        CSC_PCLKDIV2)

/* CSC macro for CPU: 132 MHz; AHB: 33 MHz; APB: 8.25 MHz (/4) */
#define CSC_132_33_8 (CSC_HCLKDIV4 | \
                      CSC_MAINDIV1(11) | \
                      CSC_MAINDIV2(23) | \
                      CSC_PREDIV(16) | \
                      CSC_PS1 | \
                      CSC_PCLKDIV4)

/* CSC macro for CPU: 132 MHz; AHB: 33 MHz; APB: 16.5 MHz (/4) */
#define CSC_132_33_16 (CSC_HCLKDIV4 | \
                       CSC_MAINDIV1(11) | \
                       CSC_MAINDIV2(23) | \
                       CSC_PREDIV(16) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 132 MHz; AHB: 66 MHz; APB: 16.5 MHz (/4) */
#define CSC_132_66_16 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(11) | \
                       CSC_MAINDIV2(23) | \
                       CSC_PREDIV(16) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV4)

/* CSC macro for CPU: 132 MHz; AHB: 66 MHz; APB: 33 MHz (/2) */
#define CSC_132_66_33 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(11) | \
                       CSC_MAINDIV2(23) | \
                       CSC_PREDIV(16) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 150 MHz; AHB: 75 MHz; APB: 18.75 MHz (/4) */
#define CSC_150_75_19 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(17) | \
                       CSC_PREDIV(12) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV4)

/* CSC macro for CPU: 150 MHz; AHB: 75 MHz; APB: 37.5 MHz (/2) */
#define CSC_150_75_37 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(17) | \
                       CSC_PREDIV(12) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 166 MHz; AHB: 41.7 MHz; APB: 20.8 MHz (/2) */
#define CSC_166_42_21 (CSC_HCLKDIV4 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(28) | \
                       CSC_PREDIV(18) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 166 MHz; AHB: 83.4 MHz; APB: 21 MHz (/4) */
#define CSC_166_83_21 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(28) | \
                       CSC_PREDIV(18) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV4)

/* CSC macro for CPU: 166 MHz; AHB: 83.4 MHz; APB: 42 MHz (/2) */
#define CSC_166_83_42 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(28) | \
                       CSC_PREDIV(18) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 175 MHz; AHB: 44 MHz; APB: 22 MHz (/2) */
#define CSC_175_44_22 (CSC_HCLKDIV4 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(28) | \
                       CSC_PREDIV(17) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 175 MHz; AHB: 87 MHz; APB: 22 MHz (/4) */
#define CSC_175_87_22 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(28) | \
                       CSC_PREDIV(17) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV4)

/* CSC macro for CPU: 175 MHz; AHB: 87 MHz; APB: 43 MHz (/2) */
#define CSC_175_87_43 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(28) | \
                       CSC_PREDIV(17) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 184 MHz; AHB: 46 MHz; APB: 23 MHz (/2) */
#define CSC_184_46_23 (CSC_HCLKDIV4 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(28) | \
                       CSC_PREDIV(16) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 184 MHz; AHB: 92 MHz; APB: 23 MHz (/4) */
#define CSC_184_92_23 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(28) | \
                       CSC_PREDIV(16) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV4)

/* CSC macro for CPU: 184 MHz; AHB: 92 MHz; APB: 46 MHz (/2) */
#define CSC_184_92_46 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(28) | \
                       CSC_PREDIV(16) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 190 MHz; AHB: 48 MHz; APB: 24 MHz (/2) */
#define CSC_190_48_24 (CSC_HCLKDIV4 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(29) | \
                       CSC_PREDIV(16) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 190 MHz; AHB: 96 MHz; APB: 24 MHz (/4) */
#define CSC_190_96_24 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(29) | \
                       CSC_PREDIV(16) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV4)

/* CSC macro for CPU: 190 MHz; AHB: 96 MHz; APB: 48 MHz (/2) */
#define CSC_190_96_48 (CSC_HCLKDIV2 | \
                       CSC_MAINDIV1(13) | \
                       CSC_MAINDIV2(29) | \
                       CSC_PREDIV(16) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 200 MHz; AHB: 50 MHz; APB: 25 MHz (/2) */
#define CSC_200_50_25 (CSC_HCLKDIV4 | \
                       CSC_MAINDIV1(12) | \
                       CSC_MAINDIV2(29) | \
                       CSC_PREDIV(14) | \
                       CSC_PS1 | \
                       CSC_PCLKDIV2)

/* CSC macro for CPU: 200 MHz; AHB: 100 MHz; APB: 12 MHz (/8) */
#define CSC_200_100_12 (CSC_HCLKDIV2 | \
                        CSC_MAINDIV1(12) | \
                        CSC_MAINDIV2(29) | \
                        CSC_PREDIV(14) | \
                        CSC_PS1 | \
                        CSC_PCLKDIV8)

/* CSC macro for CPU: 200 MHz; AHB: 100 MHz; APB: 25 MHz (/4) */
#define CSC_200_100_25 (CSC_HCLKDIV2 | \
                        CSC_MAINDIV1(12) | \
                        CSC_MAINDIV2(29) | \
                        CSC_PREDIV(14) | \
                        CSC_PS1 | \
                        CSC_PCLKDIV4)

/* CSC macro for CPU: 200 MHz; AHB: 50 MHz; APB: 25 MHz (/2) */
#define CSC_200_100_50 (CSC_HCLKDIV2 | \
                        CSC_MAINDIV1(12) | \
                        CSC_MAINDIV2(29) | \
                        CSC_PREDIV(14) | \
                        CSC_PS1 | \
                        CSC_PCLKDIV2)

/* CSC macro for CPU: 220 MHz; AHB: 110 MHz; APB: 55 MHz (/2) */
#define CSC_220_110_55 (CSC_HCLKDIV2 | \
                        CSC_MAINDIV1(14) | \
                        CSC_MAINDIV2(26) | \
                        CSC_PREDIV(13) | \
                        CSC_PS1 | \
                        CSC_PCLKDIV2)
                        
/* CSC macro for CPU: 266 MHz; AHB: 133 MHz; APB: 66 MHz  */
#define CSC_266_133_66 (CSC_HCLKDIV2 | \
                        CSC_MAINDIV1(13) | \
                        CSC_MAINDIV2(28) | \
                        CSC_PREDIV(23) | \
                        CSC_PS0 | \
                        CSC_PCLKDIV2)                        

                        
/* Macro pointing to CSC registers */
#define CLKSC   ((CSC_REGS_T *)(CLKSC_BASE))

/* Macro pointing to CSC registers (alternate) */
#define CSC     CLKSC

#endif /* LH7A404_CLKSC_H */

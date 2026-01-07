/***********************************************************************
 * $Id:: lh79524_clcdc.h 27 2007-08-31 19:35:06Z kevinw                $
 *
 * Project: LH79524 headers
 *
 * Description:
 *      This file contains the structure definitions and manifest
 *      constants for LH79524 component:
 *          CLCDC & LCDICP (ALI)
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

#ifndef LH79524_CLCDC_H
#define LH79524_CLCDC_H

/***********************************************************************
 * Color LCD Controller Register Structure
 **********************************************************************/

/* LCD Interface Conversion Peripheral Register Structure */
typedef struct LCDICP_REGS_S
{
  volatile UNS_32 lcdicp_setup;       /* HR-TFT Setup register */
  volatile UNS_32 lcdicp_control;     /* HR-TFT Control register */
  volatile UNS_32 lcdicp_timing1;     /* HR-TFT Timing 1 register */
  volatile UNS_32 lcdicp_timing2;     /* HR-TFT Timing 2 register */
} LCDICP_REGS_T, *PLCDICP_REGS_T;

/* Color LCD controller Module Register Structure */ 
typedef struct CLCDC_REGS_S
{
  volatile UNS_32 lcdtiming0;         /* LCD timing 0 register */
  volatile UNS_32 lcdtiming1;         /* LCD timing 1 register */
  volatile UNS_32 lcdtiming2;         /* LCD timing 2 register */
  volatile UNS_32 reserved;          
  volatile UNS_32 lcdupbase;          /* LCD upper frame buffer
                                         address register */
  volatile UNS_32 lcdlpbase;          /* LCD LCD lower frame buffer
                                         address register */
  volatile UNS_32 lcdintrenable;      /* LCD int enable register */
  volatile UNS_32 lcdctrl;            /* LCD control register */
  volatile UNS_32 lcdstatus;          /* LCD status register */
  volatile UNS_32 lcdinterrupt;       /* LCD interrupt register */
  volatile UNS_32 lcdupcurr;          /* LCD upper frame buffer
                                         current address register */
  volatile UNS_32 lcdlpcurr;          /* LCD lower frame buffer
                                         current address register */
  volatile UNS_32 reservedclcdc[116]; /* LCD reserved */
  volatile UNS_32 lcdpalette[128];    /* LCD palette registers */
} CLCDC_REGS_T, *PCLCDC_REGS_T;


/* Number of color LCD controllers on the chip */
#define N_LCDS  (1)

/***********************************************************************
 * Color LCD controller timing 0 register definitions
 **********************************************************************/

/* LCD controller timing 0 pixel per line load macro */
#define CLCDC_LCDTIMING0_PPL(n) _SBF(2, (((n) / 16) - 1) & 0x0000003F)
/* LCD controller timing 0 HSYNC pulse width load macro */
#define CLCDC_LCDTIMING0_HSW(n) _SBF(8, ((n) - 1) & 0x000000FF)
/* LCD controller timing 0 horizontal front porch load macro */
#define CLCDC_LCDTIMING0_HFP(n) _SBF(16, ((n) - 1) & 0x000000FF)
/* LCD controller timing 0 horizontal back porch load macro */
#define CLCDC_LCDTIMING0_HBP(n) _SBF(24, ((n) - 1) & 0x000000FF)

/***********************************************************************
 * Color LCD controller timing 1 register definitions
 **********************************************************************/

/* LCD controller timing 1 lines per panel load macro */
#define CLCDC_LCDTIMING1_LPP(n) _SBF(0, ((n) - 1) & 0x000003FF)
/* LCD controller timing 1 VSYNC pulse width load macro */
#define CLCDC_LCDTIMING1_VSW(n) _SBF(10, ((n) - 1) & 0x0000003F)
/* LCD controller timing 1 vertical front porch load macro */
#define CLCDC_LCDTIMING1_VFP(n) _SBF(16, ((n) - 1) & 0x000000FF)
/* LCD controller timing 1 vertical back porch load macro */
#define CLCDC_LCDTIMING1_VBP(n) _SBF(24, ((n) - 1) & 0x000000FF)

/***********************************************************************
 * Color LCD controller timing 2 register definitions
 **********************************************************************/

/* LCD controller timing 2 panel clock divisor load macro */
#define CLCDC_LCDTIMING2_PCD_LO(n)  _SBF(0, ((n) - 2) & 0x0000001F)
/* LCD controller timing 2 AC bias frequency load macro */
#define CLCDC_LCDTIMING2_ACB(n) _SBF(6, ((n) - 1) & 0x0000001F)
/* LCD controller timing 2 VSYNC invert bit */
#define CLCDC_LCDTIMING2_IVS    _BIT(11)
/* LCD controller timing 2 HSYNC invert bit */
#define CLCDC_LCDTIMING2_IHS    _BIT(12)
/* LCD controller timing 2 clock invert bit */
#define CLCDC_LCDTIMING2_IPC    _BIT(13)
/* LCD controller timing 2 output enable invert bit */
#define CLCDC_LCDTIMING2_IOE    _BIT(14)
/* LCD controller timing 2 clocks per line load macro */
#define CLCDC_LCDTIMING2_CPL(n) _SBF(16, (n) & 0x000003FF)
/* LCD controller timing 2 bypass pixel divider bit */
#define CLCDC_LCDTIMING2_BCD    _BIT(26)
/* LCD controller timing 2 panel clock divisor load macro */
#define CLCDC_LCDTIMING2_PCD_HI(n)  _SBF(25, ((n) - 2) & 0x000003E0)

/***********************************************************************
 * Color LCD controller interrupt enable/status register definitions
 **********************************************************************/

/* FIFO Underflow Interrupt */
#define CLCDC_LCDSTATUS_FIFOUF   _BIT(1)
/* Next Base Update Interrupt */
#define CLCDC_LCDSTATUS_BU      _BIT(2)
/* Vertical Compare Interrupt Enable */
#define CLCDC_LCDSTATUS_VCOMP   _BIT(3)
/* Bus Master Error Interrupt Enable */
#define CLCDC_LCDSTATUS_MBERROR _BIT(4)

/***********************************************************************
 * Color LCD controller control register definitions
 **********************************************************************/

/* LCD control enable bit */
#define CLCDC_LCDCTRL_ENABLE      _BIT(0)
/* LCD control 1 bit per pixel bit field */ 
#define CLCDC_LCDCTRL_BPP1        _SBF(1, 0x0)
/* LCD control 2 bits per pixel bit field */ 
#define CLCDC_LCDCTRL_BPP2        _SBF(1, 0x1)
/* LCD control 4 bits per pixel bit field */ 
#define CLCDC_LCDCTRL_BPP4        _SBF(1, 0x2)
/* LCD control 8 bits per pixel bit field */ 
#define CLCDC_LCDCTRL_BPP8        _SBF(1, 0x3)
/* LCD control 16 bits per pixel bit field */ 
#define CLCDC_LCDCTRL_BPP16       _SBF(1, 0x4)
/* LCD control mono select bit */
#define CLCDC_LCDCTRL_BW_MONO     _BIT(4)
/* LCD controler TFT select bit */
#define CLCDC_LCDCTRL_TFT         _BIT(5)
/* LCD control monochrome LCD has 4-bit/8-bit select bit */ 
#define CLCDC_LCDCTRL_MONO8       _BIT(6)
/* LCD control dual panel select bit */
#define CLCDC_LCDCTRL_DUAL        _BIT(7)
/* LCD control normal RGB bit */
#define CLCDC_LCDCTRL_RGB         _BIT(8)
/* LCD control swap RGB (555 BGR mode) bit */
#define CLCDC_LCDCTRL_BGR       0x00000000
/* LCD control Big-Endian Byte Ordering bit */ 
#define CLCDC_LCDCTRL_BEBO        _BIT(9)
/* LCD control Big-Endian Pixel Ordering bit */ 
#define CLCDC_LCDCTRL_BEPO        _BIT(10)
/* LCD control power enable bit */ 
#define CLCDC_LCDCTRL_PWR         _BIT(11)
/* LCD control VCOMP interrupt is start of VSYNC */
#define CLCDC_LCDCTRL_VCOMP_VS    _SBF(12, 0x0)
/* LCD control VCOMP interrupt is start of back porch */
#define CLCDC_LCDCTRL_VCOMP_BP    _SBF(12, 0x1)
/* LCD control VCOMP interrupt is start of video */
#define CLCDC_LCDCTRL_VCOMP_AV    _SBF(12, 0x2)
/* LCD control VCOMP interrupt is start of front porch */
#define CLCDC_LCDCTRL_VCOMP_FP    _SBF(12, 0x3)
/* LCD control watermark level is 4 or more words free bit */
#define CLCDC_LCDCTRL_WATERMARK   _BIT(16)

/***********************************************************************
 * LCDICP setup register definitions
 **********************************************************************/

/* LCDICP setup enable bypass mode value */
#define  LCDICP_SETUP_MODE_BYPASS   0x00000000
/* LCDICP setup enable HRTFT mode value */
#define  LCDICP_SETUP_MODE_HRTFT    _BIT(0)
/* LCDICP setup reserved bits, always programmed as '1' */
#define LCDICP_SETUP_RESERVED       _SBF(1, 0x6)
/* LCDICP setup pixels per line load macro */
#define  LCDICP_SETUP_PPL(n)        _SBF(4, ((n) - 1) & 0x000001FF)
/* LCDICP setup power on LCD signals enable bit */
#define  LCDICP_SETUP_EN            _BIT(13)

/***********************************************************************
 * LCDICP control register definitions
 **********************************************************************/

/* LCDICP control SPS enable bit */
#define LCDICP_CONTROL_SPSEN        _BIT(0)
/* LCDICP control CLS enable bit */
#define LCDICP_CONTROL_CLSEN        _BIT(1)
/* LCDICP control Display Control Signal Output enable bit */
#define LCDICP_CONTROL_DISP         _BIT(3)
/* LCDICP control LCDVEEEN Output enable bit */
#define LCDICP_CONTROL_EN0          _BIT(4)
/* LCDICP control Mod Signal Value bit */
#define LCDICP_CONTROL_MODVAL       _BIT(8)
/* LCDICP control MOD Signal Override enable bit */
#define LCDICP_CONTROL_MODOVRD      _BIT(9)

/***********************************************************************
 * LCDICP timing 1 register definitions
 **********************************************************************/

/* LCDICP timing 1 LP delay load macro */
#define LCDICP_TIMING1_LPDEL(n)     _SBF(0, ((n) - 1) & 0x0000000F)
/* LCDICP timing 1 polarity reversal delay load macro */
#define LCDICP_TIMING1_REVDEL(n)    _SBF(4, ((n) - 1) & 0x0000000F)
/* LCDICP timing 1 LP to PS delay load macro */
#define LCDICP_TIMING1_PS_CLSDEL(n) _SBF(8, ((n) - 1) & 0x0000000F)
/* LCDICP timing 1 LCDMOD LOW delay load macro */
#define LCDICP_TIMING1_PS_MODDEL(n) _SBF(12, ((n) - 1) & 0x00000003)

/***********************************************************************
 * LCDICP timing 2 register definitions
 **********************************************************************/

/* LCDICP timing 2 SPL to CLS delay load macro */
#define LCDICP_TIMING2_PS_CLSDEL2(n) _SBF(0, ((n) - 1) & 0x000001FF)
/* LCDICP timing 2 SPL delay load macro */
#define LCDICP_TIMING2_SPLVALUE(n)   _SBF(9, ((n) - 1) & 0x0000007F)
        
/* Macro pointing to LCD Interface Conversion Peripheral Register */
#define LCDICP ((LCDICP_REGS_T *)(ALI_BASE))
/* Macro pointing to Color LCD controller Module Register */
#define CLCDC ((CLCDC_REGS_T *)(LCD_BASE))

#endif /* LH79524_CLCDC_H */

/***********************************************************************
 * $Id:: lh79524_emc.h 27 2007-08-31 19:35:06Z kevinw                  $
 *
 * Project: LH79524 headers
 *
 * Description: 
 *      This file contains the structure definitions and manifest
 *      constants for LH79524 component:
 *
 *          External Memory Controller
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
#ifndef LH79524_EMC_H
#define LH79524_EMC_H

#include "lpc_types.h"
#include "lh79524_chip.h"

/***********************************************************************
 * External Memory Controller Module Register Structure
 **********************************************************************/

typedef struct
{
  /* Control Register */
  volatile UNS_32 ctrl;     
  /* Status Register */
  volatile UNS_32 status;
  /* Configuration Register */
  volatile UNS_32 config;
  UNS_32   reserved0[5];
  /* Dynamic Memory Control Register */
  volatile UNS_32 sdramc_ctrl;
  /* Dynamic Memory Refresh Timer */
  volatile UNS_32 sdramc_refresh;
  /* Dynamic Memory read configuration Register */
  volatile UNS_32 sdramc_read_config;
  UNS_32   reserved1;
  /* Dynamic Memory Precharge Command Period */
  volatile UNS_32 sdramc_rp;
  /* Dynamic Memory Active to Precharge Command Period */
  volatile UNS_32 sdramc_ras;
  /* Dynamic Memory Self-Refresh Exit Time */
  volatile UNS_32 sdramc_srex;
  /* Dynamic Memory Last Data Out to Active Time */
  volatile UNS_32 sdramc_apr;
  /* Dynamic Memory Data-In to Active Command Time */
  volatile UNS_32 sdramc_dal;
  /* Dynamic Memory Write Recovery Time */
  volatile UNS_32 sdramc_wr;
  /* Dynamic Memory Active to Active Command Period */
  volatile UNS_32 sdramc_rc;
  /* Dynamic Memory Auto-Refresh Period, and Auto-Refresh
     to Active Command Period */
  volatile UNS_32 sdramc_rfc;
  /* Dynamic Memory Exit Self-Refresh to Active Command Time */
  volatile UNS_32 sdramc_xsr;
  /* Dynamic Memory Active Bank A to Active Bank B Time */
  volatile UNS_32 sdramc_rrd;
  /* Dynamic Memory Load Mode Register to Active Command Time */
  volatile UNS_32 sdramc_mrd;
  UNS_32   reserved2[9];
  /* Static Memory Extended Wait */
  volatile UNS_32 static_ext_wait;
  UNS_32   reserved3[31];
  /* Dynamic Configuration Register for nDCS0 */
  volatile UNS_32 sdramc_cfg0;
  /* Dynamic Memory RAS and CAS Delay for nDCS0 */
  volatile UNS_32 sdramc_rascas0;
  UNS_32   reserved4[6];
  /* Dynamic Configuration Register for nDCS1 */
  volatile UNS_32 sdramc_cfg1;
  /* Dynamic Memory RAS and CAS Delay for nDCS1 */
  volatile UNS_32 sdramc_rascas1;
  UNS_32   reserved5[54];
  /* Static Memory Configuration for nCS0 */
  volatile UNS_32 static_cfg0;
  /* Static Memory Write Enable Delay for nCS0 */
  volatile UNS_32 static_waitwen0;
  /* Static Memory Output Enable Delay for nCS0 */
  volatile UNS_32 static_waitoen0;
  /* Static Memory Read Delay for nCS0 */
  volatile UNS_32 static_waitrd0;
  /* Static Memory Page Mode Read Delay for nCS0 */
  volatile UNS_32 static_waitpage0;
  /* Static Memory Write Delay for nCS0 */
  volatile UNS_32 static_waitwr0;
  /* Static Memory Turn Around Delay for nCS0 */
  volatile UNS_32 static_waitturn0;
  UNS_32 reserved6;
  /* Static Memory Configuration for nCS1 */
  volatile UNS_32 static_cfg1;
  /* Static Memory Write Enable Delay for nCS1 */
  volatile UNS_32 static_waitwen1;
  /* Static Memory Output Enable Delay for nCS1 */
  volatile UNS_32 static_waitoen1;
  /* Static Memory Read Delay for nCS1 */
  volatile UNS_32 static_waitrd1;
  /* Static Memory Page Mode Read Delay for nCS1 */
  volatile UNS_32 static_waitpage1;
  /* Static Memory Write Delay for nCS1 */
  volatile UNS_32 static_waitwr1;
  /* Static Memory Turn Around Delay for nCS1 */
  volatile UNS_32 static_waitturn1;
  UNS_32 reserved7;
  /* Static Memory Configuration for nCS2 */
  volatile UNS_32 static_cfg2;
  /* Static Memory Write Enable Delay for nCS2 */
  volatile UNS_32 static_waitwen2;
  /* Static Memory Output Enable Delay for nCS2 */
  volatile UNS_32 static_waitoen2;
  /* Static Memory Read Delay for nCS2 */
  volatile UNS_32 static_waitrd2;
  /* Static Memory Page Mode Read Delay for nCS2 */
  volatile UNS_32 static_waitpage2;
  /* Static Memory Write Delay for nCS2 */
  volatile UNS_32 static_waitwr2;
  /* Static Memory Turn Around Delay for nCS2 */
  volatile UNS_32 static_waitturn2;
  UNS_32 reserved8;
  /* Static Memory Configuration for nCS3 */
  volatile UNS_32 static_cfg3;
  /* Static Memory Write Enable Delay for nCS3 */
  volatile UNS_32 static_waitwen3;
  /* Static Memory Output Enable Delay for nCS3 */
  volatile UNS_32 static_waitoen3;
  /* Static Memory Read Delay for nCS3 */
  volatile UNS_32 static_waitrd3;
  /* Static Memory Page Mode Read Delay for nCS3 */
  volatile UNS_32 static_waitpage3;
  /* Static Memory Write Delay for nCS3 */
  volatile UNS_32 static_waitwr3;
  /* Static Memory Turn Around Delay for nCS3 */
  volatile UNS_32 static_waitturn3;
  UNS_32 reserved9;
} EMC_REGS_T;

/***********************************************************************
 * External Memory Controller Bit Field constants
 **********************************************************************/
 
#define EMC_CTL_ENABLE                _BIT(0)
#define EMC_CTL_LOW_PWR               _BIT(2)

#define EMC_STATUS_SA                 _BIT(2)
#define EMC_STATUS_WR_BUF             _BIT(1)
#define EMC_STATUS_BUSY               _BIT(0)

#define EMC_CFG_SDCCLK_1_2            _BIT(8)
#define EMC_CFG_SDCCLK_1_1            (0)

#define EMC_SDRAMC_CTL_CE             _BIT(0)
#define EMC_SDRAMC_CTL_CS             _BIT(1)
#define EMC_SDRAMC_CTL_SR             _BIT(2)
#define EMC_SDRAMC_CTL_MCC            _BIT(5)
#define EMC_SDRAMC_CTL_NORMAL_CMD     _SBF(7,0)
#define EMC_SDRAMC_CTL_MODE_CMD       _SBF(7,1)
#define EMC_SDRAMC_CTL_PALL_CMD       _SBF(7,2)
#define EMC_SDRAMC_CTL_NOP_CMD        _SBF(7,3)
#define EMC_SDRAMC_CTL_DP             _BIT(8)

#define EMC_SDRAMC_CFG_SDRAM_MD       _SBF(3,0)
#define EMC_SDRAMC_CFG_LOW_PWR_MD     _SBF(3,1)
#define EMC_SDRAMC_CFG_SYNC_FLASH     _SBF(3,2)
#define EMC_SDRAMC_CFG_BUF_EN         _BIT(19)
#define EMC_SDRAMC_CFG_WP             _BIT(20)

/*16-bit external bus high-performance address mapping */
/*16Mb (2Mx8), 2 banks, row length = 11, column length = 9*/
#define SDRAMC_16HP_2Mx8_2B_R11_C9    (_SBF(7,0x00))
/*16Mb (1Mx16), 2 banks, row length = 11, column length = 8*/
#define SDRAMC_16HP_1Mx16_2B_R11_C8   (_SBF(7,0x01))
/*64Mb (8Mx8), 4 banks, row length = 12, column length = 9*/
#define SDRAMC_16HP_8Mx8_4B_R12_C9    (_SBF(7,0x04))
/*64Mb (4Mx16), 4 banks, row length = 12, column length = 8*/
#define SDRAMC_16HP_4Mx16_4B_R12_C8   (_SBF(7,0x05))
/*128Mb (16Mx8), 4 banks, row length = 12, column length = 10*/
#define SDRAMC_16HP_16Mx8_4B_R12_C10  (_SBF(7,0x08))
/*128Mb (8Mx16), 4 banks, row length = 12, column length = 9*/
#define SDRAMC_16HP_8Mx16_4B_R12_C9   (_SBF(7,0x09))
/*256Mb (32Mx8), 4 banks, row length = 13, column length = 10*/
#define SDRAMC_16HP_32Mx8_4B_R13_C10  (_SBF(7,0x0C))
/*256Mb (16Mx16), 4 banks, row length = 13, column length = 9*/
#define SDRAMC_16HP_16Mx16_4B_R13_C9  (_SBF(7,0x0D))
/*512Mb (64Mx8), 4 banks, row length = 13, column length = 11*/
#define SDRAMC_16HP_64Mx8_4B_R13_C11  (_SBF(7,0x10))
/*512Mb (32Mx16), 4 banks, row length = 13, column length = 10*/
#define SDRAMC_16HP_32Mx16_4B_R13_C10 (_SBF(7,0x11))

/*16-bit external bus low power SDRAM address mapping */
/*16Mb (2Mx8), 2 banks, row length = 11, column length = 9*/
#define SDRAMC_16LP_2Mx8_2B_R11_C9    (_SBF(7,0x20))
/*16Mb (1Mx16), 2 banks, row length = 11, column length = 8*/
#define SDRAMC_16LP_1Mx16_2B_R11_C8   (_SBF(7,0x21))
/*64Mb (8Mx8), 4 banks, row length = 12, column length = 9*/
#define SDRAMC_16LP_8Mx8_4B_R12_C9    (_SBF(7,0x24))
/*64Mb (4Mx16), 4 banks, row length = 12, column length = 8*/
#define SDRAMC_16LP_4Mx16_4B_R12_C8   (_SBF(7,0x25))
/*128Mb (16Mx8), 4 banks, row length = 12, column length = 10*/
#define SDRAMC_16LP_16Mx8_4B_R12_C10  (_SBF(7,0x28))
/*128Mb (8Mx16), 4 banks, row length = 12, column length = 9*/
#define SDRAMC_16LP_8Mx16_4B_R12_C9   (_SBF(7,0x29))
/*256Mb (32Mx8), 4 banks, row length = 13, column length = 10*/
#define SDRAMC_16LP_32Mx8_4B_R13_C10  (_SBF(7,0x2C))
/*256Mb (16Mx16), 4 banks, row length = 13, column length = 9*/
#define SDRAMC_16LP_16Mx16_4B_R13_C9  (_SBF(7,0x2D))
/*512Mb (64Mx8), 4 banks, row length = 13, column length = 11*/
#define SDRAMC_16LP_64Mx8_4B_R13_C11  (_SBF(7,0x30))
/*512Mb (32Mx16), 4 banks, row length = 13, column length = 10*/
#define SDRAMC_16LP_32Mx16_4B_R13_C10 (_SBF(7,0x31))

/*32-bit external bus high-performance address mapping */
/*16Mb (2Mx8), 2 banks, row length = 11, column length = 9*/
#define SDRAMC_32HP_2Mx8_2B_R11_C9    (_SBF(7,0x00) | _BIT(14))
/*16Mb (1Mx16), 2 banks, row length = 11, column length = 8*/
#define SDRAMC_32HP_1Mx16_2B_R11_C8   (_SBF(7,0x01) | _BIT(14))
/*64Mb (8Mx8), 4 banks, row length = 12, column length = 9*/
#define SDRAMC_32HP_8Mx8_4B_R12_C9    (_SBF(7,0x04) | _BIT(14))
/*64Mb (4Mx16), 4 banks, row length = 12, column length = 8*/
#define SDRAMC_32HP_4Mx16_4B_R12_C8   (_SBF(7,0x05) | _BIT(14))
/*128Mb (16Mx8), 4 banks, row length = 12, column length = 10*/
#define SDRAMC_32HP_16Mx8_4B_R12_C10  (_SBF(7,0x08) | _BIT(14))
/*128Mb (8Mx16), 4 banks, row length = 12, column length = 9*/
#define SDRAMC_32HP_8Mx16_4B_R12_C9   (_SBF(7,0x09) | _BIT(14))
/*256Mb (32Mx8), 4 banks, row length = 13, column length = 10*/
#define SDRAMC_32HP_32Mx8_4B_R13_C10  (_SBF(7,0x0C) | _BIT(14))
/*256Mb (16Mx16), 4 banks, row length = 13, column length = 9*/
#define SDRAMC_32HP_16Mx16_4B_R13_C9  (_SBF(7,0x0D) | _BIT(14))
/*512Mb (64Mx8), 4 banks, row length = 13, column length = 11*/
#define SDRAMC_32HP_64Mx8_4B_R13_C11  (_SBF(7,0x10) | _BIT(14))
/*512Mb (32Mx16), 4 banks, row length = 13, column length = 10*/
#define SDRAMC_32HP_32Mx16_4B_R13_C10 (_SBF(7,0x11) | _BIT(14))

/*32-bit external bus low power SDRAM address mapping */
/*16Mb (2Mx8), 2 banks, row length = 11, column length = 9*/
#define SDRAMC_32LP_2Mx8_2B_R11_C9    (_SBF(7,0x20) | _BIT(14))
/*16Mb (1Mx16), 2 banks, row length = 11, column length = 8*/
#define SDRAMC_32LP_1Mx16_2B_R11_C8   (_SBF(7,0x21) | _BIT(14))
/*64Mb (8Mx8), 4 banks, row length = 12, column length = 9*/
#define SDRAMC_32LP_8Mx8_4B_R12_C9    (_SBF(7,0x24) | _BIT(14))
/*64Mb (4Mx16), 4 banks, row length = 12, column length = 8*/
#define SDRAMC_32LP_4Mx16_4B_R12_C8   (_SBF(7,0x25) | _BIT(14))
/*128Mb (16Mx8), 4 banks, row length = 12, column length = 10*/
#define SDRAMC_32LP_16Mx8_4B_R12_C10  (_SBF(7,0x28) | _BIT(14))
/*128Mb (8Mx16), 4 banks, row length = 12, column length = 9*/
#define SDRAMC_32LP_8Mx16_4B_R12_C9   (_SBF(7,0x29) | _BIT(14))
/*256Mb (32Mx8), 4 banks, row length = 13, column length = 10*/
#define SDRAMC_32LP_32Mx8_4B_R13_C10  (_SBF(7,0x2C) | _BIT(14))
/*256Mb (16Mx16), 4 banks, row length = 13, column length = 9*/
#define SDRAMC_32LP_16Mx16_4B_R13_C9  (_SBF(7,0x2D) | _BIT(14))
/*512Mb (64Mx8), 4 banks, row length = 13, column length = 11*/
#define SDRAMC_32LP_64Mx8_4B_R13_C11  (_SBF(7,0x30) | _BIT(14))
/*512Mb (32Mx16), 4 banks, row length = 13, column length = 10*/
#define SDRAMC_32LP_32Mx16_4B_R13_C10 (_SBF(7,0x31) | _BIT(14))

#define EMC_SDRAMC_RDCFG_CLKOUTDELAY_STG       _SBF(0,0)
#define EMC_SDRAMC_RDCFG_CMDDELAY_STG          _SBF(0,1) 
#define EMC_SDRAMC_RDCFG_CMDDELAY_P1_STG       _SBF(0,2)
#define EMC_SDRAMC_RDCFG_CMDDELAY__P2_STG      _SBF(0,3)

#define EMC_SDRAMC_RASCAS_CAS0        _SBF(8,0)
#define EMC_SDRAMC_RASCAS_CAS1        _SBF(8,1)
#define EMC_SDRAMC_RASCAS_CAS2        _SBF(8,2)
#define EMC_SDRAMC_RASCAS_CAS3        _SBF(8,3)
#define EMC_SDRAMC_RASCAS_RAS0        _SBF(0,0)
#define EMC_SDRAMC_RASCAS_RAS1        _SBF(0,1)
#define EMC_SDRAMC_RASCAS_RAS2        _SBF(0,2)
#define EMC_SDRAMC_RASCAS_RAS3        _SBF(0,3)

#define EMC_CLOCK(hclk)               \
    (hclk/(((EMC->config & _BIT(8))>>8)+1))

#define EMC_SDRAMC_REFRESH(trf,hclk)  \
    (((UNS_64)(trf * hclk)/16000000000) & _BITMASK(11))

#define EMC_SDRAMC_TRP(trp,hclk)      \
    (((UNS_64)(trp * EMC_CLOCK(hclk))/1000000000) & _BITMASK(4))
#define EMC_SDRAMC_TRAS(tras,hclk)    \
    (((UNS_64)(tras * EMC_CLOCK(hclk))/1000000000) & _BITMASK(4))
#define EMC_SDRAMC_TSREX(tsrex,hclk)  \
    (((UNS_64)(tsrex * EMC_CLOCK(hclk))/1000000000) & _BITMASK(4))
#define EMC_SDRAMC_TARP(tarp,hclk)    \
    (((UNS_64)(tarp * EMC_CLOCK(hclk))/1000000000) & _BITMASK(4))
#define EMC_SDRAMC_TDAL(tdal,hclk)    \
    (((UNS_64)(tdal * EMC_CLOCK(hclk))/1000000000) & _BITMASK(4))
#define EMC_SDRAMC_TWR(twr,hclk)      \
    (((UNS_64)(twr * EMC_CLOCK(hclk))/1000000000) & _BITMASK(4))
#define EMC_SDRAMC_TRC(trc,hclk)      \
    (((UNS_64)(trc * EMC_CLOCK(hclk))/1000000000) & _BITMASK(5))
#define EMC_SDRAMC_TRFC(trfc,hclk)    \
    (((UNS_64)(trfc * EMC_CLOCK(hclk))/1000000000) & _BITMASK(5))
#define EMC_SDRAMC_TXSR(txsr,hclk)    \
    (((UNS_64)(txsr * EMC_CLOCK(hclk))/1000000000) & _BITMASK(5))
#define EMC_SDRAMC_TRRD(trrd,hclk)    \
    (((UNS_64)(trrd * EMC_CLOCK(hclk))/1000000000) & _BITMASK(5))
#define EMC_SDRAMC_TMRD(tmrd,hclk)    \
    (((UNS_64)(tmrd * EMC_CLOCK(hclk))/1000000000) & _BITMASK(5))


/*Static Memory Controler defines*/

#define EMC_STATIC_CFG_MW8      _SBF(0,0)  /* Memory width 8 bits */
#define EMC_STATIC_CFG_MW16     _SBF(0,1)  /* Memory width 16 bits */
#define EMC_STATIC_CFG_MW32     _SBF(0,2)  /* Memory width 16 bits */

#define EMC_STATIC_CFG_PM       _SBF(3,1)
#define EMC_STATIC_CFG_PC       _SBF(6,1)
#define EMC_STATIC_CFG_BLS      _SBF(7,1)
#define EMC_STATIC_CFG_EW       _SBF(8,1)
#define EMC_STATIC_CFG_B        _SBF(19,1)
#define EMC_STATIC_CFG_P        _SBF(20,1)

#define EMC_STATIC_EXWAIT(twait,hclk)   \
    (((UNS_64)(twait * hclk)/16000000000) & _BITMASK(10))

#define EMC_STATIC_WAIT_WEN(twen,hclk)  \
    (((UNS_64)(twen * hclk)/1000000000) & _BITMASK(4))

#define EMC_STATIC_WAIT_OEN(toen,hclk)  \
    (((UNS_64)(toen * hclk)/1000000000) & _BITMASK(4))

#define EMC_STATIC_WAIT_RD(trd,hclk)    \
    (((UNS_64)(trd * hclk)/1000000000) & _BITMASK(5))

#define EMC_STATIC_WAIT_PAGE(tpg,hclk)  \
    (((UNS_64)(tpg * hclk)/1000000000) & _BITMASK(5))

#define EMC_STATIC_WAIT_WR(twr,hclk)    \
    (((UNS_64)(twr * hclk)/1000000000) & _BITMASK(5))

#define EMC_STATIC_WAIT_TURN(trn,hclk)  \
    (((UNS_64)(trn * hclk)/1000000000) & _BITMASK(4))


/* Macro pointing to vectored interrupt controller 1 registers */
#define EMC ((EMC_REGS_T *)(EMC_REGS_BASE))

#endif /* LH79524_EMC_H */

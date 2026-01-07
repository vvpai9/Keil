/*
 * File:	mac7100.h
 * Purpose:	Register and bit definitions for the MAC7100
 * Date:	14 Apr 2005 19:49:59
 *
 * Notes:	
 *	
 */

#ifndef __MAC7100_H__
#define __MAC7100_H__

typedef volatile unsigned char      vuint8_t;
typedef volatile unsigned short     vuint16_t;
typedef volatile unsigned long      vuint32_t;
typedef volatile unsigned long long vuint64_t;


/*********************************************************************
*
* AEIM Module (AEIM)
*
*********************************************************************/

/* Register read/write macros */
#define AEIM_CSAR0                 (*(vuint16_t *)(0xFC008080)) /* AR - Chip Select Address Register */
#define AEIM_CSAR1                 (*(vuint16_t *)(0xFC00808C)) /* AR - Chip Select Address Register */
#define AEIM_CSAR2                 (*(vuint16_t *)(0xFC008098)) /* AR - Chip Select Address Register */
#define AEIM_CSAR(x)               (*(vuint16_t *)(0xFC008080+((x)*0x00C))) /* AR - Chip Select Address Register */
#define AEIM_CSMR0                 (*(vuint32_t *)(0xFC008084)) /* MR - Mask Register */
#define AEIM_CSMR1                 (*(vuint32_t *)(0xFC008090)) /* MR - Mask Register */
#define AEIM_CSMR2                 (*(vuint32_t *)(0xFC00809C)) /* MR - Mask Register */
#define AEIM_CSMR(x)               (*(vuint32_t *)(0xFC008084+((x)*0x00C))) /* MR - Mask Register */
#define AEIM_CSCR0                 (*(vuint16_t *)(0xFC00808A)) /* CR - Control Register */
#define AEIM_CSCR1                 (*(vuint16_t *)(0xFC008096)) /* CR - Control Register */
#define AEIM_CSCR2                 (*(vuint16_t *)(0xFC0080A2)) /* CR - Control Register */
#define AEIM_CSCR(x)               (*(vuint16_t *)(0xFC00808A+((x)*0x00C))) /* CR - Control Register */

/* Bit definitions and macros for AEIM_CSARn */
#define AEIM_BA(x)                 (((x)&0xFFFF)<<0)    /*  Base address */

/* Bit definitions and macros for AEIM_CSMRn */
#define AEIM_V                     (0x00000001)   /*  Valid */
#define AEIM_UD                    (0x00000002)   /*  User data address space mask */
#define AEIM_UC                    (0x00000004)   /*  User code address space mask */
#define AEIM_SD                    (0x00000008)   /*  Supervisor data address space mask */
#define AEIM_SC                    (0x00000010)   /*  Supervisor code address space mask */
#define AEIM_CI                    (0x00000020)   /*  CPU space and int ack cycle mask */
#define AEIM_AM                    (0x00000040)   /*  Alternate master */
#define AEIM_WP                    (0x00000100)   /*  Write protect */
#define AEIM_BAM(x)                (((x)&0x0000FFFF)<<16)   /*  Base address mask */

/* Bit definitions and macros for AEIM_CSCRn */
#define AEIM_BSTW                  (0x0008)       /*  Burst write enable */
#define AEIM_BSTR                  (0x0010)       /*  Burst read enable */
#define AEIM_BEM                   (0x0020)       /*  Byte enable mode */
#define AEIM_PS(x)                 (((x)&0x0003)<<6)    /*  Port size */
#define AEIM_AA                    (0x0100)       /*  Auto-acknowledge enable */
#define AEIM_WS(x)                 (((x)&0x000F)<<10)   /*  Wait states */

/*********************************************************************
*
* AIPS Module (AIPS)
*
*********************************************************************/

/* Register read/write macros */
#define AIPS_MPR                   (*(vuint32_t *)(0xFC000000)) /* MPR - Master Priviledge Register */
#define AIPS_PACRA                 (*(vuint32_t *)(0xFC000020)) /* PACRA - Peripheral Access Control Register A */
#define AIPS_PACRB                 (*(vuint32_t *)(0xFC000028)) /* PACRB - Peripheral Access Control Register B */
#define AIPS_OPACRA                (*(vuint32_t *)(0xFC000040)) /* OPACRA - Off-Platform Peripheral Access Control Register A */
#define AIPS_OPACRB                (*(vuint32_t *)(0xFC000044)) /* OPACRB - Off-Platform Peripheral Access Control Register B */
#define AIPS_OPACRC                (*(vuint32_t *)(0xFC000048)) /* OPACRC - Off-Platform Peripheral Access Control Register C */
#define AIPS_OPACRD                (*(vuint32_t *)(0xFC00004C)) /* OPACRD - Off-Platform Peripheral Access Control Register D */
#define AIPS_OPACRE                (*(vuint32_t *)(0xFC000050)) /* OPACRE - Off-Platform Peripheral Access Control Register E */

/* Bit definitions and macros for AIPS_MPR */
#define AIPS_MPROT1(x)             (((x)&0x0000000F)<<24)   /*  Master protection field 1 */
#define AIPS_MPROT0(x)             (((x)&0x0000000F)<<28)   /*  Master protection field 0 */

/* Bit definitions and macros for AIPS_PACRA */
#define AIPS_PACR2(x)              (((x)&0x0000000F)<<20)   /*  Peripheral Acc Ctrl 2 */
#define AIPS_PACR1(x)              (((x)&0x0000000F)<<24)   /*  Peripheral Acc Ctrl 1 */
#define AIPS_PACR0(x)              (((x)&0x0000000F)<<28)   /*  Peripheral Acc Ctrl 0 */

/* Bit definitions and macros for AIPS_PACRB */
#define AIPS_PACR18(x)             (((x)&0x0000000F)<<20)   /*  Peripheral Acc Ctrl 18 */
#define AIPS_PACR17(x)             (((x)&0x0000000F)<<24)   /*  Peripheral Acc Ctrl 17 */
#define AIPS_PACR16(x)             (((x)&0x0000000F)<<28)   /*  Peripheral Acc Ctrl 16 */

/* Bit definitions and macros for AIPS_OPACRA */
#define AIPS_OPACR7(x)             (((x)&0x0000000F)<<0)    /*  Off-platform Peripheral Acc Ctrl 7 */
#define AIPS_OPACR6(x)             (((x)&0x0000000F)<<4)    /*  Off-platform Peripheral Acc Ctrl 6 */
#define AIPS_OPACR5(x)             (((x)&0x0000000F)<<8)    /*  Off-platform Peripheral Acc Ctrl 5 */
#define AIPS_OPACR4(x)             (((x)&0x0000000F)<<12)   /*  Off-platform Peripheral Acc Ctrl 4 */
#define AIPS_OPACR3(x)             (((x)&0x0000000F)<<16)   /*  Off-platform Peripheral Acc Ctrl 3 */
#define AIPS_OPACR2(x)             (((x)&0x0000000F)<<20)   /*  Off-platform Peripheral Acc Ctrl 2 */
#define AIPS_OPACR1(x)             (((x)&0x0000000F)<<24)   /*  Off-platform Peripheral Acc Ctrl 1 */
#define AIPS_OPACR0(x)             (((x)&0x0000000F)<<28)   /*  Off-platform Peripheral Acc Ctrl 0 */

/* Bit definitions and macros for AIPS_OPACRB */
#define AIPS_OPACR14(x)            (((x)&0x0000000F)<<4)    /*  Off-platform Peripheral Acc Ctrl 14 */
#define AIPS_OPACR13(x)            (((x)&0x0000000F)<<8)    /*  Off-platform Peripheral Acc Ctrl 13 */
#define AIPS_OPACR11(x)            (((x)&0x0000000F)<<16)   /*  Off-platform Peripheral Acc Ctrl 11 */
#define AIPS_OPACR8(x)             (((x)&0x0000000F)<<28)   /*  Off-platform Peripheral Acc Ctrl 8 */

/* Bit definitions and macros for AIPS_OPACRC */
#define AIPS_OPACR23(x)            (((x)&0x0000000F)<<0)    /*  Off-platform Peripheral Acc Ctrl 23 */
#define AIPS_OPACR20(x)            (((x)&0x0000000F)<<12)   /*  Off-platform Peripheral Acc Ctrl 20 */
#define AIPS_OPACR19(x)            (((x)&0x0000000F)<<16)   /*  Off-platform Peripheral Acc Ctrl 19 */
#define AIPS_OPACR18(x)            (((x)&0x0000000F)<<20)   /*  Off-platform Peripheral Acc Ctrl 18 */
#define AIPS_OPACR17(x)            (((x)&0x0000000F)<<24)   /*  Off-platform Peripheral Acc Ctrl 17 */

/* Bit definitions and macros for AIPS_OPACRD */
#define AIPS_OPACR28(x)            (((x)&0x0000000F)<<12)   /*  Off-platform Peripheral Acc Ctrl 28 */
#define AIPS_OPACR26(x)            (((x)&0x0000000F)<<20)   /*  Off-platform Peripheral Acc Ctrl 26 */
#define AIPS_OPACR24(x)            (((x)&0x0000000F)<<28)   /*  Off-platform Peripheral Acc Ctrl 24 */

/* Bit definitions and macros for AIPS_OPACRE */
#define AIPS_OPACR33(x)            (((x)&0x0000000F)<<24)   /*  Off-platform Peripheral Acc Ctrl 33 */
#define AIPS_OPACR32(x)            (((x)&0x0000000F)<<28)   /*  Off-platform Peripheral Acc Ctrl 32 */

/*********************************************************************
*
* AXBS Module (AXBS)
*
*********************************************************************/

/* Register read/write macros */
#define AXBS_PR_EIM                (*(vuint32_t *)(0xFC004100)) /* PR_EIM - Priority Register for Slave Port to EIM */
#define AXBS_CR_EIM                (*(vuint32_t *)(0xFC004110)) /* CR_EIM - Control Register for Slave Port to EIM */
#define AXBS_PR_SRAM               (*(vuint32_t *)(0xFC004300)) /* PR_SRAM - Priority Register for Slave Port to RAM Controller */
#define AXBS_CR_SRAM               (*(vuint32_t *)(0xFC004310)) /* CR_SRAM - Control Register for Slave Port to RAM Controller */
#define AXBS_PR_PC                 (*(vuint32_t *)(0xFC004700))
#define AXBS_CR_PC                 (*(vuint32_t *)(0xFC004710))

/* Bit definitions and macros for AXBS_PR_EIM */
#define AXBS_CORE                  (0x00000001)   /*  Core Master Priority */
#define AXBS_DMA                   (0x00000010)   /*  DMA Master Priority */

/* Bit definitions and macros for AXBS_CR_EIM */
#define AXBS_PARK                  (0x00000001)   /*  Park */
#define AXBS_PCTL(x)               (((x)&0x00000003)<<4)    /*  Parking Control */
#define AXBS_ARB(x)                (((x)&0x00000003)<<8)    /*  Arbitration Mode */
#define AXBS_HLP                   (0x40000000)   /*  Halt Low Priority */
#define AXBS_RO                    (0x80000000)   /*  Read Only */

/*********************************************************************
*
* CFM Module (CFM)
*
*********************************************************************/

/* Register read/write macros */
#define CFM_CFMMCR                 (*(vuint16_t *)(0xFC0F0000)) /* MCR - Module Configuration Register. */
#define CFM_CFMCLKD                (*(vuint8_t  *)(0xFC0F0002)) /* CLKD - Clock Divider Register */
#define CFM_CFMSEC                 (*(vuint32_t *)(0xFC0F0008)) /* SEC - Security Register */
#define CFM_CFMPROT                (*(vuint32_t *)(0xFC0F0010)) /* PROT - Program Flash Protection Register */
#define CFM_CFMSACC                (*(vuint32_t *)(0xFC0F0014)) /* SACC - Program Flash Supervisor Access Register */
#define CFM_CFMDACC                (*(vuint32_t *)(0xFC0F0018)) /* DACC - Program Flash Data Access Register */
#define CFM_CFMUSTAT               (*(vuint8_t  *)(0xFC0F0020)) /* USTAT - User Status Register */
#define CFM_CFMCMD                 (*(vuint8_t  *)(0xFC0F0024)) /* CMD - Command Register */
#define CFM_CFMDATA0               (*(vuint32_t *)(0xFC0F0030)) /* DATA0 - CFM Data Register for Program Flash Block 0 and Data */
#define CFM_CFMDATA1               (*(vuint32_t *)(0xFC0F0038)) /* DATA1 - CFM Data Register for Program Flash Block 1 and Data */
#define CFM_CFMDFPROT              (*(vuint8_t  *)(0xFC0F0044)) /* DFPROT - Data Flash Protection Register */
#define CFM_CFMDFSACC              (*(vuint8_t  *)(0xFC0F0045)) /* DFSACC - Data Flash Supervisor Access Register */
#define CFM_CFMDFDACC              (*(vuint8_t  *)(0xFC0F0046)) /* DFDACC - Data Flash Data Access Register */
#define CFM_CFMCLKSEL              (*(vuint16_t *)(0xFC0F0050)) /* CFMCLKSEL - CFM Clock Select Register */

/* Bit definitions and macros for CFM_CFMMCR */
#define CFM_KEYACC                 (0x0020)       /*  Enable Security Key Writing */
#define CFM_CCIE                   (0x0040)       /*  Command Complete Int Enable */
#define CFM_CBEIE                  (0x0080)       /*  Command Buffer Empty Int Enable */
#define CFM_AEIE                   (0x0100)       /*  Access Error Interrupt Enable */
#define CFM_PVIE                   (0x0200)       /*  Protection Violation Int Enable */
#define CFM_LOCK                   (0x0400)       /*  Write lock control */
#define CFM_MRDS(x)                (((x)&0x0003)<<11)   /*  Margin Read Setting */

/* Bit definitions and macros for CFM_CFMCLKD */
#define CFM_DIV(x)                 (((x)&0x3F)<<0)  /*  Clock Divider Bits */
#define CFM_PRDIV8                 (0x40)         /*  Enable Prescalar by 8 */
#define CFM_DIVLD                  (0x80)         /*  Clock Divider Loaded */

/* Bit definitions and macros for CFM_CFMSEC */
#define CFM_SEC(x)                 (((x)&0x00000003)<<0)    /*  Flash Memory Security Bits */
#define CFM_SECSTAT                (0x20000000)   /*  Flash Memory Security Status */
#define CFM_KEYEN(x)               (((x)&0x00000003)<<30)   /*  Enable backdoor key access */

/* Bit definitions and macros for CFM_CFMPROT */
#define CFM_PROTECT0               (0x00000001)   /*  Protect flash, sect 0 */
#define CFM_PROTECT1               (0x00000002)   /*  Protect flash, sect 1 */
#define CFM_PROTECT2               (0x00000004)   /*  Protect flash, sect 2 */
#define CFM_PROTECT3               (0x00000008)   /*  Protect flash, sect 3 */
#define CFM_PROTECT4               (0x00000010)   /*  Protect flash, sect 4 */
#define CFM_PROTECT5               (0x00000020)   /*  Protect flash, sect 5 */
#define CFM_PROTECT6               (0x00000040)   /*  Protect flash, sect 6 */
#define CFM_PROTECT7               (0x00000080)   /*  Protect flash, sect 7 */
#define CFM_PROTECT8               (0x00000100)   /*  Protect flash, sect 8 */
#define CFM_PROTECT9               (0x00000200)   /*  Protect flash, sect 9 */
#define CFM_PROTECT10              (0x00000400)   /*  Protect flash, sect 10 */
#define CFM_PROTECT11              (0x00000800)   /*  Protect flash, sect 11 */
#define CFM_PROTECT12              (0x00001000)   /*  Protect flash, sect 12 */
#define CFM_PROTECT13              (0x00002000)   /*  Protect flash, sect 13 */
#define CFM_PROTECT14              (0x00004000)   /*  Protect flash, sect 14 */
#define CFM_PROTECT15              (0x00008000)   /*  Protect flash, sect 15 */
#define CFM_PROTECT16              (0x00010000)   /*  Protect flash, sect 16 */
#define CFM_PROTECT17              (0x00020000)   /*  Protect flash, sect 17 */
#define CFM_PROTECT18              (0x00040000)   /*  Protect flash, sect 18 */
#define CFM_PROTECT19              (0x00080000)   /*  Protect flash, sect 19 */
#define CFM_PROTECT20              (0x00100000)   /*  Protect flash, sect 20 */
#define CFM_PROTECT21              (0x00200000)   /*  Protect flash, sect 21 */
#define CFM_PROTECT22              (0x00400000)   /*  Protect flash, sect 22 */
#define CFM_PROTECT23              (0x00800000)   /*  Protect flash, sect 23 */
#define CFM_PROTECT24              (0x01000000)   /*  Protect flash, sect 24 */
#define CFM_PROTECT25              (0x02000000)   /*  Protect flash, sect 25 */
#define CFM_PROTECT26              (0x04000000)   /*  Protect flash, sect 26 */
#define CFM_PROTECT27              (0x08000000)   /*  Protect flash, sect 27 */
#define CFM_PROTECT28              (0x10000000)   /*  Protect flash, sect 28 */
#define CFM_PROTECT29              (0x20000000)   /*  Protect flash, sect 29 */
#define CFM_PROTECT30              (0x40000000)   /*  Protect flash, sect 30 */
#define CFM_PROTECT31              (0x80000000)   /*  Protect flash, sect 31 */

/* Bit definitions and macros for CFM_CFMSACC */
#define CFM_SUPV0                  (0x00000001)   /*  Supervisor flash access, sect 0 */
#define CFM_SUPV1                  (0x00000002)   /*  Supervisor flash access, sect 1 */
#define CFM_SUPV2                  (0x00000004)   /*  Supervisor flash access, sect 2 */
#define CFM_SUPV3                  (0x00000008)   /*  Supervisor flash access, sect 3 */
#define CFM_SUPV4                  (0x00000010)   /*  Supervisor flash access, sect 4 */
#define CFM_SUPV5                  (0x00000020)   /*  Supervisor flash access, sect 5 */
#define CFM_SUPV6                  (0x00000040)   /*  Supervisor flash access, sect 6 */
#define CFM_SUPV7                  (0x00000080)   /*  Supervisor flash access, sect 7 */
#define CFM_SUPV8                  (0x00000100)   /*  Supervisor flash access, sect 8 */
#define CFM_SUPV9                  (0x00000200)   /*  Supervisor flash access, sect 9 */
#define CFM_SUPV10                 (0x00000400)   /*  Supervisor flash access, sect 10 */
#define CFM_SUPV11                 (0x00000800)   /*  Supervisor flash access, sect 11 */
#define CFM_SUPV12                 (0x00001000)   /*  Supervisor flash access, sect 12 */
#define CFM_SUPV13                 (0x00002000)   /*  Supervisor flash access, sect 13 */
#define CFM_SUPV14                 (0x00004000)   /*  Supervisor flash access, sect 14 */
#define CFM_SUPV15                 (0x00008000)   /*  Supervisor flash access, sect 15 */
#define CFM_SUPV16                 (0x00010000)   /*  Supervisor flash access, sect 16 */
#define CFM_SUPV17                 (0x00020000)   /*  Supervisor flash access, sect 17 */
#define CFM_SUPV18                 (0x00040000)   /*  Supervisor flash access, sect 18 */
#define CFM_SUPV19                 (0x00080000)   /*  Supervisor flash access, sect 19 */
#define CFM_SUPV20                 (0x00100000)   /*  Supervisor flash access, sect 20 */
#define CFM_SUPV21                 (0x00200000)   /*  Supervisor flash access, sect 21 */
#define CFM_SUPV22                 (0x00400000)   /*  Supervisor flash access, sect 22 */
#define CFM_SUPV23                 (0x00800000)   /*  Supervisor flash access, sect 23 */
#define CFM_SUPV24                 (0x01000000)   /*  Supervisor flash access, sect 24 */
#define CFM_SUPV25                 (0x02000000)   /*  Supervisor flash access, sect 25 */
#define CFM_SUPV26                 (0x04000000)   /*  Supervisor flash access, sect 26 */
#define CFM_SUPV27                 (0x08000000)   /*  Supervisor flash access, sect 27 */
#define CFM_SUPV28                 (0x10000000)   /*  Supervisor flash access, sect 28 */
#define CFM_SUPV29                 (0x20000000)   /*  Supervisor flash access, sect 29 */
#define CFM_SUPV30                 (0x40000000)   /*  Supervisor flash access, sect 30 */
#define CFM_SUPV31                 (0x80000000)   /*  Supervisor flash access, sect 31 */

/* Bit definitions and macros for CFM_CFMDACC */
#define CFM_DACC0                  (0x00000001)   /*  Program Flash Data access, sect 0 */
#define CFM_DACC1                  (0x00000002)   /*  Program Flash Data access, sect 1 */
#define CFM_DACC2                  (0x00000004)   /*  Program Flash Data access, sect 2 */
#define CFM_DACC3                  (0x00000008)   /*  Program Flash Data access, sect 3 */
#define CFM_DACC4                  (0x00000010)   /*  Program Flash Data access, sect 4 */
#define CFM_DACC5                  (0x00000020)   /*  Program Flash Data access, sect 5 */
#define CFM_DACC6                  (0x00000040)   /*  Program Flash Data access, sect 6 */
#define CFM_DACC7                  (0x00000080)   /*  Program Flash Data access, sect 7 */
#define CFM_DACC8                  (0x00000100)   /*  Program Flash Data access, sect 8 */
#define CFM_DACC9                  (0x00000200)   /*  Program Flash Data access, sect 9 */
#define CFM_DACC10                 (0x00000400)   /*  Program Flash Data access, sect 10 */
#define CFM_DACC11                 (0x00000800)   /*  Program Flash Data access, sect 11 */
#define CFM_DACC12                 (0x00001000)   /*  Program Flash Data access, sect 12 */
#define CFM_DACC13                 (0x00002000)   /*  Program Flash Data access, sect 13 */
#define CFM_DACC14                 (0x00004000)   /*  Program Flash Data access, sect 14 */
#define CFM_DACC15                 (0x00008000)   /*  Program Flash Data access, sect 15 */
#define CFM_DACC16                 (0x00010000)   /*  Program Flash Data access, sect 16 */
#define CFM_DACC17                 (0x00020000)   /*  Program Flash Data access, sect 17 */
#define CFM_DACC18                 (0x00040000)   /*  Program Flash Data access, sect 18 */
#define CFM_DACC19                 (0x00080000)   /*  Program Flash Data access, sect 19 */
#define CFM_DACC20                 (0x00100000)   /*  Program Flash Data access, sect 20 */
#define CFM_DACC21                 (0x00200000)   /*  Program Flash Data access, sect 21 */
#define CFM_DACC22                 (0x00400000)   /*  Program Flash Data access, sect 22 */
#define CFM_DACC23                 (0x00800000)   /*  Program Flash Data access, sect 23 */
#define CFM_DACC24                 (0x01000000)   /*  Program Flash Data access, sect 24 */
#define CFM_DACC25                 (0x02000000)   /*  Program Flash Data access, sect 25 */
#define CFM_DACC26                 (0x04000000)   /*  Program Flash Data access, sect 26 */
#define CFM_DACC27                 (0x08000000)   /*  Program Flash Data access, sect 27 */
#define CFM_DACC28                 (0x10000000)   /*  Program Flash Data access, sect 28 */
#define CFM_DACC29                 (0x20000000)   /*  Program Flash Data access, sect 29 */
#define CFM_DACC30                 (0x40000000)   /*  Program Flash Data access, sect 30 */
#define CFM_DACC31                 (0x80000000)   /*  Program Flash Data access, sect 31 */

/* Bit definitions and macros for CFM_CFMUSTAT */
#define CFM_BLANK                  (0x04)         /*  Blank Flag */
#define CFM_ACCERR                 (0x10)         /*  Access Error Flag */
#define CFM_PVIOL                  (0x20)         /*  Protection Violation Flag */
#define CFM_CCIF                   (0x40)         /*  Command Complete Int Flag */
#define CFM_CBEIF                  (0x80)         /*  Command Buffer Empty Int Flag */

/* Bit definitions and macros for CFM_CFMCMD */
#define CFM_CMD(x)                 (((x)&0x7F)<<0)  /*  Command */

/* Bit definitions and macros for CFM_CFMDFPROT */
#define CFM_PROTECT_DF0            (0x01)         /*  Protect data flash, sector 0 */
#define CFM_PROTECT_DF1            (0x02)         /*  Protect data flash, sector 1 */
#define CFM_PROTECT_DF2            (0x04)         /*  Protect data flash, sector 2 */
#define CFM_PROTECT_DF3            (0x08)         /*  Protect data flash, sector 3 */
#define CFM_PROTECT_DF4            (0x10)         /*  Protect data flash, sector 4 */
#define CFM_PROTECT_DF5            (0x20)         /*  Protect data flash, sector 5 */
#define CFM_PROTECT_DF6            (0x40)         /*  Protect data flash, sector 6 */
#define CFM_PROTECT_DF7            (0x80)         /*  Protect data flash, sector 7 */

/* Bit definitions and macros for CFM_CFMDFSACC */
#define CFM_SUPV_DF0               (0x01)         /*  Supv data flash access, sect 0 */
#define CFM_SUPV_DF1               (0x02)         /*  Supv data flash access, sect 1 */
#define CFM_SUPV_DF2               (0x04)         /*  Supv data flash access, sect 2 */
#define CFM_SUPV_DF3               (0x08)         /*  Supv data flash access, sect 3 */
#define CFM_SUPV_DF4               (0x10)         /*  Supv data flash access, sect 4 */
#define CFM_SUPV_DF5               (0x20)         /*  Supv data flash access, sect 5 */
#define CFM_SUPV_DF6               (0x40)         /*  Supv data flash access, sect 6 */
#define CFM_SUPV_DF7               (0x80)         /*  Supv data flash access, sect 7 */

/* Bit definitions and macros for CFM_CFMDFDACC */
#define CFM_DACC_DF0               (0x01)         /*  Flash Data Access, sector 0 */
#define CFM_DACC_DF1               (0x02)         /*  Flash Data Access, sector 1 */
#define CFM_DACC_DF2               (0x04)         /*  Flash Data Access, sector 2 */
#define CFM_DACC_DF3               (0x08)         /*  Flash Data Access, sector 3 */
#define CFM_DACC_DF4               (0x10)         /*  Flash Data Access, sector 4 */
#define CFM_DACC_DF5               (0x20)         /*  Flash Data Access, sector 5 */
#define CFM_DACC_DF6               (0x40)         /*  Flash Data Access, sector 6 */
#define CFM_DACC_DF7               (0x80)         /*  Flash Data Access, sector 7 */

/* Bit definitions and macros for CFM_CFMCLKSEL */
#define CFM_CLKSEL(x)              (((x)&0x0003)<<0)    /* Program Flash read access latency select */

/*********************************************************************
*
* CRG Module (CRG)
*
*********************************************************************/

/* Register read/write macros */
#define CRG_SYNR                   (*(vuint8_t  *)(0xFC088000)) /* SYNR - Synthesizer Register */
#define CRG_REFDV                  (*(vuint8_t  *)(0xFC088001)) /* REFDV - Reference Divider Register */
#define CRG_CTFLG                  (*(vuint8_t  *)(0xFC088002)) /* CTFLG - Test Flags Register (reserved for factory use) */
#define CRG_CRGFLG                 (*(vuint8_t  *)(0xFC088003)) /* CRGFLG - Flags Register */
#define CRG_CRGINT                 (*(vuint8_t  *)(0xFC088004)) /* CRGINT - Interrupt Enable Register */
#define CRG_CLKSEL                 (*(vuint8_t  *)(0xFC088005)) /* CLKSEL - Clock Select Register */
#define CRG_PLLCTL                 (*(vuint8_t  *)(0xFC088006)) /* PLLCTL - PLL Control Register */
#define CRG_SDMCTL                 (*(vuint8_t  *)(0xFC088007)) /* SDMCTL - STOP/DOZE Control Register */
#define CRG_BDMCTL                 (*(vuint8_t  *)(0xFC088008)) /* BDMCTL - BDM Control Register */
#define CRG_FORBYP                 (*(vuint8_t  *)(0xFC088009)) /* FORBYP - Force and Bypass Test Register (reserved for factory use) */
#define CRG_CTCTL                  (*(vuint8_t  *)(0xFC08800A)) /* CTCTL - Test Control Register (reserved for factory use) */

/* Bit definitions and macros for CRG_SYNR */
#define CRG_SYN(x)                 (((x)&0x3F)<<0)  /*  Synthesizer Count value */

/* Bit definitions and macros for CRG_REFDV */
#define CRG_REFD(x)                (((x)&0x0F)<<0)  /*  Reference divider */

/* Bit definitions and macros for CRG_CRGFLG */
#define CRG_SCM                    (0x01)         /*  Self Clock Mode Status */
#define CRG_SCMIF                  (0x02)         /*  Self Clock Mode Interrupt Flag */
#define CRG_TRACK                  (0x04)         /*  Track Status */
#define CRG_LOCK                   (0x08)         /*  Lock Status */
#define CRG_LOCKIF                 (0x10)         /*  PLL Lock Interrupt Flag */
#define CRG_LVRF                   (0x20)         /*  Low Voltage Reset Flag */
#define CRG_PORF                   (0x40)         /*  Power on Reset Flag */
#define CRG_STPEF                  (0x80)         /*  Stop Entry Flag */

/* Bit definitions and macros for CRG_CRGINT */
#define CRG_SCMIE                  (0x02)         /*  Self Clock Mode Interrupt Enable */
#define CRG_LOCKIE                 (0x10)         /*  Lock Interrupt Enable */

/* Bit definitions and macros for CRG_CLKSEL */
#define CRG_SWTDOZE                (0x01)         /*  SWT stops in Doze Mode */
#define CRG_RTIDOZE                (0x02)         /*  RTI stops in Doze Mode */
#define CRG_PLLDOZE                (0x08)         /*  PLL stops in Doze Mode */
#define CRG_DOZE_ROA               (0x10)         /*  Reduced Osc Amplitude in Doze Mode */
#define CRG_PSTP                   (0x40)         /*  Pseudo Stop */
#define CRG_PLLSEL                 (0x80)         /*  PLL Select */

/* Bit definitions and macros for CRG_PLLCTL */
#define CRG_SCME                   (0x01)         /*  Self Clock Mode Enable */
#define CRG_PWE                    (0x02)         /*  SWT Enable during Pseudo Stop */
#define CRG_PRE                    (0x04)         /*  RTI Enable during Pseudo Stop */
#define CRG_FSTWKP                 (0x08)         /*  Fast Wake-up from Full Stop Bit */
#define CRG_ACQ                    (0x10)         /*  Acquisition */
#define CRG_AUTO                   (0x20)         /*  Automatic Bandwidth Control */
#define CRG_PLLON                  (0x40)         /*  Phase Lock Loop On */
#define CRG_CME                    (0x80)         /*  Clock Monitor Enable */

/* Bit definitions and macros for CRG_SDMCTL */
#define CRG_STOP                   (0x01)         /*  STOP mode */
#define CRG_DOZE                   (0x02)         /*  DOZE mode */

/* Bit definitions and macros for CRG_BDMCTL */
#define CRG_RSBCK                  (0x40)         /*  SWT and RTI stop in Active BDM mode */

/*********************************************************************
*
* DMAMUX Module (DMAMUX)
*
*********************************************************************/

/* Register read/write macros */
#define DMAMUX_CHCONFIG0           (*(vuint8_t  *)(0xFC084000))
#define DMAMUX_CHCONFIG1           (*(vuint8_t  *)(0xFC084001))
#define DMAMUX_CHCONFIG2           (*(vuint8_t  *)(0xFC084002))
#define DMAMUX_CHCONFIG3           (*(vuint8_t  *)(0xFC084003))
#define DMAMUX_CHCONFIG4           (*(vuint8_t  *)(0xFC084004))
#define DMAMUX_CHCONFIG5           (*(vuint8_t  *)(0xFC084005))
#define DMAMUX_CHCONFIG6           (*(vuint8_t  *)(0xFC084006))
#define DMAMUX_CHCONFIG7           (*(vuint8_t  *)(0xFC084007))
#define DMAMUX_CHCONFIG8           (*(vuint8_t  *)(0xFC084008))
#define DMAMUX_CHCONFIG9           (*(vuint8_t  *)(0xFC084009))
#define DMAMUX_CHCONFIG10          (*(vuint8_t  *)(0xFC08400A))
#define DMAMUX_CHCONFIG11          (*(vuint8_t  *)(0xFC08400B))
#define DMAMUX_CHCONFIG12          (*(vuint8_t  *)(0xFC08400C))
#define DMAMUX_CHCONFIG13          (*(vuint8_t  *)(0xFC08400D))
#define DMAMUX_CHCONFIG14          (*(vuint8_t  *)(0xFC08400E))
#define DMAMUX_CHCONFIG15          (*(vuint8_t  *)(0xFC08400F))
#define DMAMUX_CHCONFIG(x)         (*(vuint8_t  *)(0xFC084000+((x)*0x001)))

/* Bit definitions and macros for DMAMUX_CHCONFIGn */
#define DMAMUX_SOURCE(x)           (((x)&0x3F)<<0)  /*  Source */
#define DMAMUX_TRIG                (0x40)         /*  Trigger Enable (ONLY on Channel 0-7) */
#define DMAMUX_ENBL                (0x80)         /*  Channel Enable */

/*********************************************************************
*
* DMATD1016 Module (ATD)
*
*********************************************************************/

/* Register read/write macros */
#define ATD0_TRIGCTL               (*(vuint8_t  *)(0xFC0E0000))
#define ATD0_ETRIGCH               (*(vuint8_t  *)(0xFC0E0001))
#define ATD0_PRE                   (*(vuint8_t  *)(0xFC0E0002))
#define ATD0_MODE                  (*(vuint8_t  *)(0xFC0E0003))
#define ATD0_INT                   (*(vuint8_t  *)(0xFC0E000E))
#define ATD0_FLAG                  (*(vuint8_t  *)(0xFC0E000F))
#define ATD0_CW                    (*(vuint32_t *)(0xFC0E0010))
#define ATD0_RR                    (*(vuint32_t *)(0xFC0E0014))
#define ATD1_TRIGCTL               (*(vuint8_t  *)(0xFC0E4000))
#define ATD1_ETRIGCH               (*(vuint8_t  *)(0xFC0E4001))
#define ATD1_PRE                   (*(vuint8_t  *)(0xFC0E4002))
#define ATD1_MODE                  (*(vuint8_t  *)(0xFC0E4003))
#define ATD1_INT                   (*(vuint8_t  *)(0xFC0E400E))
#define ATD1_FLAG                  (*(vuint8_t  *)(0xFC0E400F))
#define ATD1_CW                    (*(vuint32_t *)(0xFC0E4010))
#define ATD1_RR                    (*(vuint32_t *)(0xFC0E4014))
#define ATD_TRIGCTL(x)             (*(vuint8_t  *)(0xFC0E0000+((x)*0x4000)))
#define ATD_ETRIGCH(x)             (*(vuint8_t  *)(0xFC0E0001+((x)*0x4000)))
#define ATD_PRE(x)                 (*(vuint8_t  *)(0xFC0E0002+((x)*0x4000)))
#define ATD_MODE(x)                (*(vuint8_t  *)(0xFC0E0003+((x)*0x4000)))
#define ATD_INT(x)                 (*(vuint8_t  *)(0xFC0E000E+((x)*0x4000)))
#define ATD_FLAG(x)                (*(vuint8_t  *)(0xFC0E000F+((x)*0x4000)))
#define ATD_CW(x)                  (*(vuint32_t *)(0xFC0E0010+((x)*0x4000)))
#define ATD_RR(x)                  (*(vuint32_t *)(0xFC0E0014+((x)*0x4000)))

/* Bit definitions and macros for ATD_TRIGCTL */
#define ATD_TRIGLE                 (0x01)         /*  Trigger is level/edge sensitive */
#define ATD_TRIGP                  (0x02)         /*  Trigger polarity */
#define ATD_TRIGSEL(x)             (((x)&0x03)<<2)  /*  Trigger source select */

/* Bit definitions and macros for ATD_ETRIGCH */
#define ATD_TRIGCH(x)              (((x)&0x0F)<<0)  /*  External Trigger Channel */

/* Bit definitions and macros for ATD_PRE */
#define ATD_PRES(x)                (((x)&0x7F)<<0)  /*  Prescaler */

/* Bit definitions and macros for ATD_MODE */
#define ATD_DEBUG(x)               (((x)&0x03)<<4)  /*  Debug mode support */
#define ATD_DOZE                   (0x40)         /*  Doze mode support */
#define ATD_MDIS                   (0x80)         /*  Module disable (Disabled Mode) */

/* Bit definitions and macros for ATD_INT */
#define ATD_CCIE                   (0x01)         /*  Conversion complete interrupt enable */
#define ATD_CPIE                   (0x02)         /*  Conversion paused interrupt enable */
#define ATD_ETOIE                  (0x04)         /*  External trigger overrun interrupt enable */
#define ATD_CRLIE                  (0x08)         /*  Conversion result lost interrupt enable */
#define ATD_CQEIE                  (0x10)         /*  Command queue empty interrupt enable */
#define ATD_CQFIE                  (0x20)         /*  Command queue full interrupt enable */

/* Bit definitions and macros for ATD_FLAG */
#define ATD_CC                     (0x01)         /*  Conversion complete flag */
#define ATD_CP                     (0x02)         /*  Conversion paused flag */
#define ATD_ETO                    (0x04)         /*  External trigger overrun flag */
#define ATD_CRL                    (0x08)         /*  Conversion result lost flag */
#define ATD_CQE                    (0x10)         /*  Command queue empty flag */
#define ATD_CQF                    (0x20)         /*  Command queue full flag */

/* Bit definitions and macros for ATD_CW */
#define ATD_CWCH(x)                (((x)&0x0000000F)<<16)   /*  Command word channel */
#define ATD_CWNF(x)                (((x)&0x00000003)<<21)   /*  Command word numeric format */
#define ATD_CW8                    (0x00800000)   /*  Command word 8 Bit resolution */
#define ATD_CWSB                   (0x01000000)   /*  Command word sample amplifier bypass */
#define ATD_CWSL(x)                (((x)&0x00000003)<<25)   /*  Command word sample length */
#define ATD_CWCM(x)                (((x)&0x00000003)<<27)   /*  Command word conversion mode */
#define ATD_CWGI                   (0x20000000)   /*  Command word generate interrupt */
#define ATD_CWSC                   (0x40000000)   /*  Command word special channel */

/* Bit definitions and macros for ATD_RR */
#define ATD_RRCR(x)                (((x)&0x0000FFFF)<<0)    /*  Result register conversion result */
#define ATD_RRCH(x)                (((x)&0x0000000F)<<16)   /*  Result register channel */
#define ATD_RRNF(x)                (((x)&0x00000003)<<21)   /*  Result register numeric format */
#define ATD_RR8                    (0x00800000)   /*  Result register 8 Bit resolution */
#define ATD_RRSB                   (0x01000000)   /*  Result register sample amplifier bypass */
#define ATD_RRSL(x)                (((x)&0x00000003)<<25)   /*  Result register sample length */
#define ATD_RRCM(x)                (((x)&0x00000003)<<27)   /*  Result register conversion mode */
#define ATD_RRGI                   (0x20000000)   /*  Result register generate interrupt */
#define ATD_RRSC                   (0x40000000)   /*  Result register special channel */

/*********************************************************************
*
* DSPI Module (DSPI)
*
*********************************************************************/

/* Register read/write macros */
#define DSPI0_MCR                  (*(vuint32_t *)(0xFC0B4000)) /* MCR - Module Configuration Register */
#define DSPI0_TCR                  (*(vuint32_t *)(0xFC0B4008)) /* TCR - Transfer Count Register */
#define DSPI0_CTAR0                (*(vuint32_t *)(0xFC0B400C)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI0_CTAR1                (*(vuint32_t *)(0xFC0B4010)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI0_CTAR2                (*(vuint32_t *)(0xFC0B4014)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI0_CTAR3                (*(vuint32_t *)(0xFC0B4018)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI0_CTAR4                (*(vuint32_t *)(0xFC0B401C)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI0_CTAR5                (*(vuint32_t *)(0xFC0B4020)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI0_CTAR(x)              (*(vuint32_t *)(0xFC0B400C+((x)*0x004))) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI0_SR                   (*(vuint32_t *)(0xFC0B402C)) /* SR - Status Register */
#define DSPI0_RSER                 (*(vuint32_t *)(0xFC0B4030)) /* RSER - DMA/Interrupt Request Select and Enable Register */
#define DSPI0_PUSHR                (*(vuint32_t *)(0xFC0B4034)) /* PUSHR - PUSH TX FIFO Register */
#define DSPI0_POPR                 (*(vuint32_t *)(0xFC0B4038)) /* POPR - POP RX FIFO Register */
#define DSPI0_TXFR0                (*(vuint32_t *)(0xFC0B403C)) /* TXFR[n] - Transmit FIFO Registers */
#define DSPI0_TXFR1                (*(vuint32_t *)(0xFC0B4040)) /* TXFR[n] - Transmit FIFO Registers */
#define DSPI0_TXFR2                (*(vuint32_t *)(0xFC0B4044)) /* TXFR[n] - Transmit FIFO Registers */
#define DSPI0_TXFR3                (*(vuint32_t *)(0xFC0B4048)) /* TXFR[n] - Transmit FIFO Registers */
#define DSPI0_TXFR(x)              (*(vuint32_t *)(0xFC0B403C+((x)*0x004))) /* TXFR[n] - Transmit FIFO Registers */
#define DSPI0_RXFR0                (*(vuint32_t *)(0xFC0B407C)) /* RXFR[n] - Receive FIFO Registers */
#define DSPI0_RXFR1                (*(vuint32_t *)(0xFC0B4080)) /* RXFR[n] - Receive FIFO Registers */
#define DSPI0_RXFR2                (*(vuint32_t *)(0xFC0B4084)) /* RXFR[n] - Receive FIFO Registers */
#define DSPI0_RXFR3                (*(vuint32_t *)(0xFC0B4088)) /* RXFR[n] - Receive FIFO Registers */
#define DSPI0_RXFR(x)              (*(vuint32_t *)(0xFC0B407C+((x)*0x004))) /* RXFR[n] - Receive FIFO Registers */
#define DSPI1_MCR                  (*(vuint32_t *)(0xFC0B8000)) /* MCR - Module Configuration Register */
#define DSPI1_TCR                  (*(vuint32_t *)(0xFC0B8008)) /* TCR - Transfer Count Register */
#define DSPI1_CTAR0                (*(vuint32_t *)(0xFC0B800C)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI1_CTAR1                (*(vuint32_t *)(0xFC0B8010)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI1_CTAR2                (*(vuint32_t *)(0xFC0B8014)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI1_CTAR3                (*(vuint32_t *)(0xFC0B8018)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI1_CTAR4                (*(vuint32_t *)(0xFC0B801C)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI1_CTAR5                (*(vuint32_t *)(0xFC0B8020)) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI1_CTAR(x)              (*(vuint32_t *)(0xFC0B800C+((x)*0x004))) /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI1_SR                   (*(vuint32_t *)(0xFC0B802C)) /* SR - Status Register */
#define DSPI1_RSER                 (*(vuint32_t *)(0xFC0B8030)) /* RSER - DMA/Interrupt Request Select and Enable Register */
#define DSPI1_PUSHR                (*(vuint32_t *)(0xFC0B8034)) /* PUSHR - PUSH TX FIFO Register */
#define DSPI1_POPR                 (*(vuint32_t *)(0xFC0B8038)) /* POPR - POP RX FIFO Register */
#define DSPI1_TXFR0                (*(vuint32_t *)(0xFC0B803C)) /* TXFR[n] - Transmit FIFO Registers */
#define DSPI1_TXFR1                (*(vuint32_t *)(0xFC0B8040)) /* TXFR[n] - Transmit FIFO Registers */
#define DSPI1_TXFR2                (*(vuint32_t *)(0xFC0B8044)) /* TXFR[n] - Transmit FIFO Registers */
#define DSPI1_TXFR3                (*(vuint32_t *)(0xFC0B8048)) /* TXFR[n] - Transmit FIFO Registers */
#define DSPI1_TXFR(x)              (*(vuint32_t *)(0xFC0B803C+((x)*0x004))) /* TXFR[n] - Transmit FIFO Registers */
#define DSPI1_RXFR0                (*(vuint32_t *)(0xFC0B807C)) /* RXFR[n] - Receive FIFO Registers */
#define DSPI1_RXFR1                (*(vuint32_t *)(0xFC0B8080)) /* RXFR[n] - Receive FIFO Registers */
#define DSPI1_RXFR2                (*(vuint32_t *)(0xFC0B8084)) /* RXFR[n] - Receive FIFO Registers */
#define DSPI1_RXFR3                (*(vuint32_t *)(0xFC0B8088)) /* RXFR[n] - Receive FIFO Registers */
#define DSPI1_RXFR(x)              (*(vuint32_t *)(0xFC0B807C+((x)*0x004))) /* RXFR[n] - Receive FIFO Registers */
#define DSPI_MCR(x)                (*(vuint32_t *)(0xFC0B4000+((x)*0x4000)))    /* MCR - Module Configuration Register */
#define DSPI_TCR(x)                (*(vuint32_t *)(0xFC0B4008+((x)*0x4000)))    /* TCR - Transfer Count Register */
#define DSPI_CTAR0(x)              (*(vuint32_t *)(0xFC0B400C+((x)*0x4000)))    /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI_CTAR1(x)              (*(vuint32_t *)(0xFC0B4010+((x)*0x4000)))    /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI_CTAR2(x)              (*(vuint32_t *)(0xFC0B4014+((x)*0x4000)))    /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI_CTAR3(x)              (*(vuint32_t *)(0xFC0B4018+((x)*0x4000)))    /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI_CTAR4(x)              (*(vuint32_t *)(0xFC0B401C+((x)*0x4000)))    /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI_CTAR5(x)              (*(vuint32_t *)(0xFC0B4020+((x)*0x4000)))    /* CTAR[n] - Clock and Transfer Attributes Registers */
#define DSPI_SR(x)                 (*(vuint32_t *)(0xFC0B402C+((x)*0x4000)))    /* SR - Status Register */
#define DSPI_RSER(x)               (*(vuint32_t *)(0xFC0B4030+((x)*0x4000)))    /* RSER - DMA/Interrupt Request Select and Enable Register */
#define DSPI_PUSHR(x)              (*(vuint32_t *)(0xFC0B4034+((x)*0x4000)))    /* PUSHR - PUSH TX FIFO Register */
#define DSPI_POPR(x)               (*(vuint32_t *)(0xFC0B4038+((x)*0x4000)))    /* POPR - POP RX FIFO Register */
#define DSPI_TXFR0(x)              (*(vuint32_t *)(0xFC0B403C+((x)*0x4000)))    /* TXFR[n] - Transmit FIFO Registers */
#define DSPI_TXFR1(x)              (*(vuint32_t *)(0xFC0B4040+((x)*0x4000)))    /* TXFR[n] - Transmit FIFO Registers */
#define DSPI_TXFR2(x)              (*(vuint32_t *)(0xFC0B4044+((x)*0x4000)))    /* TXFR[n] - Transmit FIFO Registers */
#define DSPI_TXFR3(x)              (*(vuint32_t *)(0xFC0B4048+((x)*0x4000)))    /* TXFR[n] - Transmit FIFO Registers */
#define DSPI_RXFR0(x)              (*(vuint32_t *)(0xFC0B407C+((x)*0x4000)))    /* RXFR[n] - Receive FIFO Registers */
#define DSPI_RXFR1(x)              (*(vuint32_t *)(0xFC0B4080+((x)*0x4000)))    /* RXFR[n] - Receive FIFO Registers */
#define DSPI_RXFR2(x)              (*(vuint32_t *)(0xFC0B4084+((x)*0x4000)))    /* RXFR[n] - Receive FIFO Registers */
#define DSPI_RXFR3(x)              (*(vuint32_t *)(0xFC0B4088+((x)*0x4000)))    /* RXFR[n] - Receive FIFO Registers */

/* Bit definitions and macros for DSPI_MCR */
#define DSPI_HALT                  (0x00000001)   /*  Halt */
#define DSPI_SMPL_PT(x)            (((x)&0x00000003)<<8)    /*  Sample Point */
#define DSPI_CLR_RXF               (0x00000400)   /*  Clear RX FIFO */
#define DSPI_CLR_TXF               (0x00000800)   /*  Clear TX FIFO */
#define DSPI_DIS_RXF               (0x00001000)   /*  Disable Receive FIFO */
#define DSPI_DIS_TXF               (0x00002000)   /*  Disable Transmit FIFO */
#define DSPI_MDIS                  (0x00004000)   /*  Module Disable */
#define DSPI_DOZE                  (0x00008000)   /*  Doze Enable */
#define DSPI_PCSIS0                (0x00010000)   /*  Peripheral Chip Select Inactive State 0 */
#define DSPI_PCSIS1                (0x00020000)   /*  Peripheral Chip Select Inactive State 1 */
#define DSPI_PCSIS2                (0x00040000)   /*  Peripheral Chip Select Inactive State 2 */
#define DSPI_PCSIS3                (0x00080000)   /*  Peripheral Chip Select Inactive State 3 */
#define DSPI_PCSIS4                (0x00100000)   /*  Peripheral Chip Select Inactive State 4 */
#define DSPI_PCSIS5                (0x00200000)   /*  Peripheral Chip Select Inactive State 5 */
#define DSPI_PCSIS6                (0x00400000)   /*  Peripheral Chip Select Inactive State 6 */
#define DSPI_PCSIS7                (0x00800000)   /*  Peripheral Chip Select Inactive State 7 */
#define DSPI_ROOE                  (0x01000000)   /*  Receive FIFO Overflow Overwrite Enable */
#define DSPI_PCSSE                 (0x02000000)   /*  Peripheral Chip Select Strobe Enable */
#define DSPI_MTFE                  (0x04000000)   /*  Modified Timing Format Enable */
#define DSPI_FRZ                   (0x08000000)   /*  Freeze */
#define DSPI_DCONF(x)              (((x)&0x00000003)<<28)   /*  DSPI Configuration */
#define DSPI_CONT_SCKE             (0x40000000)   /*  Continuous SCK Enable */
#define DSPI_MSTR                  (0x80000000)   /*  Master/Slave Mode Select */

/* Bit definitions and macros for DSPI_TCR */
#define DSPI_SPI_TCNT(x)           (((x)&0x0000FFFF)<<16)   /*  SPI Transfer Counter */

/* Bit definitions and macros for DSPI_CTARn */
#define DSPI_BR(x)                 (((x)&0x0000000F)<<0)    /*  Baud Rate Scaler */
#define DSPI_DT(x)                 (((x)&0x0000000F)<<4)    /*  Delay after Transfer Scaler */
#define DSPI_ASC(x)                (((x)&0x0000000F)<<8)    /*  After SCK Delay Scaler */
#define DSPI_CSSCK(x)              (((x)&0x0000000F)<<12)   /*  PCS to SCK Delay Scaler */
#define DSPI_PBR(x)                (((x)&0x00000003)<<16)   /*  Baud Rate Prescaler */
#define DSPI_PDT(x)                (((x)&0x00000003)<<18)   /*  Delay after Transfer Prescaler */
#define DSPI_PASC(x)               (((x)&0x00000003)<<20)   /*  After SCK Delay Prescaler */
#define DSPI_PCSSCK(x)             (((x)&0x00000003)<<22)   /*  PCS to SCK Delay Prescaler */
#define DSPI_LSBFE                 (0x01000000)   /*  LSB First Enable */
#define DSPI_CPHA                  (0x02000000)   /*  Clock Phase */
#define DSPI_CPOL                  (0x04000000)   /*  Clock Polarity */
#define DSPI_FMSZ(x)               (((x)&0x0000000F)<<27)   /*  Frame Size */
#define DSPI_DBR                   (0x80000000)   /*  Double Baud Rate */

/* Bit definitions and macros for DSPI_SR */
#define DSPI_POPNXTPTR(x)          (((x)&0x0000000F)<<0)    /*  Pop Next Pointer */
#define DSPI_RXCTR(x)              (((x)&0x0000000F)<<4)    /*  RX FIFO Counter */
#define DSPI_TXNXTPTR(x)           (((x)&0x0000000F)<<8)    /*  Transmit Next Pointer */
#define DSPI_TXCTR(x)              (((x)&0x0000000F)<<12)   /*  TX FIFO Counter */
#define DSPI_RFDF                  (0x00020000)   /*  Receive FIFO Drain Flag */
#define DSPI_RFOF                  (0x00080000)   /*  Receive FIFO Overflow Flag */
#define DSPI_TFFF                  (0x02000000)   /*  Transmit FIFO Fill Flag */
#define DSPI_TFUF                  (0x08000000)   /*  Transmit FIFO Underflow Flag */
#define DSPI_EOQF                  (0x10000000)   /*  End of Queue Flag */
#define DSPI_TXRXS                 (0x40000000)   /*  TX & RX Status */
#define DSPI_TCF                   (0x80000000)   /*  Transfer Complete Flag */

/* Bit definitions and macros for DSPI_RSER */
#define DSPI_RFDF_DIRS             (0x00010000)   /*  Receive FIFO Drain DMA or Int Req Select */
#define DSPI_RFDF_RE               (0x00020000)   /*  Receive FIFO Drain Request Enable */
#define DSPI_RFOF_RE               (0x00080000)   /*  Receive FIFO Overflow Request Enable */
#define DSPI_TFFF_DIRS             (0x01000000)   /*  Transmit FIFO Fill DMA or Int Req Select */
#define DSPI_TFFF_RE               (0x02000000)   /*  Transmit FIFO Fill Request Enable */
#define DSPI_TFUF_RE               (0x08000000)   /*  Transmit FIFO Underflow Request Enable */
#define DSPI_EOQF_RE               (0x10000000)   /*  DSPI Finished Request Enable */
#define DSPI_TCF_RE                (0x80000000)   /*  Transmission Complete Request Enable */

/* Bit definitions and macros for DSPI_PUSHR */
#define DSPI_TXDATA(x)             (((x)&0x0000FFFF)<<0)    /*  Transmit Data */
#define DSPI_PCS0                  (0x00010000)   /*  Peripheral Chip Select 0 */
#define DSPI_PCS1                  (0x00020000)   /*  Peripheral Chip Select 1 */
#define DSPI_PCS2                  (0x00040000)   /*  Peripheral Chip Select 2 */
#define DSPI_PCS3                  (0x00080000)   /*  Peripheral Chip Select 3 */
#define DSPI_PCS4                  (0x00100000)   /*  Peripheral Chip Select 4 */
#define DSPI_PCS5                  (0x00200000)   /*  Peripheral Chip Select 5 */
#define DSPI_PCS6                  (0x00400000)   /*  Peripheral Chip Select 6 */
#define DSPI_PCS7                  (0x00800000)   /*  Peripheral Chip Select 7 */
#define DSPI_CTCNT                 (0x04000000)   /*  Clear SPI_TCNT */
#define DSPI_EOQ                   (0x08000000)   /*  End Of Queue */
#define DSPI_CTAS(x)               (((x)&0x00000007)<<28)   /*  Clock and Transfer Attributes Select */
#define DSPI_CONT                  (0x80000000)   /*  Continuous Peripheral Chip Select Enable */

/* Bit definitions and macros for DSPI_POPR */
#define DSPI_RXDATA(x)             (((x)&0x0000FFFF)<<0)    /*  Received Data */

/* Bit definitions and macros for DSPI_TXFRn */
#define DSPI_TXDATA(x)             (((x)&0x0000FFFF)<<0)    /*  Transmit Data */
#define DSPI_TXCMD(x)              (((x)&0x0000FFFF)<<16)   /*  Transmit Command */

/* Bit definitions and macros for DSPI_RXFRn */
#define DSPI_RXDATA(x)             (((x)&0x0000FFFF)<<0)    /*  Receive Data */

/*********************************************************************
*
* EDMAC Module (EDMAC)
*
*********************************************************************/

/* Register read/write macros */
#define EDMAC_CR                   (*(vuint32_t *)(0xFC044000)) /* CR - Control Register */
#define EDMAC_ES                   (*(vuint32_t *)(0xFC044004)) /* ES - Error Status Register */
#define EDMAC_ERQ                  (*(vuint16_t *)(0xFC04400E))
#define EDMAC_EEI                  (*(vuint16_t *)(0xFC044016))
#define EDMAC_SERQ                 (*(vuint8_t  *)(0xFC044018))
#define EDMAC_CERQ                 (*(vuint8_t  *)(0xFC044019))
#define EDMAC_SEEI                 (*(vuint8_t  *)(0xFC04401A))
#define EDMAC_CEEI                 (*(vuint8_t  *)(0xFC04401B))
#define EDMAC_CINT                 (*(vuint8_t  *)(0xFC04401C))
#define EDMAC_CERR                 (*(vuint8_t  *)(0xFC04401D))
#define EDMAC_SSRT                 (*(vuint8_t  *)(0xFC04401E))
#define EDMAC_CDNE                 (*(vuint8_t  *)(0xFC04401F))
#define EDMAC_INT                  (*(vuint16_t *)(0xFC044026))
#define EDMAC_ERR                  (*(vuint16_t *)(0xFC04402E))
#define EDMAC_DCHPRI0              (*(vuint8_t  *)(0xFC044100)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI1              (*(vuint8_t  *)(0xFC044101)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI2              (*(vuint8_t  *)(0xFC044102)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI3              (*(vuint8_t  *)(0xFC044103)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI4              (*(vuint8_t  *)(0xFC044104)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI5              (*(vuint8_t  *)(0xFC044105)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI6              (*(vuint8_t  *)(0xFC044106)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI7              (*(vuint8_t  *)(0xFC044107)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI8              (*(vuint8_t  *)(0xFC044108)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI9              (*(vuint8_t  *)(0xFC044109)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI10             (*(vuint8_t  *)(0xFC04410A)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI11             (*(vuint8_t  *)(0xFC04410B)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI12             (*(vuint8_t  *)(0xFC04410C)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI13             (*(vuint8_t  *)(0xFC04410D)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI14             (*(vuint8_t  *)(0xFC04410E)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI15             (*(vuint8_t  *)(0xFC04410F)) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_DCHPRI(x)            (*(vuint8_t  *)(0xFC044100+((x)*0x001))) /* CH[n] - DMA Channel n Priority Register 0-15 */
#define EDMAC_TCD0_W0              (*(vuint32_t *)(0xFC045000)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD1_W0              (*(vuint32_t *)(0xFC045020)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD2_W0              (*(vuint32_t *)(0xFC045040)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD3_W0              (*(vuint32_t *)(0xFC045060)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD4_W0              (*(vuint32_t *)(0xFC045080)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD5_W0              (*(vuint32_t *)(0xFC0450A0)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD6_W0              (*(vuint32_t *)(0xFC0450C0)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD7_W0              (*(vuint32_t *)(0xFC0450E0)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD8_W0              (*(vuint32_t *)(0xFC045100)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD9_W0              (*(vuint32_t *)(0xFC045120)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD10_W0             (*(vuint32_t *)(0xFC045140)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD11_W0             (*(vuint32_t *)(0xFC045160)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD12_W0             (*(vuint32_t *)(0xFC045180)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD13_W0             (*(vuint32_t *)(0xFC0451A0)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD14_W0             (*(vuint32_t *)(0xFC0451C0)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD15_W0             (*(vuint32_t *)(0xFC0451E0)) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD_W0(x)            (*(vuint32_t *)(0xFC045000+((x)*0x020))) /* Transfer Control Descriptor Word 0 */
#define EDMAC_TCD0_W1              (*(vuint32_t *)(0xFC045004)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD1_W1              (*(vuint32_t *)(0xFC045024)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD2_W1              (*(vuint32_t *)(0xFC045044)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD3_W1              (*(vuint32_t *)(0xFC045064)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD4_W1              (*(vuint32_t *)(0xFC045084)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD5_W1              (*(vuint32_t *)(0xFC0450A4)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD6_W1              (*(vuint32_t *)(0xFC0450C4)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD7_W1              (*(vuint32_t *)(0xFC0450E4)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD8_W1              (*(vuint32_t *)(0xFC045104)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD9_W1              (*(vuint32_t *)(0xFC045124)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD10_W1             (*(vuint32_t *)(0xFC045144)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD11_W1             (*(vuint32_t *)(0xFC045164)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD12_W1             (*(vuint32_t *)(0xFC045184)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD13_W1             (*(vuint32_t *)(0xFC0451A4)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD14_W1             (*(vuint32_t *)(0xFC0451C4)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD15_W1             (*(vuint32_t *)(0xFC0451E4)) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD_W1(x)            (*(vuint32_t *)(0xFC045004+((x)*0x020))) /* Transfer Control Descriptor Word 1 */
#define EDMAC_TCD0_W2              (*(vuint32_t *)(0xFC045008)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD1_W2              (*(vuint32_t *)(0xFC045028)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD2_W2              (*(vuint32_t *)(0xFC045048)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD3_W2              (*(vuint32_t *)(0xFC045068)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD4_W2              (*(vuint32_t *)(0xFC045088)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD5_W2              (*(vuint32_t *)(0xFC0450A8)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD6_W2              (*(vuint32_t *)(0xFC0450C8)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD7_W2              (*(vuint32_t *)(0xFC0450E8)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD8_W2              (*(vuint32_t *)(0xFC045108)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD9_W2              (*(vuint32_t *)(0xFC045128)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD10_W2             (*(vuint32_t *)(0xFC045148)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD11_W2             (*(vuint32_t *)(0xFC045168)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD12_W2             (*(vuint32_t *)(0xFC045188)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD13_W2             (*(vuint32_t *)(0xFC0451A8)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD14_W2             (*(vuint32_t *)(0xFC0451C8)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD15_W2             (*(vuint32_t *)(0xFC0451E8)) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD_W2(x)            (*(vuint32_t *)(0xFC045008+((x)*0x020))) /* Transfer Control Descriptor Word 2 */
#define EDMAC_TCD0_W3              (*(vuint32_t *)(0xFC04500C)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD1_W3              (*(vuint32_t *)(0xFC04502C)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD2_W3              (*(vuint32_t *)(0xFC04504C)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD3_W3              (*(vuint32_t *)(0xFC04506C)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD4_W3              (*(vuint32_t *)(0xFC04508C)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD5_W3              (*(vuint32_t *)(0xFC0450AC)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD6_W3              (*(vuint32_t *)(0xFC0450CC)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD7_W3              (*(vuint32_t *)(0xFC0450EC)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD8_W3              (*(vuint32_t *)(0xFC04510C)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD9_W3              (*(vuint32_t *)(0xFC04512C)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD10_W3             (*(vuint32_t *)(0xFC04514C)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD11_W3             (*(vuint32_t *)(0xFC04516C)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD12_W3             (*(vuint32_t *)(0xFC04518C)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD13_W3             (*(vuint32_t *)(0xFC0451AC)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD14_W3             (*(vuint32_t *)(0xFC0451CC)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD15_W3             (*(vuint32_t *)(0xFC0451EC)) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD_W3(x)            (*(vuint32_t *)(0xFC04500C+((x)*0x020))) /* Transfer Control Descriptor Word 3 */
#define EDMAC_TCD0_W4              (*(vuint32_t *)(0xFC045010)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD1_W4              (*(vuint32_t *)(0xFC045030)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD2_W4              (*(vuint32_t *)(0xFC045050)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD3_W4              (*(vuint32_t *)(0xFC045070)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD4_W4              (*(vuint32_t *)(0xFC045090)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD5_W4              (*(vuint32_t *)(0xFC0450B0)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD6_W4              (*(vuint32_t *)(0xFC0450D0)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD7_W4              (*(vuint32_t *)(0xFC0450F0)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD8_W4              (*(vuint32_t *)(0xFC045110)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD9_W4              (*(vuint32_t *)(0xFC045130)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD10_W4             (*(vuint32_t *)(0xFC045150)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD11_W4             (*(vuint32_t *)(0xFC045170)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD12_W4             (*(vuint32_t *)(0xFC045190)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD13_W4             (*(vuint32_t *)(0xFC0451B0)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD14_W4             (*(vuint32_t *)(0xFC0451D0)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD15_W4             (*(vuint32_t *)(0xFC0451F0)) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD_W4(x)            (*(vuint32_t *)(0xFC045010+((x)*0x020))) /* Transfer Control Descriptor Word 4 */
#define EDMAC_TCD0_W5              (*(vuint32_t *)(0xFC045014)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD1_W5              (*(vuint32_t *)(0xFC045034)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD2_W5              (*(vuint32_t *)(0xFC045054)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD3_W5              (*(vuint32_t *)(0xFC045074)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD4_W5              (*(vuint32_t *)(0xFC045094)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD5_W5              (*(vuint32_t *)(0xFC0450B4)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD6_W5              (*(vuint32_t *)(0xFC0450D4)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD7_W5              (*(vuint32_t *)(0xFC0450F4)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD8_W5              (*(vuint32_t *)(0xFC045114)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD9_W5              (*(vuint32_t *)(0xFC045134)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD10_W5             (*(vuint32_t *)(0xFC045154)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD11_W5             (*(vuint32_t *)(0xFC045174)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD12_W5             (*(vuint32_t *)(0xFC045194)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD13_W5             (*(vuint32_t *)(0xFC0451B4)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD14_W5             (*(vuint32_t *)(0xFC0451D4)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD15_W5             (*(vuint32_t *)(0xFC0451F4)) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD_W5(x)            (*(vuint32_t *)(0xFC045014+((x)*0x020))) /* Transfer Control Descriptor Word 5 */
#define EDMAC_TCD0_W6              (*(vuint32_t *)(0xFC045018)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD1_W6              (*(vuint32_t *)(0xFC045038)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD2_W6              (*(vuint32_t *)(0xFC045058)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD3_W6              (*(vuint32_t *)(0xFC045078)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD4_W6              (*(vuint32_t *)(0xFC045098)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD5_W6              (*(vuint32_t *)(0xFC0450B8)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD6_W6              (*(vuint32_t *)(0xFC0450D8)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD7_W6              (*(vuint32_t *)(0xFC0450F8)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD8_W6              (*(vuint32_t *)(0xFC045118)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD9_W6              (*(vuint32_t *)(0xFC045138)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD10_W6             (*(vuint32_t *)(0xFC045158)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD11_W6             (*(vuint32_t *)(0xFC045178)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD12_W6             (*(vuint32_t *)(0xFC045198)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD13_W6             (*(vuint32_t *)(0xFC0451B8)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD14_W6             (*(vuint32_t *)(0xFC0451D8)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD15_W6             (*(vuint32_t *)(0xFC0451F8)) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD_W6(x)            (*(vuint32_t *)(0xFC045018+((x)*0x020))) /* Transfer Control Descriptor Word 6 */
#define EDMAC_TCD0_W7              (*(vuint32_t *)(0xFC04501C)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD1_W7              (*(vuint32_t *)(0xFC04503C)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD2_W7              (*(vuint32_t *)(0xFC04505C)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD3_W7              (*(vuint32_t *)(0xFC04507C)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD4_W7              (*(vuint32_t *)(0xFC04509C)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD5_W7              (*(vuint32_t *)(0xFC0450BC)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD6_W7              (*(vuint32_t *)(0xFC0450DC)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD7_W7              (*(vuint32_t *)(0xFC0450FC)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD8_W7              (*(vuint32_t *)(0xFC04511C)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD9_W7              (*(vuint32_t *)(0xFC04513C)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD10_W7             (*(vuint32_t *)(0xFC04515C)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD11_W7             (*(vuint32_t *)(0xFC04517C)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD12_W7             (*(vuint32_t *)(0xFC04519C)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD13_W7             (*(vuint32_t *)(0xFC0451BC)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD14_W7             (*(vuint32_t *)(0xFC0451DC)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD15_W7             (*(vuint32_t *)(0xFC0451FC)) /* Transfer Control Descriptor Word 7 */
#define EDMAC_TCD_W7(x)            (*(vuint32_t *)(0xFC04501C+((x)*0x020))) /* Transfer Control Descriptor Word 7 */

/* Bit definitions and macros for EDMAC_CR */
#define EDMAC_EBW                  (0x00000001)   /*  Enable Buffered Writes */
#define EDMAC_EDBG                 (0x00000002)   /*  Enable Debug */
#define EDMAC_ERCA                 (0x00000004)   /*  Enable Round Robin Channel Arbitration */
#define EDMAC_ERGA                 (0x00000008)   /*  Enable Round Robin Group Arbitration */
#define EDMAC_GRP0PRI(x)           (((x)&0x00000003)<<8)    /*  Channel Group 0 Priority */
#define EDMAC_GRP1PRI(x)           (((x)&0x00000003)<<10)   /*  Channel Group 1 Priority */
#define EDMAC_GRP2PRI(x)           (((x)&0x00000003)<<12)   /*  Channel Group 2 Priority  */
#define EDMAC_GRP3PRI(x)           (((x)&0x00000003)<<14)   /*  Channel Group 3 Priority */

/* Bit definitions and macros for EDMAC_ES */
#define EDMAC_DBE                  (0x00000001)   /*  Destination Bus Error */
#define EDMAC_SBE                  (0x00000002)   /*  Source Bus Error */
#define EDMAC_SGE                  (0x00000004)   /*  Scatter/Gather Config Error */
#define EDMAC_NCE                  (0x00000008)   /*  Nbytes/Citer Config Register */
#define EDMAC_DOE                  (0x00000010)   /*  Destination Offset Error */
#define EDMAC_DAE                  (0x00000020)   /*  Destination Address Error */
#define EDMAC_SOE                  (0x00000040)   /*  Source Offset Error */
#define EDMAC_SAE                  (0x00000080)   /*  Source Address Error */
#define EDMAC_ERRCHAN(x)           (((x)&0x0000003F)<<8)    /*  Error Channel Number */
#define EDMAC_CPE                  (0x00004000)   /*  Channel Priority Error */
#define EDMAC_GPE                  (0x00008000)   /*  Group Priority Error */
#define EDMAC_VLD                  (0x80000000)   /*  Logical OR of all ERR bits */

/* Bit definitions and macros for EDMAC_ERQ */
#define EDMAC_ERQ0                 (0x0001)       /*  Enable DMA Request 0 */
#define EDMAC_ERQ1                 (0x0002)       /*  Enable DMA Request 1 */
#define EDMAC_ERQ2                 (0x0004)       /*  Enable DMA Request 2 */
#define EDMAC_ERQ3                 (0x0008)       /*  Enable DMA Request 3 */
#define EDMAC_ERQ4                 (0x0010)       /*  Enable DMA Request 4 */
#define EDMAC_ERQ5                 (0x0020)       /*  Enable DMA Request 5 */
#define EDMAC_ERQ6                 (0x0040)       /*  Enable DMA Request 6 */
#define EDMAC_ERQ7                 (0x0080)       /*  Enable DMA Request 7 */
#define EDMAC_ERQ8                 (0x0100)       /*  Enable DMA Request 8 */
#define EDMAC_ERQ9                 (0x0200)       /*  Enable DMA Request 9 */
#define EDMAC_ERQ10                (0x0400)       /*  Enable DMA Request 10 */
#define EDMAC_ERQ11                (0x0800)       /*  Enable DMA Request 11 */
#define EDMAC_ERQ12                (0x1000)       /*  Enable DMA Request 12 */
#define EDMAC_ERQ13                (0x2000)       /*  Enable DMA Request 13 */
#define EDMAC_ERQ14                (0x4000)       /*  Enable DMA Request 14 */
#define EDMAC_ERQ15                (0x8000)       /*  Enable DMA Request 15 */

/* Bit definitions and macros for EDMAC_EEI */
#define EDMAC_EEI0                 (0x0001)       /*  Enable Error Interrupt 0 */
#define EDMAC_EEI1                 (0x0002)       /*  Enable Error Interrupt 1 */
#define EDMAC_EEI2                 (0x0004)       /*  Enable Error Interrupt 2 */
#define EDMAC_EEI3                 (0x0008)       /*  Enable Error Interrupt 3 */
#define EDMAC_EEI4                 (0x0010)       /*  Enable Error Interrupt 4 */
#define EDMAC_EEI5                 (0x0020)       /*  Enable Error Interrupt 5 */
#define EDMAC_EEI6                 (0x0040)       /*  Enable Error Interrupt 6 */
#define EDMAC_EEI7                 (0x0080)       /*  Enable Error Interrupt 7 */
#define EDMAC_EEI8                 (0x0100)       /*  Enable Error Interrupt 8 */
#define EDMAC_EEI9                 (0x0200)       /*  Enable Error Interrupt 9 */
#define EDMAC_EEI10                (0x0400)       /*  Enable Error Interrupt 10 */
#define EDMAC_EEI11                (0x0800)       /*  Enable Error Interrupt 11 */
#define EDMAC_EEI12                (0x1000)       /*  Enable Error Interrupt 12 */
#define EDMAC_EEI13                (0x2000)       /*  Enable Error Interrupt 13 */
#define EDMAC_EEI14                (0x4000)       /*  Enable Error Interrupt 14 */
#define EDMAC_EEI15                (0x8000)       /*  Enable Error Interrupt 15 */

/* Bit definitions and macros for EDMAC_SERQ */
#define EDMAC_SRQ(x)               (((x)&0x0F)<<0)  /*  Set Enable Requests */
#define EDMAC_SAER                 (0x40)         /*  Set All Enable Requests */

/* Bit definitions and macros for EDMAC_CERQ */
#define EDMAC_CRQ(x)               (((x)&0x0F)<<0)  /*  Clear Enable Requests */
#define EDMAC_CAER                 (0x40)         /*  Clear All Enable Requests */

/* Bit definitions and macros for EDMAC_SEEI */
#define EDMAC_SEI(x)               (((x)&0x0F)<<0)  /*  Set Enable Error Interrupt */
#define EDMAC_SAEE                 (0x40)         /*  Set All Enable Error Interrupts */

/* Bit definitions and macros for EDMAC_CEEI */
#define EDMAC_CEI(x)               (((x)&0x0F)<<0)  /*  Clear Enable Error Interrupt */
#define EDMAC_CAEE                 (0x40)         /*  Clear All Enable Error Interrupts */

/* Bit definitions and macros for EDMAC_CINT */
#define EDMAC_CIR(x)               (((x)&0x0F)<<0)  /*  Clear Interrupt Request */
#define EDMAC_CAIR                 (0x40)         /*  Clear All Interrupt Requests */

/* Bit definitions and macros for EDMAC_CERR */
#define EDMAC_CER(x)               (((x)&0x0F)<<0)  /*  Clear Error Indicator */
#define EDMAC_CAER                 (0x40)         /*  Clear All Error Indicators */

/* Bit definitions and macros for EDMAC_SSRT */
#define EDMAC_SST(x)               (((x)&0x0F)<<0)  /*  Set START Bit */
#define EDMAC_SAST                 (0x40)         /*  Set all START Bits */

/* Bit definitions and macros for EDMAC_CDNE */
#define EDMAC_CDN(x)               (((x)&0x0F)<<0)  /*  Clear DONE Status Bit */
#define EDMAC_CADN                 (0x40)         /*  Clear All DONE Status Bits */

/* Bit definitions and macros for EDMAC_INT */
#define EDMAC_INTR0                (0x0001)       /*  Interrupt Request 0 */
#define EDMAC_INTR1                (0x0002)       /*  Interrupt Request 1 */
#define EDMAC_INTR2                (0x0004)       /*  Interrupt Request 2 */
#define EDMAC_INTR3                (0x0008)       /*  Interrupt Request 3 */
#define EDMAC_INTR4                (0x0010)       /*  Interrupt Request 4 */
#define EDMAC_INTR5                (0x0020)       /*  Interrupt Request 5 */
#define EDMAC_INTR6                (0x0040)       /*  Interrupt Request 6 */
#define EDMAC_INTR7                (0x0080)       /*  Interrupt Request 7 */
#define EDMAC_INTR8                (0x0100)       /*  Interrupt Request 8 */
#define EDMAC_INTR9                (0x0200)       /*  Interrupt Request 9 */
#define EDMAC_INTR10               (0x0400)       /*  Interrupt Request 10 */
#define EDMAC_INTR11               (0x0800)       /*  Interrupt Request 11 */
#define EDMAC_INTR12               (0x1000)       /*  Interrupt Request 12 */
#define EDMAC_INTR13               (0x2000)       /*  Interrupt Request 13 */
#define EDMAC_INTR14               (0x4000)       /*  Interrupt Request 14 */
#define EDMAC_INTR15               (0x8000)       /*  Interrupt Request 15 */

/* Bit definitions and macros for EDMAC_ERR */
#define EDMAC_DERR0                (0x0001)       /*  DMA Error 0 */
#define EDMAC_DERR1                (0x0002)       /*  DMA Error 1 */
#define EDMAC_DERR2                (0x0004)       /*  DMA Error 2 */
#define EDMAC_DERR3                (0x0008)       /*  DMA Error 3 */
#define EDMAC_DERR4                (0x0010)       /*  DMA Error 4 */
#define EDMAC_DERR5                (0x0020)       /*  DMA Error 5 */
#define EDMAC_DERR6                (0x0040)       /*  DMA Error 6 */
#define EDMAC_DERR7                (0x0080)       /*  DMA Error 7 */
#define EDMAC_DERR8                (0x0100)       /*  DMA Error 8 */
#define EDMAC_DERR9                (0x0200)       /*  DMA Error 9 */
#define EDMAC_DERR10               (0x0400)       /*  DMA Error 10 */
#define EDMAC_DERR11               (0x0800)       /*  DMA Error 11 */
#define EDMAC_DERR12               (0x1000)       /*  DMA Error 12 */
#define EDMAC_DERR13               (0x2000)       /*  DMA Error 13 */
#define EDMAC_DERR14               (0x4000)       /*  DMA Error 14 */
#define EDMAC_DERR15               (0x8000)       /*  DMA Error 15 */

/* Bit definitions and macros for EDMAC_DCHPRIn */
#define EDMAC_CHPRI(x)             (((x)&0x0F)<<0)  /*  Channel n Arbitration Priority */
#define EDMAC_GRPPRI(x)            (((x)&0x03)<<4)  /*  Channel n Current Group Priority */
#define EDMAC_ECP                  (0x80)         /*  Enable Channel Preemption */

/* Bit definitions and macros for EDMAC_TCDn_W0 */
#define EDMAC_SADDR(x)             (((x)&0xFFFFFFFF)<<0)    /*  Source Address */

/* Bit definitions and macros for EDMAC_TCDn_W1 */
#define EDMAC_SOFF(x)              (((x)&0x0000FFFF)<<0)    /*  Source Address Signed Offset */
#define EDMAC_DSIZE(x)             (((x)&0x00000007)<<16)   /*  Destination Data Transfer Size */
#define EDMAC_DMOD(x)              (((x)&0x0000001F)<<19)   /*  Destination Address Modulo */
#define EDMAC_SSIZE(x)             (((x)&0x00000007)<<24)   /*  Source Data Transfer Size */
#define EDMAC_SMOD(x)              (((x)&0x0000001F)<<27)   /*  Source Address Modulo */

/* Bit definitions and macros for EDMAC_TCDn_W2 */
#define EDMAC_NBYTES(x)            (((x)&0xFFFFFFFF)<<0)    /*  Inner "minor" byte transfer count */

/* Bit definitions and macros for EDMAC_TCDn_W3 */
#define EDMAC_SLAST(x)             (((x)&0xFFFFFFFF)<<0)    /*  Last source address adjustment */

/* Bit definitions and macros for EDMAC_TCDn_W4 */
#define EDMAC_DADDR(x)             (((x)&0xFFFFFFFF)<<0)    /*  Destination Address */

/* Bit definitions and macros for EDMAC_TCDn_W5 */
#define EDMAC_DOFF(x)              (((x)&0x0000FFFF)<<0)    /*  Destination address signed offset */
#define EDMAC_CITER(x)             (((x)&0x00007FFF)<<16)   /*  Current "major" iteration count */
#define EDMAC_CITER_E_LINK         (0x80000000)   /*  Enab ch.-to-ch. linking @ minor loop complt */
#define EDMAC_CITER_LINKCH(x)      (((x)&0x0000003F)<<25)   /*  Bitfield: Minor loop complete link channel */

/* Bit definitions and macros for EDMAC_TCDn_W6 */
#define EDMAC_DLAST(x)             (((x)&0xFFFFFFFF)<<0)    /*  Last destination address adjustment */

/* Bit definitions and macros for EDMAC_TCDn_W7 */
#define EDMAC_START                (0x00000001)   /*  Channel start */
#define EDMAC_INT_MAJ              (0x00000002)   /*  Enable int when maj iteration completes */
#define EDMAC_INT_HALF             (0x00000004)   /*  Enable int when maj ctr is half complete */
#define EDMAC_D_REQ                (0x00000008)   /*  Disable request */
#define EDMAC_E_SG                 (0x00000010)   /*  Enable scatter/gather processing */
#define EDMAC_MAJOR_E_LINK         (0x00000020)   /*  Enab ch.-to-ch. linking @ major loop compl */
#define EDMAC_ACTIVE               (0x00000040)   /*  Channel active */
#define EDMAC_DONE                 (0x00000080)   /*  Channel done */
#define EDMAC_MAJOR_LINKCH(x)      (((x)&0x0000003F)<<8)    /*  Link channel number */
#define EDMAC_BWC(x)               (((x)&0x00000003)<<14)   /*  Bandwidth control */
#define EDMAC_BITER(x)             (((x)&0x00007FFF)<<16)   /*  Beginning "major" iteration count */
#define EDMAC_BITER_E_LINK         (0x80000000)   /*  Enable channel-to-channel linking on minor loop complete */
#define EDMAC_BITER_LINKCH(x)      (((x)&0x0000003F)<<25)   /*  Bitfield: Beginning minor loop complete link channel */

/*********************************************************************
*
* EMIOS Module (EMIOS)
*
*********************************************************************/

/* Register read/write macros */
#define EMIOS_MCR                  (*(vuint32_t *)(0xFC0DC000)) /* MCR - Module Configuration Register */
#define EMIOS_GFLAG                (*(vuint32_t *)(0xFC0DC004)) /* GFLAG - Global FLAG Register */
#define EMIOS_OUDIS                (*(vuint32_t *)(0xFC0DC008)) /* OUDIS - Output Update Disable Register */
#define EMIOS_UCDIS                (*(vuint32_t *)(0xFC0DC00C)) /* UCDIS - Disable Channel Register */
#define EMIOS_CHA0                 (*(vuint32_t *)(0xFC0DC020)) /* A - A Register */
#define EMIOS_CHA1                 (*(vuint32_t *)(0xFC0DC040)) /* A - A Register */
#define EMIOS_CHA2                 (*(vuint32_t *)(0xFC0DC060)) /* A - A Register */
#define EMIOS_CHA3                 (*(vuint32_t *)(0xFC0DC080)) /* A - A Register */
#define EMIOS_CHA4                 (*(vuint32_t *)(0xFC0DC0A0)) /* A - A Register */
#define EMIOS_CHA5                 (*(vuint32_t *)(0xFC0DC0C0)) /* A - A Register */
#define EMIOS_CHA6                 (*(vuint32_t *)(0xFC0DC0E0)) /* A - A Register */
#define EMIOS_CHA7                 (*(vuint32_t *)(0xFC0DC100)) /* A - A Register */
#define EMIOS_CHA8                 (*(vuint32_t *)(0xFC0DC120)) /* A - A Register */
#define EMIOS_CHA9                 (*(vuint32_t *)(0xFC0DC140)) /* A - A Register */
#define EMIOS_CHA10                (*(vuint32_t *)(0xFC0DC160)) /* A - A Register */
#define EMIOS_CHA11                (*(vuint32_t *)(0xFC0DC180)) /* A - A Register */
#define EMIOS_CHA12                (*(vuint32_t *)(0xFC0DC1A0)) /* A - A Register */
#define EMIOS_CHA13                (*(vuint32_t *)(0xFC0DC1C0)) /* A - A Register */
#define EMIOS_CHA14                (*(vuint32_t *)(0xFC0DC1E0)) /* A - A Register */
#define EMIOS_CHA15                (*(vuint32_t *)(0xFC0DC200)) /* A - A Register */
#define EMIOS_CHA(x)               (*(vuint32_t *)(0xFC0DC020+((x)*0x020))) /* A - A Register */
#define EMIOS_CHB0                 (*(vuint32_t *)(0xFC0DC024)) /* B - B Register */
#define EMIOS_CHB1                 (*(vuint32_t *)(0xFC0DC044)) /* B - B Register */
#define EMIOS_CHB2                 (*(vuint32_t *)(0xFC0DC064)) /* B - B Register */
#define EMIOS_CHB3                 (*(vuint32_t *)(0xFC0DC084)) /* B - B Register */
#define EMIOS_CHB4                 (*(vuint32_t *)(0xFC0DC0A4)) /* B - B Register */
#define EMIOS_CHB5                 (*(vuint32_t *)(0xFC0DC0C4)) /* B - B Register */
#define EMIOS_CHB6                 (*(vuint32_t *)(0xFC0DC0E4)) /* B - B Register */
#define EMIOS_CHB7                 (*(vuint32_t *)(0xFC0DC104)) /* B - B Register */
#define EMIOS_CHB8                 (*(vuint32_t *)(0xFC0DC124)) /* B - B Register */
#define EMIOS_CHB9                 (*(vuint32_t *)(0xFC0DC144)) /* B - B Register */
#define EMIOS_CHB10                (*(vuint32_t *)(0xFC0DC164)) /* B - B Register */
#define EMIOS_CHB11                (*(vuint32_t *)(0xFC0DC184)) /* B - B Register */
#define EMIOS_CHB12                (*(vuint32_t *)(0xFC0DC1A4)) /* B - B Register */
#define EMIOS_CHB13                (*(vuint32_t *)(0xFC0DC1C4)) /* B - B Register */
#define EMIOS_CHB14                (*(vuint32_t *)(0xFC0DC1E4)) /* B - B Register */
#define EMIOS_CHB15                (*(vuint32_t *)(0xFC0DC204)) /* B - B Register */
#define EMIOS_CHB(x)               (*(vuint32_t *)(0xFC0DC024+((x)*0x020))) /* B - B Register */
#define EMIOS_CHCNT0               (*(vuint32_t *)(0xFC0DC028)) /* CNT - Counter Register */
#define EMIOS_CHCNT1               (*(vuint32_t *)(0xFC0DC048)) /* CNT - Counter Register */
#define EMIOS_CHCNT2               (*(vuint32_t *)(0xFC0DC068)) /* CNT - Counter Register */
#define EMIOS_CHCNT3               (*(vuint32_t *)(0xFC0DC088)) /* CNT - Counter Register */
#define EMIOS_CHCNT4               (*(vuint32_t *)(0xFC0DC0A8)) /* CNT - Counter Register */
#define EMIOS_CHCNT5               (*(vuint32_t *)(0xFC0DC0C8)) /* CNT - Counter Register */
#define EMIOS_CHCNT6               (*(vuint32_t *)(0xFC0DC0E8)) /* CNT - Counter Register */
#define EMIOS_CHCNT7               (*(vuint32_t *)(0xFC0DC108)) /* CNT - Counter Register */
#define EMIOS_CHCNT8               (*(vuint32_t *)(0xFC0DC128)) /* CNT - Counter Register */
#define EMIOS_CHCNT9               (*(vuint32_t *)(0xFC0DC148)) /* CNT - Counter Register */
#define EMIOS_CHCNT10              (*(vuint32_t *)(0xFC0DC168)) /* CNT - Counter Register */
#define EMIOS_CHCNT11              (*(vuint32_t *)(0xFC0DC188)) /* CNT - Counter Register */
#define EMIOS_CHCNT12              (*(vuint32_t *)(0xFC0DC1A8)) /* CNT - Counter Register */
#define EMIOS_CHCNT13              (*(vuint32_t *)(0xFC0DC1C8)) /* CNT - Counter Register */
#define EMIOS_CHCNT14              (*(vuint32_t *)(0xFC0DC1E8)) /* CNT - Counter Register */
#define EMIOS_CHCNT15              (*(vuint32_t *)(0xFC0DC208)) /* CNT - Counter Register */
#define EMIOS_CHCNT(x)             (*(vuint32_t *)(0xFC0DC028+((x)*0x020))) /* CNT - Counter Register */
#define EMIOS_CHC0                 (*(vuint32_t *)(0xFC0DC02C)) /* C - Control Register */
#define EMIOS_CHC1                 (*(vuint32_t *)(0xFC0DC04C)) /* C - Control Register */
#define EMIOS_CHC2                 (*(vuint32_t *)(0xFC0DC06C)) /* C - Control Register */
#define EMIOS_CHC3                 (*(vuint32_t *)(0xFC0DC08C)) /* C - Control Register */
#define EMIOS_CHC4                 (*(vuint32_t *)(0xFC0DC0AC)) /* C - Control Register */
#define EMIOS_CHC5                 (*(vuint32_t *)(0xFC0DC0CC)) /* C - Control Register */
#define EMIOS_CHC6                 (*(vuint32_t *)(0xFC0DC0EC)) /* C - Control Register */
#define EMIOS_CHC7                 (*(vuint32_t *)(0xFC0DC10C)) /* C - Control Register */
#define EMIOS_CHC8                 (*(vuint32_t *)(0xFC0DC12C)) /* C - Control Register */
#define EMIOS_CHC9                 (*(vuint32_t *)(0xFC0DC14C)) /* C - Control Register */
#define EMIOS_CHC10                (*(vuint32_t *)(0xFC0DC16C)) /* C - Control Register */
#define EMIOS_CHC11                (*(vuint32_t *)(0xFC0DC18C)) /* C - Control Register */
#define EMIOS_CHC12                (*(vuint32_t *)(0xFC0DC1AC)) /* C - Control Register */
#define EMIOS_CHC13                (*(vuint32_t *)(0xFC0DC1CC)) /* C - Control Register */
#define EMIOS_CHC14                (*(vuint32_t *)(0xFC0DC1EC)) /* C - Control Register */
#define EMIOS_CHC15                (*(vuint32_t *)(0xFC0DC20C)) /* C - Control Register */
#define EMIOS_CHC(x)               (*(vuint32_t *)(0xFC0DC02C+((x)*0x020))) /* C - Control Register */
#define EMIOS_CHS0                 (*(vuint32_t *)(0xFC0DC030)) /* S - Status Register */
#define EMIOS_CHS1                 (*(vuint32_t *)(0xFC0DC050)) /* S - Status Register */
#define EMIOS_CHS2                 (*(vuint32_t *)(0xFC0DC070)) /* S - Status Register */
#define EMIOS_CHS3                 (*(vuint32_t *)(0xFC0DC090)) /* S - Status Register */
#define EMIOS_CHS4                 (*(vuint32_t *)(0xFC0DC0B0)) /* S - Status Register */
#define EMIOS_CHS5                 (*(vuint32_t *)(0xFC0DC0D0)) /* S - Status Register */
#define EMIOS_CHS6                 (*(vuint32_t *)(0xFC0DC0F0)) /* S - Status Register */
#define EMIOS_CHS7                 (*(vuint32_t *)(0xFC0DC110)) /* S - Status Register */
#define EMIOS_CHS8                 (*(vuint32_t *)(0xFC0DC130)) /* S - Status Register */
#define EMIOS_CHS9                 (*(vuint32_t *)(0xFC0DC150)) /* S - Status Register */
#define EMIOS_CHS10                (*(vuint32_t *)(0xFC0DC170)) /* S - Status Register */
#define EMIOS_CHS11                (*(vuint32_t *)(0xFC0DC190)) /* S - Status Register */
#define EMIOS_CHS12                (*(vuint32_t *)(0xFC0DC1B0)) /* S - Status Register */
#define EMIOS_CHS13                (*(vuint32_t *)(0xFC0DC1D0)) /* S - Status Register */
#define EMIOS_CHS14                (*(vuint32_t *)(0xFC0DC1F0)) /* S - Status Register */
#define EMIOS_CHS15                (*(vuint32_t *)(0xFC0DC210)) /* S - Status Register */
#define EMIOS_CHS(x)               (*(vuint32_t *)(0xFC0DC030+((x)*0x020))) /* S - Status Register */

/* Bit definitions and macros for EMIOS_MCR */
#define EMIOS_GPRE(x)              (((x)&0x000000FF)<<8)    /*  Global Prescaler */
#define EMIOS_SRV(x)               (((x)&0x0000000F)<<16)   /*  Server Time Slot */
#define EMIOS_GPREN                (0x04000000)   /*  Global Prescaler Enable */
#define EMIOS_ETB                  (0x08000000)   /*  External Time Base */
#define EMIOS_GTBE                 (0x10000000)   /*  Global Time Base Enable */
#define EMIOS_FRZ                  (0x20000000)   /*  Freeze */
#define EMIOS_MDIS                 (0x40000000)   /*  Module Disable */
#define EMIOS_DOZEEN               (0x80000000)   /*  Doze Enable */

/* Bit definitions and macros for EMIOS_GFLAG */
#define EMIOS_F0                   (0x00000001)   /*  Ch  0 Flag */
#define EMIOS_F1                   (0x00000002)   /*  Ch  1 Flag */
#define EMIOS_F2                   (0x00000004)   /*  Ch  2 Flag */
#define EMIOS_F3                   (0x00000008)   /*  Ch  3 Flag */
#define EMIOS_F4                   (0x00000010)   /*  Ch  4 Flag */
#define EMIOS_F5                   (0x00000020)   /*  Ch  5 Flag */
#define EMIOS_F6                   (0x00000040)   /*  Ch  6 Flag */
#define EMIOS_F7                   (0x00000080)   /*  Ch  7 Flag */
#define EMIOS_F8                   (0x00000100)   /*  Ch  8 Flag */
#define EMIOS_F9                   (0x00000200)   /*  Ch  9 Flag */
#define EMIOS_F10                  (0x00000400)   /*  Ch 10 Flag */
#define EMIOS_F11                  (0x00000800)   /*  Ch 11 Flag */
#define EMIOS_F12                  (0x00001000)   /*  Ch 12 Flag */
#define EMIOS_F13                  (0x00002000)   /*  Ch 13 Flag */
#define EMIOS_F14                  (0x00004000)   /*  Ch 14 Flag */
#define EMIOS_F15                  (0x00008000)   /*  Ch 15 Flag */

/* Bit definitions and macros for EMIOS_OUDIS */
#define EMIOS_OU0                  (0x00000001)   /*  Ch  0 Output Update Disable */
#define EMIOS_OU1                  (0x00000002)   /*  Ch  1 Output Update Disable */
#define EMIOS_OU2                  (0x00000004)   /*  Ch  2 Output Update Disable */
#define EMIOS_OU3                  (0x00000008)   /*  Ch  3 Output Update Disable */
#define EMIOS_OU4                  (0x00000010)   /*  Ch  4 Output Update Disable */
#define EMIOS_OU5                  (0x00000020)   /*  Ch  5 Output Update Disable */
#define EMIOS_OU6                  (0x00000040)   /*  Ch  6 Output Update Disable */
#define EMIOS_OU7                  (0x00000080)   /*  Ch  7 Output Update Disable */
#define EMIOS_OU8                  (0x00000100)   /*  Ch  8 Output Update Disable */
#define EMIOS_OU9                  (0x00000200)   /*  Ch  9 Output Update Disable */
#define EMIOS_OU10                 (0x00000400)   /*  Ch 10 Output Update Disable */
#define EMIOS_OU11                 (0x00000800)   /*  Ch 11 Output Update Disable */
#define EMIOS_OU12                 (0x00001000)   /*  Ch 12 Output Update Disable */
#define EMIOS_OU13                 (0x00002000)   /*  Ch 13 Output Update Disable */
#define EMIOS_OU14                 (0x00004000)   /*  Ch 14 Output Update Disable */
#define EMIOS_OU15                 (0x00008000)   /*  Ch 15 Output Update Disable */

/* Bit definitions and macros for EMIOS_UCDIS */
#define EMIOS_UCDIS0               (0x00000001)   /*  Disable Ch  0 */
#define EMIOS_UCDIS1               (0x00000002)   /*  Disable Ch  1 */
#define EMIOS_UCDIS2               (0x00000004)   /*  Disable Ch  2 */
#define EMIOS_UCDIS3               (0x00000008)   /*  Disable Ch  3 */
#define EMIOS_UCDIS4               (0x00000010)   /*  Disable Ch  4 */
#define EMIOS_UCDIS5               (0x00000020)   /*  Disable Ch  5 */
#define EMIOS_UCDIS6               (0x00000040)   /*  Disable Ch  6 */
#define EMIOS_UCDIS7               (0x00000080)   /*  Disable Ch  7 */
#define EMIOS_UCDIS8               (0x00000100)   /*  Disable Ch  8 */
#define EMIOS_UCDIS9               (0x00000200)   /*  Disable Ch  9 */
#define EMIOS_UCDIS10              (0x00000400)   /*  Disable Ch 10 */
#define EMIOS_UCDIS11              (0x00000800)   /*  Disable Ch 11 */
#define EMIOS_UCDIS12              (0x00001000)   /*  Disable Ch 12 */
#define EMIOS_UCDIS13              (0x00002000)   /*  Disable Ch 13 */
#define EMIOS_UCDIS14              (0x00004000)   /*  Disable Ch 14 */
#define EMIOS_UCDIS15              (0x00008000)   /*  Disable Ch 15 */

/* Bit definitions and macros for EMIOS_CHAn */
#define EMIOS_A(x)                 (((x)&0x0000FFFF)<<0)    /*  A[15:0] */

/* Bit definitions and macros for EMIOS_CHBn */
#define EMIOS_B(x)                 (((x)&0x0000FFFF)<<0)    /*  B[15:0] */

/* Bit definitions and macros for EMIOS_CHCNTn */
#define EMIOS_C(x)                 (((x)&0x0000FFFF)<<0)    /*  C[15:0] */

/* Bit definitions and macros for EMIOS_CHCn */
#define EMIOS_MODE(x)              (((x)&0x0000007F)<<0)    /*  Mode selection */
#define EMIOS_EDPOL                (0x00000080)   /*  Edge Polarity */
#define EMIOS_EDSEL                (0x00000100)   /*  Edge Selection */
#define EMIOS_BSL(x)               (((x)&0x00000003)<<9)    /*  Bus Select */
#define EMIOS_FORCMB               (0x00001000)   /*  Force Match B */
#define EMIOS_FORCMA               (0x00002000)   /*  Force Match A */
#define EMIOS_FEN                  (0x00020000)   /*  FLAG Enable */
#define EMIOS_FCK                  (0x00040000)   /*  Filter Clock select */
#define EMIOS_IF(x)                (((x)&0x0000000F)<<19)   /*  Input Filter */
#define EMIOS_DMA                  (0x01000000)   /*  Direct Memory Access */
#define EMIOS_UCPREN               (0x02000000)   /*  Prescaler Enable */
#define EMIOS_UCPRE(x)             (((x)&0x00000003)<<26)   /*  Prescaler */
#define EMIOS_ODISSL(x)            (((x)&0x00000003)<<28)   /*  Output Disable select */
#define EMIOS_ODIS                 (0x40000000)   /*  Output Disable */
#define EMIOS_FREN                 (0x80000000)   /*  Freeze Enable */

/* Bit definitions and macros for EMIOS_CHSn */
#define EMIOS_FLAG                 (0x00000001)   /*  Flag (R) / Flag Clear (W) */
#define EMIOS_UCOUT                (0x00000002)   /*  Unified Channel Output pin */
#define EMIOS_UCIN                 (0x00000004)   /*  Unified Channel Input pin */
#define EMIOS_OVFL                 (0x00008000)   /*  Overflow (R) / Overflow Clear (W) */
#define EMIOS_OVR                  (0x80000000)   /*  Overrun (R) / Overrun Clear (W) */

/*********************************************************************
*
* ESCI Module (ESCI)
*
*********************************************************************/

/* Register read/write macros */
#define ESCI0_SCIBD                (*(vuint16_t *)(0xFC0C4000)) /* SCIBD - Baud Rate Register */
#define ESCI0_SCICR1               (*(vuint8_t  *)(0xFC0C4002)) /* SCICR1 - Control Register 1 */
#define ESCI0_SCICR2               (*(vuint8_t  *)(0xFC0C4003)) /* SCICR2 - Control Register 2 */
#define ESCI0_SCICR3               (*(vuint8_t  *)(0xFC0C4004)) /* SCICR3 - Control Register 3 */
#define ESCI0_SCICR4               (*(vuint8_t  *)(0xFC0C4005)) /* SCICR4 - Control Register 4 */
#define ESCI0_SCIDRH               (*(vuint8_t  *)(0xFC0C4006)) /* SCIDRH - Data Register High */
#define ESCI0_SCIDRL               (*(vuint8_t  *)(0xFC0C4007)) /* SCIDRL - Data Register Low */
#define ESCI0_SCISR1               (*(vuint8_t  *)(0xFC0C4008)) /* SCISR1 - Status Register 1 */
#define ESCI0_SCISR2               (*(vuint8_t  *)(0xFC0C4009)) /* SCISR2 - Status Register 2 */
#define ESCI0_LINSTAT1             (*(vuint8_t  *)(0xFC0C400A)) /* LINSTAT1 - LIN Status Register 1 */
#define ESCI0_LINSTAT2             (*(vuint8_t  *)(0xFC0C400B)) /* LINSTAT2 - LIN Status Register 2 */
#define ESCI0_LINCTRL1             (*(vuint8_t  *)(0xFC0C400C)) /* LINCTRL1 - LIN Control Register 1 */
#define ESCI0_LINCTRL2             (*(vuint8_t  *)(0xFC0C400D)) /* LINCTRL2 - LIN Control Register 2 */
#define ESCI0_LINCTRL3             (*(vuint8_t  *)(0xFC0C400E)) /* LINCTRL3 - LIN Control Register 3 */
#define ESCI0_LINTX                (*(vuint8_t  *)(0xFC0C4010)) /* LINTX - LIN TX Register */
#define ESCI0_LINRX                (*(vuint8_t  *)(0xFC0C4014)) /* LINRX - LIN RX Register */
#define ESCI0_LINCRCP1             (*(vuint8_t  *)(0xFC0C4018)) /* LINCRCP1 - LIN CRC Polynomial Register 1 */
#define ESCI0_LINCRCP2             (*(vuint8_t  *)(0xFC0C4019)) /* LINCRCP2 - LIN CRC Polynomial Register 2 */
#define ESCI1_SCIBD                (*(vuint16_t *)(0xFC0C8000)) /* SCIBD - Baud Rate Register */
#define ESCI1_SCICR1               (*(vuint8_t  *)(0xFC0C8002)) /* SCICR1 - Control Register 1 */
#define ESCI1_SCICR2               (*(vuint8_t  *)(0xFC0C8003)) /* SCICR2 - Control Register 2 */
#define ESCI1_SCICR3               (*(vuint8_t  *)(0xFC0C8004)) /* SCICR3 - Control Register 3 */
#define ESCI1_SCICR4               (*(vuint8_t  *)(0xFC0C8005)) /* SCICR4 - Control Register 4 */
#define ESCI1_SCIDRH               (*(vuint8_t  *)(0xFC0C8006)) /* SCIDRH - Data Register High */
#define ESCI1_SCIDRL               (*(vuint8_t  *)(0xFC0C8007)) /* SCIDRL - Data Register Low */
#define ESCI1_SCISR1               (*(vuint8_t  *)(0xFC0C8008)) /* SCISR1 - Status Register 1 */
#define ESCI1_SCISR2               (*(vuint8_t  *)(0xFC0C8009)) /* SCISR2 - Status Register 2 */
#define ESCI1_LINSTAT1             (*(vuint8_t  *)(0xFC0C800A)) /* LINSTAT1 - LIN Status Register 1 */
#define ESCI1_LINSTAT2             (*(vuint8_t  *)(0xFC0C800B)) /* LINSTAT2 - LIN Status Register 2 */
#define ESCI1_LINCTRL1             (*(vuint8_t  *)(0xFC0C800C)) /* LINCTRL1 - LIN Control Register 1 */
#define ESCI1_LINCTRL2             (*(vuint8_t  *)(0xFC0C800D)) /* LINCTRL2 - LIN Control Register 2 */
#define ESCI1_LINCTRL3             (*(vuint8_t  *)(0xFC0C800E)) /* LINCTRL3 - LIN Control Register 3 */
#define ESCI1_LINTX                (*(vuint8_t  *)(0xFC0C8010)) /* LINTX - LIN TX Register */
#define ESCI1_LINRX                (*(vuint8_t  *)(0xFC0C8014)) /* LINRX - LIN RX Register */
#define ESCI1_LINCRCP1             (*(vuint8_t  *)(0xFC0C8018)) /* LINCRCP1 - LIN CRC Polynomial Register 1 */
#define ESCI1_LINCRCP2             (*(vuint8_t  *)(0xFC0C8019)) /* LINCRCP2 - LIN CRC Polynomial Register 2 */
#define ESCI2_SCIBD                (*(vuint16_t *)(0xFC0CC000)) /* SCIBD - Baud Rate Register */
#define ESCI2_SCICR1               (*(vuint8_t  *)(0xFC0CC002)) /* SCICR1 - Control Register 1 */
#define ESCI2_SCICR2               (*(vuint8_t  *)(0xFC0CC003)) /* SCICR2 - Control Register 2 */
#define ESCI2_SCICR3               (*(vuint8_t  *)(0xFC0CC004)) /* SCICR3 - Control Register 3 */
#define ESCI2_SCICR4               (*(vuint8_t  *)(0xFC0CC005)) /* SCICR4 - Control Register 4 */
#define ESCI2_SCIDRH               (*(vuint8_t  *)(0xFC0CC006)) /* SCIDRH - Data Register High */
#define ESCI2_SCIDRL               (*(vuint8_t  *)(0xFC0CC007)) /* SCIDRL - Data Register Low */
#define ESCI2_SCISR1               (*(vuint8_t  *)(0xFC0CC008)) /* SCISR1 - Status Register 1 */
#define ESCI2_SCISR2               (*(vuint8_t  *)(0xFC0CC009)) /* SCISR2 - Status Register 2 */
#define ESCI2_LINSTAT1             (*(vuint8_t  *)(0xFC0CC00A)) /* LINSTAT1 - LIN Status Register 1 */
#define ESCI2_LINSTAT2             (*(vuint8_t  *)(0xFC0CC00B)) /* LINSTAT2 - LIN Status Register 2 */
#define ESCI2_LINCTRL1             (*(vuint8_t  *)(0xFC0CC00C)) /* LINCTRL1 - LIN Control Register 1 */
#define ESCI2_LINCTRL2             (*(vuint8_t  *)(0xFC0CC00D)) /* LINCTRL2 - LIN Control Register 2 */
#define ESCI2_LINCTRL3             (*(vuint8_t  *)(0xFC0CC00E)) /* LINCTRL3 - LIN Control Register 3 */
#define ESCI2_LINTX                (*(vuint8_t  *)(0xFC0CC010)) /* LINTX - LIN TX Register */
#define ESCI2_LINRX                (*(vuint8_t  *)(0xFC0CC014)) /* LINRX - LIN RX Register */
#define ESCI2_LINCRCP1             (*(vuint8_t  *)(0xFC0CC018)) /* LINCRCP1 - LIN CRC Polynomial Register 1 */
#define ESCI2_LINCRCP2             (*(vuint8_t  *)(0xFC0CC019)) /* LINCRCP2 - LIN CRC Polynomial Register 2 */
#define ESCI3_SCIBD                (*(vuint16_t *)(0xFC0D0000)) /* SCIBD - Baud Rate Register */
#define ESCI3_SCICR1               (*(vuint8_t  *)(0xFC0D0002)) /* SCICR1 - Control Register 1 */
#define ESCI3_SCICR2               (*(vuint8_t  *)(0xFC0D0003)) /* SCICR2 - Control Register 2 */
#define ESCI3_SCICR3               (*(vuint8_t  *)(0xFC0D0004)) /* SCICR3 - Control Register 3 */
#define ESCI3_SCICR4               (*(vuint8_t  *)(0xFC0D0005)) /* SCICR4 - Control Register 4 */
#define ESCI3_SCIDRH               (*(vuint8_t  *)(0xFC0D0006)) /* SCIDRH - Data Register High */
#define ESCI3_SCIDRL               (*(vuint8_t  *)(0xFC0D0007)) /* SCIDRL - Data Register Low */
#define ESCI3_SCISR1               (*(vuint8_t  *)(0xFC0D0008)) /* SCISR1 - Status Register 1 */
#define ESCI3_SCISR2               (*(vuint8_t  *)(0xFC0D0009)) /* SCISR2 - Status Register 2 */
#define ESCI3_LINSTAT1             (*(vuint8_t  *)(0xFC0D000A)) /* LINSTAT1 - LIN Status Register 1 */
#define ESCI3_LINSTAT2             (*(vuint8_t  *)(0xFC0D000B)) /* LINSTAT2 - LIN Status Register 2 */
#define ESCI3_LINCTRL1             (*(vuint8_t  *)(0xFC0D000C)) /* LINCTRL1 - LIN Control Register 1 */
#define ESCI3_LINCTRL2             (*(vuint8_t  *)(0xFC0D000D)) /* LINCTRL2 - LIN Control Register 2 */
#define ESCI3_LINCTRL3             (*(vuint8_t  *)(0xFC0D000E)) /* LINCTRL3 - LIN Control Register 3 */
#define ESCI3_LINTX                (*(vuint8_t  *)(0xFC0D0010)) /* LINTX - LIN TX Register */
#define ESCI3_LINRX                (*(vuint8_t  *)(0xFC0D0014)) /* LINRX - LIN RX Register */
#define ESCI3_LINCRCP1             (*(vuint8_t  *)(0xFC0D0018)) /* LINCRCP1 - LIN CRC Polynomial Register 1 */
#define ESCI3_LINCRCP2             (*(vuint8_t  *)(0xFC0D0019)) /* LINCRCP2 - LIN CRC Polynomial Register 2 */
#define ESCI_SCIBD(x)              (*(vuint16_t *)(0xFC0C4000+((x)*0x4000)))    /* SCIBD - Baud Rate Register */
#define ESCI_SCICR1(x)             (*(vuint8_t  *)(0xFC0C4002+((x)*0x4000)))    /* SCICR1 - Control Register 1 */
#define ESCI_SCICR2(x)             (*(vuint8_t  *)(0xFC0C4003+((x)*0x4000)))    /* SCICR2 - Control Register 2 */
#define ESCI_SCICR3(x)             (*(vuint8_t  *)(0xFC0C4004+((x)*0x4000)))    /* SCICR3 - Control Register 3 */
#define ESCI_SCICR4(x)             (*(vuint8_t  *)(0xFC0C4005+((x)*0x4000)))    /* SCICR4 - Control Register 4 */
#define ESCI_SCIDRH(x)             (*(vuint8_t  *)(0xFC0C4006+((x)*0x4000)))    /* SCIDRH - Data Register High */
#define ESCI_SCIDRL(x)             (*(vuint8_t  *)(0xFC0C4007+((x)*0x4000)))    /* SCIDRL - Data Register Low */
#define ESCI_SCISR1(x)             (*(vuint8_t  *)(0xFC0C4008+((x)*0x4000)))    /* SCISR1 - Status Register 1 */
#define ESCI_SCISR2(x)             (*(vuint8_t  *)(0xFC0C4009+((x)*0x4000)))    /* SCISR2 - Status Register 2 */
#define ESCI_LINSTAT1(x)           (*(vuint8_t  *)(0xFC0C400A+((x)*0x4000)))    /* LINSTAT1 - LIN Status Register 1 */
#define ESCI_LINSTAT2(x)           (*(vuint8_t  *)(0xFC0C400B+((x)*0x4000)))    /* LINSTAT2 - LIN Status Register 2 */
#define ESCI_LINCTRL1(x)           (*(vuint8_t  *)(0xFC0C400C+((x)*0x4000)))    /* LINCTRL1 - LIN Control Register 1 */
#define ESCI_LINCTRL2(x)           (*(vuint8_t  *)(0xFC0C400D+((x)*0x4000)))    /* LINCTRL2 - LIN Control Register 2 */
#define ESCI_LINCTRL3(x)           (*(vuint8_t  *)(0xFC0C400E+((x)*0x4000)))    /* LINCTRL3 - LIN Control Register 3 */
#define ESCI_LINTX(x)              (*(vuint8_t  *)(0xFC0C4010+((x)*0x4000)))    /* LINTX - LIN TX Register */
#define ESCI_LINRX(x)              (*(vuint8_t  *)(0xFC0C4014+((x)*0x4000)))    /* LINRX - LIN RX Register */
#define ESCI_LINCRCP1(x)           (*(vuint8_t  *)(0xFC0C4018+((x)*0x4000)))    /* LINCRCP1 - LIN CRC Polynomial Register 1 */
#define ESCI_LINCRCP2(x)           (*(vuint8_t  *)(0xFC0C4019+((x)*0x4000)))    /* LINCRCP2 - LIN CRC Polynomial Register 2 */

/* Bit definitions and macros for ESCI_SCIBD */
#define ESCI_SBR(x)                (((x)&0x1FFF)<<0)    /* SCI Baud Rate Bits */

/* Bit definitions and macros for ESCI_SCICR1 */
#define ESCI_PT                    (0x01)         /*  Parity Type */
#define ESCI_PE                    (0x02)         /*  Parity Enable */
#define ESCI_ILT                   (0x04)         /*  Idle Line Type */
#define ESCI_WAKE                  (0x08)         /*  Wakeup Condition */
#define ESCI_M                     (0x10)         /*  Data Format Mode */
#define ESCI_RSRC                  (0x20)         /*  Receiver Source */
#define ESCI_SCISDOZ               (0x40)         /*  SCI Stop in Doze Mode */
#define ESCI_LOOPS                 (0x80)         /*  Loop Select */

/* Bit definitions and macros for ESCI_SCICR2 */
#define ESCI_SBK                   (0x01)         /*  Send Break */
#define ESCI_RWU                   (0x02)         /*  Receiver Wakeup */
#define ESCI_RE                    (0x04)         /*  Receiver Enable */
#define ESCI_TE                    (0x08)         /*  Transmitter Enable */
#define ESCI_ILIE                  (0x10)         /*  Idle Line Interrupt Enable */
#define ESCI_RIE                   (0x20)         /*  Receiver Full Interrupt Enable */
#define ESCI_TCIE                  (0x40)         /*  Transmission Complete Interrupt Enable */
#define ESCI_TIE                   (0x80)         /*  Transmitter Interrupt Enable */

/* Bit definitions and macros for ESCI_SCICR3 */
#define ESCI_TXDIR                 (0x01)         /*  Transmitter pin data direction */
#define ESCI_BRK13                 (0x02)         /*  Break Transmit character length */
#define ESCI_TXDMA                 (0x04)         /*  Activate TX DMA channel */
#define ESCI_RXDMA                 (0x08)         /*  Activate RX DMA channel */
#define ESCI_IEBERR                (0x10)         /*  Enable Bit Error Interrupt */
#define ESCI_BSTP                  (0x20)         /*  Bit Error / Physical Bus Error Stop */
#define ESCI_FBR                   (0x40)         /*  Fast Bit Error */
#define ESCI_MDIS                  (0x80)         /*  Module Disable */

/* Bit definitions and macros for ESCI_SCICR4 */
#define ESCI_PFIE                  (0x01)         /* Parity Flag Interrupt Enable  */
#define ESCI_FEIE                  (0x02)         /* Frame Error Interrupt Enable  */
#define ESCI_NFIE                  (0x04)         /* Noise Flag Interrupt Enable  */
#define ESCI_ORIE                  (0x08)         /* Overrun Error Interrupt Enable  */
#define ESCI_SBSTP                 (0x40)         /* SCI Bit Error Stop  */
#define ESCI_BESM13                (0x80)         /* Bit Error Sample Mode, Bit 13 */

/* Bit definitions and macros for ESCI_SCIDRH */
#define ESCI_T8                    (0x40)         /*  Transmit Bit 8 */
#define ESCI_R8                    (0x80)         /*  Received Bit 8 */

/* Bit definitions and macros for ESCI_SCIDRL */
#define ESCI_T_R(x)                (((x)&0xFF)<<0)  /*  RX/TX bits seven through zero */

/* Bit definitions and macros for ESCI_SCISR1 */
#define ESCI_PF                    (0x01)         /*  Parity Error Flag */
#define ESCI_FE                    (0x02)         /*  Framing Error Flag */
#define ESCI_NF                    (0x04)         /*  Noise Flag */
#define ESCI_OR                    (0x08)         /*  Overrun Flag */
#define ESCI_IDLE                  (0x10)         /*  Idle Line Flag */
#define ESCI_RDRF                  (0x20)         /*  Receive Data Register Full Flag */
#define ESCI_TC                    (0x40)         /*  Transmit Complete Flag */
#define ESCI_TDRE                  (0x80)         /*  Transmit Data Register Empty Flag */

/* Bit definitions and macros for ESCI_SCISR2 */
#define ESCI_RAF                   (0x01)         /*  Receiver Active Flag */
#define ESCI_BERR                  (0x10)         /*  Bit Error */

/* Bit definitions and macros for ESCI_LINSTAT1 */
#define ESCI_FRC                   (0x01)         /*  Frame Complete */
#define ESCI_CKERR                 (0x02)         /*  Checksum Error */
#define ESCI_CERR                  (0x04)         /*  CRC Error */
#define ESCI_PBERR                 (0x08)         /*  Physical Bus Error */
#define ESCI_STO                   (0x10)         /*  Slave TimeOut */
#define ESCI_LWAKE                 (0x20)         /*  Received LIN Wakeup Signal */
#define ESCI_TXRDY                 (0x40)         /*  Transmit Data Ready */
#define ESCI_RXRDY                 (0x80)         /*  Receive Data Ready */

/* Bit definitions and macros for ESCI_LINSTAT2 */
#define ESCI_OVFL                  (0x01)         /*  RX Register Overflow */

/* Bit definitions and macros for ESCI_LINCTRL1 */
#define ESCI_LIN                   (0x01)         /*  LIN Mode */
#define ESCI_PRTY                  (0x02)         /*  Activating Parity Generation */
#define ESCI_DSF                   (0x04)         /*  Double Stop Flags */
#define ESCI_LDBG                  (0x08)         /*  LIN Debug Mode */
#define ESCI_WUD(x)                (((x)&0x03)<<4)  /*  WakeUp Delimiter Time */
#define ESCI_WU                    (0x40)         /*  LIN Bus WakeUp */
#define ESCI_LRES                  (0x80)         /*  LIN Resync */

/* Bit definitions and macros for ESCI_LINCTRL2 */
#define ESCI_FCIE                  (0x01)         /*  Frame Complete Interrupt Enable */
#define ESCI_CKIE                  (0x02)         /*  Checksum Error Interrupt Enable */
#define ESCI_CIE                   (0x04)         /*  CRC Error Interrupt Enable */
#define ESCI_PBIE                  (0x08)         /*  Physical Bus Error Interrupt Enable */
#define ESCI_STIE                  (0x10)         /*  Slave Timeout Error Interrupt Enable */
#define ESCI_WUIE                  (0x20)         /*  RX WakeUP Interrupt Enable */
#define ESCI_TXIE                  (0x40)         /*  LIN TXREG Ready Interrupt Enable */
#define ESCI_RXIE                  (0x80)         /*  LIN RXREG Ready Interrupt Enable */

/* Bit definitions and macros for ESCI_LINCTRL3 */
#define ESCI_OFIE                  (0x01)         /*  Overflow Interrupt Enable */

/* Bit definitions and macros for ESCI_LINTX */
#define ESCI_P1                    (0x80)
#define ESCI_P0                    (0x40)
#define ESCI_ID5                   (0x20)
#define ESCI_ID4                   (0x10)
#define ESCI_ID3                   (0x08)
#define ESCI_ID2                   (0x04)
#define ESCI_ID1                   (0x02)
#define ESCI_ID0                   (0x01)
#define ESCI_HDCHK                 (0x80)
#define ESCI_CSUM                  (0x40)
#define ESCI_CRC                   (0x20)
#define ESCI_TX                    (0x10)

/*********************************************************************
*
* FLEXCAN Module (FLEXCAN)
*
*********************************************************************/

/* Register read/write macros */
#define FLEXCAN0_MCR               (*(vuint32_t *)(0xFC094000)) /* MCR - Module Configuration Register */
#define FLEXCAN0_CTRL              (*(vuint32_t *)(0xFC094004)) /* CTRL - Control Register */
#define FLEXCAN0_TIMER             (*(vuint32_t *)(0xFC094008))
#define FLEXCAN0_RXGMASK           (*(vuint32_t *)(0xFC094010))
#define FLEXCAN0_RX14MASK          (*(vuint32_t *)(0xFC094014))
#define FLEXCAN0_RX15MASK          (*(vuint32_t *)(0xFC094018))
#define FLEXCAN0_ECR               (*(vuint32_t *)(0xFC09401C)) /* ECR - Error Counter Register */
#define FLEXCAN0_ESR               (*(vuint32_t *)(0xFC094020)) /* ESR - Error and Status Register */
#define FLEXCAN0_IMASK             (*(vuint32_t *)(0xFC094028))
#define FLEXCAN0_IFLAG             (*(vuint32_t *)(0xFC094030))
#define FLEXCAN0_BUFCS0            (*(vuint32_t *)(0xFC094080))
#define FLEXCAN0_BUFCS1            (*(vuint32_t *)(0xFC094090))
#define FLEXCAN0_BUFCS2            (*(vuint32_t *)(0xFC0940A0))
#define FLEXCAN0_BUFCS3            (*(vuint32_t *)(0xFC0940B0))
#define FLEXCAN0_BUFCS4            (*(vuint32_t *)(0xFC0940C0))
#define FLEXCAN0_BUFCS5            (*(vuint32_t *)(0xFC0940D0))
#define FLEXCAN0_BUFCS6            (*(vuint32_t *)(0xFC0940E0))
#define FLEXCAN0_BUFCS7            (*(vuint32_t *)(0xFC0940F0))
#define FLEXCAN0_BUFCS8            (*(vuint32_t *)(0xFC094100))
#define FLEXCAN0_BUFCS9            (*(vuint32_t *)(0xFC094110))
#define FLEXCAN0_BUFCS10           (*(vuint32_t *)(0xFC094120))
#define FLEXCAN0_BUFCS11           (*(vuint32_t *)(0xFC094130))
#define FLEXCAN0_BUFCS12           (*(vuint32_t *)(0xFC094140))
#define FLEXCAN0_BUFCS13           (*(vuint32_t *)(0xFC094150))
#define FLEXCAN0_BUFCS14           (*(vuint32_t *)(0xFC094160))
#define FLEXCAN0_BUFCS15           (*(vuint32_t *)(0xFC094170))
#define FLEXCAN0_BUFCS16           (*(vuint32_t *)(0xFC094180))
#define FLEXCAN0_BUFCS17           (*(vuint32_t *)(0xFC094190))
#define FLEXCAN0_BUFCS18           (*(vuint32_t *)(0xFC0941A0))
#define FLEXCAN0_BUFCS19           (*(vuint32_t *)(0xFC0941B0))
#define FLEXCAN0_BUFCS20           (*(vuint32_t *)(0xFC0941C0))
#define FLEXCAN0_BUFCS21           (*(vuint32_t *)(0xFC0941D0))
#define FLEXCAN0_BUFCS22           (*(vuint32_t *)(0xFC0941E0))
#define FLEXCAN0_BUFCS23           (*(vuint32_t *)(0xFC0941F0))
#define FLEXCAN0_BUFCS24           (*(vuint32_t *)(0xFC094200))
#define FLEXCAN0_BUFCS25           (*(vuint32_t *)(0xFC094210))
#define FLEXCAN0_BUFCS26           (*(vuint32_t *)(0xFC094220))
#define FLEXCAN0_BUFCS27           (*(vuint32_t *)(0xFC094230))
#define FLEXCAN0_BUFCS28           (*(vuint32_t *)(0xFC094240))
#define FLEXCAN0_BUFCS29           (*(vuint32_t *)(0xFC094250))
#define FLEXCAN0_BUFCS30           (*(vuint32_t *)(0xFC094260))
#define FLEXCAN0_BUFCS31           (*(vuint32_t *)(0xFC094270))
#define FLEXCAN0_BUFCS(x)          (*(vuint32_t *)(0xFC094080+((x)*0x010)))
#define FLEXCAN0_BUFID0            (*(vuint32_t *)(0xFC094084))
#define FLEXCAN0_BUFID1            (*(vuint32_t *)(0xFC094094))
#define FLEXCAN0_BUFID2            (*(vuint32_t *)(0xFC0940A4))
#define FLEXCAN0_BUFID3            (*(vuint32_t *)(0xFC0940B4))
#define FLEXCAN0_BUFID4            (*(vuint32_t *)(0xFC0940C4))
#define FLEXCAN0_BUFID5            (*(vuint32_t *)(0xFC0940D4))
#define FLEXCAN0_BUFID6            (*(vuint32_t *)(0xFC0940E4))
#define FLEXCAN0_BUFID7            (*(vuint32_t *)(0xFC0940F4))
#define FLEXCAN0_BUFID8            (*(vuint32_t *)(0xFC094104))
#define FLEXCAN0_BUFID9            (*(vuint32_t *)(0xFC094114))
#define FLEXCAN0_BUFID10           (*(vuint32_t *)(0xFC094124))
#define FLEXCAN0_BUFID11           (*(vuint32_t *)(0xFC094134))
#define FLEXCAN0_BUFID12           (*(vuint32_t *)(0xFC094144))
#define FLEXCAN0_BUFID13           (*(vuint32_t *)(0xFC094154))
#define FLEXCAN0_BUFID14           (*(vuint32_t *)(0xFC094164))
#define FLEXCAN0_BUFID15           (*(vuint32_t *)(0xFC094174))
#define FLEXCAN0_BUFID16           (*(vuint32_t *)(0xFC094184))
#define FLEXCAN0_BUFID17           (*(vuint32_t *)(0xFC094194))
#define FLEXCAN0_BUFID18           (*(vuint32_t *)(0xFC0941A4))
#define FLEXCAN0_BUFID19           (*(vuint32_t *)(0xFC0941B4))
#define FLEXCAN0_BUFID20           (*(vuint32_t *)(0xFC0941C4))
#define FLEXCAN0_BUFID21           (*(vuint32_t *)(0xFC0941D4))
#define FLEXCAN0_BUFID22           (*(vuint32_t *)(0xFC0941E4))
#define FLEXCAN0_BUFID23           (*(vuint32_t *)(0xFC0941F4))
#define FLEXCAN0_BUFID24           (*(vuint32_t *)(0xFC094204))
#define FLEXCAN0_BUFID25           (*(vuint32_t *)(0xFC094214))
#define FLEXCAN0_BUFID26           (*(vuint32_t *)(0xFC094224))
#define FLEXCAN0_BUFID27           (*(vuint32_t *)(0xFC094234))
#define FLEXCAN0_BUFID28           (*(vuint32_t *)(0xFC094244))
#define FLEXCAN0_BUFID29           (*(vuint32_t *)(0xFC094254))
#define FLEXCAN0_BUFID30           (*(vuint32_t *)(0xFC094264))
#define FLEXCAN0_BUFID31           (*(vuint32_t *)(0xFC094274))
#define FLEXCAN0_BUFID(x)          (*(vuint32_t *)(0xFC094084+((x)*0x010)))
#define FLEXCAN0_BUFDATA03_0       (*(vuint32_t *)(0xFC094088))
#define FLEXCAN0_BUFDATA03_1       (*(vuint32_t *)(0xFC094098))
#define FLEXCAN0_BUFDATA03_2       (*(vuint32_t *)(0xFC0940A8))
#define FLEXCAN0_BUFDATA03_3       (*(vuint32_t *)(0xFC0940B8))
#define FLEXCAN0_BUFDATA03_4       (*(vuint32_t *)(0xFC0940C8))
#define FLEXCAN0_BUFDATA03_5       (*(vuint32_t *)(0xFC0940D8))
#define FLEXCAN0_BUFDATA03_6       (*(vuint32_t *)(0xFC0940E8))
#define FLEXCAN0_BUFDATA03_7       (*(vuint32_t *)(0xFC0940F8))
#define FLEXCAN0_BUFDATA03_8       (*(vuint32_t *)(0xFC094108))
#define FLEXCAN0_BUFDATA03_9       (*(vuint32_t *)(0xFC094118))
#define FLEXCAN0_BUFDATA03_10      (*(vuint32_t *)(0xFC094128))
#define FLEXCAN0_BUFDATA03_11      (*(vuint32_t *)(0xFC094138))
#define FLEXCAN0_BUFDATA03_12      (*(vuint32_t *)(0xFC094148))
#define FLEXCAN0_BUFDATA03_13      (*(vuint32_t *)(0xFC094158))
#define FLEXCAN0_BUFDATA03_14      (*(vuint32_t *)(0xFC094168))
#define FLEXCAN0_BUFDATA03_15      (*(vuint32_t *)(0xFC094178))
#define FLEXCAN0_BUFDATA03_16      (*(vuint32_t *)(0xFC094188))
#define FLEXCAN0_BUFDATA03_17      (*(vuint32_t *)(0xFC094198))
#define FLEXCAN0_BUFDATA03_18      (*(vuint32_t *)(0xFC0941A8))
#define FLEXCAN0_BUFDATA03_19      (*(vuint32_t *)(0xFC0941B8))
#define FLEXCAN0_BUFDATA03_20      (*(vuint32_t *)(0xFC0941C8))
#define FLEXCAN0_BUFDATA03_21      (*(vuint32_t *)(0xFC0941D8))
#define FLEXCAN0_BUFDATA03_22      (*(vuint32_t *)(0xFC0941E8))
#define FLEXCAN0_BUFDATA03_23      (*(vuint32_t *)(0xFC0941F8))
#define FLEXCAN0_BUFDATA03_24      (*(vuint32_t *)(0xFC094208))
#define FLEXCAN0_BUFDATA03_25      (*(vuint32_t *)(0xFC094218))
#define FLEXCAN0_BUFDATA03_26      (*(vuint32_t *)(0xFC094228))
#define FLEXCAN0_BUFDATA03_27      (*(vuint32_t *)(0xFC094238))
#define FLEXCAN0_BUFDATA03_28      (*(vuint32_t *)(0xFC094248))
#define FLEXCAN0_BUFDATA03_29      (*(vuint32_t *)(0xFC094258))
#define FLEXCAN0_BUFDATA03_30      (*(vuint32_t *)(0xFC094268))
#define FLEXCAN0_BUFDATA03_31      (*(vuint32_t *)(0xFC094278))
#define FLEXCAN0_BUFDATA03_(x)     (*(vuint32_t *)(0xFC094088+((x)*0x010)))
#define FLEXCAN0_BUFDATA47_0       (*(vuint32_t *)(0xFC09408C))
#define FLEXCAN0_BUFDATA47_1       (*(vuint32_t *)(0xFC09409C))
#define FLEXCAN0_BUFDATA47_2       (*(vuint32_t *)(0xFC0940AC))
#define FLEXCAN0_BUFDATA47_3       (*(vuint32_t *)(0xFC0940BC))
#define FLEXCAN0_BUFDATA47_4       (*(vuint32_t *)(0xFC0940CC))
#define FLEXCAN0_BUFDATA47_5       (*(vuint32_t *)(0xFC0940DC))
#define FLEXCAN0_BUFDATA47_6       (*(vuint32_t *)(0xFC0940EC))
#define FLEXCAN0_BUFDATA47_7       (*(vuint32_t *)(0xFC0940FC))
#define FLEXCAN0_BUFDATA47_8       (*(vuint32_t *)(0xFC09410C))
#define FLEXCAN0_BUFDATA47_9       (*(vuint32_t *)(0xFC09411C))
#define FLEXCAN0_BUFDATA47_10      (*(vuint32_t *)(0xFC09412C))
#define FLEXCAN0_BUFDATA47_11      (*(vuint32_t *)(0xFC09413C))
#define FLEXCAN0_BUFDATA47_12      (*(vuint32_t *)(0xFC09414C))
#define FLEXCAN0_BUFDATA47_13      (*(vuint32_t *)(0xFC09415C))
#define FLEXCAN0_BUFDATA47_14      (*(vuint32_t *)(0xFC09416C))
#define FLEXCAN0_BUFDATA47_15      (*(vuint32_t *)(0xFC09417C))
#define FLEXCAN0_BUFDATA47_16      (*(vuint32_t *)(0xFC09418C))
#define FLEXCAN0_BUFDATA47_17      (*(vuint32_t *)(0xFC09419C))
#define FLEXCAN0_BUFDATA47_18      (*(vuint32_t *)(0xFC0941AC))
#define FLEXCAN0_BUFDATA47_19      (*(vuint32_t *)(0xFC0941BC))
#define FLEXCAN0_BUFDATA47_20      (*(vuint32_t *)(0xFC0941CC))
#define FLEXCAN0_BUFDATA47_21      (*(vuint32_t *)(0xFC0941DC))
#define FLEXCAN0_BUFDATA47_22      (*(vuint32_t *)(0xFC0941EC))
#define FLEXCAN0_BUFDATA47_23      (*(vuint32_t *)(0xFC0941FC))
#define FLEXCAN0_BUFDATA47_24      (*(vuint32_t *)(0xFC09420C))
#define FLEXCAN0_BUFDATA47_25      (*(vuint32_t *)(0xFC09421C))
#define FLEXCAN0_BUFDATA47_26      (*(vuint32_t *)(0xFC09422C))
#define FLEXCAN0_BUFDATA47_27      (*(vuint32_t *)(0xFC09423C))
#define FLEXCAN0_BUFDATA47_28      (*(vuint32_t *)(0xFC09424C))
#define FLEXCAN0_BUFDATA47_29      (*(vuint32_t *)(0xFC09425C))
#define FLEXCAN0_BUFDATA47_30      (*(vuint32_t *)(0xFC09426C))
#define FLEXCAN0_BUFDATA47_31      (*(vuint32_t *)(0xFC09427C))
#define FLEXCAN0_BUFDATA47_(x)     (*(vuint32_t *)(0xFC09408C+((x)*0x010)))
#define FLEXCAN1_MCR               (*(vuint32_t *)(0xFC098000)) /* MCR - Module Configuration Register */
#define FLEXCAN1_CTRL              (*(vuint32_t *)(0xFC098004)) /* CTRL - Control Register */
#define FLEXCAN1_TIMER             (*(vuint32_t *)(0xFC098008))
#define FLEXCAN1_RXGMASK           (*(vuint32_t *)(0xFC098010))
#define FLEXCAN1_RX14MASK          (*(vuint32_t *)(0xFC098014))
#define FLEXCAN1_RX15MASK          (*(vuint32_t *)(0xFC098018))
#define FLEXCAN1_ECR               (*(vuint32_t *)(0xFC09801C)) /* ECR - Error Counter Register */
#define FLEXCAN1_ESR               (*(vuint32_t *)(0xFC098020)) /* ESR - Error and Status Register */
#define FLEXCAN1_IMASK             (*(vuint32_t *)(0xFC098028))
#define FLEXCAN1_IFLAG             (*(vuint32_t *)(0xFC098030))
#define FLEXCAN1_BUFCS0            (*(vuint32_t *)(0xFC098080))
#define FLEXCAN1_BUFCS1            (*(vuint32_t *)(0xFC098090))
#define FLEXCAN1_BUFCS2            (*(vuint32_t *)(0xFC0980A0))
#define FLEXCAN1_BUFCS3            (*(vuint32_t *)(0xFC0980B0))
#define FLEXCAN1_BUFCS4            (*(vuint32_t *)(0xFC0980C0))
#define FLEXCAN1_BUFCS5            (*(vuint32_t *)(0xFC0980D0))
#define FLEXCAN1_BUFCS6            (*(vuint32_t *)(0xFC0980E0))
#define FLEXCAN1_BUFCS7            (*(vuint32_t *)(0xFC0980F0))
#define FLEXCAN1_BUFCS8            (*(vuint32_t *)(0xFC098100))
#define FLEXCAN1_BUFCS9            (*(vuint32_t *)(0xFC098110))
#define FLEXCAN1_BUFCS10           (*(vuint32_t *)(0xFC098120))
#define FLEXCAN1_BUFCS11           (*(vuint32_t *)(0xFC098130))
#define FLEXCAN1_BUFCS12           (*(vuint32_t *)(0xFC098140))
#define FLEXCAN1_BUFCS13           (*(vuint32_t *)(0xFC098150))
#define FLEXCAN1_BUFCS14           (*(vuint32_t *)(0xFC098160))
#define FLEXCAN1_BUFCS15           (*(vuint32_t *)(0xFC098170))
#define FLEXCAN1_BUFCS16           (*(vuint32_t *)(0xFC098180))
#define FLEXCAN1_BUFCS17           (*(vuint32_t *)(0xFC098190))
#define FLEXCAN1_BUFCS18           (*(vuint32_t *)(0xFC0981A0))
#define FLEXCAN1_BUFCS19           (*(vuint32_t *)(0xFC0981B0))
#define FLEXCAN1_BUFCS20           (*(vuint32_t *)(0xFC0981C0))
#define FLEXCAN1_BUFCS21           (*(vuint32_t *)(0xFC0981D0))
#define FLEXCAN1_BUFCS22           (*(vuint32_t *)(0xFC0981E0))
#define FLEXCAN1_BUFCS23           (*(vuint32_t *)(0xFC0981F0))
#define FLEXCAN1_BUFCS24           (*(vuint32_t *)(0xFC098200))
#define FLEXCAN1_BUFCS25           (*(vuint32_t *)(0xFC098210))
#define FLEXCAN1_BUFCS26           (*(vuint32_t *)(0xFC098220))
#define FLEXCAN1_BUFCS27           (*(vuint32_t *)(0xFC098230))
#define FLEXCAN1_BUFCS28           (*(vuint32_t *)(0xFC098240))
#define FLEXCAN1_BUFCS29           (*(vuint32_t *)(0xFC098250))
#define FLEXCAN1_BUFCS30           (*(vuint32_t *)(0xFC098260))
#define FLEXCAN1_BUFCS31           (*(vuint32_t *)(0xFC098270))
#define FLEXCAN1_BUFCS(x)          (*(vuint32_t *)(0xFC098080+((x)*0x010)))
#define FLEXCAN1_BUFID0            (*(vuint32_t *)(0xFC098084))
#define FLEXCAN1_BUFID1            (*(vuint32_t *)(0xFC098094))
#define FLEXCAN1_BUFID2            (*(vuint32_t *)(0xFC0980A4))
#define FLEXCAN1_BUFID3            (*(vuint32_t *)(0xFC0980B4))
#define FLEXCAN1_BUFID4            (*(vuint32_t *)(0xFC0980C4))
#define FLEXCAN1_BUFID5            (*(vuint32_t *)(0xFC0980D4))
#define FLEXCAN1_BUFID6            (*(vuint32_t *)(0xFC0980E4))
#define FLEXCAN1_BUFID7            (*(vuint32_t *)(0xFC0980F4))
#define FLEXCAN1_BUFID8            (*(vuint32_t *)(0xFC098104))
#define FLEXCAN1_BUFID9            (*(vuint32_t *)(0xFC098114))
#define FLEXCAN1_BUFID10           (*(vuint32_t *)(0xFC098124))
#define FLEXCAN1_BUFID11           (*(vuint32_t *)(0xFC098134))
#define FLEXCAN1_BUFID12           (*(vuint32_t *)(0xFC098144))
#define FLEXCAN1_BUFID13           (*(vuint32_t *)(0xFC098154))
#define FLEXCAN1_BUFID14           (*(vuint32_t *)(0xFC098164))
#define FLEXCAN1_BUFID15           (*(vuint32_t *)(0xFC098174))
#define FLEXCAN1_BUFID16           (*(vuint32_t *)(0xFC098184))
#define FLEXCAN1_BUFID17           (*(vuint32_t *)(0xFC098194))
#define FLEXCAN1_BUFID18           (*(vuint32_t *)(0xFC0981A4))
#define FLEXCAN1_BUFID19           (*(vuint32_t *)(0xFC0981B4))
#define FLEXCAN1_BUFID20           (*(vuint32_t *)(0xFC0981C4))
#define FLEXCAN1_BUFID21           (*(vuint32_t *)(0xFC0981D4))
#define FLEXCAN1_BUFID22           (*(vuint32_t *)(0xFC0981E4))
#define FLEXCAN1_BUFID23           (*(vuint32_t *)(0xFC0981F4))
#define FLEXCAN1_BUFID24           (*(vuint32_t *)(0xFC098204))
#define FLEXCAN1_BUFID25           (*(vuint32_t *)(0xFC098214))
#define FLEXCAN1_BUFID26           (*(vuint32_t *)(0xFC098224))
#define FLEXCAN1_BUFID27           (*(vuint32_t *)(0xFC098234))
#define FLEXCAN1_BUFID28           (*(vuint32_t *)(0xFC098244))
#define FLEXCAN1_BUFID29           (*(vuint32_t *)(0xFC098254))
#define FLEXCAN1_BUFID30           (*(vuint32_t *)(0xFC098264))
#define FLEXCAN1_BUFID31           (*(vuint32_t *)(0xFC098274))
#define FLEXCAN1_BUFID(x)          (*(vuint32_t *)(0xFC098084+((x)*0x010)))
#define FLEXCAN1_BUFDATA03_0       (*(vuint32_t *)(0xFC098088))
#define FLEXCAN1_BUFDATA03_1       (*(vuint32_t *)(0xFC098098))
#define FLEXCAN1_BUFDATA03_2       (*(vuint32_t *)(0xFC0980A8))
#define FLEXCAN1_BUFDATA03_3       (*(vuint32_t *)(0xFC0980B8))
#define FLEXCAN1_BUFDATA03_4       (*(vuint32_t *)(0xFC0980C8))
#define FLEXCAN1_BUFDATA03_5       (*(vuint32_t *)(0xFC0980D8))
#define FLEXCAN1_BUFDATA03_6       (*(vuint32_t *)(0xFC0980E8))
#define FLEXCAN1_BUFDATA03_7       (*(vuint32_t *)(0xFC0980F8))
#define FLEXCAN1_BUFDATA03_8       (*(vuint32_t *)(0xFC098108))
#define FLEXCAN1_BUFDATA03_9       (*(vuint32_t *)(0xFC098118))
#define FLEXCAN1_BUFDATA03_10      (*(vuint32_t *)(0xFC098128))
#define FLEXCAN1_BUFDATA03_11      (*(vuint32_t *)(0xFC098138))
#define FLEXCAN1_BUFDATA03_12      (*(vuint32_t *)(0xFC098148))
#define FLEXCAN1_BUFDATA03_13      (*(vuint32_t *)(0xFC098158))
#define FLEXCAN1_BUFDATA03_14      (*(vuint32_t *)(0xFC098168))
#define FLEXCAN1_BUFDATA03_15      (*(vuint32_t *)(0xFC098178))
#define FLEXCAN1_BUFDATA03_16      (*(vuint32_t *)(0xFC098188))
#define FLEXCAN1_BUFDATA03_17      (*(vuint32_t *)(0xFC098198))
#define FLEXCAN1_BUFDATA03_18      (*(vuint32_t *)(0xFC0981A8))
#define FLEXCAN1_BUFDATA03_19      (*(vuint32_t *)(0xFC0981B8))
#define FLEXCAN1_BUFDATA03_20      (*(vuint32_t *)(0xFC0981C8))
#define FLEXCAN1_BUFDATA03_21      (*(vuint32_t *)(0xFC0981D8))
#define FLEXCAN1_BUFDATA03_22      (*(vuint32_t *)(0xFC0981E8))
#define FLEXCAN1_BUFDATA03_23      (*(vuint32_t *)(0xFC0981F8))
#define FLEXCAN1_BUFDATA03_24      (*(vuint32_t *)(0xFC098208))
#define FLEXCAN1_BUFDATA03_25      (*(vuint32_t *)(0xFC098218))
#define FLEXCAN1_BUFDATA03_26      (*(vuint32_t *)(0xFC098228))
#define FLEXCAN1_BUFDATA03_27      (*(vuint32_t *)(0xFC098238))
#define FLEXCAN1_BUFDATA03_28      (*(vuint32_t *)(0xFC098248))
#define FLEXCAN1_BUFDATA03_29      (*(vuint32_t *)(0xFC098258))
#define FLEXCAN1_BUFDATA03_30      (*(vuint32_t *)(0xFC098268))
#define FLEXCAN1_BUFDATA03_31      (*(vuint32_t *)(0xFC098278))
#define FLEXCAN1_BUFDATA03_(x)     (*(vuint32_t *)(0xFC098088+((x)*0x010)))
#define FLEXCAN1_BUFDATA47_0       (*(vuint32_t *)(0xFC09808C))
#define FLEXCAN1_BUFDATA47_1       (*(vuint32_t *)(0xFC09809C))
#define FLEXCAN1_BUFDATA47_2       (*(vuint32_t *)(0xFC0980AC))
#define FLEXCAN1_BUFDATA47_3       (*(vuint32_t *)(0xFC0980BC))
#define FLEXCAN1_BUFDATA47_4       (*(vuint32_t *)(0xFC0980CC))
#define FLEXCAN1_BUFDATA47_5       (*(vuint32_t *)(0xFC0980DC))
#define FLEXCAN1_BUFDATA47_6       (*(vuint32_t *)(0xFC0980EC))
#define FLEXCAN1_BUFDATA47_7       (*(vuint32_t *)(0xFC0980FC))
#define FLEXCAN1_BUFDATA47_8       (*(vuint32_t *)(0xFC09810C))
#define FLEXCAN1_BUFDATA47_9       (*(vuint32_t *)(0xFC09811C))
#define FLEXCAN1_BUFDATA47_10      (*(vuint32_t *)(0xFC09812C))
#define FLEXCAN1_BUFDATA47_11      (*(vuint32_t *)(0xFC09813C))
#define FLEXCAN1_BUFDATA47_12      (*(vuint32_t *)(0xFC09814C))
#define FLEXCAN1_BUFDATA47_13      (*(vuint32_t *)(0xFC09815C))
#define FLEXCAN1_BUFDATA47_14      (*(vuint32_t *)(0xFC09816C))
#define FLEXCAN1_BUFDATA47_15      (*(vuint32_t *)(0xFC09817C))
#define FLEXCAN1_BUFDATA47_16      (*(vuint32_t *)(0xFC09818C))
#define FLEXCAN1_BUFDATA47_17      (*(vuint32_t *)(0xFC09819C))
#define FLEXCAN1_BUFDATA47_18      (*(vuint32_t *)(0xFC0981AC))
#define FLEXCAN1_BUFDATA47_19      (*(vuint32_t *)(0xFC0981BC))
#define FLEXCAN1_BUFDATA47_20      (*(vuint32_t *)(0xFC0981CC))
#define FLEXCAN1_BUFDATA47_21      (*(vuint32_t *)(0xFC0981DC))
#define FLEXCAN1_BUFDATA47_22      (*(vuint32_t *)(0xFC0981EC))
#define FLEXCAN1_BUFDATA47_23      (*(vuint32_t *)(0xFC0981FC))
#define FLEXCAN1_BUFDATA47_24      (*(vuint32_t *)(0xFC09820C))
#define FLEXCAN1_BUFDATA47_25      (*(vuint32_t *)(0xFC09821C))
#define FLEXCAN1_BUFDATA47_26      (*(vuint32_t *)(0xFC09822C))
#define FLEXCAN1_BUFDATA47_27      (*(vuint32_t *)(0xFC09823C))
#define FLEXCAN1_BUFDATA47_28      (*(vuint32_t *)(0xFC09824C))
#define FLEXCAN1_BUFDATA47_29      (*(vuint32_t *)(0xFC09825C))
#define FLEXCAN1_BUFDATA47_30      (*(vuint32_t *)(0xFC09826C))
#define FLEXCAN1_BUFDATA47_31      (*(vuint32_t *)(0xFC09827C))
#define FLEXCAN1_BUFDATA47_(x)     (*(vuint32_t *)(0xFC09808C+((x)*0x010)))
#define FLEXCAN2_MCR               (*(vuint32_t *)(0xFC09C000)) /* MCR - Module Configuration Register */
#define FLEXCAN2_CTRL              (*(vuint32_t *)(0xFC09C004)) /* CTRL - Control Register */
#define FLEXCAN2_TIMER             (*(vuint32_t *)(0xFC09C008))
#define FLEXCAN2_RXGMASK           (*(vuint32_t *)(0xFC09C010))
#define FLEXCAN2_RX14MASK          (*(vuint32_t *)(0xFC09C014))
#define FLEXCAN2_RX15MASK          (*(vuint32_t *)(0xFC09C018))
#define FLEXCAN2_ECR               (*(vuint32_t *)(0xFC09C01C)) /* ECR - Error Counter Register */
#define FLEXCAN2_ESR               (*(vuint32_t *)(0xFC09C020)) /* ESR - Error and Status Register */
#define FLEXCAN2_IMASK             (*(vuint32_t *)(0xFC09C028))
#define FLEXCAN2_IFLAG             (*(vuint32_t *)(0xFC09C030))
#define FLEXCAN2_BUFCS0            (*(vuint32_t *)(0xFC09C080))
#define FLEXCAN2_BUFCS1            (*(vuint32_t *)(0xFC09C090))
#define FLEXCAN2_BUFCS2            (*(vuint32_t *)(0xFC09C0A0))
#define FLEXCAN2_BUFCS3            (*(vuint32_t *)(0xFC09C0B0))
#define FLEXCAN2_BUFCS4            (*(vuint32_t *)(0xFC09C0C0))
#define FLEXCAN2_BUFCS5            (*(vuint32_t *)(0xFC09C0D0))
#define FLEXCAN2_BUFCS6            (*(vuint32_t *)(0xFC09C0E0))
#define FLEXCAN2_BUFCS7            (*(vuint32_t *)(0xFC09C0F0))
#define FLEXCAN2_BUFCS8            (*(vuint32_t *)(0xFC09C100))
#define FLEXCAN2_BUFCS9            (*(vuint32_t *)(0xFC09C110))
#define FLEXCAN2_BUFCS10           (*(vuint32_t *)(0xFC09C120))
#define FLEXCAN2_BUFCS11           (*(vuint32_t *)(0xFC09C130))
#define FLEXCAN2_BUFCS12           (*(vuint32_t *)(0xFC09C140))
#define FLEXCAN2_BUFCS13           (*(vuint32_t *)(0xFC09C150))
#define FLEXCAN2_BUFCS14           (*(vuint32_t *)(0xFC09C160))
#define FLEXCAN2_BUFCS15           (*(vuint32_t *)(0xFC09C170))
#define FLEXCAN2_BUFCS16           (*(vuint32_t *)(0xFC09C180))
#define FLEXCAN2_BUFCS17           (*(vuint32_t *)(0xFC09C190))
#define FLEXCAN2_BUFCS18           (*(vuint32_t *)(0xFC09C1A0))
#define FLEXCAN2_BUFCS19           (*(vuint32_t *)(0xFC09C1B0))
#define FLEXCAN2_BUFCS20           (*(vuint32_t *)(0xFC09C1C0))
#define FLEXCAN2_BUFCS21           (*(vuint32_t *)(0xFC09C1D0))
#define FLEXCAN2_BUFCS22           (*(vuint32_t *)(0xFC09C1E0))
#define FLEXCAN2_BUFCS23           (*(vuint32_t *)(0xFC09C1F0))
#define FLEXCAN2_BUFCS24           (*(vuint32_t *)(0xFC09C200))
#define FLEXCAN2_BUFCS25           (*(vuint32_t *)(0xFC09C210))
#define FLEXCAN2_BUFCS26           (*(vuint32_t *)(0xFC09C220))
#define FLEXCAN2_BUFCS27           (*(vuint32_t *)(0xFC09C230))
#define FLEXCAN2_BUFCS28           (*(vuint32_t *)(0xFC09C240))
#define FLEXCAN2_BUFCS29           (*(vuint32_t *)(0xFC09C250))
#define FLEXCAN2_BUFCS30           (*(vuint32_t *)(0xFC09C260))
#define FLEXCAN2_BUFCS31           (*(vuint32_t *)(0xFC09C270))
#define FLEXCAN2_BUFCS(x)          (*(vuint32_t *)(0xFC09C080+((x)*0x010)))
#define FLEXCAN2_BUFID0            (*(vuint32_t *)(0xFC09C084))
#define FLEXCAN2_BUFID1            (*(vuint32_t *)(0xFC09C094))
#define FLEXCAN2_BUFID2            (*(vuint32_t *)(0xFC09C0A4))
#define FLEXCAN2_BUFID3            (*(vuint32_t *)(0xFC09C0B4))
#define FLEXCAN2_BUFID4            (*(vuint32_t *)(0xFC09C0C4))
#define FLEXCAN2_BUFID5            (*(vuint32_t *)(0xFC09C0D4))
#define FLEXCAN2_BUFID6            (*(vuint32_t *)(0xFC09C0E4))
#define FLEXCAN2_BUFID7            (*(vuint32_t *)(0xFC09C0F4))
#define FLEXCAN2_BUFID8            (*(vuint32_t *)(0xFC09C104))
#define FLEXCAN2_BUFID9            (*(vuint32_t *)(0xFC09C114))
#define FLEXCAN2_BUFID10           (*(vuint32_t *)(0xFC09C124))
#define FLEXCAN2_BUFID11           (*(vuint32_t *)(0xFC09C134))
#define FLEXCAN2_BUFID12           (*(vuint32_t *)(0xFC09C144))
#define FLEXCAN2_BUFID13           (*(vuint32_t *)(0xFC09C154))
#define FLEXCAN2_BUFID14           (*(vuint32_t *)(0xFC09C164))
#define FLEXCAN2_BUFID15           (*(vuint32_t *)(0xFC09C174))
#define FLEXCAN2_BUFID16           (*(vuint32_t *)(0xFC09C184))
#define FLEXCAN2_BUFID17           (*(vuint32_t *)(0xFC09C194))
#define FLEXCAN2_BUFID18           (*(vuint32_t *)(0xFC09C1A4))
#define FLEXCAN2_BUFID19           (*(vuint32_t *)(0xFC09C1B4))
#define FLEXCAN2_BUFID20           (*(vuint32_t *)(0xFC09C1C4))
#define FLEXCAN2_BUFID21           (*(vuint32_t *)(0xFC09C1D4))
#define FLEXCAN2_BUFID22           (*(vuint32_t *)(0xFC09C1E4))
#define FLEXCAN2_BUFID23           (*(vuint32_t *)(0xFC09C1F4))
#define FLEXCAN2_BUFID24           (*(vuint32_t *)(0xFC09C204))
#define FLEXCAN2_BUFID25           (*(vuint32_t *)(0xFC09C214))
#define FLEXCAN2_BUFID26           (*(vuint32_t *)(0xFC09C224))
#define FLEXCAN2_BUFID27           (*(vuint32_t *)(0xFC09C234))
#define FLEXCAN2_BUFID28           (*(vuint32_t *)(0xFC09C244))
#define FLEXCAN2_BUFID29           (*(vuint32_t *)(0xFC09C254))
#define FLEXCAN2_BUFID30           (*(vuint32_t *)(0xFC09C264))
#define FLEXCAN2_BUFID31           (*(vuint32_t *)(0xFC09C274))
#define FLEXCAN2_BUFID(x)          (*(vuint32_t *)(0xFC09C084+((x)*0x010)))
#define FLEXCAN2_BUFDATA03_0       (*(vuint32_t *)(0xFC09C088))
#define FLEXCAN2_BUFDATA03_1       (*(vuint32_t *)(0xFC09C098))
#define FLEXCAN2_BUFDATA03_2       (*(vuint32_t *)(0xFC09C0A8))
#define FLEXCAN2_BUFDATA03_3       (*(vuint32_t *)(0xFC09C0B8))
#define FLEXCAN2_BUFDATA03_4       (*(vuint32_t *)(0xFC09C0C8))
#define FLEXCAN2_BUFDATA03_5       (*(vuint32_t *)(0xFC09C0D8))
#define FLEXCAN2_BUFDATA03_6       (*(vuint32_t *)(0xFC09C0E8))
#define FLEXCAN2_BUFDATA03_7       (*(vuint32_t *)(0xFC09C0F8))
#define FLEXCAN2_BUFDATA03_8       (*(vuint32_t *)(0xFC09C108))
#define FLEXCAN2_BUFDATA03_9       (*(vuint32_t *)(0xFC09C118))
#define FLEXCAN2_BUFDATA03_10      (*(vuint32_t *)(0xFC09C128))
#define FLEXCAN2_BUFDATA03_11      (*(vuint32_t *)(0xFC09C138))
#define FLEXCAN2_BUFDATA03_12      (*(vuint32_t *)(0xFC09C148))
#define FLEXCAN2_BUFDATA03_13      (*(vuint32_t *)(0xFC09C158))
#define FLEXCAN2_BUFDATA03_14      (*(vuint32_t *)(0xFC09C168))
#define FLEXCAN2_BUFDATA03_15      (*(vuint32_t *)(0xFC09C178))
#define FLEXCAN2_BUFDATA03_16      (*(vuint32_t *)(0xFC09C188))
#define FLEXCAN2_BUFDATA03_17      (*(vuint32_t *)(0xFC09C198))
#define FLEXCAN2_BUFDATA03_18      (*(vuint32_t *)(0xFC09C1A8))
#define FLEXCAN2_BUFDATA03_19      (*(vuint32_t *)(0xFC09C1B8))
#define FLEXCAN2_BUFDATA03_20      (*(vuint32_t *)(0xFC09C1C8))
#define FLEXCAN2_BUFDATA03_21      (*(vuint32_t *)(0xFC09C1D8))
#define FLEXCAN2_BUFDATA03_22      (*(vuint32_t *)(0xFC09C1E8))
#define FLEXCAN2_BUFDATA03_23      (*(vuint32_t *)(0xFC09C1F8))
#define FLEXCAN2_BUFDATA03_24      (*(vuint32_t *)(0xFC09C208))
#define FLEXCAN2_BUFDATA03_25      (*(vuint32_t *)(0xFC09C218))
#define FLEXCAN2_BUFDATA03_26      (*(vuint32_t *)(0xFC09C228))
#define FLEXCAN2_BUFDATA03_27      (*(vuint32_t *)(0xFC09C238))
#define FLEXCAN2_BUFDATA03_28      (*(vuint32_t *)(0xFC09C248))
#define FLEXCAN2_BUFDATA03_29      (*(vuint32_t *)(0xFC09C258))
#define FLEXCAN2_BUFDATA03_30      (*(vuint32_t *)(0xFC09C268))
#define FLEXCAN2_BUFDATA03_31      (*(vuint32_t *)(0xFC09C278))
#define FLEXCAN2_BUFDATA03_(x)     (*(vuint32_t *)(0xFC09C088+((x)*0x010)))
#define FLEXCAN2_BUFDATA47_0       (*(vuint32_t *)(0xFC09C08C))
#define FLEXCAN2_BUFDATA47_1       (*(vuint32_t *)(0xFC09C09C))
#define FLEXCAN2_BUFDATA47_2       (*(vuint32_t *)(0xFC09C0AC))
#define FLEXCAN2_BUFDATA47_3       (*(vuint32_t *)(0xFC09C0BC))
#define FLEXCAN2_BUFDATA47_4       (*(vuint32_t *)(0xFC09C0CC))
#define FLEXCAN2_BUFDATA47_5       (*(vuint32_t *)(0xFC09C0DC))
#define FLEXCAN2_BUFDATA47_6       (*(vuint32_t *)(0xFC09C0EC))
#define FLEXCAN2_BUFDATA47_7       (*(vuint32_t *)(0xFC09C0FC))
#define FLEXCAN2_BUFDATA47_8       (*(vuint32_t *)(0xFC09C10C))
#define FLEXCAN2_BUFDATA47_9       (*(vuint32_t *)(0xFC09C11C))
#define FLEXCAN2_BUFDATA47_10      (*(vuint32_t *)(0xFC09C12C))
#define FLEXCAN2_BUFDATA47_11      (*(vuint32_t *)(0xFC09C13C))
#define FLEXCAN2_BUFDATA47_12      (*(vuint32_t *)(0xFC09C14C))
#define FLEXCAN2_BUFDATA47_13      (*(vuint32_t *)(0xFC09C15C))
#define FLEXCAN2_BUFDATA47_14      (*(vuint32_t *)(0xFC09C16C))
#define FLEXCAN2_BUFDATA47_15      (*(vuint32_t *)(0xFC09C17C))
#define FLEXCAN2_BUFDATA47_16      (*(vuint32_t *)(0xFC09C18C))
#define FLEXCAN2_BUFDATA47_17      (*(vuint32_t *)(0xFC09C19C))
#define FLEXCAN2_BUFDATA47_18      (*(vuint32_t *)(0xFC09C1AC))
#define FLEXCAN2_BUFDATA47_19      (*(vuint32_t *)(0xFC09C1BC))
#define FLEXCAN2_BUFDATA47_20      (*(vuint32_t *)(0xFC09C1CC))
#define FLEXCAN2_BUFDATA47_21      (*(vuint32_t *)(0xFC09C1DC))
#define FLEXCAN2_BUFDATA47_22      (*(vuint32_t *)(0xFC09C1EC))
#define FLEXCAN2_BUFDATA47_23      (*(vuint32_t *)(0xFC09C1FC))
#define FLEXCAN2_BUFDATA47_24      (*(vuint32_t *)(0xFC09C20C))
#define FLEXCAN2_BUFDATA47_25      (*(vuint32_t *)(0xFC09C21C))
#define FLEXCAN2_BUFDATA47_26      (*(vuint32_t *)(0xFC09C22C))
#define FLEXCAN2_BUFDATA47_27      (*(vuint32_t *)(0xFC09C23C))
#define FLEXCAN2_BUFDATA47_28      (*(vuint32_t *)(0xFC09C24C))
#define FLEXCAN2_BUFDATA47_29      (*(vuint32_t *)(0xFC09C25C))
#define FLEXCAN2_BUFDATA47_30      (*(vuint32_t *)(0xFC09C26C))
#define FLEXCAN2_BUFDATA47_31      (*(vuint32_t *)(0xFC09C27C))
#define FLEXCAN2_BUFDATA47_(x)     (*(vuint32_t *)(0xFC09C08C+((x)*0x010)))
#define FLEXCAN3_MCR               (*(vuint32_t *)(0xFC0A0000)) /* MCR - Module Configuration Register */
#define FLEXCAN3_CTRL              (*(vuint32_t *)(0xFC0A0004)) /* CTRL - Control Register */
#define FLEXCAN3_TIMER             (*(vuint32_t *)(0xFC0A0008))
#define FLEXCAN3_RXGMASK           (*(vuint32_t *)(0xFC0A0010))
#define FLEXCAN3_RX14MASK          (*(vuint32_t *)(0xFC0A0014))
#define FLEXCAN3_RX15MASK          (*(vuint32_t *)(0xFC0A0018))
#define FLEXCAN3_ECR               (*(vuint32_t *)(0xFC0A001C)) /* ECR - Error Counter Register */
#define FLEXCAN3_ESR               (*(vuint32_t *)(0xFC0A0020)) /* ESR - Error and Status Register */
#define FLEXCAN3_IMASK             (*(vuint32_t *)(0xFC0A0028))
#define FLEXCAN3_IFLAG             (*(vuint32_t *)(0xFC0A0030))
#define FLEXCAN3_BUFCS0            (*(vuint32_t *)(0xFC0A0080))
#define FLEXCAN3_BUFCS1            (*(vuint32_t *)(0xFC0A0090))
#define FLEXCAN3_BUFCS2            (*(vuint32_t *)(0xFC0A00A0))
#define FLEXCAN3_BUFCS3            (*(vuint32_t *)(0xFC0A00B0))
#define FLEXCAN3_BUFCS4            (*(vuint32_t *)(0xFC0A00C0))
#define FLEXCAN3_BUFCS5            (*(vuint32_t *)(0xFC0A00D0))
#define FLEXCAN3_BUFCS6            (*(vuint32_t *)(0xFC0A00E0))
#define FLEXCAN3_BUFCS7            (*(vuint32_t *)(0xFC0A00F0))
#define FLEXCAN3_BUFCS8            (*(vuint32_t *)(0xFC0A0100))
#define FLEXCAN3_BUFCS9            (*(vuint32_t *)(0xFC0A0110))
#define FLEXCAN3_BUFCS10           (*(vuint32_t *)(0xFC0A0120))
#define FLEXCAN3_BUFCS11           (*(vuint32_t *)(0xFC0A0130))
#define FLEXCAN3_BUFCS12           (*(vuint32_t *)(0xFC0A0140))
#define FLEXCAN3_BUFCS13           (*(vuint32_t *)(0xFC0A0150))
#define FLEXCAN3_BUFCS14           (*(vuint32_t *)(0xFC0A0160))
#define FLEXCAN3_BUFCS15           (*(vuint32_t *)(0xFC0A0170))
#define FLEXCAN3_BUFCS16           (*(vuint32_t *)(0xFC0A0180))
#define FLEXCAN3_BUFCS17           (*(vuint32_t *)(0xFC0A0190))
#define FLEXCAN3_BUFCS18           (*(vuint32_t *)(0xFC0A01A0))
#define FLEXCAN3_BUFCS19           (*(vuint32_t *)(0xFC0A01B0))
#define FLEXCAN3_BUFCS20           (*(vuint32_t *)(0xFC0A01C0))
#define FLEXCAN3_BUFCS21           (*(vuint32_t *)(0xFC0A01D0))
#define FLEXCAN3_BUFCS22           (*(vuint32_t *)(0xFC0A01E0))
#define FLEXCAN3_BUFCS23           (*(vuint32_t *)(0xFC0A01F0))
#define FLEXCAN3_BUFCS24           (*(vuint32_t *)(0xFC0A0200))
#define FLEXCAN3_BUFCS25           (*(vuint32_t *)(0xFC0A0210))
#define FLEXCAN3_BUFCS26           (*(vuint32_t *)(0xFC0A0220))
#define FLEXCAN3_BUFCS27           (*(vuint32_t *)(0xFC0A0230))
#define FLEXCAN3_BUFCS28           (*(vuint32_t *)(0xFC0A0240))
#define FLEXCAN3_BUFCS29           (*(vuint32_t *)(0xFC0A0250))
#define FLEXCAN3_BUFCS30           (*(vuint32_t *)(0xFC0A0260))
#define FLEXCAN3_BUFCS31           (*(vuint32_t *)(0xFC0A0270))
#define FLEXCAN3_BUFCS(x)          (*(vuint32_t *)(0xFC0A0080+((x)*0x010)))
#define FLEXCAN3_BUFID0            (*(vuint32_t *)(0xFC0A0084))
#define FLEXCAN3_BUFID1            (*(vuint32_t *)(0xFC0A0094))
#define FLEXCAN3_BUFID2            (*(vuint32_t *)(0xFC0A00A4))
#define FLEXCAN3_BUFID3            (*(vuint32_t *)(0xFC0A00B4))
#define FLEXCAN3_BUFID4            (*(vuint32_t *)(0xFC0A00C4))
#define FLEXCAN3_BUFID5            (*(vuint32_t *)(0xFC0A00D4))
#define FLEXCAN3_BUFID6            (*(vuint32_t *)(0xFC0A00E4))
#define FLEXCAN3_BUFID7            (*(vuint32_t *)(0xFC0A00F4))
#define FLEXCAN3_BUFID8            (*(vuint32_t *)(0xFC0A0104))
#define FLEXCAN3_BUFID9            (*(vuint32_t *)(0xFC0A0114))
#define FLEXCAN3_BUFID10           (*(vuint32_t *)(0xFC0A0124))
#define FLEXCAN3_BUFID11           (*(vuint32_t *)(0xFC0A0134))
#define FLEXCAN3_BUFID12           (*(vuint32_t *)(0xFC0A0144))
#define FLEXCAN3_BUFID13           (*(vuint32_t *)(0xFC0A0154))
#define FLEXCAN3_BUFID14           (*(vuint32_t *)(0xFC0A0164))
#define FLEXCAN3_BUFID15           (*(vuint32_t *)(0xFC0A0174))
#define FLEXCAN3_BUFID16           (*(vuint32_t *)(0xFC0A0184))
#define FLEXCAN3_BUFID17           (*(vuint32_t *)(0xFC0A0194))
#define FLEXCAN3_BUFID18           (*(vuint32_t *)(0xFC0A01A4))
#define FLEXCAN3_BUFID19           (*(vuint32_t *)(0xFC0A01B4))
#define FLEXCAN3_BUFID20           (*(vuint32_t *)(0xFC0A01C4))
#define FLEXCAN3_BUFID21           (*(vuint32_t *)(0xFC0A01D4))
#define FLEXCAN3_BUFID22           (*(vuint32_t *)(0xFC0A01E4))
#define FLEXCAN3_BUFID23           (*(vuint32_t *)(0xFC0A01F4))
#define FLEXCAN3_BUFID24           (*(vuint32_t *)(0xFC0A0204))
#define FLEXCAN3_BUFID25           (*(vuint32_t *)(0xFC0A0214))
#define FLEXCAN3_BUFID26           (*(vuint32_t *)(0xFC0A0224))
#define FLEXCAN3_BUFID27           (*(vuint32_t *)(0xFC0A0234))
#define FLEXCAN3_BUFID28           (*(vuint32_t *)(0xFC0A0244))
#define FLEXCAN3_BUFID29           (*(vuint32_t *)(0xFC0A0254))
#define FLEXCAN3_BUFID30           (*(vuint32_t *)(0xFC0A0264))
#define FLEXCAN3_BUFID31           (*(vuint32_t *)(0xFC0A0274))
#define FLEXCAN3_BUFID(x)          (*(vuint32_t *)(0xFC0A0084+((x)*0x010)))
#define FLEXCAN3_BUFDATA03_0       (*(vuint32_t *)(0xFC0A0088))
#define FLEXCAN3_BUFDATA03_1       (*(vuint32_t *)(0xFC0A0098))
#define FLEXCAN3_BUFDATA03_2       (*(vuint32_t *)(0xFC0A00A8))
#define FLEXCAN3_BUFDATA03_3       (*(vuint32_t *)(0xFC0A00B8))
#define FLEXCAN3_BUFDATA03_4       (*(vuint32_t *)(0xFC0A00C8))
#define FLEXCAN3_BUFDATA03_5       (*(vuint32_t *)(0xFC0A00D8))
#define FLEXCAN3_BUFDATA03_6       (*(vuint32_t *)(0xFC0A00E8))
#define FLEXCAN3_BUFDATA03_7       (*(vuint32_t *)(0xFC0A00F8))
#define FLEXCAN3_BUFDATA03_8       (*(vuint32_t *)(0xFC0A0108))
#define FLEXCAN3_BUFDATA03_9       (*(vuint32_t *)(0xFC0A0118))
#define FLEXCAN3_BUFDATA03_10      (*(vuint32_t *)(0xFC0A0128))
#define FLEXCAN3_BUFDATA03_11      (*(vuint32_t *)(0xFC0A0138))
#define FLEXCAN3_BUFDATA03_12      (*(vuint32_t *)(0xFC0A0148))
#define FLEXCAN3_BUFDATA03_13      (*(vuint32_t *)(0xFC0A0158))
#define FLEXCAN3_BUFDATA03_14      (*(vuint32_t *)(0xFC0A0168))
#define FLEXCAN3_BUFDATA03_15      (*(vuint32_t *)(0xFC0A0178))
#define FLEXCAN3_BUFDATA03_16      (*(vuint32_t *)(0xFC0A0188))
#define FLEXCAN3_BUFDATA03_17      (*(vuint32_t *)(0xFC0A0198))
#define FLEXCAN3_BUFDATA03_18      (*(vuint32_t *)(0xFC0A01A8))
#define FLEXCAN3_BUFDATA03_19      (*(vuint32_t *)(0xFC0A01B8))
#define FLEXCAN3_BUFDATA03_20      (*(vuint32_t *)(0xFC0A01C8))
#define FLEXCAN3_BUFDATA03_21      (*(vuint32_t *)(0xFC0A01D8))
#define FLEXCAN3_BUFDATA03_22      (*(vuint32_t *)(0xFC0A01E8))
#define FLEXCAN3_BUFDATA03_23      (*(vuint32_t *)(0xFC0A01F8))
#define FLEXCAN3_BUFDATA03_24      (*(vuint32_t *)(0xFC0A0208))
#define FLEXCAN3_BUFDATA03_25      (*(vuint32_t *)(0xFC0A0218))
#define FLEXCAN3_BUFDATA03_26      (*(vuint32_t *)(0xFC0A0228))
#define FLEXCAN3_BUFDATA03_27      (*(vuint32_t *)(0xFC0A0238))
#define FLEXCAN3_BUFDATA03_28      (*(vuint32_t *)(0xFC0A0248))
#define FLEXCAN3_BUFDATA03_29      (*(vuint32_t *)(0xFC0A0258))
#define FLEXCAN3_BUFDATA03_30      (*(vuint32_t *)(0xFC0A0268))
#define FLEXCAN3_BUFDATA03_31      (*(vuint32_t *)(0xFC0A0278))
#define FLEXCAN3_BUFDATA03_(x)     (*(vuint32_t *)(0xFC0A0088+((x)*0x010)))
#define FLEXCAN3_BUFDATA47_0       (*(vuint32_t *)(0xFC0A008C))
#define FLEXCAN3_BUFDATA47_1       (*(vuint32_t *)(0xFC0A009C))
#define FLEXCAN3_BUFDATA47_2       (*(vuint32_t *)(0xFC0A00AC))
#define FLEXCAN3_BUFDATA47_3       (*(vuint32_t *)(0xFC0A00BC))
#define FLEXCAN3_BUFDATA47_4       (*(vuint32_t *)(0xFC0A00CC))
#define FLEXCAN3_BUFDATA47_5       (*(vuint32_t *)(0xFC0A00DC))
#define FLEXCAN3_BUFDATA47_6       (*(vuint32_t *)(0xFC0A00EC))
#define FLEXCAN3_BUFDATA47_7       (*(vuint32_t *)(0xFC0A00FC))
#define FLEXCAN3_BUFDATA47_8       (*(vuint32_t *)(0xFC0A010C))
#define FLEXCAN3_BUFDATA47_9       (*(vuint32_t *)(0xFC0A011C))
#define FLEXCAN3_BUFDATA47_10      (*(vuint32_t *)(0xFC0A012C))
#define FLEXCAN3_BUFDATA47_11      (*(vuint32_t *)(0xFC0A013C))
#define FLEXCAN3_BUFDATA47_12      (*(vuint32_t *)(0xFC0A014C))
#define FLEXCAN3_BUFDATA47_13      (*(vuint32_t *)(0xFC0A015C))
#define FLEXCAN3_BUFDATA47_14      (*(vuint32_t *)(0xFC0A016C))
#define FLEXCAN3_BUFDATA47_15      (*(vuint32_t *)(0xFC0A017C))
#define FLEXCAN3_BUFDATA47_16      (*(vuint32_t *)(0xFC0A018C))
#define FLEXCAN3_BUFDATA47_17      (*(vuint32_t *)(0xFC0A019C))
#define FLEXCAN3_BUFDATA47_18      (*(vuint32_t *)(0xFC0A01AC))
#define FLEXCAN3_BUFDATA47_19      (*(vuint32_t *)(0xFC0A01BC))
#define FLEXCAN3_BUFDATA47_20      (*(vuint32_t *)(0xFC0A01CC))
#define FLEXCAN3_BUFDATA47_21      (*(vuint32_t *)(0xFC0A01DC))
#define FLEXCAN3_BUFDATA47_22      (*(vuint32_t *)(0xFC0A01EC))
#define FLEXCAN3_BUFDATA47_23      (*(vuint32_t *)(0xFC0A01FC))
#define FLEXCAN3_BUFDATA47_24      (*(vuint32_t *)(0xFC0A020C))
#define FLEXCAN3_BUFDATA47_25      (*(vuint32_t *)(0xFC0A021C))
#define FLEXCAN3_BUFDATA47_26      (*(vuint32_t *)(0xFC0A022C))
#define FLEXCAN3_BUFDATA47_27      (*(vuint32_t *)(0xFC0A023C))
#define FLEXCAN3_BUFDATA47_28      (*(vuint32_t *)(0xFC0A024C))
#define FLEXCAN3_BUFDATA47_29      (*(vuint32_t *)(0xFC0A025C))
#define FLEXCAN3_BUFDATA47_30      (*(vuint32_t *)(0xFC0A026C))
#define FLEXCAN3_BUFDATA47_31      (*(vuint32_t *)(0xFC0A027C))
#define FLEXCAN3_BUFDATA47_(x)     (*(vuint32_t *)(0xFC0A008C+((x)*0x010)))
#define FLEXCAN_MCR(x)             (*(vuint32_t *)(0xFC094000+((x)*0x4000)))    /* MCR - Module Configuration Register */
#define FLEXCAN_CTRL(x)            (*(vuint32_t *)(0xFC094004+((x)*0x4000)))    /* CTRL - Control Register */
#define FLEXCAN_TIMER(x)           (*(vuint32_t *)(0xFC094008+((x)*0x4000)))
#define FLEXCAN_RXGMASK(x)         (*(vuint32_t *)(0xFC094010+((x)*0x4000)))
#define FLEXCAN_RX14MASK(x)        (*(vuint32_t *)(0xFC094014+((x)*0x4000)))
#define FLEXCAN_RX15MASK(x)        (*(vuint32_t *)(0xFC094018+((x)*0x4000)))
#define FLEXCAN_ECR(x)             (*(vuint32_t *)(0xFC09401C+((x)*0x4000)))    /* ECR - Error Counter Register */
#define FLEXCAN_ESR(x)             (*(vuint32_t *)(0xFC094020+((x)*0x4000)))    /* ESR - Error and Status Register */
#define FLEXCAN_IMASK(x)           (*(vuint32_t *)(0xFC094028+((x)*0x4000)))
#define FLEXCAN_IFLAG(x)           (*(vuint32_t *)(0xFC094030+((x)*0x4000)))
#define FLEXCAN_BUFCS0(x)          (*(vuint32_t *)(0xFC094080+((x)*0x4000)))
#define FLEXCAN_BUFCS1(x)          (*(vuint32_t *)(0xFC094090+((x)*0x4000)))
#define FLEXCAN_BUFCS2(x)          (*(vuint32_t *)(0xFC0940A0+((x)*0x4000)))
#define FLEXCAN_BUFCS3(x)          (*(vuint32_t *)(0xFC0940B0+((x)*0x4000)))
#define FLEXCAN_BUFCS4(x)          (*(vuint32_t *)(0xFC0940C0+((x)*0x4000)))
#define FLEXCAN_BUFCS5(x)          (*(vuint32_t *)(0xFC0940D0+((x)*0x4000)))
#define FLEXCAN_BUFCS6(x)          (*(vuint32_t *)(0xFC0940E0+((x)*0x4000)))
#define FLEXCAN_BUFCS7(x)          (*(vuint32_t *)(0xFC0940F0+((x)*0x4000)))
#define FLEXCAN_BUFCS8(x)          (*(vuint32_t *)(0xFC094100+((x)*0x4000)))
#define FLEXCAN_BUFCS9(x)          (*(vuint32_t *)(0xFC094110+((x)*0x4000)))
#define FLEXCAN_BUFCS10(x)         (*(vuint32_t *)(0xFC094120+((x)*0x4000)))
#define FLEXCAN_BUFCS11(x)         (*(vuint32_t *)(0xFC094130+((x)*0x4000)))
#define FLEXCAN_BUFCS12(x)         (*(vuint32_t *)(0xFC094140+((x)*0x4000)))
#define FLEXCAN_BUFCS13(x)         (*(vuint32_t *)(0xFC094150+((x)*0x4000)))
#define FLEXCAN_BUFCS14(x)         (*(vuint32_t *)(0xFC094160+((x)*0x4000)))
#define FLEXCAN_BUFCS15(x)         (*(vuint32_t *)(0xFC094170+((x)*0x4000)))
#define FLEXCAN_BUFCS16(x)         (*(vuint32_t *)(0xFC094180+((x)*0x4000)))
#define FLEXCAN_BUFCS17(x)         (*(vuint32_t *)(0xFC094190+((x)*0x4000)))
#define FLEXCAN_BUFCS18(x)         (*(vuint32_t *)(0xFC0941A0+((x)*0x4000)))
#define FLEXCAN_BUFCS19(x)         (*(vuint32_t *)(0xFC0941B0+((x)*0x4000)))
#define FLEXCAN_BUFCS20(x)         (*(vuint32_t *)(0xFC0941C0+((x)*0x4000)))
#define FLEXCAN_BUFCS21(x)         (*(vuint32_t *)(0xFC0941D0+((x)*0x4000)))
#define FLEXCAN_BUFCS22(x)         (*(vuint32_t *)(0xFC0941E0+((x)*0x4000)))
#define FLEXCAN_BUFCS23(x)         (*(vuint32_t *)(0xFC0941F0+((x)*0x4000)))
#define FLEXCAN_BUFCS24(x)         (*(vuint32_t *)(0xFC094200+((x)*0x4000)))
#define FLEXCAN_BUFCS25(x)         (*(vuint32_t *)(0xFC094210+((x)*0x4000)))
#define FLEXCAN_BUFCS26(x)         (*(vuint32_t *)(0xFC094220+((x)*0x4000)))
#define FLEXCAN_BUFCS27(x)         (*(vuint32_t *)(0xFC094230+((x)*0x4000)))
#define FLEXCAN_BUFCS28(x)         (*(vuint32_t *)(0xFC094240+((x)*0x4000)))
#define FLEXCAN_BUFCS29(x)         (*(vuint32_t *)(0xFC094250+((x)*0x4000)))
#define FLEXCAN_BUFCS30(x)         (*(vuint32_t *)(0xFC094260+((x)*0x4000)))
#define FLEXCAN_BUFCS31(x)         (*(vuint32_t *)(0xFC094270+((x)*0x4000)))
#define FLEXCAN_BUFID0(x)          (*(vuint32_t *)(0xFC094084+((x)*0x4000)))
#define FLEXCAN_BUFID1(x)          (*(vuint32_t *)(0xFC094094+((x)*0x4000)))
#define FLEXCAN_BUFID2(x)          (*(vuint32_t *)(0xFC0940A4+((x)*0x4000)))
#define FLEXCAN_BUFID3(x)          (*(vuint32_t *)(0xFC0940B4+((x)*0x4000)))
#define FLEXCAN_BUFID4(x)          (*(vuint32_t *)(0xFC0940C4+((x)*0x4000)))
#define FLEXCAN_BUFID5(x)          (*(vuint32_t *)(0xFC0940D4+((x)*0x4000)))
#define FLEXCAN_BUFID6(x)          (*(vuint32_t *)(0xFC0940E4+((x)*0x4000)))
#define FLEXCAN_BUFID7(x)          (*(vuint32_t *)(0xFC0940F4+((x)*0x4000)))
#define FLEXCAN_BUFID8(x)          (*(vuint32_t *)(0xFC094104+((x)*0x4000)))
#define FLEXCAN_BUFID9(x)          (*(vuint32_t *)(0xFC094114+((x)*0x4000)))
#define FLEXCAN_BUFID10(x)         (*(vuint32_t *)(0xFC094124+((x)*0x4000)))
#define FLEXCAN_BUFID11(x)         (*(vuint32_t *)(0xFC094134+((x)*0x4000)))
#define FLEXCAN_BUFID12(x)         (*(vuint32_t *)(0xFC094144+((x)*0x4000)))
#define FLEXCAN_BUFID13(x)         (*(vuint32_t *)(0xFC094154+((x)*0x4000)))
#define FLEXCAN_BUFID14(x)         (*(vuint32_t *)(0xFC094164+((x)*0x4000)))
#define FLEXCAN_BUFID15(x)         (*(vuint32_t *)(0xFC094174+((x)*0x4000)))
#define FLEXCAN_BUFID16(x)         (*(vuint32_t *)(0xFC094184+((x)*0x4000)))
#define FLEXCAN_BUFID17(x)         (*(vuint32_t *)(0xFC094194+((x)*0x4000)))
#define FLEXCAN_BUFID18(x)         (*(vuint32_t *)(0xFC0941A4+((x)*0x4000)))
#define FLEXCAN_BUFID19(x)         (*(vuint32_t *)(0xFC0941B4+((x)*0x4000)))
#define FLEXCAN_BUFID20(x)         (*(vuint32_t *)(0xFC0941C4+((x)*0x4000)))
#define FLEXCAN_BUFID21(x)         (*(vuint32_t *)(0xFC0941D4+((x)*0x4000)))
#define FLEXCAN_BUFID22(x)         (*(vuint32_t *)(0xFC0941E4+((x)*0x4000)))
#define FLEXCAN_BUFID23(x)         (*(vuint32_t *)(0xFC0941F4+((x)*0x4000)))
#define FLEXCAN_BUFID24(x)         (*(vuint32_t *)(0xFC094204+((x)*0x4000)))
#define FLEXCAN_BUFID25(x)         (*(vuint32_t *)(0xFC094214+((x)*0x4000)))
#define FLEXCAN_BUFID26(x)         (*(vuint32_t *)(0xFC094224+((x)*0x4000)))
#define FLEXCAN_BUFID27(x)         (*(vuint32_t *)(0xFC094234+((x)*0x4000)))
#define FLEXCAN_BUFID28(x)         (*(vuint32_t *)(0xFC094244+((x)*0x4000)))
#define FLEXCAN_BUFID29(x)         (*(vuint32_t *)(0xFC094254+((x)*0x4000)))
#define FLEXCAN_BUFID30(x)         (*(vuint32_t *)(0xFC094264+((x)*0x4000)))
#define FLEXCAN_BUFID31(x)         (*(vuint32_t *)(0xFC094274+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_0(x)     (*(vuint32_t *)(0xFC094088+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_1(x)     (*(vuint32_t *)(0xFC094098+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_2(x)     (*(vuint32_t *)(0xFC0940A8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_3(x)     (*(vuint32_t *)(0xFC0940B8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_4(x)     (*(vuint32_t *)(0xFC0940C8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_5(x)     (*(vuint32_t *)(0xFC0940D8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_6(x)     (*(vuint32_t *)(0xFC0940E8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_7(x)     (*(vuint32_t *)(0xFC0940F8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_8(x)     (*(vuint32_t *)(0xFC094108+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_9(x)     (*(vuint32_t *)(0xFC094118+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_10(x)    (*(vuint32_t *)(0xFC094128+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_11(x)    (*(vuint32_t *)(0xFC094138+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_12(x)    (*(vuint32_t *)(0xFC094148+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_13(x)    (*(vuint32_t *)(0xFC094158+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_14(x)    (*(vuint32_t *)(0xFC094168+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_15(x)    (*(vuint32_t *)(0xFC094178+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_16(x)    (*(vuint32_t *)(0xFC094188+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_17(x)    (*(vuint32_t *)(0xFC094198+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_18(x)    (*(vuint32_t *)(0xFC0941A8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_19(x)    (*(vuint32_t *)(0xFC0941B8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_20(x)    (*(vuint32_t *)(0xFC0941C8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_21(x)    (*(vuint32_t *)(0xFC0941D8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_22(x)    (*(vuint32_t *)(0xFC0941E8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_23(x)    (*(vuint32_t *)(0xFC0941F8+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_24(x)    (*(vuint32_t *)(0xFC094208+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_25(x)    (*(vuint32_t *)(0xFC094218+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_26(x)    (*(vuint32_t *)(0xFC094228+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_27(x)    (*(vuint32_t *)(0xFC094238+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_28(x)    (*(vuint32_t *)(0xFC094248+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_29(x)    (*(vuint32_t *)(0xFC094258+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_30(x)    (*(vuint32_t *)(0xFC094268+((x)*0x4000)))
#define FLEXCAN_BUFDATA03_31(x)    (*(vuint32_t *)(0xFC094278+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_0(x)     (*(vuint32_t *)(0xFC09408C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_1(x)     (*(vuint32_t *)(0xFC09409C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_2(x)     (*(vuint32_t *)(0xFC0940AC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_3(x)     (*(vuint32_t *)(0xFC0940BC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_4(x)     (*(vuint32_t *)(0xFC0940CC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_5(x)     (*(vuint32_t *)(0xFC0940DC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_6(x)     (*(vuint32_t *)(0xFC0940EC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_7(x)     (*(vuint32_t *)(0xFC0940FC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_8(x)     (*(vuint32_t *)(0xFC09410C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_9(x)     (*(vuint32_t *)(0xFC09411C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_10(x)    (*(vuint32_t *)(0xFC09412C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_11(x)    (*(vuint32_t *)(0xFC09413C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_12(x)    (*(vuint32_t *)(0xFC09414C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_13(x)    (*(vuint32_t *)(0xFC09415C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_14(x)    (*(vuint32_t *)(0xFC09416C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_15(x)    (*(vuint32_t *)(0xFC09417C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_16(x)    (*(vuint32_t *)(0xFC09418C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_17(x)    (*(vuint32_t *)(0xFC09419C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_18(x)    (*(vuint32_t *)(0xFC0941AC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_19(x)    (*(vuint32_t *)(0xFC0941BC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_20(x)    (*(vuint32_t *)(0xFC0941CC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_21(x)    (*(vuint32_t *)(0xFC0941DC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_22(x)    (*(vuint32_t *)(0xFC0941EC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_23(x)    (*(vuint32_t *)(0xFC0941FC+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_24(x)    (*(vuint32_t *)(0xFC09420C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_25(x)    (*(vuint32_t *)(0xFC09421C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_26(x)    (*(vuint32_t *)(0xFC09422C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_27(x)    (*(vuint32_t *)(0xFC09423C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_28(x)    (*(vuint32_t *)(0xFC09424C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_29(x)    (*(vuint32_t *)(0xFC09425C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_30(x)    (*(vuint32_t *)(0xFC09426C+((x)*0x4000)))
#define FLEXCAN_BUFDATA47_31(x)    (*(vuint32_t *)(0xFC09427C+((x)*0x4000)))

/* Bit definitions and macros for FLEXCAN_MCR */
#define FLEXCAN_MAXMB(x)           (((x)&0x0000003F)<<0)    /*  Maximum No of Msg Buffers */
#define FLEXCAN_BCC                (0x00010000)   /*  Backwards Compatibility Configuration */
#define FLEXCAN_DOZE               (0x00040000)   /*  Doze Mode Enable */
#define FLEXCAN_WAK_SRC            (0x00080000)   /*  Wake Up Source */
#define FLEXCAN_LPM_ACK            (0x00100000)   /*  Low Power Mode Acknowledge */
#define FLEXCAN_SLF_WAK            (0x00400000)   /*  Self Wake Up */
#define FLEXCAN_SUPV               (0x00800000)   /*  Supervisor Mode */
#define FLEXCAN_FRZ_ACK            (0x01000000)   /*  Freeze Mode Acknowledge */
#define FLEXCAN_SOFT_RST           (0x02000000)   /*  Soft Reset */
#define FLEXCAN_WAK_MSK            (0x04000000)   /*  Wake Up Interrupt Mask */
#define FLEXCAN_NOT_RDY            (0x08000000)   /*  FlexCAN Not Ready */
#define FLEXCAN_HALT               (0x10000000)   /*  Halt FlexCAN */
#define FLEXCAN_FRZ                (0x40000000)   /*  Freeze Enable */
#define FLEXCAN_MDIS               (0x80000000)   /*  Module Disable */

/* Bit definitions and macros for FLEXCAN_CTRL */
#define FLEXCAN_PROPSEG(x)         (((x)&0x00000007)<<0)    /*  Propagation Segment */
#define FLEXCAN_LOM                (0x00000008)   /*  Listen-Only Mode */
#define FLEXCAN_LBUF               (0x00000010)   /*  Lowest Buffer TX'ed First */
#define FLEXCAN_TSYN               (0x00000020)   /*  Timer Sync Mode */
#define FLEXCAN_BOFF_REC           (0x00000040)   /*  Bus-Off Recovery Mode */
#define FLEXCAN_SMP                (0x00000080)   /*  Sampling Mode */
#define FLEXCAN_LPB                (0x00001000)   /*  Loop Back */
#define FLEXCAN_CLK_SRC            (0x00002000)   /*  CAN Engine Clock Source */
#define FLEXCAN_ERR_MSK            (0x00004000)   /*  Error Mask */
#define FLEXCAN_BOFF_MSK           (0x00008000)   /*  Bus Off Mask */
#define FLEXCAN_PSEG2(x)           (((x)&0x00000007)<<16)   /*  Phase Segment 2 */
#define FLEXCAN_PSEG1(x)           (((x)&0x00000007)<<19)   /*  Phase Segment 1 */
#define FLEXCAN_RJW(x)             (((x)&0x00000003)<<22)   /*  Resync Jump Width */
#define FLEXCAN_PRESDIV(x)         (((x)&0x000000FF)<<24)   /*  Prescaler Division Factor */

/* Bit definitions and macros for FLEXCAN_TIMER */
#define FLEXCAN_TMR(x)             (((x)&0x0000FFFF)<<0)    /*  Timer */

/* Bit definitions and macros for FLEXCAN_RXGMASK */
#define FLEXCAN_MI(x)              (((x)&0x1FFFFFFF)<<0)    /*  Standard ID Mask Bits */

/* Bit definitions and macros for FLEXCAN_ECR */
#define FLEXCAN_TX_ERR_COUNTER(x)  (((x)&0x000000FF)<<0)    /*  Transmit Error Counter */
#define FLEXCAN_RX_ERR_COUNTER(x)  (((x)&0x000000FF)<<8)    /*  Receive Error Counter */

/* Bit definitions and macros for FLEXCAN_ESR */
#define FLEXCAN_WAK_INT            (0x00000001)   /*  Wake-Up Interrupt */
#define FLEXCAN_ERR_INT            (0x00000002)   /*  Error Interrupt */
#define FLEXCAN_BOFF_INT           (0x00000004)   /*  Bus Off Interrupt */
#define FLEXCAN_FLT_CONF(x)        (((x)&0x00000003)<<4)    /*  Fault Confinement State */
#define FLEXCAN_TXRX               (0x00000040)   /*  FlexCAN status (tx/rx) */
#define FLEXCAN_IDLE               (0x00000080)   /*  CAN bus IDLE state */
#define FLEXCAN_RX_WRN             (0x00000100)   /*  Rx Error Counter */
#define FLEXCAN_TX_WRN             (0x00000200)   /*  TX Error Counter */
#define FLEXCAN_STF_ERR            (0x00000400)   /*  Stuffing Error */
#define FLEXCAN_FRM_ERR            (0x00000800)   /*  Form Error */
#define FLEXCAN_CRC_ERR            (0x00001000)   /*  Cyclic Redundancy Code Error */
#define FLEXCAN_ACK_ERR            (0x00002000)   /*  Acknowledge Error */
#define FLEXCAN_BIT0_ERR           (0x00004000)   /*  Bit0 Error */
#define FLEXCAN_BIT1_ERR           (0x00008000)   /*  Bit1 Error */

/* Bit definitions and macros for FLEXCAN_IMASK */
#define FLEXCAN_BUF0M              (0x00000001)   /*  Message buffer mask 0 */
#define FLEXCAN_BUF1M              (0x00000002)   /*  Message buffer mask 1 */
#define FLEXCAN_BUF2M              (0x00000004)   /*  Message buffer mask 2 */
#define FLEXCAN_BUF3M              (0x00000008)   /*  Message buffer mask 3 */
#define FLEXCAN_BUF4M              (0x00000010)   /*  Message buffer mask 4 */
#define FLEXCAN_BUF5M              (0x00000020)   /*  Message buffer mask 5 */
#define FLEXCAN_BUF6M              (0x00000040)   /*  Message buffer mask 6 */
#define FLEXCAN_BUF7M              (0x00000080)   /*  Message buffer mask 7 */
#define FLEXCAN_BUF8M              (0x00000100)   /*  Message buffer mask 8 */
#define FLEXCAN_BUF9M              (0x00000200)   /*  Message buffer mask 9 */
#define FLEXCAN_BUF10M             (0x00000400)   /*  Message buffer mask 10 */
#define FLEXCAN_BUF11M             (0x00000800)   /*  Message buffer mask 11 */
#define FLEXCAN_BUF12M             (0x00001000)   /*  Message buffer mask 12 */
#define FLEXCAN_BUF13M             (0x00002000)   /*  Message buffer mask 13 */
#define FLEXCAN_BUF14M             (0x00004000)   /*  Message buffer mask 14 */
#define FLEXCAN_BUF15M             (0x00008000)   /*  Message buffer mask 15 */
#define FLEXCAN_BUF16M             (0x00010000)   /*  Message buffer mask 16 */
#define FLEXCAN_BUF17M             (0x00020000)   /*  Message buffer mask 17 */
#define FLEXCAN_BUF18M             (0x00040000)   /*  Message buffer mask 18 */
#define FLEXCAN_BUF19M             (0x00080000)   /*  Message buffer mask 19 */
#define FLEXCAN_BUF20M             (0x00100000)   /*  Message buffer mask 20 */
#define FLEXCAN_BUF21M             (0x00200000)   /*  Message buffer mask 21 */
#define FLEXCAN_BUF22M             (0x00400000)   /*  Message buffer mask 22 */
#define FLEXCAN_BUF23M             (0x00800000)   /*  Message buffer mask 23 */
#define FLEXCAN_BUF24M             (0x01000000)   /*  Message buffer mask 24 */
#define FLEXCAN_BUF25M             (0x02000000)   /*  Message buffer mask 25 */
#define FLEXCAN_BUF26M             (0x04000000)   /*  Message buffer mask 26 */
#define FLEXCAN_BUF27M             (0x08000000)   /*  Message buffer mask 27 */
#define FLEXCAN_BUF28M             (0x10000000)   /*  Message buffer mask 28 */
#define FLEXCAN_BUF29M             (0x20000000)   /*  Message buffer mask 29 */
#define FLEXCAN_BUF30M             (0x40000000)   /*  Message buffer mask 30 */
#define FLEXCAN_BUF31M             (0x80000000)   /*  Message buffer mask 31 */

/* Bit definitions and macros for FLEXCAN_IFLAG */
#define FLEXCAN_BUF0I              (0x00000001)   /*  Message buffer int 0 */
#define FLEXCAN_BUF1I              (0x00000002)   /*  Message buffer int 1 */
#define FLEXCAN_BUF2I              (0x00000004)   /*  Message buffer int 2 */
#define FLEXCAN_BUF3I              (0x00000008)   /*  Message buffer int 3 */
#define FLEXCAN_BUF4I              (0x00000010)   /*  Message buffer int 4 */
#define FLEXCAN_BUF5I              (0x00000020)   /*  Message buffer int 5 */
#define FLEXCAN_BUF6I              (0x00000040)   /*  Message buffer int 6 */
#define FLEXCAN_BUF7I              (0x00000080)   /*  Message buffer int 7 */
#define FLEXCAN_BUF8I              (0x00000100)   /*  Message buffer int 8 */
#define FLEXCAN_BUF9I              (0x00000200)   /*  Message buffer int 9 */
#define FLEXCAN_BUF10I             (0x00000400)   /*  Message buffer int 10 */
#define FLEXCAN_BUF11I             (0x00000800)   /*  Message buffer int 11 */
#define FLEXCAN_BUF12I             (0x00001000)   /*  Message buffer int 12 */
#define FLEXCAN_BUF13I             (0x00002000)   /*  Message buffer int 13 */
#define FLEXCAN_BUF14I             (0x00004000)   /*  Message buffer int 14 */
#define FLEXCAN_BUF15I             (0x00008000)   /*  Message buffer int 15 */
#define FLEXCAN_BUF16I             (0x00010000)   /*  Message buffer int 16 */
#define FLEXCAN_BUF17I             (0x00020000)   /*  Message buffer int 17 */
#define FLEXCAN_BUF18I             (0x00040000)   /*  Message buffer int 18 */
#define FLEXCAN_BUF19I             (0x00080000)   /*  Message buffer int 19 */
#define FLEXCAN_BUF20I             (0x00100000)   /*  Message buffer int 20 */
#define FLEXCAN_BUF21I             (0x00200000)   /*  Message buffer int 21 */
#define FLEXCAN_BUF22I             (0x00400000)   /*  Message buffer int 22 */
#define FLEXCAN_BUF23I             (0x00800000)   /*  Message buffer int 23 */
#define FLEXCAN_BUF24I             (0x01000000)   /*  Message buffer int 24 */
#define FLEXCAN_BUF25I             (0x02000000)   /*  Message buffer int 25 */
#define FLEXCAN_BUF26I             (0x04000000)   /*  Message buffer int 26 */
#define FLEXCAN_BUF27I             (0x08000000)   /*  Message buffer int 27 */
#define FLEXCAN_BUF28I             (0x10000000)   /*  Message buffer int 28 */
#define FLEXCAN_BUF29I             (0x20000000)   /*  Message buffer int 29 */
#define FLEXCAN_BUF30I             (0x40000000)   /*  Message buffer int 30 */
#define FLEXCAN_BUF31I             (0x80000000)   /*  Message buffer int 31 */

/* Bit definitions and macros for FLEXCAN_BUFCSn */
#define FLEXCAN_TIMESTAMP(x)       (((x)&0x0000FFFF)<<0)    /*  Free-running Ctr Time Stamp    */
#define FLEXCAN_LENGTH(x)          (((x)&0x0000000F)<<16)   /*  Length of Data in bytes         */
#define FLEXCAN_RTR                (0x00100000)   /*  Remote Transmission Request     */
#define FLEXCAN_IDE                (0x00200000)   /*  ID Extended Bit                 */
#define FLEXCAN_SRR                (0x00400000)   /*  Substitute Remote Request       */
#define FLEXCAN_CODE(x)            (((x)&0x0000000F)<<24)   /*  Message Buffer Code             */

/*********************************************************************
*
* IIC Module (IIC)
*
*********************************************************************/

/* Register read/write macros */
#define IIC_IBAD                   (*(vuint8_t  *)(0xFC0AC000)) /* IBAD - IIC Bus Address Register */
#define IIC_IBFD                   (*(vuint8_t  *)(0xFC0AC001)) /* IBFD - IIC Bus Frequency Divider Register */
#define IIC_IBCR                   (*(vuint8_t  *)(0xFC0AC002)) /* IBCR - IIC-Bus Control Register */
#define IIC_IBSR                   (*(vuint8_t  *)(0xFC0AC003)) /* IBSR - IIC Bus Status Register */
#define IIC_IBDR                   (*(vuint8_t  *)(0xFC0AC004)) /* IBDR - IIC Bus Data I/O Register */

/* Bit definitions and macros for IIC_IBAD */
#define IIC_ADR1                   (0x02)         /*  Slave Address1 */
#define IIC_ADR2                   (0x04)         /*  Slave Address2 */
#define IIC_ADR3                   (0x08)         /*  Slave Address3 */
#define IIC_ADR4                   (0x10)         /*  Slave Address4 */
#define IIC_ADR5                   (0x20)         /*  Slave Address5 */
#define IIC_ADR6                   (0x40)         /*  Slave Address6 */
#define IIC_ADR7                   (0x80)         /*  Slave Address7 */

/* Bit definitions and macros for IIC_IBFD */
#define IIC_IBC0                   (0x01)         /*  I-Bus Clock Rate 0 */
#define IIC_IBC1                   (0x02)         /*  I-Bus Clock Rate 1 */
#define IIC_IBC2                   (0x04)         /*  I-Bus Clock Rate 2 */
#define IIC_IBC3                   (0x08)         /*  I-Bus Clock Rate 3 */
#define IIC_IBC4                   (0x10)         /*  I-Bus Clock Rate 4 */
#define IIC_IBC5                   (0x20)         /*  I-Bus Clock Rate 5 */
#define IIC_IBC6                   (0x40)         /*  I-Bus Clock Rate 6 */
#define IIC_IBC7                   (0x80)         /*  I-Bus Clock Rate 7 */

/* Bit definitions and macros for IIC_IBCR */
#define IIC_IBSDOZE                (0x01)         /*  I-Bus Interface Stop in DOZE mode */
#define IIC_DMAEN                  (0x02)         /*  DMA Enable */
#define IIC_RSTA                   (0x04)         /*  Repeat Start */
#define IIC_TXAK                   (0x08)         /*  Transmit Acknowledge enable */
#define IIC_TXRX                   (0x10)         /*  Transmit/Receive mode select bit */
#define IIC_MSSL                   (0x20)         /*  Master/Slave mode select bit */
#define IIC_IBIE                   (0x40)         /*  I-Bus Interrupt Enable */
#define IIC_IBDIS                  (0x80)         /*  I-Bus DISABLE */

/* Bit definitions and macros for IIC_IBSR */
#define IIC_RXAK                   (0x01)         /*  Received Acknowledge */
#define IIC_IBIF                   (0x02)         /*  I-Bus Interrupt */
#define IIC_SRW                    (0x04)         /*  Slave Read/Write */
#define IIC_IBAL                   (0x10)         /*  Arbitration Lost */
#define IIC_IBB                    (0x20)         /*  Bus busy bit */
#define IIC_IAAS                   (0x40)         /*  Addressed as a slave bit */
#define IIC_TCF                    (0x80)         /*  Data transferring bit */

/* Bit definitions and macros for IIC_IBDR */
#define IIC_D0                     (0x01)         /*  Data bit 0 */
#define IIC_D1                     (0x02)         /*  Data bit 1 */
#define IIC_D2                     (0x04)         /*  Data bit 2 */
#define IIC_D3                     (0x08)         /*  Data bit 3 */
#define IIC_D4                     (0x10)         /*  Data bit 4 */
#define IIC_D5                     (0x20)         /*  Data bit 5 */
#define IIC_D6                     (0x40)         /*  Data bit 6 */
#define IIC_D7                     (0x80)         /*  Data bit 7 */

/*********************************************************************
*
* INTC Module (INTC)
*
*********************************************************************/

/* Register read/write macros */
#define INTC_IPRH                  (*(vuint32_t *)(0xFC048000)) /* IPRH - Interrupt Pending Register High */
#define INTC_IPRL                  (*(vuint32_t *)(0xFC048004)) /* IPRL - Interrupt Pending Register Low */
#define INTC_IMRH                  (*(vuint32_t *)(0xFC048008)) /* IMRH - Interrupt Mask Register High */
#define INTC_IMRL                  (*(vuint32_t *)(0xFC04800C)) /* IMRL - Interrupt Mask Register Low */
#define INTC_IFRCH                 (*(vuint32_t *)(0xFC048010)) /* IFRCH Interrupt Force Register High */
#define INTC_IFRCL                 (*(vuint32_t *)(0xFC048014)) /* IFRCL - Interrupt Force Register Low */
#define INTC_ICONFIG               (*(vuint8_t  *)(0xFC04801B)) /* ICONFIG - Interrupt Configuration Register */
#define INTC_SIMR                  (*(vuint8_t  *)(0xFC04801C)) /* SIMR - Set Interrupt Mask Register */
#define INTC_CIMR                  (*(vuint8_t  *)(0xFC04801D)) /* CIMR - Clear Interrupt Mask Register */
#define INTC_CLMASK                (*(vuint8_t  *)(0xFC04801E)) /* CLMASK - Current Level Mask Register */
#define INTC_SLMASK                (*(vuint8_t  *)(0xFC04801F)) /* SLMASK - Saved Level Mask Register */
#define INTC_ICR0                  (*(vuint8_t  *)(0xFC048040)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR1                  (*(vuint8_t  *)(0xFC048041)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR2                  (*(vuint8_t  *)(0xFC048042)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR3                  (*(vuint8_t  *)(0xFC048043)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR4                  (*(vuint8_t  *)(0xFC048044)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR5                  (*(vuint8_t  *)(0xFC048045)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR6                  (*(vuint8_t  *)(0xFC048046)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR7                  (*(vuint8_t  *)(0xFC048047)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR8                  (*(vuint8_t  *)(0xFC048048)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR9                  (*(vuint8_t  *)(0xFC048049)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR10                 (*(vuint8_t  *)(0xFC04804A)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR11                 (*(vuint8_t  *)(0xFC04804B)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR12                 (*(vuint8_t  *)(0xFC04804C)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR13                 (*(vuint8_t  *)(0xFC04804D)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR14                 (*(vuint8_t  *)(0xFC04804E)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR15                 (*(vuint8_t  *)(0xFC04804F)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR16                 (*(vuint8_t  *)(0xFC048050)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR17                 (*(vuint8_t  *)(0xFC048051)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR18                 (*(vuint8_t  *)(0xFC048052)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR19                 (*(vuint8_t  *)(0xFC048053)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR20                 (*(vuint8_t  *)(0xFC048054)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR21                 (*(vuint8_t  *)(0xFC048055)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR22                 (*(vuint8_t  *)(0xFC048056)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR23                 (*(vuint8_t  *)(0xFC048057)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR24                 (*(vuint8_t  *)(0xFC048058)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR25                 (*(vuint8_t  *)(0xFC048059)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR26                 (*(vuint8_t  *)(0xFC04805A)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR27                 (*(vuint8_t  *)(0xFC04805B)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR28                 (*(vuint8_t  *)(0xFC04805C)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR29                 (*(vuint8_t  *)(0xFC04805D)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR30                 (*(vuint8_t  *)(0xFC04805E)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR31                 (*(vuint8_t  *)(0xFC04805F)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR32                 (*(vuint8_t  *)(0xFC048060)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR33                 (*(vuint8_t  *)(0xFC048061)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR34                 (*(vuint8_t  *)(0xFC048062)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR35                 (*(vuint8_t  *)(0xFC048063)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR36                 (*(vuint8_t  *)(0xFC048064)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR37                 (*(vuint8_t  *)(0xFC048065)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR38                 (*(vuint8_t  *)(0xFC048066)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR39                 (*(vuint8_t  *)(0xFC048067)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR40                 (*(vuint8_t  *)(0xFC048068)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR41                 (*(vuint8_t  *)(0xFC048069)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR42                 (*(vuint8_t  *)(0xFC04806A)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR43                 (*(vuint8_t  *)(0xFC04806B)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR44                 (*(vuint8_t  *)(0xFC04806C)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR45                 (*(vuint8_t  *)(0xFC04806D)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR46                 (*(vuint8_t  *)(0xFC04806E)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR47                 (*(vuint8_t  *)(0xFC04806F)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR48                 (*(vuint8_t  *)(0xFC048070)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR49                 (*(vuint8_t  *)(0xFC048071)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR50                 (*(vuint8_t  *)(0xFC048072)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR51                 (*(vuint8_t  *)(0xFC048073)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR52                 (*(vuint8_t  *)(0xFC048074)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR53                 (*(vuint8_t  *)(0xFC048075)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR54                 (*(vuint8_t  *)(0xFC048076)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR55                 (*(vuint8_t  *)(0xFC048077)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR56                 (*(vuint8_t  *)(0xFC048078)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR57                 (*(vuint8_t  *)(0xFC048079)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR58                 (*(vuint8_t  *)(0xFC04807A)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR59                 (*(vuint8_t  *)(0xFC04807B)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR60                 (*(vuint8_t  *)(0xFC04807C)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR61                 (*(vuint8_t  *)(0xFC04807D)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR62                 (*(vuint8_t  *)(0xFC04807E)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR63                 (*(vuint8_t  *)(0xFC04807F)) /* ICR[n] - Interrupt Control Registers */
#define INTC_ICR(x)                (*(vuint8_t  *)(0xFC048040+((x)*0x001))) /* ICR[n] - Interrupt Control Registers */
#define INTC_IRQIACK               (*(vuint8_t  *)(0xFC0480EC)) /* IRQIACK - IRQ Interrupt Acknowledge Register */
#define INTC_FIQIACK               (*(vuint8_t  *)(0xFC0480F0)) /* FIQIACK - FIQ Interrupt Acknowledge Register */

/* Bit definitions and macros for INTC_IPRH */
#define INTC_IPR32                 (0x00000001)   /*  Interrupt pending register 32 */
#define INTC_IPR33                 (0x00000002)   /*  Interrupt pending register 33 */
#define INTC_IPR34                 (0x00000004)   /*  Interrupt pending register 34 */
#define INTC_IPR35                 (0x00000008)   /*  Interrupt pending register 35 */
#define INTC_IPR36                 (0x00000010)   /*  Interrupt pending register 36 */
#define INTC_IPR37                 (0x00000020)   /*  Interrupt pending register 37 */
#define INTC_IPR38                 (0x00000040)   /*  Interrupt pending register 38 */
#define INTC_IPR39                 (0x00000080)   /*  Interrupt pending register 39 */
#define INTC_IPR40                 (0x00000100)   /*  Interrupt pending register 40 */
#define INTC_IPR41                 (0x00000200)   /*  Interrupt pending register 41 */
#define INTC_IPR42                 (0x00000400)   /*  Interrupt pending register 42 */
#define INTC_IPR43                 (0x00000800)   /*  Interrupt pending register 43 */
#define INTC_IPR44                 (0x00001000)   /*  Interrupt pending register 44 */
#define INTC_IPR45                 (0x00002000)   /*  Interrupt pending register 45 */
#define INTC_IPR46                 (0x00004000)   /*  Interrupt pending register 46 */
#define INTC_IPR47                 (0x00008000)   /*  Interrupt pending register 47 */
#define INTC_IPR48                 (0x00010000)   /*  Interrupt pending register 48 */
#define INTC_IPR49                 (0x00020000)   /*  Interrupt pending register 49 */
#define INTC_IPR50                 (0x00040000)   /*  Interrupt pending register 50 */
#define INTC_IPR51                 (0x00080000)   /*  Interrupt pending register 51 */
#define INTC_IPR52                 (0x00100000)   /*  Interrupt pending register 52 */
#define INTC_IPR53                 (0x00200000)   /*  Interrupt pending register 53 */
#define INTC_IPR54                 (0x00400000)   /*  Interrupt pending register 54 */
#define INTC_IPR55                 (0x00800000)   /*  Interrupt pending register 55 */
#define INTC_IPR56                 (0x01000000)   /*  Interrupt pending register 56 */
#define INTC_IPR57                 (0x02000000)   /*  Interrupt pending register 57 */
#define INTC_IPR58                 (0x04000000)   /*  Interrupt pending register 58 */
#define INTC_IPR59                 (0x08000000)   /*  Interrupt pending register 59 */
#define INTC_IPR60                 (0x10000000)   /*  Interrupt pending register 60 */
#define INTC_IPR61                 (0x20000000)   /*  Interrupt pending register 61 */
#define INTC_IPR62                 (0x40000000)   /*  Interrupt pending register 62 */
#define INTC_IPR63                 (0x80000000)   /*  Interrupt pending register 63 */

/* Bit definitions and macros for INTC_IPRL */
#define INTC_IPR0                  (0x00000001)   /*  Interrupt pending register 0 */
#define INTC_IPR1                  (0x00000002)   /*  Interrupt pending register 1 */
#define INTC_IPR2                  (0x00000004)   /*  Interrupt pending register 2 */
#define INTC_IPR3                  (0x00000008)   /*  Interrupt pending register 3 */
#define INTC_IPR4                  (0x00000010)   /*  Interrupt pending register 4 */
#define INTC_IPR5                  (0x00000020)   /*  Interrupt pending register 5 */
#define INTC_IPR6                  (0x00000040)   /*  Interrupt pending register 6 */
#define INTC_IPR7                  (0x00000080)   /*  Interrupt pending register 7 */
#define INTC_IPR8                  (0x00000100)   /*  Interrupt pending register 8 */
#define INTC_IPR9                  (0x00000200)   /*  Interrupt pending register 9 */
#define INTC_IPR10                 (0x00000400)   /*  Interrupt pending register 10 */
#define INTC_IPR11                 (0x00000800)   /*  Interrupt pending register 11 */
#define INTC_IPR12                 (0x00001000)   /*  Interrupt pending register 12 */
#define INTC_IPR13                 (0x00002000)   /*  Interrupt pending register 13 */
#define INTC_IPR14                 (0x00004000)   /*  Interrupt pending register 14 */
#define INTC_IPR15                 (0x00008000)   /*  Interrupt pending register 15 */
#define INTC_IPR16                 (0x00010000)   /*  Interrupt pending register 16 */
#define INTC_IPR17                 (0x00020000)   /*  Interrupt pending register 17 */
#define INTC_IPR18                 (0x00040000)   /*  Interrupt pending register 18 */
#define INTC_IPR19                 (0x00080000)   /*  Interrupt pending register 19 */
#define INTC_IPR20                 (0x00100000)   /*  Interrupt pending register 20 */
#define INTC_IPR21                 (0x00200000)   /*  Interrupt pending register 21 */
#define INTC_IPR22                 (0x00400000)   /*  Interrupt pending register 22 */
#define INTC_IPR23                 (0x00800000)   /*  Interrupt pending register 23 */
#define INTC_IPR24                 (0x01000000)   /*  Interrupt pending register 24 */
#define INTC_IPR25                 (0x02000000)   /*  Interrupt pending register 25 */
#define INTC_IPR26                 (0x04000000)   /*  Interrupt pending register 26 */
#define INTC_IPR27                 (0x08000000)   /*  Interrupt pending register 27 */
#define INTC_IPR28                 (0x10000000)   /*  Interrupt pending register 28 */
#define INTC_IPR29                 (0x20000000)   /*  Interrupt pending register 29 */
#define INTC_IPR30                 (0x40000000)   /*  Interrupt pending register 30 */
#define INTC_IPR31                 (0x80000000)   /*  Interrupt pending register 31 */

/* Bit definitions and macros for INTC_IMRH */
#define INTC_IMR32                 (0x00000001)   /*  Interrupt mask register 32 */
#define INTC_IMR33                 (0x00000002)   /*  Interrupt mask register 33 */
#define INTC_IMR34                 (0x00000004)   /*  Interrupt mask register 34 */
#define INTC_IMR35                 (0x00000008)   /*  Interrupt mask register 35 */
#define INTC_IMR36                 (0x00000010)   /*  Interrupt mask register 36 */
#define INTC_IMR37                 (0x00000020)   /*  Interrupt mask register 37 */
#define INTC_IMR38                 (0x00000040)   /*  Interrupt mask register 38 */
#define INTC_IMR39                 (0x00000080)   /*  Interrupt mask register 39 */
#define INTC_IMR40                 (0x00000100)   /*  Interrupt mask register 40 */
#define INTC_IMR41                 (0x00000200)   /*  Interrupt mask register 41 */
#define INTC_IMR42                 (0x00000400)   /*  Interrupt mask register 42 */
#define INTC_IMR43                 (0x00000800)   /*  Interrupt mask register 43 */
#define INTC_IMR44                 (0x00001000)   /*  Interrupt mask register 44 */
#define INTC_IMR45                 (0x00002000)   /*  Interrupt mask register 45 */
#define INTC_IMR46                 (0x00004000)   /*  Interrupt mask register 46 */
#define INTC_IMR47                 (0x00008000)   /*  Interrupt mask register 47 */
#define INTC_IMR48                 (0x00010000)   /*  Interrupt mask register 48 */
#define INTC_IMR49                 (0x00020000)   /*  Interrupt mask register 49 */
#define INTC_IMR50                 (0x00040000)   /*  Interrupt mask register 50 */
#define INTC_IMR51                 (0x00080000)   /*  Interrupt mask register 51 */
#define INTC_IMR52                 (0x00100000)   /*  Interrupt mask register 52 */
#define INTC_IMR53                 (0x00200000)   /*  Interrupt mask register 53 */
#define INTC_IMR54                 (0x00400000)   /*  Interrupt mask register 54 */
#define INTC_IMR55                 (0x00800000)   /*  Interrupt mask register 55 */
#define INTC_IMR56                 (0x01000000)   /*  Interrupt mask register 56 */
#define INTC_IMR57                 (0x02000000)   /*  Interrupt mask register 57 */
#define INTC_IMR58                 (0x04000000)   /*  Interrupt mask register 58 */
#define INTC_IMR59                 (0x08000000)   /*  Interrupt mask register 59 */
#define INTC_IMR60                 (0x10000000)   /*  Interrupt mask register 60 */
#define INTC_IMR61                 (0x20000000)   /*  Interrupt mask register 61 */
#define INTC_IMR62                 (0x40000000)   /*  Interrupt mask register 62 */
#define INTC_IMR63                 (0x80000000)   /*  Interrupt mask register 63 */

/* Bit definitions and macros for INTC_IMRL */
#define INTC_IMR0                  (0x00000001)   /*  Interrupt mask register 0 */
#define INTC_IMR1                  (0x00000002)   /*  Interrupt mask register 1 */
#define INTC_IMR2                  (0x00000004)   /*  Interrupt mask register 2 */
#define INTC_IMR3                  (0x00000008)   /*  Interrupt mask register 3 */
#define INTC_IMR4                  (0x00000010)   /*  Interrupt mask register 4 */
#define INTC_IMR5                  (0x00000020)   /*  Interrupt mask register 5 */
#define INTC_IMR6                  (0x00000040)   /*  Interrupt mask register 6 */
#define INTC_IMR7                  (0x00000080)   /*  Interrupt mask register 7 */
#define INTC_IMR8                  (0x00000100)   /*  Interrupt mask register 8 */
#define INTC_IMR9                  (0x00000200)   /*  Interrupt mask register 9 */
#define INTC_IMR10                 (0x00000400)   /*  Interrupt mask register 10 */
#define INTC_IMR11                 (0x00000800)   /*  Interrupt mask register 11 */
#define INTC_IMR12                 (0x00001000)   /*  Interrupt mask register 12 */
#define INTC_IMR13                 (0x00002000)   /*  Interrupt mask register 13 */
#define INTC_IMR14                 (0x00004000)   /*  Interrupt mask register 14 */
#define INTC_IMR15                 (0x00008000)   /*  Interrupt mask register 15 */
#define INTC_IMR16                 (0x00010000)   /*  Interrupt mask register 16 */
#define INTC_IMR17                 (0x00020000)   /*  Interrupt mask register 17 */
#define INTC_IMR18                 (0x00040000)   /*  Interrupt mask register 18 */
#define INTC_IMR19                 (0x00080000)   /*  Interrupt mask register 19 */
#define INTC_IMR20                 (0x00100000)   /*  Interrupt mask register 20 */
#define INTC_IMR21                 (0x00200000)   /*  Interrupt mask register 21 */
#define INTC_IMR22                 (0x00400000)   /*  Interrupt mask register 22 */
#define INTC_IMR23                 (0x00800000)   /*  Interrupt mask register 23 */
#define INTC_IMR24                 (0x01000000)   /*  Interrupt mask register 24 */
#define INTC_IMR25                 (0x02000000)   /*  Interrupt mask register 25 */
#define INTC_IMR26                 (0x04000000)   /*  Interrupt mask register 26 */
#define INTC_IMR27                 (0x08000000)   /*  Interrupt mask register 27 */
#define INTC_IMR28                 (0x10000000)   /*  Interrupt mask register 28 */
#define INTC_IMR29                 (0x20000000)   /*  Interrupt mask register 29 */
#define INTC_IMR30                 (0x40000000)   /*  Interrupt mask register 30 */
#define INTC_IMR31                 (0x80000000)   /*  Interrupt mask register 31 */

/* Bit definitions and macros for INTC_IFRCH */
#define INTC_IFRC32                (0x00000001)   /*  Interrupt force register 32 */
#define INTC_IFRC33                (0x00000002)   /*  Interrupt force register 33 */
#define INTC_IFRC34                (0x00000004)   /*  Interrupt force register 34 */
#define INTC_IFRC35                (0x00000008)   /*  Interrupt force register 35 */
#define INTC_IFRC36                (0x00000010)   /*  Interrupt force register 36 */
#define INTC_IFRC37                (0x00000020)   /*  Interrupt force register 37 */
#define INTC_IFRC38                (0x00000040)   /*  Interrupt force register 38 */
#define INTC_IFRC39                (0x00000080)   /*  Interrupt force register 39 */
#define INTC_IFRC40                (0x00000100)   /*  Interrupt force register 40 */
#define INTC_IFRC41                (0x00000200)   /*  Interrupt force register 41 */
#define INTC_IFRC42                (0x00000400)   /*  Interrupt force register 42 */
#define INTC_IFRC43                (0x00000800)   /*  Interrupt force register 43 */
#define INTC_IFRC44                (0x00001000)   /*  Interrupt force register 44 */
#define INTC_IFRC45                (0x00002000)   /*  Interrupt force register 45 */
#define INTC_IFRC46                (0x00004000)   /*  Interrupt force register 46 */
#define INTC_IFRC47                (0x00008000)   /*  Interrupt force register 47 */
#define INTC_IFRC48                (0x00010000)   /*  Interrupt force register 48 */
#define INTC_IFRC49                (0x00020000)   /*  Interrupt force register 49 */
#define INTC_IFRC50                (0x00040000)   /*  Interrupt force register 50 */
#define INTC_IFRC51                (0x00080000)   /*  Interrupt force register 51 */
#define INTC_IFRC52                (0x00100000)   /*  Interrupt force register 52 */
#define INTC_IFRC53                (0x00200000)   /*  Interrupt force register 53 */
#define INTC_IFRC54                (0x00400000)   /*  Interrupt force register 54 */
#define INTC_IFRC55                (0x00800000)   /*  Interrupt force register 55 */
#define INTC_IFRC56                (0x01000000)   /*  Interrupt force register 56 */
#define INTC_IFRC57                (0x02000000)   /*  Interrupt force register 57 */
#define INTC_IFRC58                (0x04000000)   /*  Interrupt force register 58 */
#define INTC_IFRC59                (0x08000000)   /*  Interrupt force register 59 */
#define INTC_IFRC60                (0x10000000)   /*  Interrupt force register 60 */
#define INTC_IFRC61                (0x20000000)   /*  Interrupt force register 61 */
#define INTC_IFRC62                (0x40000000)   /*  Interrupt force register 62 */
#define INTC_IFRC63                (0x80000000)   /*  Interrupt force register 63 */

/* Bit definitions and macros for INTC_IFRCL */
#define INTC_IFRC0                 (0x00000001)   /*  Interrupt force register 0 */
#define INTC_IFRC1                 (0x00000002)   /*  Interrupt force register 1 */
#define INTC_IFRC2                 (0x00000004)   /*  Interrupt force register 2 */
#define INTC_IFRC3                 (0x00000008)   /*  Interrupt force register 3 */
#define INTC_IFRC4                 (0x00000010)   /*  Interrupt force register 4 */
#define INTC_IFRC5                 (0x00000020)   /*  Interrupt force register 5 */
#define INTC_IFRC6                 (0x00000040)   /*  Interrupt force register 6 */
#define INTC_IFRC7                 (0x00000080)   /*  Interrupt force register 7 */
#define INTC_IFRC8                 (0x00000100)   /*  Interrupt force register 8 */
#define INTC_IFRC9                 (0x00000200)   /*  Interrupt force register 9 */
#define INTC_IFRC10                (0x00000400)   /*  Interrupt force register 10 */
#define INTC_IFRC11                (0x00000800)   /*  Interrupt force register 11 */
#define INTC_IFRC12                (0x00001000)   /*  Interrupt force register 12 */
#define INTC_IFRC13                (0x00002000)   /*  Interrupt force register 13 */
#define INTC_IFRC14                (0x00004000)   /*  Interrupt force register 14 */
#define INTC_IFRC15                (0x00008000)   /*  Interrupt force register 15 */
#define INTC_IFRC16                (0x00010000)   /*  Interrupt force register 16 */
#define INTC_IFRC17                (0x00020000)   /*  Interrupt force register 17 */
#define INTC_IFRC18                (0x00040000)   /*  Interrupt force register 18 */
#define INTC_IFRC19                (0x00080000)   /*  Interrupt force register 19 */
#define INTC_IFRC20                (0x00100000)   /*  Interrupt force register 20 */
#define INTC_IFRC21                (0x00200000)   /*  Interrupt force register 21 */
#define INTC_IFRC22                (0x00400000)   /*  Interrupt force register 22 */
#define INTC_IFRC23                (0x00800000)   /*  Interrupt force register 23 */
#define INTC_IFRC24                (0x01000000)   /*  Interrupt force register 24 */
#define INTC_IFRC25                (0x02000000)   /*  Interrupt force register 25 */
#define INTC_IFRC26                (0x04000000)   /*  Interrupt force register 26 */
#define INTC_IFRC27                (0x08000000)   /*  Interrupt force register 27 */
#define INTC_IFRC28                (0x10000000)   /*  Interrupt force register 28 */
#define INTC_IFRC29                (0x20000000)   /*  Interrupt force register 29 */
#define INTC_IFRC30                (0x40000000)   /*  Interrupt force register 30 */
#define INTC_IFRC31                (0x80000000)   /*  Interrupt force register 31 */

/* Bit definitions and macros for INTC_ICONFIG */
#define INTC_FIQDEF(x)             (((x)&0x1F)<<0)  /*  FIQ Interrupt Level Definition */
#define INTC_EMASK                 (0x20)         /*  Enable Hardware Level Masking */
#define INTC_EIRQPRI               (0x40)         /*  Enable Core's Priority Elevation on IRQ */
#define INTC_EFIQPRI               (0x80)         /*  Enable Core's Priority Elevation on FIQ */

/* Bit definitions and macros for INTC_SIMR */
#define INTC_SIM(x)                (((x)&0x7F)<<0)  /*  Set Interrupt Mask */

/* Bit definitions and macros for INTC_CIMR */
#define INTC_CIM(x)                (((x)&0x7F)<<0)  /*  Clear Interrupt Mask */

/* Bit definitions and macros for INTC_CLMASK */
#define INTC_CLMSK(x)              (((x)&0x1F)<<0)  /*  Current Level Mask */

/* Bit definitions and macros for INTC_SLMASK */
#define INTC_SLMSK(x)              (((x)&0x1F)<<0)  /*  Saved Level Mask */

/* Bit definitions and macros for INTC_ICRn */
#define INTC_LEVEL(x)              (((x)&0x0F)<<0)  /*  Interrupt Request Level */

/* Bit definitions and macros for INTC_IRQIACK */
#define INTC_VECTOR(x)             (((x)&0xFF)<<0)  /*  Interrupt Vector Number */

/* Bit definitions and macros for INTC_FIQIACK */
#define INTC_VECTOR(x)             (((x)&0xFF)<<0)  /*  Interrupt Vector Number */

/*********************************************************************
*
* MCM Module (MCM)
*
*********************************************************************/

/* Register read/write macros */
#define MCM_PCT                    (*(vuint16_t *)(0xFC040000))
#define MCM_REV                    (*(vuint16_t *)(0xFC040002))
#define MCM_AMC                    (*(vuint16_t *)(0xFC040004))
#define MCM_ASC                    (*(vuint16_t *)(0xFC040006))
#define MCM_IMC                    (*(vuint32_t *)(0xFC040008))
#define MCM_MRSR                   (*(vuint8_t  *)(0xFC04000F)) /* MRSR - Miscellaneous Reset Status Register */
#define MCM_MWCR                   (*(vuint8_t  *)(0xFC040013)) /* MWCR - Miscellaneous Wakeup Control Register */
#define MCM_MSWTCR                 (*(vuint16_t *)(0xFC040016)) /* MSWTCR - Miscellaneous Software Watchdog Timer Control Register */
#define MCM_MSWTSR                 (*(vuint8_t  *)(0xFC04001B)) /* MSWTSR - Miscellaneous Software Watchdog Timer Service Register */
#define MCM_MSWTIR                 (*(vuint8_t  *)(0xFC04001F)) /* MSWTIR - Miscellaneous Software Watchdog Timer Interrupt Register */
#define MCM_AAMR                   (*(vuint32_t *)(0xFC040020)) /* AAMR - AXBS Address Map Register */
#define MCM_CFADR                  (*(vuint32_t *)(0xFC040070)) /* CFADR - Core Fault Address Register */
#define MCM_CFLOC                  (*(vuint8_t  *)(0xFC040076)) /* CFLOC - Core Fault Location Register */
#define MCM_CFATR                  (*(vuint8_t  *)(0xFC040077)) /* CFATR - Core Fault Attributes Register */
#define MCM_CFDTR                  (*(vuint32_t *)(0xFC04007C)) /* CFDTR - Core Fault Data Register */

/* Bit definitions and macros for MCM_AMC */
#define MCM_AXMC(x)                (((x)&0x00FF)<<0)    /*  AXBS Master Configuration */

/* Bit definitions and macros for MCM_ASC */
#define MCM_AXSC(x)                (((x)&0x00FF)<<0)    /*  AXBS Slave Configuration */
#define MCM_DP64                   (0x8000)       /*  64-bit Datapath */

/* Bit definitions and macros for MCM_MRSR */
#define MCM_SWTR                   (0x20)         /*  Watchdog Timer Reset */
#define MCM_DIR                    (0x40)         /*  Device Input Reset */
#define MCM_POR                    (0x80)         /*  Power-On Reset */

/* Bit definitions and macros for MCM_MWCR */
#define MCM_PRILVL(x)              (((x)&0x0F)<<0)  /*  Interrupt Priority Level */
#define MCM_ENBWCR                 (0x80)         /*  Enable WCR */

/* Bit definitions and macros for MCM_MSWTCR */
#define MCM_SWT(x)                 (((x)&0x001F)<<0)    /*  Watchdog Time-Out Period */
#define MCM_SWRI(x)                (((x)&0x0003)<<5)    /*  Watchdog Reset/Interrupt */
#define MCM_SWE                    (0x0080)       /*  Watchdog Enable */
#define MCM_SWRWH                  (0x0100)       /*  Watchdog Run While Halted */
#define MCM_SWCIN16                (0x0200)       /*  Force SWT CarryIn16 */
#define MCM_RO                     (0x8000)       /*  Read-Only */

/* Bit definitions and macros for MCM_MSWTIR */
#define MCM_SWTIC                  (0x01)         /*  Watchdog Interrupt Flag */

/* Bit definitions and macros for MCM_AAMR */
#define MCM_A0SLAVE(x)             (((x)&0x00000007)<<0)    /*  Address 0 Slave Number */
#define MCM_EA0                    (0x00000008)   /*  Enable Address Region 0 */
#define MCM_A1SLAVE(x)             (((x)&0x00000007)<<4)    /*  Address 1 Slave Number */
#define MCM_EA1                    (0x00000080)   /*  Enable Address Region 1 */
#define MCM_A2SLAVE(x)             (((x)&0x00000007)<<8)    /*  Address 2 Slave Number */
#define MCM_EA2                    (0x00000800)   /*  Enable Address Region 2 */
#define MCM_A3SLAVE(x)             (((x)&0x00000007)<<12)   /*  Address 3 Slave Number */
#define MCM_EA3                    (0x00008000)   /*  Enable Address Region 3 */
#define MCM_A4SLAVE(x)             (((x)&0x00000007)<<16)   /*  Address 4 Slave Number */
#define MCM_EA4                    (0x00080000)   /*  Enable Address Region 4 */
#define MCM_A5SLAVE(x)             (((x)&0x00000007)<<20)   /*  Address 5 Slave Number */
#define MCM_EA5                    (0x00800000)   /*  Enable Address Region 5 */
#define MCM_A6SLAVE(x)             (((x)&0x00000007)<<24)   /*  Address 6 Slave Number */
#define MCM_EA6                    (0x08000000)   /*  Enable Address Region 6 */
#define MCM_A7SLAVE(x)             (((x)&0x00000007)<<28)   /*  Address 7 Slave Number */
#define MCM_EA7                    (0x80000000)   /*  Enable Address Region 7 */

/* Bit definitions and macros for MCM_CFLOC */
#define MCM_LOCALERR               (0x80)         /*  Bus Error Indicator */

/* Bit definitions and macros for MCM_CFATR */
#define MCM_PROTECTION(x)          (((x)&0x0F)<<0)  /*  Protection fault type */
#define MCM_SIZE(x)                (((x)&0x07)<<4)  /*  8-16-32-64-bit core access */
#define MCM_WRITE                  (0x80)         /*  Core read/write access */

/*********************************************************************
*
* PIM Module (PIM)
*
*********************************************************************/

/* Register read/write macros */
#define PIM_PA_CONFIG0             (*(vuint16_t *)(0xFC0E8000)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG1             (*(vuint16_t *)(0xFC0E8002)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG2             (*(vuint16_t *)(0xFC0E8004)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG3             (*(vuint16_t *)(0xFC0E8006)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG4             (*(vuint16_t *)(0xFC0E8008)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG5             (*(vuint16_t *)(0xFC0E800A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG6             (*(vuint16_t *)(0xFC0E800C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG7             (*(vuint16_t *)(0xFC0E800E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG8             (*(vuint16_t *)(0xFC0E8010)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG9             (*(vuint16_t *)(0xFC0E8012)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG10            (*(vuint16_t *)(0xFC0E8014)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG11            (*(vuint16_t *)(0xFC0E8016)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG12            (*(vuint16_t *)(0xFC0E8018)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG13            (*(vuint16_t *)(0xFC0E801A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG14            (*(vuint16_t *)(0xFC0E801C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG15            (*(vuint16_t *)(0xFC0E801E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_CONFIG(x)           (*(vuint16_t *)(0xFC0E8000+((x)*0x002))) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PA_PORTIFR             (*(vuint16_t *)(0xFC0E8020)) /* PORTIFR - Port Wide Interrupt Flag Register */
#define PIM_PA_PORTDATA            (*(vuint16_t *)(0xFC0E8024)) /* PORTDATA - Port Wide Data Read/Write Register */
#define PIM_PA_PORTIR              (*(vuint16_t *)(0xFC0E8026)) /* PORTIR - Port Wide Input Register */
#define PIM_PA_PINDATA0            (*(vuint8_t  *)(0xFC0E8028)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA1            (*(vuint8_t  *)(0xFC0E8029)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA2            (*(vuint8_t  *)(0xFC0E802A)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA3            (*(vuint8_t  *)(0xFC0E802B)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA4            (*(vuint8_t  *)(0xFC0E802C)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA5            (*(vuint8_t  *)(0xFC0E802D)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA6            (*(vuint8_t  *)(0xFC0E802E)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA7            (*(vuint8_t  *)(0xFC0E802F)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA8            (*(vuint8_t  *)(0xFC0E8030)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA9            (*(vuint8_t  *)(0xFC0E8031)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA10           (*(vuint8_t  *)(0xFC0E8032)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA11           (*(vuint8_t  *)(0xFC0E8033)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA12           (*(vuint8_t  *)(0xFC0E8034)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA13           (*(vuint8_t  *)(0xFC0E8035)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA14           (*(vuint8_t  *)(0xFC0E8036)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA15           (*(vuint8_t  *)(0xFC0E8037)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PA_PINDATA(x)          (*(vuint8_t  *)(0xFC0E8028+((x)*0x001))) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_CONFIG0             (*(vuint16_t *)(0xFC0E8040)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG1             (*(vuint16_t *)(0xFC0E8042)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG2             (*(vuint16_t *)(0xFC0E8044)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG3             (*(vuint16_t *)(0xFC0E8046)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG4             (*(vuint16_t *)(0xFC0E8048)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG5             (*(vuint16_t *)(0xFC0E804A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG6             (*(vuint16_t *)(0xFC0E804C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG7             (*(vuint16_t *)(0xFC0E804E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG8             (*(vuint16_t *)(0xFC0E8050)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG9             (*(vuint16_t *)(0xFC0E8052)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG10            (*(vuint16_t *)(0xFC0E8054)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG11            (*(vuint16_t *)(0xFC0E8056)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG12            (*(vuint16_t *)(0xFC0E8058)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG13            (*(vuint16_t *)(0xFC0E805A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG14            (*(vuint16_t *)(0xFC0E805C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG15            (*(vuint16_t *)(0xFC0E805E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_CONFIG(x)           (*(vuint16_t *)(0xFC0E8040+((x)*0x002))) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PB_PORTIFR             (*(vuint16_t *)(0xFC0E8060)) /* PORTIFR - Port Wide Interrupt Flag Register */
#define PIM_PB_PORTDATA            (*(vuint16_t *)(0xFC0E8064)) /* PORTDATA - Port Wide Data Read/Write Register */
#define PIM_PB_PORTIR              (*(vuint16_t *)(0xFC0E8066)) /* PORTIR - Port Wide Input Register */
#define PIM_PB_PINDATA0            (*(vuint8_t  *)(0xFC0E8068)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA1            (*(vuint8_t  *)(0xFC0E8069)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA2            (*(vuint8_t  *)(0xFC0E806A)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA3            (*(vuint8_t  *)(0xFC0E806B)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA4            (*(vuint8_t  *)(0xFC0E806C)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA5            (*(vuint8_t  *)(0xFC0E806D)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA6            (*(vuint8_t  *)(0xFC0E806E)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA7            (*(vuint8_t  *)(0xFC0E806F)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA8            (*(vuint8_t  *)(0xFC0E8070)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA9            (*(vuint8_t  *)(0xFC0E8071)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA10           (*(vuint8_t  *)(0xFC0E8072)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA11           (*(vuint8_t  *)(0xFC0E8073)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA12           (*(vuint8_t  *)(0xFC0E8074)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA13           (*(vuint8_t  *)(0xFC0E8075)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA14           (*(vuint8_t  *)(0xFC0E8076)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA15           (*(vuint8_t  *)(0xFC0E8077)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PB_PINDATA(x)          (*(vuint8_t  *)(0xFC0E8068+((x)*0x001))) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_CONFIG0             (*(vuint16_t *)(0xFC0E8080)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG1             (*(vuint16_t *)(0xFC0E8082)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG2             (*(vuint16_t *)(0xFC0E8084)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG3             (*(vuint16_t *)(0xFC0E8086)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG4             (*(vuint16_t *)(0xFC0E8088)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG5             (*(vuint16_t *)(0xFC0E808A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG6             (*(vuint16_t *)(0xFC0E808C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG7             (*(vuint16_t *)(0xFC0E808E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG8             (*(vuint16_t *)(0xFC0E8090)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG9             (*(vuint16_t *)(0xFC0E8092)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG10            (*(vuint16_t *)(0xFC0E8094)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG11            (*(vuint16_t *)(0xFC0E8096)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG12            (*(vuint16_t *)(0xFC0E8098)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG13            (*(vuint16_t *)(0xFC0E809A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG14            (*(vuint16_t *)(0xFC0E809C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG15            (*(vuint16_t *)(0xFC0E809E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_CONFIG(x)           (*(vuint16_t *)(0xFC0E8080+((x)*0x002))) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PC_PORTIFR             (*(vuint16_t *)(0xFC0E80A0)) /* PORTIFR - Port Wide Interrupt Flag Register */
#define PIM_PC_PORTDATA            (*(vuint16_t *)(0xFC0E80A4)) /* PORTDATA - Port Wide Data Read/Write Register */
#define PIM_PC_PORTIR              (*(vuint16_t *)(0xFC0E80A6)) /* PORTIR - Port Wide Input Register */
#define PIM_PC_PINDATA0            (*(vuint8_t  *)(0xFC0E80A8)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA1            (*(vuint8_t  *)(0xFC0E80A9)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA2            (*(vuint8_t  *)(0xFC0E80AA)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA3            (*(vuint8_t  *)(0xFC0E80AB)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA4            (*(vuint8_t  *)(0xFC0E80AC)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA5            (*(vuint8_t  *)(0xFC0E80AD)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA6            (*(vuint8_t  *)(0xFC0E80AE)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA7            (*(vuint8_t  *)(0xFC0E80AF)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA8            (*(vuint8_t  *)(0xFC0E80B0)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA9            (*(vuint8_t  *)(0xFC0E80B1)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA10           (*(vuint8_t  *)(0xFC0E80B2)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA11           (*(vuint8_t  *)(0xFC0E80B3)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA12           (*(vuint8_t  *)(0xFC0E80B4)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA13           (*(vuint8_t  *)(0xFC0E80B5)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA14           (*(vuint8_t  *)(0xFC0E80B6)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA15           (*(vuint8_t  *)(0xFC0E80B7)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PC_PINDATA(x)          (*(vuint8_t  *)(0xFC0E80A8+((x)*0x001))) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_CONFIG0             (*(vuint16_t *)(0xFC0E80C0)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG1             (*(vuint16_t *)(0xFC0E80C2)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG2             (*(vuint16_t *)(0xFC0E80C4)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG3             (*(vuint16_t *)(0xFC0E80C6)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG4             (*(vuint16_t *)(0xFC0E80C8)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG5             (*(vuint16_t *)(0xFC0E80CA)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG6             (*(vuint16_t *)(0xFC0E80CC)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG7             (*(vuint16_t *)(0xFC0E80CE)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG8             (*(vuint16_t *)(0xFC0E80D0)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG9             (*(vuint16_t *)(0xFC0E80D2)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG10            (*(vuint16_t *)(0xFC0E80D4)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG11            (*(vuint16_t *)(0xFC0E80D6)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG12            (*(vuint16_t *)(0xFC0E80D8)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG13            (*(vuint16_t *)(0xFC0E80DA)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG14            (*(vuint16_t *)(0xFC0E80DC)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG15            (*(vuint16_t *)(0xFC0E80DE)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_CONFIG(x)           (*(vuint16_t *)(0xFC0E80C0+((x)*0x002))) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PD_PORTIFR             (*(vuint16_t *)(0xFC0E80E0)) /* PORTIFR - Port Wide Interrupt Flag Register */
#define PIM_PD_PORTDATA            (*(vuint16_t *)(0xFC0E80E4)) /* PORTDATA - Port Wide Data Read/Write Register */
#define PIM_PD_PORTIR              (*(vuint16_t *)(0xFC0E80E6)) /* PORTIR - Port Wide Input Register */
#define PIM_PD_PINDATA0            (*(vuint8_t  *)(0xFC0E80E8)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA1            (*(vuint8_t  *)(0xFC0E80E9)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA2            (*(vuint8_t  *)(0xFC0E80EA)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA3            (*(vuint8_t  *)(0xFC0E80EB)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA4            (*(vuint8_t  *)(0xFC0E80EC)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA5            (*(vuint8_t  *)(0xFC0E80ED)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA6            (*(vuint8_t  *)(0xFC0E80EE)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA7            (*(vuint8_t  *)(0xFC0E80EF)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA8            (*(vuint8_t  *)(0xFC0E80F0)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA9            (*(vuint8_t  *)(0xFC0E80F1)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA10           (*(vuint8_t  *)(0xFC0E80F2)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA11           (*(vuint8_t  *)(0xFC0E80F3)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA12           (*(vuint8_t  *)(0xFC0E80F4)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA13           (*(vuint8_t  *)(0xFC0E80F5)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA14           (*(vuint8_t  *)(0xFC0E80F6)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA15           (*(vuint8_t  *)(0xFC0E80F7)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PD_PINDATA(x)          (*(vuint8_t  *)(0xFC0E80E8+((x)*0x001))) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_CONFIG0             (*(vuint16_t *)(0xFC0E8100)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG1             (*(vuint16_t *)(0xFC0E8102)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG2             (*(vuint16_t *)(0xFC0E8104)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG3             (*(vuint16_t *)(0xFC0E8106)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG4             (*(vuint16_t *)(0xFC0E8108)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG5             (*(vuint16_t *)(0xFC0E810A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG6             (*(vuint16_t *)(0xFC0E810C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG7             (*(vuint16_t *)(0xFC0E810E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG8             (*(vuint16_t *)(0xFC0E8110)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG9             (*(vuint16_t *)(0xFC0E8112)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG10            (*(vuint16_t *)(0xFC0E8114)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG11            (*(vuint16_t *)(0xFC0E8116)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG12            (*(vuint16_t *)(0xFC0E8118)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG13            (*(vuint16_t *)(0xFC0E811A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG14            (*(vuint16_t *)(0xFC0E811C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG15            (*(vuint16_t *)(0xFC0E811E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_CONFIG(x)           (*(vuint16_t *)(0xFC0E8100+((x)*0x002))) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PE_PORTIFR             (*(vuint16_t *)(0xFC0E8120)) /* PORTIFR - Port Wide Interrupt Flag Register */
#define PIM_PE_PORTDATA            (*(vuint16_t *)(0xFC0E8124)) /* PORTDATA - Port Wide Data Read/Write Register */
#define PIM_PE_PORTIR              (*(vuint16_t *)(0xFC0E8126)) /* PORTIR - Port Wide Input Register */
#define PIM_PE_PINDATA0            (*(vuint8_t  *)(0xFC0E8128)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA1            (*(vuint8_t  *)(0xFC0E8129)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA2            (*(vuint8_t  *)(0xFC0E812A)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA3            (*(vuint8_t  *)(0xFC0E812B)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA4            (*(vuint8_t  *)(0xFC0E812C)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA5            (*(vuint8_t  *)(0xFC0E812D)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA6            (*(vuint8_t  *)(0xFC0E812E)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA7            (*(vuint8_t  *)(0xFC0E812F)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA8            (*(vuint8_t  *)(0xFC0E8130)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA9            (*(vuint8_t  *)(0xFC0E8131)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA10           (*(vuint8_t  *)(0xFC0E8132)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA11           (*(vuint8_t  *)(0xFC0E8133)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA12           (*(vuint8_t  *)(0xFC0E8134)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA13           (*(vuint8_t  *)(0xFC0E8135)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA14           (*(vuint8_t  *)(0xFC0E8136)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA15           (*(vuint8_t  *)(0xFC0E8137)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PE_PINDATA(x)          (*(vuint8_t  *)(0xFC0E8128+((x)*0x001))) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_CONFIG0             (*(vuint16_t *)(0xFC0E8140)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG1             (*(vuint16_t *)(0xFC0E8142)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG2             (*(vuint16_t *)(0xFC0E8144)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG3             (*(vuint16_t *)(0xFC0E8146)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG4             (*(vuint16_t *)(0xFC0E8148)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG5             (*(vuint16_t *)(0xFC0E814A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG6             (*(vuint16_t *)(0xFC0E814C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG7             (*(vuint16_t *)(0xFC0E814E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG8             (*(vuint16_t *)(0xFC0E8150)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG9             (*(vuint16_t *)(0xFC0E8152)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG10            (*(vuint16_t *)(0xFC0E8154)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG11            (*(vuint16_t *)(0xFC0E8156)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG12            (*(vuint16_t *)(0xFC0E8158)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG13            (*(vuint16_t *)(0xFC0E815A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG14            (*(vuint16_t *)(0xFC0E815C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG15            (*(vuint16_t *)(0xFC0E815E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_CONFIG(x)           (*(vuint16_t *)(0xFC0E8140+((x)*0x002))) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PF_PORTIFR             (*(vuint16_t *)(0xFC0E8160)) /* PORTIFR - Port Wide Interrupt Flag Register */
#define PIM_PF_PORTDATA            (*(vuint16_t *)(0xFC0E8164)) /* PORTDATA - Port Wide Data Read/Write Register */
#define PIM_PF_PORTIR              (*(vuint16_t *)(0xFC0E8166)) /* PORTIR - Port Wide Input Register */
#define PIM_PF_PINDATA0            (*(vuint8_t  *)(0xFC0E8168)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA1            (*(vuint8_t  *)(0xFC0E8169)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA2            (*(vuint8_t  *)(0xFC0E816A)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA3            (*(vuint8_t  *)(0xFC0E816B)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA4            (*(vuint8_t  *)(0xFC0E816C)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA5            (*(vuint8_t  *)(0xFC0E816D)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA6            (*(vuint8_t  *)(0xFC0E816E)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA7            (*(vuint8_t  *)(0xFC0E816F)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA8            (*(vuint8_t  *)(0xFC0E8170)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA9            (*(vuint8_t  *)(0xFC0E8171)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA10           (*(vuint8_t  *)(0xFC0E8172)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA11           (*(vuint8_t  *)(0xFC0E8173)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA12           (*(vuint8_t  *)(0xFC0E8174)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA13           (*(vuint8_t  *)(0xFC0E8175)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA14           (*(vuint8_t  *)(0xFC0E8176)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA15           (*(vuint8_t  *)(0xFC0E8177)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PF_PINDATA(x)          (*(vuint8_t  *)(0xFC0E8168+((x)*0x001))) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_CONFIG0             (*(vuint16_t *)(0xFC0E8180)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG1             (*(vuint16_t *)(0xFC0E8182)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG2             (*(vuint16_t *)(0xFC0E8184)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG3             (*(vuint16_t *)(0xFC0E8186)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG4             (*(vuint16_t *)(0xFC0E8188)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG5             (*(vuint16_t *)(0xFC0E818A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG6             (*(vuint16_t *)(0xFC0E818C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG7             (*(vuint16_t *)(0xFC0E818E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG8             (*(vuint16_t *)(0xFC0E8190)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG9             (*(vuint16_t *)(0xFC0E8192)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG10            (*(vuint16_t *)(0xFC0E8194)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG11            (*(vuint16_t *)(0xFC0E8196)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG12            (*(vuint16_t *)(0xFC0E8198)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG13            (*(vuint16_t *)(0xFC0E819A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG14            (*(vuint16_t *)(0xFC0E819C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG15            (*(vuint16_t *)(0xFC0E819E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_CONFIG(x)           (*(vuint16_t *)(0xFC0E8180+((x)*0x002))) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PG_PORTIFR             (*(vuint16_t *)(0xFC0E81A0)) /* PORTIFR - Port Wide Interrupt Flag Register */
#define PIM_PG_PORTDATA            (*(vuint16_t *)(0xFC0E81A4)) /* PORTDATA - Port Wide Data Read/Write Register */
#define PIM_PG_PORTIR              (*(vuint16_t *)(0xFC0E81A6)) /* PORTIR - Port Wide Input Register */
#define PIM_PG_PINDATA0            (*(vuint8_t  *)(0xFC0E81A8)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA1            (*(vuint8_t  *)(0xFC0E81A9)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA2            (*(vuint8_t  *)(0xFC0E81AA)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA3            (*(vuint8_t  *)(0xFC0E81AB)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA4            (*(vuint8_t  *)(0xFC0E81AC)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA5            (*(vuint8_t  *)(0xFC0E81AD)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA6            (*(vuint8_t  *)(0xFC0E81AE)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA7            (*(vuint8_t  *)(0xFC0E81AF)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA8            (*(vuint8_t  *)(0xFC0E81B0)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA9            (*(vuint8_t  *)(0xFC0E81B1)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA10           (*(vuint8_t  *)(0xFC0E81B2)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA11           (*(vuint8_t  *)(0xFC0E81B3)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA12           (*(vuint8_t  *)(0xFC0E81B4)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA13           (*(vuint8_t  *)(0xFC0E81B5)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA14           (*(vuint8_t  *)(0xFC0E81B6)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA15           (*(vuint8_t  *)(0xFC0E81B7)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PG_PINDATA(x)          (*(vuint8_t  *)(0xFC0E81A8+((x)*0x001))) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_CONFIG0             (*(vuint16_t *)(0xFC0E81C0)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG1             (*(vuint16_t *)(0xFC0E81C2)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG2             (*(vuint16_t *)(0xFC0E81C4)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG3             (*(vuint16_t *)(0xFC0E81C6)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG4             (*(vuint16_t *)(0xFC0E81C8)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG5             (*(vuint16_t *)(0xFC0E81CA)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG6             (*(vuint16_t *)(0xFC0E81CC)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG7             (*(vuint16_t *)(0xFC0E81CE)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG8             (*(vuint16_t *)(0xFC0E81D0)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG9             (*(vuint16_t *)(0xFC0E81D2)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG10            (*(vuint16_t *)(0xFC0E81D4)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG11            (*(vuint16_t *)(0xFC0E81D6)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG12            (*(vuint16_t *)(0xFC0E81D8)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG13            (*(vuint16_t *)(0xFC0E81DA)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG14            (*(vuint16_t *)(0xFC0E81DC)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG15            (*(vuint16_t *)(0xFC0E81DE)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_CONFIG(x)           (*(vuint16_t *)(0xFC0E81C0+((x)*0x002))) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PH_PORTIFR             (*(vuint16_t *)(0xFC0E81E0)) /* PORTIFR - Port Wide Interrupt Flag Register */
#define PIM_PH_PORTDATA            (*(vuint16_t *)(0xFC0E81E4)) /* PORTDATA - Port Wide Data Read/Write Register */
#define PIM_PH_PORTIR              (*(vuint16_t *)(0xFC0E81E6)) /* PORTIR - Port Wide Input Register */
#define PIM_PH_PINDATA0            (*(vuint8_t  *)(0xFC0E81E8)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA1            (*(vuint8_t  *)(0xFC0E81E9)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA2            (*(vuint8_t  *)(0xFC0E81EA)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA3            (*(vuint8_t  *)(0xFC0E81EB)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA4            (*(vuint8_t  *)(0xFC0E81EC)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA5            (*(vuint8_t  *)(0xFC0E81ED)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA6            (*(vuint8_t  *)(0xFC0E81EE)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA7            (*(vuint8_t  *)(0xFC0E81EF)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA8            (*(vuint8_t  *)(0xFC0E81F0)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA9            (*(vuint8_t  *)(0xFC0E81F1)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA10           (*(vuint8_t  *)(0xFC0E81F2)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA11           (*(vuint8_t  *)(0xFC0E81F3)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA12           (*(vuint8_t  *)(0xFC0E81F4)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA13           (*(vuint8_t  *)(0xFC0E81F5)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA14           (*(vuint8_t  *)(0xFC0E81F6)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA15           (*(vuint8_t  *)(0xFC0E81F7)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PH_PINDATA(x)          (*(vuint8_t  *)(0xFC0E81E8+((x)*0x001))) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_CONFIG0             (*(vuint16_t *)(0xFC0E8200)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG1             (*(vuint16_t *)(0xFC0E8202)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG2             (*(vuint16_t *)(0xFC0E8204)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG3             (*(vuint16_t *)(0xFC0E8206)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG4             (*(vuint16_t *)(0xFC0E8208)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG5             (*(vuint16_t *)(0xFC0E820A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG6             (*(vuint16_t *)(0xFC0E820C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG7             (*(vuint16_t *)(0xFC0E820E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG8             (*(vuint16_t *)(0xFC0E8210)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG9             (*(vuint16_t *)(0xFC0E8212)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG10            (*(vuint16_t *)(0xFC0E8214)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG11            (*(vuint16_t *)(0xFC0E8216)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG12            (*(vuint16_t *)(0xFC0E8218)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG13            (*(vuint16_t *)(0xFC0E821A)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG14            (*(vuint16_t *)(0xFC0E821C)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG15            (*(vuint16_t *)(0xFC0E821E)) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_CONFIG(x)           (*(vuint16_t *)(0xFC0E8200+((x)*0x002))) /* CONFIG[n] - PORT Pin Configuration Registers */
#define PIM_PI_PORTIFR             (*(vuint16_t *)(0xFC0E8220)) /* PORTIFR - Port Wide Interrupt Flag Register */
#define PIM_PI_PORTDATA            (*(vuint16_t *)(0xFC0E8224)) /* PORTDATA - Port Wide Data Read/Write Register */
#define PIM_PI_PORTIR              (*(vuint16_t *)(0xFC0E8226)) /* PORTIR - Port Wide Input Register */
#define PIM_PI_PINDATA0            (*(vuint8_t  *)(0xFC0E8228)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA1            (*(vuint8_t  *)(0xFC0E8229)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA2            (*(vuint8_t  *)(0xFC0E822A)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA3            (*(vuint8_t  *)(0xFC0E822B)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA4            (*(vuint8_t  *)(0xFC0E822C)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA5            (*(vuint8_t  *)(0xFC0E822D)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA6            (*(vuint8_t  *)(0xFC0E822E)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA7            (*(vuint8_t  *)(0xFC0E822F)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA8            (*(vuint8_t  *)(0xFC0E8230)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA9            (*(vuint8_t  *)(0xFC0E8231)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA10           (*(vuint8_t  *)(0xFC0E8232)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA11           (*(vuint8_t  *)(0xFC0E8233)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA12           (*(vuint8_t  *)(0xFC0E8234)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA13           (*(vuint8_t  *)(0xFC0E8235)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA14           (*(vuint8_t  *)(0xFC0E8236)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA15           (*(vuint8_t  *)(0xFC0E8237)) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_PI_PINDATA(x)          (*(vuint8_t  *)(0xFC0E8228+((x)*0x001))) /* PINDATA[n] - Port Pin Data Registers */
#define PIM_GLBLINT                (*(vuint16_t *)(0xFC0E83C0)) /* Global Interrupt Status Register */
#define PIM_PIMCONFIG              (*(vuint16_t *)(0xFC0E83C2)) /* PIM Configuration Register */
#define PIM_CONFIG_TDI             (*(vuint16_t *)(0xFC0E83C4)) /* TDI Pin Configuration Register */
#define PIM_CONFIG_TDO             (*(vuint16_t *)(0xFC0E83C6)) /* TDO Pin Configuration Register */
#define PIM_CONFIG_TMS             (*(vuint16_t *)(0xFC0E83C8)) /* TMS Pin Configuration Register */
#define PIM_CONFIG_TCK             (*(vuint16_t *)(0xFC0E83CA)) /* TCK Pin Configuration Register */
#define PIM_CONFIG_TA              (*(vuint16_t *)(0xFC0E83CC)) /* TA Pin Configuration Register */

/* Bit definitions and macros for PIM_PA_CONFIGn */
#define PIM_PIFR                   (0x0001)       /*  Pin Interrupt Flag Register */
#define PIM_PIER                   (0x0002)       /*  Pin Interrupt Enable Register */
#define PIM_PULL(x)                (((x)&0x0003)<<2)    /*  Pull-up/down Enable Register */
#define PIM_RDR                    (0x0010)       /*  Reduced Drive Strength Register */
#define PIM_ODER                   (0x0020)       /*  Open Drain Enable Register */
#define PIM_DDR                    (0x0040)       /*  Data Direction Register */
#define PIM_MODE                   (0x0080)       /*  Pin Mode Register */

/* Bit definitions and macros for PIM_GLBLINT */
#define PIM_INT_PENDING(x)         (((x)&0x01FF)<<0)    /*  Interrupt Pending */

/* Bit definitions and macros for PIM_PIMCONFIG */
#define PIM_PORTHSEL               (0x0001)       /*  Clock Enable for the EIM module */
#define PIM_EIMCLKEN               (0x0002)       /*  Port H Select */

/*********************************************************************
*
* PIT Module (PIT)
*
*********************************************************************/

/* Register read/write macros */
#define PIT_TLVAL0                 (*(vuint32_t *)(0xFC08C000)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL1                 (*(vuint32_t *)(0xFC08C004)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL2                 (*(vuint32_t *)(0xFC08C008)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL3                 (*(vuint32_t *)(0xFC08C00C)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL4                 (*(vuint32_t *)(0xFC08C010)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL5                 (*(vuint32_t *)(0xFC08C014)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL6                 (*(vuint32_t *)(0xFC08C018)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL7                 (*(vuint32_t *)(0xFC08C01C)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL8                 (*(vuint32_t *)(0xFC08C020)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL9                 (*(vuint32_t *)(0xFC08C024)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL10                (*(vuint32_t *)(0xFC08C028)) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TLVAL(x)               (*(vuint32_t *)(0xFC08C000+((x)*0x004))) /* TLVAL[n] - PIT RTI / Timer Load Value Registers */
#define PIT_TVAL0                  (*(vuint32_t *)(0xFC08C080)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL1                  (*(vuint32_t *)(0xFC08C084)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL2                  (*(vuint32_t *)(0xFC08C088)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL3                  (*(vuint32_t *)(0xFC08C08C)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL4                  (*(vuint32_t *)(0xFC08C090)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL5                  (*(vuint32_t *)(0xFC08C094)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL6                  (*(vuint32_t *)(0xFC08C098)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL7                  (*(vuint32_t *)(0xFC08C09C)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL8                  (*(vuint32_t *)(0xFC08C0A0)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL9                  (*(vuint32_t *)(0xFC08C0A4)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL10                 (*(vuint32_t *)(0xFC08C0A8)) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_TVAL(x)                (*(vuint32_t *)(0xFC08C080+((x)*0x004))) /* TVAL[n] - PIT Current RTI / Timer Value Registers */
#define PIT_FLG                    (*(vuint32_t *)(0xFC08C100)) /* FLG - PIT Interrupt Flags Register */
#define PIT_INTEN                  (*(vuint32_t *)(0xFC08C104)) /* INTEN - PIT Interrupt Enable Register */
#define PIT_INTSEL                 (*(vuint32_t *)(0xFC08C108)) /* INTSEL - PIT Interrupt/DMA Select Registers */
#define PIT_EN                     (*(vuint32_t *)(0xFC08C10C)) /* EN - PIT Timer Enable Register */
#define PIT_CTRL                   (*(vuint32_t *)(0xFC08C110)) /* CTRL - PIT Control Register */

/* Bit definitions and macros for PIT_TLVALn */
#define PIT_TSV(x)                 (((x)&0x00FFFFFF)<<0)    /*  Time Start Value */

/* Bit definitions and macros for PIT_TVALn */
#define PIT_TVL(x)                 (((x)&0x00FFFFFF)<<0)    /*  Current Timer Value */

/* Bit definitions and macros for PIT_FLG */
#define PIT_RTIF                   (0x00000001)   /*  Real Time Int Flag */
#define PIT_TIF1                   (0x00000002)   /*  Real Time Int Flag for Timer 1 */
#define PIT_TIF2                   (0x00000004)   /*  Real Time Int Flag for Timer 2 */
#define PIT_TIF3                   (0x00000008)   /*  Real Time Int Flag for Timer 3 */
#define PIT_TIF4                   (0x00000010)   /*  Real Time Int Flag for Timer 4 */

/* Bit definitions and macros for PIT_INTEN */
#define PIT_RTIE                   (0x00000001)   /*  Real Time Interrupt Enable Bit */
#define PIT_TIE1                   (0x00000002)   /*  Timer 1 Interrupt Enable Bit */
#define PIT_TIE2                   (0x00000004)   /*  Timer 2 Interrupt Enable Bit */
#define PIT_TIE3                   (0x00000008)   /*  Timer 3 Interrupt Enable Bit */
#define PIT_TIE4                   (0x00000010)   /*  Timer 4 Interrupt Enable Bit */

/* Bit definitions and macros for PIT_INTSEL */
#define PIT_ISEL1                  (0x00000002)   /*  Interrupt Selector 1 */
#define PIT_ISEL2                  (0x00000004)   /*  Interrupt Selector 2 */
#define PIT_ISEL3                  (0x00000008)   /*  Interrupt Selector 3 */
#define PIT_ISEL4                  (0x00000010)   /*  Interrupt Selector 4 */

/* Bit definitions and macros for PIT_EN */
#define PIT_PEN0                   (0x00000001)   /*  Timer Enable Bit */
#define PIT_PEN1                   (0x00000002)   /*  Timer Enable Bit */
#define PIT_PEN2                   (0x00000004)   /*  Timer Enable Bit */
#define PIT_PEN3                   (0x00000008)   /*  Timer Enable Bit */
#define PIT_PEN4                   (0x00000010)   /*  Timer Enable Bit */
#define PIT_PEN5                   (0x00000020)   /*  Timer Enable Bit */
#define PIT_PEN6                   (0x00000040)   /*  Timer Enable Bit */
#define PIT_PEN7                   (0x00000080)   /*  Timer Enable Bit */
#define PIT_PEN8                   (0x00000100)   /*  Timer Enable Bit */
#define PIT_PEN9                   (0x00000200)   /*  Timer Enable Bit */
#define PIT_PEN10                  (0x00000400)   /*  Timer Enable Bit */

/* Bit definitions and macros for PIT_CTRL */
#define PIT_MDIS                   (0x01000000)   /*  Module Disable */
#define PIT_DOZE                   (0x02000000)   /*  Disable Module in Doze Mode */

/*********************************************************************
*
* SSM Module (SSM)
*
*********************************************************************/

/* Register read/write macros */
#define SSM_STATUS                 (*(vuint16_t *)(0xFC080002))
#define SSM_MEMCONFIG              (*(vuint16_t *)(0xFC080004))
#define SSM_ERROR                  (*(vuint16_t *)(0xFC080008))
#define SSM_DEBUGPORT              (*(vuint16_t *)(0xFC08000E))

/* Bit definitions and macros for SSM_STATUS */
#define SSM_DMAACTCH(x)            (((x)&0x000F)<<0)    /*  Active DMA Channel */
#define SSM_DMAIDLE                (0x0010)       /*  DMA Is Idle */
#define SSM_MODE(x)                (((x)&0x0003)<<5)    /*  Device Mode */
#define SSM_SEC                    (0x0080)       /*  Security Status */
#define SSM_EIM_SIZE(x)            (((x)&0x0003)<<8)    /*  EIM Port Size */
#define SSM_EIM_ACK                (0x0400)       /*  EIM Acknowledge */
#define SSM_NEXUS(x)               (((x)&0x0003)<<11)   /*  Nexus Status */

/* Bit definitions and macros for SSM_MEMCONFIG */
#define SSM_DFLASHVALID            (0x0001)       /*  Data Flash Valid */
#define SSM_DFLASHSIZE(x)          (((x)&0x000F)<<1)    /*  Data Flash Size */
#define SSM_IFLASHVALID            (0x0020)       /*  Instruction Flash Valid */
#define SSM_IFLASHSIZE(x)          (((x)&0x000F)<<6)    /*  Instruction Flash Size */
#define SSM_SRAMVALID              (0x0400)       /*  SRAM Valid */
#define SSM_SRAMSIZE(x)            (((x)&0x000F)<<11)   /*  SRAM Size */
#define SSM_SRHOLE                 (0x8000)       /*  SRAM Hole */

/* Bit definitions and macros for SSM_ERROR */
#define SSM_BABORT                 (0x0001)       /*  Bus Abort Enable */

/* Bit definitions and macros for SSM_DEBUGPORT */
#define SSM_DEBUG_MODE(x)          (((x)&0x0007)<<0)    /*  Debug Status Port Mode */

/*********************************************************************
*
* VREG Module (VREG)
*
*********************************************************************/

/* Register read/write macros */
#define VREG_CTRL                  (*(vuint8_t  *)(0xFC090001)) /* CTRL - Control Register */
#define VREG_APICL                 (*(vuint8_t  *)(0xFC090002)) /* Autonomous Periodical Interrupt Control Register */
#define VREG_APITR                 (*(vuint8_t  *)(0xFC090003)) /* Autonomous Periodical Interrupt Trimming Register */

/* Bit definitions and macros for VREG_CTRL */
#define VREG_LVIF                  (0x01)         /*  Low Voltage Interrupt Flag */
#define VREG_LVIE                  (0x02)         /*  Low Voltage Interrupt Enable Bit */
#define VREG_LVDS                  (0x04)         /*  Low Voltage Detect Status Bit */

/* Bit definitions and macros for VREG_APICL */
#define VREG_APIF                  (0x01)         /*  API Interrupt Flag */
#define VREG_APIE                  (0x02)         /*  API Interrupt Enable Bit */
#define VREG_APIFE                 (0x04)         /*  API Feature Enable Bit */
#define VREG_APIR(x)               (((x)&0x0F)<<3)  /*  API Rate Bits */
#define VREG_APICLK                (0x80)         /*  API Clock Select Bit */

/* Bit definitions and macros for VREG_APITR */
#define VREG_PITR(x)               (((x)&0x3F)<<2)  /*  Period Trimming Bits */

/********************************************************************/

#endif /* __MAC7100_H__ */

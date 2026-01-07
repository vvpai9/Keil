/***********************************************************************
 * $Id:: lh7a404_smc.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 SMC definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         Static Memory Controller 
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

#ifndef LH7A404_SMC_H
#define LH7A404_SMC_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * Static Memory Controller Module Register Structure
 **********************************************************************/

/* SMC Module Register Structure */ 
typedef struct
{
    volatile UNS_32 bcr0;            /* SMC bank 0 config register */
    volatile UNS_32 bcr1;            /* SMC bank 1 config register */
    volatile UNS_32 bcr2;            /* SMC bank 2 config register */
    volatile UNS_32 bcr3;            /* SMC bank 3 config register */
    volatile UNS_32 reserved1;       /* SMC reserved 1 */
    volatile UNS_32 reserved2;       /* SMC reserved 1 */
    volatile UNS_32 bcr6;            /* SMC bank 6 config register */
    volatile UNS_32 bcr7;            /* SMC bank 7 config register */
    volatile UNS_32 pc1_attribute;   /* SMC card 1 attribute register */
    volatile UNS_32 pc1_common;      /* SMC card 1 common register */
    volatile UNS_32 pc1_io;          /* SMC card 1 IO space register */
    volatile UNS_32 reserved3;       /* SMC reserved 3 */
    volatile UNS_32 pc2_attribute;   /* SMC card 2 attribute register */
    volatile UNS_32 pc2_common;      /* SMC card 2 common register */
    volatile UNS_32 pc2_io;          /* SMC card 2 IO space register */
    volatile UNS_32 reserved4;       /* SMC reserved 4 */
    volatile UNS_32 pcmcia_control;  /* SMC PC card control register */
} SMC_REGS_T;

/***********************************************************************
 * SMC Bank Configuration register defines
 **********************************************************************/

/* SMC BCR register idle time load macro */
#define SMC_BCR_IDCY(n) _SBF(0, ((n) & 0x0F))
/* SMC BCR register read wait state load macro */
#define SMC_BCR_WST1(n) _SBF(5, ((n) & 0x1F))
#define SMC_BCR_RBLE    0x00000400   /* SMC read byte lane enable bit */
/* SMC BCR register write wait state load macro */
#define SMC_BCR_WST2(n) _SBF(11, ((n) & 0x1F))
#define SMC_BCR_WPERR   0x02000000   /* SMC write protect error flag */
#define SMC_BCR_WP      0x04000000   /* SMC write protect enable */
#define SMC_BCR_PME     0x08000000   /* SMC page mode enable */
#define SMC_BCR_MW8     0x00000000   /* SMC 8 bit memory width */
#define SMC_BCR_MW16    0x10000000   /* SMC 16 bit memory width */
#define SMC_BCR_MW32    0x20000000   /* SMC 32 bit memory width */
#define SMC_BCR_BRKDIS  0x40000000   /* SMC EBI break disable bit */

/***********************************************************************
 * PCMCIA Attribute, Common, and IO Space Configuration register
 * defines
 **********************************************************************/

/* SMC PC card pre-charge delay load macro */
#define PCMCIA_CFG_PC(n) _SBF(0, ((n) & 0xFF))
/* SMC PC card hold time load macro */
#define PCMCIA_CFG_HT(n) _SBF(8, ((n) & 0x0F))
/* SMC PC card access time load macro */
#define PCMCIA_CFG_AC(n) _SBF(16, ((n) & 0xFF))
#define PCMCIA_CFG_W8    0x00000000  /* SMC PC card 8 bit mode */
#define PCMCIA_CFG_W16   0x80000000  /* SMC PC card 16 bit mode */

/***********************************************************************
 * PCMCIA Control register defines
 **********************************************************************/

/* SMC PC Card disable */
#define PCMCIA_CONTROL_NONE      0x00000000
/* SMC PC Card CF mode on slot 1 */
#define PCMCIA_CONTROL_CF        0x00000001
/* SMC PC Card PC mode on slot 1 */
#define PCMCIA_CONTROL_PC        0x00000002
/* SMC PC Card CF mode on slot 1 and PC mode on slot 2 */
#define PCMCIA_CONTROL_CFPC      0x00000003
/* SMC PC Card reset card 1 */
#define PCMCIA_CONTROL_PC1RST    0x00000004
/* SMC PC Card reset card 2 */
#define PCMCIA_CONTROL_PC2RST    0x00000008
/* SMC PC Card normal mode (no resets) */
#define PCMCIA_CONTROL_PCNORMAL  0x00000000
/* SMC PC Card slot 1 wait state enable (nWAIT) */
#define PCMCIA_CONTROL_WEN1      0x00000010
/* SMC PC Card slot 2 wait state enable (nWAIT) */
#define PCMCIA_CONTROL_WEN2      0x00000020
/* SMC PC Card manual PCREG mode */
#define PCMCIA_CONTROL_MANPREG   0x00000100
/* SMC PC Card automatic PCREG mode */
#define PCMCIA_CONTROL_AUTOPREG  0x00000000

/* Macro pointing to SMC registers */
#define SMC ((SMC_REGS_T *)(SMC_REGS_BASE))

#endif /* LH7A404_SMC_H */

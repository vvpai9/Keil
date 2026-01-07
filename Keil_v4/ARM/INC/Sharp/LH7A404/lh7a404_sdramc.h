/***********************************************************************
 * $Id:: lh7a404_sdramc.h 14 2007-08-28 16:08:18Z kevinw               $
 *
 * Project: LH7A404 SDRAM controller definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for LH7A404 component:
 *         SDRAM controller
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

#ifndef LH7A404_SDRAMC_H
#define LH7A404_SDRAMC_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * SDRAM Controller Module Register Structure
 **********************************************************************/

/* SDRAM controller Module Register Structure */ 
typedef struct
{
    volatile UNS_32 reserved;  /* SDRAM controller reserved register */
    volatile UNS_32 global;    /* SDRAM controller global register */
    volatile UNS_32 refresh;   /* SDRAM controller refresh register */
    volatile UNS_32 boot;      /* SDRAM controller boot register */
    volatile UNS_32 nsdcs0;    /* SDRAM controller select 0 register */
    volatile UNS_32 nsdcs1;    /* SDRAM controller select 1 register */
    volatile UNS_32 nsdcs2;    /* SDRAM controller select 2 register */
    volatile UNS_32 nsdcs3;    /* SDRAM controller select 3 register */
} SDRAMC_REGS_T;

/***********************************************************************
 * SDRAM Configuration register defines
 **********************************************************************/

/* SDRAM synchronuous memory clock enable */
#define SDRAM_GLOBAL_CKE          0x80000000
/* SDRAM synchronuous memory clock shutdown enable */
#define SDRAM_GLOBAL_CLKSHUTDOWN  0x40000000
/* SDRAM bus arbitration enable bit */
#define SDRAM_GLOBAL_REARB_EN     0x00000080
/* SDRAM load command bit */
#define SDRAM_GLOBAL_LCR          0x00000040
/* SDRAM memory busy state bit */
#define SDRAM_GLOBAL_SMEMBUSY     0x00000020
/* SDRAM memory busy state bit */
#define SDRAM_GLOBAL_MRS          0x00000002 /* SDRAM MRS bit */
#define SDRAM_GLOBAL_INITIALISE   0x00000001 /* SDRAM initialize bit */
#define SDRAM_GLOBAL_NOP          0x00000003 /* SDRAM NOP mode */
#define SDRAM_GLOBAL_PREALL       0x00000001 /* SDRAM percharge mode */
#define SDRAM_GLOBAL_ENAMODE      0x00000002 /* SDRAM 'mode' mode */
/* SDRAM load command bits */
#define SDRAM_GLOBAL_ENACMD       0x00000042 
#define SDRAM_GLOBAL_NORMAL       0x00000000 /* SDRAM normal mode */

/***********************************************************************
 * SDRAM nSDCSx Device Configuration register defines
 **********************************************************************/

/* SDRAM autoprecharge bit */
#define SDRAM_NSDCS_AUTOPRECHARGE  0x01000000
/* SDRAM RAS to CAS latency is 2 */
#define SDRAM_NSDCS_RASTOCAS_RASL2 0x00200000
/* SDRAM RAS to CAS latency is 3 */
#define SDRAM_NSDCS_RASTOCAS_RASL3 0x00300000
/* SDRAM Disable write burst bit */
#define SDRAM_NSDCS_WBL            0x00080000
#define SDRAM_NSDCS_CASLAT2        0x00010000 /* SDRAM CAS latency 2 */
#define SDRAM_NSDCS_CASLAT3        0x00020000 /* SDRAM CAS latency 3 */
#define SDRAM_NSDCS_CASLAT4        0x00030000 /* SDRAM CAS latency 4 */
#define SDRAM_NSDCS_CASLAT5        0x00040000 /* SDRAM CAS latency 5 */
#define SDRAM_NSDCS_CASLAT6        0x00050000 /* SDRAM CAS latency 6 */
#define SDRAM_NSDCS_CASLAT7        0x00060000 /* SDRAM CAS latency 7 */
#define SDRAM_NSDCS_CASLAT8        0x00070000 /* SDRAM CAS latency 8 */
#define SDRAM_NSDCS_2KPAGE         0x00000040
/* SROM look-alike mode bit */
#define SDRAM_NSDCS_SROMLL         0x00000020
/* SROM maximum burst size of 512 bytes bit */
#define SDRAM_NSDCS_SROM512        0x00000010
#define SDRAM_NSDCS_BANKCOUNT4     0x00000008 /* SDRAM 4 banks bit */
/* SDRAM external bus width is 32 bits */
#define SDRAM_NSDCS_EBW32          0x00000000
/* SDRAM external bus width is 16 bits */
#define SDRAM_NSDCS_EBW16          0x00000004

/***********************************************************************
 * SDRAM Boot Status register defines
 **********************************************************************/

/* SDRAM status media change synchronous ROM boot bit */
#define SDRAM_BOOT_MEDCHG_SYNCH   0x00000004
/* SDRAM status media change asynchronous ROM boot bit */
#define SDRAM_BOOT_MEDCHG_ASYNCH  0x00000000
/* SDRAM status synchronous 32-bit boot value */
#define SDRAM_BOOT_SYNCHROM32     0x00000003
/* SDRAM status synchronous 32-bit syncflash value */
#define SDRAM_BOOT_SYNCHFLASH32   0x00000002
/* SDRAM status synchronous 16-bit boot value */
#define SDRAM_BOOT_SYNCHROM16     0x00000001
/* SDRAM status synchronous 16-bit syncflash boot value */
#define SDRAM_BOOT_SYNCHFLASH16   0x00000000
/* SDRAM status asynchronous 32-bit boot value */
#define SDRAM_BOOT_ASYNCH32       0x00000002
/* SDRAM status asynchronous 16-bit boot value */
#define SDRAM_BOOT_ASYNCH16       0x00000001
/* SDRAM status asynchronous 8-bit boot value */
#define SDRAM_BOOT_ASYNCH8        0x00000000
/* SDRAM status value when booting from 8-bit asynchronous flash */
#define SDRAM_BOOT_ROM8           (SDRAM_BOOT_ASYNCH8 | \
                                   SDRAM_BOOT_ASYNCHROM)
/* SDRAM status value when booting from 16-bit asynchronous flash */
#define SDRAM_BOOT_ROM16          (SDRAM_BOOT_ASYNCH16 | \
                                   SDRAM_BOOT_ASYNCHROM)
/* SDRAM status value when booting from 32-bit asynchronous flash */
#define SDRAM_BOOT_ROM32          (SDRAM_BOOT_ASYNCH32 | \
                                   SDRAM_BOOT_ASYNCHROM)
/* SDRAM status value when booting from 16-bit synchflash */
#define SDRAM_BOOT_SFLASH16       (SDRAM_BOOT_SYNCHFLASH16 | \
                                   SDRAM_BOOT_SYNCHROM)
/* SDRAM status value when booting from 16-bit ROM */
#define SDRAM_BOOT_SROM16         (SDRAM_BOOT_SYNCHROM16 | \
                                   SDRAM_BOOT_SYNCHROM)
/* SDRAM status value when booting from 32-bit synchflash */
#define SDRAM_BOOT_SFLASH32       (SDRAM_BOOT_SYNCHFLASH32 | \
                                   SDRAM_BOOT_SYNCHROM)
/* SDRAM status value when booting from 32-bit ROM */
#define SDRAM_BOOT_SROM32         (SDRAM_BOOT_SYNCHROM32 | \
                                   SDRAM_BOOT_SYNCHROM)

/***********************************************************************
 * SDRAM Refresh Timer register defines
 **********************************************************************/

/* SDRAM refresh register load value macro */
#define SDRAM_REFTMR_REFCNT(n)      ((n) & 0xFFFF)

/* Macro pointing to SDRAM controller registers */
#define SDRAMC ((SDRAMC_REGS_T *)(SDRAM_REGS_BASE))

#endif /* LH7A404_SDRAMC_H */

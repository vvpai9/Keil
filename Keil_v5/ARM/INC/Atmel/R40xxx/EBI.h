/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  EBI.H:  Header file for External Bus Interface                     */
/*                                                                     */
/***********************************************************************/

#ifndef __EBI_H
#define __EBI_H


/*---------------*/
/* EBI Registers */
/*---------------*/
#define EBI_CSR0   REG(EBI_BASE + 0x00)    /* Chip Select Register 0 */
#define EBI_CSR1   REG(EBI_BASE + 0x04)    /* Chip Select Register 1 */
#define EBI_CSR2   REG(EBI_BASE + 0x08)    /* Chip Select Register 2 */
#define EBI_CSR3   REG(EBI_BASE + 0x0C)    /* Chip Select Register 3 */
#define EBI_CSR4   REG(EBI_BASE + 0x10)    /* Chip Select Register 4 */
#define EBI_CSR5   REG(EBI_BASE + 0x14)    /* Chip Select Register 5 */
#define EBI_CSR6   REG(EBI_BASE + 0x18)    /* Chip Select Register 6 */
#define EBI_CSR7   REG(EBI_BASE + 0x1C)    /* Chip Select Register 7 */
#define EBI_RCR    REG(EBI_BASE + 0x20)    /* Remap Control Register */
#define EBI_MCR    REG(EBI_BASE + 0x24)    /* Memory Control Register */
#ifdef AT91M42800
#define EBI_ASR    REG(EBI_BASE + 0x30)    /* Abort Status Register */
#define EBI_AASR   REG(EBI_BASE + 0x34)    /* Address Abort Status Register */
#endif


/*--------------------------------*/
/* EBI_CSR: Chip Select Registers */
/*--------------------------------*/

#define EBI_DBW              (3<<0)        /* Data Bus Width */
#define EBI_DBW_16           (1<<0)        /* 16-bit Data Bus */
#define EBI_DBW_8            (2<<0)        /* 8-bit Data Bus */

#define EBI_NWS              (7<<2)        /* Number of Wait States */
#define EBI_NWS_1            (0<<2)        /* 1 Wait State */
#define EBI_NWS_2            (1<<2)        /* 2 Wait States */
#define EBI_NWS_3            (2<<2)        /* 3 Wait States */
#define EBI_NWS_4            (3<<2)        /* 4 Wait States */
#define EBI_NWS_5            (4<<2)        /* 5 Wait States */
#define EBI_NWS_6            (5<<2)        /* 6 Wait States */
#define EBI_NWS_7            (6<<2)        /* 7 Wait States */
#define EBI_NWS_8            (7<<2)        /* 8 Wait States */

#define EBI_WSE              (1<<5)        /* Wait State Enable */

#define EBI_PAGES            (3<<7)        /* Page Size */
#define EBI_PAGES_1M         (0<<7)        /* 1M Bytes */
#define EBI_PAGES_4M         (1<<7)        /* 4M Bytes */
#define EBI_PAGES_16M        (2<<7)        /* 16M Bytes */
#define EBI_PAGES_64M        (3<<7)        /* 64M Bytes */

#define EBI_TDF              (7<<9)        /* Data Float Output Time */
#define EBI_TDF_0            (0<<9)        /* 0 Cycles added */
#define EBI_TDF_1            (1<<9)        /* 1 Cycles added */
#define EBI_TDF_2            (2<<9)        /* 2 Cycles added */
#define EBI_TDF_3            (3<<9)        /* 3 Cycles added */
#define EBI_TDF_4            (4<<9)        /* 4 Cycles added */
#define EBI_TDF_5            (5<<9)        /* 5 Cycles added */
#define EBI_TDF_6            (6<<9)        /* 6 Cycles added */
#define EBI_TDF_7            (7<<9)        /* 7 Cycles added */

#define EBI_BAT              (1<<12)       /* Byte Access Type */
#define EBI_BAT_BYTE_WRITE   (0<<12)       /* Byte Write Access Type */
#define EBI_BAT_BYTE_SELECT  (1<<12)       /* Byte Select Access Type */

#define EBI_CSEN             (1<<13)       /* Chip Select Enable */

#define EBI_BA               (0x0FFF<<20)  /* Base Address Mask */
#define EBI_B_BA             20            /* Base Address Bit Shift */

/*---------------------------------*/
/* EBI_RCR: Remap Control Register */
/*---------------------------------*/
#define EBI_RCB              (1<<0)        /* Remap Command Bit */

/*----------------------------------*/
/* EBI_MCR: Memory Control Register */
/*----------------------------------*/

#define EBI_ALE              7             /* Address Line Enable */
#define EBI_ALE_16M          0             /* Bank Size 16M Bytes */
#define EBI_ALE_8M           4             /* Bank Size 8M Bytes */
#define EBI_ALE_4M           5             /* Bank Size 4M Bytes */
#define EBI_ALE_2M           6             /* Bank Size 2M Bytes */
#define EBI_ALE_1M           7             /* Bank Size 1M Bytes */

#define EBI_DRP              (1<<4)        /* Data Read Protocol */
#define EBI_DRP_STANDARD     (0<<4)        /* Standard Read Protocol */
#define EBI_DRP_EARLY        (1<<4)        /* Early Read Protocol */

/*-------------------------------------------------------------------*/
/* EBI_MCR: Abort Status Register - Defined only for the AT91M42800  */
/*-------------------------------------------------------------------*/
#ifdef AT91M42800

#define EBI_UNDADD             (1<<0)      /* Undefined Address Abort Status */
#define EBI_MISADD             (1<<1)      /* Misaligned Address Abort Status */

#define EBI_ABTSZ              (3<<8)      /* Abort Size Status */
#define EBI_ABTSZ_IN_BYTE      (0<<8)      /* Abort Size in Byte */
#define EBI_ABTSZ_IN_HALF_WORD (1<<8)      /* Abort Size in Half-word */
#define EBI_ABTSZ_IN_WORD      (2<<8)      /* Abort Size in Word */

#define EBI_ABTTYP             (3<<10)     /* Abort Type Status */
#define EBI_ABTTYP_READ        (0<<10)     /* Abort Type = Data Read */
#define EBI_ABTTYP_WRITE       (1<<10)     /* Abort Type = Data Write */
#define EBI_ABTTYP_CODE_FETCH  (2<<10)     /* Abort Type = Code Fetch */

#define EBI_ARM                (1<<12)     /* Abort Induced by the ARM Core */
#define EBI_PDC                (1<<13)     /* Abort Induced by the PDC */

#endif /* AT91M42800 */


#endif /* __EBI_H */

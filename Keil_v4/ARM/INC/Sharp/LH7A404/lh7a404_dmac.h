/***********************************************************************
 * $Id:: lh7a404_dmac.h 14 2007-08-28 16:08:18Z kevinw                 $
 *
 * Project: LH7A404 DMA controller definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for LH7A404 component:
 *         DMA controller
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

#ifndef LH7A404_DMAC_H
#define LH7A404_DMAC_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * DMAC Module Register Structures
 **********************************************************************/

/* DMA controller Module M2P address and count register structure */
typedef struct
{
    volatile UNS_32 maxcnt;        /* DMA max terminal count register */
    volatile UNS_32 base;          /* DMA base address register */
    volatile UNS_32 current;       /* DMA current address register */
    volatile UNS_32 reserved;
} DMAC_ACREG_T;

/* DMA controller Module Channel Register Structure for M2P channels */
typedef struct
{
    volatile UNS_32 control;       /* DMA control register */
    volatile UNS_32 interrupt;     /* DMA interrupt status register */
    volatile UNS_32 palloc;        /* DMA peripheral allocation reg */
    volatile UNS_32 cntl_stat;     /* DMA status register */
    volatile UNS_32 reserved2;
    volatile UNS_32 remain;        /* DMA bytes remaining register */
    volatile UNS_32 reserved3[2];
    DMAC_ACREG_T    addr_cnt[2];   /* DMA address/count registers */
} DMA_BLOCK_T;

/* DMA controller Module Channel Register Structure for M2M channels */
typedef struct
{
    volatile UNS_32 control;       /* DMA control register */
    volatile UNS_32 interrupt;     /* DMA interrupt status register */
    volatile UNS_32 reserved1;
    volatile UNS_32 cntl_stat;     /* DMA status register */
    volatile UNS_32 bcr0;          /* DMA ch 0a bytes remaining reg */
    volatile UNS_32 bcr1;          /* DMA ch 0b bytes remaining reg */
    volatile UNS_32 sar_base0;     /* DMA ch 0a source base addr reg */
    volatile UNS_32 sar_base1;     /* DMA ch 0b source base addr reg */
    volatile UNS_32 reserved2;
    volatile UNS_32 sar_current0;  /* DMA ch 0a current base addr reg */
    volatile UNS_32 sar_current1;  /* DMA ch 0b current base addr reg */
    volatile UNS_32 dar_base0;     /* DMA ch 0a dest base addr reg */
    volatile UNS_32 dar_base1;     /* DMA ch 0b dest base addr reg */
    volatile UNS_32 dar_current0;  /* DMA ch 0a current dest addr reg */
    volatile UNS_32 reserved3;
    volatile UNS_32 dar_current1;  /* DMA ch 0b current dest addr reg */
} DMA_MM_BLOCK_T;

/* DMA controller Module Register Structure */ 
typedef struct
{
    DMA_BLOCK_T     chregs[14];    /* DMA channels registers */
    volatile UNS_32 dma_ch_arb;    /* DMA channel arbitration reg */
    volatile UNS_32 reserved[15];
    volatile UNS_32 dma_global_int; /* DMA global interrupt register */
} DMA_REGS_T;

/***********************************************************************
 * DMA control register definitions
 **********************************************************************/

/* DMA control/status stall interrupt enable bit */
#define DMAC_STALL            0x00000001
/* DMA control/status new FIFO interrupt enable bit */
#define DMAC_NFB              0x00000002
/* DMA control/status channel error interrupt enable bit */
#define DMAC_CHERROR          0x00000008
/* DMA control channel enable bit */
#define DMAC_ENABLE           0x00000010
/* DMA control abort enable bit */
#define DMAC_ABORT            0x00000020
/* DMA control interrupt control (supress channel error) enable bit */
#define DMAC_ICE              0x00000040

/***********************************************************************
 * DMA peripheral allocation register definitions
 **********************************************************************/

/* DMA peripheral allocation reg TX channel USB device */
#define DMAC_TX_USB_SEL       0x00000000
/* DMA peripheral allocation reg TX channel SDMMC device */
#define DMAC_TX_SDMMC_SEL     0x00000001
/* DMA peripheral allocation reg TX channel AC97 channel 1 device */
#define DMAC_TX_AC971_SEL     0x00000002
/* DMA peripheral allocation reg TX channel AC97 channel 2 device */
#define DMAC_TX_AC972_SEL     0x00000003
/* DMA peripheral allocation reg TX channel AC97 channel 3 device */
#define DMAC_TX_AC973_SEL     0x00000004
/* DMA peripheral allocation reg TX channel UART channel 1 device */
#define DMAC_TX_UART1_SEL     0x00000006
/* DMA peripheral allocation reg TX channel UART channel 2 device */
#define DMAC_TX_UART2_SEL     0x00000007
/* DMA peripheral allocation reg TX channel UART channel 3 device */
#define DMAC_TX_UART3_SEL     0x00000008
/* DMA peripheral allocation reg RX channel USB device */
#define DMAC_RX_USB_SEL       0x00000000
/* DMA peripheral allocation reg RX channel SDMMC device */
#define DMAC_RX_SDMMC_SEL     0x00000001
/* DMA peripheral allocation reg RX channel AC97 channel 1 device */
#define DMAC_RX_AC971_SEL     0x00000002
/* DMA peripheral allocation reg RX channel AC97 channel 2 device */
#define DMAC_RX_AC972_SEL     0x00000003
/* DMA peripheral allocation reg RX channel AC97 channel 3 device */
#define DMAC_RX_AC973_SEL     0x00000004
/* DMA peripheral allocation reg RX channel UART channel 1 device */
#define DMAC_RX_UART1_SEL     0x00000006
/* DMA peripheral allocation reg RX channel UART channel 2 device */
#define DMAC_RX_UART2_SEL     0x00000007
/* DMA peripheral allocation reg RX channel UART channel 3 device */
#define DMAC_RX_UART3_SEL     0x00000008

/***********************************************************************
 * DMA status register definitions
 **********************************************************************/

/* DMA status next buffer bit */
#define DMAC_NEXTBUFFER       0x00000040
/* DMA status current state retrieve macro */
#define DMAC_CURRENTSTATE(n)  (((n) & 0x30) >> 4)
/* DMA status idle state */
#define DMAC_STATE_IDLE       0
/* DMA status stall state */
#define DMAC_STATE_STALL      1
/* DMA status on state */
#define DMAC_STATE_ON         2
/* DMA status next buffer state */
#define DMAC_STATE_NEXT       3
/* DMA status DMA byte stored retrieve macro */
#define DMAC_STATUS_BYTES(n)  (((n) & 0xF80) >> 7)

/***********************************************************************
 * DMA global interrupt register definitions
 **********************************************************************/

#define DMAC_CH1_INT    0x00000001 /* DMAC channel 1 int bit */
#define DMAC_CH0_INT    0x00000002 /* DMAC channel 0 int bit */
#define DMAC_CH3_INT    0x00000004 /* DMAC channel 3 int bit */
#define DMAC_CH2_INT    0x00000008 /* DMAC channel 2 int bit */
#define DMAC_CH5_INT    0x00000010 /* DMAC channel 5 int bit */
#define DMAC_CH4_INT    0x00000020 /* DMAC channel 4 int bit */
#define DMAC_CH7_INT    0x00000040 /* DMAC channel 7 int bit */
#define DMAC_CH6_INT    0x00000080 /* DMAC channel 6 int bit */
#define DMAC_CH9_INT    0x00000100 /* DMAC channel 9 int bit */
#define DMAC_CH8_INT    0x00000200 /* DMAC channel 8 int bit */
#define DMAC_MMCH0_INT  0x00000400 /* DMAC M2M channel 0 int bit */
#define DMAC_MMCH1_INT  0x00000800 /* DMAC M2M channel 1 int bit */

/***********************************************************************
 * DMA channel aribtration register definitions
 **********************************************************************/

/* DMAC channel aribtration register select M2M priority over M2P */
#define DMAC_M2M_PRIOR  0x00000001
/* DMAC channel aribtration register select M2P priority over M2M */
#define DMAC_M2P_PRIOR  0x00000000

/***********************************************************************
 * DMA M2M control additional register definitions
 **********************************************************************/

/* DMAC M2M control register source copy transfer bit */
#define DMAC_MM_SCT     0x00000002
/* DMAC M2M control register done interrupt enable bit */
#define DMAC_MM_DONE_EN 0x00000004
/* DMAC M2M control register start transfer bit */
#define DMAC_MM_START   0x00000010
/* DMAC M2M control register burst size of 16 bytes */
#define DMAC_MM_B16     0x00000080
/* DMAC M2M control register burst size of 32 bytes */
#define DMAC_MM_B32     0x000000A0
/* DMAC M2M control register burst size of 64 bytes */
#define DMAC_MM_B64     0x000000C0
/* DMAC M2M control register burst size of 128 bytes */
#define DMAC_MM_B128    0x000000E0
/* DMAC M2M control register burst size of 256 bytes */
#define DMAC_MM_B256    0x00000100
/* DMAC M2M control register burst size of 512 bytes */
#define DMAC_MM_B512    0x00000120
/* DMAC M2M control register burst size of 1024 bytes */
#define DMAC_MM_B1024   0x00000140
/* DMAC M2M control register burst size of 2046 bytes */
#define DMAC_MM_B2048   0x00000160
/* DMAC M2M control register burst size of 4096 bytes */
#define DMAC_MM_B4096   0x00000180
/* DMAC M2M control register burst size of 8192 bytes */
#define DMAC_MM_B8192   0x000001A0
/* DMAC M2M control register burst size of 16384 bytes */
#define DMAC_MM_B16384  0x000001C0
/* DMAC M2M control register burst size of 32768 bytes */
#define DMAC_MM_B32768  0x000001E0
/* DMAC M2M ocntrol register peripheral width is 8-bits */
#define DMAC_MM_PW_8BT  0x00000000
/* DMAC M2M ocntrol register peripheral width is 16-bits */
#define DMAC_MM_PW_16BT 0x00000200
/* DMAC M2M ocntrol register peripheral width is 32-bits */
#define DMAC_MM_PW_32BT 0x00000400
/* DMAC M2M control register destination address hold bit */
#define DMAC_MM_DAH     0x00000800
/* DMAC M2M control register source address hold bit */
#define DMAC_MM_SAH     0x00001000
/* DMAC M2M control register transfer mode is sw initiated */
#define DMAC_MM_SWTRAN  0x00000000
/* DMAC M2M control register transfer mode is hardware M2P */
#define DMAC_MM_M2PTRAN 0x00002000
/* DMAC M2M control register transfer mode is hardware P2M */
#define DMAC_MM_P2MTRAN 0x00004000
/* DMAC M2M control register EOT polarity is active low input */
#define DMAC_MM_EOT_LOW 0x00000000
/* DMAC M2M control register EOT polarity is active high input */
#define DMAC_MM_EOT_HI  0x00008000
/* DMAC M2M control register EOT polarity is active low output */
#define DMAC_MM_TC_LOW  0x00010000
/* DMAC M2M control register EOT polarity is active high output */
#define DMAC_MM_TC_HI   0x00018000
/* DMAC M2M control register DACK polarity is active low */
#define DMAC_MM_DK_LOW  0x00040000
/* DMAC M2M control register DACK polarity is active high */
#define DMAC_MM_DK_HIGH 0x00050000
/* DMAC M2M control register DREQ polarity is active low level */
#define DMAC_MM_DR_LL   0x00000000
/* DMAC M2M control register DREQ polarity is active high level */
#define DMAC_MM_DR_HL   0x00080000
/* DMAC M2M control register DREQ polarity is active low edge */
#define DMAC_MM_DR_LE   0x00100000
/* DMAC M2M control register DREQ polarity is active high edge */
#define DMAC_MM_DR_HE   0x00180000

/* Offset of the M2M registers from the start of the DMAC */
#define DMA_MM_REGS_OFFSET 0x00000100
#define DMA_MM_REGS_OFFSET1 0x00000140

/* Macro pointing to DMA registers */
#define DMAC ((DMA_REGS_T *)(DMA_REGS_BASE))
/* Macro for the two M2M DMA register banks */
#define DMACMM ((DMA_MM_BLOCK_T *)(DMA_REGS_BASE + DMA_MM_REGS_OFFSET))
#define DMACMM0 ((DMA_MM_BLOCK_T *)(DMA_REGS_BASE + DMA_MM_REGS_OFFSET))
#define DMACMM1 ((DMA_MM_BLOCK_T *)(DMA_REGS_BASE + DMA_MM_REGS_OFFSET1))

#endif /* LH7A404_DMAC_H */

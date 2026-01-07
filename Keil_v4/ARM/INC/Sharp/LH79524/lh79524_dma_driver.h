/***********************************************************************
 * $Id:: lh79524_dma_driver.h 27 2007-08-31 19:35:06Z kevinw           $
 *
 * Project: LH79524 DMA driver
 *
 * Description:
 *     This file contains driver support for the DMA module on the
 *     LH79524
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

#ifndef LH79524_DMA_DRIVER_H
#define LH79524_DMA_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh79524_dmac.h"

/***********************************************************************
 * DMA device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* DMA device commands (IOCTL commands) */
typedef enum {
    DMA_CLEAR_STATUS,   /* Clear DMA status register, arg = status */
    DMA_ENABLE_INT,     /* Enable one of DMA interrupt, arg = mask */
    DMA_DISABLE_INT,    /* Disable one of DMA interrupt, arg = mask */
    DMA_SET_M2M_SRC,    /* DMA set m2m source address, arg = addr */
    DMA_SET_M2M_DEST,   /* DMA set m2m destination address, arg = addr */
    DMA_SET_M2M_BYTES,  /* DMA set m2m number of bytes to be transfered, 
                        arg = number of bytes */
    DMA_SET_M2M_SRC_WIDTH,  /* DMA set m2m srouce width, arg = width */
    DMA_SET_M2M_DEST_WIDTH, /* DMA set m2m destination width, arg = wid*/
    DMA_SET_M2M_BURST_LEN,  /* DMA set m2m transfer burst length, arg =
                        number of items in single burst, 1, 4, 8, 16 */
    DMA_START_M2M,      /* Start m2m DMA transfer, no arg */
    DMA_STOP_M2M,       /* Stop m2m DMA transfer, no arg */
    DMA_SET_EXT_CHANNEL,/* DMA set external transfer channel, arg = 0 
                        for DREQ0, arg = 1 for DREQ1 */
    DMA_SET_EXT_DIRECTION,  /* DMA set external transfer direction, 
                        arg = 0 for peripheral to memory, arg = 1 for
                        memory to peripheral */
    DMA_SET_EXT_SRC,    /* DMA external transfer set source address, 
                        arg = address */
    DMA_SET_EXT_DEST,   /* DMA external transfer set destination address,
                        arg = address */
    DMA_SET_EXT_BYTES,  /* DMA external transfer set number of bytes to
                        transfer, arg = number of bytes */
    DMA_SET_EXT_SRC_WIDTH,  /* DMA external transfer width set, arg = 
                        width */
    DMA_SET_EXT_DEST_WIDTH, /* DMA external transfer destination width
                        set, arg = width */
    DMA_SET_EXT_BURST_LEN,  /* DMA external transfer burst width set,
                        arg = burst length, 1,4,8.16 */
	DMA_SET_SO_INC,		/* DMA external set current source register 
						increamented. arg = 1, increamented, arg = 0, 
						unchanged */
	DMA_SET_DE_INC,		/* DMA external set current destination register 
						increamented. arg = 1, increamented, arg = 0, 
						unchanged */
    DMA_ENABLE_EXT,     /* DMA start external transfer, arg = 1, enable
    					arg = 0 disable */
    DMA_GET_STATUS      /* DMA get DMA status register value, returns
                        DMAC_EOT0
                        DMAC_EOT1
                        DMAC_EOT2
                        DMAC_EOT3
                        DMAC_ERROR0
                        DMAC_ERROR1
                        DMAC_ERROR2
                        DMAC_ERROR3
                        DMAC_ACTIVE0 
                        DMAC_ACTIVE1 
                        DMAC_ACTIVE2 
                        DMAC_ACTIVE3 */
    
} DMA_IOCTL_CMD_T;

/***********************************************************************
 * DMA device configuration structure
 **********************************************************************/

/* DMA device configuration structure */
typedef struct
{
    INT_32 init;       /* Device initialized flag */
    DMAC_REGS_T *regptr; /* Pointer to DMA registers */
} DMA_CFG_T;

/***********************************************************************
 * DMA driver functions
 **********************************************************************/
/* Open the dma */
INT_32 dma_open(void *ipbase, INT_32 arg);

/* Close the dma */
STATUS dma_close(INT_32 devid);

/* dma configuration block */
STATUS dma_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* DMA read function (stub only) */
INT_32 dma_read(INT_32 devid,
                void *buffer,
                INT_32 max_bytes);

/* DMA write function (stub only) */
INT_32 dma_write(INT_32 devid,
                 void *buffer,
                 INT_32 n_bytes);

#ifdef __cplusplus
}
#endif

#endif /* LH79524_DMA_DRIVER_H */

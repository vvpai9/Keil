/***********************************************************************
 * $Id:: lh7a404_dma_driver.h 14 2007-08-28 16:08:18Z kevinw           $
 *
 * Project: LH7A404 DMA driver
 *
 * Description:
 *     This file contains driver support for the DMA module on the
 *     LH7A404
 *
 * Notes:
 *     DMA memory to memory operations are not yet implemented. These
 *     will be implemented in a later version of this driver.
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

#ifndef LH7A404_DMA_DRIVER_H
#define LH7A404_DMA_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_dmac.h"

/***********************************************************************
 * DMA driver types
 **********************************************************************/

/* DMA channel enumeration */
typedef enum
{
    DMAC_USB_RX = 0,   /* DMA USB RX channel */
    DMAC_USB_TX,       /* DMA USB TX channel */
    DMAC_SDMMC_RX,     /* DMA SDMMC RX channel */
    DMAC_SDMMC_TX,     /* DMA SDMMC TX channel */
    DMAC_AAC_RX1,      /* DMA AC97 RX channel 1 */
    DMAC_AAC_TX1,      /* DMA AC97 TX channel 1 */
    DMAC_AAC_RX2,      /* DMA AC97 TX channel 2 */
    DMAC_AAC_TX2,      /* DMA AC97 RX channel 2 */
    DMAC_AAC_RX3,      /* DMA AC97 RX channel 3 */
    DMAC_AAC_TX3,      /* DMA AC97 TX channel 3 */
    DMAC_UART_RX1,     /* DMA UART RX channel 1 */
    DMAC_UART_TX1,     /* DMA UART TX channel 1 */
    DMAC_UART_RX2,     /* DMA UART RX channel 2 */
    DMAC_UART_TX2,     /* DMA UART TX channel 2 */
    DMAC_UART_RX3,     /* DMA UART RX channel 3 */
    DMAC_UART_TX3,     /* DMA UART TX channel 3 */
    DMAC_CHANNEL_NONE  /* DMA channel delimiter */
} DMAC_CHANNEL_T;

/* This type is a function pointer to a callback function the DMA
   driver will call when it needs more data to keep the DMA stream
   going. This function type is only used with the dmac_start_using_cb()
   function when starting DMA transfers that use callbacks. For a user
   of this driver function, another function needs to be defined with
   the following prototype. For a receive and transmit channel, this
   function requires slightly different arguments:
   For transmit:
       Argument 1 is a pointer to a buffer to get data from the
           callback
       Argument 2 is a pointer to a UNS_32. The value contains the
           number of bytes that were transferred in the last DMA
           transfer when calling the callback function. The value will
           contain the number of bytes to transfer in the buffer when
           returning from the callback function. This value should never
           be more than 64KBytes and should be a multiple of 4.
       Argument 3 is a pointer to a boolean flag. The flag value will
           be sent as TRUE to the callback if the DMA transfer was
           aborted due to an error. The callback must return the flag
           as TRUE if it wants to abort the transfer.
   For receive:
       Argument 1 is a pointer to a buffer that is allocated by the
           callback function. The DMA data will be placed into this
           area.
       Argument 2 is a pointer to a UNS_32. The value contains the
           number of bytes that were transferred in the last DMA
           transfer when calling the callback function. The value will
           contain the number of bytes to transfer in the buffer when
           returning from the callback function. This value should never
           be more than 64KBytes and should be a multiple of 4.
       Argument 3 is a pointer to a boolean flag. The flag value will
           be sent as TRUE to the callback if the DMA transfer was
           aborted due to an error. The callback must return the flag
           as TRUE if it wants to abort the transfer. */
typedef void (*DMACFUNC_T) (void *,     /* Address to place data */
                            UNS_32 *,   /* Requested # of bytes */
                            BOOL_32 *); /* Abort flag */

/* DMA channel status types */
typedef enum
{
    DMA_ERROR = -2,               /* DMA has stopped on an error */
    DMA_ABORTED = -1,             /* DMA has been completed/aborted */
    DMA_IDLE = DMAC_STATE_IDLE,   /* DMA channel is idle (disabled) */
    DMA_STALL = DMAC_STATE_STALL, /* DMA channel is stalled */
    DMA_ON = DMAC_STATE_ON,       /* DMA is not stalled and needs
                                     another packet */
    DMA_NEXT = DMAC_STATE_NEXT    /* DMA is transferring packets */
} DMAC_STATUS_T;

/***********************************************************************
 * DMA driver functions
 **********************************************************************/

/* Start a DMA channel transfer using a callback function */
BOOL_32 dmac_start_using_cb(DMAC_CHANNEL_T channel,
                         DMACFUNC_T dcb_func,
                         BOOL_32 no_terminate);

/* Start a DMA channel transfer using a set buffer size */
BOOL_32 dmac_start(DMAC_CHANNEL_T channel,
                void *buffer,
                UNS_32 bytes,
                BOOL_32 no_terminate);

/* Force a stalled channel to restart */
void dmac_restart(DMAC_CHANNEL_T channel);

/* Stop and deallocate a DMA channel */
void dmac_stop(DMAC_CHANNEL_T channel);

/* Flush a DMA channel */
void dmac_flush(DMAC_CHANNEL_T channel);

/* Return a DMA channel status */
DMAC_STATUS_T dmac_get_status(DMAC_CHANNEL_T channel);

/* Return the number of bytes in the byte packer */
INT_32 dmac_get_packer_bytes(DMAC_CHANNEL_T channel);

/* DMA interrupt enable and disable */
UNS_32 dmac_channel_int_enable(DMAC_CHANNEL_T channel,
                               UNS_32 enable_mask);

/* DMA interrupt handler */
void dmac_isr(void);

#endif /* LH7A404_DMA_DRIVER_H */

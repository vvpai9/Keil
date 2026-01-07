/***********************************************************************
 * $Id:: lh7a404_sdmmc_driver.h 14 2007-08-28 16:08:18Z kevinw         $
 *
 * Project: LH7A404 SDMMC driver
 *
 * Description:
 *     This file contains basic driver support for the SDMMC module
 *     on the LH7A404
 *
 * Notes:
 *     This driver supports basic MMC and SD data transfer capability
 *     and is intended to be a reference on how the SDMMC interface of
 *     the LH7A404 works. This driver can be used to transfer data to
 *     and from an MMC card, but not every SDMMC function is implemented
 *     and a system with an SD/MMC interface may require more capability
 *     than what this driver provides. The following is provided by this
 *     driver:
 *         SDMMC multi-block read and write
 *         Interrupt and DMA control and transfer modes
 *         Device status and detection (via OCR polling)
 *         SDMMC state management
 *    Although support for multiple SD/MMC cards is provided, it may
 *    not work correctly 'as is' when accessing multiple cards at the
 *    same time. Making some operations atomic may help fix this.
 *
 *    This driver requires state management in the interrupt handler.
 *    Some IOCTL commands request data from the MMC card or interface
 *    that isn't immediately available. To keep the driver from using
 *    delay and monitor loops and delaying external applications, the
 *    driver will usually take a request without providing an immediate
 *    result. The user application needs to keep this in mind and check
 *    the status of the operation at a time after the initial request.
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

#ifndef LH7A404_SDMMC_DRIVER_H
#define LH7A404_SDMMC_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_sdmmc.h"

/***********************************************************************
 * SDMMC device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* SDMMC device commands (IOCTL commands) */
typedef enum {
    /* These commands effect all cards in the stack */
    MMC_SET_CLOCK,    /* Set or reset the SDMMC clock rate in Hz. Use
                         arg as value in Hz to set clock to, returns
                         the actual set clock speed */
    MMC_ENABLE_INTS,  /* Enable SDMMC interrupts, use arg as an OR'ed
                         value of MMC_INT_DATA_TRANSFER_DONE,
                         MMC_INT_PROGRAM_DONE, MMC_INT_END_CMD_RESPONSE,
                         MMC_INT_BUFFER_READY, MMC_INT_CLOCK_STOPPED,
                         or MMC_INT_SDIO_INT*/
    MMC_DISABLE_INTS, /* Disable SDMMC interrupts, use arg as an OR'ed
                         value of MMC_INT_DATA_TRANSFER_DONE,
                         MMC_INT_PROGRAM_DONE, MMC_INT_END_CMD_RESPONSE,
                         MMC_INT_BUFFER_READY, MMC_INT_CLOCK_STOPPED,
                         or MMC_INT_SDIO_INT*/
    MMC_CLEAR_INTS,   /* Clear SDMMC interrupts, use arg as an OR'ed
                         value of MMC_INT_DATA_TRANSFER_DONE,
                         MMC_INT_PROGRAM_DONE, MMC_INT_END_CMD_RESPONSE,
                         MMC_INT_BUFFER_READY, MMC_INT_CLOCK_STOPPED,
                         or MMC_INT_SDIO_INT*/
    MMC_INSTALL_CB,   /* Install interrupt callback function that is
                         called when MMC_READ_SECTORS or
                         MMC_WRITE_SECTORS is complete, use arg as
                         address of callback function to install - this
                         only works in interrupt and DMA modes */
    MMC_SD_CHECK,     /* Returns 1 if the card is a SD card, 0 if it is
                         an MMC card, only valid after detection, use
                         arg = 0*/
    MMC_GET_OCR,      /* Requests the saved OCR value for the card, only
                         valid after detection, use arg as an address to
                         where the OCR will be written */
    MMC_RESET,        /* Reset the all cards in the stack, use arg = 0,
                         after this command is issued, wait for about
                         350uS before starting a detection sequence to
                         allow the card to initialize */

    /* The following commands use the state machine to handle the
       request over time and do not return instant results. Once one
       of these commands has been issue, use the MMC_GET_STATUS command
       with the MMC_DRV_STATUS argument to determine when the command
       has completed and it's status */
    MMC_DETECT,       /* Detects an MMC card, use arg as the passed OCR
                         voltage range used for card filtering - use the
                         MMC_GET_STATUS to determine when the operation
                         has finished and if it was successful, a reset
                         sequence must always precede the detection
                         sequence */
    MMC_CARD_EJECT,   /* Ejects the selected card, card will need to be
                         removed and re-inserted to be re-detected as it
                         will be placed in inactive state, use
                         arg = 0 */
    MMC_GET_CID,      /* Requests the card identification (CID) register,
                         use arg as an address to where the CID will be
                         written */
    MMC_GET_CSD,      /* Requests the card specific data (CSD) register,
                         use arg as an address to where the CSD will be
                         written */
    MMC_READ_REQUEST, /* Requests a read of data of 1 or more sectors,
                         use arg as a pointer of type SDMMC_SECTORS_T */
    MMC_WRITE_REQUEST,/* Requests a write of data of 1 or more sectors,
                         use arg as a pointer of type SDMMC_SECTORS_T */
    MMC_DESELECT_CARD,/* Deselect the active SDMMC card, use arg = 0 */
    MMC_GET_STATUS    /* Return SDMMC status, use arg as a value of type
                         MMC_IOCTL_STS_T */
} MMC_IOCTL_CMD_T;

/* SDMMC device arguments for MMC_GET_STATUS command (IOCTL
   arguments) */
typedef enum {
    MMC_DRV_STATUS,   /* Returns the status of the current operation,
                         a value of type SDMMC_CMD_STATUS_T */
    MMC_INTS_ENABLED, /* Returns enabled interrupts, an OR'ed value
                         value of MMC_INT_DATA_TRANSFER_DONE,
                         MMC_INT_PROGRAM_DONE, MMC_INT_END_CMD_RESPONSE,
                         MMC_INT_BUFFER_READY, MMC_INT_CLOCK_STOPPED,
                         or MMC_INT_SDIO_INT*/
    MMC_INTS_PENDING, /* Returns pending interrupts, an OR'ed value
                         value of MMC_INT_DATA_TRANSFER_DONE,
                         MMC_INT_PROGRAM_DONE, MMC_INT_END_CMD_RESPONSE,
                         MMC_INT_BUFFER_READY, MMC_INT_CLOCK_STOPPED,
                         or MMC_INT_SDIO_INT*/
    MMC_GET_SECT_SIZE /* Returns the MMC sector size in bytes */

} MMC_IOCTL_STS_T;

/* Possible SDMMC error conditions for the request/response state
   machine - these statuses may not be applicable to all operation
   types, and can also be used to monitor states for polling if
   needed by using the MMC_WAITING_FOR_xxxxx status checks */
typedef enum
{
    MMC_OPERATION_OK,           /* Operation completed successfully */
    MMC_OPERATION_FAILED,       /* Operation failed */
    MMC_WAITING_FOR_RESPONSE,   /* Operation is still busy */
    MMC_DMA,                    /* Operation is waiting for DMA
                                   closure */
    MMC_NO_RESPONSE             /* No response from card */
} SDMMC_CMD_STATUS_T;

/* MMC sector read/write request structure, used to define first
   logical sector and number of blocks to read */
typedef struct
{
    UNS_32  logical_sector;    /* Logical sector starting at 0 */
    UNS_32  number_sectors;    /* Number of sectors to read/write */
    BOOL_32 use_dma;           /* Use DMA for the transfer */
    void    *buffer;           /* Buffer to move data to or from (used
                                  in DMA mode only) */
} SDMMC_SECTORS_T;

/***********************************************************************
 * SDMMC driver API functions
 **********************************************************************/

/* Open the SDMMC */
INT_32 sdmmc_open(void *ipbase,
                  INT_32 arg);

/* Close the SDMMC */
STATUS sdmmc_close(INT_32 devid);

/* SDMMC configuration block */
STATUS sdmmc_ioctl(INT_32 devid,
                   INT_32 cmd,
                   INT_32 arg);

/* Read a block of data */
INT_32 sdmmc_read(INT_32 devid,
                  void *buffer,
                  INT_32 max_bytes);

/* Write a block of data */
INT_32 sdmmc_write(INT_32 devid,
                   void *buffer,
                   INT_32 n_bytes);

/* SDMMC interrupt handler (routes to the user define interrupt
   handler function) */
void sdmmc_isr(void);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_SDMMC_DRIVER_H */

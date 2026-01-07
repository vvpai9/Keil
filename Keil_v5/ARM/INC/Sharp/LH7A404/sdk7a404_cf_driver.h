/***********************************************************************
 * $Id:: sdk7a404_cf_driver.h 14 2007-08-28 16:08:18Z kevinw           $
 *
 * Project: SDK7A404 CompactFlash driver
 *
 * Description:
 *     This file contains driver support for the IDE mode CompactFlash
 *     interface on the SDK7A404 EVB.
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

#ifndef SDK7A404_CF_DRIVER_H
#define SDK7A404_CF_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lpc_types.h"
#include "sdk7a404_board.h"

/***********************************************************************
 * SDK7A400 CompactFlash configuration commands (IOCTL commands and
 * arguments)
 **********************************************************************/

/* CompactFlash device commands (IOCTL commands) */
typedef enum {
    CF_READ_BLOCKS,  /* Issue command to read a series of sectors, use
                        arg = pointer to structure of CF_BLOCKS_T */
    CF_WRITE_BLOCKS, /* Issue command to write a series of sectors, use
                        arg = pointer to structure of CF_BLOCKS_T */
    CF_ERASE_SECTOR, /* Erase a single sector, use arg = sector number
                        to erase */
    CF_GET_STATUS    /* Return a CF interface status, use arg as a
                        value of type CF_IOCTL_STS_T */
} CF_IOCTL_CMD_T;

/* CompactFlash device arguments for CF_GET_STATUS command (IOCTL
   arguments) */
typedef enum {
    CF_CARD_DETECT,  /* Returns 1 if a CF card is inserted in the EVB,
                        otherwise 0 */
    CF_CARD_READY,   /* Returns 1 if the card is ready for a new
                        command, otherwise 0 */
    CF_CARD_BUSY     /* Returns 1 if the card is busy, otherwise 0 */
} CF_IOCTL_STS_T;

/* Pointer to a sector block(s) read/write structure */
typedef struct
{
    INT_32 sector;   /* First sector to read */
    INT_32 num_blocks;  /* Number of sectors to read */
} CF_BLOCKS_T;

/***********************************************************************
 * SDK7A400 CompactFlash API functions
 **********************************************************************/

/* Open the CompactFlash device */
INT_32 cf_open(void *ipbase,
               INT_32 arg);

/* Close the CompactFlash device */
STATUS cf_close(INT_32 devid);

/* CompactFlash device configuration block */
STATUS cf_ioctl(INT_32 devid,
                INT_32 cmd,
                INT_32 arg);

/* CompactFlash device read function */
INT_32 cf_read(INT_32 devid,
               void *buffer,
               INT_32 max_bytes);

/* CompactFlash device write function */
INT_32 cf_write(INT_32 devid,
                void *buffer,
                INT_32 n_bytes);

#ifdef __cplusplus
}
#endif

#endif /* SDK7A404_CF_DRIVER_H */

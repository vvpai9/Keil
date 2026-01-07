/***********************************************************************
 * $Id:: sdk7a404_strataflash.h 14 2007-08-28 16:08:18Z kevinw         $
 *
 * Project: StrataFlash structure, definitions, and functions
 *
 * Description:
 *     This file contains structures, defines, and function prototypes
 *     used to program StrataFlash devices on the SDK7A404 boards.
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

#ifndef SDK7A404_STRATAFLASH_H
#define SDK7A404_STRATAFLASH_H

#include "lpc_types.h"

/* Detect the number of CFI devices and the configuration */
BOOL_32 cfi_detect(volatile UNS_32 *addr);

/* Return the (combined) device size in bytes */
UNS_32 cfi_getdevsize(void);

/* Clear a block lock */
void cfi_clear_block_lock(UNS_32 block);

/* Set a block lock */
void cfi_set_block_lock(UNS_32 block);

/* Returns the total number of blocks in FLASH */
UNS_32 cfi_get_block_count(void);

/* Returns the starting address of the block */
UNS_32 cfi_get_block_address(UNS_32 block);

/* Returns the size of the block */
UNS_32 cfi_get_block_size(UNS_32 block);

/* Returns the size of the write buffer */
UNS_32 cfi_get_wb_size(void);

/* Returns the block number for the passed address */
UNS_32 cfi_get_block_from_address(UNS_32 *addr);

/* Erases a block of FLASH */
void cfi_erase_block(UNS_32 block);

/* Erases the entire FLASH device */
void cfi_erase_device(void);

/* Write a single value (32-bits) to the FLASH devices */
void cfi_writeword(volatile UNS_32 *addr,
                   UNS_32 val);

/* Return FLASH devices to normal mode */
void cfi_exitprog_mode(volatile UNS_32 *addr);

/* Write data to FLASH (using buffer) */
INT_32 cfi_write_to_buffer(UNS_32 *src,
                           volatile UNS_32 *dest,
                           INT_32 words);

#endif /* SDK7A404_STRATAFLASH_H */

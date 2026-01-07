/*
 *****************************************************************************
 * Copyright @ 2007 by austriamicrosystems AG                                *
 * All rights are reserved.                                                  *
 *                                                                           *
 * Reproduction in whole or in part is prohibited without the written consent*
 * of the copyright owner. Austriamicrosystems reserves the right to make    *
 * changes without notice at any time. The software is provided as is and    *
 * Austriamicrosystems makes no warranty, expressed, implied or statutory,   *
 * including but not limited to any implied warranty of merchantability or   *
 * fitness for any particular purpose, or that the use will not infringe any *
 * third party patent, copyright or trademark. Austriamicrosystems should    *
 * not be liable for any loss or damage arising from its use.                *
 *****************************************************************************
 */

/*
 *      PROJECT:   AS353x
 *      $Revision: 759 $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author M. Arpa
 *  \author H. Treml (Substitute)
 *
 *  \brief AS3525 platform specific register base addresses.
 *  
 *  AS3525 platform specific register base addresses.
 *  Currently the following target platforms exist
 *
 */

#ifndef _AS3525_BASE_ADDRESSES_H_
#define _AS3525_BASE_ADDRESSES_H_

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/

/*
******************************************************************************
* DEFINES
******************************************************************************
*/

/* RAM */
#define AS3525_RAM_BASE            0x00000000

/* AHB */
#define AS3525_USB_BASE            0xC6000000
#define AS3525_VIC_BASE            0xC6010000
#define AS3525_DMAC_BASE           0xC6020000
#define AS3525_EXTMEM_ITF_BASE     0xC6030000
#define AS3525_MEMSTICK_BASE       0xC6040000
#define AS3525_CF_IDE_BASE         0xC6050000

/* APB */
#define AS3525_NAND_FLASH_BASE     0xC8000000
#define AS3525_BIST_MANAGER_BASE   0xC8010000
#define AS3525_SD_MCI_BASE         0xC8020000
#define AS3525_TIMER_BASE          0xC8040000
#define AS3525_WDT_BASE            0xC8050000
#define AS3525_I2C_MS_BASE         0xC8060000
#define AS3525_I2C_AUDIO_BASE      0xC8070000
#define AS3525_SSP_BASE            0xC8080000
#define AS3525_I2SIN_BASE          0xC8090000
#define AS3525_I2SOUT_BASE         0xC80A0000
#define AS3525_GPIO1_BASE          0xC80B0000
#define AS3525_GPIO2_BASE          0xC80C0000
#define AS3525_GPIO3_BASE          0xC80D0000
#define AS3525_GPIO4_BASE          0xC80E0000
#define AS3525_CGU_BASE            0xC80F0000
#define AS3525_CCU_BASE            0xC8100000
#define AS3525_UART_BASE           0xC8110000
#define AS3525_DBOP_BASE           0xC8120000

#endif /* _AS3525_BASE_ADDRESSES_H_ */



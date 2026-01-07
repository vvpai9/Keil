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
 * third party patent, copyright or trademark. Austriamicrosystems should not*
 * be liable for any loss or damage arising from its use.                    *
 *****************************************************************************
 */

/*
 *      PROJECT:   AS35xx
 *      $Revision: $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author C. Schicklgruber
 *  \author  (Substitute)
 *
 *  \brief Interface between software and hardware specific base addresses.
 *  
 *  Interface between software and hardware specific base addresses.
 *
 */

#ifndef _SDK_BASE_ADDRESSES_H_
#define _SDK_BASE_ADDRESSES_H_


/*
******************************************************************************
* INCLUDES
******************************************************************************
*/
#include "as3525_base_addresses.h"

/*
******************************************************************************
* DEFINES
******************************************************************************
*/

/* RAM */
#define REGISTER_BASE_RAM            AS3525_RAM_BASE

/* AHB */
#define REGISTER_BASE_USB            AS3525_USB_BASE
#define REGISTER_BASE_VIC            AS3525_VIC_BASE
#define REGISTER_BASE_DMAC           AS3525_DMAC_BASE
#define REGISTER_BASE_EXTMEM_ITF     AS3525_EXTMEM_ITF_BASE
#define REGISTER_BASE_MEMSTICK       AS3525_MEMSTICK_BASE
#define REGISTER_BASE_CF_IDE         AS3525_CF_IDE_BASE

/* APB */
#define REGISTER_BASE_NAND_FLASH     AS3525_NAND_FLASH_BASE
#define REGISTER_BASE_BIST_MANAGER   AS3525_BIST_MANAGER_BASE
#define REGISTER_BASE_SD_MCI         AS3525_SD_MCI_BASE
#define REGISTER_BASE_TIMER          AS3525_TIMER_BASE
#define REGISTER_BASE_WDT            AS3525_WDT_BASE
#define REGISTER_BASE_I2C_MS         AS3525_I2C_MS_BASE
#define REGISTER_BASE_I2C_AUDIO      AS3525_I2C_AUDIO_BASE
#define REGISTER_BASE_SSP            AS3525_SSP_BASE
#define REGISTER_BASE_I2SINE         AS3525_I2SIN_BASE
#define REGISTER_BASE_I2SOUT         AS3525_I2SOUT_BASE
#define REGISTER_BASE_GPIO1          AS3525_GPIO1_BASE
#define REGISTER_BASE_GPIO2          AS3525_GPIO2_BASE
#define REGISTER_BASE_GPIO3          AS3525_GPIO3_BASE
#define REGISTER_BASE_GPIO4          AS3525_GPIO4_BASE
#define REGISTER_BASE_CGU            AS3525_CGU_BASE
#define REGISTER_BASE_CCU            AS3525_CCU_BASE
#define REGISTER_BASE_UART           AS3525_UART_BASE
#define REGISTER_BASE_DBOP           AS3525_DBOP_BASE

/*
******************************************************************************
* GLOBAL MACROS
******************************************************************************
*/

/*
******************************************************************************
* GLOBAL DATA TYPES
******************************************************************************
*/

/*
******************************************************************************
* GLOBAL VARIABLE DECLARATIONS
******************************************************************************
*/


/*
******************************************************************************
* GLOBAL FUNCTION PROTOTYPES
******************************************************************************
*/


#endif /* _SDK_BASE_ADDRESSES_H_ */



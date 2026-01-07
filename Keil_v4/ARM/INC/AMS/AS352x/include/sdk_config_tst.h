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
 *      PROJECT:   AS352x
 *      $Revision: 759 $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author M. Arpa
 *  \author H. Treml (Substitute)
 *
 *  \brief Configuration file for the application.
 *  
 *  Configuration file for the AS35xx application.
 *                 Specify here the:
 *                 - External Oscillator/Crystal Frequency
 *                 - Memory Size for the FCA
 *
 */

#ifndef _SDK_CONFIG_H_
#define _SDK_CONFIG_H_

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

/*----------------------------------------------------------------------------
* Application identification                                               
*-----------------------------------------------------------------------------
*/
#define SDK_APPL_DEBUG               1

/*----------------------------------------------------------------------------
* Block Device Configuration                                               
*-----------------------------------------------------------------------------
*/
/**
 * Select the block device you want to have during your appliation.
 * IDE and NAND cannot be enabled at the same time, as those share
 * pins. This is not supported in SW.
 * MMC and MST cannot be enabled at the same time, as those share
 * pins. This is not supported in SW.
 * The block device is automatically initialised and deinitialised.
 *
 * check the define for NAF reloader application
 **/
#define SDK_USE_NAF_DRIVER            1

#define SDK_NAND_FLASH_TYPE                 SDK_NAND_256MB_BB
//#define SDK_NAND_FLASH_TYPE                 SDK_NAND_1024MB_BB

/*----------------------------------------------------------------------------
* USB Configuration                                                        
*-----------------------------------------------------------------------------
*/

#define SDK_USE_USB                   1


/*----------------------------------------------------------------------------
*  External Memory Configuration                                            
*-----------------------------------------------------------------------------
*/

/**
* Define whether external memory shall be initialised or not.
**/
#define SDK_USE_EXT_MEMORY    1
#define SDK_USE_EXT_CODE      1


/*----------------------------------------------------------------------------
 * File Cache Configuration                                                   
 *----------------------------------------------------------------------------
 */
/**
 * There are two different base configuration for the FCA:
 * - small buffer: several Kilo-Bytes (e.g. 6KB)
 * - big buffer:   several Mega-Bytes (e.g. 32MB)
 *
 * A small buffer can be hold in internal RAM (SRAM), while when using a big
 * buffer external RAM should be available.
 *
 * In addition to the base selection, also the sizes of the cache used
 * can be varied.
 **/
#define SDK_FCA_BIG_BUFFER            1   /* !<1 == big , 0 == small */


/*----------------------------------------------------------------------------
 * Reloader Configuration                                                   
 *----------------------------------------------------------------------------
 */
/**
 * define from which medium the reloading is done.
 * if the reloader is turned off, no reloading is done. This should
 * be used only for debugging, where you do not want to burn your
 * appliction to NAND before running it.
 *
 * possible options:
 * SDK_NO_RELOADER
 * SDK_IDE_RELOADER
 * SDK_NAF_RELOADER
 * SDK_SD_RELAODER
 **/
#define SDK_USE_RELOADER                 SDK_NO_RELOADER

/*----------------------------------------------------------------------------
 * Various Features Configuration                                           
 *----------------------------------------------------------------------------
 */
#define SDK_USE_EQUALISER    SDK_DSP_EQ_OFF

/*----------------------------------------------------------------------------
 * Debug Configuration                                                      
 *----------------------------------------------------------------------------
 */
/* For debug version we enable debug switches */

#define SDK_USE_UART_DRIVER              1

#define SDK_DEBUG_SERIAL                        1

#define SDK_USE_ASSERT                   1

#define SDK_USE_TESTMATE                 0

#define SDK_USE_HEAP_TRACE               1

#define SDK_USE_AMS_FS_VERBOSE           1

#include "sdk_defaults.h"

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

#endif /* _SDK_CONFIG_H_ */



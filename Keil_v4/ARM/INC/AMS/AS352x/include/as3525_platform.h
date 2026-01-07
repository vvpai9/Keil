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
 *  \author Pradeep Ganesh
 *  \author M. Arpa (Substitute)
 *
 *  \brief Definition of AS353x interrupt constants
 *  
 *  Definition of AS353x interrupt constants,
 *  and base register addresses
 *
 */

#ifndef _AS3525_PLATFORM_H_
#define _AS3525_PLATFORM_H_

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/
#include "aptypes.h"
#include "cmacros.h"
#include "as3525_base_addresses.h"

/*
******************************************************************************
* DEFINES
******************************************************************************
*/
#if !defined(apOS_NO_STATIC_STATE)
/*
 * Description:
 * Define the constant apOS_NO_STATIC_STATE as non-zero if the peripheral data storage will be
 * created externally.  Undefine this if the storage is static within each module.
 */
#define apOS_NO_STATIC_STATE FALSE
#endif

#if !defined(apOS_CONFIG_USE_NO_CLIB)
/*
 * Description:
 * Define the constant apOS_CONFIG_USE_NO_CLIB as non-zero if the code should not use any
 * C library functions.
 */
#define apOS_CONFIG_USE_NO_CLIB TRUE
//#define apOS_CONFIG_USE_NO_CLIB TRUE
#endif

#if !defined(apOS_PLATFORM_INTEGRATOR)
/*
 * Description:
 * Define the constant apOS_PLATFORM_INTEGRATOR as non-zero if running on Integrator.
 * This will allow the test code to check for a logic module and chain the interrupt handler
 */
#define apOS_PLATFORM_INTEGRATOR FALSE
#endif

#if !defined(apOS_PLATFORM_HAS_TIMERS)
/*
 * Description:
 * Define the constant apOS_PLATFORM_HAS_TIMERS as false if the platform does not include
 * any timers.  This will ensure that no cross-module calls using timers are built.
 */
#define apOS_PLATFORM_HAS_TIMERS FALSE
#endif

/*
 * Description:
 * Enumeration of the base addresses for the various
 * peripheral modules.
 */

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
typedef enum apOS_System_xBaseAddress
{
      AS3525_RAM_BASE_ADDRESS           = (WORD32) AS3525_RAM_BASE,
      AS3525_SYSTEM_BASE_USB            = (WORD32) AS3525_USB_BASE,
      AS3525_SYSTEM_BASE_VIC            = (WORD32) AS3525_VIC_BASE,
      AS3525_SYSTEM_BASE_DMAC           = (WORD32) AS3525_DMAC_BASE,
      AS3525_SYSTEM_BASE_EXTMEM_ITF     = (WORD32) AS3525_EXTMEM_ITF_BASE,
      AS3525_SYSTEM_BASE_MEMSTICK       = (WORD32) AS3525_MEMSTICK_BASE,
      AS3525_SYSTEM_BASE_CF_IDE         = (WORD32) AS3525_CF_IDE_BASE,
      AS3525_SYSTEM_BASE_NAND_FLASH     = (WORD32) AS3525_NAND_FLASH_BASE,
      AS3525_SYSTEM_BASE_BIST_MANAGER   = (WORD32) AS3525_BIST_MANAGER_BASE,
      AS3525_SYSTEM_BASE_SD_MCI         = (WORD32) AS3525_SD_MCI_BASE,
      AS3525_SYSTEM_BASE_TIMER          = (WORD32) AS3525_TIMER_BASE,
      AS3525_SYSTEM_BASE_WDT            = (WORD32) AS3525_WDT_BASE,
      AS3525_SYSTEM_BASE_I2C_MS         = (WORD32) AS3525_I2C_MS_BASE,
      AS3525_SYSTEM_BASE_I2C_AUDIO      = (WORD32) AS3525_I2C_AUDIO_BASE,
      AS3525_SYSTEM_BASE_SSP            = (WORD32) AS3525_SSP_BASE,
      AS3525_SYSTEM_BASE_I2SIN          = (WORD32) AS3525_I2SIN_BASE,
      AS3525_SYSTEM_BASE_I2SOUT         = (WORD32) AS3525_I2SOUT_BASE,
      AS3525_SYSTEM_BASE_GPIO1          = (WORD32) AS3525_GPIO1_BASE,
      AS3525_SYSTEM_BASE_GPIO2          = (WORD32) AS3525_GPIO2_BASE,
      AS3525_SYSTEM_BASE_GPIO3          = (WORD32) AS3525_GPIO3_BASE,
      AS3525_SYSTEM_BASE_GPIO4          = (WORD32) AS3525_GPIO4_BASE,
      AS3525_SYSTEM_BASE_CGU            = (WORD32) AS3525_CGU_BASE,
      AS3525_SYSTEM_BASE_CCU            = (WORD32) AS3525_CCU_BASE,
      AS3525_SYSTEM_BASE_UART           = (WORD32) AS3525_UART_BASE

}
apOS_System_eBaseAddress;

#ifndef USE_NO_PLATFORM


#if !apOS_NO_STATIC_STATE

typedef enum apOS_UART_xId
{
    apOS_UART_0 = 0,        // Specifies UART 0
    apOS_UART_1 = 1,        // Specifies UART 1
    apOS_UART_MAXIMUM        // Number of UARTs in the system
}
apOS_UART_oId;              //Enumeration of UARTs available for the system

typedef enum apOS_GPIO_xId
{
    apOS_GPIO_0 = 0,        // General GPIO available to OEM
    apOS_GPIO_1 = 1,        // General GPIO available to OEM
    apOS_GPIO_MAXIMUM        // Number of GPIOs in the system
}
apOS_GPIO_oId;              //Enumeration of GPIOs available for the system

typedef enum apOS_RTC_xId
{
    apOS_RTC_0   = 0,       // Specifies Timer 0
    apOS_RTC_MAXIMUM        // Number of timers in the system
}
apOS_RTC_oId;               //Enumeration of real time clocks available for the system

typedef enum apOS_KMI_xId
{
    apOS_KMI_0   = 0,       // Specifies Keyboard/Mouse Interface 0
    apOS_KMI_1   = 1,       // Specifies Keyboard/Mouse Interface 0
    apOS_KMI_MAXIMUM        // Number of Interfaces in the system
}
apOS_KMI_oId;               //Enumeration of Keyboard/Mouse Interfaces available for the system

typedef enum apOS_DMA_xId
{
    apOS_DMA_0 = 0,
    apOS_DMA_MAXIMUM
}
apOS_DMA_oId;

typedef enum apOS_SSP_xId
{
    apOS_SSP_0 = 0,
    apOS_SSP_MAXIMUM
}
apOS_SSP_oId;

typedef enum apOS_TIMER_xId
{
    apOS_TIMER_0 = 0,
    apOS_TIMER_MAXIMUM
}
apOS_TIMER_oId;

typedef enum apOS_MCI_xId
{
    apOS_MCI_0 = 0,
    apOS_MCI_MAXIMUM
}
apOS_MCI_oId;


typedef enum apOS_PL172_xId
{
    apOS_PL172_0 = 0,
    apOS_PL172_MAXIMUM
}
apOS_PL172_oId;

#else

typedef void * apOS_UART_oId;
typedef void * apOS_GPIO_oId;
typedef void * apOS_RTC_oId;
typedef void * apOS_KMI_oId;
typedef void * apOS_DMA_oId;
typedef void * apOS_SSP_oId;
typedef void * apOS_TIMER_oId;
typedef void * apOS_MCI_oId;
typedef void * apOS_PL172_oId;
#endif

/*
 * ------------------------------------------------------------------
 * Versions of peripherals available to the system
 */
#define apUART_VERSION 11   //This is an example definition specifying the UART to be a PL011

#endif

#endif // _AS3525_PLATFORM_H_





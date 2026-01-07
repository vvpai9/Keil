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
 *  \brief Configuration file for the application.
 *  
 *  Configuration file for the application.
 *  Specify here the:
 *  - External Oscillator/Crystal Frequency 
 *  - Memory Size for the FCA
 *
 */


#ifndef _SDK_CALC_CONFIG_H_
#define _SDK_CALC_CONFIG_H_

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
/*----------------------------------------------------------------------*/
/* Operating System                                                     */
/*----------------------------------------------------------------------*/

/**
 * This is a define to have a symbolic name for one millisecond. 
 * Do not modify this calculation as it depends on the settings of the 
 * timer 1 (in directory timer_driver).
 **/
#ifdef ARMULATOR
    #define SDK_TIMER_TICKS_PER_MILLI_SEC \
            ( 16 * 60 )
#else
        /**
         * Timer has a divider of 16 in front of its clock on AS3525.
         **/
        #define SDK_TIMER_TICKS_PER_MILLI_SEC \
                ( ( (SDK_MAIN_CLOCK_FREQUENCY) / 16 ) / 1000 )
#endif /* ARMULATOR */

/*----------------------------------------------------------------------*/
/* Block Device Configuration                                           */
/*----------------------------------------------------------------------*/

#if ( (SDK_USE_IDE_DRIVER == 1 ) && (SDK_USE_NAF_DRIVER == 1 ) )
    #error "IDE and NAF cannot be enabled at the same time due to shared pins!"
#endif

#if ( (SDK_USE_MMC_DRIVER == 1 ) && (SDK_USE_MST_DRIVER == 1 ) )
    #error "MMC and MST cannot be enabled at the same time due to shared pins!"
#endif


/*----------------------------------------------------------------------*/
/* USB Configuration                                                    */
/*----------------------------------------------------------------------*/

/**
 * If a device shall not be used, than its LUN should be set to this
 * value.
 **/
#define SDK_USB_MSC_LUN_UNDEF (0xFF)

/**
 * Each block device that shall be accessible through USB MSC must be
 * assigned a unique LUN. All block devices that are not accessible 
 * through USB MSC must be assigned the undef value.
 **/
#if (SDK_USE_IDE_DRIVER == 1 )
    #define SDK_USB_MSC_IDE_LUN (SDK_USE_IDE_DRIVER-1)
#else
    #define SDK_USB_MSC_IDE_LUN (SDK_USB_MSC_LUN_UNDEF)
#endif

#if (SDK_USE_NAF_DRIVER == 1 )
    #define SDK_USB_MSC_NAF_LUN (SDK_USE_IDE_DRIVER+SDK_USE_NAF_DRIVER-1)
#else
    #define SDK_USB_MSC_NAF_LUN (SDK_USB_MSC_LUN_UNDEF)
#endif

#if (SDK_USE_MMC_DRIVER == 1 )
    #define SDK_USB_MSC_MMC_LUN (SDK_USE_IDE_DRIVER+SDK_USE_NAF_DRIVER+SDK_USE_MMC_DRIVER-1)
#else
    #define SDK_USB_MSC_MMC_LUN (SDK_USB_MSC_LUN_UNDEF)
#endif

#if (SDK_USE_MST_DRIVER == 1 )
    #define SDK_USB_MSC_MST_LUN (SDK_USE_IDE_DRIVER+SDK_USE_NAF_DRIVER+SDK_USE_MMC_DRIVER+SDK_USE_MST_DRIVER-1)
#else
    #define SDK_USB_MSC_MST_LUN (SDK_USB_MSC_LUN_UNDEF)
#endif

#if (SDK_USE_RAM_DRIVER == 1 )
    #define SDK_USB_MSC_RAM_LUN (SDK_USE_IDE_DRIVER+SDK_USE_NAF_DRIVER+SDK_USE_MMC_DRIVER+SDK_USE_MST_DRIVER+SDK_USE_RAM_DRIVER-1)
#else
    #define SDK_USB_MSC_RAM_LUN (SDK_USB_MSC_LUN_UNDEF)
#endif


/**
 * Number of luns that are currenlty supported.
 **/
#define SDK_USB_MSC_MAX_LUN (SDK_USE_IDE_DRIVER+SDK_USE_NAF_DRIVER+SDK_USE_MMC_DRIVER+SDK_USE_MST_DRIVER+SDK_USE_RAM_DRIVER)



/*----------------------------------------------------------------------*/
/* Reloader Configuration                                               */
/*----------------------------------------------------------------------*/

/**
 * verify the correct setting of SDK_USE_RELOADER
 **/
#if (   (   (SDK_USE_RELOADER != SDK_NO_RELOADER)   \
         && (SDK_USE_RELOADER != SDK_NAF_RELOADER)  \
         && (SDK_USE_RELOADER != SDK_IDE_RELOADER)  \
         && (SDK_USE_RELOADER != SDK_SD_RELOADER )) \
     || (   (SDK_USE_RELOADER == SDK_NAF_RELOADER)  \
         && (SDK_USE_NAF_DRIVER == 0))                 \
     || (   (SDK_USE_RELOADER == SDK_IDE_RELOADER)  \
         && (SDK_USE_IDE_DRIVER == 0))                 \
     || (   (SDK_USE_RELOADER == SDK_SD_RELOADER)   \
         && (SDK_USE_MMC_DRIVER == 0)) )
  #error Setting for SDK_USE_RELOADER not allowed
#endif



/*----------------------------------------------------------------------*/
/* Sanity checks, that configuration makes sense and is possible.       */
/*----------------------------------------------------------------------*/

/* if we have no external memory we must have a small fca. */
#if ( SDK_USE_EXT_MEMORY != 1 && SDK_FCA_BIG_BUFFER == 1 )
    #error "Err: Cannot have a big fca when no external memory is available."
#endif

/* if we have external memory, the fca cannot have a cache bigger than the
   external memory. */
#if ( SDK_USE_EXT_MEMORY != 1 && SDK_FCA_MEMORY_SIZE > SDK_EXT_MEMORY_SIZE )
    #error "Err: fca memory must not be greater than external memory is."
#endif

/**
 * If the ram reloader is used external memory is required 
 **/
#if ( SDK_DEBUG_SWITCH_RAM_RELOADER == 1 ) && ( SDK_USE_EXT_MEMORY == 0 )
    #error "Err: SDK_DEBUG_SWITCH_RAM_RELOADER needs external memory"
#endif

/* we must have at least one block device */
#if (  SDK_USE_IDE_DRIVER == 0 && SDK_USE_NAF_DRIVER == 0 && SDK_USE_MMC_DRIVER == 0 && SDK_USE_MST_DRIVER == 0 && SDK_USE_RAM_DRIVER == 0)
    #error "Err: must have at least one block device."
#endif 

/* cannot have ide without external memory */
#if (  SDK_USE_IDE_DRIVER == 1 && SDK_USE_EXT_MEMORY == 0 )
    #error "Err: cannot have IDE without external memory."
#endif 

/* cannot have naf and ide at the same time - they share pins */
#if (  SDK_USE_IDE_DRIVER == 1 && SDK_USE_NAF_DRIVER == 1 )
    #error "Err: cannot have IDE and NAF device. They share pins."
#endif 

/* cannot have mst and mmc at the same time - they share pins */
#if (  SDK_USE_MMC_DRIVER == 1 && SDK_USE_MST_DRIVER == 1 )
    #error "Err: cannot have MMC and MST device. They share pins."
#endif 


/* Currently we have only a nand flash reloader */
#if (( SDK_USE_IDE_DRIVER == 1 ) && (  SDK_USE_RELOADER == SDK_NAF_RELOADER ))
    #error Ide drive and reloader cannot be used at the same time! (naf and ide share pins!)
#endif 

/* Check debug switch setting, only one of SDK_DEBUG_SERIAL, SDK_DEBUG_CONSOLE 
   and SDK_DEBUG_BUFFER may be set */

#ifdef DEBUG_SET
#error temporary variable DEBUG_SET must not be set beforehand
#endif

#if (SDK_DEBUG_SERIAL != 0)
    #define DEBUG_SET
#endif

#if (SDK_DEBUG_CONSOLE != 0)
    #ifdef DEBUG_SET 
        #error Only one of DEBUG_* can be set.
    #else
        #define DEBUG_SET
    #endif
#endif

#if (SDK_DEBUG_BUFFER != 0)
    #ifdef DEBUG_SET
        #error Only one of DEBUG_* can be set.
    #else
        #define DEBUG_SET
    #endif
#endif

/* Undefine temporary preprocessor variable */
#undef DEBUG_SET

/* Application type configuration:only one application type must be set
   We assume that defines are set to 1 when activated */
#define APPLICATION_TYPES_SET     \
    ( SDK_APPL_IDE_DRM10       \
    + SDK_APPL_IDE_PDDRM       \
    + SDK_APPL_NAF_DRM10       \
    + SDK_APPL_NAF_MLC_DRM10   \
    + SDK_APPL_NAF_PDDRM       \
    + SDK_APPL_SWAP            \
    + SDK_APPL_SD_PDDRM        \
    + SDK_APPL_SD_DRM10        \
    + SDK_APPL_DEBUG )

#if (APPLICATION_TYPES_SET > 1)
    #error More than one application type set in sdk_config.h \
           Please check your configuration
#endif

/*----------------------------------------------------------------------*/
/* Driver Configuration                                                    */
/*----------------------------------------------------------------------*/

#if SDK_DEBUG_SERIAL
#if  !(SDK_USE_UART_DRIVER)
    #error SDK_DEBUG_SERIAL requires SDK_USE_UART_DRIVER==1 
#endif
#endif


#if SDK_USE_DRM10
#if !(SDK_USE_RTC_DRIVER)
#error DRM10 needs RTC driver 
#endif 
#endif

/*----------------------------------------------------------------------*/
/* Other Configuration                                                    */
/*----------------------------------------------------------------------*/

#if ( (SDK_USE_BLUETOOTH ==1) && (SDK_DISPLAY_TYPE != SHARP_176220) )
    #error not applicable
#endif

#endif /* _SDK_CALC_CONFIG_H_ */



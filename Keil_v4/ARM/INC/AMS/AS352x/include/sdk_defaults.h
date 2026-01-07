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
 *      $Revision: $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author F. Lobmaier
 *  \author U. Herrmann (Substitute)
 *
 *  \brief default values for applications
 *  
 *  default values for applications
 *
 */

#ifndef _SDK_DEFAULTS_H_
#define _SDK_DEFAULTS_H_

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
/* Clock Configuration                                                  */
/*----------------------------------------------------------------------*/

/**
 * The main clock frequency is the frequency that is received in the
 * AS353x5 through the clk_main line. I.e. the frequency is either from
 * an external clock or from the external crystal.
 **/
#ifndef SDK_MAIN_CLOCK_FREQUENCY
    #define SDK_MAIN_CLOCK_FREQUENCY   (24000000)
#endif


/*----------------------------------------------------------------------*/
/* Operating System                                                     */
/*----------------------------------------------------------------------*/

/**
 * Frequency with which the OS-Timer ISR is called. This is also the
 * frequency with which at least context switching can occur.
 * To get an system tick every 2-milliseconds you would have to
 * write here:
 *  #define SDK_SYSTEM_TICK     (2*(SDK_TIMER_TICKS_PER_MILLI_SEC))
 **/
#ifndef SDK_SYSTEM_TICK
    #define SDK_SYSTEM_TICK     (SDK_TIMER_TICKS_PER_MILLI_SEC)
#endif

/*----------------------------------------------------------------------*/
/* Application Type Configuration                                           */
/*----------------------------------------------------------------------*/

/**
 * the following application types are supported:
 *
 * SDK_APPL_IDE_DRM10      ... IDE based application with external RAM,
 *                               USB mode is MTP, Microsoft(R) DRM10
 *
 * SDK_APPL_IDE_PDDRM     ... IDE based application with external RAM,
 *                               USB mode is MSC, Microsoft(R) PDDRMv1
 *
 * SDK_APPL_NAF_DRM10      ... NAF based application with external RAM,
 *                               USB mode is MTP, Microsoft(R) DRM10
 *
 * SDK_APPL_NAF_PDDRM     ... NAF based application w/o external RAM,
 *                               USB mode is MSC, Microsoft(R) PDDRMv1
 *
 * SDK_APPL_NAF_MLC_PDDRM ... NAF_ADVANCED (MLC) based application with external RAM,
 *                               USB mode is MSC, Microsoft(R) PDDRMv1
 *
 * SDK_APPL_SWAP          ... NAF based application w/o external RAM,
 *                               USB mode is MTP, Microsoft(R) DRM10
 *
 * SDK_APPL_SD_PDDRM      ... SD/MMC based application w/o external RAM,
 *                               USB mode is MSC, Microsoft(R) PDDRMv1
 *
 * SDK_APPL_DEBUG         ... Debug application with external RAM,
 *                               USB mode is MSC, Microsoft (R) PDDRMv1
 *
 * NotYetImplemented:
 * SDK_APPL_SD_DMR10       ... SD/MMC based application w/o external RAM,
 *                               USB mode is MTP, Microsoft(R) DRM10
 **/
#ifndef  SDK_APPL_IDE_DRM10
    #define SDK_APPL_IDE_DRM10            0
#endif
#ifndef  SDK_APPL_IDE_PDDRM
    #define SDK_APPL_IDE_PDDRM            0
#endif
#ifndef  SDK_APPL_IDE_HOST
    #define SDK_APPL_IDE_HOST             0
#endif
#ifndef  SDK_APPL_NAF_DRM10
    #define SDK_APPL_NAF_DRM10            0
#endif
#ifndef  SDK_APPL_NAF_MLC_DRM10
    #define SDK_APPL_NAF_MLC_DRM10        0
#endif
#ifndef  SDK_APPL_NAF_PDDRM
    #define SDK_APPL_NAF_PDDRM            0
#endif
#ifndef  SDK_APPL_MSC_VIDEO
    #define SDK_APPL_MSC_VIDEO            0
#endif
#ifndef  SDK_APPL_NAF_MLC_DRM10
    #define SDK_APPL_NAF_MLC_DRM10        0
#endif
#ifndef  SDK_APPL_NAF_MLC_PDDRM
    #define SDK_APPL_NAF_MLC_PDDRM        0
#endif
#ifndef SDK_APPL_SWAP
    #define SDK_APPL_SWAP                 0
#endif
#ifndef  SDK_APPL_SD_DRM10
    #define SDK_APPL_SD_DRM10             0
#endif
#ifndef  SDK_APPL_SD_PDDRM
    #define SDK_APPL_SD_PDDRM             0
#endif
#ifndef SDK_APPL_DEBUG
    #define SDK_APPL_DEBUG                0
#endif

/*----------------------------------------------------------------------*/
/* Block Device Configuration                                           */
/*----------------------------------------------------------------------*/

/**
 * Select the block device you want to have during your appliation.
 * IDE and NAND cannot be enabled at the same time, as those share
 * pins. This is not supported in SW.
 * MMC and MST cannot be enabled at the same time, as those share
 * pins. This is not supported in SW.
 * The block device is automatically initialised and deinitialised.
 **/
#ifndef  SDK_USE_IDE_DRIVER
    #define SDK_USE_IDE_DRIVER            0
#endif
#ifndef SDK_USE_NAF_DRIVER
    #define SDK_USE_NAF_DRIVER            0
#endif
#ifndef SDK_USE_MMC_DRIVER
    #define SDK_USE_MMC_DRIVER            0
#endif
#ifndef SDK_USE_MST_DRIVER
    #define SDK_USE_MST_DRIVER            0
#endif
#ifndef SDK_USE_RAM_DRIVER
    #define SDK_USE_RAM_DRIVER            0
#endif


/*----------------------------------------------------------------------*/
/* USB Configuration                                                    */
/*----------------------------------------------------------------------*/

#ifndef SDK_USE_USB
    #define SDK_USE_USB                   0
#endif

#ifndef SDK_USB_HOST
    #define SDK_USB_HOST                    0
#endif

#ifndef SDK_USB_HIDE_SYSTEM_FOLDERS
    #define SDK_USB_HIDE_SYSTEM_FOLDERS   0
#endif

/*----------------------------------------------------------------------*/
/* MDDB Configuration                                                    */
/*----------------------------------------------------------------------*/

/*
 * The number of objects which can be stored in the MDDB
 * This number must cover files and folders.
 */
#ifndef SDK_OBJECTS_IN_MDDB
    #define SDK_OBJECTS_IN_MDDB           2048
#endif

/*----------------------------------------------------------------------*/
/* DRM Configuration                                                    */
/*----------------------------------------------------------------------*/

#ifndef SDK_USE_DRM10
    #define SDK_USE_DRM10             0
#endif

#if (SDK_USE_DRM10 == 1)
    #ifndef SDK_USE_WMA9_DECODER
        #define SDK_USE_WMA9_DECODER                 1
    #endif
    #ifndef SDK_USB_MODE_MTP
        #define SDK_USB_MODE_MTP                 1
    #endif
    #ifndef SDK_USE_RTC_DRIVER
        #define SDK_USE_RTC_DRIVER        1
    #endif
#else
    #ifndef SDK_USE_WMA9_DECODER
        #define SDK_USE_WMA9_DECODER                 0
    #endif
    #ifndef SDK_USB_MODE_MTP
        #define SDK_USB_MODE_MTP                 0
    #endif
#endif

#ifndef SDK_DRM_MODE_HOST
    #define SDK_DRM_MODE_HOST                0
#endif

/**
 * Operation Mode of the application can be set to:
 *    - Player Mode (only playback of DRM files)
 *    - Transfer Mode (only transfer of DRM files, also known as host
 *                     communication mode)
 *    - Monolithic Mode (playback and transfer of DRM files)
 **/
#define PLAYER_MODE         0
#define TRANSFER_MODE       1
#define MONOLITHIC_MODE     2

#ifndef SDK_OPERATION_MODE
    #define SDK_OPERATION_MODE        MONOLITHIC_MODE
#endif

/**
 * Media type of the storage medium attached to the device and used with DRM
 **/
#define SDK_USE_MMC     1
#define SDK_USE_IDE     2
#define SDK_USE_NAF     3

#ifndef SDK_DRM_MEDIA_TYPE
    #if (SDK_USE_IDE_DRIVER == 1)
        #define SDK_DRM_MEDIA_TYPE   SDK_USE_IDE
    #elif (SDK_USE_NAF_DRIVER == 1)
        #define SDK_DRM_MEDIA_TYPE   SDK_USE_NAF
    #elif (SDK_USE_MMC_DRIVER == 1)
        #define SDK_DRM_MEDIA_TYPE   SDK_USE_MMC
    #endif
#endif

/*----------------------------------------------------------------------*/
/* External Memory Configuration                                        */
/*----------------------------------------------------------------------*/

/**
 * Possible Values are:
 * - 16*1024*1024 == 16MB -- reference AS3527 reference player
 * - 64*1024*1024 == 64MB == external memory of 64MB is available
 **/

#if defined SDRAM_MT48H8M16LF
    #define SDK_EXT_MEMORY_SIZE     (16*1024*1024)
#else
    #define SDK_EXT_MEMORY_SIZE     (64*1024*1024)
#endif

/**
 * Define whether external memory shall be initialised or not.
 **/
#ifndef SDK_USE_EXT_MEMORY
    #define SDK_USE_EXT_MEMORY   0
#endif

#ifndef SDK_USE_EXT_CODE
    #define SDK_USE_EXT_CODE     0
#endif

#if (SDK_USE_EXT_CODE == 1)
/* This specifies that all addresses from 0x30000000 to 0x302fffff should be
   made cacheable */
    #ifndef SDK_EXT_CODE_SECTION_START
        #define SDK_EXT_CODE_SECTION_START      0x30000000
    #endif
    #ifndef SDK_EXT_CODE_SECTION_END
        #define SDK_EXT_CODE_SECTION_END        0x30200000
    #endif
#endif


/*----------------------------------------------------------------------*/
/* File Cache Configuration                                             */
/*----------------------------------------------------------------------*/

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
#ifndef SDK_FCA_BIG_BUFFER
    #define SDK_FCA_BIG_BUFFER            0   /* 1 == big , 0 == small */
#endif

/**
 * The actual memory sizes that are used for caching. Note that the small
 * buffer is placed in internal RAM while the big buffer is placed in
 * external RAM. AS3527 reference player has less than 32MB external RAM
 * so has to be this taken to account.
 **/
#if (SDK_FCA_BIG_BUFFER == 1)
    #ifdef SDRAM_MT48H8M16LF
        #ifndef SDK_FCA_MEMORY_SIZE
            #define SDK_FCA_MEMORY_SIZE       (8*1024*1024)
        #endif
    #else
        #ifndef SDK_FCA_MEMORY_SIZE
            #define SDK_FCA_MEMORY_SIZE       (32*1024*1024)
        #endif
    #endif /*SDRAM_MT48H8M16LF */

#   if (SDK_USE_MMC_DRIVER == 1)
/* SD driver supports transfers up to 0xffff bytes in one request, but for
   performance reasons the value 0xfe00 should be used */
        #define SDK_FCA_MAX_FILL_SIZE     (0xFE00)
#   else
    #if (SDK_USE_IDE_DRIVER == 1)
        #define SDK_FCA_MAX_FILL_SIZE     (0x1F000)
    #else
        #define SDK_FCA_MAX_FILL_SIZE     (0x4000)
    #endif
#endif

#else
    #define SDK_FCA_MEMORY_SIZE       (0x1800)
    #define SDK_FCA_MAX_FILL_SIZE     (0x800)
#endif


/*----------------------------------------------------------------------*/
/* Reloader Configuration                                               */
/*----------------------------------------------------------------------*/

/**
 * these are the possible settings for SDK_USE_RELOADER,
 * select the storage device for the reloadable code:
 **/
#define SDK_NO_RELOADER                  0
#define SDK_NAF_RELOADER                 1
#define SDK_IDE_RELOADER                 2
#define SDK_SD_RELOADER                  3

/* For debugging have the default not to use the reloader */
#ifndef SDK_USE_RELOADER
    #define SDK_USE_RELOADER                 SDK_NO_RELOADER
#endif


/* switch for application-swapping - can be found in naf_appl_swap\..\Makefile */
#ifndef SDK_RLD_APPLICATION_SWAP
    #define SDK_RLD_APPLICATION_SWAP                0
#endif

/**
 * max. size of the sum of all loadable data objects in [bytes],
 * must be multiple of 0x200 !
 **/
#ifndef SDK_MAX_LOADABLE_DATA_SIZE
    #define SDK_MAX_LOADABLE_DATA_SIZE       (0x200*0x200UL)
#endif

/**
 * number of max. available dynamically reloadable modules
 **/
#ifndef SDK_MAX_APPL_IN_PRIVATE_REGION
    #define SDK_MAX_APPL_IN_PRIVATE_REGION   (25)
#endif

/**
 * max. size of dyn. reloadable module [Bytes] - note that the bootloaders
 * only load up to 0x4F000 bytes. So the boot module must not be bigger
 * than 0x4C000.
 **/
#ifndef SDK_APPL_SIZE
    #define SDK_APPL_SIZE                    (0x40000UL)
#endif

/**
 * max. size of boot application module [Bytes]
 * Loaded by the bootloaders at startup, if activated.
 **/
#ifndef SDK_BOOT_APPL_SIZE
    #define SDK_BOOT_APPL_SIZE               (0x4F000UL)
#endif

/**
 * defines if the code section get names derived from the file name.
 * if the code section does not get names, the default names are
 * used. I.e. we have names for each function. This is necessary
 * for the naf_appl_swap application.
 **/
#ifndef SDK_DEFINE_CODE_SECTION_NAMES
     #define SDK_DEFINE_CODE_SECTION_NAMES 0
#endif


/*----------------------------------------------------------------------*/
/* NAND Flash Configuration                                             */
/*----------------------------------------------------------------------*/

/**
 * Currently supported NAF device types
 **/
#define SDK_NAND_64MB_SB       1
#define SDK_NAND_128MB_SB      2
#define SDK_NAND_128MB_BB      3
#define SDK_NAND_256MB_BB      4
#define SDK_NAND_512MB_BB      5
#define SDK_NAND_1024MB_BB     6
#define SDK_NAND_1024MB_BB_MLC 7
#define SDK_NAND_2048MB_BB_MLC 8
#define SDK_NAND_2048MB_BB_MLC_T56  9

/**
 * Number of attached NAND flashes
 **/
#ifndef SDK_NAF_MAX_DEVICES
    #define SDK_NAF_MAX_DEVICES 1
#endif


/**
 * start chip select line 0...3 for NAND flash(es). All other
 * NAND flashes must come consecutive. E.g. 0+1, or 2+3.
 **/

#define SDK_NAF_CHIP_SELECT                 0
#ifndef SDK_NAND_FLASH_TYPE
    #define SDK_NAND_FLASH_TYPE                 SDK_NAND_256MB_BB
#endif


/**
 * Number of NAND blocks in Private Region. Add ~10% for bad blocks.
 **/
#ifndef SDK_NAF_PRV_REGION_BLOCKS
#define SDK_NAF_PRV_REGION_BLOCKS                               \
        ( ( (  (SDK_MAX_APPL_IN_PRIVATE_REGION)          \
             * (SDK_APPL_SIZE)                           \
            )                                               \
            + SDK_MAX_LOADABLE_DATA_SIZE                 \
          )                                                 \
          / (SDK_NAF_BLOCK_SIZE_IN_BYTES)                       \
          * 11                                              \
          / 10                                              \
          * SDK_NAF_LOSS_MULTIPLIER                      \
        )
#endif

#ifndef SDK_NAF_USE_DMA
    #define SDK_NAF_USE_DMA 1
#endif

/*----------------------------------------------------------------------*/
/* Various Features Configuration                                       */
/*----------------------------------------------------------------------*/

/**
 * If this feature is enabled the user can copy files to naf by pressing
 * the mute key.
 **/
//#define USER_FILE_COPY_ENABLE


#ifndef SDK_USE_BLUETOOTH
    #define SDK_USE_BLUETOOTH            0
#endif

/**
 *  switch of DataBase Browser
 */
#ifndef SDK_USER_BROWSE_DB
    #define SDK_USER_BROWSE_DB                   0
#endif

/* maximum number of files within one directory which can be displayed on the
 * user interface */
#ifndef SDK_MAX_NR_OF_FILES_IN_ONE_DIR
    #define SDK_MAX_NR_OF_FILES_IN_ONE_DIR 1100
#endif

/**
 * This define is used when the file system is formatted in
 * promer or factory reset. The value of 32 results in:
 * - 64kB Cluster Size for NAND Flashes with 2kB Block Size
 * - 16kB  Cluster Size for IDE and SD with 512B Block Size
 * This shall be overruled in sdk_config.h with a value
 * which fits better to the needs of the application since this
 * default
 **/

#ifndef SDK_FS_FAT_SECTORS_PER_CLUSTER
    #if (SDK_USE_NAF_DRIVER)
        #define SDK_FS_FAT_SECTORS_PER_CLUSTER   (16)
    #elif (SDK_USE_IDE_DRIVER)
        #define SDK_FS_FAT_SECTORS_PER_CLUSTER   (32)
    #else /* for SD/MMC, etc. */
        #define SDK_FS_FAT_SECTORS_PER_CLUSTER   (32)
    #endif
#endif

/* enable charger */
#ifndef SDK_USER_CHARGER_ENABLE
    #define SDK_USER_CHARGER_ENABLE     0
#endif

/* supported equalizer settings */
#define SDK_DSP_EQ_OFF      0
#define SDK_DSP_EQ_6DB      1
#define SDK_DSP_EQ_12DB     2
/* enable/disable the equaliser */
#ifndef SDK_USE_EQUALISER
    #define SDK_USE_EQUALISER    SDK_DSP_EQ_6DB
#endif

/* enable/disable digital volume */
#ifndef SDK_USE_DIGITAL_VOLUME
    #define SDK_USE_DIGITAL_VOLUME           0
#endif

#ifndef SDK_APPL_USE_RECORDER
    #define SDK_APPL_USE_RECORDER                   1
#endif

/* Should dma transfers of DMAC and IDE dma master to cacheable memory be
   allowed? This makes file I/O much easier. However a bit of extra code is
   added. Also write-through mode is employed which reduces performance
   some 10%.
*/
#ifndef SDK_ALLOW_DMA_ON_CACHEABLE_MEM
    #define SDK_ALLOW_DMA_ON_CACHEABLE_MEM     0
#endif

/**
 * enable/disable the factory reset functionality which formats the media
 * and creates the folders and the necessary content required by MS-WMDRM10-PD
 **/
#ifndef SDK_APPL_FACTORY_RESET
    #define SDK_APPL_FACTORY_RESET                  0
#endif

/* enable/disable keyboard keys */
#ifndef SDK_USE_ALTERNATE_KEYBOARD
    #define SDK_USE_ALTERNATE_KEYBOARD       0
#endif

/* OS_LIBMODE_R is currently the only mode of the RTOS which is supported
   USB depends on it.  */
#define OS_LIBMODE_R

/* FIXME Bluetooth headsets are not yet supported in this SDK version! */
#ifndef SDK_USE_BLUETOOTH
    #define SDK_USE_BLUETOOTH 0
#endif

/*----------------------------------------------------------------------*/
/* Video Decoder Configuration                                          */
/*----------------------------------------------------------------------*/
#ifndef SDK_USE_MP4_DECODER
    #define SDK_USE_MP4_DECODER      0
#endif

#ifndef SDK_USE_WMV_DECODER
    #define SDK_USE_WMV_DECODER      0
#endif

/*----------------------------------------------------------------------*/
/* Audio De/Encoder Configuration                                       */
/*----------------------------------------------------------------------*/

#ifndef SDK_USE_IMA_DECODER
    #define SDK_USE_IMA_DECODER      1
#endif

#ifndef SDK_USE_WAV_DECODER
    #define SDK_USE_WAV_DECODER      1
#endif

#ifndef SDK_USE_MP3_DECODER
    #define SDK_USE_MP3_DECODER      1
#endif

#ifndef SDK_USE_WMA_DECODER
    #define SDK_USE_WMA_DECODER      1
#endif

#ifndef SDK_USE_OGG_DECODER
    #define SDK_USE_OGG_DECODER      1
#endif

#ifndef SDK_USE_IMA_ENCODER
    #define SDK_USE_IMA_ENCODER      1
#endif

#ifndef SDK_USE_WAV_ENCODER
    #define SDK_USE_WAV_ENCODER      1
#endif

#ifndef SDK_USE_MP3_ENCODER
    #define SDK_USE_MP3_ENCODER      1
#endif

#ifndef SDK_USE_AAC_DECODER
    #if (SDK_USE_MP4_DECODER == 1)
        #define SDK_USE_AAC_DECODER      1
    #else
        #define SDK_USE_AAC_DECODER      0
    #endif
#endif

#ifndef SDK_USE_AUDIBLE_DECODER
    #define SDK_USE_AUDIBLE_DECODER      0
#endif

/* directory where the recorded files will be stored (may also be a directory
 * tree separated by \\ ) */
#ifndef SDK_RECORDER_DIRECTORY
    #define SDK_RECORDER_DIRECTORY   "voice"
#endif


/* template filename which will be used to store the recorded files by adding
 * a sequential number */
#ifndef SDK_RECORDER_FILENAME
    #define SDK_RECORDER_FILENAME    "rfile"
#endif

/* activates the restrictions in the recorder settings for mp3 */
#ifndef SDK_REC_ENABLE_MP3_SETTINGS_RESTRICTION
    #define SDK_REC_ENABLE_MP3_SETTINGS_RESTRICTION    1
#endif


/*----------------------------------------------------------------------*/
/* Driver Configuration                                                 */
/*----------------------------------------------------------------------*/

/**
 * Currently drivers which can be disabled in cgu_driver are given here.
 * However more can be added like RTC driver.
 **/

#ifndef SDK_USE_I2S_DRIVER
    #define SDK_USE_I2S_DRIVER  1
#endif

#ifndef SDK_USE_SSP_DRIVER
    #define SDK_USE_SSP_DRIVER  0
#endif

#ifndef SDK_USE_UART_DRIVER
    #if (SDK_USE_BLUETOOTH == 1)
        /* The UART is used for communication with the BlueCore4-ROM chip,  */
        /* hence debugging can only be done via the console!!!              */
        #define SDK_USE_UART_DRIVER 1
        #define USE_UART_BT
    #else
#if defined(SDK_DEBUG_SERIAL) && SDK_DEBUG_SERIAL
    #define SDK_USE_UART_DRIVER 1
#else
    #define SDK_USE_UART_DRIVER 0
#endif
    #endif
#endif

#ifndef SDK_USE_DBOP
    #define SDK_USE_DBOP        1
#endif

/* disable RTC driver per default if application is not using DRM10 */
#ifndef SDK_USE_RTC_DRIVER
/* NAF needs RTC as seed generator */
#if SDK_USE_NAF_DRIVER
    #define SDK_USE_RTC_DRIVER  1
#else
    #define SDK_USE_RTC_DRIVER  0
#endif
#endif

/* Most applications don't need SPDIF input, however we want to show it.*/
#ifndef SDK_USE_SPDIF_INPUT
    #define SDK_USE_SPDIF_INPUT 1
#endif

/* Use DMA for I2SOUT and I2SIN transfers                                    */
#ifndef SDK_I2SOUT_USE_DMA
    #define SDK_I2SOUT_USE_DMA  1
#endif

#ifndef SDK_I2SIN_USE_DMA
    #define SDK_I2SIN_USE_DMA   1
#endif

/*----------------------------------------------------------------------*/
/* AFE Configuration                                                    */
/*----------------------------------------------------------------------*/

/* _Obsolete_ old defines           */
/* 17224 is AS3515, 17182 is AS3517 */
#ifndef  ANALOG_17224
#ifndef  ANALOG_17182
    #define  ANALOG_17224
#endif
#endif


/* supported afe chips */
#define AFE_AS3515 1
#define AFE_AS3517 2
#define AFE_AS3658 3

/* default is AS3515   */
#ifndef AFE_CHIP_TYPE
    #ifdef ANALOG_17224
        #define AFE_CHIP_TYPE  AFE_AS3515
    #else
        #define AFE_CHIP_TYPE  AFE_AS3517
    #endif
#endif


#ifndef SDK_AFE_ENABLE_SHADOW
    #define SDK_AFE_ENABLE_SHADOW 0
#endif

/* _Obsolete_ as the blocking mode of the AFE driver is not supported
   any more.
*/
#ifndef SDK_AFE_USE_BLOCKING_MODE
    #define SDK_AFE_USE_BLOCKING_MODE    0
#endif


/*----------------------------------------------------------------------*/
/* Hardware Configuration                                                  */
/*----------------------------------------------------------------------*/

#ifndef SDK_CHG_BATTERY_IS_SEPARATED
    #define SDK_CHG_BATTERY_IS_SEPARATED  0
#endif

/*----------------------------------------------------------------------*/
/* Display Configuration                                                */
/*----------------------------------------------------------------------*/

/* supported display types */
#define BATRON_128064_AVC               1
#define TIANMA_128160_CKFWG             2
#define SHARP_176220                    3
#define DISPLAY_HX8903_176220_CKFWG     4

/* select the currently used display type */
#ifndef SDK_DISPLAY_TYPE
    #define SDK_DISPLAY_TYPE  TIANMA_128160_CKFWG
#endif

/* define if DMA-Transfer to Display_Controler should be enabled */

#ifndef SDK_LCD_USE_DMA
    #if ((SDK_USE_MP4_DECODER == 1) || (SDK_USE_WMV_DECODER == 1))
        #define SDK_LCD_USE_DMA      1
    #else
    #define SDK_LCD_USE_DMA                  0
#endif
#endif

#ifndef SDK_IDE_POWER_IS_DCDC3
    #define SDK_IDE_POWER_IS_DCDC3 0
#endif

/* Graphical User Interface Settings */
#ifndef GUI_SUPPORT_MOUSE
    #define GUI_SUPPORT_MOUSE           0    /* Support a mouse */
#endif
#ifndef GUI_WINSUPPORT
    #define GUI_WINSUPPORT              0    /* Use window manager */
#endif
#ifndef GUI_SUPPORT_ROTATION
    #if ((SDK_USE_MP4_DECODER == 1) || (SDK_USE_WMV_DECODER == 1))
        #define GUI_SUPPORT_ROTATION    1
    #else
        #define GUI_SUPPORT_ROTATION    0    /* Disable support for text rotation */
    #endif
#endif

#ifndef GUI_SUPPORT_MEMDEV
    #if ((SDK_USE_MP4_DECODER == 1) || (SDK_USE_WMV_DECODER == 1))
        #define GUI_SUPPORT_MEMDEV      1
    #else
        #define GUI_SUPPORT_MEMDEV      0    /* Memory device package not available */
    #endif
#endif
#ifndef GUI_SUPPORT_AA
    #define GUI_SUPPORT_AA              0    /* Antialiasing package not available */
#endif
#ifndef GUI_ALLOC_SIZE
    #if ((SDK_USE_MP4_DECODER == 1) || (SDK_USE_WMV_DECODER == 1))
        #define GUI_ALLOC_SIZE          180000  /* Size of dynamic memory ... */
                                                /* For WM, cursor and memory devices */
    #else
        #define GUI_ALLOC_SIZE          1000    /* Size of dynamic memory ... */
                                                /* For WM, cursor and memory devices */
    #endif
#endif

/*----------------------------------------------------------------------*/
/* Debug Configuration                                                  */
/*----------------------------------------------------------------------*/

#ifndef SDK_DEBUG_SWITCH_RAM_RELOADER
    #define SDK_DEBUG_SWITCH_RAM_RELOADER   0
#endif

#ifndef SDK_DEBUG_SERIAL
    #define SDK_DEBUG_SERIAL            0
#endif

#ifndef SDK_DEBUG_CONSOLE
    #define SDK_DEBUG_CONSOLE           0
#endif

#ifndef SDK_DEBUG_BUFFER
    #define SDK_DEBUG_BUFFER            0
#endif

#ifndef SDK_USE_ASSERT
    #define SDK_USE_ASSERT       0
#endif

#ifndef USE_EMBOS_VIEW
    #define USE_EMBOS_VIEW          0
#endif

#ifndef SDK_USE_HEAP_TRACE
    #define SDK_USE_HEAP_TRACE   0
#endif

#ifndef SDK_USE_AMS_FS_VERBOSE
    #define SDK_USE_AMS_FS_VERBOSE    0
#endif

/* dis/enable write protection for internal memory (0x00 to 0x50000) and make
 * internal memory in address range 0xC1000000 to 0xC1050000 cachable in order
 * to load the data there
 *
 * CAUTION: if enabled, YOU HAVE TO organize the scatter-load file in such a
 *          way that data stays now in internal memory address range
 *          0xC1000000 to 0xC1050000!!!
 */
#ifndef SDK_DEBUG_WRITEPROTECT_INT_MEM
    #define SDK_DEBUG_WRITEPROTECT_INT_MEM      0
#endif


#include "sdk_calc_config.h"
#include "sdk_naf_config.h" /* get naf specific defines */

#endif /*_SDK_DEFAULTS_H_*/



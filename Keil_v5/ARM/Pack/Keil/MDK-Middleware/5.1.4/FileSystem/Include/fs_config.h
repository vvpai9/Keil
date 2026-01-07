/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::File System
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    fs_config.h
 * Purpose: File System Library Configuration
 * Rev.:    V5.05
 *----------------------------------------------------------------------------*/

#include <absacc.h>
#include <string.h>
#include <rt_sys.h>
#include "rl_fs_lib.h"

#pragma thumb
#pragma O3

/*-----------------------------------------------------------------------------
 *      File System Configuration File
 *----------------------------------------------------------------------------*/

#ifdef __MICROLIB
  #error "File System does not work with MicroLIB"
#endif

/* ---------------------------------------------------------------------------*/

#ifndef NOR0_ENABLE
  #define NOR0_ENABLE  0
  #define NOR0_DEFAULT_DRIVE 0
#endif

#ifndef NOR1_ENABLE
  #define NOR1_ENABLE  0
  #define NOR1_DEFAULT_DRIVE 0
#endif

#ifndef RAM0_ENABLE
  #define RAM0_ENABLE  0
  #define RAM0_DEFAULT_DRIVE 0
#endif

/* If MC0 drive not defined */
#ifndef MC0_ENABLE
  #define MC0_ENABLE   0
  #define MC0_DEFAULT_DRIVE 0
#endif

/* If MC1 drive not defined */
#ifndef MC1_ENABLE
  #define MC1_ENABLE   0
  #define MC1_DEFAULT_DRIVE 0
#endif

/* If NAND0 drive not defined */
#ifndef NAND0_ENABLE
  #define NAND0_ENABLE  0
  #define NAND0_DEFAULT_DRIVE 0
#endif

/* If NAND1 drive not defined */
#ifndef NAND1_ENABLE
  #define NAND1_ENABLE  0
  #define NAND1_DEFAULT_DRIVE 0
#endif

/* If USB0 drive not defined */
#ifndef USB0_ENABLE
  #define USB0_ENABLE  0
  #define USB0_DEFAULT_DRIVE 0
#endif

/* If USB1 drive not defined */
#ifndef USB1_ENABLE
  #define USB1_ENABLE  0
  #define USB1_DEFAULT_DRIVE 0
#endif

/* FS_Config V5.00 compatibility */
#ifndef FAT_MAX_OPEN_FILES
  #define FAT_MAX_OPEN_FILES NUM_FILES
#endif
#ifndef EFS_MAX_OPEN_FILES
  #define EFS_MAX_OPEN_FILES NUM_FILES
#endif

/* ---------------------------------------------------------------------------*/

/* Check number of enabled drives */
#define FS_NDRV (NOR0_ENABLE  + NOR1_ENABLE +   \
                 RAM0_ENABLE  +                 \
                 MC0_ENABLE   + MC1_ENABLE  +   \
                 USB0_ENABLE  + USB1_ENABLE +   \
                 NAND0_ENABLE + NAND1_ENABLE)
#if (FS_NDRV == 0)
  #error "No drive enabled, File System requires at least on component ::File System:Drive"
#endif

/* Count number of enabled FAT drives */
#define FS_FAT_NDRV (RAM0_ENABLE  +               \
                     MC0_ENABLE   + MC1_ENABLE  + \
                     USB0_ENABLE  + USB1_ENABLE + \
                     NAND0_ENABLE + NAND1_ENABLE)

/* Count number of enabled NAND devices */
#define FS_NAND_NDRV  (NAND0_ENABLE + NAND1_ENABLE)

/* Check Default drive settings */
#define __DEF  ((NOR0_DEFAULT_DRIVE  & NOR0_ENABLE)  +  \
                (NOR1_DEFAULT_DRIVE  & NOR1_ENABLE)  +  \
                (RAM0_DEFAULT_DRIVE  & RAM0_ENABLE)  +  \
                (MC0_DEFAULT_DRIVE   & MC0_ENABLE)   +  \
                (MC1_DEFAULT_DRIVE   & MC1_ENABLE)   +  \
                (USB0_DEFAULT_DRIVE  & USB0_ENABLE)  +  \
                (USB1_DEFAULT_DRIVE  & USB1_ENABLE)  +  \
                (NAND0_DEFAULT_DRIVE & NAND0_ENABLE) +  \
                (NAND1_DEFAULT_DRIVE & NAND1_ENABLE))
#if (__DEF == 0)
  #error "Default ::File System:Drive not specified"
#elif (__DEF > 1)
  #error "Multiple default ::File System:Drive: enabled"
#endif

/* Check MCI port consistency */
#if (MC0_ENABLE && MC1_ENABLE)
  #if (MC0_MCI_DRIVER == MC1_MCI_DRIVER)
    #error "::File System:Drive:Memory Card: MCI ports for different drives must be different"
  #endif
#endif

/* Check FS usage */
#define EFS_USE (NOR0_ENABLE + NOR1_ENABLE)
#define FAT_USE (RAM0_ENABLE + MC0_ENABLE + MC1_ENABLE + USB0_ENABLE + USB1_ENABLE + NAND0_ENABLE + NAND1_ENABLE)

/* Check journal usage */
#define FSJ_USE (MC0_ENABLE   * MC0_FAT_JOURNAL   +  \
                 MC1_ENABLE   * MC1_FAT_JOURNAL   +  \
                 USB0_ENABLE  * USB0_FAT_JOURNAL  +  \
                 USB1_ENABLE  * USB1_FAT_JOURNAL  +  \
                 NAND0_ENABLE * NAND0_FAT_JOURNAL +  \
                 NAND1_ENABLE * NAND1_FAT_JOURNAL)

/* Reserved sector count */
#define FAT_SECT_RSVD 64

/* Make sure to resolve a weak stdlib symbol. */
#ifdef __RTX
extern volatile int _stream_list_lock;
  #define STREAM_LIST_LOCK   _stream_list_lock;
#else
 #define STREAM_LIST_LOCK
#endif

/* File Control Blocks for the FAT File System */
#define FAT_HANDLE_COUNT ((FAT_MAX_OPEN_FILES > 0) ? FAT_MAX_OPEN_FILES : 1)
fsFAT_Handle fs_fat_fh[FAT_HANDLE_COUNT];
uint8_t const FS_FAT_MAX_FILES = FAT_MAX_OPEN_FILES;

/* File Control Blocks for the Embedded File System */
#define EFS_HANDLE_COUNT ((EFS_MAX_OPEN_FILES > 0) ? EFS_MAX_OPEN_FILES : 1)
fsEFS_Handle fs_efs_fh[EFS_HANDLE_COUNT];
uint8_t const FS_EFS_MAX_FILES = EFS_MAX_OPEN_FILES;

/* Number of enabled drives */
uint8_t const _NDRV = FS_NDRV;

/*----------------------------------------------------------------------------
 *  FAT Name Cache definition and configuration
 *---------------------------------------------------------------------------*/
#if (FAT_NAME_CACHE_SIZE == 0)
  FAT_NCACHE_CFG fat_ncache = {
    0, 0, 0, NULL
  };
#else
  #if (FAT_NAME_CACHE_RELOC == 1)
    #define __AT_FAT_NAME  __at(FAT_NAME_CACHE_ADDR)
  #else
    #define __AT_FAT_NAME
  #endif

  /* FAT name cache max folder depth */
  #define FAT_NAME_MAX_DEPTH 8

  /* FAT name cache control block size and count */
  #define FAT_NAME_CB_SZ (16)
  #define FAT_NAME_CB_POOL_SZ     (FAT_NAME_CB_SZ * FS_FAT_NDRV)

  /* FAT name cache folder depth control block size */
  #define FAT_NAME_DEPTH_CB_SZ (8)
  #define FAT_NAME_DEPTH_POOL_SZ  (FAT_NAME_DEPTH_CB_SZ * FAT_NAME_MAX_DEPTH * FS_FAT_NDRV)

  /* FAT name cache pool size  */
  #define FAT_NAME_LINK_SZ  (48)
  #define FAT_NAME_LINK_POOL_SZ   (FAT_NAME_LINK_SZ * FAT_NAME_CACHE_SIZE)

  /* FAT name cache buffer size in bytes */
  #define FAT_NAME_POOL_SIZE (FAT_NAME_CB_POOL_SZ    + \
                              FAT_NAME_DEPTH_POOL_SZ + \
                              FAT_NAME_LINK_POOL_SZ)

  static uint32_t fat_name_pool[FAT_NAME_POOL_SIZE/4] __AT_FAT_NAME;

  FAT_NCACHE_CFG fat_ncache = {
    FAT_NAME_MAX_DEPTH,
    FS_FAT_NDRV,
    FAT_NAME_POOL_SIZE,
    fat_name_pool
  };
#endif /* FAT_NAME_CACNT */

#define EXPAND_SYMBOL(name, port) name##port
#define CREATE_SYMBOL(name, port) EXPAND_SYMBOL(name, port)

/*----------------------------------------------------------------------------
 *  Drive F0: NOR Flash device NOR0 configuration
 *---------------------------------------------------------------------------*/
#if (NOR0_ENABLE)
  static fsEFS_Volume   nor0_vol;

  extern ARM_DRIVER_NOR CREATE_SYMBOL (Driver_NOR_,     NOR0_NAME);
  extern ARM_NOR_DEVICE CREATE_SYMBOL (NOR_Device_,     NOR0_NAME);

  #if (NOR0_SPI)
  extern ARM_DRIVER_SPI CREATE_SYMBOL (Driver_SPI,      NOR0_SPI_DRIVER);
  ARM_DRIVER_SPI       *CREATE_SYMBOL (NOR_SPI_Driver_, NOR0_NAME) = &CREATE_SYMBOL (Driver_SPI, NOR0_SPI_DRIVER);
  #endif
#endif

/*----------------------------------------------------------------------------
 *  Drive F1: NOR Flash device NOR1 configuration
 *---------------------------------------------------------------------------*/
#if (NOR1_ENABLE)
  static fsEFS_Volume   nor1_vol;

  extern ARM_DRIVER_NOR CREATE_SYMBOL (Driver_NOR_,     NOR1_NAME);
  extern ARM_NOR_DEVICE CREATE_SYMBOL (NOR_Device_,     NOR1_NAME);

  #if (NOR1_SPI)
  extern ARM_DRIVER_SPI CREATE_SYMBOL (Driver_SPI,      NOR1_SPI_DRIVER);
  ARM_DRIVER_SPI       *CREATE_SYMBOL (NOR_SPI_Driver_, NOR1_NAME) = &CREATE_SYMBOL (Driver_SPI, NOR1_SPI_DRIVER);
  #endif
#endif

/*----------------------------------------------------------------------------
 *  Drive M0: Memory Card device MC0 configuration
 *---------------------------------------------------------------------------*/
#if (MC0_ENABLE)
  static fsFAT_Volume mc0_vol;
  static MCI_DEV      mc0_dev;

  #if (MC0_FAT_JOURNAL)
  static FSJOUR mc0_fsj;
  #endif

  extern ARM_DRIVER_MCI CREATE_SYMBOL (Driver_MCI, MC0_MCI_DRIVER);

  #if (MC0_CACHE_RELOC == 1)
    #define __AT_MC0  __at(MC0_CACHE_ADDR)
  #else
    #define __AT_MC0
  #endif

  /* MC0 Cache Buffer for Data and FAT Caching */
  static uint32_t mc0_cache[(MC0_CACHE_SIZE+1) * 256 + MC0_FAT_JOURNAL * 128] __AT_MC0;

  #if (MC0_SPI == 0)
    /* SD Native bus mode */
    #define MC0_INIT(m)      mc_mci_Init        (m,       &mc0_dev)
    #define MC0_UNINIT(m)    mc_mci_UnInit      (m,       &mc0_dev)
    #define MC0_RDSEC(s,b,c) mc_mci_ReadSector  (s, b, c, &mc0_dev)
    #define MC0_WRSEC(s,b,c) mc_mci_WriteSector (s, b, c, &mc0_dev)
    #define MC0_RDINFO(i)    mc_mci_ReadInfo    (i,       &mc0_dev)
    #define MC0_DEVCTRL(c,p) mc_mci_DevCtrl     (c, p,    &mc0_dev)
  #else
    /* SPI bus mode */
    #define MC0_INIT(m)      mc_spi_Init        (m,       &mc0_dev)
    #define MC0_UNINIT(m)    mc_spi_UnInit      (m,       &mc0_dev)
    #define MC0_RDSEC(s,b,c) mc_spi_ReadSector  (s, b, c, &mc0_dev)
    #define MC0_WRSEC(s,b,c) mc_spi_WriteSector (s, b, c, &mc0_dev)
    #define MC0_RDINFO(i)    mc_spi_ReadInfo    (i,       &mc0_dev)
    #define MC0_DEVCTRL(c,p) mc_spi_DevCtrl     (c, p,    &mc0_dev)

    extern ARM_DRIVER_SPI CREATE_SYMBOL (Driver_SPI, MC0_SPI_DRIVER);
  #endif

  /* MC0 wrapper functions */
  static uint32_t mc0_Init (uint32_t mode) {
    return (MC0_INIT (mode));
  }
  static uint32_t mc0_UnInit (uint32_t mode) {
    return (MC0_UNINIT (mode));
  }
  static uint32_t mc0_RdSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    return (MC0_RDSEC (sect, buf, cnt));
  }
  static uint32_t mc0_WrSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    return (MC0_WRSEC (sect, buf, cnt));
  }
  static uint32_t mc0_RdInfo (fsMediaInfo *info) {
    return (MC0_RDINFO (info));
  }
  static fsStatus mc0_DevCtrl (fsDevCtrlCode code, void *p) {
    return (MC0_DEVCTRL (code, p));
  }

  /* MC0 FAT device driver */
  FAT_DRV mc0_drv = {
    mc0_Init,
    mc0_UnInit,
    mc0_RdSect,
    mc0_WrSect,
    mc0_RdInfo,
    mc0_DevCtrl
  };

  /* ------- MC0 MCI/SPI Callback ------- */
  static void MC0_MCI_SignalEvent (ARM_MCI_EVENT event) {
    mc_mci_DrvEvent (event, &mc0_dev);
  }
  #if (MC0_SPI != 0)
  static void MC0_SPI_SignalEvent (ARM_SPI_EVENT event) {
    mc_spi_DrvEvent (event, &mc0_dev);
  }
  #endif
#endif

/*----------------------------------------------------------------------------
 *  Drive M1: Memory Card device MC1 configuration
 *---------------------------------------------------------------------------*/
#if (MC1_ENABLE)
  static fsFAT_Volume mc1_vol;
  static MCI_DEV      mc1_dev;

  #if (MC1_FAT_JOURNAL)
  static FSJOUR mc1_fsj;
  #endif

  extern ARM_DRIVER_MCI CREATE_SYMBOL (Driver_MCI, MC1_MCI_DRIVER);

  #if (MC1_CACHE_RELOC == 1)
    #define __AT_MC1  __at(MC1_CACHE_ADDR)
  #else
    #define __AT_MC1
  #endif

  /* MC1 Cache Buffer for Data and FAT Caching */
  static uint32_t mc1_cache[(MC1_CACHE_SIZE+1) * 256 + MC1_FAT_JOURNAL * 128] __AT_MC1;

  #if (MC1_SPI == 0)
    /* SD Native bus mode */
    #define MC1_INIT(m)      mc_mci_Init        (m,       &mc1_dev)
    #define MC1_UNINIT(m)    mc_mci_UnInit      (m,       &mc1_dev)
    #define MC1_RDSEC(s,b,c) mc_mci_ReadSector  (s, b, c, &mc1_dev)
    #define MC1_WRSEC(s,b,c) mc_mci_WriteSector (s, b, c, &mc1_dev)
    #define MC1_RDINFO(i)    mc_mci_ReadInfo    (i,       &mc1_dev)
    #define MC1_DEVCTRL(c,p) mc_mci_DevCtrl     (c, p,    &mc1_dev)
  #else
    /* SPI bus mode */
    #define MC1_INIT(m)      mc_spi_Init        (m,       &mc1_dev)
    #define MC1_UNINIT(m)    mc_spi_UnInit      (m,       &mc1_dev)
    #define MC1_RDSEC(s,b,c) mc_spi_ReadSector  (s, b, c, &mc1_dev)
    #define MC1_WRSEC(s,b,c) mc_spi_WriteSector (s, b, c, &mc1_dev)
    #define MC1_RDINFO(i)    mc_spi_ReadInfo    (i,       &mc1_dev)
    #define MC1_DEVCTRL(c,p) mc_spi_DevCtrl     (c, p,    &mc1_dev)

    extern ARM_DRIVER_SPI CREATE_SYMBOL (Driver_SPI, MC1_SPI_DRIVER);
  #endif

  /* MC1 wrapper functions */
  static uint32_t mc1_Init (uint32_t mode) {
    return (MC1_INIT (mode));
  }
  static uint32_t mc1_UnInit (uint32_t mode) {
    return (MC1_UNINIT (mode));
  }
  static uint32_t mc1_RdSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    return (MC1_RDSEC (sect, buf, cnt));
  }
  static uint32_t mc1_WrSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    return (MC1_WRSEC (sect, buf, cnt));
  }
  static uint32_t mc1_RdInfo (fsMediaInfo *info) {
    return (MC1_RDINFO (info));
  }
  static fsStatus mc1_DevCtrl (fsDevCtrlCode code, void *p) {
    return (MC1_DEVCTRL (code, p));
  }

  /* MC1 FAT device driver */
  FAT_DRV mc1_drv = {
    mc1_Init,
    mc1_UnInit,
    mc1_RdSect,
    mc1_WrSect,
    mc1_RdInfo,
    mc1_DevCtrl
  };

  /* ------- MC1 MCI/SPI Callback ------- */
  static void MC1_MCI_SignalEvent (ARM_MCI_EVENT event) {
    mc_mci_DrvEvent (event, &mc1_dev);
  }
  #if (MC1_SPI != 0)
  static void MC1_SPI_SignalEvent (ARM_SPI_EVENT event) {
    mc_spi_DrvEvent (event, &mc1_dev);
  }
  #endif
#endif

/*----------------------------------------------------------------------------
 *  General NAND Flash device configuration
 *---------------------------------------------------------------------------*/
#ifdef RTE_FileSystem_Drive_NAND_0
  #if (NAND0_ENABLE)
    #define NAND_INFO_0_DEV_0

    #if ((NAND1_ENABLE) && (NAND1_DRIVER == NAND0_DRIVER))
      #if (NAND1_DEV_NUM == NAND0_DEV_NUM)
        #error "::File System:Drive:NAND: NAND ports for different drives must be different"
      #endif
      #define NAND_INFO_0_DEV_1
    #endif
  #endif
#endif

#ifdef RTE_FileSystem_Drive_NAND_1
  #if (((NAND0_ENABLE == 0) && NAND1_ENABLE) || ((NAND0_ENABLE && NAND1_ENABLE) && (NAND1_DRIVER != NAND0_DRIVER)))
    #define NAND_INFO_1_DEV_0
  #endif
#endif

#if (NAND0_ENABLE)
  static fsFAT_Volume nand0_vol;
  static NAND_FTL_DEV nand0_dev;

  #if (NAND0_FAT_JOURNAL)
  static FSJOUR       nand0_fsj;
  #endif

  extern ARM_DRIVER_NAND  CREATE_SYMBOL (Driver_NAND, NAND0_DRIVER);
#endif

#if (NAND1_ENABLE)
  static fsFAT_Volume nand1_vol;
  static NAND_FTL_DEV nand1_dev;

  #if (NAND1_FAT_JOURNAL)
  static FSJOUR       nand1_fsj;
  #endif

  #if defined(NAND_INFO_1_DEV_0)
  extern ARM_DRIVER_NAND  CREATE_SYMBOL (Driver_NAND, NAND1_DRIVER);
  #endif
#endif

#if defined(NAND_INFO_0_DEV_0)
  #define NAND0_EVENT_HANDLER   NAND_SignalEventHandler0
  #if defined(NAND_INFO_0_DEV_1)
    #define NAND1_EVENT_HANDLER  NAND_SignalEventHandler0
  #endif

  void NAND_SignalEventHandler0 (uint32_t dev_num) {
    switch (dev_num) {
      case NAND0_DEV_NUM: ftl_DrvEvent (&nand0_dev); break;

      #if defined(NAND_INFO_0_DEV_1)
      case NAND1_DEV_NUM: ftl_DrvEvent (&nand1_dev); break;
      #endif

      default: return;
    }
  }

  ARM_NAND_DEVICE NAND_DevInfo0[] = {
    {&nand0_dev.PgLay,
     NAND0_TYPE,
     NAND0_DEV_NUM,
     NAND0_PAGE_SIZE,
     NAND0_BLOCK_COUNT,
     NAND0_PAGE_COUNT,
     NAND_SEC_BLOCK  (NAND0_PAGE_COUNT, NAND0_PAGE_SIZE),
     NAND_SEC_PAGE   (NAND0_PAGE_SIZE),
     NAND_ROW_CYCLES (NAND0_BLOCK_COUNT, NAND0_PAGE_COUNT),
     NAND_COL_CYCLES (NAND0_PAGE_SIZE),
     NAND0_SW_ECC
    },
    #if defined(NAND_INFO_0_DEV_1)
    {&nand1_dev.PgLay,
     NAND1_TYPE,
     NAND1_DEV_NUM,
     NAND1_PAGE_SIZE,
     NAND1_BLOCK_COUNT,
     NAND1_PAGE_COUNT,
     NAND_SEC_BLOCK  (NAND1_PAGE_COUNT, NAND1_PAGE_SIZE),
     NAND_SEC_PAGE   (NAND1_PAGE_SIZE),
     NAND_ROW_CYCLES (NAND1_BLOCK_COUNT, NAND1_PAGE_COUNT),
     NAND_COL_CYCLES (NAND1_PAGE_SIZE),
     NAND1_SW_ECC
    },
    #endif
  };
  #define NAND_INFO0      NAND_DevInfo0
  #define NAND_INFO0_SZ   (sizeof(NAND_DevInfo0) / sizeof(NAND_DevInfo0[0]))
#else
  #define NAND_INFO0      NULL
  #define NAND_INFO0_SZ   0
#endif

#if defined(NAND_INFO_1_DEV_0)
  #define NAND1_EVENT_HANDLER    NAND_SignalEventHandler1

  void NAND_SignalEventHandler1 (uint32_t dev_num) {
    switch (dev_num) {
      case NAND1_DEV_NUM: ftl_DrvEvent (&nand1_dev); break;

      default: return;
    }
  }

  ARM_NAND_DEVICE NAND_DevInfo1[] = {
    {&nand1_dev.PgLay,
     NAND1_TYPE,
     NAND1_DEV_NUM,
     NAND1_PAGE_SIZE,
     NAND1_BLOCK_COUNT,
     NAND1_PAGE_COUNT,
     NAND_SEC_BLOCK  (NAND1_PAGE_COUNT, NAND1_PAGE_SIZE),
     NAND_SEC_PAGE   (NAND1_PAGE_SIZE),
     NAND_ROW_CYCLES (NAND1_BLOCK_COUNT, NAND1_PAGE_COUNT),
     NAND_COL_CYCLES (NAND1_PAGE_SIZE),
     NAND1_SW_ECC
    },
  };
  #define NAND_INFO1      NAND_DevInfo1
  #define NAND_INFO1_SZ   (sizeof(NAND_DevInfo1) / sizeof(NAND_DevInfo1[0]))
#else
  #define NAND_INFO1      NULL
  #define NAND_INFO1_SZ   0
#endif

/*----------------------------------------------------------------------------
 *  Drive N0: NAND Flash device NAND0 configuration
 *---------------------------------------------------------------------------*/
#if (NAND0_ENABLE)
  #if (NAND0_CACHE_RELOC == 1)
    #define __AT_NAND0  __at(NAND0_CACHE_ADDR)
  #else
    #define __AT_NAND0
  #endif

  /* NAND Cache Buffer for FAT, Page and Block Caching */
  #define NAND0_CSZ   ((NAND0_CACHE_SIZE  + 1) * 1024             + \
                       (NAND0_PAGE_CACHE  + 2) * NAND0_PAGE_SIZE  + \
                       (NAND0_BLOCK_CACHE + 2) * NAND0_PAGE_COUNT)
  #define NAND0_FSJBUF (NAND0_FAT_JOURNAL      * 512)

  static uint32_t     nand0_cache[NAND0_CSZ/4 + NAND0_FSJBUF/4] __AT_NAND0;
  static PAGE_CACHE   nand0_capg [NAND0_PAGE_CACHE  + 1];
  static BLOCK_CACHE  nand0_cabl [NAND0_BLOCK_CACHE + 2];
  static uint32_t     nand0_ttsn [NAND_TSN_SIZE(NAND0_BLOCK_COUNT, NAND0_PAGE_SIZE)];

  /* NAND Flash Configuration */
  static NAND_FTL_CFG nand0_cfg = {
    /* Block Translation Table Space */
    1,
    NAND_BTT_SIZE (NAND0_BLOCK_COUNT),

    /* Data Space */
    NAND_BTT_SIZE (NAND0_BLOCK_COUNT) + 1,
    NAND0_BLOCK_COUNT - 1,

    /* Caching */
    NAND0_BLOCK_CACHE + 2,
    NAND0_PAGE_CACHE  + 1,
    NAND_TSN_SIZE(NAND0_BLOCK_COUNT, NAND0_PAGE_SIZE),

    /* Page buffer & Caches */
    (uint8_t *)&nand0_cache[(NAND0_CACHE_SIZE+1)*256],
    &nand0_cabl[0],
    (uint8_t *)&nand0_cache[(NAND0_CACHE_SIZE+1)*256+(NAND0_PAGE_CACHE+2)*NAND0_PAGE_SIZE/4],
    &nand0_capg[0],
    (uint8_t *)&nand0_cache[(NAND0_CACHE_SIZE+1)*256+NAND0_PAGE_SIZE/4],
    &nand0_ttsn[0]
  };

  /* NAND0 wrapper functions */
  static uint32_t nand0_Init (uint32_t mode) {
    return (ftl_Init (mode, &nand0_dev, NAND_INFO0, NAND_INFO0_SZ));
  }
  static uint32_t nand0_UnInit (uint32_t mode) {
    return (ftl_UnInit (mode, &nand0_dev));
  }
  static uint32_t nand0_RdSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    uint32_t retv = ftl_ReadSect (sect, buf, cnt, &nand0_dev);
    if (retv < 2) return (true);
    else          return (false);
  }
  static uint32_t nand0_WrSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    uint32_t retv = ftl_WriteSect (sect, buf, cnt, &nand0_dev);
    if (retv < 2) return (true);
    else          return (false);
  }
  static uint32_t nand0_RdInfo (fsMediaInfo *info) {
    return (ftl_ReadInfo (info, &nand0_dev));
  }
  static fsStatus nand0_DevCtrl (fsDevCtrlCode code, void *p) {
    return (ftl_DevCtrl (code, p, &nand0_dev));
  }

  FAT_DRV nand0_drv = {
    nand0_Init,
    nand0_UnInit,
    nand0_RdSect,
    nand0_WrSect,
    nand0_RdInfo,
    nand0_DevCtrl
  };
#endif

/*----------------------------------------------------------------------------
 *  Drive N1: NAND Flash device NAND1 configuration
 *---------------------------------------------------------------------------*/
#if (NAND1_ENABLE)
  #if (NAND1_CACHE_RELOC == 1)
    #define __AT_NAND1  __at(NAND1_CACHE_ADDR)
  #else
    #define __AT_NAND1
  #endif

  /* NAND Cache Buffer for FAT, Page and Block Caching */
  #define NAND1_CSZ   ((NAND1_CACHE_SIZE  + 1) * 1024             + \
                       (NAND1_PAGE_CACHE  + 2) * NAND1_PAGE_SIZE  + \
                       (NAND1_BLOCK_CACHE + 2) * NAND1_PAGE_COUNT)
  #define NAND1_FSJBUF (NAND1_FAT_JOURNAL      * 512)
 
  static uint32_t     nand1_cache[NAND1_CSZ/4 + NAND1_FSJBUF/4] __AT_NAND1;
  static PAGE_CACHE   nand1_capg [NAND1_PAGE_CACHE  + 1];
  static BLOCK_CACHE  nand1_cabl [NAND1_BLOCK_CACHE + 2];
  static uint32_t     nand1_ttsn [NAND_TSN_SIZE(NAND1_BLOCK_COUNT, NAND1_PAGE_SIZE)];

  /* NAND Flash Configuration */
  static NAND_FTL_CFG nand1_cfg = {
    /* Block Translation Table Space */
    1,
    NAND_BTT_SIZE (NAND1_BLOCK_COUNT),

    /* Data Space */
    NAND_BTT_SIZE (NAND1_BLOCK_COUNT) + 1,
    NAND1_BLOCK_COUNT - 1,

    /* Caching */
    NAND1_BLOCK_CACHE + 2,
    NAND1_PAGE_CACHE  + 1,
    NAND_TSN_SIZE(NAND1_BLOCK_COUNT, NAND1_PAGE_SIZE),

    /* Page buffer & Caches */
    (uint8_t *)&nand1_cache[(NAND1_CACHE_SIZE+1)*256],
    &nand1_cabl[0],
    (uint8_t *)&nand1_cache[(NAND1_CACHE_SIZE+1)*256+(NAND1_PAGE_CACHE+2)*NAND1_PAGE_SIZE/4],
    &nand1_capg[0],
    (uint8_t *)&nand1_cache[(NAND1_CACHE_SIZE+1)*256+NAND1_PAGE_SIZE/4],
    &nand1_ttsn[0],
  };

  /* NAND1 wrapper functions */
  static uint32_t nand1_Init (uint32_t mode) {
    return (ftl_Init(mode, &nand1_dev, NAND_INFO1, NAND_INFO1_SZ));
  }
  static uint32_t nand1_UnInit (uint32_t mode) {
    return (ftl_UnInit (mode, &nand1_dev));
  }
  static uint32_t nand1_RdSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    uint32_t retv = ftl_ReadSect (sect, buf, cnt, &nand1_dev);
    if (retv < 2) return (true);
    else          return (false);
  }
  static uint32_t nand1_WrSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    uint32_t retv = ftl_WriteSect (sect, buf, cnt, &nand1_dev);
    if (retv < 2) return (true);
    else          return (false);
  }
  static uint32_t nand1_RdInfo (fsMediaInfo *info) {
    return (ftl_ReadInfo (info, &nand1_dev));
  }
  static fsStatus nand1_DevCtrl (fsDevCtrlCode code, void *p) {
    return (ftl_DevCtrl (code, p, &nand1_dev));
  }

  FAT_DRV nand1_drv = {
    nand1_Init,
    nand1_UnInit,
    nand1_RdSect,
    nand1_WrSect,
    nand1_RdInfo,
    nand1_DevCtrl
  };
#endif

/*----------------------------------------------------------------------------
 *  Drive R0: RAM device RAM0 configuration
 *---------------------------------------------------------------------------*/
#if (RAM0_ENABLE)
  static fsFAT_Volume ram0_vol;

  #if (RAM0_SIZE < 0x4A00)
    #error "::File System:Drive:RAM requires minimum of 0x4A00 bytes of memory"
  #endif

  #if (RAM0_RELOC == 1)
    #define __AT_RAM0  __at(RAM0_BASE_ADDR)
  #else
    #define __AT_RAM0
  #endif

  /* RAM0 Device data buffer */
  static uint32_t ram0_buf[256 + (RAM0_SIZE/4)] __AT_RAM0;

  /* RAM0 device info */
  static RAM_DEV  ram0_dev = {
    (uint8_t *)&ram0_buf[256],
    RAM0_SIZE
  };

  /* RAM0 wrapper functions */
  static uint32_t ram0_Init (uint32_t mode) {
    return (ram_Init (mode, &ram0_dev));
  }
  static uint32_t ram0_UnInit (uint32_t mode) {
    return (ram_UnInit (mode, &ram0_dev));
  }
  static uint32_t ram0_RdSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    return (ram_ReadSector (sect, buf, cnt, &ram0_dev));
  }
  static uint32_t ram0_WrSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    return (ram_WriteSector (sect, buf, cnt, &ram0_dev));
  }
  static uint32_t ram0_RdInfo (fsMediaInfo *info) {
    return (ram_ReadInfo (info, &ram0_dev));
  }
  static fsStatus ram0_DevCtrl (fsDevCtrlCode code, void *p) {
    return (ram_DevCtrl (code, p, &ram0_dev));
  }

  /* FAT RAM Driver Control Block */
  FAT_DRV ram0_drv = {
    ram0_Init,
    ram0_UnInit,
    ram0_RdSect,
    ram0_WrSect,
    ram0_RdInfo,
    ram0_DevCtrl
  };
#endif

/*----------------------------------------------------------------------------
 *  Drive U0: USB Flash device USB0 configuration
 *---------------------------------------------------------------------------*/
#if (USB0_ENABLE)
  extern FAT_DRV usb0_drv;

  #if (USB0_FAT_JOURNAL)
  static FSJOUR usb0_fsj;
  #endif

  /* USB Cache Buffer for Data and FAT Caching */
  static uint32_t usb0_cache[(USB0_CACHE_SIZE+1) * 256 + USB0_FAT_JOURNAL * 128];
  static fsFAT_Volume usb0_vol;

  /* USB0 wrapper functions */
  static uint32_t usb0_Init (uint32_t mode) {
    return (FS_USBH_MSC_Initialize      (0, mode));
  }
  static uint32_t usb0_UnInit (uint32_t mode) {
    return (FS_USBH_MSC_Uninitialize    (0, mode));
  }
  static uint32_t usb0_RdSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    return (FS_USBH_MSC_ReadSectors     (0, sect, cnt, buf));
  }
  static uint32_t usb0_WrSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    return (FS_USBH_MSC_WriteSectors    (0, sect, cnt, buf));
  }
  static uint32_t usb0_RdInfo (fsMediaInfo *info) {
    return (FS_USBH_MSC_ReadInfo        (0, info));
  }
  static fsStatus usb0_DevCtrl (fsDevCtrlCode code, void *p) {
    return (FS_USBH_MSC_DeviceCtrl      (0, code, p));
  }

  FAT_DRV usb0_drv = {
    usb0_Init,
    usb0_UnInit,
    usb0_RdSect,
    usb0_WrSect,
    usb0_RdInfo,
    usb0_DevCtrl
  };
#endif

/*----------------------------------------------------------------------------
 *  Drive U1: USB Flash device USB1 configuration
 *---------------------------------------------------------------------------*/
#if (USB1_ENABLE)
  extern FAT_DRV usb1_drv;

  #if (USB1_FAT_JOURNAL)
  static FSJOUR usb1_fsj;
  #endif

  /* USB Cache Buffer for Data and FAT Caching */
  static uint32_t usb1_cache[(USB1_CACHE_SIZE+1) * 256 + USB1_FAT_JOURNAL * 128];
  static fsFAT_Volume usb1_vol;

  /* USB1 wrapper functions */
  static uint32_t usb1_Init (uint32_t mode) {
    return (FS_USBH_MSC_Initialize      (1, mode));
  }
  static uint32_t usb1_UnInit (uint32_t mode) {
    return (FS_USBH_MSC_Uninitialize    (1, mode));
  }
  static uint32_t usb1_RdSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    return (FS_USBH_MSC_ReadSectors     (1, sect, cnt, buf));
  }
  static uint32_t usb1_WrSect (uint32_t sect, uint8_t *buf, uint32_t cnt) {
    return (FS_USBH_MSC_WriteSectors    (1, sect, cnt, buf));
  }
  static uint32_t usb1_RdInfo (fsMediaInfo *info) {
    return (FS_USBH_MSC_ReadInfo        (1, info));
  }
  static fsStatus usb1_DevCtrl (fsDevCtrlCode code, void *p) {
    return (FS_USBH_MSC_DeviceCtrl      (1, code, p));
  }

  FAT_DRV usb1_drv = {
    usb1_Init,
    usb1_UnInit,
    usb1_RdSect,
    usb1_WrSect,
    usb1_RdInfo,
    usb1_DevCtrl
  };
#endif


/*-----------------------------------------------------------------------------
 *  An array of installed Device drivers
 *----------------------------------------------------------------------------*/
FS_DEV fs_DevPool[FS_NDRV] = {
#if (NOR0_ENABLE)
  { &nor0_vol, "F0", FS_EMB | NOR0_DEFAULT_DRIVE },
#endif
#if (NOR1_ENABLE)
  { &nor1_vol, "F1", FS_EMB | NOR1_DEFAULT_DRIVE },
#endif
#if (MC0_ENABLE)
  { &mc0_vol,  "M0", FS_FAT | MC0_DEFAULT_DRIVE  | FS_IOC },
#endif
#if (MC1_ENABLE)
  { &mc1_vol,  "M1", FS_FAT | MC1_DEFAULT_DRIVE  | FS_IOC },
#endif
#if (NAND0_ENABLE)
  { &nand0_vol,"N0", FS_FAT | NAND0_DEFAULT_DRIVE | FS_IOC },
#endif
#if (NAND1_ENABLE)
  { &nand1_vol,"N1", FS_FAT | NAND1_DEFAULT_DRIVE | FS_IOC },
#endif
#if (RAM0_ENABLE)
  { &ram0_vol, "R0", FS_FAT | RAM0_DEFAULT_DRIVE },
#endif
#if (USB0_ENABLE)
  { &usb0_vol, "U0", FS_FAT | USB0_DEFAULT_DRIVE },
#endif
#if (USB1_ENABLE)
  { &usb1_vol, "U1", FS_FAT | USB1_DEFAULT_DRIVE },
#endif
};

/*-----------------------------------------------------------------------------
 *  Configure Flash File System
 *----------------------------------------------------------------------------*/
void fs_config (void) {

#if (NOR0_ENABLE)
  nor0_vol.Drv     = &CREATE_SYMBOL (Driver_NOR_, NOR0_NAME);
  nor0_vol.BaseAdr = NOR0_BASE_ADDR;
  nor0_vol.InitVal = CREATE_SYMBOL (NOR_Device_, NOR0_NAME).erased_value * 0x01010101;
  nor0_vol.NumSect = CREATE_SYMBOL (NOR_Device_, NOR0_NAME).sector_count;
  nor0_vol.Size    = CREATE_SYMBOL (NOR_Device_, NOR0_NAME).size;
  nor0_vol.DevCfg  = CREATE_SYMBOL (NOR_Device_, NOR0_NAME).sector_info;
#endif

#if (NOR1_ENABLE)
  nor1_vol.Drv     = &CREATE_SYMBOL (Driver_NOR_, NOR1_NAME);
  nor1_vol.BaseAdr = NOR1_BASE_ADDR;
  nor1_vol.InitVal = CREATE_SYMBOL (NOR_Device_, NOR1_NAME).erased_value * 0x01010101;
  nor1_vol.NumSect = CREATE_SYMBOL (NOR_Device_, NOR1_NAME).sector_count;
  nor1_vol.Size    = CREATE_SYMBOL (NOR_Device_, NOR1_NAME).size;
  nor1_vol.DevCfg  = CREATE_SYMBOL (NOR_Device_, NOR1_NAME).sector_info;
#endif

#if (MC0_ENABLE)
  mc0_vol.Drv           = &mc0_drv;
  mc0_vol.CaBuf         = mc0_cache;
  mc0_vol.CaSize        = MC0_CACHE_SIZE * 2;

  /* Register MCI driver for Native mode */
  mc0_dev.DrvMci        = &CREATE_SYMBOL (Driver_MCI, MC0_MCI_DRIVER);
  mc0_dev.MCI_Callback  = MC0_MCI_SignalEvent;
 #if (MC0_SPI != 0)
  /* Register SPI driver for SPI mode */
  mc0_dev.DrvSpi        = &CREATE_SYMBOL (Driver_SPI, MC0_SPI_DRIVER);
  mc0_dev.SPI_Callback  = MC0_SPI_SignalEvent;
 #endif

 #if (MC0_FAT_JOURNAL)
  /* Register file system journal */
  mc0_fsj.buf           = (uint8_t *)&mc0_cache[(MC0_CACHE_SIZE+1) * 256];
  mc0_vol.fsj           = &mc0_fsj;
  mc0_vol.RsvdS         = FAT_SECT_RSVD;
 #else
  mc0_vol.fsj           = NULL;
  mc0_vol.RsvdS         = 0;
 #endif
#endif  

#if (MC1_ENABLE)
  mc1_vol.Drv           = &mc1_drv;
  mc1_vol.CaBuf         = mc1_cache;
  mc1_vol.CaSize        = MC1_CACHE_SIZE * 2;

 /* Register MCI driver for Native mode */
  mc1_dev.DrvMci        = &CREATE_SYMBOL (Driver_MCI, MC1_MCI_DRIVER);
  mc1_dev.MCI_Callback  = MC1_MCI_SignalEvent;
 #if (MC1_SPI != 0)
  /* Register SPI driver for SPI mode */
  mc1_dev.DrvSpi        = &CREATE_SYMBOL (Driver_SPI, MC1_SPI_DRIVER);
  mc1_dev.SPI_Callback  = MC1_SPI_SignalEvent;
 #endif

 #if (MC1_FAT_JOURNAL)
  /* Register file system journal */
  mc1_fsj.buf           = (uint8_t *)&mc1_cache[(MC1_CACHE_SIZE+1) * 256];
  mc1_vol.fsj           = &mc1_fsj;
  mc1_vol.RsvdS         = FAT_SECT_RSVD;
 #else
  mc1_vol.fsj           = NULL;
  mc1_vol.RsvdS         = 0;
 #endif
#endif  

#if (NAND0_ENABLE)
  nand0_vol.Drv       = &nand0_drv;
  nand0_vol.CaBuf     = nand0_cache;
  nand0_vol.CaSize    = NAND0_CACHE_SIZE * 2;

  nand0_dev.Drv       = &CREATE_SYMBOL (Driver_NAND, NAND0_DRIVER);
  nand0_dev.Dev       = &NAND_DevInfo0[0];
  nand0_dev.Cfg       = &nand0_cfg;
  nand0_dev.Callback  = NAND0_EVENT_HANDLER;

 #if (NAND0_FAT_JOURNAL)
  /* Register file system journal */
  nand0_fsj.buf       = (uint8_t *)&nand0_cache[NAND0_CSZ/4];
  nand0_vol.fsj       = &nand0_fsj;
  nand0_vol.RsvdS     = FAT_SECT_RSVD;
 #else
  nand0_vol.fsj       = NULL;
  nand0_vol.RsvdS     = 0;
 #endif
#endif

#if (NAND1_ENABLE)
  nand1_vol.Drv       = &nand1_drv;
  nand1_vol.CaBuf     = nand1_cache;
  nand1_vol.CaSize    = NAND1_CACHE_SIZE * 2;

  nand1_dev.Drv       = &CREATE_SYMBOL (Driver_NAND, NAND1_DRIVER);
  #if defined(NAND_INFO_0_DEV_1)
  nand1_dev.Dev       = &NAND_DevInfo0[1];
  #else
  nand1_dev.Dev       = &NAND_DevInfo1[0];
  #endif
  nand1_dev.Cfg       = &nand1_cfg;
  nand1_dev.Callback  = NAND1_EVENT_HANDLER;

 #if (NAND1_FAT_JOURNAL)
  /* Register file system journal */
  nand1_fsj.buf       = (uint8_t *)&nand1_cache[NAND1_CSZ/4];
  nand1_vol.fsj       = &nand1_fsj;
  nand1_vol.RsvdS     = FAT_SECT_RSVD;
 #else
  nand1_vol.fsj       = NULL;
  nand1_vol.RsvdS     = 0;
 #endif
#endif

#if (RAM0_ENABLE)
  ram0_vol.Drv      = &ram0_drv;
  ram0_vol.CaBuf    = ram0_buf;
  ram0_vol.CaSize   = 0;
  ram0_vol.RsvdS    = 0;
  ram0_vol.fsj      = NULL;
#endif

#if (USB0_ENABLE)
  usb0_vol.Drv      = &usb0_drv;
  usb0_vol.CaBuf    = usb0_cache;
  usb0_vol.CaSize   = USB0_CACHE_SIZE * 2;

 #if (USB0_FAT_JOURNAL)
  /* Register file system journal */
  usb0_fsj.buf      = (uint8_t *)&usb0_cache[(USB0_CACHE_SIZE+1) * 256];
  usb0_vol.fsj      = &usb0_fsj;
  usb0_vol.RsvdS    = FAT_SECT_RSVD;
 #else
  usb0_vol.fsj      = NULL;
  usb0_vol.RsvdS    = 0;
 #endif
#endif  

#if (USB1_ENABLE)
  usb1_vol.Drv      = &usb1_drv;
  usb1_vol.CaSize   = USB1_CACHE_SIZE * 2;
  usb1_vol.CaBuf    = usb1_cache;
  

 #if (USB1_FAT_JOURNAL)
  /* Register file system journal */
  usb1_fsj.buf      = (uint8_t *)&usb1_cache[(USB1_CACHE_SIZE+1) * 256];
  usb1_vol.fsj      = &usb1_fsj;
  usb1_vol.RsvdS    = FAT_SECT_RSVD;
 #else
  usb1_vol.fsj      = NULL;
  usb1_vol.RsvdS    = 0;
 #endif
#endif

  STREAM_LIST_LOCK;
}


#if (EFS_USE == 0)
 /* Empty functions to reduce image size when EFS not used */
 bool     efs_path_valid (const char *path)                            { return (false); }
 int32_t  efs_handle_get (fsEFS_Volume *vol)                           { return (-1); }
 fsStatus efs_open  (int32_t handle, const char *fn, int openmode)     { return (fsError); }
 fsStatus efs_close (int32_t handle)                                   { return (fsError); }
 int32_t  efs_read  (int32_t handle,       uint8_t *buf, uint32_t len) { return (0);  }
 int32_t  efs_write (int32_t handle, const uint8_t *buf, uint32_t len) { return (-1); }
 fsStatus efs_flush (int32_t handle)                                   { return (fsError); }
 int32_t  efs_flen  (int32_t handle)                                   { return (-1); }
 fsStatus efs_seek  (int32_t handle, uint32_t pos)                     { return (fsError); }
 fsStatus efs_ffind (int32_t handle, fsFileInfo *info)                 { return (fsError); }
 fsStatus efs_find  (int32_t handle, const char *fname)                { return (fsError); }
 fsStatus efs_delete(int32_t handle)                                   { return (fsError); }
 int32_t  efs_analyse(fsEFS_Volume *vol) { return (0); }
 fsStatus efs_check  (fsEFS_Volume *vol) { return (fsError); }
 fsStatus efs_format (fsEFS_Volume *vol) { return (fsError); }
 uint32_t efs_free   (fsEFS_Volume *vol) { return (0); }
 fsStatus efs_defrag (fsEFS_Volume *vol) { return (fsError); }
#endif /* EFS_USE */

#if (FAT_USE == 0)
 /* Empty functions to reduce image size when FAT not used */
 int32_t  fat_handle_get (fsFAT_Volume *vol) { return (-1); }
 fsStatus fat_open (int32_t handle, const char *path, int32_t openmode){ return (fsError); }
 fsStatus fat_close(int32_t handle)                                    { return (fsError); }
 int32_t  fat_read (int32_t handle, uint8_t *buf, uint32_t len)        { return(-1);      }
 int32_t  fat_write(int32_t handle, const uint8_t *buf, uint32_t len)  { return(-1);      }
 int32_t  fat_flen (int32_t handle)                                    { return (-1); }
 fsStatus fat_seek (int32_t handle, uint32_t pos)                      { return(fsError); } 
 int32_t  fat_init (fsFAT_Volume *vol)                                 { return (0);      }
 fsStatus fat_ffind  (const char *fn, fsFileInfo *info, fsFAT_Volume *vol) { return (fsError); }
 fsStatus fat_delete (const char *fn, fsFAT_Volume *vol)               { return(fsError); }
 fsStatus fat_rename (const char *path, const char *newname, fsFAT_Volume *vol) { return (fsError); }
 fsStatus fat_format (fsFAT_Volume *vol, const char *opt)              { return (fsError); }
 uint64_t fat_free   (fsFAT_Volume *vol)                               { return (0); }
 fsStatus fat_attrib (fsFAT_Volume *vol, const char *fn, uint32_t attrib) { return (fsError); }
 fsStatus fat_read_label  (fsFAT_Volume *vol, char *buf)               { return (fsError); }
 fsStatus fat_read_serial (fsFAT_Volume *vol, uint32_t *serial)        { return (fsError); }
 fsStatus fat_mkdir (const char *path, fsFAT_Volume *vol)              { return (fsError); }
 uint32_t fat_jour_init (fsFAT_Volume *vi)                             { return (true);  }
#else
 #if (FSJ_USE == 0)
  /* Empty functions to reduce image size when journal not used */
  uint32_t fat_jour_init (fsFAT_Volume *vol)           { return (true);  }
  uint32_t fat_jour_prep (fsFAT_Volume *vol)           { return (true);  }
  uint32_t fsj_set_space (FSJOUR *fsj, uint32_t start_sect, uint32_t cnt) {
                                                        return (false); }
  uint32_t fsj_write     (FSJOUR *fsj, uint32_t sect, uint32_t cnt, uint8_t *buf) {
                                                        return (false); }
  uint32_t fsj_init      (FSJOUR *fsj, FAT_DRV *drv)  { return (false); }
 #endif
#endif /* FAT_USE */

#if (FAT_NAME_CACHE_SIZE == 0)
  uint32_t   elink_init      (void)                              { return (1);    }
  uint32_t   elink_init_path (const char *drvLet)                { return (0xFF); }
  uint32_t   elink_flush     (const char *drvLet)                { return (1);    }
  uint32_t   elink_cmd       (uint32_t i, uint32_t j)            { return (0);    }
  uint32_t   elink_insert    (void *p, uint32_t i, uint32_t j)   { return (1);    }
  uint32_t   elink_delete    (void *p, uint32_t i)               { return (0);    }
  uint32_t   elink_scan      (uint32_t i, void **pp, uint32_t j) { return (1);    }
#endif


/*-----------------------------------------------------------------------------
 *  Retarget low level functions
 *----------------------------------------------------------------------------*/

#pragma import(__use_no_semihosting_swi)

#ifndef STDIO_DISABLE

/* Standard IO device handles. */
#define STDIN   0x8001
#define STDOUT  0x8002
#define STDERR  0x8003

/* Standard IO device name defines. */
const char __stdin_name[]  = "STDIN";
const char __stdout_name[] = "STDOUT";
const char __stderr_name[] = "STDERR";

#if (__TARGET_ARCH_7_M || __TARGET_ARCH_7E_M)
/* Redirected to ITM by default */
extern int stdio_getc (void);
extern int stdio_putc (int ch);
#else
/* Dummy implementation */
__weak int stdio_getc (void)   { return (-1); }
__weak int stdio_putc (int ch) {}
#endif

#endif


/**
  Defined in rt_sys.h, this function writes a character to the console. The
  console might have been redirected. You can use this function as a last
  resort error handling routine.
  
  The default implementation of this function uses semihosting.
  You can redefine this function, or __raise(), even if there is no other
  input/output. For example, it might write an error message to a log kept
  in nonvolatile memory.

  \param[in] ch character to write
*/
__weak void _ttywrch (int ch) {
#ifndef STDIO_DISABLE
#ifndef STDOUT_LF_CR_DISABLE
  if (ch == '\n') stdio_putc ('\r');
#endif
  stdio_putc (ch);
#endif
}


/**
  Defined in rt_sys.h, this function opens a file.

  The _sys_open() function is required by fopen() and freopen(). These
  functions in turn are required if any file input/output function is to
  be used.
  The openmode parameter is a bitmap whose bits mostly correspond directly to
  the ISO mode specification. Target-dependent extensions are possible, but
  freopen() must also be extended.

  \param[in] name     File name
  \param[in] openmode Mode specification bitmap

  \return    The return value is –1 if an error occurs.
*/
FILEHANDLE _sys_open (const char *name, int openmode) {
  /* Register standard Input Output devices. */
#ifndef STDIO_DISABLE
  if (strcmp(name, "STDIN") == 0) {
    return (STDIN);
  }
  if (strcmp(name, "STDOUT") == 0) {
    return (STDOUT);
  }
  if (strcmp(name, "STDERR") == 0) {
    return (STDERR);
  }
#endif
  return (__sys_open (name, openmode));
}


/**
  Defined in rt_sys.h, this function closes a file previously opened
  with _sys_open().
  
  This function must be defined if any input/output function is to be used.

  \param[in] fh File handle

  \return    The return value is 0 if successful. A nonzero value indicates
             an error.
*/
int _sys_close (FILEHANDLE fh) {
#ifndef STDIO_DISABLE
  switch (fh) {
    case STDOUT:
    case STDIN:
    case STDERR:
      return (0);
  }
#endif
  return (__sys_close (fh));
}


/**
  Defined in rt_sys.h, this function writes the contents of a buffer to a file
  previously opened with _sys_open().

  \note The mode parameter is here for historical reasons. It contains
        nothing useful and must be ignored.

  \param[in] fh   File handle
  \param[in] buf  Data buffer
  \param[in] len  Data length
  \param[in] mode Ignore this parameter

  \return    The return value is either:
             - a positive number representing the number of characters not
               written (so any nonzero return value denotes a failure of
               some sort)
             - a negative number indicating an error.
*/
int _sys_write (FILEHANDLE fh, const uint8_t *buf, uint32_t len, int mode) {
#ifndef STDIO_DISABLE
  int ch;

  switch (fh) {
    case STDOUT:
      /* Standard Output device. */
      for (  ; len; len--) {
        ch = *buf++;
#ifndef STDOUT_LF_CR_DISABLE
        if (ch == '\n') stdio_putc ('\r');
#endif
        stdio_putc (ch);
      }
      return (0);
    case STDIN:
    case STDERR:
      return (-1);
  }
#endif
  return (__sys_write (fh, buf, len));
}


/**
  Defined in rt_sys.h, this function reads the contents of a file into a buffer.

  Reading up to and including the last byte of data does not turn on the EOF
  indicator. The EOF indicator is only reached when an attempt is made to read
  beyond the last byte of data. The target-independent code is capable of
  handling:
    - the EOF indicator being returned in the same read as the remaining bytes
      of data that precede the EOF
    - the EOF indicator being returned on its own after the remaining bytes of
      data have been returned in a previous read.

  \note The mode parameter is here for historical reasons. It contains
        nothing useful and must be ignored.

  \param[in] fh   File handle
  \param[in] buf  Data buffer
  \param[in] len  Data length
  \param[in] mode Ignore this parameter

  \return     The return value is one of the following:
              - The number of bytes not read (that is, len - result number of
                bytes were read).
              - An error indication.
              - An EOF indicator. The EOF indication involves the setting of
                0x80000000 in the normal result.
*/
int _sys_read (FILEHANDLE fh, uint8_t *buf, uint32_t len, int mode) {
#ifndef STDIO_DISABLE
  int ch;

  switch (fh) {
    case STDIN:
      /* Standard Input device. */
      do {
        ch = stdio_getc ();
      } while (ch < 0);
      *buf++ = (uint8_t)ch;
      len--;            
      for (  ; len; len--) {
        ch = stdio_getc ();
        if (ch < 0) break;
        *buf++ = (uint8_t)ch;
      }
      return (len);
    case STDOUT:
    case STDERR:
      return (-1);
  }
#endif
  return (__sys_read (fh, buf, len));
}


/**
  Defined in rt_sys.h, this function determines if a file handle identifies
  a terminal.

  When a file is connected to a terminal device, this function is used to
  provide unbuffered behavior by default (in the absence of a call to
  set(v)buf) and to prohibit seeking.

  \param[in] fh File handle

  \return    The return value is one of the following values:
             - 0:     There is no interactive device.
             - 1:     There is an interactive device.
             - other: An error occurred.
*/
int _sys_istty (FILEHANDLE fh) {
#ifndef STDIO_DISABLE
  switch (fh) {
    case STDOUT:
    case STDIN:
    case STDERR:
      return (1);
  }
#endif
  return (0);
}


/**
  Defined in rt_sys.h, this function puts the file pointer at offset pos from
  the beginning of the file.

  This function sets the current read or write position to the new location pos
  relative to the start of the current file fh.

  \param[in] fh  File handle
  \param[in] pos File pointer offset

  \return    The result is:
             - non-negative if no error occurs
             - negative if an error occurs
*/
int _sys_seek (FILEHANDLE fh, long pos) {
#ifndef STDIO_DISABLE
  switch (fh) {
    case STDOUT:
    case STDIN:
    case STDERR:
      return (-1);
  }
#endif
  return (__sys_seek (fh, pos));
}


/**
  This function is deprecated. It is never called by any other library function,
  and you are not required to re-implement it if you are retargeting standard
  I/O (stdio).
*/
int _sys_ensure (FILEHANDLE fh) {
#ifndef STDIO_DISABLE
  switch (fh) {
    case STDOUT:
    case STDIN:
    case STDERR:
      return (-1);
  }
#endif
  return (__sys_ensure (fh));
}


/**
  Defined in rt_sys.h, this function returns the current length of a file.

  This function is used by _sys_seek() to convert an offset relative to the
  end of a file into an offset relative to the beginning of the file.
  You do not have to define _sys_flen() if you do not intend to use fseek().
  If you retarget at system _sys_*() level, you must supply _sys_flen(),
  even if the underlying system directly supports seeking relative to the
  end of a file.

  \param[in] fh File handle

  \return    This function returns the current length of the file fh,
             or a negative error indicator.
*/
long _sys_flen (FILEHANDLE fh) {
#ifndef STDIO_DISABLE
  switch (fh) {
    case STDOUT:
    case STDIN:
    case STDERR:
      return (0);
  }
#endif
  return (__sys_flen (fh));
}


/**
  Defined in rt_sys.h, this is the library exit function. All exits from the
  library eventually call _sys_exit().

  This function must not return. You can intercept application exit at a
  higher level by either:
    - Implementing the C library function exit() as part of your application.
      You lose atexit() processing and library shutdown if you do this.
    - Implementing the function __rt_exit(int n) as part of your application.
      You lose library shutdown if you do this, but atexit() processing is
      still performed when exit() is called or main() returns.

  \param[in] return_code Library return code
  \return    The return code is advisory. An implementation might attempt to
             pass it to the execution environment.
*/
__weak void _sys_exit (int return_code) {
  /* Endless loop. */
  while (1);
}

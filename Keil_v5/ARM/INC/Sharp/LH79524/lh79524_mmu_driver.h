/***********************************************************************
 * $Id:: lh79524_mmu_driver.h 27 2007-08-31 19:35:06Z kevinw           $
 *
 * Project: LH79524 MMU driver
 *
 * Description:
 *     This file contains driver support for the MMU module on the
 *     LH79524
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

#ifndef LH79524_MMU_DRIVER_H
#define LH79524_MMU_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh79524_mmu.h"

/***********************************************************************
 * MMU device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

///* MMU device commands (IOCTL commands) */
typedef enum {
    MMU_SET_ENABLE,     /* Enable MMU, arg = 1, enable MMU, arg = 0 disable
                            MMU */
    MMU_SET_CACHE_ON,   /* Turn on cache, arg = 1, turn on global cache.
                            arg = 0, turn off global cache. */
    MMU_SET_WRITE_BUFFER_ON,    /* Turn on write buffer. arg = 1, turn on
                            global write buffer. arg = 0, turn off global 
                            write buffer */
    MMU_INVALIDATE_CACHE,       /* Invalidate the cache. Do cache 
                            refreshment, no arg */
    MMU_FLUSH_TLB,      /* Flush the TLB register. Used each time there is
                            a translation table change */
    MMU_SET_TTB_ADDR,   /* Set MMU translation table address. arg = 
                            translation table physical starting address */
    MMU_MAP_VIRT_PHY,   /* Map virtual address to physical address. arg =
                            virtual address, return physical address */
    MMU_MAP_PHY_VIRT,   /* Map physical address to virtual address. arg =
                            physical address, return virtual address */
    MMU_GET_STATUS      /* Get a MMU status, use an argument type of
                       MMU_IOCTL_STS_T as the argument to return the
                       correct status */
} MMU_IOCTL_CMD_T;

/* MMU device arguments for MMU_GET_STATUS command (IOCTL arguments) */
typedef enum {
    MMU_GET_ENABLE, /* Returns MMU enable status (TRUE = enabled, 
                       FALSE = disabled */
    MMU_GET_CACHE_ON, /* Returns Cache on status (TRUE = turned on, 
                       FALSE = turned off */
    MMU_GET_WRITE_BUFFER_ON /* Returns Write Buffer on status (TRUE
                        = turned on. FALSE = turned off) */
} MMU_IOCTL_STS_T;

/***********************************************************************
 * MMU device configuration structure
 **********************************************************************/

/* MMU device configuration structure */
typedef struct
{
    INT_32 init;       /* Device initialized flag */
} MMU_CFG_T;

/***********************************************************************
 * MMU driver functions
 **********************************************************************/
/* Open the MMU */
INT_32 mmu_open(void *ipbase, INT_32 arg);

/* Close the MMU */
STATUS mmu_close(INT_32 devid);

/* Watchdog timer configuration block */
STATUS mmu_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* MMU read function (stub only) */
INT_32 mmu_read(INT_32 devid,
                void *buffer,
                INT_32 max_bytes);

/* MMU write function (stub only) */
INT_32 mmu_write(INT_32 devid,
                 void *buffer,
                 INT_32 n_bytes);

/*  Given a virtual address, return the corresponding
*  physical address */
UNS_32 mmu_map_virtual_to_physical(UNS_32 addr);
/*  Given a physical address, return the first corresponding
*  virtual address */
void * mmu_map_physical_to_virtual(UNS_32 addr);
                 
#ifdef __cplusplus
}
#endif

#endif /* LH79524_MMU_DRIVER_H */

/***********************************************************************
 * $Id:: lh79524_int_driver.h 27 2007-08-31 19:35:06Z kevinw           $
 *
 * Project: LH79524 INT driver
 *
 * Description:
 *     This file contains driver support for the INT module on the
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

#ifndef LH79524_INT_DRIVER_H
#define LH79524_INT_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh79524_vic.h"

/***********************************************************************
 * INT device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* INT device commands (IOCTL commands) */
typedef enum {
    FIQ_GLOBAL_ENABLE,      /* Enable global FIQ interrupt, arg = 1 
                            enable FIQ globally, arg = 0 disable FIQ */
    FIQ_ENABLE_SOURCE,      /* Enable specific VIC source as FIQ and enable
                            this source. arg = VIC source */
    FIQ_DISABLE_SOURCE,     /* Disable specific VIC source to generate
                            FIQ interrupt. arg = VIC source */
    FIQ_SET_HANDLER,        /* Set FIQ interruption handling routine. 
                            arg = handler routine addr */
    FIQ_REMOVE_HANDLER,     /* Remove FIQ handler routine. Set FIQ handling
                            routine as default. no arg */
    FIQ_GET_STATUS,         /* Get a int status, use an argument type of
                            INT_IOCTL_STS_T as the argument to return the
                            correct status */
                       
                       
    IRQ_GLOBAL_ENABLE,      /* Enable global IRQ interrupt, arg = 1 
                            enable IRQ globally, arg = 0 disable IRQ */
    IRQ_ENABLE_SOURCE,      /* Enable specific VIC source as IRQ and enable
                            this source. arg = VIC source */
    IRQ_DISABLE_SOURCE,     /* Disable specific VIC source to generate
                            IRQ interrupt. arg = VIC source */
    IRQ_SET_CURRENT_SOURCE, /* Set the VIC source for the operation - 
                            IRQ_SET_PRIORITY and IRQ_SET_HANDLER. arg =
                            VIC source */
    IRQ_SET_PRIORITY,       /* Set IRQ priority of the current VIC source.
                            arg = priority from 0 to 15 */
    IRQ_SET_HANDLER,        /* Set IRQ interruption handling routine for 
                            current VIC source. arg = handler routine addr */
    IRQ_REMOVE_HANDLER,     /* Remove IRQ handler for specific VIC source. 
                            Remove this source from VIC controller. arg =
                            VIC source */
    IRQ_GET_STATUS,         /* Get a int status, use an argument type of
                            INT_IOCTL_STS_T as the argument to return the
                            correct status */
                       
                       
    SWI_ENABLE_SOURCE,      /* Enable specific VIC source as SWI and enable
                            this source. arg = VIC source */
    SWI_DISABLE_SOURCE,     /* Disable specific VIC source to generate
                            SWI interrupt. arg = VIC source */
    SWI_SET_HANDLER,        /* Set SWI interruption handling routine. 
                            arg = handler routine addr */
    SWI_REMOVE_HANDLER,     /* Remove SWI handler routine. Set SWI handling
                            routine as default. no arg */
    SWI_GET_STATUS          /* Get a int status, use an argument type of
                            INT_IOCTL_STS_T as the argument to return the
                            correct status */
                       
} INT_IOCTL_CMD_T;

/* INT device arguments for INT_GET_STATUS command (IOCTL arguments) */
typedef enum {
    IRQ_GET_ENABLE,         /* Returns IRQ enable status (status = all 32
                            source IRQ enable status) */
    IRQ_GET_PENDING,        /* Returns pending IRQ status (status = all 32
                            source, bits indicating which source IRQ
                            pending */
    IRQ_GET_RAW,            /* Returns raw IRQ status (status = all 32 source
                            bits indicating which source raw IRQ happended */
    IRQ_GET_HANDLER,        /* Returns IRQ handling routine address. 
                            IRQ_SET_CURRENT_SOURCE must be called before this */
                            
    FIQ_GET_ENABLE,         /* Returns FIQ enable status (status = all 32
                            source FIQ enable status) */
    FIQ_GET_PENDING,        /* Returns pending FIQ status (status = all 32
                            source, bits indicating which source FIQ
                            pending */
    FIQ_GET_RAW,            /* Returns raw FIQ status (status = all 32 source
                            bits indicating which source raw FIQ happended */
    FIQ_GET_HANDLER,        /* Returns FIQ handling routine address */
                            
    SWI_GET_ENABLE,         /* Returns SWI enable status (status = all 32
                            source SWI enable status) */
    SWI_GET_PENDING,        /* Returns pending SWI status (status = all 32
                            source, bits indicating which source SWI
                            pending */
    SWI_GET_HANDLER         /* Returns SWI handling routine address */
                            
                            
} INT_IOCTL_STS_T;

/***********************************************************************
 * INT device configuration structure
 **********************************************************************/

/* INT device configuration structure */
typedef struct
{
    INT_32 init;       /* Device initialized flag */
} INT_CFG_T;

/***********************************************************************
 * INT driver functions
 **********************************************************************/
/* Open the IRQ interrupt */
INT_32 irq_open(void *ipbase, INT_32 arg);

/* Open the FIQ interrupt */
INT_32 fiq_open(void *ipbase, INT_32 arg);

/* Open the SWI interrupt */
INT_32 swi_open(void *ipbase, INT_32 arg);

/* Close the IRQ interrupt */
STATUS irq_close(INT_32 devid);

/* Close the FIQ interrupt */
STATUS fiq_close(INT_32 devid);

/* Close the SWI interrupt */
STATUS swi_close(INT_32 devid);

/* IRQ configuration block */
STATUS irq_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* FIQ configuration block */
STATUS fiq_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* SWI configuration block */
STATUS swi_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* INT read function (stub only) */
INT_32 int_read(INT_32 devid,
                void *buffer,
                INT_32 max_bytes);

/* INT write function (stub only) */
INT_32 int_write(INT_32 devid,
                 void *buffer,
                 INT_32 n_bytes);

#ifdef __cplusplus
}
#endif

#endif /* LH79524_INT_DRIVER_H */

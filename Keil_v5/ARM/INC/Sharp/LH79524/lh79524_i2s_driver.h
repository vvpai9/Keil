/***********************************************************************
 * $Id:: lh79524_i2s_driver.h 27 2007-08-31 19:35:06Z kevinw           $
 *
 * Project: LH79524 i2s driver
 *
 * Description:
 *     This file contains driver support for the i2s module on the
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

#ifndef LH79524_I2S_DRIVER_H
#define LH79524_I2S_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lpc_types.h"
#include "lh79524_I2S.h"


/***********************************************************************
 * i2s device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* i2s device commands (IOCTL commands) */
typedef enum {
    I2S_ENABLE_LOCK,    			/* Enable i2s converter */
    I2S_ENABLE_LOOPBACK,  			/* Enable loop back mode for SSP converter */
    I2S_INVERT_WS,  				/* Invert WS status bit */
    I2S_WS_DELAY_APPLY,   			/* WS delay applied */
    I2S_MASTER_CLK_INVERT,    		/* Master clock invert */
    I2S_RECEIVE_OVERRUN_INT_MASK,   /* Receive overrun int mask */
    I2S_RECEIVE_TIMEOUT_INT_MASK,   /* Receive timeout int mask */
    I2S_RECEIVE_FIFO_INT_MASK,     	/* Receive receive fifo int mask */
    I2S_TRANSMIT_FIFO_INT_MASK,   	/* transmit fifo int mask */
    I2S_TRANSMIT_UNDERRUN_INT_MASK, /* transmit underrun int mask */
    I2S_CODEC_ERROR_INT_MASK,  		/* external codec protocol error int mask */
    I2S_SSP_PROTOCOL_ERROR_INT_MASK,/* ssp protocol error int mask */
    I2S_CLEAR_INT_TX_UNDERRUN,  	/* clear transmit underrun interrupt */
    I2S_CLEAR_INT_CODEC_ERR,   		/* clear external codec protocol error interrupt */
    I2S_CLEAR_INT_SSP_PROTOCOL_ERR, /* clear ssp protocol error interrupt */
    I2S_GET_STATUS         /* Get i2s status, use an argument type of
                            I2S_IOCTL_STS_T as the argument to return the
                            correct status */
} I2S_IOCTL_CMD_T;
                
                
/* i2s device arguments for i2s_GET_STATUS command (IOCTL arguments) */
typedef enum {
    I2S_GET_STATUS_REG,  		/* Get the I2S status register value */
    I2S_GET_RAW_INT_REG,       	/* Get the I2S raw interrupt status register value */
    I2S_GET_MASKED_INT_REG      /* Get the I2S masked interrupt status register value */
    
} I2S_IOCTL_STS_T;
                    
    
/***********************************************************************
 * i2s device configuration structure
 **********************************************************************/

/* i2s device configuration structure */
typedef struct
{
    INT_32 init;       /* Device initialized flag */
    I2S_REGS_T *regptr; /* Pointer to i2s registers */
} I2S_CFG_T;

/***********************************************************************
 * i2s driver functions
 **********************************************************************/
/* Open the watchdog timer */
INT_32 i2s_open(void *ipbase, INT_32 arg);

/* Close the watchdog timer */
STATUS i2s_close(INT_32 devid);

/* Watchdog timer configuration block */
STATUS i2s_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* i2s read function (stub only) */
INT_32 i2s_read(INT_32 devid,
                void *buffer,
                INT_32 max_bytes);

/* i2s write function (stub only) */
INT_32 i2s_write(INT_32 devid,
                 void *buffer,
                 INT_32 n_bytes);

#ifdef __cplusplus
}
#endif

#endif /* LH79524_I2S_DRIVER_H */

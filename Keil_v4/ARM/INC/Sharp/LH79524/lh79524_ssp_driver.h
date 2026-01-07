/***********************************************************************
 * $Id:: lh79524_ssp_driver.h 27 2007-08-31 19:35:06Z kevinw           $
 *
 * Project: LH79524 SSP driver
 *
 * Description:
 *     This file contains driver support for the SSP module on the
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

#ifndef LH79524_SSP_DRIVER_H
#define LH79524_SSP_DRIVER_H

/* define clock divider and prescaler maxima and minima */
#define RCPC_SSP_PRESCALE_MAX 256
#define SSP_PRESCALE_MAX 254
#define SSP_PRESCALE_MIN 2
#define SSP_DIVIDER_MAX 256
#define MAX_SSP_FREQ (hclk_freq / SSP_PRESCALE_MIN)
#define SSP_MAX_TIMEOUT 0xffff

/* type for SSP frame format - Motorola, TI, National */
typedef enum
{
    SSP_MODE_NATIONAL,
    SSP_MODE_TI,            
    SSP_MODE_MOTOROLA   
}SSP_FRAME_T;

/* type for SSP operation enable or disable - int, loopback
SSP enable */
typedef enum
{
    SSP_OPERATION,
    SSP_LOOPBACK_MODE,
    SSP_RECEIVE_FIFO_OVERRUN_INT,
    SSP_RECEIVE_TIMEOUT_INT,
    SSP_TRANSMIT_FIFO_INT,
    SSP_RECEIVE_FIFO_INT
}SSP_OPERATION_T;

/* type for SSPFRM pin mode - auto: controled by SSP, high
: GPIO high, low : GPIO low */
typedef enum
{
    SSPFRM_AUTO,
    SSPFRM_HIGH,
    SSPFRM_LOW
}SSPFRM_PIN_T;

#ifdef __cplusplus
extern "C" {
#endif

#include "lh79524_ssp.h"

/***********************************************************************
 * SSP device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* SSP device commands (IOCTL commands) */
typedef enum {
    SSP_ENABLE, /* Enable SSP operation and init the SSP controller.
	        	arg = 1, enable SSP. arg = 0 disable SSP */
    SSP_SET_SLAVE, /* Set SSP operation in slave or master mode
	        	arg = 1, slave mode. arg = 0 master mode */
	SSP_SET_FRAME_FORMAT,	/* Set SSP in either National or TI or 
					Motorola mode. arg =
				*	SSP_MODE_NATIONAL	: National microwire format
				*	SSP_MODE_TI			: TI synchronous serial data 
										  frame format
				*	SSP_MODE_MOTOROLA	: Motorola SPI data format
				*/
	SSP_SET_DATA_SIZE,	/* Set SSP frame data size, size is 
				valid from 4 to 16 	arg = data size */
	SSP_SET_SPEED,	/* Set the SSP receive timeout in microseconds */
	        	/* arg = requested bits per second */
	SSP_SET_SSPFRM_PIN,	/*  configure the SSPFRM pin to be high, low, 
				or auto during ssp operation. arg =
				*  	SSPFRM_AUTO	: set up the pin muxing so that the SSP 
				*				controls the SSPFRM pin
				*	SSPFRM_HIGH	: set SSPFRM pin as GPIO and 
									set it as high
				*	SSPFRM_LOW	: set SSPFRM pin as GPIO and 
									set it as low
				*/
	SSP_SET_SCLK_POLARITY,	/* invert the sclk signal polarity, only 
				effective in Motorola mode. arg = 1, invert polarity, 
				arg = 0,   	normal polarity */
	SSP_SET_SCLK_PHASE,   	/* invert the sclk signal phase, only 
				effective in Motorola mode. arg = 1, invert phrase, 
				arg = 0, normal phrase */
	SSP_TX_WORD,   	/* transmit one word using polling mode. arg = 
				word to be transfered */
	SSP_RX_WORD,   	/* SSP receive one word using polling mode. 
				no arg */
    SSP_TX_RX_WORD,	/* SSP transceive one word using polling mode. arg =
	        	word to be trasmitted. Returns the word received. */
	SSP_LOOP_BACK_ENABLE,  	/* Enable SSP loop back mode. arg = 1, 
				enable. arg = 0,	disable */
	SSP_INT_ENABLE,    	/* Enable SSP interruption generation, arg =
				*	SSP_RECEIVE_FIFO_OVERRUN_INT	: enable receive 
					fifo overrun int
				*	SSP_TRANSMIT_FIFO_INT	: enable transmit fifo 
					interruption
				*	SSP_RECEIVE_FIFO_INT	: enable receive fifo 
					interruption
	        	*/
    SSP_INT_DISABLE,   	/* Disable SSP interruption generation, arg = 
				*	SSP_RECEIVE_FIFO_OVERRUN_INT	: enable receive 
					fifo overrun int
				*	SSP_TRANSMIT_FIFO_INT	: enable transmit 
					fifo interruption
				*	SSP_RECEIVE_FIFO_INT	: enable receive fifo 
					interruption
	        	*/
	SSP_INT_CLEAR,    	/* only ssp receive fifo overrun interrupt 
				can be cleared,	no arg */
	SSP_DMA_TX_INIT,   	/* Set up initial value for SSP transmit 
				using DMA, no arg */
	SSP_DMA_RX_INIT,   	/* Set up initial value for SSP receive 
				using DMA, no arg */
	SSP_DMA_TX_RX_INIT,	/* Set up initial value for SSP transceive 
				using DMA, no arg */
	SSP_DMA_SET_SOURCE,	/* Set up source address for SSP using DMA, 
				arg = source addr */
	SSP_DMA_SET_DEST,  	/* Set up destination address for SSP using DMA, 
	        	arg = destination addr */
	SSP_DMA_SET_COUNT, 	/* Set up number of words for SSP operation 
				using DMA, 	arg = number of words */
	SSP_DMA_SET_RX_TIME_OUT,	/*  Set the SSP DMA receive timeout 
				to the closest time	in microseconds that the 
				hardware allows. arg = time	in microsecond */
	SSP_DMA_TX_INT_HANDLER,    	/* Default transmit interrupt handler 
				to be called by
	        	SSP DMA transfer interrupt routine, no arg */
	SSP_DMA_TXRX_INT_HANDLER,  	/* Default receive and transceive 
				interrupt handler to be called by	SSP DMA transfer 
				interrupt routine, 	no arg */
    SSP_DMA_TX_START,	/* Start DMA transfer from memory to SSP, 
    			SSP_DMA_TX_INIT	must be called before this, no arg */
	SSP_DMA_RX_START,  	/* Start DMA transfer from SSP to memory, 
				SSP_DMA_RX_INIT	must be called before this, no arg */
	SSP_DMA_TX_RX_START,/*  Start DMA transfer from SSP to memory, 
				SSP_DMA_TX_RX_INIT must be called before this, no arg */
    SSP_GET_STATUS  /* Get a ssp status, use an argument type of
                       SSP_IOCTL_STS_T as the argument to return the
                       correct status */
} SSP_IOCTL_CMD_T;

/* SSP device arguments for SSP_GET_STATUS command (IOCTL arguments) */
typedef enum {
    SSP_GET_SPEED,	/* Returns the SSP speed in bits per second. */
	SSP_GET_INT_STATUS,	/* Returns SSP interrupt status 
						*	SSP_RECEIVE_FIFO_OVERRUN_INT	
						*	SSP_TRANSMIT_FIFO_INT	
						*	SSP_RECEIVE_FIFO_INT	
	        			*/
    SSP_GET_BUSY,	/* Returns 1 if SSP is busy, 0 for not busy */
    SSP_GET_RX_FIFO_FULL,	/* Returns 1 if SSP receive fifo is full, 
                    	0 for not full */
    SSP_GET_RX_FIFO_NOT_EMPTY,	/* Returns 1 if SSP receive fifo 
    					is not empty, 0 for empty */
    SSP_GET_TX_FIFO_NOT_FULL,  	/* Returns 1 if SSP transmit fifo 
    					is not full, 0 for full */
    SSP_GET_TX_FIFO_EMPTY,    	/* Returns 1 if SSP transmit fifo 
    					is empty, 0 for not empty */
    SSP_GET_DMA_RX_TIME_OUT   	/* Returns the time out value for 
    					DMA ssp transfer in microseconds */
    
} SSP_IOCTL_STS_T;


/***********************************************************************
 * SSP device configuration structure
 **********************************************************************/

/* SSP device configuration structure */
typedef struct
{
    INT_32 init;       /* Device initialized flag */
    SSP_REGS_T *regptr; /* Pointer to SSP registers */
} SSP_CFG_T;

/***********************************************************************
 * SSP driver functions
 **********************************************************************/
/* Open the ssp */
INT_32 ssp_open(void *ipbase, INT_32 arg);

/* Close the ssp */
STATUS ssp_close(INT_32 devid);

/* ssp configuration block */
STATUS ssp_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* SSP read function (stub only) */
INT_32 ssp_read(INT_32 devid,
                void *buffer,
                INT_32 max_bytes);

/* SSP write function (stub only) */
INT_32 ssp_write(INT_32 devid,
                 void *buffer,
                 INT_32 n_bytes);

#ifdef __cplusplus
}
#endif

#endif /* LH79524_SSP_DRIVER_H */

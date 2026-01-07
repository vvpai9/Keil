/*********************************************************************** 
 * $Id:: lh79524_uart_driver.h 27 2007-08-31 19:35:06Z kevinw          $
 * 
 * Project: LH79524 chip definitions
 * 
 * Description: 
 *      This file contains the function and data declarations for the 
 *      LH79524 UART 0, 1 and 2 driver. 
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

#ifndef LH79524_UART_DRIVER_H
#define LH79524_UART_DRIVER_H

#include "lh79524_uart.h"

#if defined __cplusplus
#if __cplusplus
extern "C"
{
#endif /* __cplusplus */
#endif /* __cplusplus */


/* Size of the ring buffer */
#define RING_SIZE              (512)

/*
 * Ring buffer structure 
 */
typedef struct RING_S
{
  /* Buffer size */
  UNS_32 size;    
  /* Buffer data count */
  UNS_32 count;   
  /* Input position - write */
  UNS_32 in_pos;  
  /* Output posyion - read */
  UNS_32 out_pos; 
  /* Pointer to data buffer */
  CHAR*  data;    
} RING_T, *PRING_T;

/* Init a ring buffer */
#define RING_INIT(ring, nbytes) \
{ \
((RING_T*)ring)->size = (nbytes); \
((RING_T*)ring)->count = 0; \
((RING_T*)ring)->in_pos = 0; \
((RING_T*)ring)->out_pos = 0; \
}

/* Drain and reset a ring buffer */
#define RING_FLUSH(ring) \
{ \
((RING_T*)ring)->count = 0; \
((RING_T*)ring)->in_pos = 0; \
((RING_T*)ring)->out_pos = 0; \
}

/* Return the current buffer count */
#define RING_COUNT(ring) ((RING_T*)ring)->count

/* Put a byte into the buffer */
#define RING_PUTC(ring, rdata) \
{ \
((RING_T*)ring)->count++; \
((RING_T*)ring)->data[((RING_T*)ring)->in_pos++] = (rdata); \
if (((RING_T*)ring)->in_pos >= ((RING_T*)ring)->size) \
{ \
    ((RING_T*)ring)->in_pos = 0; \
} \
}

/* Get a byte from the buffer */
#define RING_GETC(ring, rdata) \
{ \
((RING_T*)ring)->count--; \
if (((RING_T*)ring)->out_pos >= ((RING_T*)ring)->size) \
{ \
    ((RING_T*)ring)->out_pos = 0; \
} \
(rdata) = ((RING_T*)ring)->data[((RING_T*)ring)->out_pos++]; \
} 

/* Serial driver config params */
typedef struct UART_CFG_S
{
/* Baud rate setting of the uart */
  INT_32  baud_rate;
/* Frame configuration (8-N-1) */
  INT_32  options;
/* Depth of the rx data fifo */
  INT_32  rx_fifo_depth;
/* Depth of the tx data fifo */
  INT_32  tx_fifo_depth;
/* */
  INT_32  uart2_ssm;
/* */
  INT_32  uart2_swm;
/* */
  UNS_8   actrl0;
/* */
  UNS_8   actrl1;
/* */
  INT_32  ulan_mode;
/* micro-lan mode flag (82510 only) */
  BOOL_16 ulan_flag;
/* External XTAL clock rate  */
  UNS_32  sys_clk;
/* Polling mode state */
  BOOL_32 poll_mode;
/* */
  int parity;
/* */
  int stop_bits;
/* */
  int data_bits;
} UART_CFG_T, *PUART_CFG_T;

/* Serial driver control structure */
typedef struct SERIAL_S
{
/* Base address of the uart - Note: do not change location 
   of this structure member */ 
  void*   regs;       
/* Default irq handler */
  void*   irq_hdlr;              
/* Rx dma channel */     
  void*   rx_dma;                   
/* Tx dma channel */
  void*   tx_dma;                   
/* Initialization status */
  BOOL_32 init;                     
/* Interrupt handler table  */
  PFV     isr[10];                  
/* Interrupt mask being used */
  UNS_32  imask;                    
/* Interrupt vector being used */
  UNS_32  ivec;
/* Default rx data ring buffer id */                  
  RING_T  rx_id;                    
/* Default rx error ring buffer id */       
  RING_T  rx_err_id;                
/* Default tx data ring buffer id */                 
  RING_T  tx_id;                    
/* Default rx data buffer */           
  UNS_8   rx_data[RING_SIZE];       
/* Default rx errors buffer */
  UNS_8   rx_err_data[RING_SIZE];   
/* Default tx data buffer */
  UNS_8   tx_data[RING_SIZE];       
/* OS hooks */
  INT_32  sem_id;
/* Semaphore take method */
  PFI     sem_take;
/* Semaphore take method args */
  void*   sem_take_arg;
/* Semaphore release method */
  PFI     sem_give;
/* Semaphore give method args */
  void*   sem_give_arg;
/* Critical section enter */
  PFI     enter_critical;
/* Critical section exit */
  PFI     exit_critical;
/* External ring buffer id */
  INT_32  ring_id;
/* External ring buffer put method */
  PFI     ring_putc;
/* External ring buffer get char method */
  PFI     ring_getc;
/* External ring buffer init method */
  PFI     ring_init;
/* External ring buffer reset method */
  PFI     ring_flush;
/* Device configuration parameters */    
  UART_CFG_T cfg;                      
} SERIAL_T, *PSERIAL_T;

/* Serial driver device id's */
typedef enum
{
/* Uart0 id */
  DEV_UART0 = 0,
/* Uart1 id */ 
  DEV_UART1,
/* Uart2 id */
  DEV_UART2
} UART_ID_T;

/* Serial driver data bit settings */
typedef enum
{
/* Charachter is 5 data bits */
  UART_DATA_BITS_5 = 0,
/* Charachter is 6 data bits */
  UART_DATA_BITS_6,
/* Charachter is 7 data bits */
  UART_DATA_BITS_7,
/* Charachter is 8 data bits */
  UART_DATA_BITS_8,
/* Charachter is 9 data bits */
  UART_DATA_BITS_9
} UART_DATA_BITS_T;

/* Serial driver stop bit settings */
typedef enum
{
/* 3/4 stop bit */
  UART_STOP_BITS_3_4 = 0, 
/* 1 stop bit */
  UART_STOP_BITS_1,       
/* 1 1/4 stop bits */
  UART_STOP_BITS_1_1_4,   
/* 1 1/2 stop bits */
  UART_STOP_BITS_1_1_2,   
/* 1 3/4 stop bits */
  UART_STOP_BITS_1_3_4,   
/* 2 stop bits */
  UART_STOP_BITS_2        
} UART_STOP_BITS_T;

/* Serial driver parity bit settings */
typedef enum
{
/* No parity */
  UART_PARITY_NONE = 0, 
/* Odd parity */
  UART_PARITY_ODD,
/* Even parity */
  UART_PARITY_EVEN,
/* High parity */
  UART_PARITY_HIGH,
/* Low parity */
  UART_PARITY_LOW,
/* Software parity */
  UART_PARITY_SOFTWARE
} UART_PARITY_T;

/* Serial driver loopback settings */
typedef enum
{
/* no loopback, no echo */
  UART_NO_LOOPBACK = 0,   
/* local loopback */
  UART_LOCAL_LOOPBACK,    
/* no loopback, echo on */
  UART_ECHO,            
/* remote loopback */
  UART_REMOTE_LOOPBACK    
} UART_LOOPBACK_T;


/* Serial driver ioctl (IO control) commands */
typedef enum
{
/* Set baud rate */  
  UART_SET_BAUD_RATE = 0,
/* Get baud rate */
  UART_GET_BAUD_RATE,
/* Enable fifos */
  UART_ENABLE_FIFO,  
/* Disable fifos */
  UART_DISABLE_FIFO, 
/* Set tx fifo level */  
  UART_SET_TX_FIFO_LVL, 
/* Set tx fifo level */  
  UART_GET_TX_FIFO_LVL,
/* Set rx fifo level */  
  UART_SET_RX_FIFO_LVL,
/* Get rx fifo level */  
  UART_GET_RX_FIFO_LVL, 
/* Frame options set */  
  UART_SET_FRAME_OPTIONS,
/* Frame options get */  
  UART_GET_FRAME_OPTIONS, 
/* Mask interrupts at the source */ 
  UART_DISABLE_INT,     
/* Unmask interrupts at the source */ 
  UART_ENABLE_INT, 
/* Enable the uart */ 
  UART_START,          
/* Disable the uart */
  UART_STOP, 
/* Enable the uart receiver */ 
  UART_ENABLE_RX,          
/* Disable the uart reciever */
  UART_DISABLE_RX,   
/* Enable the uart tranmitter */ 
  UART_ENABLE_TX,          
/* Disable the uart tranmitter */
  UART_DISABLE_TX,         
/* Loopback mode enable */
  UART_ENABLE_LOOPBACK,       
/* Loopback mode disable */
  UART_DISABLE_LOOPBACK,     
/* Flush rx and tx fifo and ring buffers */
  UART_FLUSH,      
/* Return pointer to device isr */
  UART_GET_ISR,   
/* Enable interrupt driver mode */
  UART_SET_INT_MODE,
/* Enable polling mode */
  UART_SET_POLL_MODE,
/* Bind int lock mechanism */
  UART_SET_INT_LOCK,
/* Bind int unlock mechanism */
  UART_SET_INT_UNLOCK
} UART_IOCTLS_T;

/* Unix style API  */
extern INT_32 uart_open (INT_32 ipbase, INT_32 arg);
extern STATUS uart_close (INT_32 devid);
extern INT_32 uart_read (INT_32 devid, CHAR* buffer, INT_32 max_bytes);
extern INT_32 uart_write (INT_32 devid, CHAR* buffer, INT_32 n_bytes);
extern STATUS uart_ioctl (INT_32 devid, INT_32 cmd, INT_32 arg);


#if defined __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif  /* LH79524_UART_DRIVER_H */

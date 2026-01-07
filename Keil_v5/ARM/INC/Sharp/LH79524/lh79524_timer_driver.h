/***********************************************************************
 * $Id:: lh79524_timer_driver.h 27 2007-08-31 19:35:06Z kevinw         $
 *
 * Project: LH79524 timer driver
 *
 * Description:
 *     This file contains driver support for the timer modules on the
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

#ifndef LH79524_TIMERS_H
#define LH79524_TIMERS_H

#if defined __cplusplus
#if __cplusplus
extern "C"
{
#endif /* __cplusplus */
#endif /* __cplusplus */

#include "lh79524_chip.h"
#include "lh79524_timer.h"

/* Timer driver config params */
typedef struct TIMER_CFG_S
{
/* Current clock rate of timer */
  INT_32 clock_rate;
/* External xtal clock rate  */
  UNS_32 sys_clk;
/* Timer allocation state */
  INT_32 allocated;
} TIMER_CFG_T, *PTIMER_CFG_T;

/* Timer driver control structure */
typedef struct TIMERS_S
{
/* Base address of the device */ 
  void*   regs;       
/* Default irq handler */
  void*   irq_hdlr;              
/* Initialization status */
  BOOL_32 init;                     
/* Callback method to be used by isr */
  PFI     callback;                  
/* Interrupt mask being used */
  UNS_32  imask;                    
/* Interrupt vector being used */
  UNS_32  ivec;
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
/* Device configuration parameters */    
  TIMER_CFG_T cfg;                      
} TIMER_T, *PTIMER_T;

/* Timer clock settings */
typedef enum
{
/* System clock/2 */
  TIMER_HCLK_DIV_2 = 0, 
/* System clock/4 */
  TIMER_HCLK_DIV_4, 
/* System clock/8 */
  TIMER_HCLK_DIV_8, 
/* System clock/16 */
  TIMER_HCLK_DIV_16, 
/* System clock/32 */
  TIMER_HCLK_DIV_32, 
/* System clock/64 */
  TIMER_HCLK_DIV_64, 
/* System clock/128 */
  TIMER_HCLK_DIV_128, 
/* External clock */
  TIMER_CTCLK
} TIMER_CLK_T;

/* Timers driver ioctl (IO control) commands */
typedef enum
{
/* Start a timer */  
  TIMER_START = 0,
/* Stop a timer */
  TIMER_STOP,
/* Clear a counter */
  TIMER_CLEAR_CNT,
/* Set the clock rate */
  TIMER_SET_CLK_RATE,
/* Set the clock rate */
  TIMER_GET_CLK_RATE,
/* Enable PWM mode */
  TIMER_SET_PWM_MODE,
/* Enable Periodic mode */
  TIMER_SET_PERIODIC_MODE,
/* Enable free running counter mode */
  TIMER_SET_CNT_MODE,
/* Mask interrupts at the source */ 
  TIMER_DISABLE_INT,     
/* Unmask interrupts at the source */ 
  TIMER_ENABLE_INT, 
/* Return pointer to device isr */
  TIMER_GET_ISR,
/* Bind a callback method to be used by the timer isr */
  TIMER_SET_CALLBACK,
/* Set the timer status register */
  TIMER_SET_STATUS,
/* Get the timer status register */
  TIMER_GET_STATUS,
/* Set the timer count register */
  TIMER_SET_COUNT,
/* Set the timer count register */
  TIMER_GET_COUNT,
/* Set the timer cmp0 register */
  TIMER_SET_CMP0,
/* Get the timer cmp0 register */
  TIMER_GET_CMP0,
/* Set the timer cmp1 register */
  TIMER_SET_CMP1,
/* Get the timer cmp1 register */
  TIMER_GET_CMP1,
/* Set the timer cap0 register */
  TIMER_SET_CAP0,
/* Get the timer cap0 register */
  TIMER_GET_CAP0,
/* Set the timer cap1 register */
  TIMER_SET_CAP1,
/* Get the timer cap1 register */
  TIMER_GET_CAP1,
/* Timer 0 start ioctl */
  TIMER0_EXTENDED_IOCTL
} TIMER_IOCTLS_T;

/* Timer0 driver ioctl (IO control) commands */
typedef enum
{
/* Set the timer compare and capture control register */
  TIMER0_SET_CMP_CAP_CTRL = TIMER0_EXTENDED_IOCTL,
/* Get the timer compare and capture control register */
  TIMER0_GET_CMP_CAP_CTRL,
/* Set the timer capture2 register */
  TIMER0_SET_CAP2,
/* Get the timer capture2 register */
  TIMER0_GET_CAP2,
/* Set the timer capture3 register */
  TIMER0_SET_CAP3,
/* Get the timer capture3 register */
  TIMER0_GET_CAP3,
/* Set the timer capture4 register */
  TIMER0_SET_CAP4,
/* Get the timer capture4 register */
  TIMER0_GET_CAP4
} TIMER0_IOCTLS_T;


/* Unix style API  */
extern INT_32 timer0_open (INT_32 ipbase, INT_32 arg);
extern STATUS timer0_close (INT_32 devid);
extern INT_32 timer0_read (INT_32 devid, CHAR* buffer, INT_32 max_bytes);
extern INT_32 timer0_write (INT_32 devid, CHAR* buffer, INT_32 n_bytes);
extern STATUS timer0_ioctl (INT_32 devid, INT_32 cmd, INT_32 arg);

/* Unix style API  */
extern INT_32 timer_open (INT_32 ipbase, INT_32 arg);
extern STATUS timer_close (INT_32 devid);
extern INT_32 timer_read (INT_32 devid, CHAR* buffer, INT_32 max_bytes);
extern INT_32 timer_write (INT_32 devid, CHAR* buffer, INT_32 n_bytes);
extern STATUS timer_ioctl (INT_32 devid, INT_32 cmd, INT_32 arg);

/***********************************************************************
 * Other Timer driver functions
 **********************************************************************/

/* Delay for usec microSeconds */
extern void timer_wait_us(TIMER_REGS_T *timer, 
                          UNS_32 usec, 
                          UNS_32 xtal_in);

/* Delay for msec microSeconds */
extern void timer_wait_ms(TIMER_REGS_T *timer, 
                          UNS_32 msec, 
                          UNS_32 xtal_in);


#if defined __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif  /* LH79524_TIMERS_H */

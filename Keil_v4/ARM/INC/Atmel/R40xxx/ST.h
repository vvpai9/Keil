/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  ST.H:  Header file for System Timer                                */
/*                                                                     */
/***********************************************************************/

#ifndef __ST_H
#define __ST_H


/*--------------*/
/* ST Registers */
/*--------------*/
#define ST_CR      REG(ST_BASE + 0x00) /* Control Register */
#define ST_PIMR    REG(ST_BASE + 0x04) /* Period Interval Mode Register */
#define ST_WDMR    REG(ST_BASE + 0x08) /* Watchdog Mode Register */
#define ST_RTMR    REG(ST_BASE + 0x0C) /* Real Time Mode Register */
#define ST_SR      REG(ST_BASE + 0x10) /* Status Register */
#define ST_IER     REG(ST_BASE + 0x14) /* Interrupt Enable Register */
#define ST_IDR     REG(ST_BASE + 0x18) /* Interrupt Disable Register */
#define ST_IMR     REG(ST_BASE + 0x1C) /* Interrupt Mask Register */
#define ST_RTAR    REG(ST_BASE + 0x20) /* Real Time Alarm Register */
#define ST_CRTR    REG(ST_BASE + 0x24) /* Current Real Time Register */


/*-------------------------*/
/* ST_CR: Control Register */
/*-------------------------*/
#define ST_WDRST           (1<<0)      /* Watchdog Timer Restart */

/*---------------------------------*/
/* ST_WDMR: Watchdog Mode Register */
/*---------------------------------*/
#define ST_RSTEN           (1<<16)     /* WatchDog Overflow Reset Enable */
#define ST_EXTEN           (1<<17)     /* External Signal Assertion Enable */

/*------------------------------------*/
/* ST_SR:  Status Register            */
/* ST_IER: Interrupt Enable  Register */
/* ST_IDR: Interrupt Disable Register */
/* ST_IMR: Interrupt Mask    Register */
/*------------------------------------*/
#define ST_PITS            (1<<0)      /* Period Interval Timer Status */
#define ST_WDOVF           (1<<1)      /* Watchdog Overflow Status */
#define ST_RTTINC          (1<<2)      /* Real Time Timer Increment */
#define ST_ALMS            (1<<3)      /* Alarm Status */


#endif /* __ST_H */

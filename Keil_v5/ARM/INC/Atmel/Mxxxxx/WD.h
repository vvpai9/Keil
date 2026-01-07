/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  WD.H:  Header file for Watchdog Timer                              */
/*                                                                     */
/***********************************************************************/

#ifndef __WD_H
#define __WD_H


/*--------------*/
/* WD Registers */
/*--------------*/
#define WD_OMR     REG(WD_BASE + 0x00) /* Overflow Mode Register */
#define WD_CMR     REG(WD_BASE + 0x04) /* Clock Mode Register */
#define WD_CR      REG(WD_BASE + 0x08) /* Control Register */
#define WD_SR      REG(WD_BASE + 0x0C) /* Status Register */


/*---------------------------------*/
/*  WD_OMR: Overflow Mode Register */
/*---------------------------------*/
#define WD_WDEN            (1<<0)      /* Watch Dog Enable */
#define WD_RSTEN           (1<<1)      /* Internal Reset Enable */
#define WD_IRQEN           (1<<2)      /* Interrupt Enable */
#define WD_EXTEN           (1<<3)      /* External Signal Enable */
#define WD_OKEY            (0x234<<4)  /* Overflow Mode Register Access Key */

/*-----------------------------*/
/* WD_CMR: Clock Mode Register */
/*-----------------------------*/

#define WD_WDCLKS          (3<<0)      /* Clock Selection */
#define WD_WDCLKS_MCK8     (0<<0)
#define WD_WDCLKS_MCK32    (1<<0)
#define WD_WDCLKS_MCK128   (2<<0)
#define WD_WDCLKS_MCK1024  (3<<0)

#define WD_HPCV            (0x0F<<2)   /* High Preload Counter Value */

#define WD_CKEY            (0x06E<<7)  /* Clock Register Access Key */

/*-------------------------*/
/* WD_CR: Control Register */
/*-------------------------*/
#define WD_RSTKEY          0xC071      /* Watch Dog Restart Key */

/*------------------------*/
/* WD_SR: Status Register */
/*------------------------*/

#define WD_WDOVF           (1<<0)      /* WatchDog Overflow Status */


#endif /* __WD_H */

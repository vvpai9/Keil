/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  RTC.H:  Header file for Real Time Clock                            */
/*                                                                     */
/***********************************************************************/

#ifndef __RTC_H
#define __RTC_H


/*---------------*/
/* RTC Registers */
/*---------------*/
#define RTC_MR     REG(RTC_BASE + 0x00)    /* Mode Register */
#define RTC_HMR    REG(RTC_BASE + 0x04)    /* Hour Mode Register */
#define RTC_TIMR   REG(RTC_BASE + 0x08)    /* Time Register */
#define RTC_CALR   REG(RTC_BASE + 0x0C)    /* Calendar Register */
#define RTC_TAR    REG(RTC_BASE + 0x10)    /* Time Alarm Register */
#define RTC_CAR    REG(RTC_BASE + 0x14)    /* Calendar Alarm Register */
#define RTC_SR     REG(RTC_BASE + 0x18)    /* Status Register */
#define RTC_SCR    REG(RTC_BASE + 0x1C)    /* Status Clear Register */
#define RTC_IER    REG(RTC_BASE + 0x20)    /* Interrupt Enable Register */
#define RTC_IDR    REG(RTC_BASE + 0x24)    /* Interrupt Disable Register */
#define RTC_IMR    REG(RTC_BASE + 0x28)    /* Interrupt Mask Register */
#define RTC_VER    REG(RTC_BASE + 0x2C)    /* Valid Entry Register */


/*-------------------------*/
/* RTC_MR: Mode Register   */
/*-------------------------*/
#define RTC_UPDTIM             (1<<0)      /* Update Request Time Register */
#define RTC_UPDCAL             (1<<1)      /* Update Request Calendar Register */

#define RTC_TEVSEL             (3<<8)      /* Time Event Selection */
#define RTC_TEVSEL_MN_CHG      (0<<8)      /* Minute change */
#define RTC_TEVSEL_HR_CHG      (1<<8)      /* Hour change */
#define RTC_TEVSEL_EVDAY_MD    (2<<8)      /* Every Day at Midnight */
#define RTC_TEVSEL_EVDAY_NOON  (3<<8)      /* Every Day at Noon */

#define RTC_CEVSEL             (3<<16)     /* Calendar Event Selection */
#define RTC_CEVSEL_WEEK_CHG    (0<<16)     /* Week Change */
#define RTC_CEVSEL_MONTH_CHG   (1<<16)     /* Month Change */
#define RTC_CEVSEL_YEAR_CHG    (2<<16)     /* Year Change */

/*-----------------------------*/
/* RTC_HMR: Hour Mode Register */
/*-----------------------------*/
#define RTC_24_HRMOD           (0<<0)      /* 24-Hour Mode */
#define RTC_12_HRMOD           (1<<0)      /* 12-Hour Mode */

/*-------------------------*/
/* RTC_TIMR: Time Register */
/*-------------------------*/
#define RTC_M_SEC              (0x7F<<0)   /* Second Mask */
#define RTC_B_SEC              0           /* Second Bit Shift */
#define RTC_M_MIN              (0x7F<<8)   /* Minute Mask */
#define RTC_B_MIN              8           /* Minute Bit Shift */
#define RTC_M_HOUR             (0x3F<<16)  /* Hour Mask */
#define RTC_B_HOUR             16          /* Hour Bit Shift */
#define RTC_AMPM               (1<<22)     /* AMPM Indicator */
#define RTC_AM                 (0<<22)     /* AM Indicator */
#define RTC_PM                 (1<<22)     /* PM Indicator */

/*-----------------------------*/
/* RTC_CALR: Calendar Register */
/*-----------------------------*/
#define RTC_M_CENT             (0x3F<<0)   /* Century Mask */
#define RTC_B_CENT             0           /* Century Bit Shift */
#define RTC_M_YEAR             (0xFF<<8)   /* Year Mask */
#define RTC_B_YEAR             8           /* Year Bit Shift */
#define RTC_M_MONTH            (0x1F<<16)  /* Month Mask */
#define RTC_B_MONTH            16          /* Month Bit Shift */
#define RTC_M_DAY              (0x07<<21)  /* Day Mask */
#define RTC_B_DAY              21          /* Day Bit Shift */
#define RTC_M_DATE             (0x3F<<24)  /* Date Mask */
#define RTC_B_DATE             24          /* Date Bit Shift */

/*------------------------------*/
/* RTC_TAR: Time Alarm Register */
/*------------------------------*/
#define RTC_SEC_ALRM_DIS       (0<<7)      /* Second Alarm Disable */
#define RTC_SEC_ALRM_EN        (1<<7)      /* Second Alarm Enable */
#define RTC_MIN_ALRM_DIS       (0<<15)     /* Minute Alarm Disable */
#define RTC_MIN_ALRM_EN        (1<<15)     /* Minute Alarm Enable */
#define RTC_HOUR_ALRM_DIS      (0<<23)     /* Hour Alarm Disable */
#define RTC_HOUR_ALRM_EN       (1<<23)     /* Hour Alarm Enable */

/*----------------------------------*/
/* RTC_CAR: Calendar Alarm Register */
/*----------------------------------*/
#define RTC_MONTH_ALRM_DIS     (0<<23)     /* Month Alarm Disable */
#define RTC_MONTH_ALRM_EN      (1<<23)     /* Month Alarm Enable */
#define RTC_DATE_ALRM_DIS      (0<<31)     /* Date Alarm Disable */
#define RTC_DATE_ALRM_EN       (1<<31)     /* Date Alarm Enable */

/*-------------------------------------*/
/* RTC_SR:  Status Register            */
/* RTC_SCR: Status Clear Register      */
/* RTC_IER: Interrupt Enable Register  */
/* RTC_IDR: Interrupt Disable Register */
/* RTC_IMR: Interrupt Mask Register    */
/*-------------------------------------*/
#define RTC_ACKUPD             (1<<0)      /* Acknowledge for Update */
#define RTC_ALARM              (1<<1)      /* Alarm Flag */
#define RTC_SEC                (1<<2)      /* Second Event */
#define RTC_TIMEV              (1<<3)      /* Time Event */
#define RTC_CALEV              (1<<4)      /* Calendar Event */

/*-------------------------------*/
/* RTC_VER: Valid Entry Register */
/*-------------------------------*/
#define RTC_NVT                (1<<0)      /* Non-Valid Time */
#define RTC_NVC                (1<<1)      /* Non-Valid Calendar */
#define RTC_NVTAL              (1<<2)      /* Non-Valid Time Alarm */
#define RTC_NVCAL              (1<<3)      /* Non-Valid Calendar Alarm */


#endif /* __RTC_H */

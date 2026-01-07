/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2005                           */
/***********************************************************************/
/*                                                                     */
/*  STR91x.h:   Header file for STMicroelectronics STR910 / STR912     */
/*                                                                     */
/***********************************************************************/

#ifndef __STR91X_H
#define __STR91X_H

#define SCU_BASE        (0x5C002000)
#define ADC_BASE        (0x5C00A000)
#define GPIO4_BASE      (0x5800A000)
#define GPIO8_BASE      (0x5800E000)
#define GPIO9_BASE      (0x5800F000)


#define SCU_PRR1        ((volatile unsigned long *)(SCU_BASE+0x020))
#define SCU_GPIOANA     ((volatile unsigned long *)(SCU_BASE+0x0BC))

#define SCU_GPIOOUT4    ((volatile unsigned long *)(SCU_BASE+0x054))
#define SCU_GPIOIN4     ((volatile unsigned long *)(SCU_BASE+0x074))
#define SCU_GPIOTYPE4   ((volatile unsigned long *)(SCU_BASE+0x094))
#define GPIO4_DIR       ((volatile unsigned char *)(GPIO4_BASE+0x400))
  
#define GPIO8_DIR       ((volatile unsigned char *)(GPIO8_BASE+0x400))
#define GPIO8_LCD_DATA  ((volatile unsigned char *)(GPIO8_BASE+0x3FC))

#define GPIO9_DIR       ((volatile unsigned char *)(GPIO9_BASE+0x400))
#define GPIO9_LED       ((volatile unsigned char *)(GPIO9_BASE+0x03C))
#define GPIO9_LCD_E1    ((volatile unsigned char *)(GPIO9_BASE+0x040))
#define GPIO9_LCD_E2    ((volatile unsigned char *)(GPIO9_BASE+0x080))
#define GPIO9_LCD_EN    ((volatile unsigned char *)(GPIO9_BASE+0x0C0))
#define GPIO9_LCD_RW    ((volatile unsigned char *)(GPIO9_BASE+0x100))
#define GPIO9_LCD_DI    ((volatile unsigned char *)(GPIO9_BASE+0x200))

#define ADC_CR          ((volatile unsigned long *)(ADC_BASE+0x000))
#define ADC_CCR         ((volatile unsigned long *)(ADC_BASE+0x004))
#define ADC_DR6         ((volatile unsigned long *)(ADC_BASE+0x02C))

#endif  // __STR91X_H

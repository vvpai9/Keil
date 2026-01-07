/*
 *****************************************************************************
 * Copyright @ 2007 by austriamicrosystems AG                                *
 * All rights are reserved.                                                  *
 *                                                                           *
 * Reproduction in whole or in part is prohibited without the written consent*
 * of the copyright owner. Austriamicrosystems reserves the right to make    *
 * changes without notice at any time. The software is provided as is and    *
 * Austriamicrosystems makes no warranty, expressed, implied or statutory,   *
 * including but not limited to any implied warranty of merchantability or   *
 * fitness for any particular purpose, or that the use will not infringe any *
 * third party patent, copyright or trademark. Austriamicrosystems should    *
 * not be liable for any loss or damage arising from its use.                *
 *****************************************************************************
 */

/*
 *      PROJECT:   AS353x
 *      $RCSfile:  $
 *      $Revision: $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author C. Eisendle
 *  \author M. Barjaktarevic (Substitute)
 *
 *  \brief  AS3658/AS3657 specific header file
 *
 */

#ifndef AFE_AS3658_H_
#define AFE_AS3658_H_


#if (AFE_CHIP_TYPE == AFE_AS3658)

#define    AFE_I2C_SLAVE_ADDR               (0x40)


#ifndef AFE_OSC_FREQ
#define    AFE_OSC_FREQ                     AFE_OSC_FREQ_12000KHZ
#endif /* AFE_OSC_FREQ */

#define    AFE_STEP_DOWN1                   (0x00)
#define    AFE_STEP_DOWN2                   (0x01)
#define    AFE_STEP_DOWN3                   (0x02)
#define    AFE_LDO_RF1                      (0x03)
#define    AFE_LDO_RF2                      (0x04)
#define    AFE_LDO_RF3                      (0x05)
#define    AFE_LDO_DIG1                     (0x06)
#define    AFE_LDO_DIG2                     (0x07)
#define    AFE_LDO_DIG3                     (0x08)
#define    AFE_LDO_DIG4                     (0x09)
#define    AFE_USB_CHARGER_CONTROL          (0x0A)
#define    AFE_CHARGER_CONTROL              (0x0B)
#define    AFE_BATTERY_MONITOR              (0x0C)
#define    AFE_CHARGER_CONFIG               (0x0D)
#define    AFE_CHARGER_SUPERVISION          (0x0E)
#define    AFE_FUEL_GAUGE                   (0x0F)
#define    AFE_CHARGER_CURRENT              (0x10)
#define    AFE_CP_CONTROL                   (0x11)
#define    AFE_GPIO1                        (0x12)
#define    AFE_GPIO2                        (0x13)
#define    AFE_GPIO3                        (0x14)
#define    AFE_GPIO4                        (0x15)
#define    AFE_RESET_TIMER                  (0x16)
#define    AFE_POWER1_CTRL                  (0x17)
#define    AFE_POWER1_CTRL_0MSEC            (0x18)
#define    AFE_POWER1_CTRL_1MSEC            (0x19)
#define    AFE_POWER1_CTRL_2MSEC            (0x1A)
#define    AFE_POWER1_CTRL_3MSEC            (0x1B)
#define    AFE_POWER1_CTRL_4MSEC            (0x1C)
#define    AFE_POWER1_CTRL_5MSEC            (0x1D)
#define    AFE_POWER2_CTRL                  (0x1E)
#define    AFE_GPIO_CONTROL                 (0x1F)
#define    AFE_STEP_UP_CONTROL              (0x20)
#define    AFE_STEP_UP1_CONTROL             (0x21)
#define    AFE_STEP_UP2_CONTROL             (0x22)
#define    AFE_STEP_DOWN1_CONTROL           (0x23)
#define    AFE_STEP_DOWN2_CONTROL           (0x24)
#define    AFE_STEP_DOWN_CHARGER_CONTROL    (0x25)
#define    AFE_BACKUP_BATTERY_CHARGER       (0x26)
#define    AFE_DCDC1_CURRENT                (0x27)
#define    AFE_DCDC2_CURRENT                (0x28)
#define    AFE_CURRENT1_CURRENT             (0x29)
#define    AFE_CURRENT2_CURRENT             (0x2A)
#define    AFE_CURRENT3_CURRENT             (0x2B)
#define    AFE_CURRENT4_CURRENT             (0x2C)
#define    AFE_DCDC3_CURRENT                (0x2D)
#define    AFE_ADC_IDAC                     (0x2E)
#define    AFE_IRQ_MASK1                    (0x2F)
#define    AFE_IRQ_MASK2                    (0x30)
#define    AFE_IRQ_MASK3                    (0x31)
#define    AFE_IRQ_STATUS1                  (0x32)
#define    AFE_IRQ_STATUS2                  (0x33)
#define    AFE_IRQ_STATUS3                  (0x34)
#define    AFE_LOW_VOLTAGE_STATUS1          (0x35)
#define    AFE_LOW_VOLTAGE_STATUS2          (0x36)
#define    AFE_GPIO_SIGNAL                  (0x37)
#define    AFE_PWM_HIGH_TIME                (0x38)
#define    AFE_PWM_LOW_TIME                 (0x39)
#define    AFE_CURRENT_CONTROL              (0x3A)
#define    AFE_AUDIOSET1                    (0x4A)
#define    AFE_AUDIOSET2                    (0x4B)
#define    AFE_AUDIOSET3                    (0x4C)
#define    AFE_DAC_L                        (0x4D)
#define    AFE_DAC_R                        (0x4E)
#define    AFE_ADC_L                        (0x4F)
#define    AFE_ADC_R                        (0x50)
#define    AFE_HPH_R                        (0x51)
#define    AFE_HPH_L                        (0x52)
#define    AFE_LINE_OUT_R                   (0x53)
#define    AFE_LINE_OUT_L                   (0x54)
#define    AFE_LINE_IN_R                    (0x55)
#define    AFE_LINE_IN_L                    (0x56)
#define    AFE_MIC_R                        (0x57)
#define    AFE_MIC_L                        (0x58)
#define    AFE_SPDIF                        (0x59)

#define    AFE_CHARGER_STATUS               (0x63)
#define    AFE_USB_CHARGER_STATUS           (0x64)
#define    AFE_I2S_CONTROL1                 (0x83)
#define    AFE_I2S_CONTROL2                 (0x84)
#define    AFE_UID_10                       (0xCF)


/* default values                                   */
/* these are the default values for bank7 (10kohm)  */
#define    AFE_STEP_DOWN1_DEFAULT_VALUE          (76)
#define    AFE_STEP_DOWN2_DEFAULT_VALUE          (204)
#define    AFE_STEP_DOWN3_DEFAULT_VALUE          (54)
#define    AFE_LDO_RF1_DEFAULT_VALUE             (113)
#define    AFE_LDO_RF2_DEFAULT_VALUE             (29)
#define    AFE_LDO_RF3_DEFAULT_VALUE             (17)
#define    AFE_LDO_DIG1_DEFAULT_VALUE            (21)
#define    AFE_LDO_DIG2_DEFAULT_VALUE            (21)
#define    AFE_LDO_DIG3_DEFAULT_VALUE            (9)
#define    AFE_LDO_DIG4_DEFAULT_VALUE            (9)
#define    AFE_USB_CHARGER_CONTROL_DEFAULT_VALUE (215)
#define    AFE_CHARGER_CONTROL_DEFAULT_VALUE     (173)
#define    AFE_BATTERY_MONITOR_DEFAULT_VALUE     (103)
#define    AFE_CHARGER_CONFIG_DEFAULT_VALUE      (38)
#define    AFE_FUEL_GAUGE_DEFAULT_VALUE          (1)
#define    AFE_CHARGER_CURRENT_DEFAULT_VALUE     (61)
#define    AFE_CP_CONTROL_DEFAULT_VALUE          (1)
#define    AFE_GPIO_DEFAULT_VALUE                (7)
#define    AFE_RESET_TIMER_DEFAULT_VALUE         (131)
#define    AFE_POWER1_CTRL_DEFAULT_VALUE         (255)

/* disable all IRQs per default to achieve the same behaviour as MMP chips */
#define    AFE_IRQ_MASK_DEFAULT_VALUE            (255)



/* allow all interrupts  */
#define AFE_IRQ1_MASK  (0xFF)
#define AFE_IRQ2_MASK  (0xFF)
#define AFE_IRQ3_MASK  (0xFF)


#define AFE_IRQ_FIRST   AFE_IRQ_STATUS1
#define AFE_IRQ_LAST    AFE_IRQ_STATUS3

/*number of interrupt registers                                              */
#define AFE_INT_REGISTERS_NO            (0x3)

/*highest valid address    */
#define    AFE_LAST_VALID_ADDRESS   AFE_UID_10

/*define boundary of last shadowed register address                          */
#define     AFE_SHADOWED_BOUNDARY   (AFE_IRQ_MASK3 + 1)

#endif /* AFE_CHIP_TYPE == AFE_AS3658 */

#endif /* AFE_AS3658_H_ */

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
 *      $RCSfile: $
 *      $Revision: $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author C. Eisendle
 *  \author M. Barjaktarevic (Substitute)
 *
 *  \brief  AS3515 specific header file
 *
 */

#ifndef AFE_AS3515_H_
#define AFE_AS3515_H_


#if (AFE_CHIP_TYPE == AFE_AS3515)
#define    AFE_I2C_SLAVE_ADDR               (0x46)


#define    AFE_LINE_OUT_R   (0x00)
#define    AFE_LINE_OUT_L   (0x01)
#define    AFE_HPH_OUT_R    (0x02)
#define    AFE_HPH_OUT_L    (0x03)
#define    AFE_LSP_OUT_R    (0x04)
#define    AFE_LSP_OUT_L    (0x05)
#define    AFE_MIC1_R       (0x06)
#define    AFE_MIC1_L       (0x07)
#define    AFE_MIC2_R       (0x08)
#define    AFE_MIC2_L       (0x09)
#define    AFE_LINE_IN1_R   (0x0A)
#define    AFE_LINE_IN1_L   (0x0B)
#define    AFE_LINE_IN2_R   (0x0C)
#define    AFE_LINE_IN2_L   (0x0D)
#define    AFE_DAC_R        (0x0E)
#define    AFE_DAC_L        (0x0F)
#define    AFE_ADC_R        (0x10)
#define    AFE_ADC_L        (0x11)
#define    AFE_AUDIOSET1    (0x14)
#define    AFE_AUDIOSET2    (0x15)
#define    AFE_AUDIOSET3    (0x16)
#define    AFE_VBUS_CP      (0x17)  /*obsolete definition       */
#define    AFE_USB_UTIL     (0x17)  /*new name for AFE_VBUS_CP  */
/* the following 5 registers are not used - they are skipped    */
/* during the initialisation phase                              */
#define    AFE_UNUSED_0     (0x18)
#define    AFE_UNUSED_1     (0x19)
#define    AFE_UNUSED_2     (0x1A)
#define    AFE_UNUSED_3     (0x1B)
#define    AFE_UNUSED_4     (0x1C)
#define    AFE_CLOCK_OUT    (0x1D)
#define    AFE_SYSTEM       (0x20)
#define    AFE_CVDD_DCDC3   (0x21)
#define    AFE_CHARGER      (0x22)
#define    AFE_DCDC15       (0x23)
#define    AFE_SUPERVISOR   (0x24)
#define    AFE_IRQ_ENRD0    (0x25)
#define    AFE_IRQ_ENRD1    (0x26)
#define    AFE_IRQ_ENRD2    (0x27)
#define    AFE_RTCV         (0x28)
#define    AFE_RTCT         (0x29)
#define    AFE_RTC_0        (0x2A)
#define    AFE_RTC_1        (0x2B)
#define    AFE_RTC_2        (0x2C)
#define    AFE_RTC_3        (0x2D)
#define    AFE_ADC_0        (0x2E)
#define    AFE_ADC_1        (0x2F)
#define    AFE_UID_0        (0x30)
#define    AFE_UID_1        (0x31)
#define    AFE_UID_2        (0x32)
#define    AFE_UID_3        (0x33)
#define    AFE_UID_4        (0x34)
#define    AFE_UID_5        (0x35)
#define    AFE_UID_6        (0x36)
#define    AFE_UID_7        (0x37)
#define    AFE_UID_8        (0x38)
#define    AFE_UID_9        (0x39)
#define    AFE_UID_10       (0x3A)
#define    AFE_UID_11       (0x3B)
#define    AFE_UID_12       (0x3C)
#define    AFE_UID_13       (0x3D)
#define    AFE_UID_14       (0x3E)
#define    AFE_UID_15       (0x3F)

#define AFE_SYSTEM_DEFAULT_VALUE (0x21)
#define AFE_RTCV_DEFAULT_VALUE          (0x23)
#define AFE_RTCT_DEFAULT_VALUE          (0x40)

#define AFE_IRQ_ENRD0_MASK  (0xd7)
#define AFE_IRQ_ENRD1_MASK  (0xdf)
#define AFE_IRQ_ENRD2_MASK  (0x0f)

#define AFE_IRQ_FIRST   AFE_IRQ_ENRD0
#define AFE_IRQ_LAST    AFE_IRQ_ENRD2

/*number of interrupt registers                                              */
#define AFE_INT_REGISTERS_NO            (0x3)

/*define boundary of last shadowed register address                          */
#define     AFE_SHADOWED_BOUNDARY   (AFE_AUDIOSET3 + 1)

/*highest valid address    */
#define    AFE_LAST_VALID_ADDRESS   AFE_UID_15

#endif /* AFE_CHIP_TYPE == AFE_AS3515 */

#endif /* AFE_AS3515_H_ */

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
 * third party patent, copyright or trademark. Austriamicrosystems should not*
 * be liable for any loss or damage arising from its use.                    *
 *****************************************************************************
 */

/*
 *      PROJECT:   AS353x
 *      $Revision: 759 $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author M. Boehm
 *  \author W. Reichart (Substitute)
 *
 *  Definition of AS353x USB registers.
 *
 */
#ifndef _USB_REGISTERS_H_
#define _USB_REGISTERS_H_

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/
#include "sdk_base_addresses.h"

/*
******************************************************************************
* DEFINES
******************************************************************************
*/
/*!
 * Device Logical IN Endpoint-Specific Registers
 */
#define USB_IEP0_CTRL                   (REGISTER_BASE_USB + 0x00000)   /*!< Control Register */
#define USB_IEP0_STS            (REGISTER_BASE_USB + 0x00004)   /*!< Status Register */
#define USB_IEP0_TXFSIZE        (REGISTER_BASE_USB + 0x00008)   /*!< TxFIFO Size */
#define USB_IEP0_MPS            (REGISTER_BASE_USB + 0x0000c)   /*!< Maximum Packet Size */

#define USB_IEP0_DESC_PTR        (REGISTER_BASE_USB + 0x00014)   /*!< Data Descriptor Pointer */
#define USB_IEP0_STS_MASK        (REGISTER_BASE_USB + 0x00018)   /*!< Status Mask Register */

#define USB_IEP1_CTRL                   (REGISTER_BASE_USB + 0x00020)   /*!< Control Register */
#define USB_IEP1_STS            (REGISTER_BASE_USB + 0x00024)   /*!< Status Register */
#define USB_IEP1_TXFSIZE        (REGISTER_BASE_USB + 0x00028)   /*!< TxFIFO Size */
#define USB_IEP1_MPS            (REGISTER_BASE_USB + 0x0002c)   /*!< Maximum Packet Size */

#define USB_IEP1_DESC_PTR        (REGISTER_BASE_USB + 0x00034)   /*!< Data Descriptor Pointer */
#define USB_IEP1_STS_MASK        (REGISTER_BASE_USB + 0x00038)   /*!< Status Mask Register */

#define USB_IEP2_CTRL            (REGISTER_BASE_USB + 0x00040)   /*!< Control Register */
#define USB_IEP2_STS            (REGISTER_BASE_USB + 0x00044)   /*!< Status Register */
#define USB_IEP2_TXFSIZE        (REGISTER_BASE_USB + 0x00048)   /*!< TxFIFO Size */
#define USB_IEP2_MPS            (REGISTER_BASE_USB + 0x0004c)   /*!< Maximum Packet Size */

#define USB_IEP2_DESC_PTR        (REGISTER_BASE_USB + 0x00054)   /*!< Data Descriptor Pointer */
#define USB_IEP2_STS_MASK        (REGISTER_BASE_USB + 0x00058)   /*!< Status Mask Register */

#define USB_IEP3_CTRL                   (REGISTER_BASE_USB + 0x00060)   /*!< Control Register */
#define USB_IEP3_STS            (REGISTER_BASE_USB + 0x00064)   /*!< Status Register */
#define USB_IEP3_TXFSIZE        (REGISTER_BASE_USB + 0x00068)   /*!< TxFIFO Size */
#define USB_IEP3_MPS            (REGISTER_BASE_USB + 0x0006c)   /*!< Maximum Packet Size */

#define USB_IEP3_DESC_PTR        (REGISTER_BASE_USB + 0x00074)   /*!< Data Descriptor Pointer */
#define USB_IEP3_STS_MASK        (REGISTER_BASE_USB + 0x00078)   /*!< Status Mask Register */

/*!
 * Device Logical OUT Endpoint-Specific Registers
 */
#define USB_OEP0_CTRL            (REGISTER_BASE_USB + 0x00200)   /*!< Control Register*/
#define USB_OEP0_STS            (REGISTER_BASE_USB + 0x00204)   /*!< Status Register */
#define USB_OEP0_RXFR            (REGISTER_BASE_USB + 0x00208)   /*!< Rx Packet Frame Number Register */
#define USB_OEP0_MPS            (REGISTER_BASE_USB + 0x0020c)   /*!< RxFIFO Size/Maximum Packet Size Register*/
#define USB_OEP0_SUP_PTR        (REGISTER_BASE_USB + 0x00210)   /*!< Setup buffer Pointer Register */
#define USB_OEP0_DESC_PTR        (REGISTER_BASE_USB + 0x00214)   /*!< Data Descriptor Pointer */
#define USB_OEP0_STS_MASK               (REGISTER_BASE_USB + 0x00218)   /*!< Status Mask Register */

#define USB_OEP1_CTRL                   (REGISTER_BASE_USB + 0x00220)   /*!< Control Register */
#define USB_OEP1_STS                    (REGISTER_BASE_USB + 0x00224)   /*!< Status Register */
#define USB_OEP1_RXFR                   (REGISTER_BASE_USB + 0x00228)   /*!< Rx Packet Frame Number Register */
#define USB_OEP1_MPS                    (REGISTER_BASE_USB + 0x0022c)   /*!< RxFIFO Size/Maximum Packet Size Register*/
#define USB_OEP1_SUP_PTR                (REGISTER_BASE_USB + 0x00230)   /*!< Setup buffer Pointer Register */
#define USB_OEP1_DESC_PTR               (REGISTER_BASE_USB + 0x00234)   /*!< Data Descriptor Pointer */
#define USB_OEP1_STS_MASK               (REGISTER_BASE_USB + 0x00238)   /*!< Status Mask Register */

#define USB_OEP2_CTRL                   (REGISTER_BASE_USB + 0x00240)   /*!< Control Register */
#define USB_OEP2_STS                    (REGISTER_BASE_USB + 0x00244)   /*!< Status Register */
#define USB_OEP2_RXFR                   (REGISTER_BASE_USB + 0x00248)   /*!< Rx Packet Frame Number Register */
#define USB_OEP2_MPS                    (REGISTER_BASE_USB + 0x0024c)   /*!< RxFIFO Size/Maximum Packet Size Register*/
#define USB_OEP2_SUP_PTR                (REGISTER_BASE_USB + 0x00250)   /*!< Setup buffer Pointer Register */
#define USB_OEP2_DESC_PTR               (REGISTER_BASE_USB + 0x00254)   /*!< Data Descriptor Pointer */
#define USB_OEP2_STS_MASK               (REGISTER_BASE_USB + 0x00258)   /*!< Status Mask Register */

#define USB_OEP3_CTRL                   (REGISTER_BASE_USB + 0x00260)   /*!< Control Register */
#define USB_OEP3_STS                    (REGISTER_BASE_USB + 0x00264)   /*!< Status Register */
#define USB_OEP3_RXFR                   (REGISTER_BASE_USB + 0x00268)   /*!< Rx Packet Frame Number Register */
#define USB_OEP3_MPS                    (REGISTER_BASE_USB + 0x0026c)   /*!< RxFIFO Size/Maximum Packet Size Register*/
#define USB_OEP3_SUP_PTR                (REGISTER_BASE_USB + 0x00270)   /*!< Setup buffer Pointer Register */
#define USB_OEP3_DESC_PTR               (REGISTER_BASE_USB + 0x00274)   /*!< Data Descriptor Pointer */
#define USB_OEP3_STS_MASK               (REGISTER_BASE_USB + 0x00278)   /*!< Status Mask Register */

/*!
 * Device Global Registers
 */
#define USB_DEV_CFG                     (REGISTER_BASE_USB + 0x00400)   /*!< Device Configuration Register */
#define USB_DEV_CTRL                    (REGISTER_BASE_USB + 0x00404)   /*!< Device Control Register */
#define USB_DEV_STS                     (REGISTER_BASE_USB + 0x00408)   /*!< Device Status Register */
#define USB_DEV_INTR                    (REGISTER_BASE_USB + 0x0040c)   /*!< Device Interrupt Register */
#define USB_DEV_INTR_MASK               (REGISTER_BASE_USB + 0x00410)   /*!< Device Interrupt Mask Register */
#define USB_DEV_EP_INTR                 (REGISTER_BASE_USB + 0x00414)   /*!< Device Endpoint Interrupt Register*/
#define USB_DEV_EP_INTR_MASK            (REGISTER_BASE_USB + 0x00418)   /*!< Device Endpoint Interrupt Mask Register*/

/*!
 * Device Physical Endpoint Information Registers
 */

#define USB_PHY_EP0_INFO                (REGISTER_BASE_USB + 0x00504)   /*!< Information Register */
#define USB_PHY_EP1_INFO                (REGISTER_BASE_USB + 0x00508)   /*!< Information Register */
#define USB_PHY_EP2_INFO                (REGISTER_BASE_USB + 0x0050c)   /*!< Information Register */
#define USB_PHY_EP3_INFO                (REGISTER_BASE_USB + 0x00510)   /*!< Information Register */
#define USB_PHY_EP4_INFO                (REGISTER_BASE_USB + 0x00514)   /*!< Information Register */
#define USB_PHY_EP5_INFO                (REGISTER_BASE_USB + 0x00518)   /*!< Information Register */

/*!
 * Host Channel-Specific Registers
 */

#define USB_HOST_CH0_SPLT               (REGISTER_BASE_USB + 0x01000)   /*!< Split Information Register */
#define USB_HOST_CH0_STS                (REGISTER_BASE_USB + 0x01004)   /*!< Status Register */
#define USB_HOST_CH0_TXFSIZE            (REGISTER_BASE_USB + 0x01008)   /*!< TxFIFO Register */
#define USB_HOST_CH0_REQ                (REGISTER_BASE_USB + 0x0100c)   /*!< Request Register */
#define USB_HOST_CH0_PER_INFO           (REGISTER_BASE_USB + 0x01010)   /*!< Periodic/Split Transaction Information Register */
#define USB_HOST_CH0_DESC_PTR           (REGISTER_BASE_USB + 0x01014)   /*!< Data Descriptor Pointer */
#define USB_HOST_CH0_STS_MASK           (REGISTER_BASE_USB + 0x01018)   /*!< Status Mask Register */

#define USB_HOST_CH1_SPLT               (REGISTER_BASE_USB + 0x01020)   /*!< Split Information Register */
#define USB_HOST_CH1_STS                (REGISTER_BASE_USB + 0x01024)   /*!< Status Register */
#define USB_HOST_CH1_TXFSIZE            (REGISTER_BASE_USB + 0x01028)   /*!< TxFIFO Register */
#define USB_HOST_CH1_REQ                (REGISTER_BASE_USB + 0x0102c)   /*!< Request Register */
#define USB_HOST_CH1_PER_INFO           (REGISTER_BASE_USB + 0x01030)   /*!< Periodic/Split Transaction Information Register */
#define USB_HOST_CH1_DESC_PTR           (REGISTER_BASE_USB + 0x01034)   /*!< Data Descriptor Pointer */
#define USB_HOST_CH1_STS_MASK           (REGISTER_BASE_USB + 0x01038)   /*!< Status Mask Register */

#define USB_HOST_CH2_SPLT               (REGISTER_BASE_USB + 0x01040)   /*!< Split Information Register */
#define USB_HOST_CH2_STS                (REGISTER_BASE_USB + 0x01044)   /*!< Status Register */
#define USB_HOST_CH2_TXFSIZE            (REGISTER_BASE_USB + 0x01048)   /*!< TxFIFO Register */
#define USB_HOST_CH2_REQ                (REGISTER_BASE_USB + 0x0104c)   /*!< Request Register */
#define USB_HOST_CH2_PER_INFO           (REGISTER_BASE_USB + 0x01050)   /*!< Periodic/Split Transaction Information Register */
#define USB_HOST_CH2_DESC_PTR           (REGISTER_BASE_USB + 0x01054)   /*!< Data Descriptor Pointer */
#define USB_HOST_CH2_STS_MASK           (REGISTER_BASE_USB + 0x01058)   /*!< Status Mask Register */

#define USB_HOST_CH3_SPLT               (REGISTER_BASE_USB + 0x01060)   /*!< Split Information Register */
#define USB_HOST_CH3_STS                (REGISTER_BASE_USB + 0x01064)   /*!< Status Register */
#define USB_HOST_CH3_TXFSIZE            (REGISTER_BASE_USB + 0x01068)   /*!< TxFIFO Register */
#define USB_HOST_CH3_REQ                (REGISTER_BASE_USB + 0x0106c)   /*!< Request Register */
#define USB_HOST_CH3_PER_INFO           (REGISTER_BASE_USB + 0x01070)   /*!< Periodic/Split Transaction Information Register */
#define USB_HOST_CH3_DESC_PTR           (REGISTER_BASE_USB + 0x01074)   /*!< Data Descriptor Pointer */
#define USB_HOST_CH3_STS_MASK           (REGISTER_BASE_USB + 0x01078)   /*!< Status Mask Register */

/*!
 * Host Global Registers
 */

#define USB_HOST_CFG                    (REGISTER_BASE_USB + 0x01400)   /*!< Host Configuration Register */
#define USB_HOST_CTRL                   (REGISTER_BASE_USB + 0x01404)   /*!< Host Control Register */

#define USB_HOST_INTR                   (REGISTER_BASE_USB + 0x0140c)   /*!< Host Interrupt Register */
#define USB_HOST_INTR_MASK              (REGISTER_BASE_USB + 0x01410)   /*!< Host Interrupt Mask Register */
#define USB_HOST_CH_INTR                (REGISTER_BASE_USB + 0x01414)   /*!< Host Channel Interrupt Register */
#define USB_HOST_CH_INTR_MASK           (REGISTER_BASE_USB + 0x01418)   /*!< Host Channel Interrupt Mask Register */
#define USB_HOST_FRAME_INT              (REGISTER_BASE_USB + 0x0141c)   /*!< Host Frame Interval Register */
#define USB_HOST_FRAME_REM              (REGISTER_BASE_USB + 0x01420)   /*!< Host Frame Remaining Register */
#define USB_HOST_FRAME_NUM              (REGISTER_BASE_USB + 0x01424)   /*!< Host Frame Number Register */

/*!
 * Host Port and Status Registers
 */
#define USB_HOST_PORT0_CTRL_STS         (REGISTER_BASE_USB + 0x01500)   /*!< Host Port and Status Register */


/*!
 * Core Global Registers
 */
#define USB_OTG_CSR                     (REGISTER_BASE_USB + 0x02000)   /*!< OTG Control and Status Register */
#define USB_I2C_CSR                     (REGISTER_BASE_USB + 0x02004)   /*!< I2C Access Register */
#define USB_GPIO_CSR                    (REGISTER_BASE_USB + 0x02008)   /*!< General Purpose Input/Output Register */
#define USB_SNPSID_CSR                  (REGISTER_BASE_USB + 0x0200c)   /*!< Synopsys ID Register */
#define USB_USERID_CSR                  (REGISTER_BASE_USB + 0x02010)   /*!< User ID Register */
#define USB_USER_CONF1                  (REGISTER_BASE_USB + 0x02014)   /*!< User Config1 Register */
#define USB_USER_CONF2                  (REGISTER_BASE_USB + 0x02018)   /*!< User Config2 Register */
#define USB_USER_CONF3                  (REGISTER_BASE_USB + 0x0201c)   /*!< User Config3 Register */
#define USB_USER_CONF4                  (REGISTER_BASE_USB + 0x02020)   /*!< User Config4 Register */
#define USB_USER_CONF5                  (REGISTER_BASE_USB + 0x02024)   /*!< User Config5 Register */


#endif



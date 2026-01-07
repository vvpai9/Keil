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
 *      $Revision: 759 $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author H. Treml
 *  \author M. Arpa (Substitute)
 *
 *  \brief SSP register definitions
 *
 *  SSP register definitions
 *
 */

#ifndef SSP_REGISTERS_H
#define SSP_REGISTERS_H

/*
******************************************************************************
* DEFINES
******************************************************************************
*/

#define SSP_SSPCR0      (REGISTER_BASE_SSP + 0x00) /*!< CR0 control register */
#define SSP_SSPCR1      (REGISTER_BASE_SSP + 0x04) /*!< CR1 control register */


#define SSP_SSPRXD      (REGISTER_BASE_SSP + 0x08) /*!< Read Data Register   */
#define SSP_SSPTXD      (REGISTER_BASE_SSP + 0x08) /*!< Write Data register  */

#define SSP_SSPSR       (REGISTER_BASE_SSP + 0x0C)/*!<status register        */
#define SSP_SSPCPSR     (REGISTER_BASE_SSP + 0x10)/*!<Pre-scaler register    */
#define SSP_SSPIMSC     (REGISTER_BASE_SSP + 0x14)/*!<Interrupt Mask and clear
                                                   *  register
                                                   */
#define SSP_SSPIRS      (REGISTER_BASE_SSP + 0x18)/*!<Raw interrupt status
                                                   *  register
                                                   */
#define SSP_SSPMIS      (REGISTER_BASE_SSP + 0x1C)/*!<Masked interrupt status
                                                   *  register
                                                   */
#define SSP_SSPICR      (REGISTER_BASE_SSP + 0x20)/*!<interrupt clear register*/
#define SSP_SSPDMACR    (REGISTER_BASE_SSP + 0x24)/*!<DMA control register   */


/******************************************************************************
                          SSP register bit field definitions
******************************************************************************/

#define SSPCR0_DSS_4BIT     0x03 /*!< 4-Bit Data format                      */
#define SSPCR0_DSS_5BIT     0x04 /*!< 5-Bit Data format                      */
#define SSPCR0_DSS_6BIT     0x05 /*!< 6-Bit Data format                      */
#define SSPCR0_DSS_7BIT     0x06 /*!< 7-Bit Data format                      */
#define SSPCR0_DSS_8BIT     0x07 /*!< 8-Bit Data format                      */
#define SSPCR0_DSS_9BIT     0x08 /*!< 9-Bit Data format                      */
#define SSPCR0_DSS_10BIT    0x09 /*!< 10-Bit Data format                     */
#define SSPCR0_DSS_11BIT    0x0A /*!< 11-Bit Data format                     */
#define SSPCR0_DSS_12BIT    0x0B /*!< 12-Bit Data format                     */
#define SSPCR0_DSS_13BIT    0x0C /*!< 13-Bit Data format                     */
#define SSPCR0_DSS_14BIT    0x0D /*!< 14-Bit Data format                     */
#define SSPCR0_DSS_15BIT    0x0E /*!< 15-Bit Data format                     */
#define SSPCR0_DSS_16BIT    0x0F /*!< 16-Bit Data format                     */

#define SSPCR0_SPO          0x40 /*!< Polarity for SPI format : motorola only*/
#define SSPCR0_SPH          0x80 /*!< Phase for SPI format : motorola only   */


#define SSPCR1_SOD          0x08 /*!< 0: SSP slave can drive Txd line , 1: No*/
#define SSPCR1_MS           0x04 /*!< Master or Slave Selection              */
#define SSPCR1_SSE          0x02 /*!< 1: SSE Enable                          */
#define SSPCR1_LBM          0x01 /*!< 1: SSE Loop back Enable                */

#define SSPSR_BSY           0x10 /*!< SSP idle,1 :Transmitting or receiving  */
#define SSPSR_RFF           0x08 /*!< SSP Rx fifo not full , 1 : full        */
#define SSPSR_RNE           0x04 /*!< SSP Rx fifo is empty , 1 : not empty   */
#define SSPSR_TNF           0x02 /*!< SSP Tx fifo full , 1 : not full        */
#define SSPSR_TFE           0x01 /*!< SSP Tx fifo not empty, 1 : empty       */

#define SSPDMACR_TX_EN      0x02 /*!< Tx FIFO DMA IS enabled                 */
#define SSPDMACR_RX_EN      0x01 /*!< Tx FIFO DMA IS enabled                 */


/*
******************************************************************************
* GLOBAL MACROS
******************************************************************************
*/


#define FRAME_FORMAT(format) (((format) & 0xf) << 4)
#define SET_SCR_DEVISOR(Devisor) ((Devisor & 0xff) << 8)
#define SET_CPSDVSR_DEVISOR(Devisor) (Devisor)

#endif /* SSP_REGISTERS_H                                                    */




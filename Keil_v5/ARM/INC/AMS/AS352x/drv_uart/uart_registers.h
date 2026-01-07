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
 *  \author Niveditha.V.C
 *  \author Pradeep Ganesh Natarajan (Substitute)
 *
 *  \brief Definition of AS353x UART registers
 *
 *  Definition of AS353x UART registers
 *
 */

#ifndef UART_REGISTERS_H
#define UART_REGISTERS_H

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
#define UART_DATA_REG      ((REGISTER_BASE_UART) + 0x00) /*!< Data register */
#define UART_DLO_REG       ((REGISTER_BASE_UART) + 0x00) /*!< Clock divider
                                                     (lower byte) register  */
#define UART_DHI_REG       ((REGISTER_BASE_UART) + 0x04) /*!< Clock divider
                                                     (higher byte) register */
#define UART_INTEN_REG     ((REGISTER_BASE_UART) + 0x04) /*!< Interrupt enable
                                                          *   register      */
#define UART_INTSTATUS_REG ((REGISTER_BASE_UART) + 0x08) /*!< Interrupt status
                                                          *   register      */
#define UART_FCTL_REG      ((REGISTER_BASE_UART) + 0x0C) /*!< Fifo control
                                                          *   register      */
#define UART_FSTATUS_REG   ((REGISTER_BASE_UART) + 0x0C) /*!< Fifo status
                                                          *   register      */
#define UART_LNCTL_REG     ((REGISTER_BASE_UART) + 0x10) /*!< Line control
                                                          *   register      */
#define UART_LNSTATUS_REG  ((REGISTER_BASE_UART) + 0x14) /*!< Line status
                                                          *   register      */
#endif /* UART_REGISTERS_H */



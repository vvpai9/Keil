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
 *  \author Ulrich Herrmann
 *
 *  Contains definitions of dbop registers
 *
 */
#ifndef _DBOP_REGISTERS_H_
#define _DBOP_REGISTERS_H_

/* ----------------------- includes --------------------------------------- */

#include "sdk_base_addresses.h"


#define DBOP_TIMPOL_01  ( (REGISTER_BASE_DBOP) + 0x00 ) /*!< DBOP Timing and polarity for control 0 and 1 */
#define DBOP_TIMPOL_23  ( (REGISTER_BASE_DBOP) + 0x04 ) /*!< DBOP Timing and polarity for control 1 and 2 */
#define DBOP_CTRL       ( (REGISTER_BASE_DBOP) + 0x08 ) /*!< DBOP Control Register */
#define DBOP_STAT       ( (REGISTER_BASE_DBOP) + 0x0C ) /*!< DBOP Status Register */
#define DBOP_DOUT       ( (REGISTER_BASE_DBOP) + 0x10 ) /*!< DBOP Data output register */
#define DBOP_DIN        ( (REGISTER_BASE_DBOP) + 0x14 ) /*!< DBOP Data input register */


#endif /* _DBOP_REGISTERS_H_ */



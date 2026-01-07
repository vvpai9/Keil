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
 *  \author M. Arpa
 *  \author  (Substitute)
 *
 *  \brief Definition of AS353x chip control unit registers
 *  
 *  Definition of AS353x chip control unit registers.  
 *
 */

#ifndef _CCU_REGISTERS_H_
#define _CCU_REGISTERS_H_

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
#define CCU_SRC           ( (REGISTER_BASE_CCU) + 0x00)
#define CCU_SRL           ( (REGISTER_BASE_CCU) + 0x04)
#define CCU_MEMMAP        ( (REGISTER_BASE_CCU) + 0x08)
#define CCU_IO            ( (REGISTER_BASE_CCU) + 0x0C)
#define CCU_SCON          ( (REGISTER_BASE_CCU) + 0x10)
#define CCU_VERS          ( (REGISTER_BASE_CCU) + 0x14)

#define CCU_SPARE1        ( (REGISTER_BASE_CCU) + 0x18)
#define CCU_SPARE2        ( (REGISTER_BASE_CCU) + 0x1C)

/*
******************************************************************************
* GLOBAL MACROS
******************************************************************************
*/

/*
******************************************************************************
* GLOBAL DATA TYPES
******************************************************************************
*/

/*
******************************************************************************
* GLOBAL VARIABLE DECLARATIONS
******************************************************************************
*/

/*
******************************************************************************
* GLOBAL FUNCTION PROTOTYPES
******************************************************************************
*/

#endif  /* _CCU_REGISTERS_H_ */



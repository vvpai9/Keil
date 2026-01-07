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
 *  \author H. Hackl
 *  \author M. Arpa (Substitute)
 *
 *  \brief Definition of AS353x cgu registers.
 *  
 *  Definition of AS353x cgu registers.
 *
 */


#ifndef _CGU_REGISTERS_H_
#define _CGU_REGISTERS_H_

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
#define CGU_REG_PLLA         ( (REGISTER_BASE_CGU) + 0x00 )
#define CGU_REG_PLLB         ( (REGISTER_BASE_CGU) + 0x04 )
#define CGU_REG_PLLASUP      ( (REGISTER_BASE_CGU) + 0x08 )
#define CGU_REG_PLLBSUP      ( (REGISTER_BASE_CGU) + 0x0C )
#define CGU_REG_PROC         ( (REGISTER_BASE_CGU) + 0x10 )
#define CGU_REG_PERI         ( (REGISTER_BASE_CGU) + 0x14 )
#define CGU_REG_AUDIO        ( (REGISTER_BASE_CGU) + 0x18 )
#define CGU_REG_USB          ( (REGISTER_BASE_CGU) + 0x1C )
#define CGU_REG_INTCTRL      ( (REGISTER_BASE_CGU) + 0x20 )
#define CGU_REG_IRQ          ( (REGISTER_BASE_CGU) + 0x24 )
#define CGU_REG_COUNTA       ( (REGISTER_BASE_CGU) + 0x28 )
#define CGU_REG_COUNTB       ( (REGISTER_BASE_CGU) + 0x2C )
#define CGU_REG_IDE          ( (REGISTER_BASE_CGU) + 0x30 )
#define CGU_REG_MEMSTICK     ( (REGISTER_BASE_CGU) + 0x34 )
#define CGU_REG_DBOP         ( (REGISTER_BASE_CGU) + 0x38 )

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

#endif  /* _CGU_REGISTERS_H_ */



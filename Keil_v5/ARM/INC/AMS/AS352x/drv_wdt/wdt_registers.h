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
 *  \author Monika Arpa
 *
 *  Register addresses
 *
 */

#ifndef _WDT_REGISTERS_H_
#define _WDT_REGISTERS_H_

/* ----------------------- includes --------------------------------------- */

#include "sdk_base_addresses.h"


/* ----------------------- defines ---------------------------------------- */


#define WDT_LOAD      ( REGISTER_BASE_WDT + 0x000 ) /* 32-bits r/w */
#define WDT_VALUE     ( REGISTER_BASE_WDT + 0x004 ) /* 32-bits ro  */
#define WDT_CONTROL   ( REGISTER_BASE_WDT + 0x008 ) /*  2-bits r/w */
#define WDT_INTCLR    ( REGISTER_BASE_WDT + 0x00C ) /*         wo  */
#define WDT_RIS       ( REGISTER_BASE_WDT + 0x010 ) /*  1-bit  ro  */
#define WDT_MIS       ( REGISTER_BASE_WDT + 0x014 ) /*  1-bit  ro  */
#define WDT_LOCK      ( REGISTER_BASE_WDT + 0xC00 ) /* 32-bits r/w */


/**
 * Peripheral ID register - read only
 **/
#define WDT_PERIPHID0 ( REGISTER_BASE_WDT + 0xFE0 )
#define WDT_PERIPHID1 ( REGISTER_BASE_WDT + 0xFE4 )
#define WDT_PERIPHID2 ( REGISTER_BASE_WDT + 0xFE8 )
#define WDT_PERIPHID3 ( REGISTER_BASE_WDT + 0xFEC )

/**
 * Prime Cell ID register - read only
 **/
#define WDT_PCELLID0 ( REGISTER_BASE_WDT + 0xFF0 )
#define WDT_PCELLID1 ( REGISTER_BASE_WDT + 0xFF4 )
#define WDT_PCELLID2 ( REGISTER_BASE_WDT + 0xFF8 )
#define WDT_PCELLID3 ( REGISTER_BASE_WDT + 0xFFC )




#endif /* _WDT_REGISTERS_H_ */



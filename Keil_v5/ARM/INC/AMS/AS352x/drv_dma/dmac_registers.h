

/********************************************************************************/
/* Copyright @ 2004 by austriamicrosystems AG                                   */
/* All rights are reserved. Reproduction in whole or in part is                 */
/* prohibited without the written consent of the copyright owner.               */
/* austriamicrosystems reserves the right to make changes without notice at     */
/* any time. The software is provided as is and austriamicrosystems makes       */
/* no warranty, expressed, implied or statutory, including but not limited to   */
/* any implied warranty of merchantability or fitness for any particular        */
/* purpose, or that the use will not infringe any third party patent, copyright */
/* or trademark. Austriamicrosystems should not be liable for any loss or       */
/* damage arising from its use.                                                 */
/********************************************************************************/

/**
 *        PROJECT: AS353x                                                       
 *      COPYRIGHT: austriamicrosystems 2004                                     
 *      $Revision: 759 $                                                        
 *         AUTHOR: H. Hackl                                                     
 *       LANGUAGE: C                                                            
 *    DESCRIPTION: Definition of AS353x DMAC registers. 
 *                        
 **/
#ifndef _DMAC_REGISTERS_H_
#define _DMAC_REGISTERS_H_

/* ----------------------- includes --------------------------------------- */

#include "sdk_base_addresses.h"


/* ----------------------- defines ---------------------------------------- */

#define DMAC_IntStatus             ( (REGISTER_BASE_DMAC) + 0x000 )
#define DMAC_IntTCStatus           ( (REGISTER_BASE_DMAC) + 0x004 )
#define DMAC_IntTCClear            ( (REGISTER_BASE_DMAC) + 0x008 )
#define DMAC_IntErrorStatus        ( (REGISTER_BASE_DMAC) + 0x00C )
#define DMAC_IntErrorClear         ( (REGISTER_BASE_DMAC) + 0x010 )
#define DMAC_RawIntTCStatus        ( (REGISTER_BASE_DMAC) + 0x014 )
#define DMAC_RawIntErrorStatus     ( (REGISTER_BASE_DMAC) + 0x018 )

#define DMAC_SoftBReq              ( (REGISTER_BASE_DMAC) + 0x020 )
#define DMAC_SoftSReq              ( (REGISTER_BASE_DMAC) + 0x024 )
#define DMAC_SoftLBReq             ( (REGISTER_BASE_DMAC) + 0x028 )
#define DMAC_SoftSBReq             ( (REGISTER_BASE_DMAC) + 0x02C )

#define DMAC_Configuration         ( (REGISTER_BASE_DMAC) + 0x030 )
#define DMAC_Sync                  ( (REGISTER_BASE_DMAC) + 0x034 )

#define DMAC_C0SrcAddr             ( (REGISTER_BASE_DMAC) + 0x100 )
#define DMAC_C0DestAddr            ( (REGISTER_BASE_DMAC) + 0x104 )
#define DMAC_C0LLI                 ( (REGISTER_BASE_DMAC) + 0x108 )
#define DMAC_C0Control             ( (REGISTER_BASE_DMAC) + 0x10C )
#define DMAC_C0Configuration       ( (REGISTER_BASE_DMAC) + 0x110 )

#define DMAC_C1SrcAddr             ( (REGISTER_BASE_DMAC) + 0x120 )
#define DMAC_C1DestAddr            ( (REGISTER_BASE_DMAC) + 0x124 )
#define DMAC_C1LLI                 ( (REGISTER_BASE_DMAC) + 0x128 )
#define DMAC_C1Control             ( (REGISTER_BASE_DMAC) + 0x12C )
#define DMAC_C1Configuration       ( (REGISTER_BASE_DMAC) + 0x130 )

#define DMAC_PeripheralId0         ( (REGISTER_BASE_DMAC) + 0xFE0 )
#define DMAC_PeripheralId1         ( (REGISTER_BASE_DMAC) + 0xFE4 )
#define DMAC_PeripheralId2         ( (REGISTER_BASE_DMAC) + 0xFE8 )
#define DMAC_PeripheralId3         ( (REGISTER_BASE_DMAC) + 0xFEC )
#define DMAC_CellId0               ( (REGISTER_BASE_DMAC) + 0xFF0 )
#define DMAC_CellId1               ( (REGISTER_BASE_DMAC) + 0xFF4 )
#define DMAC_CellId2               ( (REGISTER_BASE_DMAC) + 0xFF8 )
#define DMAC_CellId3               ( (REGISTER_BASE_DMAC) + 0xFFC )

#endif /* _DMAC_REGISTERS_H_ */



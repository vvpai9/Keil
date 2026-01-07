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
/* -------------------------------------------------------------------
 *        PROJECT: AS353x
 *      COPYRIGHT: austriamicrosystems 2004
 *      $Revision: 759 $
 *          AUTOR: H. Treml
 *     SUBSTITUTE: M. Arpa
 *       LANGUAGE: C
 *    DESCRIPTION: timer driver
 *
 * ------------------------------------------------------------------- */

#ifndef _TIMER_REGISTERS_H_
#define _TIMER_REGISTERS_H_


/* ----------------------- includes --------------------------------------- */

#include "sdk_base_addresses.h"


/* ----------------------- defines ---------------------------------------- */

#define Timer1Load       ( (REGISTER_BASE_TIMER) + 0x00 ) /* 32-bit width */
#define Timer1Value      ( (REGISTER_BASE_TIMER) + 0x04 ) /* 32 bit width */
#define Timer1Control    ( (REGISTER_BASE_TIMER) + 0x08 ) /*  8 bit width */
#define Timer1IntClr     ( (REGISTER_BASE_TIMER) + 0x0C ) /* clears ir by write access */
#define Timer1RIS        ( (REGISTER_BASE_TIMER) + 0x10 ) /*  1 bit width */
#define Timer1MIS        ( (REGISTER_BASE_TIMER) + 0x14 ) /*  1 bit width */

#define Timer2Load       ( (REGISTER_BASE_TIMER) + 0x20 )
#define Timer2Value      ( (REGISTER_BASE_TIMER) + 0x24 )
#define Timer2Control    ( (REGISTER_BASE_TIMER) + 0x28 )
#define Timer2IntClr     ( (REGISTER_BASE_TIMER) + 0x2C )
#define Timer2RIS        ( (REGISTER_BASE_TIMER) + 0x30 )
#define Timer2MIS        ( (REGISTER_BASE_TIMER) + 0x34 )

#endif /* _TIMER_REGISTERS_H_ */



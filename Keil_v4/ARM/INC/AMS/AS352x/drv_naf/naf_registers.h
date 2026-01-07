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
 *    DESCRIPTION: Definition of AS353x naf registers.
 *                          
 **/

#ifndef _NAF_REGISTERS_H_
#define _NAF_REGISTERS_H_



/**********************************************************************/
/*** Register     Offset  Width Type  Function                      ***/
/*** ============================================================== ***/
/*** NAFConfig    0x000      20  R/W  Configuration register        ***/
/*** NAFControl   0x004       2  W    Control register              ***/
/*** NAFEcc       0x008      32  R    ECC register                  ***/
/*** NAFData      0x00C      16  R/W  Data (unbufferd) register     ***/
/*** NAFMode      0x010       8  R/W  Mode register                 ***/
/*** NAFStatus    0x014      14  R    Status register               ***/
/*** NAFMask      0x018       7  R/W  Interrupt mask register       ***/
/*** NAFFifodata  0x01C      32  R/W  Data (buffered) register      ***/
/*** NAFWords     0x020      11  R/W  Words register                ***/
/*** NAFClear     0x024       7  W    Interrupt Clear register      ***/
/*** NAFTest      0x028       2  W    Test register                 ***/
/**********************************************************************/

/* ----------------------- includes --------------------------------------- */

#include "sdk_base_addresses.h"


/* ----------------------- defines ---------------------------------------- */

//      Registername        Address

#define NAF_CONFIG         ( (REGISTER_BASE_NAND_FLASH) + 0x00 )
#define NAF_CONTROL        ( (REGISTER_BASE_NAND_FLASH) + 0x04 )
#define NAF_ECC            ( (REGISTER_BASE_NAND_FLASH) + 0x08 )
#define NAF_DATA           ( (REGISTER_BASE_NAND_FLASH) + 0x0C )
#define NAF_MODE           ( (REGISTER_BASE_NAND_FLASH) + 0x10 )
#define NAF_STATUS         ( (REGISTER_BASE_NAND_FLASH) + 0x14 )
#define NAF_MASK           ( (REGISTER_BASE_NAND_FLASH) + 0x18 )
#define NAF_FIFODATA       ( (REGISTER_BASE_NAND_FLASH) + 0x1C )
#define NAF_WORDS          ( (REGISTER_BASE_NAND_FLASH) + 0x20 )
#define NAF_CLEAR          ( (REGISTER_BASE_NAND_FLASH) + 0x24 )
#define NAF_TEST           ( (REGISTER_BASE_NAND_FLASH) + 0x28 )
                            
#endif /* _NAF_REGISTERS_H_ */




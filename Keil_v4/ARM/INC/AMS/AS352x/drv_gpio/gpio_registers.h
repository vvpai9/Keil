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
 *  \brief Definition of AS353x GPIO registers.
 *  
 *  Definition of AS353x GPIO registers.
 *
 */

/*! \page drv_gpio

 \section sec1 Assignment
 The GPIO driver is providing all register definitions for the general purpose ports. 
 It is not implemented specially for one application, because these ports can be used 
 by various applications.
 As an example implementation there is also a sample LED driver available within the 
 GPIO driver directory which is capable of controlling the two LED s on the evaluation 
 board.
 Each general purpose data register is mapped to 256 different locations. 
 The address of each of these 256 locations defines which bits can be accessed through 
 this "instance" of the data register. I.e. the address is used as a mask for the data 
 register. 

 \section sec2 Interface
 The interfaces are only register definitions.

*/

#ifndef _GPIO_REGISTERS_H_
#define _GPIO_REGISTERS_H_

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
/****************   GPIO1   *******************/

#define GPIO1_DATA       ( (REGISTER_BASE_GPIO1) + 0x000 )  /* GPIO data register */
#define GPIO1_DIR        ( (REGISTER_BASE_GPIO1) + 0x400 )  /* GPIO data direction register */
#define GPIO1_IS         ( (REGISTER_BASE_GPIO1) + 0x404 )  /* GPIO interrupt sense register */
#define GPIO1_IBE        ( (REGISTER_BASE_GPIO1) + 0x408 )  /* GPIO interrupt both edges register */
#define GPIO1_IEV        ( (REGISTER_BASE_GPIO1) + 0x40C )  /* GPIO interrupt event register */
#define GPIO1_IE         ( (REGISTER_BASE_GPIO1) + 0x410 )  /* GPIO interrupt mask register */
#define GPIO1_RIS        ( (REGISTER_BASE_GPIO1) + 0x414 )  /* GPIO raw interrupt status */
#define GPIO1_MIS        ( (REGISTER_BASE_GPIO1) + 0x418 )  /* GPIO masked interrupt status */
#define GPIO1_IC         ( (REGISTER_BASE_GPIO1) + 0x41C )  /* GPIO interrupt clear */
#define GPIO1_AFSEL      ( (REGISTER_BASE_GPIO1) + 0x420 )  /* GPIO mode control select */
                                                        
                                                        
/****************   GPIO2   *******************/        
                                                        
#define GPIO2_DATA       ( (REGISTER_BASE_GPIO2) + 0x000 )  /* GPIO data register */
#define GPIO2_DIR        ( (REGISTER_BASE_GPIO2) + 0x400 )  /* GPIO data direction register */
#define GPIO2_IS         ( (REGISTER_BASE_GPIO2) + 0x404 )  /* GPIO interrupt sense register */
#define GPIO2_IBE        ( (REGISTER_BASE_GPIO2) + 0x408 )  /* GPIO interrupt both edges register */
#define GPIO2_IEV        ( (REGISTER_BASE_GPIO2) + 0x40C )  /* GPIO interrupt event register */
#define GPIO2_IE         ( (REGISTER_BASE_GPIO2) + 0x410 )  /* GPIO interrupt mask register */
#define GPIO2_RIS        ( (REGISTER_BASE_GPIO2) + 0x414 )  /* GPIO raw interrupt status */
#define GPIO2_MIS        ( (REGISTER_BASE_GPIO2) + 0x418 )  /* GPIO masked interrupt status */
#define GPIO2_IC         ( (REGISTER_BASE_GPIO2) + 0x41C )  /* GPIO interrupt clear */
#define GPIO2_AFSEL      ( (REGISTER_BASE_GPIO2) + 0x420 )  /* GPIO mode control select */

                                                        
/****************   GPIO3   *******************/        
                                                        
#define GPIO3_DATA       ( (REGISTER_BASE_GPIO3) + 0x000 )  /* GPIO data register */
#define GPIO3_DIR        ( (REGISTER_BASE_GPIO3) + 0x400 )  /* GPIO data direction register */
#define GPIO3_IS         ( (REGISTER_BASE_GPIO3) + 0x404 )  /* GPIO interrupt sense register */
#define GPIO3_IBE        ( (REGISTER_BASE_GPIO3) + 0x408 )  /* GPIO interrupt both edges register */
#define GPIO3_IEV        ( (REGISTER_BASE_GPIO3) + 0x40C )  /* GPIO interrupt event register */
#define GPIO3_IE         ( (REGISTER_BASE_GPIO3) + 0x410 )  /* GPIO interrupt mask register */
#define GPIO3_RIS        ( (REGISTER_BASE_GPIO3) + 0x414 )  /* GPIO raw interrupt status */
#define GPIO3_MIS        ( (REGISTER_BASE_GPIO3) + 0x418 )  /* GPIO masked interrupt status */
#define GPIO3_IC         ( (REGISTER_BASE_GPIO3) + 0x41C )  /* GPIO interrupt clear */
#define GPIO3_AFSEL      ( (REGISTER_BASE_GPIO3) + 0x420 )  /* GPIO mode control select */

                                                        
/****************   GPIO4   *******************/        
                                                        
#define GPIO4_DATA       ( (REGISTER_BASE_GPIO4) + 0x000 )  /* GPIO data register */
#define GPIO4_DIR        ( (REGISTER_BASE_GPIO4) + 0x400 )  /* GPIO data direction register */
#define GPIO4_IS         ( (REGISTER_BASE_GPIO4) + 0x404 )  /* GPIO interrupt sense register */
#define GPIO4_IBE        ( (REGISTER_BASE_GPIO4) + 0x408 )  /* GPIO interrupt both edges register */
#define GPIO4_IEV        ( (REGISTER_BASE_GPIO4) + 0x40C )  /* GPIO interrupt event register */
#define GPIO4_IE         ( (REGISTER_BASE_GPIO4) + 0x410 )  /* GPIO interrupt mask register */
#define GPIO4_RIS        ( (REGISTER_BASE_GPIO4) + 0x414 )  /* GPIO raw interrupt status */
#define GPIO4_MIS        ( (REGISTER_BASE_GPIO4) + 0x418 )  /* GPIO masked interrupt status */
#define GPIO4_IC         ( (REGISTER_BASE_GPIO4) + 0x41C )  /* GPIO interrupt clear */
#define GPIO4_AFSEL      ( (REGISTER_BASE_GPIO4) + 0x420 )  /* GPIO mode control select */

/*
******************************************************************************
* GLOBAL MACROS
******************************************************************************
*/
/* PURPOSE     : Macros for atomic setting/clearing bits in a certain GPIO 
   USAGE       : ClrGPIOBits(GPIO3,0x05) clears bit 2 and bit 0 in CGPIO3 
   DESCRIPTION : Macro works because of special layout of ARMs GPIO IP block which 
                 can access single bits via special addresses.
 */

#define ClrGPIOBits(gpio,mask)   \
    WReg8((gpio##_DATA+((mask)<<2)),0) 

#define SetGPIOBits(gpio,mask)   \
    WReg8((gpio##_DATA+((mask)<<2)),(mask))

#define ReadGPIOBits(gpio,mask)   \
    RReg8((gpio##_DATA+((mask)<<2)))

#define WriteGPIOBits(gpio,mask,value)   \
    WReg8((gpio##_DATA+((mask)<<2)),value)

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

#endif /* _GPIO_REGISTERS_H_ */



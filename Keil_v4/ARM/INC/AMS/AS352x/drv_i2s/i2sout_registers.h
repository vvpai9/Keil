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
 *  \author Indrajith Radhakrishnan
 *  \author Pradeep Ganesh Natarajan(Substitute)
 *
 *  \brief
 *
 *  i2sout interface register addresses
 *
*/

#ifndef _I2OUT_REGISTERS_H_
#define _I2OUT_REGISTERS_H_


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

/***************************************************************************/
/*** Register            Offset   Width  Type   Function                 ***/
/*** =================================================================== ***/
/*** I2SOUT_CONTROL      0x000     7     R/W    Control register         ***/
/*** I2SOUT_MASK         0x004     8     R/W    Interrupt mask register  ***/
/*** I2SOUT_RAW_STATUS   0x008     8     R      Raw status register      ***/
/*** I2SOUT_STATUS       0x00C     8     R      Status register          ***/
/*** I2SOUT_CLEAR        0x010     8     W      Interrupt clear register ***/
/*** I2SOUT_DATA         0x014    32     R/W    Audio data register      ***/
/***************************************************************************/

/* Register addresses */
#define I2SOUT_CONTROL          ( (REGISTER_BASE_I2SOUT) + 0x00) /* control register */
#define I2SOUT_MASK             ( (REGISTER_BASE_I2SOUT) + 0x04) /* interrupt mask register */
#define I2SOUT_RAW_STATUS       ( (REGISTER_BASE_I2SOUT) + 0x08) /* raw status register */
#define I2SOUT_STATUS           ( (REGISTER_BASE_I2SOUT) + 0x0C) /* status register */
#define I2SOUT_CLEAR            ( (REGISTER_BASE_I2SOUT) + 0x10) /* interrupt clear register */
#define I2SOUT_DATA             ( (REGISTER_BASE_I2SOUT) + 0x14) /* audio data register */


#endif /* _I2OUT_REGISTERS_H_ */



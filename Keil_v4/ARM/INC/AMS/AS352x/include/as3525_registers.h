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
 *  \author M. Arpa
 *  \author H. Treml (Substitute)
 *
 *  \brief Definition of AS353x registers
 *  
 *  Definition of AS353x registers that are used by more
 *  than one module. Registers of a module may be specified
 *  here or in a module_register.h file.
 *
 */

#ifndef _AS3525_REGISTERS_H_
#define _AS3525_REGISTERS_H_

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/

#include "ams_types.h"

/*
******************************************************************************
* DEFINES
******************************************************************************
*/

/*
******************************************************************************
* GLOBAL MACROS
******************************************************************************
*/

/**
 * This macro shall be used to access a 32-bit wide register for reading
 * the value.
 *
 * E.g. to read from the TEST_REG add in the code:
 *
 *         uint32 testInput;
 *
 *         testInput = RReg32( TEST_REG );
 *
 **/
#define RReg32( registerAddress ) \
        ( *( ( const volatile uint32 * )( registerAddress ) ) )


/**
 * This macro shall be used to access a 32-bit wide register for writing
 * the value.
 *
 * E.g. to write to the TEST_REG add in the code:
 *
 *         uint32 testOutput = 0x23456789;
 *
 *         WReg32( TEST_REG, testOutput );
 *
 **/
#define WReg32( registerAddress, value ) \
        ( *( (volatile uint32 *)(registerAddress) ) = ( (uint32)(value) ) )


/**
 * This macro shall be used to access a 32-bit wide register for setting
 * some bits to the current value.
 *
 * E.g. to set bit 24 of TEST_REG add in the code:
 *
 *         SetRegBits32( TEST_REG, (1 << 24) );
 *
 **/
#define SetRegBits32( registerAddress, value ) \
        ( *( (volatile uint32 *)(registerAddress) ) |= ( (uint32)(value) ) )

/**
 * This macro shall be used to access a 32-bit wide register for clearing
 * some bits to the current value.
 *
 * E.g. to clear bit 24 of TEST_REG add in the code:
 *
 *         ClrRegBits32( TEST_REG, (1 << 24) );
 *
 **/
#define ClrRegBits32( registerAddress, value ) \
        ( *( (volatile uint32 *)(registerAddress) ) &= ( ~( (uint32)(value) ) ) )

/**
 * This macro shall be used to access a 16-bit wide register for reading
 * the value. See RReg32 for a sample.
 **/
#define RReg16( registerAddress ) \
        ( *( ( const volatile uint16 * )( registerAddress ) ) )


/**
 * This macro shall be used to access a 32-bit wide register for writing
 * the value. See WReg32 for a sample.
 **/
#define WReg16( registerAddress, value ) \
        ( *( (volatile uint16 *)(registerAddress) ) = ( (uint16)(value) ) )


/**
 * This macro shall be used to access a 16-bit wide register for setting
 * some bits to the current value.
 *
 * E.g. to set bit 14 of TEST_REG add in the code:
 *
 *         SetRegBits16( TEST_REG, (1 << 14) );
 *
 **/
#define SetRegBits16( registerAddress, value ) \
        ( *( (volatile uint16 *)(registerAddress) ) |= ( (uint16)(value) ) )

/**
 * This macro shall be used to access a 16-bit wide register for clearing
 * some bits to the current value.
 *
 * E.g. to clear bit 14 of TEST_REG add in the code:
 *
 *         ClrRegBits16( TEST_REG, (1 << 14) );
 *
 **/
#define ClrRegBits16( registerAddress, value ) \
        ( *( (volatile uint16 *)(registerAddress) ) &= ( ~( (uint16)(value) ) ) )

/**
 * This macro shall be used to access a 8-bit wide register for reading
 * the value. See RReg32 for a sample.
 **/
#define RReg8( registerAddress ) \
        ( *( ( const volatile uint8 * )( registerAddress ) ) )


/**
 * This macro shall be used to access a 8-bit wide register for writing
 * the value. See WReg32 for a sample.
 **/
#define WReg8( registerAddress, value ) \
        ( *( (volatile uint8 *)(registerAddress) ) = ( (uint8)(value) ) )


/**
 * This macro shall be used to access a  8-bit wide register for setting
 * some bits to the current value.
 *
 * E.g. to set bit  4 of TEST_REG add in the code:
 *
 *         SetRegBits8( TEST_REG, (1 <<  4) );
 *
 **/
#define SetRegBits8( registerAddress, value ) \
        ( *( (volatile uint8 *)(registerAddress) ) |= ( (uint8)(value) ) )

/**
 * This macro shall be used to access a  8-bit wide register for clearing
 * some bits to the current value.
 *
 * E.g. to clear bit  4 of TEST_REG add in the code:
 *
 *         ClrRegBits8( TEST_REG, (1 <<  4) );
 *
 **/
#define ClrRegBits8( registerAddress, value ) \
        ( *( (volatile uint8 *)(registerAddress) ) &= ( ~( (uint8)(value) ) ) )


/* ------------------- include register definitions ---------------------- */

/**
 * Add your module here like the sample for NAF and DMAC below.
 **/



#endif /* _AS3525_REGISTERS_H_ */



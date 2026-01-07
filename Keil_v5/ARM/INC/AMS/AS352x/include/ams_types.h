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
 *  \author W. Schoegler (Substitute)
 *
 *  \brief Definition of basic data types. 
 *  
 *  Definition of basic data types. These data types have
 *  fixed sizes. This file has to be adapted for each project.
 *
 */

#ifndef _AMS_TYPES_H_
#define _AMS_TYPES_H_

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/
//#include "sdk_config.h" // commented because file does not exist in includes

/*
******************************************************************************
* DEFINES
******************************************************************************
*/

/**
 * If not already defined, define these two.
 **/
#ifndef TRUE
   #define TRUE 1
   #define FALSE 0
#endif

/**
 *  define assert macro if configured 
 **/
#if (SDK_USE_ASSERT)
    #define SDK_ASSERT(x) if(!(x))while(1)
#else
    #define SDK_ASSERT(x) 0
#endif



#ifndef NULL
#define NULL (void *)0
#endif

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
 * All following types have fixed size in number of bits.
 */
typedef unsigned char  uint8;          /* sizeof(uint8)  == 1 byte */
typedef unsigned short uint16;         /* sizeof(uint16) == 2 byte */
typedef unsigned int   uint32;         /* sizeof(uint32) == 4 byte */

typedef   signed char  sint8;          /* sizeof(sint8)  == 1 byte */
typedef   signed short sint16;         /* sizeof(sint16) == 2 byte */
typedef   signed int   sint32;         /* sizeof(sint32) == 4 byte */


/*
 * For loops, counters, etc. use the fastest integer type if the
 * range of it is sufficient.
 * Note that the size and range of this type is processor dependant.
 */
typedef unsigned int uint;
typedef   signed int sint;


/*
 * This type can be used for flags.
 */
typedef sint bool_t;

/* Data type for wide (16 bit) characters. Strings composed of wide strings 
are similar to char strings. However the end is encoded by a 0 wchar and
not a byte. This implies that standard string functions do not work anymore.
*/
typedef uint16 wchar;

/* -------------------- types for i2s driver and its clients ---------- */

/* Note: currently used by I2S driver. */
typedef enum enableDisableTag
{
    DISABLE = 0, /* disable */
    ENABLE  = 1 /* enable  */
} enblDsbl;


/* -------------------- types for block devices ----------------------- */

/**
 * This call back function is used by all block device drivers.
 **/
typedef void (* devCallBack )( sint errCode );


/* -------------------- types for vic --------------------------------- */

/**
 * Every ISR must have the following signature.
 **/
typedef void (* amsIsr )( void );


/**
 * The structure below defines the entries that are necessary for the
 * vic_small library to handle interrupts in the system.
 * Each interrupt service routine must be represented by such an entry.
 **/
typedef struct _amsIsrSrcTable
{
    /**
     * The ISR function pointer. This pointer is called by the vic
     * when the interrupt is enabled and the corresponding source 
     * (field src) is set 1 by the HW. 
     **/
    amsIsr isr;

    /**
     * The source of the interrupt. Is defined in file 
     * sdk_interrupts.h as an enum. Enums on ARM are per default
     * as small as possible. Here this means 1 byte, but a 32-bit
     * unsigned value is easier for using, and the struct size in
     * when used in an array remains the same.
     **/
    uint32 src;
} amsIsrSrcTable;


#endif /* _AMS_TYPES_H_ */




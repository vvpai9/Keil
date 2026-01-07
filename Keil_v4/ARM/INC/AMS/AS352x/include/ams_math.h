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
 *  \brief Definition of MACROS for math operations not supported by the processor.
 *  
 *  Definition of MACROS for math operations not supported
 *  by the processor.
 *
 */

#ifndef _AMS_MATH_H_
#define _AMS_MATH_H_

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/

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
/* Macro introduced to compensate for no support for floating point
   division operation in the processor. So to get the correct value,
   roundup is peformed to provide accurate results for certain conditions. */

#define DIVIDE_AND_ROUND_UP(dividend,divisor) \
         ( ( (dividend) + (divisor) - 1 ) / (divisor) )

/* For sake of completness and for easier exchanging of round-up and round-down 
   divisions provide also a round-down macro */

#define DIVIDE_AND_ROUND_DOWN( a , b ) ((a)/(b))

/* Macro which evaluates to the absolute value of an integer value*/
#define ABS(A) (((A)>0)?(A):(-(A)))

#endif /* _AMS_MATH_H */




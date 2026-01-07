/*
$Id: typedefs.h,v 1.5 2004/03/05 09:07:41 ra4951 Exp $
*/

#ifdef DEBUG
/**************************************************************************
 * Copyright (c) Motorola 2004      All Rights Reserved                   *
 *                                                                        *
 * DESCRIPTION:                                                           *
 * This file defines integer data types for the device header file        *
 **************************************************************************/

/* 
$Log: typedefs.h,v $
Revision 1.5  2004/03/05 09:07:41  ra4951
Removed nested comments in CVS Log

Revision 1.4  2004/03/04 22:04:10  ra4951
Fixed comments in banner

Revision 1.3  2004/03/04 22:00:15  ra4951
Added CVS Log:, added FALSE, TRUE and enum bool_t

Revision 1.2  2004/03/03 ra4951
Fixed history, converted to DOS cr/lf format

Revision 1.1  2004/03/03 ra4951
Renamed file, removed redundant cases

Revision 0.7  2004/03/03 ra4951
Added default case for unknown toolset

Revision 0.6  2003/08/13 ra4951
Rearranged, cleaned up some comments

Revision 0.5  2003/06/17 ra4951
Added GCC support

Revision 0.4  2003/06/17 r12110
Change name to motint.h and merge  MPC5500 and MAC7100 files.

Revision 0.3  2003/05/07 r12110
Change to fully use ISO data types.

Revision 0.2  2003/03/06 r12110
Added DCC support.

Revision 0.1  2003/02/17 r12110
Initial version of file.
*/

#endif

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

typedef unsigned char bool_t;

/* Standard typedefs used by header files, based on ISO C standard */

#if defined __MWERKS__    //Metrowerk CodeWarrior
    #include <stdint.h>

    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;

#else

    // default (DIAB, GNUC, GHS, etc.)
    typedef signed char int8_t;
    typedef unsigned char uint8_t;
    typedef volatile signed char vint8_t;
    typedef volatile unsigned char vuint8_t;

    typedef signed short int16_t;
    typedef unsigned short uint16_t;
    typedef volatile signed short vint16_t;
    typedef volatile unsigned short vuint16_t;

    typedef signed int int32_t;
    typedef unsigned int uint32_t;
    typedef volatile signed int vint32_t;
    typedef volatile unsigned int vuint32_t;

#endif
#endif // _TYPEDEFS_H_

/*********************************************************************
 *
 * Copyright:
 *  MOTOROLA, INC. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of Motorola, Inc. This
 *  software is provided on an "AS IS" basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, MOTOROLA
 *  DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED, INCLUDING
 *  IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR
 *  PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH REGARD TO THE
 *  SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF) AND ANY
 *  ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL MOTOROLA BE LIABLE FOR ANY DAMAGES WHATSOEVER (INCLUDING
 *  WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS
 *  INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY
 *  LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Motorola assumes no responsibility for the maintenance and support
 *  of this software
 ********************************************************************/

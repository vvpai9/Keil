#ifndef __LPC_TYPE_H
#define __LPC_TYPE_H

/***********************************************************************
 *                                                                                      
 *    Copyright (c) 2004, BU MMS China, Philps Semiconductor                     
 *    All rights reserved.                                                             
 *                                                                                   
 *    File name: 	LPC_Type.h                                                          
 *    Description: 	Standard types, and some useful coding macros.
 *                                                                                      
 *    History:                                                                     
 *    1. Date:		Aug 08, 2004                                              	
 *       Author: 	Shawn Zhang                                                    
 *       Description: Create  
 *
 *	$Revision: 1.0 $
 **********************************************************************/

#ifndef lpc_halint8
#define lpc_halint8 char
#endif
#ifndef lpc_halint16
#define lpc_halint16 short
#endif
#ifndef lpc_halint32
#define lpc_halint32 long
#endif
#ifndef lpc_halint64
#define lpc_halint64 long long
#endif

#ifndef lpc_haladdress
#define lpc_haladdress lpc_uint32
#endif
#ifndef lpc_haladdrword
#define lpc_haladdrword lpc_uint32
#endif

#ifndef lpc_halbool
#define lpc_halbool int
#endif

/*******************************************************
 * Define basic types for using integers in memory and structures;
 * depends on compiler defaults and CPU type.
 *******************************************************/
typedef unsigned lpc_halint8    lpc_uint8;
typedef   signed lpc_halint8    lpc_int8;

typedef unsigned lpc_halint16   lpc_uint16;
typedef   signed lpc_halint16   lpc_int16;

typedef unsigned lpc_halint32   lpc_uint32;
typedef   signed lpc_halint32   lpc_int32;

typedef unsigned lpc_halint64   lpc_uint64;
typedef   signed lpc_halint64   lpc_int64;

typedef  lpc_halbool            lpc_bool;

typedef unsigned char    uint8;      // 无符号8位整型变量
typedef signed   char    int8;       // 有符号8位整型变量
typedef unsigned short   uint16;     // 无符号16位整型变量
typedef signed   short   int16;      // 有符号16位整型变量
typedef unsigned int     uint32;     // 无符号32位整型变量
typedef signed   int     int32;      // 有符号32位整型变量
typedef float            fp32;       // 单精度浮点数（32位长度）
typedef double           fp64;       // 双精度浮点数（64位长度）

/*******************************************************
 * The obvious few that compilers may define for you.
 * But in case they don't:
 *******************************************************/
#ifndef NULL
#define NULL 0
#endif

#ifndef __cplusplus

typedef lpc_halbool bool;

#ifndef false
#define false 0
#endif

#ifndef true
#define true (!false)
#endif

#endif


/* GPIO port */
#define P0	0x1
#define P1	0x2
#define P2	0x4
#define P3	0x8
#define P4	0x10
#define P5	0x20
#define P6	0x40
#define P7	0x80
#define P8	0x100
#define P9	0x200
#define P10	0x400
#define P11	0x800
#define P12	0x1000
#define P13	0x2000
#define P14	0x4000
#define P15	0x8000
#define P16	0x10000
#define P17	0x20000
#define P18	0x40000
#define P19	0x80000
#define P20	0x100000
#define P21	0x200000
#define P22	0x400000
#define P23	0x800000
#define P24	0x1000000
#define P25	0x2000000
#define P27	0x8000000
#define P28	0x10000000
#define P29	0x20000000
#define P30	0x40000000
#define P31	0x80000000

/*******************************************************
 * Define types for access plain, on-the-metal memory or devices.
 *******************************************************/
typedef lpc_uint32  LPC_WORD;
typedef lpc_uint8   LPC_BYTE;
typedef lpc_uint16  LPC_WORD16;
typedef lpc_uint32  LPC_WORD32;
typedef lpc_uint64  LPC_WORD64;

typedef lpc_haladdress  LPC_ADDRESS;
typedef lpc_haladdrword LPC_ADDRWORD;

#endif 

/*
 * Copyright: 
 * ----------------------------------------------------------------
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 *   (C) COPYRIGHT 2000,2001 ARM Limited
 *       ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 * ----------------------------------------------------------------
 * File:     aptypes.h,v
 * Revision: 1.36
 * ----------------------------------------------------------------
 * 
 *  ----------------------------------------
 *  Version and Release Control Information:
 * 
 *  File Name              : aptypes.h.rca
 *  File Revision          : 1.2
 * 
 *  Release Information    : PrimeCell(TM)-GLOBAL-REL7v0
 *  ----------------------------------------
 *
 * Header file for standard macros and typedefs to be used across the project.
 * These definitions are based on (and referenced to) the 
 * ARM Software Systems C coding standard [SSB00 WKIN 0001 B]
 */

#ifndef APTYPES_H
#define APTYPES_H
#include "ams_types.h"

#ifdef __cplusplus
extern "C" { /* allow C++ to use these headers */
#endif /* __cplusplus */

/*
 * Description:
 * macros defining scope (section 5.1.1)
 */
#define PUBLIC              /*specifies an item of public API scope*/
#define PRIVATE static      /*item with scope limited to the module*/
#define PROTECTED           /*item has public scope but is not included in the API*/

/*
 * Description:
 * Further keywords (section 5.1.2)
 */
#define PACKED __packed     /*defines a packed structure*/
#define INLINE __inline     /*specifies a routine to be in line*/
#define CONST  const        /*defines a constant item*/

/*
 * Description:
 * specification of primitive types (section 5.1.3)
 */
typedef bool_t  BOOL;          //Primitive type - Boolean variable
typedef sint8   BYTE8;         //Primitive type - signed byte variable
typedef uint8   UBYTE8;        //Primitive type - unsigned byte variable
typedef sint16  HWD16;         //Primitive type - half word variable
typedef sint32  WORD32;        //Primitive type - (32 bit) word variable
typedef uint16  UHWD16;        //Primitive type - unsigned half word variable
typedef uint32  UWORD32;       //Primitive type - unsigned (32 bit) word variable

/*
 * Description:
 * specification of additional constants (section 5.1.4)
 */
/*warning of incompatible definitions*/
#if defined(TRUE) && (TRUE != 1)
#error "TRUE previously defined not equal to 1"
#endif 
#if defined(FALSE) && (FALSE != 0)
#error "FALSE previously defined not equal to 0"
#endif 

#ifndef TRUE 
#define TRUE  (1)
#endif
#ifndef FALSE 
#define FALSE (0)
#endif
#define aNULL (void *) 0        /*a null data pointer */
#define aRNULL aNULL            /*a null pointer to a routine*/

/*
 * Description:
 * additional macros (section 5.1.5)
 */
#define IGNORE(_v) ((void)(_v))     /*indicates that the parameter is not used (for expansion)*/

/*
 * Description:
 * Inline functions implemented as macros.  Not included in the standard
 */
/*The larger of __x and __y*/
#define MAX(__x,__y) ((__x)>(__y)?(__x):(__y))
/*The smaller of __x and __y*/
#define MIN(__x,__y) ((__x)<(__y)?(__x):(__y)) 

/*
 * Description:
 * Debug macros.  Not included in the current release of the standard
 *
 * Implementation:
 * The debug macros are controlled as follows:
 * + apDEBUG - if this is not defined, all debugs are disabled
 * + apDEBUG_LEVEL - this may be:
 *      - undefined / 0 : all debug macros used
 *      - 1 : only warning/critical debug macros enabled
 *      - 2 : only critical debug macros enabled
 * + apSDK_DEBUG_BUFFER - if this is defined, debugs are written to a buffer.  Otherwise,
 *   debug data is written to stderr.  If a debug buffer is used, the following variables
 *   MUST be declared in a source file.
 *      - PUBLIC  int apDEBUG_Counter=0;
 *      - PUBLIC  char  apDEBUG_Working[apDEBUG_PRINTF_MAX];
 *      - PUBLIC  char  apDEBUG_Buffer[SDK_DEBUG_BUFFER_SIZE]="<#>";
 * + SDK_DEBUG_BUFFER_SIZE - if a debug buffer is used, this defines the size (default 1024).
 * + apDEBUG_PRINTF_MAX - if a debug buffer is used, this defines the largest size of a printf().
 *        There is no checking that this is not exceeded.  (default 128)
 *
 * Remarks:
 * The macros are as follows:
 * + apDEBUG_ENABLED - this constant is used internally.  If defined, the code is running in debug mode.
 * + apDEBUG_INFO(__s,__d) - Used to output debug information.  The two arguments are passed
 *   to printf.  Typical usage: apDEBUG_INFO("Current status: %x\n",StatusWord);
 * + apDEBUG_WARN(__s,__d) - Used to output warning information.  The two arguments are passed
 *   to printf.
 * + apDEBUG_CRIT(__s,__d) - Used to output critical information.  The two arguments are passed
 *   to printf.
 *
 * When a buffer is specified, the data is written into the buffer.  Data is written into consecutive
 * locations in the buffer, returing to the start if the buffer is full.  No debug message is ever
 * split, although a long message may be truncated by the end of the buffer.  The end of the latest
 * message is marked by the token '<#>'.
*/
#ifndef apDEBUG
    #undef  apDEBUG_ENABLED
    #ifndef apASSERT
        #define apASSERT(__x)
    #endif
    #define apDEBUG_INFO(__s,__d)
    #define apDEBUG_WARN(__s,__d)
    #define apDEBUG_CRIT(__s,__d)
#else
    #ifndef apDEBUG_ENABLED
        #define apDEBUG_ENABLED 1
    #endif
    #define apDEBUG_MODE
    #ifndef assert
        #include <assert.h>
    #endif
    #include <stdio.h>
    #include <string.h>
    #define apASSERT(__x)               assert(__x)
    #ifdef apSDK_DEBUG_BUFFER
        #ifndef SDK_DEBUG_BUFFER_SIZE
            #define SDK_DEBUG_BUFFER_SIZE 1024
        #endif
        #ifndef apDEBUG_PRINTF_MAX
            #define apDEBUG_PRINTF_MAX 128
        #endif
        #define apDEBUG_PRINT(__s,__d)  { \
                                      /*reference the external variables*/ \
                                      extern  WORD32 apDEBUG_Counter; \
                                      extern  char  apDEBUG_Working[apDEBUG_PRINTF_MAX]; \
                                      extern  char  apDEBUG_Buffer[SDK_DEBUG_BUFFER_SIZE]; \
                                      UWORD32 CopySize;                  /*bytes to copy*/ \
                                      UWORD32 CopyPtr;                   /*pointer when copying*/ \
                                      sprintf(apDEBUG_Working,__s,__d);  /*do the printf*/ \
                                      /*wrap the buffer if required*/ \
                                      if (apDEBUG_Counter > SDK_DEBUG_BUFFER_SIZE - (apDEBUG_PRINTF_MAX<<1)) \
                                        {/*clear the rest of the buffer*/ \
                                        for (CopyPtr=apDEBUG_Counter;CopyPtr<SDK_DEBUG_BUFFER_SIZE-1;CopyPtr++) \
                                              {apDEBUG_Buffer[CopyPtr]='\0';} \
                                        apDEBUG_Counter=0;}             /*reset the pointer*/ \
                                      /*restrict to available bytes*/ \
                                      CopySize = MIN(strlen(apDEBUG_Working), SDK_DEBUG_BUFFER_SIZE - apDEBUG_Counter - 3 ); \
                                      /*copy to buffer, substituting '|' for '\n'*/ \
                                      for (CopyPtr=0;CopyPtr<CopySize;CopyPtr++) \
                                        {apDEBUG_Buffer[apDEBUG_Counter++]= \
                                         (char) ((apDEBUG_Working[CopyPtr]!='\n') ? apDEBUG_Working[CopyPtr] : '|') ;} \
                                      strcpy(&apDEBUG_Buffer[apDEBUG_Counter],"<#>"); /*mark the end*/ \
                                      }
    #else
        /*we don't generate printfs during ISRs*/
        #define apDEBUG_PRINT(__s,__d)  {if (apOS_CoreIRQGet()) fprintf(stderr,__s,__d);}
    #endif
    #if !defined(apDEBUG_LEVEL) || (apDEBUG_LEVEL == 0)
        #define apDEBUG_INFO(__s,__d)   {apDEBUG_PRINT(__s,__d);}
    #else
        #define apDEBUG_INFO(__s,__d)   
    #endif
    #if !defined(apDEBUG_LEVEL) || (apDEBUG_LEVEL <= 1)
        #define apDEBUG_WARN(__s,__d)   {apDEBUG_PRINT(__s,__d);}
    #else
        #define apDEBUG_WARN(__s,__d)   
    #endif
    #define apDEBUG_CRIT(__s,__d)       {apDEBUG_PRINT(__s,__d);}
#endif

/*
 * Description:
 * General function types
 */
typedef void (*apTYPE_rCallback) (UWORD32); /* general purpose callback for handling errors etc. */

#ifdef __cplusplus
} /* allow C++ to use these headers */
#endif /* __cplusplus */

#endif



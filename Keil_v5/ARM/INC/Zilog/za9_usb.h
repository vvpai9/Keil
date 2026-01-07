#ifndef __za9_usbdefines__
#define __za9_usbdefines__

/*******************************************************************************
** File          : $HeadURL$ 
** Author        : $Author$
** Project       : HSCTRL 
** Instances     : 
** Creation date : 
********************************************************************************
********************************************************************************
** ChipIdea Microelectronica - IPCS
** TECMAIA, Rua Eng. Frederico Ulrich, n 2650
** 4470-920 MOREIRA MAIA
** Portugal
** Tel: +351 229471010
** Fax: +351 229471011
** e_mail: chipidea.com
********************************************************************************
** ISO 9001:2000 - Certified Company
** (C) 2005 Copyright Chipidea(R)
** Chipidea(R) - Microelectronica, S.A. reserves the right to make changes to
** the information contained herein without notice. No liability shall be
** incurred as a result of its use or application.
********************************************************************************
** Modification history:
** $Date$
** $Revision$
*******************************************************************************
*** Description:      
***  This file contains ARM-specific defines. The file is solely for compilations
*** and most customers will need to redfine the code in this file and in arm.c to
*** make it work on their system.
***                                                               
**************************************************************************
**END*********************************************************/

/*--------------------------------------------------------------------------*/
/*
**                            STANDARD TYPES
*/

/*
**  The following typedefs allow us to minimize portability problems
**  due to the various C compilers (even for the same processor) not
**  agreeing on the sizes of "int"s and "short int"s and "longs".
*/
#include "bsp_types.h"
#include "bsp_int.h"

#define _PTR_      *
#define _CODE_PTR_ *

typedef char _PTR_                    char_ptr;    /* signed character       */
typedef unsigned char  uchar, _PTR_   uchar_ptr;   /* unsigned character     */

typedef signed   char   int_8, _PTR_   int_8_ptr;   /* 8-bit signed integer   */
typedef unsigned char  uint_8, _PTR_   uint_8_ptr;  /* 8-bit signed integer   */

typedef          short int_16, _PTR_   int_16_ptr;  /* 16-bit signed integer  */
typedef unsigned short uint_16, _PTR_  uint_16_ptr; /* 16-bit unsigned integer*/

typedef          long  int_32, _PTR_   int_32_ptr;  /* 32-bit signed integer  */
typedef unsigned long  uint_32, _PTR_  uint_32_ptr; /* 32-bit unsigned integer*/

typedef unsigned long  boolean;  /* Machine representation of a boolean */

typedef void _PTR_     pointer;  /* Machine representation of a pointer */

/* IEEE single precision floating point number (32 bits, 8 exponent bits) */
typedef float          ieee_single;

/* IEEE double precision floating point number (64 bits, 11 exponent bits) */
typedef double         ieee_double;

#define  OTG_INTERRUPT_ROUTINE_KEYWORD 
#define DEVICE_INTERRUPT_ROUTINE_KEYWORD
#define HOST_INTERRUPT_ROUTINE_KEYWORD

#define  INTERRUPT_ROUTINE_KEYWORD OTG_INTERRUPT_ROUTINE_KEYWORD
#define  USB_release_isr BSP_INT_Release


/*--------------------------------------------------------------------------*/
/*
**                          STANDARD CONSTANTS
**
**  Note that if standard 'C' library files are included after types.h,
**  the defines of TRUE, FALSE and NULL may sometimes conflict, as most
**  standard library files do not check for previous definitions.
*/
#if 0
#ifdef  FALSE
   #undef  FALSE
#endif
#define FALSE ((boolean)0)

#ifdef  TRUE
   #undef  TRUE
#endif
#define TRUE ((boolean)1) 

#ifdef  NULL
   #undef  NULL
#endif

#ifdef __cplusplus
   #define NULL (0)
#else
   #define NULL ((pointer)0)
#endif

typedef  uint_32  VUSB_REGISTER;

#endif 

#if 0


// Not required for ZA9L 

#define  ARC_JMP_TO_ADDR_INSTRN              ((uint_32)(0x381F0000))

#endif 


#define  BSP_VUSB11_HOST_BASE_ADDRESS0       (0xFFFBD080)
#define  BSP_VUSB11_HOST_VECTOR0             (INTNUM_USB0)
#define  BSP_VUSB11_DEVICE_BASE_ADDRESS0     (0xFFFBD080)
#define  BSP_VUSB11_DEVICE_VECTOR0           (INTNUM_USB0)
#define  BSP_VUSB11_OTG_BASE_ADDRESS0        (0xFFFBD080)
#define  BSP_VUSB11_OTG_VECTOR0              (INTNUM_USB0)
#define  BSP_VUSB11_OTG_USB_OFFSET           (0x70)


// =============================================================================

/*
 * USB Controller register offsets
 */
#define USB_ADD_INFO          0x0C
#define USB_OTG_INT_STAT      0x10
#define USB_OTG_INT_EN        0x14
#define USB_OTG_STAT          0x18
#define USB_OTG_CTRL          0x1C
#define USB_INT_STAT          0x80
#define USB_INT_ENB           0x84
#define USB_ERR_STAT          0x88
#define USB_ERR_ENB           0x8C
#define USB_STAT              0x90
#define USB_CTRL              0x94
#define USB_ADDR              0x98
#define USB_PAGE_01           0x9C
#define USB_FRM_NUML          0xA0
#define USB_FRM_NUMH          0xA4
#define USB_TOKEN             0xA8
#define USB_SOF_THLD          0xAC
#define USB_PAGE_02           0xB0
#define USB_PAGE_03           0xB4
#define USB_ENDPT_CTRL        0xC0

// =============================================================================


/* The ARC is little-endian, just like USB */
#define USB_uint_16_low(x)                   ((x) & 0xFF)
#define USB_uint_16_high(x)                  (((x) >> 8) & 0xFF)

/*********************************************************
Data caching related macros
**********************************************************/
#ifdef _DATA_CACHE_
   #define USB_Uncached                 volatile _Uncached
#else
   #define USB_Uncached                 volatile
#endif
/* Macro for aligning the EP queue head to 32 byte boundary */
#define USB_MEM32_ALIGN(n)                   ((n) + (-(n) & 31))
#define USB_CACHE_ALIGN(n)               USB_MEM32_ALIGN(n) 


#ifndef __BSP__ 

// these things are not applicable for ZA9L 

#define PSP_CACHE_LINE_SIZE        (32)

#if PSP_CACHE_LINE_SIZE
#define PSP_MEMORY_ALIGNMENT       (PSP_CACHE_LINE_SIZE-1)
#else
#define PSP_MEMORY_ALIGNMENT       (3)
#endif

#define PSP_MEMORY_ALIGNMENT_MASK  (~PSP_MEMORY_ALIGNMENT)

#define _psp_set_aux(aux_reg,value) \
   _sr((unsigned)(value),(unsigned)(aux_reg))

#define _psp_get_aux(aux_reg) \
   (uint_32)_lr((unsigned)(aux_reg))

#define PSP_AUX_DC_IVDC                    (0x047)
#define PSP_AUX_DC_IVDL                    (0x04A)
#define PSP_AUX_DC_FLDL                    (0x04C)
#define PSP_AUX_DC_CTRL_FLUSH_STATUS       (0x00000100)
#define PSP_AUX_DC_CTRL                    (0x048)

#endif 


#define  OTG_INTERRUPT_ROUTINE_KEYWORD 
#define DEVICE_INTERRUPT_ROUTINE_KEYWORD
#define HOST_INTERRUPT_ROUTINE_KEYWORD

#define  INTERRUPT_ROUTINE_KEYWORD OTG_INTERRUPT_ROUTINE_KEYWORD


#define  VUSB_ARC_BDT_OUT_BIT                (0x10)
#define  VUSB_ARC_BDT_IN_BIT                 (0x00)
#define  VUSB_ARC_BDT_ODD_EVEN_BIT           (0x08)

#define  VUSB_BDT_OUT_BIT                    (VUSB_ARC_BDT_OUT_BIT)
#define  VUSB_BDT_IN_BIT                     (VUSB_ARC_BDT_IN_BIT)
#define  VUSB_BDT_ODD_EVEN_BIT               (VUSB_ARC_BDT_ODD_EVEN_BIT)

#define  VUSB_GET_STATUS(BDT_ptr)            (BDT_ptr->PID & VUSB_BD_PID_MASKS)
#define  VUSB_GET_BYTE_COUNT(BDT_ptr)        (BDT_ptr->BC)
#define  VUSB_ENDPT_REG_OFFSET               (0x40)

#define  DISABLE_INTERRUPTS()                _ASM(".equ DI,0");\
                                             _ASM("flag DI")

#define  ENABLE_INTERRUPTS()                 _ASM(".equ EI,6");\
                                             _ASM("flag EI");

#ifdef __cplusplus
extern "C" {
#endif
#ifndef __USB_OS_MQX__
extern void USB_int_install_isr(uint_8, 
   INTERRUPT_ROUTINE_KEYWORD void (_CODE_PTR_ )(void), pointer);
extern void _disable_interrupts(void);
extern void _enable_interrupts(void);
#ifdef _DATA_CACHE_
void _dcache_invalidate(void);
void _dcache_invalidate_line(pointer);
/* void _dcache_flush_mlines(pointer, uint_32); */
void _dcache_flush_mlines(pointer, int);
void _dcache_flush_line(pointer);
/* void _dcache_invalidate_mlines(pointer, uint_32); */
void _dcache_invalidate_mlines(pointer, int);
#endif

#ifndef NO_DYNAMIC_MEMORY_ALLOCATION
void * USB_memalloc(uint_32 n);
void * USB_Uncached_memalloc(uint_32 n);
void  USB_memfree(void * aligned_ptr);
#endif

#endif
#ifdef __cplusplus
}
#endif
   
#endif

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
 * File:     apbitops.h,v
 * Revision: 1.17
 * ----------------------------------------------------------------
 * 
 *  ----------------------------------------
 *  Version and Release Control Information:
 * 
 *  File Name              : apbitops.h.rca
 *  File Revision          : 1.2
 * 
 *  Release Information    : PrimeCell(TM)-GLOBAL-REL7v0
 *  ----------------------------------------
 *
 * Header file for varied bit operation macros.  These are used
 * internally within the Primecell drivers.
 *
 */

#ifndef APBITOPS_H
#define APBITOPS_H

#ifdef    __cplusplus
extern "C" {    /* allow C++ to use these headers */
#endif    /* __cplusplus */

/*
 * Description:
 * Generic constant for accessing all bits in a 32 bit word
 */
#define apBITS_ALL 0xFFFFFFFF

/*
 * Description:
 * Functions for converting a little-endian word of byte or halfword data to
 * correct endian format.
 *
 * Implementation:
 * These are required since the FIFO order for the Primecells will not be reversed
 * to match a big endian system architecture
 *
 * These require the __BIG_ENDIAN constant to be defined for a big-endian system
 * (set automatically by ADS)
 *
 * The parameter is a word variable to be byte- or halfword- reversed.
 * The correct-endian data will be placed in the same variable
 */
#ifndef __BIG_ENDIAN
#define apBYTE_STREAM_ENDIAN_ADJUST(_w)
#define apHWD_STREAM_ENDIAN_ADJUST(_w)
#else
#ifndef __thumb
/*ARM code version*/
#define apBYTE_STREAM_ENDIAN_ADJUST(_w) {UWORD32 temp;         \
        const UWORD32 mask=0x00FF00FF,shift=8;                 \
        __asm{MOV temp,_w,ROR (32-shift);AND temp,temp,mask;   \
        MOV _w,_w,ROR shift;AND _w,_w,mask;ORR _w,_w,temp;}}
#define apHWD_STREAM_ENDIAN_ADJUST(_w) {const UWORD32 shift=16;__asm(MOV _w,_w,ROR shift);}
#else
/*Thumb code version*/
#define apBYTE_STREAM_ENDIAN_ADJUST(_w) {UWORD32 temp;         \
        const UWORD32 mask=0x00FF00FF,shift=8;                 \
        __asm{MOV temp,_w;ROR temp,(32-shift);AND temp,mask;   \
        ROR _w,shift;AND _w,mask;ORR _w,temp;}}
#define apHWD_STREAM_ENDIAN_ADJUST(_w) {const UWORD32 shift=16;__asm(ROR _w,shift);}
#endif
#endif

/*
 * ***************Standard data access set*******************
 * This set of macros accesses data using a width/shift parameter.
 * This assumes that constants bsXXX and bwXXX are defined, 
 *   where XXX is the value specified in the parameter.
 * + bwXXX is the number of bits to be accessed.
 * + bsXXX is the offset of the lowest bit.
 *
 */

/*
 * Description:
 * Build a mask for the specified bits
 *
 * Implementation:
 * __bws - a width/shift pair.
 * 
 * Returns  a mask with the bits to be addressed set and all others cleared
 * 
 */
#define apBIT_MASK(__bws) ((UWORD32)(((bw ## __bws)==32)?0xFFFFFFFF:((1U << (bw ## __bws)) - 1)) << (bs ## __bws))

/*
 * Description:
 * Clear the specified bits
 *
 * Implementation:
 * __datum - the word of data to be modified
 * __bws - a width/shift pair.
 * 
 */
#define apBIT_CLEAR(__datum, __bws) ((__datum) = ((__datum) & ~((UWORD32) apBIT_MASK(__bws))))

/*
 * Description:
 * Access the specified bits from a word of data at their original offset
 *
 * Implementation:
 * __datum - the word of data to be accessed
 * __bws - a width/shift pair.
 * 
 * Returns  The relevant bits masked from the data word, still at their original offset
 * 
 */
#define apBIT_GET_UNSHIFTED(__datum, __bws) (((__datum) & ((UWORD32) apBIT_MASK(__bws))))

/*
 * Description:
 * Access the specified bits from a word of data as an integer value
 *
 * Implementation:
 * __datum - the word of data to be accessed
 * __bws - a width/shift pair.
 * 
 * Returns  The relevant bits masked from the data word shifted to bit zero
 * 
 */
#define apBIT_GET(__datum, __bws) ((UWORD32)(((__datum) & ((UWORD32) apBIT_MASK(__bws))) >> (bs ## __bws)))

/*
 * Description:
 * Place the specified value into the specified bits of a word of data
 *
 * Implementation:
 * __datum - the word of data to be accessed
 * __bws - a width/shift pair.
 * __val - the data value to be shifted into the specified bits.
 * 
 */
#define apBIT_SET(__datum, __bws, __val) ((__datum) = ((UWORD32) (__datum) & (UWORD32)~(apBIT_MASK(__bws))) | \
                                        ((UWORD32) ((UWORD32)(__val) << (UWORD32)(bs ## __bws)) & (apBIT_MASK(__bws))))

/*
 * Description:
 * Place the specified value into the specified bits of a word of data
 * without reading first - for sensitive interrupt type registers
 *
 * Implementation:
 * __datum - the word of data to be accessed
 * __bws - a width/shift pair.
 * __val - the data value to be shifted into the specified bits.
 * 
 */
#define apBIT_SET_NOREAD(__datum, __bws, __val) (UWORD32) ((__datum) = (((__val) << (bs ## __bws)) & ((UWORD32) apBIT_MASK(__bws))))

/*
 * Description:
 * Shift the specified value into the desired bits
 *
 * Implementation:
 * __bws - a width/shift pair.
 * __val - the data value to be shifted into the specified bits.
 * 
 * Returns  The value shifted to the specified offset
 */
#define apBIT_BUILD(__bws, __val) ((UWORD32)(((UWORD32)(__val) << (UWORD32)(bs ## __bws)) & ((UWORD32) apBIT_MASK(__bws))))

/*
 * ***************'Field' data access set*******************
 * This set of macros accesses data using separate width and 
 * shift parameters.
 *
 */

/*
 * Description:
 * Equivalent to apBIT_MASK, but using separate width and 
 * shift parameters.
 *
 */
#define apBIT_MASK_FIELD(__bw, __bs) ((UWORD32)((((__bw)==32)?0xFFFFFFFF:(UWORD32)((UWORD32)1U << (__bw)) - 1)) << (__bs))

/*
 * Description:
 * Equivalent to apBIT_CLEAR, but using separate width and 
 * shift parameters.
 */
#define apBIT_CLEAR_FIELD(__datum, __bw, __bs) ((__datum) = ((__datum) & ~((UWORD32) apBIT_MASK_FIELD(__bw,__bs))))

/*
 * Description:
 * Equivalent to apBIT_GET, but using separate width and 
 * shift parameters.
 */
#define apBIT_GET_FIELD(__datum, __bw, __bs) ((UWORD32)(((__datum) & ((UWORD32) apBIT_MASK_FIELD(__bw,__bs))) >> (__bs)))

/*
 * Description:
 * Equivalent to apBIT_SET, but using separate width and 
 * shift parameters.
 */
#define apBIT_SET_FIELD(__datum, __bw, __bs, __val) ((__datum) = ((__datum) & ~((UWORD32) apBIT_MASK_FIELD(__bw,__bs))) | \
                                                    ((UWORD32) ((UWORD32)(__val) << (__bs)) & ((UWORD32) apBIT_MASK_FIELD(__bw,__bs))))

/*
 * Description:
 * Equivalent to apBIT_SET_NOREAD, but using separate width and 
 * shift parameters.
 */
#define apBIT_SET_FIELD_NOREAD(__datum, __bw,__bs, __val) (UWORD32) ((__datum) = (((__val) << (__bs)) & ((UWORD32) apBIT_MASK_FIELD(__bw,__bs))))

/*
 * Description:
 * Equivalent to apBIT_BUILD, but using separate width and 
 * shift parameters.
 */
#define apBIT_BUILD_FIELD(__bw, __bs, __val) ((UWORD32)(((__val) << (__bs)) & ((UWORD32) apBIT_MASK_FIELD(__bw,__bs))))

/*
 * Description:
 * Equivalent to apBIT_GET_UNSHIFTED, but using separate width and 
 * shift parameters.
 */
#define apBIT_GET_FIELD_UNSHIFTED(__datum, __bw, __bs) ((UWORD32)((__datum) & ((UWORD32) apBIT_MASK_FIELD(__bw,__bs))))

/*
 * Description:
 * Equivalent to apBIT_SET_FIELD, but with BYTE width parameters.
 */
#define apBYTE_SET_FIELD(__datum, __bw, __bs, __val) ((__datum) = (BYTE8) (((__datum) & ~(apBIT_MASK_FIELD(__bw,__bs))) | (((__val) << (__bs)) & (apBIT_MASK_FIELD(__bw,__bs)))))

#ifdef __cplusplus
} /* allow C++ to use these headers */
#endif    /* __cplusplus */

#endif



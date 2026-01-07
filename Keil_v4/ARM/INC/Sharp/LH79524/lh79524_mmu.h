/**********************************************************************
 * $Id:: lh79524_mmu.h 27 2007-08-31 19:35:06Z kevinw                  $
 *
 *  Project: LH79524 MMU controller header file
 *
 *  Description:
 *      This file contains the definition for MMU controller on 
 *      LH79524
 * 
 ***********************************************************************
 * Software that is described herein is for illustrative purposes only  
 * which provides customers with programming information regarding the  
 * products. This software is supplied "AS IS" without any warranties.  
 * NXP Semiconductors assumes no responsibility or liability for the 
 * use of the software, conveys no license or title under any patent, 
 * copyright, or mask work right to the product. NXP Semiconductors 
 * reserves the right to make changes in the software without 
 * notification. NXP Semiconductors also make no representation or 
 * warranty that such application will be suitable for the specified 
 * use without further testing or modification. 
 *********************************************************************/

#if !defined LH79524_MMU_H
#define LH79524_MMU_H

#include "lh79524_chip.h"

/**********************************************************************
 * MMU and CACHE
 * The coprocessor which controls the MMU and Cache is the
 * "System Control Coprocessor"
 *********************************************************************/

/***********************************************************************
 * System Control Coprocessor definitions
 * These symbols are used as arguments for the <coproc> parameter
 * in MCR and MRC instructions
 **********************************************************************/
/* cp 15 register */
#define SYS_CONTROL_CP          p15
/* cp 15 register */
#define MMU_CP                  p15
/* cp 15 register */
#define CACHE_CP                p15

/***********************************************************************
 * Valid CP15 Coprocessor Registers
 * These symbols are used as arguments for the <CRn> parameter
 * in MCR and MRC instructions
 **********************************************************************/
/* cp15 coprocessor registers - ID register */
#define MMU_REG_ID              c0
/* cp15 coprocessor registers - Control register */
#define MMU_REG_CONTROL         c1
/* cp15 coprocessor registers - TTB register */
#define MMU_REG_TTB             c2
/* cp15 coprocessor registers - DAC register */
#define MMU_REG_DAC             c3
/* cp15 coprocessor registers -  Fault status register */
#define MMU_REG_FAULT_STATUS    c5
/* cp15 coprocessor registers - Fault address register */
#define MMU_REG_FAULT_ADDRESS   c6
/* cp15 coprocessor registers - Cache register */
#define MMU_REG_CACHE_OPS       c7
/* cp15 coprocessor registers - TLB register */
#define MMU_REG_TLB_OPS         c8
/* cp15 coprocessor registers - FSCE register */
#define MMU_REG_FSCE_PID        c13
/* cp15 coprocessor registers - Trace register */
#define MMU_REG_TRACE_PROCID    c13

/***********************************************************************
 * MMU Control Register Fields
 **********************************************************************/
/* These values may be used as conventional mask (or set) bits */ 
/* cp15 control register MMU  bit */
#define MMU_CONTROL_M           _BIT(0)
/* cp15 control register A bit */
#define MMU_CONTROL_A           _BIT(1)
/* cp15 control register Cache bit */
#define MMU_CONTROL_C           _BIT(2)
/* cp15 control register Write buffer bit */
#define MMU_CONTROL_W           _BIT(3)
/* cp15 control register S bit */
#define MMU_CONTROL_S           _BIT(8)
/* cp15 control register R bit */
#define MMU_CONTROL_R           _BIT(9)
/* cp15 control register V bit */
#define MMU_CONTROL_V           _BIT(13)

/* setting for cp15 control register bit enable */
#define MMU_CONTROL_FIELD_ENABLE    1
/* setting for cp15 control register bit disable */
#define MMU_CONTROL_FIELD_DISABLE   0

/* bit field definition MMU enable */ 
#define MMU_ENABLE          _SBF(0,MMU_CONTROL_FIELD_ENABLE)
/* bit field definition MMU disable */ 
#define MMU_DISABLE         _SBF(0,MMU_CONTROL_FIELD_DISABLE)

/* bit field definiton - Alignment Fault Checking enable */ 
#define MMU_AFC_ENABLE      _SBF(1,MMU_CONTROL_FIELD_ENABLE)
/* bit field definiton - Alignment Fault Checking disable */ 
#define MMU_AFC_DISABLE     _SBF(1,MMU_CONTROL_FIELD_DISABLE)
/* bit field definition - Cache enable */ 
#define MMU_CACHE_ENABLE    _SBF(2,MMU_CONTROL_FIELD_ENABLE)
/* bit field definition - Cache disable */ 
#define MMU_CACHE_DISABLE   _SBF(2,MMU_CONTROL_FIELD_DISABLE)
/* bit field definition - Write Buffer enable */ 
#define MMU_WB_ENABLE       _SBF(3,MMU_CONTROL_FIELD_ENABLE)
/* bit field definition - Write Buffer disable */ 
#define MMU_WB_DISABLE      _SBF(3,MMU_CONTROL_FIELD_DISABLE)

/* bit field definition - Low Exception Vectors enable */ 
#define MMU_LOW_XVECTORS    _SBF(13,0)
/* bit field definition - High Exception Vectors enable */ 
#define MMU_HIGH_XVECTORS   _SBF(13,1)

/***********************************************************************
 * Domain Access Control Register Fields
 * There are 16 domains, 0 - 15
 **********************************************************************/
/* bit field definition - MMU domain access bit set as none */
#define MMU_DOMAIN_NONE     0
/* bit field definition - MMU domain access bit set as client */
#define MMU_DOMAIN_CLIENT   1
/* bit field definition - MMU domain access bit set as manager */
#define MMU_DOMAIN_MANAGER  3

/* The following macros may be used to set Domain Access Control */ 
/* The range of argument 'n' is 0 -15 */ 
/* bit field definition - MMU domain access bit set as none for few bits */
#define MMU_DOMAIN_NO_ACCESS(n)         (MMU_DOMAIN_NONE << ((n)*2))
/* bit field definition - MMU domain access bit set as client for few bits */
#define MMU_DOMAIN_CLIENT_ACCESS(n)     (MMU_DOMAIN_CLIENT << ((n)*2))
/* bit field definition - MMU domain access bit set as manager for few bits */
#define MMU_DOMAIN_MANAGER_ACCESS(n)    (MMU_DOMAIN_MANAGER << ((n)*2))

/***********************************************************************
 * Fault Status Register Fields
 **********************************************************************/
/* bit field definition - MMU fault status register set domain for few bits */
#define MMU_FSR_DOMAIN(n)   (((n)&0xF0) >> 4)
/* bit field definition - MMU fault status register set type for few bits */
#define MMU_FSR_TYPE(n)     ((n)&0x0F)

/***********************************************************************
 * Translation Table
 **********************************************************************/
/* constant - Number of entries in Translation Table */ 
#define TT_ENTRIES  4096
#define TT_SIZE     (TT_ENTRIES * 4)

/***********************************************************************
 * Page Table
 **********************************************************************/
/* constant - Number of entries in Page Table */ 
#define PT_ENTRIES  256
#define PT_SIZE     (PT_ENTRIES * 4)

/***********************************************************************
 * Level 1 Descriptor fields 
 * L1D_x fields apply to both section and page descriptor,
 * where applicable
 **********************************************************************/
/* level 1 descriptor fields - fault */
#define L1D_TYPE_FAULT     _SBF(0,0)
/* level 1 descriptor fields - type */
#define L1D_TYPE_PAGE      _SBF(0,0x11) /*includes compatibility bit 4*/
/* level 1 descriptor fields - section */
#define L1D_TYPE_SECTION   _SBF(0,0x12) /*includes compatibility bit 4*/
/* level 1 descriptor fields - bufferable */
#define L1D_BUFFERABLE     _BIT(2)
/* level 1 descriptor fields - cacheable */
#define L1D_CACHEABLE      _BIT(3)
/* Section AP field meaning depends on CP15 Control Reg S and R bits
 * See LH79520 User's Guide */ 
/* cp15 control AP field - supervisor only */
#define L1D_AP_SVC_ONLY    _SBF(10,1)
/* cp15 control AP field - user read only*/
#define L1D_AP_USR_RO      _SBF(10,2)
/* cp15 control AP field - all fields */
#define L1D_AP_ALL         _SBF(10,3)
/* cp15 control AP field - domain set few bits */
#define L1D_DOMAIN(n)      _SBF(5,((n)&0x0F))
/* cp15 control AP field - sec base address */
#define L1D_SEC_BASE_ADDR(n)    _SBF(20,((n)&0xFFF))

/***********************************************************************
 * Level 2 Descriptor fields 
 * L2D_x fields apply to both large page and small page descriptors,
 * where applicable.
 **********************************************************************/
/* level 2 descriptor fields - type fault */
#define L2D_TYPE_FAULT          _SBF(0,0)
/* level 2 descriptor fields - type large page */
#define L2D_TYPE_LARGE_PAGE     _SBF(0,1)
/* level 2 descriptor fields - type small page */
#define L2D_TYPE_SMALL_PAGE     _SBF(0,2)
/* level 2 descriptor fields - type bufferable */
#define L2D_BUFFERABLE          _BIT(2)
/* level 2 descriptor fields - type cacheable */
#define L2D_CACHEABLE           _BIT(3)
/* level 2 descriptor fields - supervisor mode only */
#define L2D_AP0_SVC_ONLY        _SBF(4,1)
/* level 2 descriptor fields - user read only mode  */
#define L2D_AP0_USR_RO          _SBF(4,2)
/* level 2 descriptor fields - ap0 all bits */
#define L2D_AP0_ALL             _SBF(4,3)
/* level 2 descriptor fields - ap1 supervisor mode only */
#define L2D_AP1_SVC_ONLY        _SBF(6,1)
/* level 2 descriptor fields - ap1 user read only mode */
#define L2D_AP1_USR_RO          _SBF(6,2)
/* level 2 descriptor fields - ap1 all bits */
#define L2D_AP1_ALL             _SBF(6,3)
/* level 2 descriptor fields - ap2 supervisor mode only */
#define L2D_AP2_SVC_ONLY        _SBF(8,1)
/* level 2 descriptor fields - ap2 user read only mode */
#define L2D_AP2_USR_RO          _SBF(8,2)
/* level 2 descriptor fields - ap2 all bits */
#define L2D_AP2_ALL             _SBF(8,3)
/* level 2 descriptor fields - ap3 supervisor mode only */
#define L2D_AP3_SVC_ONLY        _SBF(10,1)
/* level 2 descriptor fields - ap3 user mode read only */
#define L2D_AP3_USR_RO          _SBF(10,2)
/* level 2 descriptor fields - ap3 all bits */
#define L2D_AP3_ALL             _SBF(10,3)
/* level 2 descriptor fields - small page base address */
#define L2D_SPAGE_BASE_ADDR(n)  _SBF(12,((n)&0xFFFFF)
/* level 2 descriptor fields - large page base address */
#define L2D_LPAGE_BASE_ADDR(n)  _SBF(16,((n)&0xFFFF)

#endif /* LH79524_MMU_H */ 

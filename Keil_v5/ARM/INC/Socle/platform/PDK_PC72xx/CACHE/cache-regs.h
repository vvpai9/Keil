#ifndef __CACHE_REGS_H_INCLUDE
#define __CACHE_REGS_H_INCLUDE

#include <type.h>
#include <io.h>
#include <platform.h>

/*	CACHE dependence	*/


#ifndef SOCLE_CACHE_CTRL_BASE
#define SOCLE_ARM7_CACHE_BASE	-1
#else
#define SOCLE_ARM7_CACHE_BASE	SOCLE_CACHE_CTRL_BASE
#endif


/*
 *  Registers
 *  */
#define CACHE_DEVID				0x0000
#define CACHE_CACHEOP			0x0004
#define CACHE_LKDN				0x0008
#define CACHE_MEMMAP_BASE		0x0010
#define CACHE_MEMMAPA		 	0x0010
#define CACHE_MEMMAPB			0x0014
#define CACHE_MEMMAPC			0x0018
#define CACHE_MEMMAPD			0x001C
#define CACHE_MEMMAP_OFFSET		0x4       

static inline void 
socle_cache_write(u32 reg, u32 value) 
{
		//iowrite32(value, base+reg);
		writew(value, (SOCLE_ARM7_CACHE_BASE + reg));
}

static inline u32
socle_cache_read(u32 reg)
{
		//ioread32(base+reg);
		return readw(SOCLE_ARM7_CACHE_BASE + reg);
}

//#define INVALID_WAY_SHIFT	31
#define CACHELINESIZE		32				// 8 WORDS Cache Line Size
#define CACHE_ENABLE		(1 << 31)
#define CACHE_DISABLE		0

/*
 *  CACHE_DEVID
 *  */
/* Global Cache Enable -rw */
#define CACHE_GLOBAL_CACHE_ENABLE (1 << 31)
#define CACHE_GLOBAL_CACHE_DISABLE 0

/* Cache Size -ro */
#define CACHE_SIZE_S			8
#define CACHE_SIZE_M			0x3   
#define CACHE_SIZE()			(readw(CACHE_DEVID) >> CACHE_SIZE_S & CACHE_SIZE_M)
#define CACHE_SIZE_4KB			0	/* 4KB */
#define CACHE_SIZE_8KB			1 	/* 8KB */
#define CACHE_SIZE_16KB			2   /* 16KB */
#define CACHE_SIZE_32KB			3   /* 32KB */

/* 2-Way associative -ro */
/* 8-word cache line size -ro */

/*
 *  CACHE_CACHEOP
 *  */
/* Loop-up address for cache op -rw */
#define CACHE_INVALIDATE_ENTRY_ADDR(x) (x & ~3)
#define CACHE_INVALIDATE_WAY(x) ((x & 1) << 31)

/* Cache Opcode */
#define CACHE_OP_NOP 0
#define CACHE_OP_INVALIDATE_SINGLE_ENTRY 1
#define CACHE_OP_INVALIDATE_WAY 2

#define Inval_autoclr		0x0
#define InvalEntry			0x1
#define InvalWay			0x2
/*
 *  CACHE_CACHELKDN
 *  */
/* Lock wawy selection */
#define CACHE_WAY_NOLOCK 0
#define CACHE_WAY_LOCK_WAY0 1
#define CACHE_WAY_LOCK_WAY2 2

/*
 *  CACHE_MEMMAP
 *  */
/* UNCACHE SIZE */
#define CACHE_MASK_32MB		0xFE
#define CACHE_MASK_64MB		0xFC
#define CACHE_MASK_128MB	0xF8

#endif

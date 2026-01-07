#ifndef _CACHE_CTRL_H_
#define _CACHE_CTRL_H_

#include <type.h>

//  for ARM7 cache test
extern int CacheTesting(int autotest);

//write_to_memory ,  size : Words
static void write_to_memory(u32 address,u32 pattern,u32 size);

//clear cache
static void clear_cache(void);
static void clear_memory(u32 address,u32 size);
static void invalidate_all_way(void);

// bank_size : Words
static int pattern_compare(u32 start,u32 bank_size,WORD pattern);

//line_fill
static void line_fill(u32 start,u32 bank_size);

#endif // _CACHE_CTRL_H_

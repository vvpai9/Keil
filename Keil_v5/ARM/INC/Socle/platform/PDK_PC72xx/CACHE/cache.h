#ifndef _CACHE_API_INCLUDE_
#define _CACHE_API_INCLUDE_

//lock down way 
#define CACHE_API_LOCK_NOLOCK		0
#define CACHE_API_LOCK_WAY0			1 
#define CACHE_API_LOCK_WAY1			2

//map index for uncache memory 
#define CACHE_API_MAPA		0
#define CACHE_API_MAPB		1
#define CACHE_API_MAPC		2
#define CACHE_API_MAPD		3

//map size
#define CACHE_API_MAP32MB	0
#define CACHE_API_MAP64MB	1
#define CACHE_API_MAP128MB	2

//invalidate way
#define INVALID_WAY0	0 
#define INVALID_WAY1	1

//wait_status
#define STS_WAIT		0 
#define STS_UNWAIT		1


//CACHE enable / disable
extern void set_cache_enable(void);			
extern void set_cache_disable(void);

//set uncache memory map ,	start_addr : [31:25] valid	
extern void cahce_set_uncache_map(int map_index, u32 start_addr, u32 map_size);

//invalidate entry	: entry_start_addr_array & entry_count
extern int cache_invalidate_entry(u32 address,int range,int status_wait);	//wait_status 1:wait for status autocleared  0:not wait

//invalidate way
extern int cache_invalidate_way(int invalid_way);

//cache lockdown
extern void cache_lockdown(int lock_way);	

//get cache size, return cache size(bytes)
extern u32 get_cache_size(void);

#endif 



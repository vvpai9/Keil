#ifndef __CLOCK_H_INCLUDED
#define __CLOCK_H_INCLUDED

#ifdef CONFIG_PC7210
#include <scu.h>
#else
extern int socle_get_cpu_clock (void);
extern int socle_get_ahb_clock (void);
extern int socle_get_apb_clock (void);
#endif

#endif

/***********************************************************************
 * $Id:: sdk7a404_cf_fat.h 14 2007-08-28 16:08:18Z kevinw              $
 *
 * Project: SDK-LH7A404 CF FAT wrapper
 *
 * Description:
 *     This file contains the wrapper for SDK-LH7A404 CF FAT.
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
 **********************************************************************/

#ifndef SDKLH7A404_CF_FAT_H
#define SDKLH7A404_CF_FAT_H

#include "lpc_types.h"

INT_32 wrap_init_func(void);
void wrap_shutdown_func(void);
STATUS wrap_insert_ck_func(void);
STATUS wrap_ready_ck_func(void);
STATUS wrap_busy_ck_func(void);
void wrap_set_sector_func(UNS_32 dat);
void wrap_start_read_func(void);
void wrap_start_write_func(void);
INT_32 wrap_read_func(UNS_8 *buf, UNS_32 num);
INT_32 wrap_write_func(UNS_8 *buf, UNS_32 num);

#endif // SDKLH7A404_CF_FAT_H

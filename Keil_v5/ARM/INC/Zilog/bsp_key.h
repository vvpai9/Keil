/*
 * Copyright 2008, ZiLOG Inc.
 * All Rights Reserved
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of ZiLOG Inc., and might
 * contain proprietary, confidential and trade secret information of
 * ZiLOG, our partners and parties from which this code has been licensed.
 * 
 * The contents of this file may not be disclosed to third parties, copied or
 * duplicated in any form, in whole or in part, without the prior written
 * permission of ZiLOG Inc.
 */
#ifndef _BSP_KEY_H_
#define _BSP_KEY_H_

#include "bsp_types.h"
#include "bsp_utils.h"
#include "bsp_tmr.h"


#define BSP_KEY_MAX_ROWS               5


/*
 * Identifies which push button keys to include when scanning.
 */
#define BSP_KEY_MASK                   (BIT5 | BIT4 | BIT3 | BIT2 | BIT1)


/*
 * Key mapping for 5 push button keys on the application board (SW2 to SW6)
 */
#define BSP_KEY_SW2                    BIT1
#define BSP_KEY_SW3                    BIT2
#define BSP_KEY_SW4                    BIT3
#define BSP_KEY_SW5                    BIT4
#define BSP_KEY_SW6                    BIT5


#define DEFAULT_SCAN_PERIOD_MS         20
#define KEY_DEBOUNCE_COUNT             3


typedef struct             BSP_KEY_S
{
   BSP_SEM                 IsIdle;        // If 1, Start has not been called
   UINT32                  ScanPeriod_ms; // ms bewteen key scans               
   UINT32                  MissedKeys;    // Counts number of missed key presses
   UINT32                  GpioMask;      // GPIO bits required for key scan
   UINT32                  RawScan;       // Scan code available in List callback
   void               (*   pIsrFunc)      // Upper-layer callback when key detected
   (                                      // callback parameters      
      struct BSP_KEY_S   * pKey           // KEY reference
   );      
   BSP_TIMER             * pTmr;          // HW timer used for Key scan

} BSP_KEY;

typedef void (* KEY_ISR_FUNC )( BSP_KEY * pKey ); 


/*
 * Key scan mapping table
 */
extern UINT32              KeyTable[5];



/*
 * Function Prototypes
 */
extern BSP_STATUS BSP_KEY_Init(    void );
extern UINT32     BSP_KEY_Scan(    UINT32 KeyMask );
extern UINT32     BSP_KEY_Decode(  UINT32 KeyCode );
extern BSP_KEY  * BSP_KEY_Acquire( KEY_ISR_FUNC pKeyFunc );
extern BSP_STATUS BSP_KEY_Release( BSP_KEY * pKey );
extern BSP_STATUS BSP_KEY_Start(   BSP_KEY * pKey );
extern BSP_STATUS BSP_KEY_Stop(    BSP_KEY * pKey );
extern BSP_STATUS BSP_KEY_Read(    BSP_KEY * pKey, UINT32 * pScanCode );



#endif

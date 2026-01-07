/******************** (C) COPYRIGHT 2005 STMicroelectronics ********************
* File Name          : lowpower.h
* Author             : MCD Application Team
* Date First Issued  : 09/27/2005 :  V1.0
* Description        : Header for the lowpower.c file.
********************************************************************************
* History:
* 09/27/2005 :  V1.0
********************************************************************************
 THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS WITH
 CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
 AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
 OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __LOWPOWER_H
#define __LOWPOWER_H

/* Includes ----------------------------------------------------------------- */
#include "73x_lib.h"

/* Exported types ----------------------------------------------------------- */
/* Exported constants ------------------------------------------------------- */
/* Module private variables ------------------------------------------------- */
/* Exported variables ------------------------------------------------------- */
/* Exported macros ---------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */
void EnterStopMode(void);
void EnterStopMode_WUT(void);
void EnterHALTMode(void);
void SetClockTo32(void);
void SetClockTo16(void);
void SetClockTo8(void);
void SetClockTo2(void);
void SetClockTo4(void);

#endif /* __LOWPOWER_H */

/******************* (C) COPYRIGHT 2005 STMicroelectronics *****END OF FILE****/


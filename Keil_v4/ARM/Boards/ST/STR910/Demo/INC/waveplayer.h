/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : waveplayer.h
* Author             : MCD Application Team
* Date First Issued  : 05/18/2006 : Version 1.0
* Description        : This file contains all the functions prototypes for the
*                      wave player software driver.
********************************************************************************
* History:
* 05/24/2006 : Version 1.1
* 05/18/2006 : Version 1.0
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/
/* Define to prevent recursive inclusion ---------------------------------------*/
#ifndef __WAVEPLAYER_H
#define __WAVEPLAYER_H

/* Includes --------------------------------------------------------------------*/
#include "91x_lib.h"

/* Exported types --------------------------------------------------------------*/
/* Exported constants ----------------------------------------------------------*/
/* Exported macro --------------------------------------------------------------*/
/* Exported functions ----------------------------------------------------------*/
void WavePlayer_Init(void);
void WavePlayer_Start(void);
void WavePlayer_Stop(void);
void WavePlayerAlarm_Start(void);
void WavePlayerAlarm_Stop(void);
#endif /*__WAVEPLAYER_H */

/******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE******/

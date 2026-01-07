/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : lowpower.h
* Author             : MCD Application Team
* Version            : V1.1.1
* Date               : 06/13/2008
* Description        : This file contains all the functions prototypes for the
*                      low power firmware driver.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LOWPOWER_H
#define __LOWPOWER_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void LowPower_Init(void);
void SYSCLKConfig_STOP(void);
void EnterSTOPMode_EXTI(void);
void EnterSTOPMode_RTCAlarm(void);
void EnterSTANDBYMode_WAKEUP(void);
void EnterSTANDBYMode_RTCAlarm(void);
void Set_STOPModeStatus(void);

#endif /* __LOWPOWER_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/

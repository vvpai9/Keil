/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : main.h
* Author             : MCD Application Team
* Date First Issued  : 05/18/2006 : Version 1.0
* Description        : Header for main.c module
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
********************************************************************************/

/* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __MAIN_H
#define __MAIN_H

/* includes ------------------------------------------------------------------*/
#include "lcd.h"
#include "menu.h"
#include "joystickHID.h"
#include "calendar.h"
#include "waveplayer.h"
#include "can.h"
#include "webserver.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Demo_Init(void);
void SystemTimer_Init(void);
void LedShow_Init(void);
void LedShow(FunctionalState NewState);
void PlayIntro(void);

#endif /* __MAIN_H */

/******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****/



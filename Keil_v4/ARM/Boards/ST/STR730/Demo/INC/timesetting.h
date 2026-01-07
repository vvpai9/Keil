/******************** (C) COPYRIGHT 2005 STMicroelectronics ********************
* File Name          : timesetting.h
* Author             : MCD Application Team
* Date First Issued  : 09/27/2005 :  V1.0
* Description        : Header for the timesetting.c file.
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
#ifndef __TIMESETTING_H
#define __TIMESETTING_H

/* Includes ------------------------------------------------------------------*/
#include "73x_lib.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Module private variables --------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
u8 ReadDigit(u8 ColBegin, u8 CountBegin, u8 ValueMax, u8 ValueMin) ;
void Time_Init(void) ;
u32 Time_Regulate(void) ;
void Time_Adjust(void) ;
void Time_Show(void) ;
void Time_Display(u32 TimeVar, u8 Col , u8 Row) ;
void Date_Regulate(void) ;
void Date_Adjust(void) ;
void Date_Display(u8 Col, u8 Row, u8 Type) ;
void Date_Show(void) ; 
void Date_Update(void) ;
void Alarm_Adjust(void) ;
void Alarm_Show(void) ;
u32 Alarm_Regulate(void); 
void Alarm_Display(u32 AlarmVar, u8 Col , u8 Row);
void ScreenSaver_Init(void);
void ScreenSaver_Show(void);

#endif /*__TIMESETTING_H */

/******************* (C) COPYRIGHT 2005 STMicroelectronics *****END OF FILE****/

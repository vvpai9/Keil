/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : calendar.h
* Author             : MCD Application Team
* Date First Issued  : 05/18/2006 : Version 1.0
* Description        : This file contains all the functions prototypes for the
*                      calendar software driver.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CALENDAR_H
#define __CALENDAR_H

/* Includes ------------------------------------------------------------------*/
#include "91x_lib.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
u8 ReadDigit(u8 ColBegin, u8 CountBegin, u8 ValueMax, u8 ValueMin) ;
void Calendar_Init(void);
void Time_Regulate(void);
void Time_Adjust(void);
void Time_Show(void);
void Time_Display(void);
void Date_Regulate(void);
void Date_Adjust(void);
void Date_Display(void);
void Date_Show(void);
void Date_Update(void);
u16 DayOfWeek(u16 nYear, u16 nMonth, u16 nDay);
u16 CountOfFeb29(u16 nYear);
bool IsLeapYear(u16 nYear);
void Alarm_Regulate(void);
void Alarm_Adjust(void);
void Alarm_Display(void);
void Alarm_Show(void);

#endif /* __CALENDAR_H */

/******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****/

/******************** (C) COPYRIGHT 2005 STMicroelectronics ********************
* File Name          : temperature.h
* Author             : MCD Application Team
* Date First Issued  : 09/27/2005 :  V1.0
* Description        : Header for the temperature.c file.
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
#ifndef __TEMPERATURE_H
#define __TEMPERATURE_H

/* Includes ------------------------------------------------------------------*/
#include "73x_lib.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define Celsius  0
#define Fahrenheit  1

/* Module private variables --------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Converter_Init(void);
void Converter_DeInit(void);
void Send_digits(u16 temp, u8 Row, u8 Col);
void CelsiusDisplay(void);
void FahrenheitDisplay(void);
void Temperature_Display(void);

#endif /* __TEMPERATURE_H */

/******************* (C) COPYRIGHT 2005 STMicroelectronics *****END OF FILE****/


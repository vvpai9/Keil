/******************** (C) COPYRIGHT 2005 STMicroelectronics ********************
* File Name          : menu.h
* Author             : MCD Application Team
* Date First Issued  : 09/27/2005 :  V1.0
* Description        : Header for the menu.c file.
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
#ifndef __MENU_H
#define __MENU_H

/* Includes ------------------------------------------------------------------*/
#include "73x_lib.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define MAX_MENU_LEVELS 4
#define  NOKEY  0
#define  SEL    1 
#define  NXT    2
#define  PRV    3
#define  BACK   4

/* Module private variables --------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define countof(a) (sizeof(a) / sizeof(*(a)))

/* Private functions ---------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Menu_Init(void);
void DisplayMenu(void);
void NxtFunc(void);
void SelFunc(void);
void PrvFunc(void);
void BackFunc(void);
u8 ReadKey(void);
void IdleFunc(void);

#endif /* __MENU_H */

/******************* (C) COPYRIGHT 2005 STMicroelectronics *****END OF FILE****/



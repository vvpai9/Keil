/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : menu.h
* Author             : MCD Application Team
* Version            : V1.1.1
* Date               : 06/13/2008
* Description        : This file contains all the functions prototypes for the
*                      menu navigation firmware driver.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MENU_H
#define __MENU_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
#include "fsmc_nor.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define  MAX_MENU_LEVELS 4
#define  NOKEY  0
#define  SEL    1
#define  RIGHT  2
#define  LEFT   3
#define  UP     4
#define  DOWN   5
#define  KEY    6

#if STM3210E
#define ALARM_ICON    0x64FE0F54
#define USB_ICON      0x64FE8F96
#define WATCH_ICON    0x64FF0FD8
#define ST_LOGO       0x64F7FBFA
#define HELP          0x64FA543C
#define TSENSOR	      0x64FD8E4C
#else
#define ICONS         0x007A9D6A
#define ALARM_ICON    ICONS+0x162D6
#define USB_ICON      ICONS+0x1E318
#define WATCH_ICON    ICONS+0x2635A
#define SLIDES        0x0055194A
#define ST_LOGO       SLIDES+0x20D39C
#define HELP          SLIDES+0x232BDE
#define TSENSOR	      SLIDES+0x2665EE
#endif

/* Module private variables --------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define countof(a) (sizeof(a) / sizeof(*(a)))

/* Private functions ---------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Menu_Init(void);
void DisplayMenu(void);
void SelFunc(void);
void UpFunc(void);
void DownFunc(void);
void ReturnFunc(void);
u8 ReadKey(void);
void IdleFunc(void);
void DisplayIcons(void);
void ShowMenuIcons(void);
void STM32Intro(void);
void HelpFunc(void);
void AboutFunc(void);
void LCD_NORDisplay(u32 address);
void LCD_SPIDisplay(u32 address);
void STM32BannerFunc(void);
void ProductPres(void);
u32 CheckBitmapFiles(void);
void SmartCard_Start(void);
void STM32BannerSpeedFunc(void);
u32 Get_SmartCardStatus(void);
void Set_CardInserted(void);

#endif /* __MENU_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/

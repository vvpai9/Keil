/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : joystickHID.h
* Author             : MCD Application Team
* Date First Issued  : 05/18/2006 : Version 1.0
* Description        : This file contains all the functions prototypes for the
*                      joystick HID software driver.
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
#ifndef __JOYSTICKHID_H
#define __JOYSTICKHID_H

/* Includes ------------------------------------------------------------------*/
#include "91x_lib.h"
#include "USB_lib.h"
#include "USB_conf.h"
#include "USB_prop.h"
#include "USB_pwr.h"
#include "USB_mem.h"

#define Sel     1
#define Right	  2
#define Left	  3
#define Up      4
#define Down	  5
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void JoyStickHID_Init(void);
void Mouse_Send(BYTE Keys);
u8 JoyState(void);
void JoyStickHID_Start(void);

#endif /* __JOYSTICKHID_H */

/******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****/

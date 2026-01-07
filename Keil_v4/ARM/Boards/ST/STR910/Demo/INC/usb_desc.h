/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : usb_desc.h
* Author             : MCD Application Team
* Date First Issued  : 05/18/2006 : Version 1.0
* Description        : Descriptors for USB HID Mouse
********************************************************************************
* History:
* 05/24/2006 : Version 1.1
* 05/18/2006 : Version 1.0
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS WITH
* CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME. AS
* A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
* OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
* OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
* CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/


#define	MOUSE_SIZ_DEVICE_DESC	18
#define	MOUSE_SIZ_CONFIG_DESC	34
#define	MOUSE_SIZ_STRING_DESC	100

#define	MOUSE_SIZ_REPORT_DESC	0x4A
#define MOUSE_OFF_HID_DESC	18
#define MOUSE_SIZ_HID_DESC	9

extern const BYTE MOUSE_DeviceDescriptor[MOUSE_SIZ_DEVICE_DESC];
extern const BYTE MOUSE_ConfigDescriptor[MOUSE_SIZ_CONFIG_DESC];
extern const BYTE MOUSE_StringDescriptor[MOUSE_SIZ_STRING_DESC];
extern const BYTE MOUSE_ReportDescriptor[MOUSE_SIZ_REPORT_DESC];

/******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****/

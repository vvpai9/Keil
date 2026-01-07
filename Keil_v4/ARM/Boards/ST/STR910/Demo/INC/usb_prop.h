/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : usb_prop.h
* Author             : MCD Application Team
* Date First Issued  : 05/18/2006 : Version 1.0
* Description        : All processings related to Mouse device
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


/* HID descriptors */
typedef enum _HID_DESCRIPTOR_TYPE {
	HID_DESCRIPTOR = 0x21,
	REPORT_DESCRIPTOR,
	PHYSICAL_DESCRIPTOR
} HID_DESCRIPTOR_TYPE;

/* HID requests */
typedef enum _HID_REQUESTS {
	GET_REPORT = 1,
	GET_IDLE,
	GET_PROTOCOL,

	SET_REPORT = 9,
	SET_IDLE,
	SET_PROTOCOL
} HID_REQUESTS;

/* HID Report types*/
typedef enum _HID_REPORT_TYPE {
	INPUT_REPORT = 1,
	OUTPUT_REPORT,
	FEATURE_REPORT
} HID_REPORT_TYPE;

void MOUSE_init(void);
void MOUSE_Reset(void);
#define MOUSE_Status_In	NOP_Process
#define MOUSE_Status_Out	NOP_Process
RESULT MOUSE_Data_Setup(BYTE);
RESULT MOUSE_NoData_Setup(BYTE);
RESULT MOUSE_Get_Interface_Setting(BYTE Interface,BYTE AlternateSetting);
BYTE *MOUSE_GetDeviceDescriptor(WORD );
BYTE *MOUSE_GetConfigDescriptor(WORD);
BYTE *MOUSE_GetStringDescriptor(WORD);

/******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****/

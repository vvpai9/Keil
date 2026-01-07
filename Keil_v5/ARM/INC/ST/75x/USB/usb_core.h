/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : usb_core.h
* Author             : MCD Application Team
* Date First Issued  : 03/10/2006 : V0.1
* Description        : Standard protocol processing (USB v2.0)
********************************************************************************
* History:
* 03/10/2006 : V0.1
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT, 
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING 
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

#define Type_Recipient	(pInfo->USBbmRequestType & (REQUEST_TYPE | RECIPIENT))

typedef enum _CONTROL_STATE {
	WAIT_SETUP,  	/* 0 */
	SETTING_UP,  	/* 1 */
	IN_DATA,	 	/* 2 */
	OUT_DATA,		/* 3 */
	LAST_IN_DATA,	/* 4 */
	LAST_OUT_DATA,	/* 5 */
	//WAIT_IN_ZERO,	/* 6 */
	//WAIT_OUT_ZERO,	/* 7 */
	WAIT_STATUS_IN,	/* 8 */
	WAIT_STATUS_OUT,/* 9 */
	STALLED,		/* 10 */
	PAUSE			/* 11 */
} CONTROL_STATE;		/* The state machine states of a control pipe */

#define STD_MAXPACKETSIZE		0x08		/* Maximum packet size */

typedef struct OneDescriptor {
	BYTE *Descriptor;
	WORD Descriptor_Size;
} ONE_DESCRIPTOR, *PONE_DESCRIPTOR;
/* All the request process routines return a value of this type
   If the return value is not SUCCESS or NOT_READY,
   the software will STALL the correspond endpoint
*/
typedef enum _RESULT {
	USB_SUCCESS = 0,			/* Process sucessfully */
	USB_ERROR,
	UNSUPPORT,
	NOT_READY				/* The process has not been finished,		*/
							/* endpoint will be NAK to further rquest	*/
} RESULT;


/*-*-*-*-*-*-*-*-*-*-* Definitions for endpoint level -*-*-*-*-*-*-*-*-*-*-*-*/

typedef struct _ENDPOINT_INFO {
	/*
	When send data out of the device,
		CopyData() is used to get data buffer 'Length' bytes data
		if Length is 0,
			CopyData() returns the total length of the data
			if the request is not supported, returns 0
			(NEW Feature )
				if CopyData() returns -1, the calling routine should not proceed
				further and will resume the SETUP process by the class device
		if Length is not 0,
			CopyData() returns a pointer to indicate the data location
		Usb_wLength is the data remain to be sent,
		Usb_wOffset is the Offset of original data
	When receive data from the host,
		CopyData() is used to get user data buffer which is capable
		of Length bytes data to copy data from the endpoint buffer.
		if Length is 0,
			CopyData() returns the available data length,
		if Length is not 0,
			CopyData() returns user buffer address
		Usb_rLength is the data remain to be received,
		Usb_rPointer is the Offset of data buffer
	*/
	WORD		Usb_wLength;
	WORD		Usb_wOffset;
	WORD		PacketSize;
	BYTE 		*(*CopyData)(WORD Length);
} ENDPOINT_INFO;

#define Usb_rLength Usb_wLength
#define Usb_rOffset Usb_wOffset


/*-*-*-*-*-*-*-*-*-*-*-* Definitions for device level -*-*-*-*-*-*-*-*-*-*-*-*/

typedef struct _DEVICE {
/*sb	BYTE EP0;	*/			 /*	Endpoint number */
	BYTE Total_Endpoint;	 /* Number of endpoints that are used */
	BYTE Total_Configuration;/* Number of configuration available */
} DEVICE;

typedef union {
	WORD	w;
	struct BW {
		BYTE	bb1;
		BYTE	bb0;
	} bw;
} WORD_BYTE;

typedef struct _DEVICE_INFO {
	BYTE		USBbmRequestType;		/* bmRequestType */
	BYTE		USBbRequest;			/* bRequest */
	WORD_BYTE	USBwValues;				/* wValue */
	WORD_BYTE	USBwIndexs;				/* wIndex */
	WORD_BYTE	USBwLengths;			/* wLength */

	BYTE		ControlState;			/* of type CONTROL_STATE */
	BYTE		Current_Feature;

	BYTE		Current_Configuration;/* Selected configuration */
	BYTE		Current_Interface;   /* Selected interface of current configuration */
	BYTE		Current_AlternateSetting;/* Selected Alternate Setting of current interface*/
	BYTE		Supp_Remote_Wakeup;// Remote Wakeup indicator: 0 Remote Wakeup is not supported
					   //                          1 Remote Wakep is supported 
						
	ENDPOINT_INFO	Ctrl_Info;
} DEVICE_INFO;

typedef struct _DEVICE_PROP {
	void	(*Init)(void);				/* Initialize the device */
	void	(*Reset)(void);				/* Reset routine of this device */

	/*	Device dependent process after the status stage	*/
	void	(*Process_Status_IN)(void);
	void	(*Process_Status_OUT)(void);

	/* Procedure of process on setup stage of a class specified request with data stage */
	/*	All class specified requests with data stage are processed in Class_Data_Setup
		Class_Data_Setup()
			responses to check all special requests and fills ENDPOINT_INFO
			according to the request
			If IN tokens are expected, then wLength & wOffset will be filled
			with the total transferring bytes and the starting position
			If OUT tokens are expected, then rLength & rOffset will be filled
			with the total expected bytes and the starting position in the buffer

			If the request is valid, Class_Data_Setup returns USB_SUCCESS, else UNSUPPORT

		CAUTION:
			Since GET_CONFIGURATION & GET_INTERFACE are highly related to
			the individual classes, they will be checked and processed here.
	*/
	RESULT	(*Class_Data_Setup)(BYTE RequestNo);

	/* Procedure of process on setup stage of a class specified request without data stage */
	/*	All class specified requests without data stage are processed in Class_NoData_Setup
		Class_NoData_Setup
			responses to check all special requests and perform the request

		CAUTION:
			Since SET_CONFIGURATION & SET_INTERFACE are highly related to
			the individual classes, they will be checked and processed here.
	*/
	RESULT	(*Class_NoData_Setup)(BYTE RequestNo);

	/*Class_Get_Interface_Setting 
		This function is used by the file usb_core.c to test if the selected Interface 
		and Alternate Setting (BYTE Interface, BYTE AlternateSetting) are supported by 
		the application.
		This function is writing by user. It should return "USB_SUCCESS" if the Interface 
		and Alternate Setting are supported by the application or "UNSUPPORT" if they 
		are not supported. */
 
	RESULT  (*Class_Get_Interface_Setting)(BYTE Interface,BYTE AlternateSetting);

	BYTE*	(*GetDeviceDescriptor)(WORD Length);
	BYTE*	(*GetConfigDescriptor)(WORD Length);
	BYTE*	(*GetStringDescriptor)(WORD Length);

	BYTE*	RxEP_buffer;
	WORD	MaxPacketSize;

} DEVICE_PROP;

extern	DEVICE_PROP Device_Property;
extern  DEVICE  Device_Table;
extern	DEVICE_INFO	Device_Info;

/* cells saving status during interrupt servicing */
extern WORD SaveRState;
extern WORD SaveTState;

#define	USBwValue	USBwValues.w
#define	USBwValue0	USBwValues.bw.bb0
#define	USBwValue1	USBwValues.bw.bb1
#define	USBwIndex	USBwIndexs.w
#define	USBwIndex0	USBwIndexs.bw.bb0
#define	USBwIndex1	USBwIndexs.bw.bb1
#define	USBwLength	USBwLengths.w
#define	USBwLength0	USBwLengths.bw.bb0
#define	USBwLength1	USBwLengths.bw.bb1

BYTE Setup0_Process(void);
BYTE Post0_Process(void);
BYTE Out0_Process(void);
BYTE In0_Process(void);

RESULT Standard_SetEndPointFeature(void);
RESULT Standard_SetDeviceFeature(void);

BYTE *Standard_GetConfiguration(WORD Length);
RESULT Standard_SetConfiguration(void);
BYTE *Standard_GetInterface(WORD Length);
RESULT Standard_SetInterface(void);
BYTE *Standard_GetDescriptorData(WORD Length, PONE_DESCRIPTOR pDesc);
BYTE *Standard_GetStringDescriptor(WORD Length, PONE_DESCRIPTOR pDesc);

void SetDeviceAddress(BYTE);
void NOP_Process(void);

/******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****/


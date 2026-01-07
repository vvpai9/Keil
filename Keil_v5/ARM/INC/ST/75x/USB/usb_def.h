/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : usb_def.h
* Author             : MCD Application Team
* Date First Issued  : 03/10/2006 : V0.1
* Description        : Definitions related to USB
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


/* Definition of "USBbmRequestType" */
#define REQUEST_TYPE		0x60	/* Mask to get request type */
#define STANDARD_REQUEST	0x00	/* Standard request */
#define	CLASS_REQUEST		0x20	/* Class request */
#define	VENDOR_REQUEST		0x40	/* Vendor request */

#define RECIPIENT			0x1F	/* Mask to get recipient */
typedef enum _RECIPIENT_TYPE {
	DEVICE_RECIPIENT,		/* Recipient device */
	INTERFACE_RECIPIENT,	/* Recipient interface */
	ENDPOINT_RECIPIENT,		/* Recipient endpoint */
	OTHER_RECIPIENT
} RECIPIENT_TYPE;

/* Definition of "USBbRequest" */
/*
#define GET_STATUS		0
#define CLEAR_FEATURE	1
#define RESERVED1		2
#define SET_FEATURE		3
#define RESERVED2		4
#define SET_ADDRESS		5
#define GET_DESCRIPTOR	6
#define SET_DESCRIPTOR	7
#define GET_CONFIGURATION 8
#define SET_CONFIGURATION 9
#define GET_INTERFACE	10
#define SET_INTERFACE	11
*/
typedef enum _STANDARD_REQUESTS {
	GET_STATUS = 0,
	CLEAR_FEATURE,
	RESERVED1,
	SET_FEATURE,
	RESERVED2,
	SET_ADDRESS,
	GET_DESCRIPTOR,
	SET_DESCRIPTOR,
	GET_CONFIGURATION,
	SET_CONFIGURATION,
	GET_INTERFACE,
	SET_INTERFACE,
	TOTAL_sREQUEST,				/* Total number of Standard request */
	SYNCH_FRAME = 12
} STANDARD_REQUESTS;

/* Definition of "USBwValue" */
typedef enum _DESCRIPTOR_TYPE {
	DEVICE_DESCRIPTOR = 1,
	CONFIG_DESCRIPTOR,
	STRING_DESCRIPTOR,
	INTERFACE_DESCRIPTOR,
	ENDPOINT_DESCRIPTOR
} DESCRIPTOR_TYPE;

/* Feature selector of a SET_FEATURE or CLEAR_FEATURE */
typedef enum _FEATURE_SELECTOR {
	ENDPOINT_STALL,
	DEVICE_REMOTE_WAKEUP
} FEATURE_SELECTOR;
/*---------------------------------------------------------------------*/
/* HID descriptors */
/*---------------------------------------------------------------------*/
typedef enum _HID_DESCRIPTOR_TYPE {
	HID_DESCRIPTOR = 0x21,
	REPORT_DESCRIPTOR,
	PHYSICAL_DESCRIPTOR
} HID_DESCRIPTOR_TYPE;

typedef enum _HID_REQUESTS {
	GET_REPORT = 1,
	GET_IDLE,
	GET_PROTOCOL,

	SET_REPORT = 9,
	SET_IDLE,
	SET_PROTOCOL
} HID_REQUESTS;

typedef enum _HID_REPORT_TYPE {
	INPUT_REPORT = 1,
	OUTPUT_REPORT,
	FEATURE_REPORT
} HID_REPORT_TYPE;
#define DFU_DETACH        0

/******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****/

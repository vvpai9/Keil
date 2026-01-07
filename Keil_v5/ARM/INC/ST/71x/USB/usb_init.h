/******************** (C) COPYRIGHT 2003 STMicroelectronics ********************
* File Name          : usb_init.h
* Author             : MCD Application Team
* Date First Issued  : 27/10/2003
* Description        : initialization routines & global variables
*
********************************************************************************/

/*  Save token on endpoint 0 */
extern BYTE	EP0_Token  ;

/*  Interrupt flags.*/
/*  Each bit represents an interrupt is coming to that endpoint */
extern WORD	Token_Event	;

/*  The number of current endpoint, it will be used to specify an endpoint */
extern BYTE	EPindex;

/*  The number of current device, it is an index to the Device_Table */
/*extern BYTE	Device_no; */

/*  Points to the DEVICE_INFO structure of current device */
/*  The purpose of this register is to speed up the execution */
extern DEVICE_INFO*	pInformation;

/*  Points to the DEVICE_PROP structure of current device */
/*  The purpose of this register is to speed up the execution */
extern DEVICE_PROP*	pProperty;

/*  Temporary save the state of Rx & Tx status. */
/*  Whenever the Rx or Tx state is changed, its value is saved */
/*  in this variable first and will be set to the EPRB or EPRA */
/*  at the end of interrupt process */
extern WORD	SaveState ;

extern WORD wInterrupt_Mask;

void USB_Init(void);
RESULT PowerOn(void);
RESULT PowerOff(void);

/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : usb_conf.h
* Author             : MCD Application Team
* Date First Issued  : 05/18/2006 : Version 1.0
* Description        : USB configurations for USB mouse
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


/* EP_NUM */
/* defines how many endpoints are used by the device */
#define EP_NUM  			(2)

/* buffer table base address */
#define BTABLE_ADDRESS   (0x10)

/* ENDP0 Rx/Tx buffer base address */
#define ENDP0_RXADDR    (0x100)
#define ENDP0_TXADDR    (0x200)

/* ENDP1 : interrupt endpoint Rx buffer base address */
#define ENDP1_TXADDR   	(0x300)


/* ISTR events */
/* IMR_MSK */
/* mask defining which events has to be handled */
/* by the device application software */
#define IMR_MSK (CNTR_CTRM  | \
				 CNTR_WKUPM | \
				 CNTR_SUSPM | \
				 CNTR_ERRM  | \
				 CNTR_SOFM  | \
				 CNTR_ESOFM | \
		 		 CNTR_RESETM  \
		 		)

/* CTR service routines */
/* associated to defined endpoints */
#define  EP1_Callback   NOP_Process
#define  EP2_Callback   NOP_Process
#define  EP3_Callback   NOP_Process
#define  EP4_Callback   NOP_Process
#define  EP5_Callback   NOP_Process
#define  EP6_Callback   NOP_Process
#define  EP7_Callback   NOP_Process
#define  EP8_Callback   NOP_Process
#define  EP9_Callback   NOP_Process



/**/
/* ISTR events */
/* user defined service routines */
/*
#define CTR_Callback   count_CTR
#define DOVR_Callback  count_DOVR
#define ERR_Callback   count_ERR
#define WKUP_Callback  count_WKUP
#define SUSP_Callback  count_SUSP
#define RESET_Callback count_RESET
#define SOF_Callback   count_SOF
#define ESOF_Callback  count_ESOF
*/

/******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****/

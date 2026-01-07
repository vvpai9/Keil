/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : usb_mem.h
* Author             : MCD Application Team
* Date First Issued  : 03/10/2006 : V0.1
* Description        : Utility functions for memory transfers
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


/* function prototypes */
void UserToPMABufferCopy(BYTE *pbUsrBuf,WORD wPMABufAddr, WORD wNBytes);
void PMAToUserBufferCopy(BYTE *pbUsrBuf,WORD wPMABufAddr, WORD wNBytes);

/******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****/


/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 *      Name:    USBHW.H
 *      Purpose: USB Hardware Layer Definitions
 *      Version: V1.11
 *----------------------------------------------------------------------------
 *      This software is supplied "AS IS" without any warranties, express,
 *      implied or statutory, including but not limited to the implied
 *      warranties of fitness for purpose, satisfactory quality and
 *      noninfringement. Keil extends you a royalty-free right to reproduce
 *      and distribute executable files created using this software for use
 *      on Philips LPC microcontroller devices only. Nothing else gives you
 *      the right to use this software.
 *
 *      Copyright (c) 2005-2007 Keil Software.
 *---------------------------------------------------------------------------*/

#ifndef __USBHW_H__
#define __USBHW_H__


/* USB Error Codes */
#define USB_ERR_PID         0x0001  /* PID Error */
#define USB_ERR_UEPKT       0x0002  /* Unexpected Packet */
#define USB_ERR_DCRC        0x0004  /* Data CRC Error */
#define USB_ERR_TIMOUT      0x0008  /* Bus Time-out Error */
#define USB_ERR_EOP         0x0010  /* End of Packet Error */
#define USB_ERR_B_OVRN      0x0020  /* Buffer Overrun */
#define USB_ERR_BTSTF       0x0040  /* Bit Stuff Error */
#define USB_ERR_TGL         0x0080  /* Toggle Bit Error */

/* USB DMA Status Codes */
#define USB_DMA_INVALID     0x0000  /* DMA Invalid - Not Configured */
#define USB_DMA_IDLE        0x0001  /* DMA Idle - Waiting for Trigger */
#define USB_DMA_BUSY        0x0002  /* DMA Busy - Transfer in progress */
#define USB_DMA_DONE        0x0003  /* DMA Transfer Done (no Errors)*/
#define USB_DMA_SUSPEND     0x0004  /* DMA Suspend */
#define USB_DMA_OVER_RUN    0x0005  /* Data Over Run */
#define USB_DMA_UNDER_RUN   0x0006  /* Data Under Run (Short Packet) */
#define USB_DMA_ERROR       0x0007  /* Error */
#define USB_DMA_UNKNOWN     0xFFFF  /* Unknown State */

/* USB Hardware Variables */
extern volatile BOOL USB_HighSpeed;

/* USB Hardware Functions */
extern void  USB_Init       (void);
extern void  USB_Connect    (BOOL  con);
extern void  USB_Reset      (void);
extern void  USB_Suspend    (void);
extern void  USB_Resume     (void);
extern void  USB_WakeUp     (void);
extern void  USB_WakeUpCfg  (BOOL  cfg);
extern void  USB_SetAddress (DWORD adr);
extern void  USB_Configure  (BOOL  cfg);
extern void  USB_ConfigEP   (USB_ENDPOINT_DESCRIPTOR *pEPD);
extern void  USB_DirCtrlEP  (DWORD dir);
extern void  USB_EnableEP   (DWORD EPNum);
extern void  USB_DisableEP  (DWORD EPNum);
extern void  USB_ResetEP    (DWORD EPNum);
extern void  USB_SetStallEP (DWORD EPNum);
extern void  USB_ClrStallEP (DWORD EPNum);
extern DWORD USB_ReadEP     (DWORD EPNum, BYTE *pData);
extern DWORD USB_WriteEP    (DWORD EPNum, BYTE *pData, DWORD cnt);
extern DWORD USB_StatusInEP0  (void);
extern DWORD USB_StatusOutEP0 (void);
extern DWORD USB_ReadSetupEP0 (BYTE *pData);
extern BOOL  USB_DMA_Setup  (DWORD EPNum, DWORD SrcDestAddr, DWORD Length);
extern void  USB_DMA_Enable (DWORD CHNum);
extern void  USB_DMA_Disable(DWORD CHNum);
extern DWORD USB_DMA_Status (DWORD CHNum);
extern DWORD USB_GetFrame   (void);
extern void  USB_ISR(void);


#endif  /* __USBHW_H__ */

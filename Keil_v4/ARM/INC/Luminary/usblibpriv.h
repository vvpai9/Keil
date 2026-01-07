//*****************************************************************************
//
// usblibpriv.h - Private header file used to share internal variables and
//                function prototypes between the various modules in the USB
//                library.  This header MUST NOT be used by application code.
//
// Copyright (c) 2008 Luminary Micro, Inc.  All rights reserved.
// 
// Software License Agreement
// 
// Luminary Micro, Inc. (LMI) is supplying this software for use solely and
// exclusively on LMI's microcontroller products.
// 
// The software is owned by LMI and/or its suppliers, and is protected under
// applicable copyright laws.  All rights are reserved.  You may not combine
// this software with "viral" open-source software in order to form a larger
// program.  Any use in violation of the foregoing restrictions may subject
// the user to criminal sanctions under applicable laws, as well as to civil
// liability for the breach of the terms and conditions of this license.
// 
// THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
// OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
// LMI SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
// CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2523 of the Stellaris USB Library.
//
//*****************************************************************************

#ifndef __USBLIBPRIV_H__
#define __USBLIBPRIV_H__

//*****************************************************************************
//
// Device enumeration functions provided by device/usbenum.c and called from
// the interrupt handler in device/usbhandler.c
//
//*****************************************************************************
extern void USBDeviceEnumHandler(void);
extern void USBDeviceEnumResetHandler(void);

//*****************************************************************************
//
// Internal interrupt handlers called from the main vectors in device and
// host mode.
//
//*****************************************************************************
extern void USBDeviceIntHandlerInternal(unsigned long ulStatus);
extern void USBHostIntHandlerInternal(unsigned long ulStatus);

//*****************************************************************************
//
// The USB device information, as supplied to USBDCDInit().
//
//*****************************************************************************
extern tDeviceInfo *g_psUSBDeviceInfo;

#endif // __USBLIBPRIV_H__

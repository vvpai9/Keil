//*****************************************************************************
//
// usbhid.h - Definitions used by HID class devices and hosts.
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

#ifndef __USBHID_H__
#define __USBHID_H__

//*****************************************************************************
//
// HID Interface descriptor Subclasses.
//
//*****************************************************************************
#define USB_HID_SCLASS_NONE     0x00
#define USB_HID_SCLASS_BOOT     0x01

//*****************************************************************************
//
// USB Interface descriptor HID protocols.
//
//*****************************************************************************
#define USB_HID_PROTOCOL_NONE   0
#define USB_HID_PROTOCOL_KEYB   1
#define USB_HID_PROTOCOL_MOUSE  2

//*****************************************************************************
//
// HID Class descriptor types.
//
//*****************************************************************************
#define USB_HID_DTYPE_HID       0x21
#define USB_HID_DTYPE_REPORT    0x22
#define USB_HID_DTYPE_PHYSICAL  0x23

//*****************************************************************************
//
// HID USB requests.
//
//*****************************************************************************
#define USBREQ_GET_REPORT       0x01
#define USBREQ_GET_IDLE         0x02
#define USBREQ_GET_PROTOCOL     0x03
#define USBREQ_SET_REPORT       0x09
#define USBREQ_SET_IDLE         0x0a
#define USBREQ_SET_PROTOCOL     0x0b

//*****************************************************************************
//
// GET_REPORT or SET_REPORT Definitions.
//
//*****************************************************************************
#define USB_HID_REPORT_IN       0x01
#define USB_HID_REPORT_OUTPUT   0x02
#define USB_HID_REPORT_FEATURE  0x03

//*****************************************************************************
//
// GET_PROTOCOL or SET_PROTOCOL Definitions.
//
//*****************************************************************************
#define USB_HID_PROTOCOL_BOOT   0
#define USB_HID_PROTOCOL_REPORT 1

//*****************************************************************************
//
// Report Values used with the Report macros.
//
//*****************************************************************************
#define USB_HID_GENERIC_DESKTOP 0x01
#define USB_HID_BUTTONS         0x09
#define USB_HID_X               0x30
#define USB_HID_Y               0x31

#define USB_HID_POINTER         0x01
#define USB_HID_MOUSE           0x02
#define USB_HID_KEYBOARD        0x06

#define USB_HID_APPLICATION     0x00
#define USB_HID_PHYSICAL        0x01

#define USB_HID_USAGE_POINTER   0x0109
#define USB_HID_USAGE_BUTTONS   0x0509
#define USB_HID_USAGE_LEDS      0x0508
#define USB_HID_USAGE_KEYCODES  0x0507

//*****************************************************************************
//
// HID Keyboard LED definitions.
//
//*****************************************************************************
#define HID_KEYB_NUM_LOCK       0x01
#define HID_KEYB_CAPS_LOCK      0x02
#define HID_KEYB_SCROLL_LOCK    0x04
#define HID_KEYB_COMPOSE        0x08
#define HID_KEYB_KANA           0x10

#endif // __USBHID_H__

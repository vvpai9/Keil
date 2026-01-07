//*****************************************************************************
//
// usbdhid.h - Definitions used by HID class devices.
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

#ifndef __USBDHID_H__
#define __USBDHID_H__

//*****************************************************************************
//
//! \addtogroup device_hid_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// Macros used to create the static Report Descriptors.
//
//*****************************************************************************

//*****************************************************************************
//
//! This is a macro to assist adding Usage Page entries in HID report
//! descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Usage Page entry
//! into a HID report structure.  These are defined by the USB HID
//! specification.
//!
//! \param usValue is the Usage Page value.
//!
//! \return Not a function.
//
//*****************************************************************************
#define UsagePage(usValue)      0x05, ((usValue) & 0xff)

//*****************************************************************************
//
//! This is a macro to assist adding Usage entries in HID report descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Usage entry into
//! a HID report structure.  These are defined by the USB HID specification.
//!
//! \param usValue is the Usage value.
//!
//! \return Not a function.
//
//*****************************************************************************
#define Usage(usValue)          0x09, ((usValue) & 0xff)

//*****************************************************************************
//
//! This is a macro to assist adding Usage Minimum entries in HID report
//! descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Usage Minimum
//! entry into a HID report structure.  This is the first or minimum value
//! associated with a usage value.
//!
//! \param usValue is the Usage Minimum value.
//!
//! \return Not a function.
//
//*****************************************************************************
#define UsageMinimum(usValue)   0x19, ((usValue) & 0xff)

//*****************************************************************************
//
//! This is a macro to assist adding Usage Maximum entries in HID report
//! descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Usage Maximum
//! entry into a HID report structure.  This is the last or maximum value
//! associated with a usage value.
//!
//! \param usValue is the Usage Maximum value.
//!
//! \return Not a function.
//
//*****************************************************************************
#define UsageMaximum(usValue)   0x29, ((usValue) & 0xff)

//*****************************************************************************
//
//! This is a macro to assist adding Logical Minimum entries in HID report
//! descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Logical Minimum
//! entry into a HID report structure.  This is the actual minimum value for a
//! range of values associated with a field.
//!
//! \param usValue is the Logical Minimum value.
//!
//! \return Not a function.
//
//*****************************************************************************
#define LogicalMinimum(usValue) 0x15, ((usValue) & 0xff)

//*****************************************************************************
//
//! This is a macro to assist adding Logical Maximum entries in HID report
//! descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Logical Maximum
//! entry into a HID report structure.  This is the actual maximum value for a
//! range of values associated with a field.
//!
//! \param usValue is the Logical Maximum value.
//!
//! \return Not a function.
//
//*****************************************************************************
#define LogicalMaximum(usValue) 0x25, ((usValue) & 0xff)

//*****************************************************************************
//
//! This is a macro to assist adding Collection entries in HID report
//! descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Collection
//! entry into a HID report structure.  This is the type of values that are
//! being grouped together, for instance input, output or features can be
//! grouped together as a collection.
//!
//! \param usValue is the type of Collection.
//!
//! \return Not a function.
//
//*****************************************************************************
#define Collection(usValue)     0xa1, ((usValue) & 0xff)

//*****************************************************************************
//
//! This is a macro to assist adding End Collection entries in HID report
//! descriptors.
//!
//! This macro can be used to place an End Collection entry into a HID report
//! structure.  This is a tag to indicate that a collection of entries has
//! ended in the HID report structure.  This terminates a previous Collection()
//! entry.
//!
//! \return Not a function.
//
//*****************************************************************************
#define EndCollection           0xc0

//*****************************************************************************
//
//! This is a macro to assist adding Report Count entries in HID report
//! descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Report Count
//! entry into a HID report structure.  This is number of entries of Report
//! Size for a given item.
//!
//! \param usValue is the number of items in a report item.
//!
//! \return Not a function.
//
//*****************************************************************************
#define ReportCount(usValue)    0x95, ((usValue) & 0xff)

//*****************************************************************************
//
//! This is a macro to assist adding Report Size entries in HID report
//! descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Report Size
//! entry into a HID report structure.  This is size in bits of the entries of
//! of a report entry.  The Report Count specifies how many entries of Report
//! Size are in a given item.  These can be individual bits or bit fields.
//!
//! \param usValue is the size, in bits, of items in a report item.
//!
//! \return Not a function.
//
//*****************************************************************************
#define ReportSize(usValue)     0x75, ((usValue) & 0xff)

//*****************************************************************************
//
//! This is a macro to assist adding Input entries in HID report descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Input entry into
//! a HID report structure.  This specifies the type of an input item in a
//! report structure.  These refer to a bit mask of flags that indicate the
//! type of input for a set of items.
//!
//! \param usValue is bit mask to specify the type of a set of input report
//! items.
//!
//! \return Not a function.
//
//*****************************************************************************
#define Input(usValue)          0x81, ((usValue) & 0xff)

//*****************************************************************************
//
//! This is a macro to assist adding Output entries in HID report descriptors.
//!
//! This macro takes a value and prepares it to be placed as a Output entry
//! into a HID report structure.  This specifies the type of an output item in
//! a report structure.  These refer to a bit mask of flags that indicate the
//! type of output for a set of items.
//!
//! \param usValue is bit mask to specify the type of a set of output report
//! items.
//!
//! \return Not a function.
//
//*****************************************************************************
#define Output(usValue)         0x91, ((usValue) & 0xff)

//*****************************************************************************
//
// Defines used with the Input() macro.
//
//*****************************************************************************
#define USB_HID_INPUT_DATA      0x0000
#define USB_HID_INPUT_CONSTANT  0x0001
#define USB_HID_INPUT_ARRAY     0x0000
#define USB_HID_INPUT_VARIABLE  0x0002
#define USB_HID_INPUT_ABS       0x0000
#define USB_HID_INPUT_RELATIVE  0x0004
#define USB_HID_INPUT_NOWRAP    0x0000
#define USB_HID_INPUT_WRAP      0x0008
#define USB_HID_INPUT_LINEAR    0x0000
#define USB_HID_INPUT_NONLINEAR 0x0010
#define USB_HID_INPUT_PREFER    0x0000
#define USB_HID_INPUT_NONPREFER 0x0020
#define USB_HID_INPUT_NONULL    0x0000
#define USB_HID_INPUT_NULL      0x0040
#define USB_HID_INPUT_BITF      0x0100
#define USB_HID_INPUT_BYTES     0x0000

//*****************************************************************************
//
// Defines used with the Output macro.
//
//*****************************************************************************
#define USB_HID_OUTPUT_DATA      0x0000
#define USB_HID_OUTPUT_CONSTANT  0x0001
#define USB_HID_OUTPUT_ARRAY     0x0000
#define USB_HID_OUTPUT_VARIABLE  0x0002
#define USB_HID_OUTPUT_ABS       0x0000
#define USB_HID_OUTPUT_RELATIVE  0x0004
#define USB_HID_OUTPUT_NOWRAP    0x0000
#define USB_HID_OUTPUT_WRAP      0x0008
#define USB_HID_OUTPUT_LINEAR    0x0000
#define USB_HID_OUTPUT_NONLINEAR 0x0010
#define USB_HID_OUTPUT_PREFER    0x0000
#define USB_HID_OUTPUT_NONPREFER 0x0020
#define USB_HID_OUTPUT_NONULL    0x0000
#define USB_HID_OUTPUT_NULL      0x0040
#define USB_HID_OUTPUT_BITF      0x0100
#define USB_HID_OUTPUT_BYTES     0x0000

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

#endif // __USBDHID_H__

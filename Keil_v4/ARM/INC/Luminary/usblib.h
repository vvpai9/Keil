//*****************************************************************************
//
// usblib.h - Main header file for the USB Library.
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

#ifndef __USBLIB_H__
#define __USBLIB_H__

//*****************************************************************************
//
// The following macro allows compiler-independent syntax to be used to
// define packed structures.  A typical structure definition using these
// macros will look similar to the following example:
//
//   #ifdef ewarm
//   #pragma pack(1)
//   #endif
//
//   typedef struct _PackedStructName
//   {
//      unsigned long ulFirstField;
//      char cCharMember;
//      unsigned short usShort;
//   }
//   PACKED tPackedStructName;
//
//   #ifdef ewarm
//   #pragma pack()
//   #endif
//
// The conditional blocks related to ewarm include the #pragma pack() lines
// only if the IAR Embedded Workbench compiler is being used.  Unfortunately,
// it is not possible to emit a #pragma from within a macro definition so this
// must be done explicitly.
//
//*****************************************************************************
#if defined(codered) ||         \
    defined(gcc) ||             \
    defined(rvmdk) ||           \
    defined(__ARMCC_VERSION) || \
    defined(sourcerygxx)
#define PACKED __attribute__ ((packed))
#else
#if defined(ewarm)
#define PACKED
#else
#error Unrecognized COMPILER!
#endif
#endif

//*****************************************************************************
//
// Assorted language IDs from the document "USB_LANGIDs.pdf" provided by the
// USB Implementers' Forum (Version 1.0).
//
//*****************************************************************************
#define USB_LANG_CHINESE_PRC    0x0804      // Chinese (PRC)
#define USB_LANG_CHINESE_TAIWAN 0x0404      // Chinese (Taiwan)
#define USB_LANG_EN_US          0x0409      // English (United States)
#define USB_LANG_EN_UK          0x0809      // English (United Kingdom)
#define USB_LANG_EN_AUS         0x0C09      // English (Australia)
#define USB_LANG_EN_CA          0x1009      // English (Canada)
#define USB_LANG_EN_NZ          0x1409      // English (New Zealand)
#define USB_LANG_FRENCH         0x040C      // French (Standard)
#define USB_LANG_GERMAN         0x0407      // German (Standard)
#define USB_LANG_HINDI          0x0439      // Hindi
#define USB_LANG_ITALIAN        0x0410      // Italian (Standard)
#define USB_LANG_JAPANESE       0x0411      // Japanese
#define USB_LANG_KOREAN         0x0412      // Korean
#define USB_LANG_ES_TRAD        0x040A      // Spanish (Traditional)
#define USB_LANG_ES_MODERN      0x0C0A      // Spanish (Modern)
#define USB_LANG_SWAHILI        0x0441      // Swahili (Kenya)
#define USB_LANG_URDU_IN        0x0820      // Urdu (India)
#define USB_LANG_URDU_PK        0x0420      // Urdu (Pakistan)

//*****************************************************************************
//
//! \addtogroup usbchap9_src
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// Note:
//
// Structure definitions which are derived directly from the USB specification
// use field names from the specification.  Since a somewhat different version
// of Hungarian prefix notation is used from the Luminary standard, beware of
// making assumptions about field sizes based on the field prefix when using
// these structures.  Of particular note is the difference in the meaning of
// the 'i' prefix.  In USB structures, this indicates a single byte index
// whereas in Luminary code, this is a 32 bit integer.
//
//*****************************************************************************

//*****************************************************************************
//
// All structures defined in this section of the header require byte packing of
// fields.  This is usually accomplished using the PACKED macro but, for IAR
// Embedded Workbench, this requries a pragma.
//
//*****************************************************************************
#ifdef ewarm
#pragma pack(1)
#endif

//*****************************************************************************
//
// Definitions related to standard USB device requests (sections 9.3 & 9.4)
//
//*****************************************************************************

//*****************************************************************************
//
//! The standard USB request header as defined in section 9.3 of the USB 2.0
//! specification.
//
//*****************************************************************************
typedef struct
{
    //
    //! Determines the type and direction of the request.
    //
    unsigned char bmRequestType;

    //
    //! Identifies the specific request being made.
    //
    unsigned char bRequest;

    //
    //! Word-sized field that varies according to the request.
    //
    unsigned short wValue;

    //
    //! Word-sized field that varies according to the request; typically used
    //! to pass an index or offset.
    //
    unsigned short wIndex;

    //
    //! The number of bytes to transfer if there is a data stage to the
    //! request.
    //
    unsigned short wLength;

}
PACKED tUSBRequest;

//*****************************************************************************
//
// The following defines are used with the bmRequestType member of tUSBRequest.
//
// Request types have 3 bit fields:
// 4:0 - Is the recipient type.
// 6:5 - Is the request type.
// 7 - Is the direction of the request.
//
//*****************************************************************************
#define USB_RTYPE_DIR_IN        0x80
#define USB_RTYPE_DIR_OUT       0x00

#define USB_RTYPE_TYPE_M        0x60
#define USB_RTYPE_VENDOR        0x40
#define USB_RTYPE_CLASS         0x20
#define USB_RTYPE_STANDARD      0x00

#define USB_RTYPE_RECIPIENT_M   0x1f
#define USB_RTYPE_OTHER         0x03
#define USB_RTYPE_ENDPOINT      0x02
#define USB_RTYPE_INTERFACE     0x01
#define USB_RTYPE_DEVICE        0x00

//*****************************************************************************
//
// Standard USB requests IDs used in the bRequest field of tUSBRequest.
//
//*****************************************************************************
#define USBREQ_GET_STATUS       0x00
#define USBREQ_CLEAR_FEATURE    0x01
#define USBREQ_SET_FEATURE      0x03
#define USBREQ_SET_ADDRESS      0x05
#define USBREQ_GET_DESCRIPTOR   0x06
#define USBREQ_SET_DESCRIPTOR   0x07
#define USBREQ_GET_CONFIG       0x08
#define USBREQ_SET_CONFIG       0x09
#define USBREQ_GET_INTERFACE    0x0a
#define USBREQ_SET_INTERFACE    0x0b
#define USBREQ_SYNC_FRAME       0x0c

//*****************************************************************************
//
// Data returned from a USBREQ_GET_STATUS request to a device.
//
//*****************************************************************************
#define USB_STATUS_SELF_PWR     0x0001  // Currently self powered.
#define USB_STATUS_REMOTE_WAKE  0x0002  // Remote wake-up is currently enabled.

//*****************************************************************************
//
// Feature Selectors (tUSBRequest.wValue) passed on USBREQ_CLEAR_FEATURE and
// USBREQ_SET_FEATURE.
//
//*****************************************************************************
#define USB_FEATURE_EP_HALT     0x0000  // Endpoint halt feature.
#define USB_FEATURE_REMOTE_WAKE 0x0001  // Remote wake feature, device only.
#define USB_FEATURE_TEST_MODE   0x0002  // Test mode

//*****************************************************************************
//
// Standard USB descriptor types.  These values are passed in the upper bytes
// of tUSBRequest.wValue on USBREQ_GET_DESCRIPTOR and also appear in the
// bDescriptorType field of standard USB descriptors.
//
//*****************************************************************************
#define USB_DTYPE_DEVICE        1
#define USB_DTYPE_CONFIGURATION 2
#define USB_DTYPE_STRING        3
#define USB_DTYPE_INTERFACE     4
#define USB_DTYPE_ENDPOINT      5
#define USB_DTYPE_DEVICE_QUAL   6
#define USB_DTYPE_OSPEED_CONF   7
#define USB_DTYPE_INTERFACE_PWR 8

//*****************************************************************************
//
// Definitions related to USB descriptors (sections 9.5 & 9.6)
//
//*****************************************************************************

//*****************************************************************************
//
//! This structure describes a generic descriptor header.  These fields are to
//! be found at the beginning of all valid USB descriptors.
//
//*****************************************************************************
typedef struct
{
    //
    //! The length of this descriptor (including this length byte) expressed
    //! in bytes.
    //
    unsigned char bLength;

    //
    //! The type identifier of the descriptor whose information follows.  For
    //! standard descriptors, this field could contain, for example,
    //! USB_DTYPE_DEVICE to identify a device descriptor or USB_DTYPE_ENDPOINT
    //! to identify an endpoint descriptor.
    //
    unsigned char bDescriptorType;
}
PACKED tDescriptorHeader;

//*****************************************************************************
//
//! This structure describes the USB device descriptor as defined in USB
//! 2.0 specification section 9.6.1.
//
//*****************************************************************************
typedef struct
{
    //
    //! The length of this descriptor in bytes.  All device descriptors are
    //! 18 bytes long.
    //
    unsigned char bLength;

    //
    //! The type of the descriptor.  For a device descriptor, this will be
    //! USB_DTYPE_DEVICE (1).
    //
    unsigned char bDescriptorType;

    //
    //! The USB Specification Release Number in BCD format.  For USB 2.0, this
    //! will be 0x0200.
    //
    unsigned short bcdUSB;

    //
    //! The device class code.
    //
    unsigned char bDeviceClass;

    //
    //! The device subclass code.  This value qualifies the value found in the
    //! bDeviceClass field.
    //
    unsigned char bDeviceSubClass;

    //
    //! The device protocol code.  This value is qualified by the values of
    //! bDeviceClass and bDeviceSubClass.
    //
    unsigned char bDeviceProtocol;

    //
    //! The maximum packet size for endpoint zero.  Valid values are 8, 16, 32
    //! and 64.
    //
    unsigned char bMaxPacketSize0;

    //
    //! The device Vendor ID (VID) as assigned by the USB-IF.
    //
    unsigned short idVendor;

    //
    //! The device Product ID (PID) as assigned by the manufacturer.
    //
    unsigned short idProduct;

    //
    //! The device release number in BCD format.
    //
    unsigned short bcdDevice;

    //
    //! The index of a string descriptor describing the manufacturer.
    //
    unsigned char iManufacturer;

    //
    //! The index of a string descriptor describing the product.
    //
    unsigned char iProduct;

    //
    //! The index of a string descriptor describing the device's serial
    //! number.
    //
    unsigned char iSerialNumber;

    //
    //! The number of possible configurations offered by the device.  This
    //! field indicates the number of distinct configuration descriptors that
    //! the device offers.
    //
    unsigned char bNumConfigurations;
}
PACKED tDeviceDescriptor;

//*****************************************************************************
//
// USB Device Class codes used in the tDeviceDescriptor.bDeviceClass field.
// Definitions for the bDeviceSubClass and bDeviceProtocol fields are device
// specific and can be found in the appropriate device class header files.
//
//*****************************************************************************
#define USB_CLASS_DEVICE        0x00
#define USB_CLASS_AUDIO         0x01
#define USB_CLASS_CDC           0x02
#define USB_CLASS_HID           0x03
#define USB_CLASS_PHYSICAL      0x05
#define USB_CLASS_IMAGE         0x06
#define USB_CLASS_PRINTER       0x07
#define USB_CLASS_MASS_STORAGE  0x08
#define USB_CLASS_HUB           0x09
#define USB_CLASS_CDC_DATA      0x0a
#define USB_CLASS_SMART_CARD    0x0b
#define USB_CLASS_SECURITY      0x0d
#define USB_CLASS_VIDEO         0x0e
#define USB_CLASS_HEALTHCARE    0x0f
#define USB_CLASS_DIAG_DEVICE   0xdc
#define USB_CLASS_WIRELESS      0xe0
#define USB_CLASS_MISC          0xef
#define USB_CLASS_APP_SPECIFIC  0xfe
#define USB_CLASS_VEND_SPECIFIC 0xff

//*****************************************************************************
//
//! This structure describes the USB device qualifier descriptor as defined in
//! the USB 2.0 specification, section 9.6.2.
//
//*****************************************************************************
typedef struct
{
    //
    //! The length of this descriptor in bytes.  All device qualifier
    //! descriptors are 10 bytes long.
    //
    unsigned char bLength;

    //
    //! The type of the descriptor.  For a device descriptor, this will be
    //! USB_DTYPE_DEVICE_QUAL (6).
    //
    unsigned char bDescriptorType;

    //
    //! The USB Specification Release Number in BCD format.  For USB 2.0, this
    //! will be 0x0200.
    //
    unsigned short bcdUSB;

    //
    //! The device class code.
    //
    unsigned char bDeviceClass;

    //
    //! The device subclass code.  This value qualifies the value found in the
    //! bDeviceClass field.
    //
    unsigned char bDeviceSubClass;

    //
    //! The device protocol code.  This value is qualified by the values of
    //! bDeviceClass and bDeviceSubClass.
    //
    unsigned char bDeviceProtocol;

    //
    //! The maximum packet size for endpoint zero when operating at a speed
    //! other than high speed.
    //
    unsigned char bMaxPacketSize0;

    //
    //! The number of other-speed configurations supported.
    //
    unsigned char bNumConfigurations;

    //
    //! Reserved for future use.  Must be set to zero.
    //
    unsigned char bReserved;
}
PACKED tDeviceQualifierDescriptor;

//*****************************************************************************
//
//! This structure describes the USB configuration descriptor as defined in
//! USB 2.0 specification section 9.6.3.  This structure also applies to the
//! USB other speed configuration descriptor defined in section 9.6.4.
//
//*****************************************************************************
typedef struct
{
    //
    //! The length of this descriptor in bytes.  All configuration descriptors
    //! are 9 bytes long.
    //
    unsigned char bLength;

    //
    //! The type of the descriptor.  For a configuration descriptor, this will
    //! be USB_DTYPE_CONFIGURATION (2).
    //
    unsigned char bDescriptorType;

    //
    //! The total length of data returned for this configuration.  This
    //! includes the combined length of all descriptors (configuration,
    //! interface, endpoint and class- or vendor-specific) returned for this
    //! configuration.
    //
    unsigned short wTotalLength;

    //
    //! The number of interface supported by this configuration.
    //
    unsigned char bNumInterfaces;

    //
    //! The value used as an argument to the SetConfiguration standard request
    //! to select this configuration.
    //
    unsigned char bConfigurationValue;

    //
    //! The index of a string descriptor describing this configuration.
    //
    unsigned char iConfiguration;

    //
    //! Attributes of this configuration.
    //
    unsigned char bmAttributes;

    //
    //! The maximum power consumption of the USB device from the bus in this
    //! configuration when the device is fully operational.  This is expressed
    //! in units of 2mA so, for example, 100 represents 200mA.
    //
    unsigned char bMaxPower;
}
PACKED tConfigDescriptor;

//*****************************************************************************
//
// Flags used in constructing the value assigned to the field
// tConfigDescriptor.bmAttributes.  Note that bit 7 is reserved and must be set
// to 1.
//
//*****************************************************************************
#define USB_CONF_ATTR_SELF_PWR  0xC0
#define USB_CONF_ATTR_RWAKE     0xA0

//*****************************************************************************
//
//! This structure describes the USB interface descriptor as defined in USB
//! 2.0 specification section 9.6.5.
//
//*****************************************************************************
typedef struct
{
    //
    //! The length of this descriptor in bytes.  All interface descriptors
    //! are 9 bytes long.
    //
    unsigned char bLength;

    //
    //! The type of the descriptor.  For an interface descriptor, this will
    //! be USB_DTYPE_INTERFACE (4).
    //
    unsigned char bDescriptorType;

    //
    //! The number of this interface.  This is a zero based index into the
    //! array of concurrent interfaces supported by this configuration.
    //
    unsigned char bInterfaceNumber;

    //
    //! The value used to select this alternate setting for the interface
    //! defined in bInterfaceNumber.
    //
    unsigned char bAlternateSetting;

    //
    //! The number of endpoints used by this interface (excluding endpoint
    //! zero).
    //
    unsigned char bNumEndpoints;

    //
    //! The interface class code as assigned by the USB-IF.
    //
    unsigned char bInterfaceClass;

    //
    //! The interface subclass code as assigned by the USB-IF.
    //
    unsigned char bInterfaceSubClass;

    //
    //! The interface protocol code as assigned by the USB-IF.
    //
    unsigned char bInterfaceProtocol;

    //
    //! The index of a string descriptor describing this interface.
    //
    unsigned char iInterface;
}
PACKED tInterfaceDescriptor;

//*****************************************************************************
//
//! This structure describes the USB endpoint descriptor as defined in USB
//! 2.0 specification section 9.6.6.
//
//*****************************************************************************
typedef struct
{
    //
    //! The length of this descriptor in bytes.  All endpoint descriptors
    //! are 7 bytes long.
    //
    unsigned char bLength;

    //
    //! The type of the descriptor.  For an endpoint descriptor, this will
    //! be USB_DTYPE_ENDPOINT (5).
    //
    unsigned char bDescriptorType;

    //
    //! The address of the endpoint.  This field contains the endpoint number
    //! ORed with flag USB_EP_DESC_OUT or USB_EP_DESC_IN to indicate the
    //! endpoint direction.
    //
    unsigned char bEndpointAddress;

    //
    //! The endpoint transfer type, USB_EP_ATTR_CONTROL, USB_EP_ATTR_ISOC,
    //! USB_EP_ATTR_BULK or USB_EP_ATTR_INT and, if isochronous, additional
    //! flags indicating usage type and synchronization method.
    //
    unsigned char bmAttributes;

    //
    //! The maximum packet size this endpoint is capable of sending or
    //! receiving when this configuration is selected.  For high speed
    //! isochronous or interrupt endpoints, bits 11 and 12 are used to
    //! pass additional information.
    //
    unsigned short wMaxPacketSize;

    //
    //! The polling interval for data transfers expressed in frames or
    //! microframes depending upon the operating speed.
    //
    unsigned char bInterval;
}
PACKED tEndpointDescriptor;

//*****************************************************************************
//
// Flags used in constructing the value assigned to the field
// tEndpointDescriptor.bEndpointAddress.
//
//*****************************************************************************
#define USB_EP_DESC_OUT                 0x00
#define USB_EP_DESC_IN                  0x80
#define USB_EP_DESC_NUM_M               0x0f

//*****************************************************************************
//
// Endpoint attributes used in tEndpointDescriptor.bmAttributes.
//
//*****************************************************************************
#define USB_EP_ATTR_CONTROL             0x00
#define USB_EP_ATTR_ISOC                0x01
#define USB_EP_ATTR_BULK                0x02
#define USB_EP_ATTR_INT                 0x03
#define USB_EP_ATTR_TYPE_M              0x03

#define USB_EP_ATTR_ISOC_NOSYNC         0x00
#define USB_EP_ATTR_ISOC_ASYNC          0x04
#define USB_EP_ATTR_ISOC_ADAPT          0x08
#define USB_EP_ATTR_ISOC_SYNC           0x0c
#define USB_EP_ATTR_USAGE_DATA          0x00
#define USB_EP_ATTR_USAGE_FEEDBACK      0x10
#define USB_EP_ATTR_USAGE_IMPFEEDBACK   0x20

//*****************************************************************************
//
//! This structure describes the USB string descriptor for index 0 as defined
//! in USB 2.0 specification section 9.6.7.  Note that the number of language
//! IDs is variable and can be determined by examining bLength.  The number of
//! language IDs present in the descriptor is given by ((bLength - 2) / 2).
//
//*****************************************************************************
typedef struct
{
    //
    //! The length of this descriptor in bytes.  This value will vary
    //! depending upon the number of language codes provided in the descriptor.
    //
    unsigned char bLength;

    //
    //! The type of the descriptor.  For a string descriptor, this will be
    //! USB_DTYPE_STRING (3).
    //
    unsigned char bDescriptorType;

    //
    //! The language code (LANGID) for the first supported language.  Note that
    //! this descriptor may support multiple languages, in which case, the
    //! number of elements in the wLANGID array will increase and bLength will
    //! be updated accordingly.
    //
    unsigned short wLANGID[1];
}
PACKED tString0Descriptor;

//*****************************************************************************
//
//! This structure describes the USB string descriptor for all string indexes
//! other than 0 as defined in USB 2.0 specification section 9.6.7.
//
//*****************************************************************************
typedef struct
{
    //
    //! The length of this descriptor in bytes.  This value will be 2 greater
    //! than the number of bytes comprising the UNICODE string that the
    //! descriptor contains.
    //
    unsigned char bLength;

    //
    //! The type of the descriptor.  For a string descriptor, this will be
    //! USB_DTYPE_STRING (3).
    //
    unsigned char bDescriptorType;

    //
    //! The first byte of the UNICODE string.  This string is not NULL
    //! terminated.  Its length (in bytes) can be computed by subtracting 2
    //! from the value in the bLength field.
    //
    unsigned char bString;
}
PACKED tStringDescriptor;

//****************************************************************************
//
//! Write a 2 byte unsigned short value to a USB descriptor block.
//!
//! \param usValue is the two byte unsigned short that is to be written to
//! the descriptor.
//!
//! This helper macro is used in descriptor definitions to write two-byte
//! values.  Since the configuration descriptor contains all interface and
//! endpoint descriptors in a contiguous block of memory, these descriptors are
//! typically defined using an array of bytes rather than as packed structures.
//!
//! \return Not a function.
//
//****************************************************************************
#define USBShort(usValue)       (usValue & 0xff), (usValue >> 8)

//****************************************************************************
//
//! Write a 4 byte unsigned long value to a USB descriptor block.
//!
//! \param ulValue is the four byte unsigned long that is to be written to the
//! descriptor.
//!
//! This helper macro is used in descriptor definitions to write four-byte
//! values.  Since the configuration descriptor contains all interface and
//! endpoint descriptors in a contiguous block of memory, these descriptors are
//! typically defined using an array of bytes rather than as packed structures.
//!
//! \return Not a function.
//
//****************************************************************************
#define USBLong(ulValue)        (ulValue & 0xff),              \
                                ((ulValue >> 8) & 0xff),       \
                                ((ulValue >> 16) & 0xff),      \
                                ((ulValue >> 24) & 0xff)

//****************************************************************************
//
//! Traverse to the next USB descriptor in a block.
//!
//! \param ptr points to the first byte of a descriptor in a block of
//! USB descriptors.
//!
//! This macro aids in traversing lists of descriptors by returning a pointer
//! to the next descriptor in the list given a pointer to the current one.
//!
//! \return Returns a pointer to the next descriptor in the block following
//! \e ptr.
//!
//****************************************************************************
#define NEXT_USB_DESCRIPTOR(ptr)                         \
        (tDescriptorHeader *)(((unsigned char *)(ptr)) + \
                              *((unsigned char *)(ptr)))

//*****************************************************************************
//
// Return to default packing when using the IAR Embedded Workbench compiler.
//
//*****************************************************************************
#ifdef ewarm
#pragma pack()
#endif

//*****************************************************************************
//
// Close the usbchap9_src Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup general_usblib_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// USB descriptor parsing functions found in usbdesc.c
//
//*****************************************************************************

//*****************************************************************************
//
//! The USB_DESC_ANY label is used as a wild card in several of the descriptor
//! parsing APIs to determine whether or not particular search criteria should
//! be ignored.
//
//*****************************************************************************
#define USB_DESC_ANY 0xFFFFFFFF

extern unsigned long USBDescGetNum(tDescriptorHeader *psDesc,
                                   unsigned long ulSize, unsigned long ulType);
extern tDescriptorHeader *USBDescGet(tDescriptorHeader *psDesc,
                                     unsigned long ulSize,
                                     unsigned long ulType,
                                     unsigned long ulIndex);
extern unsigned long
       USBDescGetNumAlternateInterfaces(tConfigDescriptor *psConfig,
                                        unsigned char ucInterfaceNumber);
extern tInterfaceDescriptor *USBDescGetInterface(tConfigDescriptor *psConfig,
                                                 unsigned long ulIndex,
                                                 unsigned long ulAltCfg);
extern tEndpointDescriptor *
       USBDescGetInterfaceEndpoint(tInterfaceDescriptor *psInterface,
                                   unsigned long ulIndex,
                                   unsigned long ulSize);

//****************************************************************************
//
//! The operating mode required by the USB library client.  This type is used
//! by applications which wish to be able to switch between host and device
//! modes by calling the USBStackModeSet() API.
//
//****************************************************************************
typedef enum
{
    //
    //! The application wishes to operate as a USB device.
    //
    USB_MODE_DEVICE,

    //
    //! The application wishes to operate as a USB host.
    //
    USB_MODE_HOST,

    //
    //! A marker indicating that no USB mode has yet been set by the
    //! application.
    //
    USB_MODE_NONE
}
tUSBMode;

//*****************************************************************************
//
// A pointer to a USB mode callback function.  This function is called by the
// USB library to indicate to the application which operating mode it should
// use, host or device.
//
//*****************************************************************************
typedef void (*tUSBModeCallback)(unsigned long ulIndex, tUSBMode eMode);

//*****************************************************************************
//
// Mode selection and dual mode interrupt steering functions.
//
//*****************************************************************************
extern void USBStackModeSet(unsigned long ulIndex, tUSBMode eUSBMode,
                            tUSBModeCallback pfnCallback);
extern void USBDualModeInit(unsigned long ulIndex);
extern void USBDualModeTerm(unsigned long ulIndex);
extern void USB0DualModeIntHandler(void);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

#endif // __USBLIB_H__

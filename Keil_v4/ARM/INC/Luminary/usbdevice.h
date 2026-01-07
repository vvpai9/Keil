//*****************************************************************************
//
// usbdevice.h - types and definitions used during USB enumeration.
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

#ifndef __USBDEVICE_H__
#define __USBDEVICE_H__

//*****************************************************************************
//
//! \addtogroup device_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! Function prototype for any standard USB request.
//
//*****************************************************************************
typedef void (* tStdRequest)(unsigned long ulIndex, tUSBRequest *pUSBRequest);

//*****************************************************************************
//
//! Data Callback for receiving data from an endpoint.
//
//*****************************************************************************
typedef void (* tInfoCallback)(unsigned long ulIndex, unsigned long ulInfo);

//*****************************************************************************
//
//! Generic interrupt handler callbacks.
//
//*****************************************************************************
typedef void (* tUSBIntHandler)(unsigned long ulIndex);

//*****************************************************************************
//
//! Interrupt handler callbacks that have status information.
//
//*****************************************************************************
typedef void (* tUSBEPIntHandler)(unsigned long ulIndex,
                                  unsigned long ulStatus);

//*****************************************************************************
//
//! USB event handler functions used during enumeration and operation of the
//! device stack.
//
//*****************************************************************************
typedef struct
{
    //
    //! This callback is made whenever the USB host requests a non-standard
    //! descriptor from the device.
    //
    tStdRequest pfnGetDescriptor;

    //
    //! This callback is made whenever the USB host makes a non-standard
    //! request.
    //
    tStdRequest pfnRequestHandler;

    //
    //! This callback is made in response to a SetInterface request from the
    //! host.
    //
    tInfoCallback pfnInterfaceChange;

    //
    //! This callback is made in response to a SetConfiguration request from
    //! the host.
    //
    tInfoCallback pfnConfigChange;

    //
    //! This callback is made when data has been received following to a call
    //! to USBDCDRequestDataEP0.
    //
    tInfoCallback pfnDataReceived;

    //
    //! This calback is made when data has been transmitted following a call to
    //! USBDCDSendDataEP0.
    //
    tInfoCallback pfnDataSent;

    //
    //! This callback is made when a USB reset is detected.
    //
    tUSBIntHandler pfnResetHandler;

    //
    //! This callback is made when the bus has been inactive long enough to
    //! trigger a suspend condition.
    //
    tUSBIntHandler pfnSuspendHandler;

    //
    //! This is called when resume signaling is detected.
    //
    tUSBIntHandler pfnResumeHandler;

    //
    //! This callback is made when the device is disconnected from the USB bus.
    //
    tUSBIntHandler pfnDisconnectHandler;

    //
    //! This callback is made to inform the device of activity on all endpoints
    //! other than endpoint zero.
    //
    tUSBEPIntHandler pfnEndpointHandler;
}
tCustomHandlers;

//*****************************************************************************
//
//! This structure is passed to the USB library on a call to USBDCDInit and
//! provides the library with information about the device that the
//! application is implementing.  It contains functions pointers for the
//! various USB event handlers and pointers to each of the standard device
//! descriptors.
//
//*****************************************************************************
typedef struct
{
    //
    //! A pointer to a structure containing pointers to event handler functions
    //! provided by the client to support the operation of this device.
    //
    tCustomHandlers sCallbacks;

    //
    //! A pointer to the device descriptor for this device.
    //
    const unsigned char *pDeviceDescriptor;

    //
    //! A pointer to an array of config descriptor pointers.  Each entry in
    //! the array corresponds to one configuration that the device may be set
    //! to use by the USB host.  The number of entries in the array must
    //! match the bNumConfigurations value in the device descriptor
    //! array, pDeviceDescriptor.
    //
    const unsigned char * const *ppConfigDescriptors;

    //
    //! A pointer to the string descriptor array for this device.
    //
    const unsigned char * const *ppStringDescriptors;

    //
    //! The number of descriptors provided in the ppStringDescriptors
    //! array.
    //
    unsigned long ulNumStringDescriptors;
}
tDeviceInfo;

//*****************************************************************************
//
// Public APIs offered by the USB library device control driver.
//
//*****************************************************************************
extern void USBDCDInit(unsigned long ulIndex, tDeviceInfo *psDevice);
extern void USBDCDTerm(unsigned long ulIndex);
extern void USBDCDStallEP0(unsigned long ulIndex);
extern void USBDCDRequestDataEP0(unsigned long ulIndex, unsigned char *pucData,
                                 unsigned long ulSize);
extern void USBDCDSendDataEP0(unsigned long ulIndex, unsigned char *pucData,
                              unsigned long ulSize);
extern void USBDCDSetDefaultConfiguration(unsigned long ulIndex,
                                          unsigned long ulDefaultConfig);

//*****************************************************************************
//
// Device mode interrupt handler for controller index 0.
//
//*****************************************************************************
extern void USB0DeviceIntHandler(void);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

#endif // __USBENUM_H__

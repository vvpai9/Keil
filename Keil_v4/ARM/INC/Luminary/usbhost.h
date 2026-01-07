//*****************************************************************************
//
// usbhost.h - Host specific definitions for the USB host library.
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

#ifndef __USBHOST_H__
#define __USBHOST_H__

//*****************************************************************************
//
//! \addtogroup host_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// This is the type used to identify what the pipe is currently in use for.
//
//*****************************************************************************
#define USBHCD_PIPE_UNUSED      0x00001000
#define USBHCD_PIPE_CONTROL     0x00001300
#define USBHCD_PIPE_BULK_OUT    0x00002100
#define USBHCD_PIPE_BULK_IN     0x00002200
#define USBHCD_PIPE_INTR_OUT    0x00004100
#define USBHCD_PIPE_INTR_IN     0x00004200
#define USBHCD_PIPE_ISOC_OUT    0x00008100
#define USBHCD_PIPE_ISOC_IN     0x00008200

//*****************************************************************************
//
// These are the USBHCD events that can result in callbacks to USB pipes.
//
//*****************************************************************************
#define USBHCD_PIPE_NO_CHANGE   0x00000000
#define USBHCD_PIPE_RX_COMPLETE 0x00000001
#define USBHCD_PIPE_RX_ERROR    0x00000002
#define USBHCD_PIPE_TX_COMPLETE 0x00000101
#define USBHCD_PIPE_TX_ERROR    0x00000102
#define USBHCD_PIPE_ERROR       0xffffffff

//*****************************************************************************
//
//! This is the structure that holds all of the information for devices
//! that are enumerated in the system.
//
//*****************************************************************************
typedef struct
{
    //
    //! The current device address for this device.
    //
    unsigned long ulAddress;

    //
    //! The current interface for this device.
    //
    unsigned long ulInterface;

    //
    //! A pointer to the device descriptor for this device.
    //
    tDeviceDescriptor DeviceDescriptor;

    //
    //! A pointer to the configuration descriptor for this device.
    //
    tConfigDescriptor *pConfigDescriptor;

    //
    //! The size of the buffer allocated to pConfigDescriptor.
    //
    unsigned long ulConfigDescriptorSize;
}
tUSBHostDevice;

//*****************************************************************************
//
//! This is a USB host driver instance, it is parsed to find a ``driver'' for
//! a class that is enumerated.
//
//*****************************************************************************
typedef struct
{
    //
    //! The interface class that this device driver supports.
    //
    unsigned long ulInterfaceClass;

    //
    //! The function called when this class of device has been detected.
    //
    void * (*pfnOpen)(tUSBHostDevice *pDevice);

    //
    //! The function called when the device, originally opened with a call
    //! to the pfnOpen function, is disconnected.
    //
    void (*pfnClose)(void *pvInstance);

    //
    //! This is the interrupt handler that will be called when an endpoint
    //! associated with this device instance generates an interrupt.
    //
    void (*pfnIntHandler)(void *pvInstance);
}
tUSBHostClassDriver;

//*****************************************************************************
//
//! This is the type definition a callback for events on USB Pipes allocated
//! by USBHCDPipeAlloc().
//
//*****************************************************************************
typedef void ( *tHCDPipeCallback)(unsigned long ulPipe, unsigned long ulEvent);

//*****************************************************************************
//
// Prototypes for the USB Host controller APIs.
//
//*****************************************************************************
extern void USBHCDMain(void);
extern void USBHCDInit(unsigned long ulIndex, void *pData,
                       unsigned long ulSize);
extern void
       USBHCDRegisterDrivers(unsigned long ulIndex,
                             const tUSBHostClassDriver * const *ppHClassDrvrs,
                             unsigned long ulNumDrivers);
extern void USBHCDTerm(unsigned long ulIndex);
extern void USBHCDSetConfig(unsigned long ulIndex, unsigned long ulDevice,
                            unsigned long ulConfiguration);
extern void USBHCDSuspend(unsigned long ulIndex);
extern void USBHCDResume(unsigned long ulIndex);
extern void USBHCDReset(unsigned long ulIndex);
extern void USBHCDPipeFree(unsigned long ulPipe);
extern unsigned long USBHCDPipeAlloc(unsigned long ulIndex,
                                     unsigned long ulEndpointType,
                                     unsigned long ulDevAddr,
                                     tHCDPipeCallback pCallback);
extern unsigned long USBHCDPipeConfig(unsigned long ulPipe,
                                      unsigned long ulMaxPayload,
                                      unsigned long ulTargetEndpoint);
extern unsigned long USBHCDPipeStatus(unsigned long ulPipe);
extern unsigned long USBHCDPipeWrite(unsigned long ulPipe,
                                     unsigned char *pData,
                                     unsigned long ulSize);
extern unsigned long USBHCDPipeRead(unsigned long ulPipe, unsigned char *pData,
                           unsigned long ulSize);
extern unsigned long USBHCDControlTransfer(unsigned long ulIndex,
                                           tUSBRequest *pSetupPacket,
                                           unsigned long ulAddress,
                                           unsigned char *pData,
                                           unsigned long ulSize,
                                           unsigned long ulMaxPacketSize);
extern void USB0HostIntHandler(void);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

#endif // __USBHOST_H__

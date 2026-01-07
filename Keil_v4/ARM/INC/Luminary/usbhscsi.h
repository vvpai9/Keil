//*****************************************************************************
//
// usbhscsi.h - Definitions for the USB host SCSI layer.
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

#ifndef __USBHSCSI_H__
#define __USBHSCSI_H__

//*****************************************************************************
//
// Prototypes for the APIs exported by the USB SCSI layer.
//
//*****************************************************************************
extern unsigned long USBHSCSIInquiry(unsigned long ulInPipe,
                                     unsigned long ulOutPipe,
                                     unsigned char *pucBuffer,
                                     unsigned long *pulSize);
extern unsigned long USBHSCSIReadCapacity(unsigned long ulInPipe,
                                          unsigned long ulOutPipe,
                                          unsigned char *pData,
                                          unsigned long *pulSize);
extern unsigned long USBHSCSIReadCapacities(unsigned long ulInPipe,
                                            unsigned long ulOutPipe,
                                            unsigned char *pData,
                                            unsigned long *pulSize);
extern unsigned long USBHSCSIModeSense6(unsigned long ulInPipe,
                                        unsigned long ulOutPipe,
                                        unsigned long ulFlags,
                                        unsigned char *pData,
                                        unsigned long *pulSize);
extern unsigned long USBHSCSITestUnitReady(unsigned long ulInPipe,
                                           unsigned long ulOutPipe);
extern unsigned long USBHSCSIRequestSense(unsigned long ulInPipe,
                                          unsigned long ulOutPipe,
                                          unsigned char *pucData,
                                          unsigned long *pulSize);
extern unsigned long USBHSCSIRead10(unsigned long ulInPipe,
                                    unsigned long ulOutPipe,
                                    unsigned long ulLBA,
                                    unsigned char *pucData,
                                    unsigned long *pulSize);
extern unsigned long USBHSCSIWrite10(unsigned long ulInPipe,
                                     unsigned long ulOutPipe,
                                     unsigned long ulLBA,
                                     unsigned char *pucData,
                                     unsigned long *pulSize);

#endif // __USBHSCSI_H__

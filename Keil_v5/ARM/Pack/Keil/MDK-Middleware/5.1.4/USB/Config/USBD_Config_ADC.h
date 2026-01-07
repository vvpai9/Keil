/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Device
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    USBD_Config_ADC_%Instance%.h
 * Purpose: USB Device Audio Device Class (ADC) Configuration
 * Rev.:    V5.10
 *----------------------------------------------------------------------------*/

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

// <h>USB Device: Audio Device Class (ADC) %Instance%
//   <o>Assign Device Class to USB Device # <0-3>
//   <i>Select USB Device that is used for this Device Class instance
#define USBD_ADC%Instance%_DEV                   0

//   <h>Isochronous Endpoint Settings
//   <i>By default, the settings match the first USB Class instance in a USB Device.
//   <i>Endpoint conflicts are flagged by compile-time error messages.
//
//     <o.0..3>Isochronous OUT Endpoint Number
//               <1=>1   <2=>2   <3=>3   <4=>4   <5=>5   <6=>6   <7=>7
//       <8=>8   <9=>9   <10=>10 <11=>11 <12=>12 <13=>13 <14=>14 <15=>15
#define USBD_ADC%Instance%_EP_ISO_OUT            3


//     <h>Endpoint Settings
//       <i>Parameters are used to create USB Descriptors and for memory 
//       <i>allocation in the USB component.
//
//       <h>Full/Low-speed (High-speed disabled)
//       <i>Parameters apply when High-speed is disabled in USBD_Config_%Instance%.c
//         <o.0..9>Maximum Endpoint Packet Size (in bytes) <0-1023>
//         <i>Specifies the physical packet size used for information exchange.
//         <i>Maximum value is 1023.
#define USBD_ADC%Instance%_WMAXPACKETSIZE        64

//         <o.0..4>Endpoint polling Interval (in ms for FS, in 125 us intervals for HS) 
//         <i>Specifies the frequency of requests initiated by USB Host for 
//         <i>getting audio samples data.
//           <1=>    1 <2=>    2 <3=>     4 <4=>     8
//           <5=>   16 <6=>   32 <7=>    64 <8=>   128
//           <9=>  256 <10=> 512 <11=> 1024 <12=> 2048
//           <13=>4096 <14=>8192 <15=>16384 <16=>32768
#define USBD_ADC%Instance%_BINTERVAL             1

//       </h>

//       <h>High-speed
//       <i>Parameters apply when High-speed is enabled in USBD_Config_%Instance%.c
//
//         <o.0..10>Maximum Endpoint Packet Size (in bytes) <0-1024>
//         <i>Specifies the physical packet size used for information exchange.
//         <i>Maximum value is 1024.
//         <o.11..12>Additional transactions per micro-frame 
//         <i>Additional transactions improve communication performance.
//           <0=>None <1=>1 additional <2=>2 additional
#define USBD_ADC%Instance%_HS_WMAXPACKETSIZE     64

//       </h>
//     </h>
//   </h>

//   <h>Audio Device Class Settings
//   <i>Parameters are used to create USB Descriptors and for memory allocation 
//   <i>in the USB component.
//
//     <s.126>Audio Control Interface String
#define USBD_ADC%Instance%_CIF_STR_DESC          L"USB_ADC"

//     <s.126>Audio Streaming (Zero Bandwidth) Interface String
#define USBD_ADC%Instance%_SIF1_STR_DESC         L"USB_ADC1"

//     <s.126>Audio Streaming (Operational) Interface String
#define USBD_ADC%Instance%_SIF2_STR_DESC         L"USB_ADC2"

//     <o.0..7>Audio Subframe Size (in bytes) <0-255>
//     <i>Configures size of sample data in bytes.
#define USBD_ADC%Instance%_BSUBFRAMESIZE         2

//     <o.0..7>Sample Resolution (in bits) <0-255>
#define USBD_ADC%Instance%_BBITRESOLUTION        16

//     <o.0..23>Sample Frequency (in Hz) <0-16777215>
#define USBD_ADC%Instance%_TSAM_FREQ             32000

//     <o>Packet Size (in bytes) <1-256>
//     <i>Configures packet size used to calculate memory requirement for 
//     <i>sample buffer. 
#define USBD_ADC%Instance%_CFG_PACKET_SIZE       32

//     <o>Packet Count <1-16>
//     <i>Configures packet count used to calculate memory requirement for 
//     <i>sample buffer. 
#define USBD_ADC%Instance%_CFG_PACKET_COUNT      1

//   </h>

//   <h>OS Resources Settings
//   <i>These settings are used to optimize usage of OS resources.
//     <o>Audio Device Class Thread Stack Size <64-65536>
#define USBD_ADC%instance%_THREAD_STACK_SIZE     512

//        Audio Device Class Thread Priority
#define USBD_ADC%instance%_THREAD_PRIORITY       osPriorityAboveNormal

//   </h>
// </h>

/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    rl_usb.h
 * Purpose: USB User API
 * Rev.:    V5.10
 *----------------------------------------------------------------------------*/

#ifndef __RL_USB_H__
#define __RL_USB_H__


#ifdef __cplusplus
extern "C"  {
#endif

#include <stdint.h>
#include <stdbool.h>


//  ==== USB Constants and Defines ====

/// Status code values returned by USB library functions.
typedef enum {
  usbOK                       =    0,   ///< Function completed with no error

  usbTimeout,                           ///< Function completed; timeout occurred
  usbInvalidParameter,                  ///< Invalid Parameter error: a mandatory parameter was missing or specified an incorrect object

  usbThreadError              = 0x10,   ///< CMSIS-RTOS Thread creation/termination failed
  usbTimerError,                        ///< CMSIS-RTOS Timer creation/deletion failed
  usbMutexError,                        ///< CMSIS-RTOS Mutex creation failed

  usbControllerError          = 0x20,   ///< Controller does not exist
  usbDeviceError,                       ///< Device does not exist 
  usbDriverError,                       ///< Driver function produced error
  usbMemoryError,                       ///< Memory management function produced error
  usbNotConfigured,                     ///< Device is not configured (is connected)
  usbClassErrorADC,                     ///< Audio Device Class (ADC) error (no device or device produced error)
  usbClassErrorCDC,                     ///< Communication Device Class (CDC) error (no device or device produced error)
  usbClassErrorHID,                     ///< Human Interface Device (HID) error (no device or device produced error) 
  usbClassErrorMSC,                     ///< Mass Storage Device (MSC) error (no device or device produced error)
  usbClassErrorCustom,                  ///< Custom device Class (Class) error (no device or device produced error)
  usbUnsupportedClass,                  ///< Unsupported Class

  usbUnknownError             = 0xFF    ///< Unspecified USB error
} usbStatus;


//  ==== USB Device Functions ====

/// \brief Initialize USB Device stack and controller
/// \param[in]     device        index of USB Device.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBD_Initialize (int8_t device);

/// \brief Un-initialize USB Device stack and controller
/// \param[in]     device        index of USB Device.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBD_Uninitialize (int8_t device);

/// \brief Activate pull-up on D+ or D- line to signal USB Device connection on USB Bus
/// \param[in]     device        index of USB Device.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBD_Connect (int8_t device);

/// \brief Disconnect USB Device from USB Bus
/// \param[in]     device        index of USB Device.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBD_Disconnect (int8_t device);

/// \brief Return USB Device configuration status
/// \param[in]     device        index of USB Device.
/// \return        true          device is in configured state and ready to communicate.
/// \return        false         device is not configured and not ready to communicate. 
extern bool USBD_Configured (int8_t device);


//  ==== USB Device Custom Class Functions ====

#ifdef __DOXYGEN__

// following functions are available for each instance of a Custom class.
// generic prefix USBD_CustomClassn is USBD_CustomClassn for Custom class instance 0.

/// \brief Called during \ref USBD_Initialize to initialize the USB Custom class Device
/// \return        none.
void USBD_CustomClassn_Initialize (void);

/// \brief Called during \ref USBD_Uninitialize to un-initialize the USB Custom class Device
/// \return        none.
void USBD_CustomClassn_Uninitialize (void);

/// \brief Custom Class Reset Event handling
/// \return        none.
void USBD_CustomClassn_EventReset (void);

/// \brief Custom Class Endpoint Start Event handling
/// \param[in]     ep_addr       endpoint address.
/// \return        none.
void USBD_CustomClassn_EventEndpointStart (uint8_t ep_addr);

/// \brief Custom Class Endpoint Stop Event handling
/// \param[in]     ep_addr       endpoint address.
/// \return        none.
void USBD_CustomClassn_EventEndpointStop (uint8_t ep_addr);

/// \brief Callback function called when a SETUP PACKET was received on Control Endpoint 0
/// \param[in]     setup_packet            pointer to received setup packet.
/// \param[out]    buf                     pointer to data buffer used for data stage requested by setup packet.
/// \param[out]    len                     pointer to number of data bytes in data stage requested by setup packet.
/// \return        usbdRequestStatus       enumerator value indicating the function execution status
/// \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
/// \return        usbdRequestOK:          request was processed successfully (send Zero-Length Packet if no data stage)
/// \return        usbdRequestStall:       request was processed but is not supported (STALL EP)
usbdRequestStatus USBD_CustomClassn_Endpoint0_SetupPacketReceived (const USB_SETUP_PACKET *setup_packet, uint8_t **buf, int32_t *len);

/// \brief Callback function called when a SETUP PACKET was processed by USB library
/// \param[in]     setup_packet            pointer to processed setup packet.
/// \return        none.
void USBD_CustomClassn_Endpoint0_SetupPacketProcessed (const USB_SETUP_PACKET *setup_packet);

/// \brief Callback function called when OUT DATA was received on Control Endpoint 0
/// \param[in]     len                     number of received data bytes.
/// \return        usbdRequestStatus       enumerator value indicating the function execution status
/// \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
/// \return        usbdRequestOK:          request was processed successfully (send Zero-Length Packet)
/// \return        usbdRequestStall:       request was processed but is not supported (stall endpoint 0)
/// \return        usbdRequestNAK:         request was processed but the device is busy (return NAK)
usbdRequestStatus USBD_CustomClassn_Endpoint0_OutDataReceived (int32_t len);

/// \brief Callback function called when IN DATA was sent on Control Endpoint 0
/// \param[in]     len                     number of sent data bytes.
/// \return        usbdRequestStatus       enumerator value indicating the function execution status
/// \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
/// \return        usbdRequestOK:          request was processed successfully (return ACK)
/// \return        usbdRequestStall:       request was processed but is not supported (stall endpoint 0)
/// \return        usbdRequestNAK:         request was processed but the device is busy (return NAK)
usbdRequestStatus USBD_CustomClassn_Endpoint0_InDataSent (int32_t len);

/// \brief Callback function called when DATA was sent or received on Endpoint n
/// \param[in]     event                   event on Endpoint:
///                                          - ARM_USBD_EP_EVENT_OUT = data OUT received
///                                          - ARM_USBD_EP_EVENT_IN  = data IN  sent
void USBD_CustomClassn_Endpoint1_Event  (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint2_Event  (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint3_Event  (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint4_Event  (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint5_Event  (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint6_Event  (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint7_Event  (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint8_Event  (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint9_Event  (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint10_Event (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint11_Event (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint12_Event (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint13_Event (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint14_Event (ARM_USBD_EP_EVENT event);
void USBD_CustomClassn_Endpoint15_Event (ARM_USBD_EP_EVENT event);

#endif // __DOXYGEN

/// \brief Start reception on Endpoint
/// \param[in]     device        index of USB Device.
/// \param[in]     ep_addr       endpoint address.
/// \param[out]    buf           buffer that receives data.
/// \param[in]     len           maximum number of bytes to read.
/// \return                      status code that indicates the execution status of the function.
extern usbStatus USBD_EndpointReadStart (int8_t device, uint8_t ep_addr, uint8_t *buf, uint32_t len);

/// \brief Read data received on Endpoint
/// \param[in]     device        index of USB Device.
/// \param[in]     ep_addr       endpoint address.
/// \param[out]    buf           buffer that receives data.
/// \param[in]     len           maximum number of bytes to read.
/// \return                      number of bytes read or execution status.
///                - value >= 0: number of bytes read
///                - value < 0:  error occurred, -value is execution status as defined with \ref usbStatus 
extern int32_t USBD_EndpointRead (int8_t device, uint8_t ep_addr, uint8_t *buf, uint32_t len);

/// \brief Write data on Endpoint
/// \param[in]     device        index of USB Device.
/// \param[in]     ep_addr       endpoint address.
/// \param[in]     buf           buffer containing data bytes to write.
/// \param[in]     len           maximum number of bytes to write.
/// \return                      number of bytes accepted for writing or execution status.
///                - value >= 0: number of bytes accepted for writing
///                - value < 0:  error occurred, -value is execution status as defined with \ref usbStatus 
extern int32_t USBD_EndpointWrite (int8_t device, uint8_t ep_addr, const uint8_t *buf, uint32_t len);

/// \brief Set/Clear stall on Endpoint
/// \param[in]     device        index of USB Device.
/// \param[in]     ep_addr       endpoint address.
/// \param[in]     stall         false = Clear stall, true = Set stall.
/// \return                      status code that indicates the execution status of the function.

extern usbStatus USBD_EndpointStall (int8_t device, uint8_t ep_addr, bool stall);

/// \brief Abort transfer on Endpoint
/// \param[in]     device        index of USB Device.
/// \param[in]     ep_addr       endpoint address.
/// \return                      status code that indicates the execution status of the function.

extern usbStatus USBD_EndpointAbort (int8_t device, uint8_t ep_addr);


//  ==== USB Device Audio Device Functions ====

#ifdef __DOXYGEN__

// following functions are available for each instance of a ADC class.
// generic prefix USBD_ADCn is USBD_ADC0 for ADC class instance 0.

/// \brief Called during \ref USBD_Initialize to initialize the USB ADC class Device
/// \return        none.
void USBD_ADCn_Initialize (void);
 
/// \brief Called during \ref USBD_Uninitialize to un-initialize the USB ADC class Device
/// \return        none.
void USBD_ADCn_Uninitialize (void);

#endif // __DOXYGEN

/// \brief Read audio samples received from USB Host
/// \param[in]     instance      instance of ADC class.
/// \param[out]    buf           buffer that receives samples.
/// \param[in]     num           maximum number of samples to read.
/// \return                      number of samples read or execution status.
///                - value >= 0: number of samples read
///                - value < 0:  error occurred, -value is execution status as defined with \ref usbStatus 
extern int32_t USBD_ADC_ReadSample (int8_t instance, void *buf, int32_t num);

/// \brief Write audio samples to be transfered to USB Host
/// \param[in]     instance      instance of ADC class.
/// \param[in]     buf           buffer containing samples to write.
/// \param[in]     num           maximum number of samples to write.
/// \return                      number of samples accepted for writing or execution status.
///                - value >= 0: number of samples accepted for writing
///                - value < 0:  error occurred, -value is execution status as defined with \ref usbStatus 
extern int32_t USBD_ADC_WriteSample (int8_t instance, const uint8_t *buf, int32_t num);


//  ==== USB Device Communication Device (Abstract Control Model) Functions ====

#ifdef __DOXYGEN__

// following functions are available for each instance of a CDC class.
// generic prefix USBD_CDCn is USBD_CDC0 for CDC class instance 0.

/// \brief Called during \ref USBD_Initialize to initialize the USB CDC class Device (Virtual COM Port)
/// \return        none.
void USBD_CDCn_ACM_Initialize (void);

/// \brief Called during \ref USBD_Uninitialize to un-initialize the USB CDC class Device (Virtual COM Port)
/// \return        none.
void USBD_CDCn_ACM_Uninitialize (void);

/// \brief Called during USB Bus reset to reset the USB CDC class Device (Virtual COM Port)
/// \return        none.
void USBD_CDCn_ACM_Reset (void);

/// \brief Change communication settings of USB CDC class Device (Virtual COM Port)
/// \param[in]     line_coding   pointer to CDC_LINE_CODING structure.
/// \return        true          set line coding request processed.
/// \return        false         set line coding request not supported or not processed.
bool USBD_CDCn_ACM_SetLineCoding (CDC_LINE_CODING *line_coding);

/// \brief Retrieve communication settings of USB CDC class Device (Virtual COM Port)
/// \param[out]    line_coding   pointer to CDC_LINE_CODING structure.
/// \return        true          get line coding request processed.
/// \return        false         get line coding request not supported or not processed.
bool USBD_CDCn_ACM_GetLineCoding (CDC_LINE_CODING *line_coding);

/// \brief Set control line states of USB CDC class Device (Virtual COM Port)
/// \param[in]     state         control line settings bitmap.
///                                - bit 0: DTR state 
///                                - bit 1: RTS state
/// \return        true          set control line state request processed.
/// \return        false         set control line state request not supported or not processed.
bool USBD_CDCn_ACM_SetControlLineState (uint16_t state);

#endif // __DOXYGEN

/// \brief Read one character received by Communication Device from USB Host
/// \param[in]     instance      instance of CDC class.
/// \return                      value of read character or no character received.
///                - value >= 0: value of first received unread character
///                - value -1:   indicates no character was received
extern int USBD_CDC_ACM_GetChar (int8_t instance);

/// \brief Write a single character from Communication Device to USB Host
/// \param[in]     instance      instance of CDC class.
/// \param[in]     ch            character to write.
/// \return                      value of accepted character or no character accepted.
///                - value ch:   if character accepted for writing
///                - value -1:   indicates character not accepted
extern int USBD_CDC_ACM_PutChar (int8_t instance, int ch);

/// \brief Read multiple data bytes received by Communication Device from USB Host
/// \param[in]     instance      instance of CDC class.
/// \param[out]    buf           buffer that receives data.
/// \param[in]     len           maximum number of bytes to read.
/// \return                      number of bytes read or execution status.
///                - value >= 0: number of bytes read
///                - value < 0:  error occurred, -value is execution status as defined with \ref usbStatus 
extern int32_t USBD_CDC_ACM_ReadData (int8_t instance, uint8_t *buf, int32_t len);

/// \brief Write data from Communication Device to USB Host
/// \param[in]     instance      instance of CDC class.
/// \param[in]     buf           buffer containing data bytes to write.
/// \param[in]     len           maximum number of bytes to write.
/// \return                      number of bytes accepted for writing or execution status.
///                - value >= 0: number of bytes accepted for writing
///                - value < 0:  error occurred, -value is execution status as defined with \ref usbStatus 
extern int32_t USBD_CDC_ACM_WriteData (int8_t instance, const uint8_t *buf, int32_t len);

/// \brief Retrieve number of data bytes received by Communication Device from  
///        USB Host that are available to read
/// \param[in]     instance      instance of CDC class.
/// \return                      number of bytes available to read.
extern int32_t USBD_CDC_ACM_DataAvailable (int8_t instance);

/// \brief Send notification of Communication Device status and line states to USB Host
/// \param[in]     instance      instance of CDC class.
/// \param[in]     state         error status and line states:
///                                - bit 6: bOverRun
///                                - bit 5: bParity
///                                - bit 4: bFraming 
///                                - bit 3: bRingSignal 
///                                - bit 2: bBreak 
///                                - bit 1: bTxCarrier (DSR line state) 
///                                - bit 0: bRxCarrier (DCD line state)
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBD_CDC_ACM_Notify (int8_t instance, uint16_t state);

/// \brief Callback function indicating new data was received by  
///        Communication Device from USB Host
/// \param[in]     instance      instance of CDC class.
/// \param[in]     len           number of bytes available to read.
/// \return        none.
extern void USBD_CDC_ACM_DataReceived (int8_t instance, int32_t len);


//  ==== USB Device Human Interface Device Functions ====

#ifdef __DOXYGEN__

// following functions are available for each instance of a HID class.
// generic prefix USBD_HIDn is USBD_HID0 for HID class instance 0.

/// \brief Called during \ref USBD_Initialize to initialize the USB HID class Device
/// \return        none.
void USBD_HIDn_Initialize (void);
 
/// \brief Called during \ref USBD_Uninitialize to un-initialize the USB HID class Device
/// \return        none.
void USBD_HIDn_Uninitialize (void);
 
/// \brief Prepare HID Report data to send
/// \param[in]     rtype         report type:
///                  - HID_REPORT_INPUT           = input report requested
///                  - HID_REPORT_FEATURE         = feature report requested
/// \param[in]     req           request type:
///                  - USBD_HID_REQ_EP_CTRL       = control endpoint request
///                  - USBD_HID_REQ_PERIOD_UPDATE = idle period expiration request
///                  - USBD_HID_REQ_EP_INT        = previously sent report on interrupt endpoint request
/// \param[in]     rid           report ID (0 if only one report exists).
/// \param[out]    buf           buffer containing report data to send.
/// \return                      number of report data bytes prepared to send or invalid report requested.
///                - value >= 0: number of report data bytes prepared to send
///                - value = -1: invalid report requested
int32_t USBD_HIDn_GetReport (uint8_t rtype, uint8_t req, uint8_t rid, uint8_t *buf);

/// \brief Process received HID Report data
/// \param[in]     rtype         report type:
///                  - HID_REPORT_OUTPUT    = output report received
///                  - HID_REPORT_FEATURE   = feature report received
/// \param[in]     req           request type:
///                  - USBD_HID_REQ_EP_CTRL = report received on control endpoint
///                  - USBD_HID_REQ_EP_INT  = report received on interrupt endpoint
/// \param[in]     rid           report ID (0 if only one report exists).
/// \param[in]     buf           buffer that receives report data.
/// \param[in]     len           length of received report data.
/// \return        true          received report data processed.
/// \return        false         received report data not processed or request not supported.
bool USBD_HIDn_SetReport (uint8_t rtype, uint8_t req, uint8_t rid, const uint8_t *buf, int32_t len);

#endif // __DOXYGEN

/// \brief Asynchronously prepare HID Report data to send
/// \param[in]     instance      instance of HID class.
/// \param[in]     rid           report ID.
/// \param[out]    buf           buffer containing report data to send.
/// \param[in]     len           number of report data bytes to send.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBD_HID_GetReportTrigger (int8_t instance, uint8_t rid, const uint8_t *buf, int32_t len);


#ifdef __DOXYGEN__

//  ==== USB Device Mass Storage Device Functions ====

// following functions are available for each instance of a MSC class.
// generic prefix USBD_MSCn is USBD_MSC0 for MSC class instance 0.

/// \brief Called during \ref USBD_Initialize to initialize the USB MSC class Device
/// \return        none.
void USBD_MSCn_Initialize (void);
 
/// \brief Called during \ref USBD_Uninitialize to un-initialize the USB MSC class Device
/// \return        none.
void USBD_MSCn_Uninitialize (void);

/// \brief Read data from media
/// \param[in]     lba           logical address of first block to read.
/// \param[in]     cnt           number of contiguous blocks to read from media.
/// \param[out]    buf           data buffer for data read from media.
/// \return        true          read succeeded.
/// \return        false         read failed.
bool USBD_MSCn_Read (uint32_t lba, uint16_t cnt, uint8_t *buf);

/// \brief Write data to media
/// \param[in]     lba           logical address of first block to write.
/// \param[in]     cnt           number of contiguous blocks to write to media.
/// \param[out]    buf           data buffer containing data to write to media.
/// \return        true          write succeeded.
/// \return        false         write failed.
bool USBD_MSCn_Write (uint32_t lba, uint16_t cnt, const uint8_t *buf);

#endif // __DOXYGEN


//  ==== USB Host Functions ====

/// \brief Initialize USB Host stack and controller
/// \param[in]     ctrl          index of USB Host controller.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBH_Initialize (uint8_t ctrl);

/// \brief Un-initialize USB Host stack and controller
/// \param[in]     ctrl          index of USB Host controller.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBH_Uninitialize (uint8_t ctrl);

/// \brief Get status of USB Device.
/// \param[in]     device        index of USB Device.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBH_GetDeviceStatus (int8_t device);


//  ==== USB Host Mass Storage Functions ====

/// \brief Get status of Mass Storage Device
/// \param[in]     instance      instance of MSC Device.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBH_MSC_GetDeviceStatus (int8_t instance);

/// \brief Read requested number of blocks from Mass Storage Device
/// \param[in]     instance      instance of MSC Device.
/// \param[in]     lba           logical block address of first block to read.
/// \param[in]     cnt           number of contiguous blocks to read.
/// \param[out]    buf           data buffer in which to read data.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBH_MSC_Read (int8_t instance, uint32_t lba, uint16_t cnt, uint8_t *buf);

/// \brief Write requested number of blocks to Mass Storage Device
/// \param[in]     instance      instance of MSC Device.
/// \param[in]     lba           logical address of first block to write.
/// \param[in]     cnt           number of contiguous blocks to write.
/// \param[in]     buf           data buffer containing data to write.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBH_MSC_Write (int8_t instance, uint32_t lba, uint16_t cnt, const uint8_t *buf);

/// \brief Read capacity of Mass Storage Device
/// \param[in]     instance      instance of MSC Device.
/// \param[out]    block_count   pointer to where total number of blocks available will be read.
/// \param[out]    block_size    pointer to where block size will be read.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBH_MSC_ReadCapacity (int8_t instance, uint32_t *block_count, uint32_t *block_size);


//  ==== USB Host Human Interface Device Functions ====

/// \brief Get status of Human Interface Device
/// \param[in]     instance      instance of HID Device.
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBH_HID_GetDeviceStatus (int8_t instance);

/// \brief Read data received from Human Interface Device
/// \param[in]     instance      instance of HID Device.
/// \param[out]    buf           buffer that receives data.
/// \param[in]     len           maximum number of bytes to read.
/// \return                      number of bytes read or execution status.
///                - value >= 0: number of bytes read
///                - value < 0:  error occurred, -value is execution status as defined with \ref usbStatus 
extern int32_t USBH_HID_Read (int8_t instance, uint8_t *buf, int32_t len);

/// \brief Write data to Human Interface Device
/// \param[in]     instance      instance of HID Device.
/// \param[in]     buf           data buffer containing data to write.
/// \param[in]     len           number of data bytes to write.
/// \return                      number of bytes accepted for writing or execution status.
///                - value >= 0: number of bytes accepted for writing
///                - value < 0:  error occurred, -value is execution status as defined with \ref usbStatus 
extern int32_t USBH_HID_Write (int8_t instance, const uint8_t *buf, int32_t len);

/// \brief Retrieve first pending pressed keyboard key on HID Keyboard
/// \param[in]     instance      instance of HID Device.
/// \return                      value of read character or no character received.
///                - value >= 0: value of first received unread character
///                - value -1:   indicates no character was received
extern int USBH_HID_GetKeyboardKey (int8_t instance);  

/// Mouse state information.
typedef struct _usbHID_MouseState {
  uint8_t button;           ///< Current button states
  int16_t x;                ///< Absolute X position change
  int16_t y;                ///< Absolute Y position change
} usbHID_MouseState;

/// \brief Retrieve state change since last call of this function
/// \param[in]     instance      instance of HID Device.
/// \param[out]    state         pointer to mouse state \ref usbHID_MouseState structure. 
/// \return                      status code that indicates the execution status of the function as defined with \ref usbStatus.
extern usbStatus USBH_HID_GetMouseState (int8_t instance, usbHID_MouseState *state);


#ifdef __cplusplus
}
#endif

#endif

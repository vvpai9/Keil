/* ----------------------------------------------------------------------
 * Copyright (C) 2013 ARM Limited. All rights reserved.
 *  
 * $Date:        7. November 2013
 * $Revision:    V1.20
 *  
 * Project:      USB Host Driver for Middleware
 * -------------------------------------------------------------------- */

/* History:
 *  Version 1.20
 *    Added API for OHCI/EHCI Host Controller Interface (HCI)
 *  Version 1.10
 *    Namespace prefix ARM_ added
 *  Version 1.00
 *    Initial release
 */ 

#ifndef __DRIVER_USBH_H
#define __DRIVER_USBH_H

#include "Driver_USB.h"

#define ARM_USBH_API_VERSION ARM_DRV_VERSION_MAJOR_MINOR(1,20)    /* API version */

/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif


/**
\brief USB Host State
*/
typedef struct _ARM_USBH_STATE {
  uint8_t connected   : 1;              ///< USB Host connected flag
  uint8_t overcurrent : 1;              ///< USB Host overcurrent flag
  uint8_t active      : 1;              ///< USB Host active flag
  uint8_t speed       : 2;              ///< USB Host speed setting
} ARM_USBH_STATE;

/**
\brief USB Host USB Request Block (URB)
*/
typedef struct _ARM_USBH_URB {          ///< USB Request Block (URB)
  uint8_t     *buf;                     ///< Buffer for read/write data
  uint32_t     len;                     ///< Requested read/write length
  uint8_t     *buf_cur;                 ///< Current position in read/write buffer
  uint32_t     len_cur;                 ///< Current length transferred
  union {
    uint8_t    parameters;              ///< Transfer Parameters
    struct {
      uint8_t  packet_type         : 4; ///< Packet Type
      uint8_t  toggle_bit          : 1; ///< Toggle Bit Value
      uint8_t  toggle_force        : 1; ///< Toggle Bit Forced (if cleared toggle_bit value is ignored)
    };
  };
  union {
    uint16_t   status;                  ///< Status
    struct {
      uint16_t submitted           : 1; ///< Submit status
      uint16_t in_progress         : 1; ///< Processing in progress status
      uint16_t cancelled           : 1; ///< Cancel status
      uint16_t completed           : 1; ///< Completion status
      uint16_t response_packet_type: 4; ///< Response packet type
      uint16_t error               : 1; ///< Error status
    };
  };
  uint32_t     nak_retries;             ///< Number of NAK retries
} ARM_USBH_URB;

/**
\brief USB Host Endpoint Handle
*/
typedef uint32_t ARM_USBH_EP_HANDLE;


/**
\brief USB Host Status of executed operation
*/
typedef enum _ARM_USBH_STATUS {
  ARM_USBH_OK       =  0,               ///< USBH Status: Operation succeeded
  ARM_USBH_ERROR    =  1                ///< USBH Status: Unspecified error
} ARM_USBH_STATUS;


/**
\brief USB Host Root HUB Port Event Type
*/
typedef enum _ARM_USBH_EVENT {
  ARM_USBH_EVENT_CONNECT,               ///< USBH Event: USB Device Connected to Port
  ARM_USBH_EVENT_DISCONNECT,            ///< USBH Event: USB Device Disconnected from Port
  ARM_USBH_EVENT_REMOTE_WAKEUP,         ///< USBH Event: USB Device activated Remote Wakeup
  ARM_USBH_EVENT_OVERCURRENT            ///< USBH Event: USB Device caused Overcurrent
} ARM_USBH_EVENT;


#ifndef __DOXYGEN_MW__                  // exclude from middleware documentation

// Function documentation
/**
  \fn          ARM_DRV_VERSION ARM_USBH_GetVersion (void)
  \brief       Get driver version.
  \return      \ref ARM_DRV_VERSION
*/
/**
  \fn          ARM_USBH_CAPABILITIES ARM_USBH_GetCapabilities (void)
  \brief       Get driver capabilities.
  \return      \ref ARM_USBH_CAPABILITIES
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_Initialize (ARM_USBH_SignalPortEvent_t     cb_port_event,
                                                    ARM_USBH_SignalEndpointEvent_t cb_endpoint_event)
  \brief       Initialize USB Host Interface.
  \param[in]   cb_port_event      Pointer to \ref ARM_USBH_SignalPortEvent
  \param[in]   cb_endpoint_event  Pointer to \ref ARM_USBH_SignalEndpointEvent
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_Uninitialize (void)
  \brief       De-initialize USB Host Interface.
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_PowerControl (ARM_POWER_STATE state)
  \brief       Control USB Host Interface Power.
  \param[in]   state Power state
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_PortPowerOnOff (uint8_t port, bool power)
  \brief       Root HUB Port Power on/off.
  \param[in]   port  Root HUB Port Number
  \param[in]   power Operation
                - \b false Power off
                - \b true  Power on
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_PortReset (uint8_t port)
  \brief       Do Root HUB Port Reset.
  \param[in]   port Root HUB Port Number
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_PortSuspend (uint8_t port)
  \brief       Suspend Root HUB Port (stop generating SOFs).
  \param[in]   port Root HUB Port Number
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_PortResume (uint8_t port)
  \brief       Resume Root HUB Port (start generating SOFs).
  \param[in]   port Root HUB Port Number
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USB_STATUS ARM_USBH_PortGetState (uint8_t port)
  \brief       Get current Root HUB Port connection State.
  \param[in]   port Root HUB Port Number
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_EP_HANDLE ARM_USBH_EndpointCreate (uint8_t ep_addr,
                                                           ARM_USB_ENDPOINT_TYPE ep_type,
                                                           uint16_t ep_max_packet_size,
                                                           uint8_t  ep_interval)
  \brief       Create Endpoint in System.
  \param[in]   ep_addr  Endpoint Address
                - ep_addr.0..3: Address
                - ep_addr.7:    Direction
  \param[in]   ep_type  Endpoint Type
  \param[in]   ep_max_packet_size Endpoint Maximum Packet Size
  \param[in]   ep_interval        Endpoint Polling Interval
  \return      Endpoint Handle \ref ARM_USBH_EP_HANDLE
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_EndpointConfigure (ARM_USBH_EP_HANDLE ep_hndl,
                                                           uint8_t dev_addr,
                                                           uint8_t ep_speed,
                                                           uint8_t ep_addr,
                                                           ARM_USB_ENDPOINT_TYPE ep_type,
                                                           uint16_t ep_max_packet_size,
                                                           uint8_t  ep_interval)
  \brief       Configure/reconfigure some properties of Endpoint.
  \param[in]   ep_hndl  Endpoint Handle
  \param[in]   dev_addr Device Address
  \param[in]   ep_speed Endpoint Speed
  \param[in]   ep_addr  Endpoint Address
                - ep_addr.0..3: Address
                - ep_addr.7:    Direction
  \param[in]   ep_type  Endpoint Type
  \param[in]   ep_max_packet_size Endpoint Maximum Packet Size
  \param[in]   ep_interval        Endpoint Polling Interval
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_EndpointDelete (ARM_USBH_EP_HANDLE ep_hndl)
  \brief       Delete Endpoint from System.
  \param[in]   ep_hndl  Endpoint Handle
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_EndpointClearHalt (ARM_USBH_EP_HANDLE ep_hndl)
  \brief       Clear Halt condition on USB Endpoint.
  \param[in]   ep_hndl  Endpoint Handle
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_URB_Submit (ARM_USBH_EP_HANDLE ep_hndl, ARM_USBH_URB *ptr_urb)
  \brief       Submit USB Request Block (URB) for Processing.
  \param[in]   ep_hndl  Endpoint Handle
  \param[in]   ptr_urb  Pointer to USB Request Block (URB)
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_URB_Abort (ARM_USBH_EP_HANDLE ep_hndl, ARM_USBH_URB *ptr_urb)
  \brief       Abort Processing of USB Request Block (URB).
  \param[in]   ep_hndl  Endpoint Handle
  \param[in]   ptr_urb  Pointer to USB Request Block (URB)
  \return      execution status \ref ARM_USBH_STATUS
*/

/**
  \fn          void ARM_USBH_SignalPortEvent (uint8_t port, ARM_USBH_EVENT event)
  \brief       Signal Root HUB Port Event.
  \param[in]   port  Root HUB Port Number
  \param[in]   event \ref ARM_USBH_EVENT
  \return      none
*/
/**
  \fn          void ARM_USBH_SignalEndpointEvent (ARM_USBH_EP_HANDLE ep_hndl, ARM_USBH_URB *ptr_urb)
  \brief       Signal Endpoint Event.
               Occurs when URB processing completes.
  \param[in]   ep_hndl  Endpoint Handle
  \param[in]   ptr_urb  Pointer to URB
  \return      none
*/

typedef void (*ARM_USBH_SignalPortEvent_t)     (uint8_t port, ARM_USBH_EVENT event);                 ///< Pointer to \ref ARM_USBH_SignalPortEvent : Signal Root HUB Port Event.
typedef void (*ARM_USBH_SignalEndpointEvent_t) (ARM_USBH_EP_HANDLE ep_hndl, ARM_USBH_URB *ptr_urb);  ///< Pointer to \ref ARM_USBH_SignalEndpointEvent : Signal Endpoint Event.

/**
\brief  USB Host Driver Capabilities.
*/
typedef struct _ARM_USBH_CAPABILITIES {
  uint32_t rh_port_mask        : 16;    ///< Root HUB available Ports Mask
  uint32_t event_connect       :  1;    ///< Signal Connect event
  uint32_t event_disconnect    :  1;    ///< Signal Disconnect event
  uint32_t event_remote_wakeup :  1;    ///< Signal Remote Wakeup event
  uint32_t event_overcurrent   :  1;    ///< Signal Overcurrent event
  uint32_t reserved            : 12;    ///< reserved for future use
} ARM_USBH_CAPABILITIES;


/**
\brief  Access structure of USB Host Driver.
*/
typedef struct _ARM_DRIVER_USBH {
  ARM_DRV_VERSION       (*GetVersion)        (void);                                             ///< Pointer to \ref ARM_USBH_GetVersion : Get driver version.
  ARM_USBH_CAPABILITIES (*GetCapabilities)   (void);                                             ///< Pointer to \ref ARM_USBH_GetCapabilities : Get driver capabilities.
  ARM_USBH_STATUS       (*Initialize)        (ARM_USBH_SignalPortEvent_t     cb_port_event,            
                                              ARM_USBH_SignalEndpointEvent_t cb_endpoint_event); ///< Pointer to \ref ARM_USBH_Initialize : Initialize USB Host Interface.
  ARM_USBH_STATUS       (*Uninitialize)      (void);                                             ///< Pointer to \ref ARM_USBH_Uninitialize : De-initialize USB Host Interface.
  ARM_USBH_STATUS       (*PowerControl)      (ARM_POWER_STATE state);                            ///< Pointer to \ref ARM_USBH_PowerControl : Control USB Host Interface Power.
  ARM_USBH_STATUS       (*PortPowerOnOff)    (uint8_t port, bool power);                         ///< Pointer to \ref ARM_USBH_PortPowerOnOff : Root HUB Port Power on/off.
  ARM_USBH_STATUS       (*PortReset)         (uint8_t port);                                     ///< Pointer to \ref ARM_USBH_PortReset : Do Root HUB Port Reset.
  ARM_USBH_STATUS       (*PortSuspend)       (uint8_t port);                                     ///< Pointer to \ref ARM_USBH_PortSuspend : Suspend Root HUB Port (stop generating SOFs).
  ARM_USBH_STATUS       (*PortResume)        (uint8_t port);                                     ///< Pointer to \ref ARM_USBH_PortResume : Resume Root HUB Port (start generating SOFs).
  ARM_USBH_STATE        (*PortGetState)      (uint8_t port);                                     ///< Pointer to \ref ARM_USBH_PortGetState : Get current Root HUB Port connection State.
  ARM_USBH_EP_HANDLE    (*EndpointCreate)    (uint8_t ep_addr,
                                              ARM_USB_ENDPOINT_TYPE ep_type,
                                              uint16_t ep_max_packet_size,
                                              uint8_t  ep_interval);                             ///< Pointer to \ref ARM_USBH_EndpointCreate : Create Endpoint in System.
  ARM_USBH_STATUS       (*EndpointConfigure) (ARM_USBH_EP_HANDLE ep_hndl,
                                              uint8_t dev_addr,
                                              uint8_t ep_speed,
                                              uint8_t ep_addr,
                                              ARM_USB_ENDPOINT_TYPE ep_type,
                                              uint16_t ep_max_packet_size,
                                              uint8_t  ep_interval);                             ///< Pointer to \ref ARM_USBH_EndpointConfigure : Configure/reconfigure some properties of Endpoint.
  ARM_USBH_STATUS       (*EndpointDelete)    (ARM_USBH_EP_HANDLE ep_hndl);                       ///< Pointer to \ref ARM_USBH_EndpointDelete : Delete Endpoint from System.
  ARM_USBH_STATUS       (*EndpointClearHalt) (ARM_USBH_EP_HANDLE ep_hndl);                       ///< Pointer to \ref ARM_USBH_EndpointClearHalt : Clear Halt condition on Endpoint.
  ARM_USBH_STATUS       (*URB_Submit)        (ARM_USBH_EP_HANDLE ep_hndl,
                                              ARM_USBH_URB *ptr_urb);                            ///< Pointer to \ref ARM_USBH_URB_Submit : Submit USB Request Block (URB) for Processing.
  ARM_USBH_STATUS       (*URB_Abort)         (ARM_USBH_EP_HANDLE ep_hndl,
                                              ARM_USBH_URB *ptr_urb);                            ///< Pointer to \ref ARM_USBH_URB_Abort : Abort Processing of USB Request Block (URB).
} const ARM_DRIVER_USBH;

// Function documentation
/**
  \fn          ARM_DRV_VERSION ARM_USBH_HCI_GetVersion (void)
  \brief       Get USB Host HCI (OHCI/EHCI) driver version.
  \return      \ref ARM_DRV_VERSION
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_HCI_Initialize (ARM_USBH_HCI_Interrupt_t *cb_interrupt)
  \brief       Initialize USB Host HCI (OHCI/EHCI) Interface.
  \param[in]   cb_interrupt Pointer to Interrupt Handler Routine
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_HCI_Uninitialize (void)
  \brief       De-initialize USB Host HCI (OHCI/EHCI) Interface.
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_HCI_PowerControl (ARM_POWER_STATE state)
  \brief       Control USB Host HCI (OHCI/EHCI) Interface Power.
  \param[in]   state Power state
  \return      execution status \ref ARM_USBH_STATUS
*/
/**
  \fn          ARM_USBH_STATUS ARM_USBH_HCI_PortPowerOnOff (uint8_t port, bool power)
  \brief       USB Host HCI (OHCI/EHCI) Root HUB Port Power on/off.
  \param[in]   port  Root HUB Port Number
  \param[in]   power Operation
                - \b false Power off
                - \b true  Power on
  \return      execution status \ref ARM_USBH_STATUS
*/

typedef void (*ARM_USBH_HCI_Interrupt_t) (void);                                ///< Pointer to Interrupt Handler Routine.

/**
  \struct ARM_DRIVER_USBH_HCI
  \brief  Access structure of USB Host HCI (OHCI/EHCI) Driver.
*/
typedef struct _ARM_DRIVER_USBH_HCI {
  ARM_DRV_VERSION (*GetVersion)     (void);                                     ///< Pointer to \ref ARM_USBH_HCI_GetVersion : Get USB Host HCI (OHCI/EHCI) driver version.
  ARM_USBH_STATUS (*Initialize)     (ARM_USBH_HCI_Interrupt_t cb_interrupt);    ///< Pointer to \ref ARM_USBH_HCI_Initialize : Initialize USB Host HCI (OHCI/EHCI) Interface.
  ARM_USBH_STATUS (*Uninitialize)   (void);                                     ///< Pointer to \ref ARM_USBH_HCI_Uninitialize : De-initialize USB Host HCI (OHCI/EHCI) Interface.
  ARM_USBH_STATUS (*PowerControl)   (ARM_POWER_STATE state);                    ///< Pointer to \ref ARM_USBH_HCI_PowerControl : Control USB Host HCI (OHCI/EHCI) Interface Power.
  ARM_USBH_STATUS (*PortPowerOnOff) (uint8_t port, bool power);                 ///< Pointer to \ref ARM_USBH_HCI_PortPowerOnOff : USB Host HCI (OHCI/EHCI) Root HUB Port Power on/off.
} const ARM_DRIVER_USBH_HCI;

#endif /* __DOXYGEN_MW__ */

/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif

#endif /* __DRIVER_USBH_H */

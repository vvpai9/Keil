/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Device
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    usbd_config_desc_macros.h
 * Purpose: USB Device Descriptor Creation Macros
 * Rev.:    V5.10
 *----------------------------------------------------------------------------*/

#define WBVAL(x)                       (x & 0xFF),((x >> 8) & 0xFF)
#define B3VAL(x)                       (x & 0xFF),((x >> 8) & 0xFF),((x >> 16) & 0xFF)
#define USB_DEVICE_DESC_SIZE           (sizeof(USB_DEVICE_DESCRIPTOR))
#define USB_DEVICE_QUALI_SIZE          (sizeof(USB_DEVICE_QUALIFIER_DESCRIPTOR))
#define USB_CONFIGURATION_DESC_SIZE    (sizeof(USB_CONFIGURATION_DESCRIPTOR))
#define USB_INTERFACE_ASSOC_DESC_SIZE  (sizeof(USB_INTERFACE_ASSOCIATION_DESCRIPTOR))
#define USB_INTERFACE_DESC_SIZE        (sizeof(USB_INTERFACE_DESCRIPTOR))
#define USB_ENDPOINT_DESC_SIZE         (sizeof(USB_ENDPOINT_DESCRIPTOR))
#define USB_HID_DESC_SIZE              (sizeof(HID_DESCRIPTOR))

#define USBD_EP0(n)                               /* Endpoint 0 */                                            \
  /* Endpoint 0 */                                                                                            \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  0,                                              /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_CONTROL,                      /* bmAttributes */                                          \
  WBVAL(USBD##n##_MAX_PACKET0),                   /* wMaxPacketSize */                                        \
  0                                               /* bInterval */

  /* USB Device Custom Class n Interface x Interface Descriptor */
#define USBD_CUSTOM_CLASSn_IFx_DESC(n,x)                                                                      \
  USB_INTERFACE_DESC_SIZE,                        /* bLength */                                               \
  USB_INTERFACE_DESCRIPTOR_TYPE,                  /* bDescriptorType */                                       \
  USBD_CUSTOM_CLASS##n##_IF##x##_NUM,             /* bInterfaceNumber */                                      \
  USBD_CUSTOM_CLASS##n##_IF##x##_ALT,             /* bAlternateSetting */                                     \
  USBD_CUSTOM_CLASS##n##_IF##x##_EP_CNT,          /* bNumEndpoints */                                         \
  USBD_CUSTOM_CLASS##n##_IF##x##_CLASS,           /* bInterfaceClass */                                       \
  USBD_CUSTOM_CLASS##n##_IF##x##_SUBCLASS,        /* bInterfaceSubClass */                                    \
  USBD_CUSTOM_CLASS##n##_IF##x##_PROTOCOL,        /* bInterfaceProtocol */                                    \
  USBD_CUSTOM_CLASS##n##_IF##x##_STR_IDX,         /* iInterface */

  /* USB Device Custom Class n Interface x Endpoint Descriptor with bInterval = 0
     typ   = BULK, INT or ISO, 
     type  = BULK, INTERRUPT or ISOCHRONOUS, 
     dir   = OUT or IN,
     spd   = FS  or HS */
#define USBD_CUSTOM_CLASSn_IFx_EP(n,x,typ,type,dir,spd)                                                       \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_##dir(USBD_CUSTOM_CLASS##n##_IF##x##_EP_##typ##_##dir),              /* bEndpointAddress */    \
  USB_ENDPOINT_TYPE_##type,                       /* bmAttributes */                                          \
  WBVAL(USBD_CUSTOM_CLASS##n##_IF##x##_EP_##typ##_##dir##_##spd##_WMAXPACKETSIZE),  /* wMaxPacketSize */      \
  0,                                              /* bInterval */

  /* USB Device Custom Class n Interface x Endpoint Descriptor with bInterval from definition
     typ   = BULK, INT or ISO, 
     type  = BULK, INTERRUPT or ISOCHRONOUS, 
     dir   = OUT or IN,
     spd   = FS  or HS */
#define USBD_CUSTOM_CLASSn_IFx_EP_w_BINTERVAL(n,x,typ,type,dir,spd)                                           \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_##dir(USBD_CUSTOM_CLASS##n##_IF##x##_EP_##typ##_##dir),              /* bEndpointAddress */    \
  USB_ENDPOINT_TYPE_##type,                       /* bmAttributes */                                          \
  WBVAL(USBD_CUSTOM_CLASS##n##_IF##x##_EP_##typ##_##dir##_##spd##_WMAXPACKETSIZE),  /* wMaxPacketSize */      \
  USBD_CUSTOM_CLASS##n##_IF##x##_EP_##typ##_##dir##_##spd##_BINTERVAL,              /* bInterval */

  /* USB Device Custom Class n Interface Association Descriptor */
#define USBD_CUSTOM_CLASSn_IAD(n)                 /* IAD: Interface Association Descriptor */                 \
  USB_INTERFACE_ASSOC_DESC_SIZE,                  /* bLength */                                               \
  USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE,      /* bDescriptorType */                                       \
  USBD_CUSTOM_CLASS##n##_IF0_NUM,                 /* bFirstInterface */                                       \
  USBD_CUSTOM_CLASS##n##_IF_CNT,                  /* bInterfaceCount */                                       \
  USBD_CUSTOM_CLASS##n##_IF0_CLASS,               /* bFunctionClass */                                        \
  USBD_CUSTOM_CLASS##n##_IF0_SUBCLASS,            /* bFunctionSubclass */                                     \
  USBD_CUSTOM_CLASS##n##_IF0_PROTOCOL,            /* bFunctionProtocol */                                     \
  USBD_CUSTOM_CLASS##n##_IF0_STR_IDX,             /* iFunction */                                             \

#define USBD_ADCn_IAD(n,first,num_of_ifs)         /* ADC: Interface Association Descriptor */                 \
  USB_INTERFACE_ASSOC_DESC_SIZE,                  /* bLength */                                               \
  USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE,      /* bDescriptorType */                                       \
 (first),                                         /* bFirstInterface */                                       \
 (num_of_ifs),                                    /* bInterfaceCount */                                       \
  USB_DEVICE_CLASS_AUDIO,                         /* bFunctionClass */                                        \
  AUDIO_SUBCLASS_AUDIOCONTROL,                    /* bFunctionSubclass */                                     \
  AUDIO_PROTOCOL_UNDEFINED,                       /* bFunctionProtocol */                                     \
  USBD_ADC##n##_IF0_STR_IDX,                      /* iFunction */                                             \

#define USBD_ADCn_DESC(n)                                                                                     \
  /* Interface, Alternate Setting 0, Audio Control */                                                         \
  USB_INTERFACE_DESC_SIZE,                        /* bLength */                                               \
  USB_INTERFACE_DESCRIPTOR_TYPE,                  /* bDescriptorType */                                       \
  USBD_ADC##n##_IF0_NUM,                          /* bInterfaceNumber */                                      \
  0x00,                                           /* bAlternateSetting */                                     \
  0x00,                                           /* bNumEndpoints */                                         \
  USB_DEVICE_CLASS_AUDIO,                         /* bInterfaceClass */                                       \
  AUDIO_SUBCLASS_AUDIOCONTROL,                    /* bInterfaceSubClass */                                    \
  AUDIO_PROTOCOL_UNDEFINED,                       /* bInterfaceProtocol */                                    \
  USBD_ADC##n##_IF0_STR_IDX,                      /* iInterface */                                            \
  /* Audio Control Interface */                                                                               \
  AUDIO_CONTROL_INTERFACE_DESC_SZ(1),             /* bLength */                                               \
  AUDIO_INTERFACE_DESCRIPTOR_TYPE,                /* bDescriptorType */                                       \
  AUDIO_CONTROL_HEADER,                           /* bDescriptorSubtype */                                    \
  WBVAL(0x0100), /* 1.00 */                       /* bcdADC */                                                \
  WBVAL(                                          /* wTotalLength */                                          \
    AUDIO_CONTROL_INTERFACE_DESC_SZ(1) +                                                                      \
    AUDIO_INPUT_TERMINAL_DESC_SIZE     +                                                                      \
    AUDIO_FEATURE_UNIT_DESC_SZ(1,1)    +                                                                      \
    AUDIO_OUTPUT_TERMINAL_DESC_SIZE                                                                           \
  ),                                                                                                          \
  0x01,                                           /* bInCollection */                                         \
  0x01,                                           /* baInterfaceNr */                                         \
                                                                                                              \
  /* Audio Input Terminal */                                                                                  \
  AUDIO_INPUT_TERMINAL_DESC_SIZE,                 /* bLength */                                               \
  AUDIO_INTERFACE_DESCRIPTOR_TYPE,                /* bDescriptorType */                                       \
  AUDIO_CONTROL_INPUT_TERMINAL,                   /* bDescriptorSubtype */                                    \
  0x01,                                           /* bTerminalID */                                           \
  WBVAL(AUDIO_TERMINAL_USB_STREAMING),            /* wTerminalType */                                         \
  0x00,                                           /* bAssocTerminal */                                        \
  0x01,                                           /* bNrChannels */                                           \
  WBVAL(AUDIO_CHANNEL_M),                         /* wChannelConfig */                                        \
  0x00,                                           /* iChannelNames */                                         \
  0x00,                                           /* iTerminal */                                             \
                                                                                                              \
  /* Audio Feature Unit */                                                                                    \
  AUDIO_FEATURE_UNIT_DESC_SZ(1,1),                /* bLength */                                               \
  AUDIO_INTERFACE_DESCRIPTOR_TYPE,                /* bDescriptorType */                                       \
  AUDIO_CONTROL_FEATURE_UNIT,                     /* bDescriptorSubtype */                                    \
  0x02,                                           /* bUnitID */                                               \
  0x01,                                           /* bSourceID */                                             \
  0x01,                                           /* bControlSize */                                          \
  AUDIO_CONTROL_MUTE |                                                                                        \
  AUDIO_CONTROL_VOLUME,                           /* bmaControls(0) */                                        \
  0x00,                                           /* bmaControls(1) */                                        \
  0x00,                                           /* iTerminal */                                             \
                                                                                                              \
  /* Audio Output Terminal */                                                                                 \
  AUDIO_OUTPUT_TERMINAL_DESC_SIZE,                /* bLength */                                               \
  AUDIO_INTERFACE_DESCRIPTOR_TYPE,                /* bDescriptorType */                                       \
  AUDIO_CONTROL_OUTPUT_TERMINAL,                  /* bDescriptorSubtype */                                    \
  0x03,                                           /* bTerminalID */                                           \
  WBVAL(AUDIO_TERMINAL_SPEAKER),                  /* wTerminalType */                                         \
  0x00,                                           /* bAssocTerminal */                                        \
  0x02,                                           /* bSourceID */                                             \
  0x00,                                           /* iTerminal */                                             \
                                                                                                              \
  /* Interface, Alternate Setting 0, Audio Streaming - Zero Bandwith */                                       \
  USB_INTERFACE_DESC_SIZE,                        /* bLength */                                               \
  USB_INTERFACE_DESCRIPTOR_TYPE,                  /* bDescriptorType */                                       \
  USBD_ADC##n##_IF1_NUM,                          /* bInterfaceNumber */                                      \
  0x00,                                           /* bAlternateSetting */                                     \
  0x00,                                           /* bNumEndpoints */                                         \
  USB_DEVICE_CLASS_AUDIO,                         /* bInterfaceClass */                                       \
  AUDIO_SUBCLASS_AUDIOSTREAMING,                  /* bInterfaceSubClass */                                    \
  AUDIO_PROTOCOL_UNDEFINED,                       /* bInterfaceProtocol */                                    \
  USBD_ADC##n##_IF1_STR_IDX,                      /* iInterface */                                            \
                                                                                                              \
  /* Interface, Alternate Setting 1, Audio Streaming - Operational */                                         \
  USB_INTERFACE_DESC_SIZE,                        /* bLength */                                               \
  USB_INTERFACE_DESCRIPTOR_TYPE,                  /* bDescriptorType */                                       \
  USBD_ADC##n##_IF1_NUM,                          /* bInterfaceNumber */                                      \
  0x01,                                           /* bAlternateSetting */                                     \
  0x01,                                           /* bNumEndpoints */                                         \
  USB_DEVICE_CLASS_AUDIO,                         /* bInterfaceClass */                                       \
  AUDIO_SUBCLASS_AUDIOSTREAMING,                  /* bInterfaceSubClass */                                    \
  AUDIO_PROTOCOL_UNDEFINED,                       /* bInterfaceProtocol */                                    \
  USBD_ADC##n##_IF1_1_STR_IDX,                    /* iInterface */                                            \
                                                                                                              \
  /* Audio Streaming Interface */                                                                             \
  AUDIO_STREAMING_INTERFACE_DESC_SIZE,            /* bLength */                                               \
  AUDIO_INTERFACE_DESCRIPTOR_TYPE,                /* bDescriptorType */                                       \
  AUDIO_STREAMING_GENERAL,                        /* bDescriptorSubtype */                                    \
  0x01,                                           /* bTerminalLink */                                         \
  0x01,                                           /* bDelay */                                                \
  WBVAL(AUDIO_FORMAT_PCM),                        /* wFormatTag */                                            \
                                                                                                              \
  /* Audio Type I Format */                                                                                   \
  AUDIO_FORMAT_TYPE_I_DESC_SZ(1),                 /* bLength */                                               \
  AUDIO_INTERFACE_DESCRIPTOR_TYPE,                /* bDescriptorType */                                       \
  AUDIO_STREAMING_FORMAT_TYPE,                    /* bDescriptorSubtype */                                    \
  AUDIO_FORMAT_TYPE_I,                            /* bFormatType */                                           \
  0x01,                                           /* bNrChannels */                                           \
  USBD_ADC##n##_BSUBFRAMESIZE,                    /* bSubFrameSize */                                         \
  USBD_ADC##n##_BBITRESOLUTION,                   /* bBitResolution */                                        \
  0x01,                                           /* bSamFreqType */                                          \
  B3VAL(USBD_ADC##n##_TSAM_FREQ),                  /* tSamFreq */

#define USBD_ADCn_EP(n)                           /* ADC Endpoints for Low-speed/Full-speed */                \
  /* Endpoint, EP ISO OUT - Standard Descriptor */                                                            \
  AUDIO_STANDARD_ENDPOINT_DESC_SIZE,              /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_OUT(USBD_ADC##n##_EP_ISO_OUT),     /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_ISOCHRONOUS,                  /* bmAttributes */                                          \
  WBVAL(USBD_ADC##n##_WMAXPACKETSIZE),            /* wMaxPacketSize */                                        \
  USBD_ADC##n##_BINTERVAL,                        /* bInterval */                                             \
  0x00,                                           /* bRefresh */                                              \
  0x00,                                           /* bSynchAddress */                                         \
                                                                                                              \
  /* Endpoint - Audio Streaming */                                                                            \
  AUDIO_STREAMING_ENDPOINT_DESC_SIZE,             /* bLength */                                               \
  AUDIO_ENDPOINT_DESCRIPTOR_TYPE,                 /* bDescriptorType */                                       \
  AUDIO_ENDPOINT_GENERAL,                         /* bDescriptor */                                           \
  0x00,                                           /* bmAttributes */                                          \
  0x00,                                           /* bLockDelayUnits */                                       \
  WBVAL(0x0000),                                  /* wLockDelay */

#define USBD_ADCn_EP_HS(n)                        /* ADC Endpoints for High-speed */                          \
  /* Endpoint, EP ISO OUT - Standard Descriptor */                                                            \
  AUDIO_STANDARD_ENDPOINT_DESC_SIZE,              /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_OUT(USBD_ADC##n##_EP_ISO_OUT),     /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_ISOCHRONOUS,                  /* bmAttributes */                                          \
  WBVAL(USBD_ADC##n##_HS_WMAXPACKETSIZE),         /* wMaxPacketSize */                                        \
  USBD_ADC##n##_BINTERVAL,                        /* bInterval */                                             \
  0x00,                                           /* bRefresh */                                              \
  0x00,                                           /* bSynchAddress */                                         \
                                                                                                              \
  /* Endpoint - Audio Streaming */                                                                            \
  AUDIO_STREAMING_ENDPOINT_DESC_SIZE,             /* bLength */                                               \
  AUDIO_ENDPOINT_DESCRIPTOR_TYPE,                 /* bDescriptorType */                                       \
  AUDIO_ENDPOINT_GENERAL,                         /* bDescriptor */                                           \
  0x00,                                           /* bmAttributes */                                          \
  0x00,                                           /* bLockDelayUnits */                                       \
  WBVAL(0x0000),                                  /* wLockDelay */

#define USBD_CDCn_IAD(n,first,num_of_ifs)         /* CDC: Interface Association Descriptor */                 \
  USB_INTERFACE_ASSOC_DESC_SIZE,                  /* bLength */                                               \
  USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE,      /* bDescriptorType */                                       \
 (first),                                         /* bFirstInterface */                                       \
 (num_of_ifs),                                    /* bInterfaceCount */                                       \
  CDC_COMMUNICATION_INTERFACE_CLASS,              /* bFunctionClass    (Communication Class) */               \
  CDC_ABSTRACT_CONTROL_MODEL,                     /* bFunctionSubclass (Abstract Control Model) */            \
  0x01,                                           /* bFunctionProtocol (V.25ter, Common AT commands) */       \
  USBD_CDC##n##_IF0_STR_IDX,                      /* iFunction */                                             \

#define USBD_CDCn_DESC_IF0(n)                                                                                 \
  /* Interface, Alternate Setting 0, CDC Class */                                                             \
  USB_INTERFACE_DESC_SIZE,                        /* bLength */                                               \
  USB_INTERFACE_DESCRIPTOR_TYPE,                  /* bDescriptorType */                                       \
  USBD_CDC##n##_IF0_NUM,                          /* bInterfaceNumber: Number of Interface */                 \
  0x00,                                           /* bAlternateSetting: Alternate setting */                  \
  0x01,                                           /* bNumEndpoints: One endpoint used */                      \
  CDC_COMMUNICATION_INTERFACE_CLASS,              /* bInterfaceClass: Communication Interface Class */        \
  CDC_ABSTRACT_CONTROL_MODEL,                     /* bInterfaceSubClass: Abstract Control Model */            \
  0x00,                                           /* bInterfaceProtocol: no protocol used */                  \
  USBD_CDC##n##_IF0_STR_IDX,                      /* iInterface: */                                           \
                                                                                                              \
  /* Header Functional Descriptor */                                                                          \
  0x05,                                           /* bLength: Endpoint Descriptor size */                     \
  CDC_CS_INTERFACE,                               /* bDescriptorType: CS_INTERFACE */                         \
  CDC_HEADER,                                     /* bDescriptorSubtype: Header Func Desc */                  \
  WBVAL(CDC_V1_10), /* 1.10 */                    /* bcdCDC */                                                \
  /* Call Management Functional Descriptor */                                                                 \
  0x05,                                           /* bFunctionLength */                                       \
  CDC_CS_INTERFACE,                               /* bDescriptorType: CS_INTERFACE */                         \
  CDC_CALL_MANAGEMENT,                            /* bDescriptorSubtype: Call Management Func Desc */         \
  0x01,                                           /* bmCapabilities: device handles call management */        \
  0x01,                                           /* bDataInterface: CDC data IF ID */                        \
  /* Abstract Control Management Functional Descriptor */                                                     \
  0x04,                                           /* bFunctionLength */                                       \
  CDC_CS_INTERFACE,                               /* bDescriptorType: CS_INTERFACE */                         \
  CDC_ABSTRACT_CONTROL_MANAGEMENT,                /* bDescriptorSubtype: Abstract Control Management desc */  \
  0x02,                                           /* bmCapabilities: SET_LINE_CODING,                         \
                                                                     GET_LINE_CODING,                         \
                                                                     SET_CONTROL_LINE_STATE supported */      \
  /* Union Functional Descriptor */                                                                           \
  0x05,                                           /* bFunctionLength */                                       \
  CDC_CS_INTERFACE,                               /* bDescriptorType: CS_INTERFACE */                         \
  CDC_UNION,                                      /* bDescriptorSubtype: Union func desc */                   \
  USBD_CDC##n##_IF0_NUM,                          /* bMasterInterface: Comm class interface is master */      \
  USBD_CDC##n##_IF1_NUM,                          /* bSlaveInterface0: Data class interface is slave 0 */

#define USBD_CDCn_EP_IF0(n)                       /* CDC Endpoints for Interface 0 for Low-speed/Full-speed */\
  /* Endpoint, EP Interrupt IN */                 /* event notification (optional) */                         \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_IN(USBD_CDC##n##_EP_INT_IN),       /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_INTERRUPT,                    /* bmAttributes */                                          \
  WBVAL(USBD_CDC##n##_WMAXPACKETSIZE),            /* wMaxPacketSize */                                        \
  USBD_CDC##n##_BINTERVAL,                        /* bInterval */

#define USBD_CDCn_EP_IF0_HS(n)                    /* CDC Endpoints for Interface 0 for High-speed */          \
  /* Endpoint, EP Interrupt IN */                 /* event notification (optional) */                         \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_IN(USBD_CDC##n##_EP_INT_IN),       /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_INTERRUPT,                    /* bmAttributes */                                          \
  WBVAL(USBD_CDC##n##_HS_WMAXPACKETSIZE),         /* wMaxPacketSize */                                        \
  USBD_CDC##n##_HS_BINTERVAL,                     /* bInterval */

#define USBD_CDCn_DESC_IF1(n)                                                                                 \
  /* Interface, Alternate Setting 0, Data class interface descriptor*/                                        \
  USB_INTERFACE_DESC_SIZE,                        /* bLength */                                               \
  USB_INTERFACE_DESCRIPTOR_TYPE,                  /* bDescriptorType */                                       \
  USBD_CDC##n##_IF1_NUM,                          /* bInterfaceNumber: Number of Interface */                 \
  0x00,                                           /* bAlternateSetting: no alternate setting */               \
  0x02,                                           /* bNumEndpoints: two endpoints used */                     \
  CDC_DATA_INTERFACE_CLASS,                       /* bInterfaceClass: Data Interface Class */                 \
  0x00,                                           /* bInterfaceSubClass: no subclass available */             \
  0x00,                                           /* bInterfaceProtocol: no protocol used */                  \
  USBD_CDC##n##_IF1_STR_IDX,                      /* iInterface */

#define USBD_CDCn_EP_IF1(n)                       /* CDC Endpoints for Interface 1 for Low-speed/Full-speed */\
  /* Endpoint, EP Bulk OUT */                                                                                 \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_OUT(USBD_CDC##n##_EP_BULK_OUT),    /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_BULK,                         /* bmAttributes */                                          \
  WBVAL(USBD_CDC##n##_WMAXPACKETSIZE1),           /* wMaxPacketSize */                                        \
  0x00,                                           /* bInterval: ignore for Bulk transfer */                   \
                                                                                                              \
  /* Endpoint, EP Bulk IN */                                                                                  \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_IN(USBD_CDC##n##_EP_BULK_IN),      /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_BULK,                         /* bmAttributes */                                          \
  WBVAL(USBD_CDC##n##_WMAXPACKETSIZE1),           /* wMaxPacketSize */                                        \
  0x00,                                           /* bInterval: ignore for Bulk transfer */

#define USBD_CDCn_EP_IF1_HS(n)                    /* CDC Endpoints for Interface 1 for High-speed */          \
  /* Endpoint, EP Bulk OUT */                                                                                 \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_OUT(USBD_CDC##n##_EP_BULK_OUT),    /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_BULK,                         /* bmAttributes */                                          \
  WBVAL(USBD_CDC##n##_HS_WMAXPACKETSIZE1),        /* wMaxPacketSize */                                        \
  USBD_CDC##n##_HS_BINTERVAL1,                    /* bInterval */                                             \
                                                                                                              \
  /* Endpoint, EP Bulk IN */                                                                                  \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_IN(USBD_CDC##n##_EP_BULK_IN),      /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_BULK,                         /* bmAttributes */                                          \
  WBVAL(USBD_CDC##n##_HS_WMAXPACKETSIZE1),        /* wMaxPacketSize */                                        \
  USBD_CDC##n##_HS_BINTERVAL1,                    /* bInterval */

#define USBD_HIDn_IAD(n,first,num_of_ifs)         /* HID: Interface Association Descriptor */                 \
  USB_INTERFACE_ASSOC_DESC_SIZE,                  /* bLength */                                               \
  USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE,      /* bDescriptorType */                                       \
 (first),                                         /* bFirstInterface */                                       \
 (num_of_ifs),                                    /* bInterfaceCount */                                       \
  USB_DEVICE_CLASS_HUMAN_INTERFACE,               /* bFunctionClass */                                        \
  HID_SUBCLASS_NONE,                              /* bFunctionSubclass */                                     \
  HID_PROTOCOL_NONE,                              /* bFunctionProtocol */                                     \
  USBD_HID##n##_STR,                              /* iFunction */                                             \

#define USBD_HIDn_DESC(n)                                                                                     \
  /* Interface, Alternate Setting 0, HID Class */                                                             \
  USB_INTERFACE_DESC_SIZE,                        /* bLength */                                               \
  USB_INTERFACE_DESCRIPTOR_TYPE,                  /* bDescriptorType */                                       \
  USBD_HID##n##_IF0_NUM,                          /* bInterfaceNumber */                                      \
  0x00,                                           /* bAlternateSetting */                                     \
  0x01+(USBD_HID##n##_EP_INT_OUT != 0),           /* bNumEndpoints */                                         \
  USB_DEVICE_CLASS_HUMAN_INTERFACE,               /* bInterfaceClass */                                       \
  HID_SUBCLASS_NONE,                              /* bInterfaceSubClass */                                    \
  HID_PROTOCOL_NONE,                              /* bInterfaceProtocol */                                    \
  USBD_HID##n##_IF0_STR_IDX,                      /* iInterface */                                            \
                                                                                                              \
  /* HID Class Descriptor */                                                                                  \
  USB_HID_DESC_SIZE,                              /* bLength */                                               \
  HID_HID_DESCRIPTOR_TYPE,                        /* bDescriptorType */                                       \
  WBVAL(0x0111), /* 1.11 */                       /* bcdHID */                                                \
  0x00,                                           /* bCountryCode */                                          \
  0x01,                                           /* bNumDescriptors */                                       \
  HID_REPORT_DESCRIPTOR_TYPE,                     /* bDescriptorType */                                       \
  WBVAL(USBD_HID##n##_REPORT_DESC_SIZE),          /* wDescriptorLength */

#define USBD_HIDn_EP(n)                           /* HID Endpoint for Low-speed/Full-speed */                 \
  /* Endpoint, HID Interrupt In */                                                                            \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_IN(USBD_HID##n##_EP_INT_IN),       /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_INTERRUPT,                    /* bmAttributes */                                          \
  WBVAL(USBD_HID##n##_WMAXPACKETSIZE),            /* wMaxPacketSize */                                        \
  USBD_HID##n##_BINTERVAL,                        /* bInterval */

#define USBD_HIDn_EP_INOUT(n)                     /* HID Endpoint for Low-speed/Full-speed */                 \
  /* Endpoint, HID Interrupt In */                                                                            \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_IN(USBD_HID##n##_EP_INT_IN),       /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_INTERRUPT,                    /* bmAttributes */                                          \
  WBVAL(USBD_HID##n##_WMAXPACKETSIZE),            /* wMaxPacketSize */                                        \
  USBD_HID##n##_BINTERVAL,                        /* bInterval */                                             \
                                                                                                              \
  /* Endpoint, HID Interrupt Out */                                                                           \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_OUT(USBD_HID##n##_EP_INT_OUT),     /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_INTERRUPT,                    /* bmAttributes */                                          \
  WBVAL(USBD_HID##n##_WMAXPACKETSIZE),            /* wMaxPacketSize */                                        \
  USBD_HID##n##_BINTERVAL,                        /* bInterval */

#define USBD_HIDn_EP_HS(n)                        /* HID Endpoint for High-speed */                           \
  /* Endpoint, HID Interrupt In */                                                                            \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_IN(USBD_HID##n##_EP_INT_IN),       /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_INTERRUPT,                    /* bmAttributes */                                          \
  WBVAL(USBD_HID##n##_HS_WMAXPACKETSIZE),         /* wMaxPacketSize */                                        \
  USBD_HID##n##_HS_BINTERVAL,                     /* bInterval */

#define USBD_HIDn_EP_INOUT_HS(n)                  /* HID Endpoint for High-speed */                           \
  /* Endpoint, HID Interrupt In */                                                                            \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_IN(USBD_HID##n##_EP_INT_IN),       /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_INTERRUPT,                    /* bmAttributes */                                          \
  WBVAL(USBD_HID##n##_HS_WMAXPACKETSIZE),         /* wMaxPacketSize */                                        \
  USBD_HID##n##_HS_BINTERVAL,                     /* bInterval */                                             \
                                                                                                              \
  /* Endpoint, HID Interrupt Out */                                                                           \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_OUT(USBD_HID##n##_EP_INT_OUT),     /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_INTERRUPT,                    /* bmAttributes */                                          \
  WBVAL(USBD_HID##n##_HS_WMAXPACKETSIZE),         /* wMaxPacketSize */                                        \
  USBD_HID##n##_HS_BINTERVAL,                     /* bInterval */

#define USBD_MSCn_IAD(n,first,num_of_ifs)         /* MSC: Interface Association Descriptor */                 \
  USB_INTERFACE_ASSOC_DESC_SIZE,                  /* bLength */                                               \
  USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE,      /* bDescriptorType */                                       \
 (first),                                         /* bFirstInterface */                                       \
 (num_of_ifs),                                    /* bInterfaceCount */                                       \
  USB_DEVICE_CLASS_STORAGE,                       /* bFunctionClass */                                        \
  MSC_SUBCLASS_SCSI,                              /* bFunctionSubclass */                                     \
  MSC_PROTOCOL_BULK_ONLY,                         /* bFunctionProtocol */                                     \
  USBD_MSC##n##_IF0_STR_IDX,                      /* iFunction */                                             \

#define USBD_MSCn_DESC(n)                                                                                     \
  /* Interface, Alternate Setting 0, MSC Class */                                                             \
  USB_INTERFACE_DESC_SIZE,                        /* bLength */                                               \
  USB_INTERFACE_DESCRIPTOR_TYPE,                  /* bDescriptorType */                                       \
  USBD_MSC##n##_IF0_NUM,                          /* bInterfaceNumber */                                      \
  0x00,                                           /* bAlternateSetting */                                     \
  0x02,                                           /* bNumEndpoints */                                         \
  USB_DEVICE_CLASS_STORAGE,                       /* bInterfaceClass */                                       \
  MSC_SUBCLASS_SCSI,                              /* bInterfaceSubClass */                                    \
  MSC_PROTOCOL_BULK_ONLY,                         /* bInterfaceProtocol */                                    \
  USBD_MSC##n##_IF0_STR_IDX,                      /* iInterface */

#define USBD_MSCn_EP(n)                           /* MSC Endpoints for Low-speed/Full-speed */                \
  /* Endpoint, EP Bulk IN */                                                                                  \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_IN(USBD_MSC##n##_EP_BULK_IN),      /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_BULK,                         /* bmAttributes */                                          \
  WBVAL(USBD_MSC##n##_WMAXPACKETSIZE),            /* wMaxPacketSize */                                        \
  0x00,                                           /* bInterval: ignore for Bulk transfer */                   \
                                                                                                              \
  /* Endpoint, EP Bulk OUT */                                                                                 \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_OUT(USBD_MSC##n##_EP_BULK_OUT),    /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_BULK,                         /* bmAttributes */                                          \
  WBVAL(USBD_MSC##n##_WMAXPACKETSIZE),            /* wMaxPacketSize */                                        \
  0x00,                                           /* bInterval: ignore for Bulk transfer */

#define USBD_MSCn_EP_HS(n)                        /* MSC Endpoints for High-speed */                          \
  /* Endpoint, EP Bulk IN */                                                                                  \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_IN(USBD_MSC##n##_EP_BULK_IN),      /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_BULK,                         /* bmAttributes */                                          \
  WBVAL(USBD_MSC##n##_HS_WMAXPACKETSIZE),         /* wMaxPacketSize */                                        \
  USBD_MSC##n##_HS_BINTERVAL,                     /* bInterval */                                             \
                                                                                                              \
  /* Endpoint, EP Bulk OUT */                                                                                 \
  USB_ENDPOINT_DESC_SIZE,                         /* bLength */                                               \
  USB_ENDPOINT_DESCRIPTOR_TYPE,                   /* bDescriptorType */                                       \
  USB_ENDPOINT_OUT(USBD_MSC##n##_EP_BULK_OUT),    /* bEndpointAddress */                                      \
  USB_ENDPOINT_TYPE_BULK,                         /* bmAttributes */                                          \
  WBVAL(USBD_MSC##n##_HS_WMAXPACKETSIZE),         /* wMaxPacketSize */                                        \
  USBD_MSC##n##_HS_BINTERVAL,                     /* bInterval */

/* USB Device Create String Descriptor */
#define USBD_STR_DEF(n)            \
  struct {                         \
    uint8_t  len;                  \
    uint8_t  type;                 \
    uint16_t str[sizeof(##n)/2-1]; \
  } desc##n                        

#define USBD_STR_VAL(n)                 \
 { sizeof(##n), USB_STRING_DESCRIPTOR_TYPE, ##n }  

/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Host
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    usbh_config.h
 * Purpose: USB Host Library Configuration
 * Rev.:    V5.10
 *----------------------------------------------------------------------------*/

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"
#include "usb_def.h"
#include "usb_adc.h"
#include "usb_cdc.h"
#include "usb_hid.h"
#include "usb_msc.h"
#include "rl_usbh.h"
#include "rl_usbd.h"

#pragma thumb
#pragma O3


/*------------------------------------------------------------------------------
 *      USB Host Global Macros
 *----------------------------------------------------------------------------*/

#define USBHn_DRIVER_(n)                Driver_USBH##n
#define USBHn_DRIVER(n)                 USBHn_DRIVER_(n)

#define USBHn_DRIVER_HCI_(n)            Driver_USBH##n##_HCI
#define USBHn_DRIVER_HCI(n)             USBHn_DRIVER_HCI_(n)

#define USBHn_DRIVER_OHCI_LIB_(n)       Driver_USBH##n##_OHCI_LIB
#define USBHn_DRIVER_OHCI_LIB(n)        USBHn_DRIVER_OHCI_LIB_(n)

#define USBHn_DRIVER_EHCI_LIB_(n)       Driver_USBH##n##_EHCI_LIB
#define USBHn_DRIVER_EHCI_LIB(n)        USBHn_DRIVER_EHCI_LIB_(n)

#if    (defined(USBH3_HC_NUM))
#define LAST_DEVICE_COMPILE             1
#elif  (defined(USBH2_HC_NUM) && !defined(RTE_USB_Host_3))
#define LAST_DEVICE_COMPILE             1
#elif  (defined(USBH1_HC_NUM) && !defined(RTE_USB_Host_3) && !defined(RTE_USB_Host_2))
#define LAST_DEVICE_COMPILE             1
#elif  (defined(USBH0_HC_NUM) && !defined(RTE_USB_Host_3) && !defined(RTE_USB_Host_2) && !defined(RTE_USB_Host_1))
#define LAST_DEVICE_COMPILE             1
#endif


/*------------------------------------------------------------------------------
 *      USB Host 0 Macros, Calculations and Constants for Library
 *----------------------------------------------------------------------------*/

#if     (defined(USBH0_HC_NUM) && defined(RTE_USB_Host_0))

#if     (USBH0_HC_MEM_POOL_RELOC == 1)
#define __AT_MEM0(x)              __attribute__((at(x)))
#else
#define __AT_MEM0(x)                
#endif
#define __ALIGNED_MEM0(x)         __attribute__((aligned(x)))

uint32_t usbh0_mem_pool            [(USBH0_HC_MEM_POOL_SIZE +3)/4] __AT_MEM0(USBH0_HC_MEM_POOL_ADDR);
const uint32_t usbh0_mem_pool_size=((USBH0_HC_MEM_POOL_SIZE +3)/4)*4;

#if     (USBH0_HC_IF == 0)              // Custom

extern   ARM_DRIVER_USBH            USBHn_DRIVER(USBH0_HC_NUM);
const    ARM_DRIVER_USBH           *usbh0_hcd_ptr = &USBHn_DRIVER(USBH0_HC_NUM);

#elif   (USBH0_HC_IF == 1)              // OHCI

extern   ARM_DRIVER_USBH            USBHn_DRIVER_OHCI_LIB(USBH0_HC_NUM);
const    ARM_DRIVER_USBH           *usbh0_hcd_ptr = &USBHn_DRIVER_OHCI_LIB(USBH0_HC_NUM);

extern   ARM_DRIVER_USBH_HCI        USBHn_DRIVER_HCI(USBH0_HC_NUM);
const    ARM_DRIVER_USBH_HCI       *usbh0_hci_hcd_ptr = &USBHn_DRIVER_HCI(USBH0_HC_NUM);

#define  USBH0_OHCI_MEM_HCCA        (USBH0_HC_MEM_POOL_ADDR + (((USBH0_HC_MEM_POOL_SIZE + 3)/4)*4))
#define  USBH0_OHCI_MEM_HCCA_SIZE   (256)
#define  USBH0_OHCI_MEM_ED          (USBH0_OHCI_MEM_HCCA + USBH0_EHCI_MEM_HCCA_SIZE)
#define  USBH0_OHCI_MEM_ED_SIZE     (USBH0_HC_OHCI_ENDPOINT_NUM*16)
#define  USBH0_OHCI_MEM_TD          (USBH0_EHCI_MEM_ED   + USBH0_EHCI_MEM_ED_SIZE)
#define  USBH0_OHCI_MEM_TD_SIZE     (USBH0_HC_OHCI_TRANSFER_NUM*16)
#define  USBH0_OHCI_MEM_TDURB       (USBH0_EHCI_MEM_QTD  + USBH0_EHCI_MEM_QTD_SIZE)
#define  USBH0_OHCI_MEM_TDURB_SIZE  (USBH0_HC_EHCI_TRANSFER_NUM* 8)

uint32_t usbh0_ohci_hcca           [(USBH0_OHCI_MEM_HCCA_SIZE +3)/4] __AT_MEM(USBH0_OHCI_MEM_HCCA);
uint32_t usbh0_ohci_ed             [(USBH0_OHCI_MEM_ED_SIZE   +3)/4] __AT_MEM(USBH0_OHCI_MEM_ED);
uint32_t usbh0_ohci_td             [(USBH0_OHCI_MEM_TD_SIZE   +3)/4] __AT_MEM(USBH0_OHCI_MEM_TD);
uint32_t usbh0_ohci_tdurb          [(USBH0_OHCI_MEM_TDURB_SIZE+3)/4] __AT_MEM(USBH0_OHCI_MEM_TDURB);

USBH_OHCI_t usbh0_ohci = { 
                                     (uint32_t *)USBH0_HC_OHCI_BASE_ADDRESS,
                                     USBH0_HC_OHCI_PORT_MASK,
                                     USBH0_HC_OHCI_ENDPOINT_NUM,
                                     USBH0_HC_OHCI_TRANSFER_NUM,
                                     0,
                                    &usbh0_ohci_hcca,
                                    &usbh0_ohci_ed,
                                    &usbh0_ohci_td,
                                     NULL,
                                    &usbh0_ohci_tdurb
                                   };

#elif   (USBH0_HC_IF == 2)              // EHCI with OHCI support

extern   ARM_DRIVER_USBH            USBHn_DRIVER_EHCI_LIB(USBH0_HC_NUM);
const    ARM_DRIVER_USBH           *usbh0_hcd_ptr = &USBHn_DRIVER_EHCI_LIB(USBH0_HC_NUM);

extern   ARM_DRIVER_USBH_HCI        USBHn_DRIVER_HCI(USBH0_HC_NUM);
const    ARM_DRIVER_USBH_HCI       *usbh0_hci_hcd_ptr = &USBHn_DRIVER_HCI(USBH0_HC_NUM);

#define  USBH0_EHCI_MEM_PFL         (USBH0_HC_MEM_POOL_ADDR + (((USBH0_HC_MEM_POOL_SIZE + 3)/4)*4))
#define  USBH0_EHCI_MEM_PFL_SIZE    (4096)
#define  USBH0_EHCI_MEM_QH          (USBH0_EHCI_MEM_PFL  + USBH0_EHCI_MEM_PFL_SIZE)
#define  USBH0_EHCI_MEM_QH_SIZE     (USBH0_HC_EHCI_ENDPOINT_NUM*64)
#define  USBH0_EHCI_MEM_QTD         (USBH0_EHCI_MEM_QH   + USBH0_EHCI_MEM_QH_SIZE)
#define  USBH0_EHCI_MEM_QTD_SIZE    (USBH0_HC_EHCI_TRANSFER_NUM*32)
#define  USBH0_EHCI_MEM_TDURB       (USBH0_EHCI_MEM_QTD  + USBH0_EHCI_MEM_QTD_SIZE)
#define  USBH0_EHCI_MEM_TDURB_SIZE  (USBH0_HC_EHCI_TRANSFER_NUM*12)

uint32_t usbh0_ehci_pfl            [(USBH0_EHCI_MEM_PFL_SIZE  +3)/4] __AT_MEM0(USBH0_EHCI_MEM_PFL) __ALIGNED_MEM0(4096);
uint32_t usbh0_ehci_qh             [(USBH0_EHCI_MEM_QH_SIZE   +3)/4] __AT_MEM0(USBH0_EHCI_MEM_QH);
uint32_t usbh0_ehci_qtd            [(USBH0_EHCI_MEM_QTD_SIZE  +3)/4] __AT_MEM0(USBH0_EHCI_MEM_QTD) __ALIGNED_MEM0(32);
uint32_t usbh0_ehci_tdurb          [(USBH0_EHCI_MEM_TDURB_SIZE+3)/4] __AT_MEM0(USBH0_EHCI_MEM_TDURB);

USBH_EHCI_t usbh0_ehci = { 
                                    (uint32_t *)USBH0_HC_EHCI_BASE_ADDRESS,
                                     USBH0_HC_EHCI_PORT_MASK,
                                     USBH0_HC_EHCI_ENDPOINT_NUM,
                                     USBH0_HC_EHCI_TRANSFER_NUM,
                                     0,
                                     0,
                                     1024,
                                    &usbh0_ehci_pfl[0],
                                    &usbh0_ehci_qh[0],
                                    &usbh0_ehci_qtd[0],
                                     NULL,
                                     NULL,
                                     NULL,
                                    &usbh0_ehci_tdurb[0]
                                  };
#endif

extern  void    USBH0_CoreThread       (void const *arg);
#if    (!defined(USBH0_CORE_THREAD_STACK_SIZE))
#define USBH0_CORE_THREAD_STACK_SIZE    0
#endif
#if    (!defined(USBH0_CORE_THREAD_PRIORITY))
#define USBH0_CORE_THREAD_PRIORITY      osPriorityNormal
#endif
osThreadDef(USBH0_CoreThread, USBH0_CORE_THREAD_PRIORITY, 1, USBH0_CORE_THREAD_STACK_SIZE);

#endif


/*------------------------------------------------------------------------------
 *      USB Host 1 Macros, Calculations and Constants for Library
 *----------------------------------------------------------------------------*/

#if     (defined(USBH1_HC_NUM) && defined(RTE_USB_Host_1))

#if     (USBH1_HC_MEM_POOL_RELOC == 1)
#define __AT_MEM1(x)              __attribute__((at(x)))
#else
#define __AT_MEM1(x)                
#endif
#define __ALIGNED_MEM1(x)         __attribute__((aligned(x)))

uint32_t usbh1_mem_pool            [(USBH1_HC_MEM_POOL_SIZE +3)/4] __AT_MEM1(USBH1_HC_MEM_POOL_ADDR);
const uint32_t usbh1_mem_pool_size=((USBH1_HC_MEM_POOL_SIZE +3)/4)*4;

#if     (USBH1_HC_IF == 0)              // Custom

extern   ARM_DRIVER_USBH            USBHn_DRIVER(USBH1_HC_NUM);
const    ARM_DRIVER_USBH           *usbh1_hcd_ptr = &USBHn_DRIVER(USBH1_HC_NUM);

#elif   (USBH1_HC_IF == 1)              // OHCI

extern   ARM_DRIVER_USBH            USBHn_DRIVER_OHCI_LIB(USBH1_HC_NUM);
const    ARM_DRIVER_USBH           *usbh1_hcd_ptr = &USBHn_DRIVER_OHCI_LIB(USBH1_HC_NUM);

extern   ARM_DRIVER_USBH_HCI        USBHn_DRIVER_HCI(USBH1_HC_NUM);
const    ARM_DRIVER_USBH_HCI       *usbh1_hci_hcd_ptr = &USBHn_DRIVER_HCI(USBH1_HC_NUM);

#define  USBH1_OHCI_MEM_HCCA        (USBH1_HC_MEM_POOL_ADDR + (((USBH1_HC_MEM_POOL_SIZE + 3)/4)*4))
#define  USBH1_OHCI_MEM_HCCA_SIZE   (256)
#define  USBH1_OHCI_MEM_ED          (USBH1_OHCI_MEM_HCCA + USBH1_EHCI_MEM_HCCA_SIZE)
#define  USBH1_OHCI_MEM_ED_SIZE     (USBH1_HC_OHCI_ENDPOINT_NUM*16)
#define  USBH1_OHCI_MEM_TD          (USBH1_EHCI_MEM_ED   + USBH1_EHCI_MEM_ED_SIZE)
#define  USBH1_OHCI_MEM_TD_SIZE     (USBH1_HC_OHCI_TRANSFER_NUM*16)
#define  USBH1_OHCI_MEM_TDURB       (USBH1_EHCI_MEM_QTD  + USBH1_EHCI_MEM_QTD_SIZE)
#define  USBH1_OHCI_MEM_TDURB_SIZE  (USBH1_HC_EHCI_TRANSFER_NUM* 8)

uint32_t usbh1_ohci_hcca           [(USBH1_OHCI_MEM_HCCA_SIZE +3)/4] __AT_MEM1(USBH1_OHCI_MEM_HCCA);
uint32_t usbh1_ohci_ed             [(USBH1_OHCI_MEM_ED_SIZE   +3)/4] __AT_MEM1(USBH1_OHCI_MEM_ED);
uint32_t usbh1_ohci_td             [(USBH1_OHCI_MEM_TD_SIZE   +3)/4] __AT_MEM1(USBH1_OHCI_MEM_TD);
uint32_t usbh1_ohci_tdurb          [(USBH1_OHCI_MEM_TDURB_SIZE+3)/4] __AT_MEM1(USBH1_OHCI_MEM_TDURB);

USBH_OHCI_t usbh1_ohci = { 
                                     (uint32_t *)USBH1_HC_OHCI_BASE_ADDRESS,
                                     USBH1_HC_OHCI_PORT_MASK,
                                     USBH1_HC_OHCI_ENDPOINT_NUM,
                                     USBH1_HC_OHCI_TRANSFER_NUM,
                                     0,
                                    &usbh1_ohci_hcca,
                                    &usbh1_ohci_ed,
                                    &usbh1_ohci_td,
                                     NULL,
                                    &usbh1_ohci_tdurb
                                   };

#elif   (USBH1_HC_IF == 2)              // EHCI with OHCI support

extern   ARM_DRIVER_USBH            USBHn_DRIVER_EHCI_LIB(USBH1_HC_NUM);
const    ARM_DRIVER_USBH           *usbh1_hcd_ptr = &USBHn_DRIVER_EHCI_LIB(USBH1_HC_NUM);

extern   ARM_DRIVER_USBH_HCI        USBHn_DRIVER_HCI(USBH1_HC_NUM);
const    ARM_DRIVER_USBH_HCI       *usbh1_hci_hcd_ptr = &USBHn_DRIVER_HCI(USBH1_HC_NUM);

#define  USBH1_EHCI_MEM_PFL         (USBH1_HC_MEM_POOL_ADDR + (((USBH1_HC_MEM_POOL_SIZE + 3)/4)*4))
#define  USBH1_EHCI_MEM_PFL_SIZE    (4096)
#define  USBH1_EHCI_MEM_QH          (USBH1_EHCI_MEM_PFL  + USBH1_EHCI_MEM_PFL_SIZE)
#define  USBH1_EHCI_MEM_QH_SIZE     (USBH1_HC_EHCI_ENDPOINT_NUM*64)
#define  USBH1_EHCI_MEM_QTD         (USBH1_EHCI_MEM_QH   + USBH1_EHCI_MEM_QH_SIZE)
#define  USBH1_EHCI_MEM_QTD_SIZE    (USBH1_HC_EHCI_TRANSFER_NUM*32)
#define  USBH1_EHCI_MEM_TDURB       (USBH1_EHCI_MEM_QTD  + USBH1_EHCI_MEM_QTD_SIZE)
#define  USBH1_EHCI_MEM_TDURB_SIZE  (USBH1_HC_EHCI_TRANSFER_NUM*12)

uint32_t usbh1_ehci_pfl            [(USBH1_EHCI_MEM_PFL_SIZE  +3)/4] __AT_MEM1(USBH1_EHCI_MEM_PFL) __ALIGNED_MEM1(4096);
uint32_t usbh1_ehci_qh             [(USBH1_EHCI_MEM_QH_SIZE   +3)/4] __AT_MEM1(USBH1_EHCI_MEM_QH);
uint32_t usbh1_ehci_qtd            [(USBH1_EHCI_MEM_QTD_SIZE  +3)/4] __AT_MEM1(USBH1_EHCI_MEM_QTD) __ALIGNED_MEM1(32);
uint32_t usbh1_ehci_tdurb          [(USBH1_EHCI_MEM_TDURB_SIZE+3)/4] __AT_MEM1(USBH1_EHCI_MEM_TDURB);

USBH_EHCI_t usbh1_ehci = { 
                                    (uint32_t *)USBH1_HC_EHCI_BASE_ADDRESS,
                                     USBH1_HC_EHCI_PORT_MASK,
                                     USBH1_HC_EHCI_ENDPOINT_NUM,
                                     USBH1_HC_EHCI_TRANSFER_NUM,
                                     0,
                                     0,
                                     1024,
                                    &usbh1_ehci_pfl[0],
                                    &usbh1_ehci_qh[0],
                                    &usbh1_ehci_qtd[0],
                                     NULL,
                                     NULL,
                                     NULL,
                                    &usbh1_ehci_tdurb[0]
                                  };
#endif

extern  void    USBH1_CoreThread       (void const *arg);
#if    (!defined(USBH1_CORE_THREAD_STACK_SIZE))
#define USBH1_CORE_THREAD_STACK_SIZE    0
#endif
#if    (!defined(USBH1_CORE_THREAD_PRIORITY))
#define USBH1_CORE_THREAD_PRIORITY      osPriorityNormal
#endif
osThreadDef(USBH1_CoreThread, USBH1_CORE_THREAD_PRIORITY, 1, USBH1_CORE_THREAD_STACK_SIZE);

#endif


/*------------------------------------------------------------------------------
 *      USB Host 2 Macros, Calculations and Constants for Library
 *----------------------------------------------------------------------------*/

#if     (defined(USBH2_HC_NUM) && defined(RTE_USB_Host_2))

#if     (USBH2_HC_MEM_POOL_RELOC == 1)
#define __AT_MEM2(x)              __attribute__((at(x)))
#else
#define __AT_MEM2(x)                
#endif
#define __ALIGNED_MEM2(x)         __attribute__((aligned(x)))

uint32_t usbh2_mem_pool            [(USBH2_HC_MEM_POOL_SIZE +3)/4] __AT_MEM2(USBH2_HC_MEM_POOL_ADDR);
const uint32_t usbh2_mem_pool_size=((USBH2_HC_MEM_POOL_SIZE +3)/4)*4;

#if     (USBH2_HC_IF == 0)              // Custom

extern   ARM_DRIVER_USBH            USBHn_DRIVER(USBH2_HC_NUM);
const    ARM_DRIVER_USBH           *usbh2_hcd_ptr = &USBHn_DRIVER(USBH2_HC_NUM);

#elif   (USBH2_HC_IF == 1)              // OHCI

extern   ARM_DRIVER_USBH            USBHn_DRIVER_OHCI_LIB(USBH2_HC_NUM);
const    ARM_DRIVER_USBH           *usbh2_hcd_ptr = &USBHn_DRIVER_OHCI_LIB(USBH2_HC_NUM);

extern   ARM_DRIVER_USBH_HCI        USBHn_DRIVER_HCI(USBH2_HC_NUM);
const    ARM_DRIVER_USBH_HCI       *usbh2_hci_hcd_ptr = &USBHn_DRIVER_HCI(USBH2_HC_NUM);

#define  USBH2_OHCI_MEM_HCCA        (USBH2_HC_MEM_POOL_ADDR + (((USBH2_HC_MEM_POOL_SIZE + 3)/4)*4))
#define  USBH2_OHCI_MEM_HCCA_SIZE   (256)
#define  USBH2_OHCI_MEM_ED          (USBH2_OHCI_MEM_HCCA + USBH2_EHCI_MEM_HCCA_SIZE)
#define  USBH2_OHCI_MEM_ED_SIZE     (USBH2_HC_OHCI_ENDPOINT_NUM*16)
#define  USBH2_OHCI_MEM_TD          (USBH2_EHCI_MEM_ED   + USBH2_EHCI_MEM_ED_SIZE)
#define  USBH2_OHCI_MEM_TD_SIZE     (USBH2_HC_OHCI_TRANSFER_NUM*16)
#define  USBH2_OHCI_MEM_TDURB       (USBH2_EHCI_MEM_QTD  + USBH2_EHCI_MEM_QTD_SIZE)
#define  USBH2_OHCI_MEM_TDURB_SIZE  (USBH2_HC_EHCI_TRANSFER_NUM* 8)

uint32_t usbh2_ohci_hcca           [(USBH2_OHCI_MEM_HCCA_SIZE +3)/4] __AT_MEM2(USBH2_OHCI_MEM_HCCA);
uint32_t usbh2_ohci_ed             [(USBH2_OHCI_MEM_ED_SIZE   +3)/4] __AT_MEM2(USBH2_OHCI_MEM_ED);
uint32_t usbh2_ohci_td             [(USBH2_OHCI_MEM_TD_SIZE   +3)/4] __AT_MEM2(USBH2_OHCI_MEM_TD);
uint32_t usbh2_ohci_tdurb          [(USBH2_OHCI_MEM_TDURB_SIZE+3)/4] __AT_MEM2(USBH2_OHCI_MEM_TDURB);

USBH_OHCI_t usbh2_ohci = { 
                                     (uint32_t *)USBH2_HC_OHCI_BASE_ADDRESS,
                                     USBH2_HC_OHCI_PORT_MASK,
                                     USBH2_HC_OHCI_ENDPOINT_NUM,
                                     USBH2_HC_OHCI_TRANSFER_NUM,
                                     0,
                                    &usbh2_ohci_hcca,
                                    &usbh2_ohci_ed,
                                    &usbh2_ohci_td,
                                     NULL,
                                    &usbh2_ohci_tdurb
                                   };

#elif   (USBH2_HC_IF == 2)              // EHCI with OHCI support

extern   ARM_DRIVER_USBH            USBHn_DRIVER_EHCI_LIB(USBH2_HC_NUM);
const    ARM_DRIVER_USBH           *usbh2_hcd_ptr = &USBHn_DRIVER_EHCI_LIB(USBH2_HC_NUM);

extern   ARM_DRIVER_USBH_HCI        USBHn_DRIVER_HCI(USBH2_HC_NUM);
const    ARM_DRIVER_USBH_HCI       *usbh2_hci_hcd_ptr = &USBHn_DRIVER_HCI(USBH2_HC_NUM);

#define  USBH2_EHCI_MEM_PFL         (USBH2_HC_MEM_POOL_ADDR + (((USBH2_HC_MEM_POOL_SIZE + 3)/4)*4))
#define  USBH2_EHCI_MEM_PFL_SIZE    (4096)
#define  USBH2_EHCI_MEM_QH          (USBH2_EHCI_MEM_PFL  + USBH2_EHCI_MEM_PFL_SIZE)
#define  USBH2_EHCI_MEM_QH_SIZE     (USBH2_HC_EHCI_ENDPOINT_NUM*64)
#define  USBH2_EHCI_MEM_QTD         (USBH2_EHCI_MEM_QH   + USBH2_EHCI_MEM_QH_SIZE)
#define  USBH2_EHCI_MEM_QTD_SIZE    (USBH2_HC_EHCI_TRANSFER_NUM*32)
#define  USBH2_EHCI_MEM_TDURB       (USBH2_EHCI_MEM_QTD  + USBH2_EHCI_MEM_QTD_SIZE)
#define  USBH2_EHCI_MEM_TDURB_SIZE  (USBH2_HC_EHCI_TRANSFER_NUM*12)

uint32_t usbh2_ehci_pfl            [(USBH2_EHCI_MEM_PFL_SIZE  +3)/4] __AT_MEM2(USBH2_EHCI_MEM_PFL) __ALIGNED_MEM2(4096);
uint32_t usbh2_ehci_qh             [(USBH2_EHCI_MEM_QH_SIZE   +3)/4] __AT_MEM2(USBH2_EHCI_MEM_QH);
uint32_t usbh2_ehci_qtd            [(USBH2_EHCI_MEM_QTD_SIZE  +3)/4] __AT_MEM2(USBH2_EHCI_MEM_QTD) __ALIGNED_MEM2(32);
uint32_t usbh2_ehci_tdurb          [(USBH2_EHCI_MEM_TDURB_SIZE+3)/4] __AT_MEM2(USBH2_EHCI_MEM_TDURB);

USBH_EHCI_t usbh2_ehci = { 
                                    (uint32_t *)USBH2_HC_EHCI_BASE_ADDRESS,
                                     USBH2_HC_EHCI_PORT_MASK,
                                     USBH2_HC_EHCI_ENDPOINT_NUM,
                                     USBH2_HC_EHCI_TRANSFER_NUM,
                                     0,
                                     0,
                                     1024,
                                    &usbh2_ehci_pfl[0],
                                    &usbh2_ehci_qh[0],
                                    &usbh2_ehci_qtd[0],
                                     NULL,
                                     NULL,
                                     NULL,
                                    &usbh2_ehci_tdurb[0]
                                  };
#endif

extern  void    USBH2_CoreThread       (void const *arg);
#if    (!defined(USBH2_CORE_THREAD_STACK_SIZE))
#define USBH2_CORE_THREAD_STACK_SIZE    0
#endif
#if    (!defined(USBH2_CORE_THREAD_PRIORITY))
#define USBH2_CORE_THREAD_PRIORITY      osPriorityNormal
#endif
osThreadDef(USBH2_CoreThread, USBH2_CORE_THREAD_PRIORITY, 1, USBH2_CORE_THREAD_STACK_SIZE);

#endif


/*------------------------------------------------------------------------------
 *      USB Host 3 Macros, Calculations and Constants for Library
 *----------------------------------------------------------------------------*/

#if     (defined(USBH3_HC_NUM) && defined(RTE_USB_Host_3))

#if     (USBH3_HC_MEM_POOL_RELOC == 1)
#define __AT_MEM3(x)              __attribute__((at(x)))
#else
#define __AT_MEM3(x)                
#endif
#define __ALIGNED_MEM3(x)         __attribute__((aligned(x)))

uint32_t usbh3_mem_pool            [(USBH3_HC_MEM_POOL_SIZE +3)/4] __AT_MEM3(USBH3_HC_MEM_POOL_ADDR);
const uint32_t usbh3_mem_pool_size=((USBH3_HC_MEM_POOL_SIZE +3)/4)*4;

#if     (USBH3_HC_IF == 0)              // Custom

extern   ARM_DRIVER_USBH            USBHn_DRIVER(USBH3_HC_NUM);
const    ARM_DRIVER_USBH           *usbh3_hcd_ptr = &USBHn_DRIVER(USBH3_HC_NUM);

#elif   (USBH3_HC_IF == 1)              // OHCI

extern   ARM_DRIVER_USBH            USBHn_DRIVER_OHCI_LIB(USBH3_HC_NUM);
const    ARM_DRIVER_USBH           *usbh3_hcd_ptr = &USBHn_DRIVER_OHCI_LIB(USBH3_HC_NUM);

extern   ARM_DRIVER_USBH_HCI        USBHn_DRIVER_HCI(USBH3_HC_NUM);
const    ARM_DRIVER_USBH_HCI       *usbh3_hci_hcd_ptr = &USBHn_DRIVER_HCI(USBH3_HC_NUM);

#define  USBH3_OHCI_MEM_HCCA        (USBH3_HC_MEM_POOL_ADDR + (((USBH3_HC_MEM_POOL_SIZE + 3)/4)*4))
#define  USBH3_OHCI_MEM_HCCA_SIZE   (256)
#define  USBH3_OHCI_MEM_ED          (USBH3_OHCI_MEM_HCCA + USBH3_EHCI_MEM_HCCA_SIZE)
#define  USBH3_OHCI_MEM_ED_SIZE     (USBH3_HC_OHCI_ENDPOINT_NUM*16)
#define  USBH3_OHCI_MEM_TD          (USBH3_EHCI_MEM_ED   + USBH3_EHCI_MEM_ED_SIZE)
#define  USBH3_OHCI_MEM_TD_SIZE     (USBH3_HC_OHCI_TRANSFER_NUM*16)
#define  USBH3_OHCI_MEM_TDURB       (USBH3_EHCI_MEM_QTD  + USBH3_EHCI_MEM_QTD_SIZE)
#define  USBH3_OHCI_MEM_TDURB_SIZE  (USBH3_HC_EHCI_TRANSFER_NUM* 8)

uint32_t usbh3_ohci_hcca           [(USBH3_OHCI_MEM_HCCA_SIZE +3)/4] __AT_MEM3(USBH3_OHCI_MEM_HCCA);
uint32_t usbh3_ohci_ed             [(USBH3_OHCI_MEM_ED_SIZE   +3)/4] __AT_MEM3(USBH3_OHCI_MEM_ED);
uint32_t usbh3_ohci_td             [(USBH3_OHCI_MEM_TD_SIZE   +3)/4] __AT_MEM3(USBH3_OHCI_MEM_TD);
uint32_t usbh3_ohci_tdurb          [(USBH3_OHCI_MEM_TDURB_SIZE+3)/4] __AT_MEM3(USBH3_OHCI_MEM_TDURB);

USBH_OHCI_t usbh3_ohci = { 
                                     (uint32_t *)USBH3_HC_OHCI_BASE_ADDRESS,
                                     USBH3_HC_OHCI_PORT_MASK,
                                     USBH3_HC_OHCI_ENDPOINT_NUM,
                                     USBH3_HC_OHCI_TRANSFER_NUM,
                                     0,
                                    &usbh3_ohci_hcca,
                                    &usbh3_ohci_ed,
                                    &usbh3_ohci_td,
                                     NULL,
                                    &usbh3_ohci_tdurb
                                   };

#elif   (USBH3_HC_IF == 2)              // EHCI with OHCI support

extern   ARM_DRIVER_USBH            USBHn_DRIVER_EHCI_LIB(USBH3_HC_NUM);
const    ARM_DRIVER_USBH           *usbh3_hcd_ptr = &USBHn_DRIVER_EHCI_LIB(USBH3_HC_NUM);

extern   ARM_DRIVER_USBH_HCI        USBHn_DRIVER_HCI(USBH3_HC_NUM);
const    ARM_DRIVER_USBH_HCI       *usbh3_hci_hcd_ptr = &USBHn_DRIVER_HCI(USBH3_HC_NUM);

#define  USBH3_EHCI_MEM_PFL         (USBH3_HC_MEM_POOL_ADDR + (((USBH3_HC_MEM_POOL_SIZE + 3)/4)*4))
#define  USBH3_EHCI_MEM_PFL_SIZE    (4096)
#define  USBH3_EHCI_MEM_QH          (USBH3_EHCI_MEM_PFL  + USBH3_EHCI_MEM_PFL_SIZE)
#define  USBH3_EHCI_MEM_QH_SIZE     (USBH3_HC_EHCI_ENDPOINT_NUM*64)
#define  USBH3_EHCI_MEM_QTD         (USBH3_EHCI_MEM_QH   + USBH3_EHCI_MEM_QH_SIZE)
#define  USBH3_EHCI_MEM_QTD_SIZE    (USBH3_HC_EHCI_TRANSFER_NUM*32)
#define  USBH3_EHCI_MEM_TDURB       (USBH3_EHCI_MEM_QTD  + USBH3_EHCI_MEM_QTD_SIZE)
#define  USBH3_EHCI_MEM_TDURB_SIZE  (USBH3_HC_EHCI_TRANSFER_NUM*12)

uint32_t usbh3_ehci_pfl            [(USBH3_EHCI_MEM_PFL_SIZE  +3)/4] __AT_MEM3(USBH3_EHCI_MEM_PFL) __ALIGNED_MEM3(4096);
uint32_t usbh3_ehci_qh             [(USBH3_EHCI_MEM_QH_SIZE   +3)/4] __AT_MEM3(USBH3_EHCI_MEM_QH);
uint32_t usbh3_ehci_qtd            [(USBH3_EHCI_MEM_QTD_SIZE  +3)/4] __AT_MEM3(USBH3_EHCI_MEM_QTD) __ALIGNED_MEM3(32);
uint32_t usbh3_ehci_tdurb          [(USBH3_EHCI_MEM_TDURB_SIZE+3)/4] __AT_MEM3(USBH3_EHCI_MEM_TDURB);

USBH_EHCI_t usbh3_ehci = { 
                                    (uint32_t *)USBH3_HC_EHCI_BASE_ADDRESS,
                                     USBH3_HC_EHCI_PORT_MASK,
                                     USBH3_HC_EHCI_ENDPOINT_NUM,
                                     USBH3_HC_EHCI_TRANSFER_NUM,
                                     0,
                                     0,
                                     1024,
                                    &usbh3_ehci_pfl[0],
                                    &usbh3_ehci_qh[0],
                                    &usbh3_ehci_qtd[0],
                                     NULL,
                                     NULL,
                                     NULL,
                                    &usbh3_ehci_tdurb[0]
                                  };
#endif

extern  void    USBH3_CoreThread       (void const *arg);
#if    (!defined(USBH3_CORE_THREAD_STACK_SIZE))
#define USBH3_CORE_THREAD_STACK_SIZE    0
#endif
#if    (!defined(USBH3_CORE_THREAD_PRIORITY))
#define USBH3_CORE_THREAD_PRIORITY      osPriorityNormal
#endif
osThreadDef(USBH3_CoreThread, USBH3_CORE_THREAD_PRIORITY, 1, USBH3_CORE_THREAD_STACK_SIZE);

#endif


/*------------------------------------------------------------------------------
 *      USB Host 0..3 Configurations
 *----------------------------------------------------------------------------*/

#if    (defined(LAST_DEVICE_COMPILE))

#ifndef USBH_MSC_NUM
#define USBH_MSC_NUM       0
#endif

#ifndef USBH_HID_NUM
#define USBH_HID_NUM       0
#endif

#ifndef USBH_CLS_NUM
#define USBH_CLS_NUM       0
#endif

#if     defined(RTE_USB_Host_0)
#define USBH0_HC           1
#else
#define USBH0_HC           0
#endif

#if     defined(RTE_USB_Host_1)
#define USBH1_HC           1
#else
#define USBH1_HC           0
#endif

#if     defined(RTE_USB_Host_2)
#define USBH2_HC           1
#else
#define USBH2_HC           0
#endif

#if     defined(RTE_USB_Host_3)
#define USBH3_HC           1
#else
#define USBH3_HC           0
#endif

#define USBH_HC_NUM       (USBH0_HC + USBH1_HC + USBH2_HC + USBH3_HC)
#define USBH_HC_MSK       (0x0F >> (4 - USBH_HC_NUM))
#define USBH_OHCI_NUM     (USBH_HC_NUM)
#define USBH_EHCI_NXP_NUM (USBH_HC_NUM)
#define USBH_DCD_NUM      ((USBH_MSC_NUM > 0) + (USBH_HID_NUM > 0) + (USBH_CLS_NUM > 0))
#define USBH_DEV_NUM      ( USBH_MSC_NUM      +  USBH_HID_NUM      +  USBH_CLS_NUM     )

                                        // Define constants
        const uint8_t usbh_hc_num  = USBH_HC_NUM;
        const uint8_t usbh_hc_msk  = USBH_HC_MSK;
        const uint8_t usbh_dcd_num = USBH_DCD_NUM;
        const uint8_t usbh_dev_num = USBH_DEV_NUM;
        const uint8_t usbh_msc_num = USBH_MSC_NUM;
        const uint8_t usbh_hid_num = USBH_HID_NUM;
        const uint8_t usbh_cls_num = USBH_CLS_NUM;

extern  ARM_DRIVER_USBH        USBHn_DRIVER(USBH0_HC_NUM);
extern  ARM_DRIVER_USBH        USBHn_DRIVER(USBH1_HC_NUM);
extern  ARM_DRIVER_USBH        USBHn_DRIVER(USBH2_HC_NUM);
extern  ARM_DRIVER_USBH        USBHn_DRIVER(USBH3_HC_NUM);

extern  const ARM_DRIVER_USBH *usbh0_hcd_ptr;
extern  const ARM_DRIVER_USBH *usbh1_hcd_ptr;
extern  const ARM_DRIVER_USBH *usbh2_hcd_ptr;
extern  const ARM_DRIVER_USBH *usbh3_hcd_ptr;

                                        // Register Host Controller Drivers
const   ARM_DRIVER_USBH ** const usbh_hcd_ptr[USBH_HC_NUM] = { 
#if     defined(RTE_USB_Host_0)
                     &usbh0_hcd_ptr
#endif
#if     defined(RTE_USB_Host_1)
                   , &usbh1_hcd_ptr
#endif
#if     defined(RTE_USB_Host_2)
                   , &usbh2_hcd_ptr
#endif
#if     defined(RTE_USB_Host_3)
                   , &usbh3_hcd_ptr
#endif
};

#if   ((USBH0_HC_IF == 1) || (USBH1_HC_IF == 1) || (USBH2_HC_IF == 1) || (USBH3_HC_IF == 1) || \
       (USBH0_HC_IF == 2) || (USBH1_HC_IF == 2) || (USBH2_HC_IF == 2) || (USBH3_HC_IF == 2)  )
extern  const ARM_DRIVER_USBH_HCI *usbh0_hci_hcd_ptr;
extern  const ARM_DRIVER_USBH_HCI *usbh1_hci_hcd_ptr;
extern  const ARM_DRIVER_USBH_HCI *usbh2_hci_hcd_ptr;
extern  const ARM_DRIVER_USBH_HCI *usbh3_hci_hcd_ptr;

const   ARM_DRIVER_USBH_HCI ** const usbh_hci_hcd_ptr[USBH_HC_NUM] = {
#if     defined(RTE_USB_Host_0)
                     &usbh0_hci_hcd_ptr
#endif
#if     defined(RTE_USB_Host_1)
                   , &usbh1_hci_hcd_ptr
#endif
#if     defined(RTE_USB_Host_2)
                   , &usbh2_hci_hcd_ptr
#endif
#if     defined(RTE_USB_Host_3)
                   , &usbh3_hci_hcd_ptr
#endif
};
#endif

#if   ((USBH0_HC_IF == 1) || (USBH1_HC_IF == 1) || (USBH2_HC_IF == 1) || (USBH3_HC_IF == 1))
extern  USBH_OHCI_t usbh0_ohci;
extern  USBH_OHCI_t usbh1_ohci;
extern  USBH_OHCI_t usbh2_ohci;
extern  USBH_OHCI_t usbh3_ohci;

const   USBH_OHCI_t * const usbh_ohci_ptr [USBH_HC_NUM] = { 
#if     defined(RTE_USB_Host_0)
                     &usbh0_ohci
#endif
#if     defined(RTE_USB_Host_1)
                   , &usbh1_ohci
#endif
#if     defined(RTE_USB_Host_2)
                   , &usbh2_ohci
#endif
#if     defined(RTE_USB_Host_3)
                   , &usbh3_ohci
#endif
};
#endif

#if   ((USBH0_HC_IF == 2) || (USBH1_HC_IF == 2) || (USBH2_HC_IF == 2) || (USBH3_HC_IF == 2))
extern  USBH_EHCI_t usbh0_ehci;
extern  USBH_EHCI_t usbh1_ehci;
extern  USBH_EHCI_t usbh2_ehci;
extern  USBH_EHCI_t usbh3_ehci;

const   USBH_EHCI_t * const usbh_ehci_ptr [USBH_HC_NUM] = { 
#if     defined(RTE_USB_Host_0)
                     &usbh0_ehci
#endif
#if     defined(RTE_USB_Host_1)
                   , &usbh1_ehci
#endif
#if     defined(RTE_USB_Host_2)
                   , &usbh2_ehci
#endif
#if     defined(RTE_USB_Host_3)
                   , &usbh3_ehci
#endif
};
#endif

#if     defined(RTE_USB_Host_0)
extern  uint32_t         usbh0_mem_pool[];
extern  const uint32_t   usbh0_mem_pool_size;
#endif
#if     defined(RTE_USB_Host_1)
extern  uint32_t         usbh1_mem_pool[];
extern  const uint32_t   usbh1_mem_pool_size;
#endif
#if     defined(RTE_USB_Host_2)
extern  uint32_t         usbh2_mem_pool[];
extern  const uint32_t   usbh2_mem_pool_size;
#endif
#if     defined(RTE_USB_Host_3)
extern  uint32_t         usbh3_mem_pool[];
extern  const uint32_t   usbh3_mem_pool_size;
#endif

        uint32_t * const usbh_mem_pool_ptr [USBH_HC_NUM] = {
#if     defined(RTE_USB_Host_0)
                     usbh0_mem_pool
#endif
#if     defined(RTE_USB_Host_1)
                   , usbh1_mem_pool
#endif
#if     defined(RTE_USB_Host_2)
                   , usbh2_mem_pool
#endif
#if     defined(RTE_USB_Host_3)
                   , usbh3_mem_pool
#endif
};
const   uint32_t * const usbh_mem_pool_size_ptr [USBH_HC_NUM] = {
#if     defined(RTE_USB_Host_0)
                     &usbh0_mem_pool_size
#endif
#if     defined(RTE_USB_Host_1)
                   , &usbh0_mem_pool_size
#endif
#if     defined(RTE_USB_Host_2)
                   , &usbh0_mem_pool_size
#endif
#if     defined(RTE_USB_Host_3)
                   , &usbh0_mem_pool_size
#endif
};

#if    (USBH_MSC_NUM)
extern  USBH_DCD      usbh_dcd_msc;
#endif
#if    (USBH_HID_NUM)
extern  USBH_DCD      usbh_dcd_hid;
#endif
#if    (USBH_CLS_NUM)
extern  USBH_DCD      usbh_dcd_cls;
#endif

                                        // Register Class Drivers
const   USBH_DCD * const usbh_dcd_ptr[USBH_DCD_NUM] = { 
#if    (USBH_MSC_NUM)
                     &usbh_dcd_msc,
#endif
#if    (USBH_HID_NUM)
                     &usbh_dcd_hid,
#endif
#if    (USBH_CLS_NUM)
                     &usbh_dcd_cls
#endif
};

extern const osThreadDef_t os_thread_def_USBH0_CoreThread;
extern const osThreadDef_t os_thread_def_USBH1_CoreThread;
extern const osThreadDef_t os_thread_def_USBH2_CoreThread;
extern const osThreadDef_t os_thread_def_USBH3_CoreThread;

const   osThreadDef_t * const usbh_core_thread_def_ptr[USBH_HC_NUM] = {
#if     defined(RTE_USB_Host_0)
                      osThread(USBH0_CoreThread)
#endif
#if     defined(RTE_USB_Host_1)
                    , osThread(USBH1_CoreThread)
#endif
#if     defined(RTE_USB_Host_2)
                    , osThread(USBH2_CoreThread)
#endif
#if     defined(RTE_USB_Host_3)
                    , osThread(USBH3_CoreThread)
#endif
};
osThreadId usbh_core_thread_id[USBH_HC_NUM];

#define USBH_DEBOUNCE_IN_MS 100

const   uint16_t usbh_debounce_in_ms[USBH_HC_NUM] = {
#if     defined(RTE_USB_Host_0)
                      USBH_DEBOUNCE_IN_MS
#endif
#if     defined(RTE_USB_Host_1)
                    , USBH_DEBOUNCE_IN_MS
#endif
#if     defined(RTE_USB_Host_2)
                    , USBH_DEBOUNCE_IN_MS
#endif
#if     defined(RTE_USB_Host_3)
                    , USBH_DEBOUNCE_IN_MS
#endif
};

extern  void USBH_ConDisconDebounce (void const * arg);
#if     defined(RTE_USB_Host_0)
osTimerDef (USBH_DebounceTimer0, USBH_ConDisconDebounce);
#endif
#if     defined(RTE_USB_Host_1)
osTimerDef (USBH_DebounceTimer1, USBH_ConDisconDebounce);
#endif
#if     defined(RTE_USB_Host_2)
osTimerDef (USBH_DebounceTimer2, USBH_ConDisconDebounce);
#endif
#if     defined(RTE_USB_Host_3)
osTimerDef (USBH_DebounceTimer3, USBH_ConDisconDebounce);
#endif
const   osTimerDef_t * const usbh_debounce_timer_def_ptr[USBH_HC_NUM] = {
#if     defined(RTE_USB_Host_0)
                      osTimer(USBH_DebounceTimer0)
#endif
#if     defined(RTE_USB_Host_1)
                    , osTimer(USBH_DebounceTimer1)
#endif
#if     defined(RTE_USB_Host_2)
                    , osTimer(USBH_DebounceTimer2)
#endif
#if     defined(RTE_USB_Host_3)
                    , osTimer(USBH_DebounceTimer3)
#endif
};
osTimerId usbh_debounce_timer_id[USBH_HC_NUM];

extern  void USBH_SignalPortEvent     (uint8_t ctrl, uint8_t port, ARM_USBH_EVENT event);
extern  void USBH_SignalEndpointEvent (uint8_t ctrl, ARM_USBH_EP_HANDLE ep_hndl, ARM_USBH_URB *ptr_urb);
#if     defined(RTE_USB_Host_0)
        void USBH0_SignalPortEvent    (uint8_t port, ARM_USBH_EVENT event)                { USBH_SignalPortEvent    (0, port, event);      }
        void USBH0_SignalEndpointEvent(ARM_USBH_EP_HANDLE ep_hndl, ARM_USBH_URB *ptr_urb) { USBH_SignalEndpointEvent(0, ep_hndl, ptr_urb); }
#endif

#if     defined(RTE_USB_Host_1)
        void USBH1_SignalPortEvent    (uint8_t port, ARM_USBH_EVENT event)                { USBH_SignalPortEvent    (1, port, event);      }
        void USBH1_SignalEndpointEvent(ARM_USBH_EP_HANDLE ep_hndl, ARM_USBH_URB *ptr_urb) { USBH_SignalEndpointEvent(1, ep_hndl, ptr_urb); }
#endif

#if     defined(RTE_USB_Host_2)
        void USBH2_SignalPortEvent    (uint8_t port, ARM_USBH_EVENT event)                { USBH_SignalPortEvent    (2, port, event);      }
        void USBH2_SignalEndpointEvent(ARM_USBH_EP_HANDLE ep_hndl, ARM_USBH_URB *ptr_urb) { USBH_SignalEndpointEvent(2, ep_hndl, ptr_urb); }
#endif

#if     defined(RTE_USB_Host_3)
        void USBH3_SignalPortEvent    (uint8_t port, ARM_USBH_EVENT event)                { USBH_SignalPortEvent    (3, port, event);      }
        void USBH3_SignalEndpointEvent(ARM_USBH_EP_HANDLE ep_hndl, ARM_USBH_URB *ptr_urb) { USBH_SignalEndpointEvent(3, ep_hndl, ptr_urb); }
#endif

#if    (USBH_HC_NUM > 0)
        ARM_USBH_SignalPortEvent_t const usbh_cb_port_event_ptr[USBH_HC_NUM] = {
#if     defined(RTE_USB_Host_0)
                      USBH0_SignalPortEvent
#endif
#if     defined(RTE_USB_Host_1)
                    , USBH1_SignalPortEvent
#endif
#if     defined(RTE_USB_Host_2)
                    , USBH2_SignalPortEvent
#endif
#if     defined(RTE_USB_Host_3)
                    , USBH3_SignalPortEvent 
#endif
};

        ARM_USBH_SignalEndpointEvent_t const usbh_cb_endpoint_event_ptr[USBH_HC_NUM] = {
#if     defined(RTE_USB_Host_0)
                      USBH0_SignalEndpointEvent
#endif
#if     defined(RTE_USB_Host_1)
                    , USBH1_SignalEndpointEvent
#endif
#if     defined(RTE_USB_Host_2)
                    , USBH2_SignalEndpointEvent
#endif
#if     defined(RTE_USB_Host_3)
                    , USBH3_SignalEndpointEvent
#endif
};

ARM_DRV_VERSION         usbh_drv_version [USBH_HC_NUM] = { 0 };
ARM_USBH_CAPABILITIES   usbh_capabilities[USBH_HC_NUM] = { 0 };

USBH_HCI  usbh_hci [USBH_HC_NUM]  = { 0 };
#endif

USBH_DEV  usbh_dev [USBH_DEV_NUM] = { 0 };

#if      (USBH_MSC_NUM)
USBH_MSC  usbh_msc [USBH_MSC_NUM] = { 0 };
#endif
#if      (USBH_HID_NUM)
USBH_HID  usbh_hid [USBH_HID_NUM] = { 0 };
extern    void USBH_HID_Thread (void const *arg);
osThreadId usbh_hid_thread_id[USBH_HID_NUM];
osThreadDef(USBH_HID_Thread, osPriorityAboveNormal, USBH_HID_NUM, NULL);
const     osThreadDef_t * const usbh_hid_thread_def_ptr[USBH_HID_NUM] = {
#if      (USBH_HID_NUM > 0)
                      osThread(USBH_HID_Thread)
#endif
#if      (USBH_HID_NUM > 1)
                    , osThread(USBH_HID_Thread)
#endif
#if      (USBH_HID_NUM > 2)
                    , osThread(USBH_HID_Thread)
#endif
#if      (USBH_HID_NUM > 3)
                    , osThread(USBH_HID_Thread) 
#endif
};
#endif
#if      (USBH_CLS_NUM)
USBH_CLS  usbh_cls [USBH_CLS_NUM] = { 0 };
#endif

#endif

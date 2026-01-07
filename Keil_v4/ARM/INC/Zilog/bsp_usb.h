
#ifndef _BSP_USB_

#define _BSP_USB_

#include "za9_usb.h"
#include "bsp_utils.h"
#include "bsp_types.h"
#include "otgapi.h"
#include "host_common.h"
#include "devapi.h"
#include "hostapi.h"
#include "types.h"
#include "usb.h"


#define  MAX_USB_CONTROLLERS     1
//Max No of EPs implemented (Bi-Directional numbering 0-3)
#define  MAX_ENDPNTS       4

#define     USB_HOST   1
#define     USB_DEV    2
#define     USB_OTG    3


typedef struct BSP_DEV_SERVICE_S
{

   UINT32      ServiceType;

   void (*pDevServiceCallBack)
   ( void      *handle,   
    UINT32     setup,
    UINT8      direction,
    UINT8      *pBuffer,
    UINT32     length,
    UINT8      error
   );

} BSP_DEV_SERVICE;


typedef struct BSP_USB_S
{
   BSP_SEM               IsAvailable;   // IsAvailable = 0 dev acquired, dev free for acquisition
   UINT32                StackMode;     // Host, OTG, Device
   UINT32                Base;          // Base address of the USB
   UINT32                ControllerNum; // Controller Number 
   
   /* Device related */
   void                  *DevHandle;    // pointer to dev stack handle
   BSP_DEV_SERVICE       *pDevService;  
   UINT32                NumDevServicesStructures;
   UINT32                DevEndPoints;
   
   /* Host related */   
   void                  *HostHandle;      // pointer to host stack handle
   void                  *info_table_ptr;

   /* OTG related */
   UINT32                OtgRole;       // 1 = USB_HOST or 2 = USB_DEV
   void                  *OtgHandle;    // pointer to Otg stack handle
   void                  *OtgInit;      // OTG initialization structure
   
} BSP_USB;


/*
 * Function Prototypes
 */
extern BSP_STATUS BSP_USB_Init( void );
extern BSP_STATUS BSP_USB_Release( BSP_USB * pUsb );

/* Device related BSP wrapper APIs */
extern BSP_USB *  BSP_USB_DeviceAcquire(UINT32   UsbControllerum, UINT32 DevEndPoints);
extern BSP_STATUS BSP_USB_DeviceDeinitEndpoint(BSP_USB   *pUsb, UINT8 EpNum, UINT8 Direction);
extern BSP_STATUS BSP_USB_DeviceReceiveData(BSP_USB  *pUsb, UINT8 EpNum, UINT8 *pBuff, UINT32 Size);
extern BSP_STATUS BSP_USB_DeviceCancelTransfer(BSP_USB  *pUsb, UINT8 EpNum, UINT8 Direction);
extern BSP_STATUS BSP_USB_DeviceSendData(BSP_USB *pUsb, UINT8 EpNum, UINT8 *pBuff, UINT32 Size);
extern BSP_STATUS BSP_USB_DeviceUnstallEndPoint(BSP_USB *pUsb, UINT8 EpNum, UINT8 Direction);
extern BSP_STATUS BSP_USB_DeviceGetStatus(BSP_USB *pUsb, UINT8 Component, UINT16 *pStatusVal);
extern BSP_STATUS BSP_USB_DeviceSetStatus(BSP_USB *pUsb, UINT8 Component, UINT16 Setting);
extern BSP_STATUS BSP_USB_DeviceStallEndpoint(BSP_USB *pUsb, UINT8 EpNum, UINT8 Direction);
extern BSP_STATUS BSP_USB_DeviceAssertResume(BSP_USB *pUsb);
extern BSP_STATUS BSP_USB_DeviceRegisterService(BSP_USB *pUsb, UINT8 Type, void(*service)(void *DevHandle, BSP_BOOL IsSetup, UINT8 Direction, UINT8 * pBuff, UINT32 DataSize, UINT8 Error));
extern BSP_STATUS BSP_USB_DeviceUnregisterService(BSP_USB *pUsb, UINT8 Type);
extern BSP_STATUS BSP_USB_DeviceInitEndpoint(BSP_USB *pUsb, UINT8 EpNum, UINT16 MaxPktSize, UINT8 Direction, UINT8 Type, UINT8 Flag);
extern BSP_STATUS BSP_USB_DeviceGetTransferStatus(BSP_USB *pUsb, UINT8 EpNum, UINT8 Direction);
extern BSP_STATUS BSP_USB_DeviceReadSetupData(BSP_USB *pUsb, UINT8 EpNum, UINT8 *pBuff);
extern BSP_STATUS BSP_USB_DeviceShutDown(BSP_USB *pUsb);


/* OTG related BSP wrapper APIs */
extern BSP_USB *  BSP_USB_OTGAcquire(UINT32 UsbControllerum, void *pOtgInitStruct);
extern BSP_STATUS BSP_USB_OTGGetStatus(BSP_USB  *pUsb, UINT8 Component, UINT32 *pStatusVal);
extern BSP_STATUS BSP_USB_OTGSetStatus(BSP_USB  *pUsb, UINT8 Component, BSP_BOOL SetVal);


/* HOST related BSP wrapper APIs */

extern BSP_USB *  BSP_USB_HostAcquire(UINT32 UsbControllerum, UINT32 MaxFrameSize);
extern BSP_STATUS BSP_USB_HostBusControl(BSP_USB *pUsb, UINT8 BusControl);
extern BSP_STATUS BSP_USB_HostSendData(BSP_USB *pUsb, void * PipeHandle, void *TrParams );
extern BSP_STATUS BSP_USB_HostClosePipe(BSP_USB *pUsb, void * PipeHandle);
extern BSP_STATUS BSP_USB_HostCloseAllPipes(BSP_USB *pUsb);
extern UINT32     BSP_USB_HostCancelTransfer(BSP_USB *pUsb, void *PipeHandle, UINT32 TrNumber);
extern BSP_STATUS BSP_USB_HostReceiveData(BSP_USB *pUsb, void *PipeHandle, void *pTrParams);
extern BSP_STATUS BSP_USB_HostUnregisterService(BSP_USB *pUsb, UINT8 Type);
extern BSP_STATUS BSP_USB_HostRegisterService(BSP_USB *pUsb, UINT8 Type, void (*pService)(void *HostHandle, UINT32 CallBakParam));
extern BSP_STATUS BSP_USB_HostOpenPipe(BSP_USB *pUsb, void *PipeInitParam, void **PipeHandle);
extern BSP_STATUS BSP_USB_HostSendSetup(BSP_USB *pUsb, void *PipeHandle, void *TrParams);
extern UINT32     BSP_USB_HostGetTransferStatus(BSP_USB *pUsb, void *PipeHanlde, UINT32 TrNumber);
extern BSP_STATUS BSP_USB_HostDriverInfoRegister(BSP_USB *pUsb, void *InfoTable);
extern void  *    BSP_USB_HostDevFindPipeHandle(BSP_USB *pUsb,  void *DevInstanceHandle, void *InterfaceHandle, UINT8 PipeType, UINT8 PipeDirection);
extern BSP_STATUS BSP_USB_HostDevGetBuffer(BSP_USB *pUsb, void *pDevInstanceHandle, UINT32 BufferSize, UINT8 **ppBuffer);
extern BSP_STATUS BSP_USB_HostDevGetDescriptor(BSP_USB *pUsb, void *pDevInstanceHandle, UINT32 DescType, UINT8 DescIndex, UINT8 InterfaceAlt, void **ppDescriptor);
extern BSP_STATUS BSP_USB_HostDevSelectConfig(BSP_USB *pUsb, void *pDevInstanceHandle, UINT8 ConfigNum);
extern BSP_STATUS BSP_USB_HostDevSelectInterface(BSP_USB *pUsb, void *pDevInstanceHandle, void * InterfaceHandle, void *ClassInterfacePtr);
extern BSP_STATUS BSP_USB_HostDevTrInit(BSP_USB *pUsb, void *pTrInitParamStruct, void (*pTrCallBack)(void *, void *, UINT8 *, UINT32, UINT32),void *pCallBackParam);
extern BSP_STATUS BSP_USB_HostShutDown(BSP_USB *pUsb);

#endif

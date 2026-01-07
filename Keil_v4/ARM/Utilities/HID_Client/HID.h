
#ifndef __HID_H__
#define __HID_H__


extern void  HID_Init();
extern void  HID_UnInit();
extern int   HID_FindDevices();
extern BOOL  HID_GetName(int num, char *buf, int sz);
extern BOOL  HID_Open(int num);
extern void  HID_Close();
extern BOOL  HID_Read (BYTE *buf, DWORD sz, DWORD *cnt);
extern BOOL  HID_Write(BYTE *buf, DWORD sz, DWORD *cnt);


#endif /* __HID_H__ */

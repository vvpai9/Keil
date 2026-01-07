
#ifndef __DEV_ITM_H__
#define __DEV_ITM_H__



// Prototypes
// ----------------------   IO   -------------------------------
         int  Open_ITM    (void);
unsigned int  Output_ITM  (const unsigned char *buf, unsigned int len);
unsigned int  Input_ITM   (unsigned char *buf, unsigned int len);
         int  Close_ITM   (void);
         
// ----------------------   Driver   -------------------------------
int  itm_putchar_retarget (int c);


#endif


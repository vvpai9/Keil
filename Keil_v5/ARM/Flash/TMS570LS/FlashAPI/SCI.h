#ifndef _SCI_H_
#define _SCI_H_

// Function Declarations
void SCI_Init(unsigned int baudValue);
void PutText(char *text);
void PutDecimal(unsigned short int n);
void PutHundreths(unsigned short int n);
void PutChar(unsigned char c);
void PutHex(unsigned int x, unsigned int digits);
void load(char * load, char * run, unsigned int length);
unsigned char GetChar();

// Symbol Definitions
#define SCIADDR 0xFFF7E400
#define SCIGCR0 (*(volatile unsigned int *) (SCIADDR))
#define SCIGCR1 (*(volatile unsigned int *) (SCIADDR+0x4))
#define SCIFLR  (*(volatile unsigned int *) (SCIADDR+0x1C))
#define SCICHAR (*(volatile unsigned int *) (SCIADDR+0x28))
#define SCIBAUD (*(volatile unsigned int *) (SCIADDR+0x2C))
#define SCIRD   (*(volatile unsigned char *)(SCIADDR+0x37))
#define SCITD   (*(volatile unsigned char *)(SCIADDR+0x3B))
#define SCIPI00 (*(volatile unsigned int *) (SCIADDR+0x3C))
#define SCIPI07 (*(volatile unsigned int *) (SCIADDR+0x58))
#define SCITXREADY (SCIFLR & (0x0800))
#define SCIRXREADY (SCIFLR & (0x0200))

// Type Definitions
enum bool {False,True};

#endif // _SCI_H_

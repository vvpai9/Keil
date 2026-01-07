#ifndef CONFIDENCETEST_H_
#define CONFIDENCETEST_H_

// Declarations of button images in 16bit (R5G6B5) BMP format
extern unsigned char const TI_Logo_16bpp[];
extern unsigned char const TI_Logo2_16bpp[];
extern unsigned char const Keil_Logo_16bpp[];
extern unsigned char const Relais_Aus_16bpp[];
extern unsigned char const Relais_Ein_16bpp[];
extern unsigned char const MemoryButton_16bpp[];
extern unsigned char const Button_CAN_16bpp[];
extern unsigned char const Button_Memory_16bpp[];
extern unsigned char const Button_Relay_16bpp[];
extern unsigned char const Button_Relay_sel_16bpp[];
extern unsigned char const Button_SDCard_16bpp[];
extern unsigned char const Button_Sensors_16bpp[];
extern unsigned char const Button_TmpLight_16bpp[];
extern unsigned char const Button_Solenoid_16bpp[];
extern unsigned char const Button_Sol1_16bpp[];
extern unsigned char const Button_Sol1_sel_16bpp[];
extern unsigned char const Button_Sol2_16bpp[];
extern unsigned char const Button_Sol2_sel_16bpp[];
extern unsigned char const Button_Sol3_16bpp[];
extern unsigned char const Button_Sol3_sel_16bpp[];
extern unsigned char const Button_Sol4_16bpp[];
extern unsigned char const Button_Sol4_sel_16bpp[];
extern unsigned char const Button_OK_16bpp[];
extern unsigned char const Button_Toggle_16bpp[];
extern unsigned char const Button_Air_16bpp[];
extern unsigned char const Button_Pump_16bpp[];
extern unsigned char const Button_Pump_sel_16bpp[];
extern unsigned char const Button_Valve_16bpp[];
extern unsigned char const Button_Valve_sel_16bpp[];

// Struct declarations from various modules
typedef struct {
  unsigned int x_min;
  unsigned int x_max;
  unsigned int y_min;
  unsigned int y_max;
  unsigned int action;
} TouchTable;

extern unsigned int clock_1s;


// Function declarations from various modules
extern void           small_delay         (void);
extern void           TIM_init            (void);
extern void           SER_init            (void);
extern int            sendchar            (int c);
extern void           Fray_init           (void);
extern int            Fray_test           (void);
extern void           beep                (void);

/* A/D Converter Interface Functions */
extern void adcInit(void);
extern void GetSolCurrent   (unsigned int * I1, unsigned int * I2, unsigned int * I3, unsigned int * I4);
extern void GetLightAndTemp (unsigned int * Light, unsigned int * Temp);
extern void GetSensorInput  (unsigned int * Input1, unsigned int * Input2);


/* SPI Interface Functions */
extern void           spi3Init            (void);
extern void           spi1Init            (void);
extern void           Touch_Init          (void);
extern unsigned int   Read16BitTSRegister (unsigned char RegAdr);
extern unsigned int   Read8BitTSRegister  (unsigned char RegAdr);
extern void           Write8BitTSRegister (unsigned char RegAdr, unsigned char Content);
extern unsigned int   Test_FRAM           (void);
extern void           ReadFRAMMemory      (unsigned int Address, unsigned int Count, unsigned char *Content);
extern void           WriteFRAMMemory     (unsigned int Address, unsigned int Count, unsigned char *Content);
extern unsigned int   Test_EEPROM         (void);
extern void           ReadEEMemory        (unsigned int Address, unsigned int Count, unsigned char *Content);
extern int            WriteEEMemory       (unsigned int Address, unsigned int Count, unsigned char *Content);
extern unsigned int   CheckForTouch       (TouchTable * TouchButtonTable, unsigned int wait);
extern void           NHET_Init           (void);

/********************************************************************/
/*  Define bit masks                                                */
/********************************************************************/
#define bit0   0x00000001
#define bit1   0x00000002
#define bit2   0x00000004
#define bit3   0x00000008
#define bit4   0x00000010
#define bit5   0x00000020
#define bit6   0x00000040
#define bit7   0x00000080
#define bit8   0x00000100
#define bit9   0x00000200
#define bit10  0x00000400
#define bit11  0x00000800
#define bit12  0x00001000
#define bit13  0x00002000
#define bit14  0x00004000
#define bit15  0x00008000
#define bit16  0x00010000
#define bit17  0x00020000
#define bit18  0x00040000
#define bit19  0x00080000
#define bit20  0x00100000
#define bit21  0x00200000
#define bit22  0x00400000
#define bit23  0x00800000
#define bit24  0x01000000
#define bit25  0x02000000
#define bit26  0x04000000
#define bit27  0x08000000
#define bit28  0x10000000
#define bit29  0x20000000
#define bit30  0x40000000
#define bit31  0x80000000

/*****************************************EMIF*****************************************************************************/
#define EMIF            0xFFFFE800 
#define NUM_EMIF_CS         4                     /*No of Chip Select*/
#define EMIF_CS0_ADDRMAP_START  0x60000000
#define EMIF_CS0_ADDRMAP_END    0x63FFFFFC
#define EMIF_CS1_ADDRMAP_START  0x64000000
#define EMIF_CS1_ADDRMAP_END    0x67FFFFFC
#define EMIF_CS2_ADDRMAP_START  0x68000000
#define EMIF_CS2_ADDRMAP_END    0x6BFFFFFC
#define EMIF_CS3_ADDRMAP_START  0x6C000000
#define EMIF_CS3_ADDRMAP_END    0x6FFFFFFC
/**************************************************************************************************************************/

#endif /*CONFIDENCETEST_H_*/

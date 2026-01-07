/**********************************************************************
 * $Id:: lh79524_iocon.h 27 2007-08-31 19:35:06Z kevinw                $
 *
 *  Project: LH79524 IOCON controller header file
 *
 *  Description:
 *      This file contains the definitions for IOCON controller on
 *      LH79524
 * 
 ***********************************************************************
 * Software that is described herein is for illustrative purposes only  
 * which provides customers with programming information regarding the  
 * products. This software is supplied "AS IS" without any warranties.  
 * NXP Semiconductors assumes no responsibility or liability for the 
 * use of the software, conveys no license or title under any patent, 
 * copyright, or mask work right to the product. NXP Semiconductors 
 * reserves the right to make changes in the software without 
 * notification. NXP Semiconductors also make no representation or 
 * warranty that such application will be suitable for the specified 
 * use without further testing or modification. 
 **********************************************************************/

#ifndef LH79524_IOCON_H
#define LH79524_IOCON_H

#include "lh79524_chip.h"

/***********************************************************************
 * IO Configuration Block Structure
 **********************************************************************/
typedef struct
{
  volatile UNS_32 mux_ctl_1;
  volatile UNS_32 res_ctl_1;
  volatile UNS_32 reserved0[2];
  volatile UNS_32 mux_ctl_3;
  volatile UNS_32 res_ctl_3;
  volatile UNS_32 mux_ctl_4;
  volatile UNS_32 res_ctl_4;
  volatile UNS_32 mux_ctl_5;
  volatile UNS_32 res_ctl_5;
  volatile UNS_32 mux_ctl_6;
  volatile UNS_32 res_ctl_6;
  volatile UNS_32 mux_ctl_7;
  volatile UNS_32 res_ctl_7;
  volatile UNS_32 reserved1[4];
  volatile UNS_32 mux_ctl_10;
  volatile UNS_32 res_ctl_10;
  volatile UNS_32 mux_ctl_11;
  volatile UNS_32 res_ctl_11;
  volatile UNS_32 mux_ctl_12;
  volatile UNS_32 res_ctl_12;
  volatile UNS_32 reserved2;
  volatile UNS_32 res_ctl_13;
  volatile UNS_32 mux_ctl_14;
  volatile UNS_32 reserved3;
  volatile UNS_32 mux_ctl_15;
  volatile UNS_32 res_ctl_15;
  volatile UNS_32 reserved4[3];
  volatile UNS_32 res_ctl_17;
  volatile UNS_32 reserved5[2];
  volatile UNS_32 mux_ctl_19;
  volatile UNS_32 res_ctl_19;
  volatile UNS_32 mux_ctl_20;
  volatile UNS_32 res_ctl_20;
  volatile UNS_32 mux_ctl_21;
  volatile UNS_32 res_ctl_21;
  volatile UNS_32 mux_ctl_22;
  volatile UNS_32 res_ctl_22;
  volatile UNS_32 mux_ctl_23;
  volatile UNS_32 res_ctl_23;
  volatile UNS_32 mux_ctl_24;
  volatile UNS_32 res_ctl_24;
  volatile UNS_32 mux_ctl_25;
} IOCON_REGS_T;

/***********************************************************************
 * Resistor Multiplexing IOCON Register Bit Field macros
 *
 **********************************************************************/
#define IOCON_PULLDOWN_VAL      1
#define IOCON_PULLUP_VAL        2
#define IOCON_FLOAT_VAL         0
#define IOCON_RES_MASK          _BITMASK(2)
#define IOCON_RES_SET(n,val)    _SBF(((n) * 2), val)
#define IOCON_PULLDOWN(n)       IOCON_RES_SET(n,IOCON_PULLDOWN_VAL)
#define IOCON_PULLUP(n)         IOCON_RES_SET(n,IOCON_PULLUP_VAL)
#define IOCON_FLOAT(n)          IOCON_RES_SET(n,IOCON_FLOAT_VAL)

#define IOCON_MUX_MASK(n)       ~(_SBF(n,_BITMASK(2)))

#define IOCON_RES1_PI2_ETHERCOL                         8
#define IOCON_RES1_PI1_ETHERMDIO                        6
#define IOCON_RES1_PI0_ETHERMDC                         4
#define IOCON_RES1_PL1_LCDVD15                          2
#define IOCON_RES1_PL0_LCDVD14                          0
                                                        
#define IOCON_RES3_CTCLK_INT4_BATCNTL                   0

#define IOCON_RES4_PA7_CTCAP2B_CTCMP2B_SCL              10
#define IOCON_RES4_PA6_CTCAP2A_CTCMP2A_SDA              8
#define IOCON_RES4_PA5_CTCAP1B_CTCMP1B                  6
#define IOCON_RES4_PA7_PA4_CTCAP1A_CTCMP1A              4
#define IOCON_RES4_PA3_CTCAP0B_CTCMP0B                  2
#define IOCON_RES4_PA2_CTCAP0A_CTCMP0A                  0

#define IOCON_RES5_PA1_INT3_UARTTX2_UARTIRTX2           14
#define IOCON_RES5_PA0_INT2_UARTRX2_UARTIRRX2           12
#define IOCON_RES5_PB7_INT1_UARTTX0_UARTIRTX0           10
#define IOCON_RES5_PB6_INT0_UARTRX0_UARTIRRX0           8
#define IOCON_RES5_PB5_SSPTX_I2STXD_UARTTX1_UARTIRTX1   6
#define IOCON_RES5_PB4_SSPRX_I2STXD_UARTRX1_UARTIRRX1   4
#define IOCON_RES5_PB3_SSPCLK_I2SLCK                    2
#define IOCON_RES5_PB2_SSPFRM_I2SWS                     0

#define IOCON_RES6_PB1_DREQ_UARTRTS0                    2
#define IOCON_RES6_PB0_DACK_UARTCTS0                    0

#define IOCON_RES7_PC7_A23_nFRE                         14
#define IOCON_RES7_PC6_A22_nFWE                         12
#define IOCON_RES7_PC5_A21                              10
#define IOCON_RES7_PC4_A20                              8
#define IOCON_RES7_PC3_A19                              6
#define IOCON_RES7_PC2_A18                              4
#define IOCON_RES7_PC1_A17                              2
#define IOCON_RES7_PC0_A16                              0

#define IOCON_RES10_PN3_D25                             14
#define IOCON_RES10_PN2_D24                             12
#define IOCON_RES10_PD7_D15                             10
#define IOCON_RES10_PK7_D23                             8
#define IOCON_RES10_PD6_D14                             6
#define IOCON_RES10_PK6_D22                             4
#define IOCON_RES10_PD5_D13                             2
#define IOCON_RES10_PK5_D21                             0

#define IOCON_RES11_PD4_D12                             14
#define IOCON_RES11_PK4_D20                             12
#define IOCON_RES11_PD3_D11                             10
#define IOCON_RES11_PK3_D19                             8
#define IOCON_RES11_PD2_D10                             6
#define IOCON_RES11_PK2_D18                             4
#define IOCON_RES11_PK1_D17                             2
#define IOCON_RES11_PD1_D9                              0

#define IOCON_RES12_PK0_D16                             14
#define IOCON_RES12_PD0_D8                              12
#define IOCON_RES12_D7                                  10
#define IOCON_RES12_D6                                  8
#define IOCON_RES12_D5                                  6
#define IOCON_RES12_D4                                  4
#define IOCON_RES12_D3                                  2
#define IOCON_RES12_D2                                  0

#define IOCON_RES13_D1                                  2
#define IOCON_RES13_D0                                  0

#define IOCON_RES15_BLE0_PM4                            0

#define IOCON_RES17_SDCLK                               0
 
#define IOCON_RES19_PE7_WAIT_DEOT                       14
#define IOCON_RES19_PE6_LCDVEEN_LCDMOD                  12
#define IOCON_RES19_PL7_D31                             10
#define IOCON_RES19_PE5_LCDVDDEN                        8
#define IOCON_RES19_PL6_D30                             6
#define IOCON_RES19_PE4_LCDSPLEN_LCDREV                 4
#define IOCON_RES19_PE3_LCDCLS                          2
#define IOCON_RES19_PL5_D29                             0

#define IOCON_RES20_PE2_LCDPS                           14
#define IOCON_RES20_PL4_D28                             12
#define IOCON_RES20_PE1_LCDDCLK                         10
#define IOCON_RES20_PN1_D27                             8
#define IOCON_RES20_PE0_LCDLP_LCDHRLP                   6
#define IOCON_RES20_PN0_D26                             4
#define IOCON_RES20_PF7_LCDFP_LCDSPS                    2
#define IOCON_RES20_PF6_LCDEN_LCDSPL                    0

#define IOCON_RES21_PF5_LCDVD11                         10
#define IOCON_RES21_PL3_LCDVD13                         8
#define IOCON_RES21_PF4_LCDVD10                         6
#define IOCON_RES21_PL2_LCDVD12                         4
#define IOCON_RES21_PF3_LCDVD9                          2
#define IOCON_RES21_PF2_LCDVD8                          0

#define IOCON_RES22_PF1_LCDVD7                          14
#define IOCON_RES22_PF0_LCDVD6                          12
#define IOCON_RES22_PG7_LCDVD5                          10
#define IOCON_RES22_PG6_LCDVD4                          8
#define IOCON_RES22_PG5_LCDVD3                          6
#define IOCON_RES22_PG4_LCDVD2                          4
#define IOCON_RES22_PG3_LCDVD1                          2
#define IOCON_RES22_PG2_LCDVD0                          0

#define IOCON_RES23_PG1_ETHERTXCLK                      14
#define IOCON_RES23_PG0_ETHERTXEN                       12
#define IOCON_RES23_PH7_ETHERTX3                        10
#define IOCON_RES23_PH6_ETHERTX2                        8
#define IOCON_RES23_PH5_ETHERTX1                        6
#define IOCON_RES23_PH4_ETHERTX0                        4
#define IOCON_RES23_PH3_ETHERTXER                       2
#define IOCON_RES23_PH2_ETHERRXCLK                      0

#define IOCON_RES24_PH1_ETHERRXDV                       12
#define IOCON_RES24_PH0_ETHERRX3                        10
#define IOCON_RES24_PI7_ETHERRX2                        8
#define IOCON_RES24_PI6_ETHERRX1                        6
#define IOCON_RES24_PI5_ETHERRX0                        4
#define IOCON_RES24_PI4_ETHERRXER                       2
#define IOCON_RES24_PI3_ETHERCRS                        0

#define IOCON_RES25_AN6_PJ7_INT7                        14
#define IOCON_RES25_AN7_PJ6_INT6                        12
#define IOCON_RES25_AN5_PJ5_INT5                        10
#define IOCON_RES25_AN8_PJ4                             8
#define IOCON_RES25_AN2_PJ3                             6
#define IOCON_RES25_AN9_PJ2                             4
#define IOCON_RES25_AN4_PJ1                             2
#define IOCON_RES25_AN3_PJ0                             0

 
/***********************************************************************
#define IOCON_RES * IOCON Multiplexing Register Bit Field macros
 *
 **********************************************************************/
#define IOCON_MUX1_ETHERCOL             _SBF(8,1)
#define IOCON_MUX1_PI2                  _SBF(8,0)
#define IOCON_MUX1_ETHERMDIO            _SBF(6,1)
#define IOCON_MUX1_PI1                  _SBF(6,0)
#define IOCON_MUX1_ETHERMDC             _SBF(4,1)
#define IOCON_MUX1_PI0                  _SBF(4,0)
#define IOCON_MUX1_LCDVD15              _SBF(2,1)
#define IOCON_MUX1_PL1                  _SBF(2,0)
#define IOCON_MUX1_LCDVD14              _SBF(0,1)
#define IOCON_MUX1_PL0                  _SBF(0,0)

#define IOCON_MUX3_CTCLK                _SBF(0,0)
#define IOCON_MUX3_INT4                 _SBF(0,1)
#define IOCON_MUX3_BATCNTL              _SBF(0,2)

#define IOCON_MUX4_PA7                  _SBF(10,0)
#define IOCON_MUX4_CTCAP2B              _SBF(10,1)
#define IOCON_MUX4_CTCMP2B              _SBF(10,2)
#define IOCON_MUX4_SCL                  _SBF(10,3)
#define IOCON_MUX4_PA6                  _SBF(8,0)
#define IOCON_MUX4_CTCAP2A              _SBF(8,1)
#define IOCON_MUX4_CTCMP2A              _SBF(8,2)
#define IOCON_MUX4_SDA                  _SBF(8,3)
#define IOCON_MUX4_PA5                  _SBF(6,0)
#define IOCON_MUX4_CTCAP1B              _SBF(6,1)
#define IOCON_MUX4_CTCMP1B              _SBF(6,2)
#define IOCON_MUX4_PA4                  _SBF(4,0)
#define IOCON_MUX4_CTCAP1A              _SBF(4,1)
#define IOCON_MUX4_CTCMP1A              _SBF(4,2)
#define IOCON_MUX4_PA3                  _SBF(2,0)
#define IOCON_MUX4_CTCAP0B              _SBF(2,1)
#define IOCON_MUX4_CTCMP0B              _SBF(2,2)
#define IOCON_MUX4_PA2                  _SBF(0,0)
#define IOCON_MUX4_CTCAP0A              _SBF(0,1)
#define IOCON_MUX4_CTCMP0A              _SBF(0,2)

#define IOCON_MUX5_PA1                  _SBF(14,0)
#define IOCON_MUX5_INT3                 _SBF(14,1)
#define IOCON_MUX5_UARTTX2              _SBF(14,2)
#define IOCON_MUX5_UARTIRTX2            _SBF(14,3)
#define IOCON_MUX5_PA0                  _SBF(12,0)
#define IOCON_MUX5_INT2                 _SBF(12,1)
#define IOCON_MUX5_UARTRX2              _SBF(12,2)
#define IOCON_MUX5_UARTIRRX2            _SBF(12,3)
#define IOCON_MUX5_PB7                  _SBF(10,0)
#define IOCON_MUX5_INT1                 _SBF(10,1)
#define IOCON_MUX5_UARTTX0              _SBF(10,2)
#define IOCON_MUX5_UARTIRTX0            _SBF(10,3)
#define IOCON_MUX5_PB6                  _SBF(8,0)
#define IOCON_MUX5_INT0                 _SBF(8,1)
#define IOCON_MUX5_UARTRX0              _SBF(8,2)
#define IOCON_MUX5_UARTIRRX0            _SBF(8,3)
#define IOCON_MUX5_PB5                  _SBF(6,0)
#define IOCON_MUX5_SSPTX_I2STXD         _SBF(6,1)
#define IOCON_MUX5_UARTTX1              _SBF(6,2)
#define IOCON_MUX5_UARTIRTX1            _SBF(6,3)
#define IOCON_MUX5_PB4                  _SBF(4,0)
#define IOCON_MUX5_SSPRX_I2STXD         _SBF(4,1)
#define IOCON_MUX5_UARTRX1              _SBF(4,2)
#define IOCON_MUX5_UARTIRRX1            _SBF(4,3)
#define IOCON_MUX5_PB3                  _SBF(2,0)
#define IOCON_MUX5_SSPCLK_I2SLCK        _SBF(2,1)
#define IOCON_MUX5_PB2                  _SBF(0,0)
#define IOCON_MUX5_SSPFRM_I2SWS         _SBF(0,1)

#define IOCON_MUX6_PB1                  _SBF(2,0)
#define IOCON_MUX6_DREQ                 _SBF(2,1)
#define IOCON_MUX6_UARTRTS0             _SBF(2,2)
#define IOCON_MUX6_PB0                  _SBF(0,0)
#define IOCON_MUX6_DACK                 _SBF(0,1)
#define IOCON_MUX6_UARTCTS0             _SBF(0,2)

#define IOCON_MUX7_PC7                  _SBF(14,0)
#define IOCON_MUX7_A23                  _SBF(14,1)
#define IOCON_MUX7_nFRE                 _SBF(14,2)
#define IOCON_MUX7_PC6                  _SBF(12,0)
#define IOCON_MUX7_A22                  _SBF(12,1)
#define IOCON_MUX7_FWE                  _SBF(12,2)
#define IOCON_MUX7_PC5                  _SBF(10,0)
#define IOCON_MUX7_A21                  _SBF(10,1)
#define IOCON_MUX7_PC4                  _SBF(8,0)
#define IOCON_MUX7_A20                  _SBF(8,1)
#define IOCON_MUX7_PC3                  _SBF(6,0)
#define IOCON_MUX7_A19                  _SBF(6,1)
#define IOCON_MUX7_PC2                  _SBF(4,0)
#define IOCON_MUX7_A18                  _SBF(4,1)
#define IOCON_MUX7_PC1                  _SBF(2,0)
#define IOCON_MUX7_A17                  _SBF(2,1)
#define IOCON_MUX7_PC0                  _SBF(0,0)
#define IOCON_MUX7_A16                  _SBF(0,1)

#define IOCON_MUX10_PN3                 _SBF(14,0)
#define IOCON_MUX10_D25                 _SBF(14,1)
#define IOCON_MUX10_PN2                 _SBF(12,0)
#define IOCON_MUX10_D24                 _SBF(12,1)
#define IOCON_MUX10_PD7                 _SBF(10,0)
#define IOCON_MUX10_D15                 _SBF(10,1)
#define IOCON_MUX10_PK7                 _SBF(8,0)
#define IOCON_MUX10_D23                 _SBF(8,1)
#define IOCON_MUX10_PD6                 _SBF(6,0)
#define IOCON_MUX10_D14                 _SBF(6,1)
#define IOCON_MUX10_PK6                 _SBF(4,0)
#define IOCON_MUX10_D22                 _SBF(4,1)
#define IOCON_MUX10_PD5                 _SBF(2,0)
#define IOCON_MUX10_D13                 _SBF(2,1)
#define IOCON_MUX10_PK5                 _SBF(0,0)
#define IOCON_MUX10_D21                 _SBF(0,1)

#define IOCON_MUX11_PD4                 _SBF(14,0)
#define IOCON_MUX11_D12                 _SBF(14,1)
#define IOCON_MUX11_PK4                 _SBF(12,0)
#define IOCON_MUX11_D20                 _SBF(12,1)
#define IOCON_MUX11_PD3                 _SBF(10,0)
#define IOCON_MUX11_D11                 _SBF(10,1)
#define IOCON_MUX11_PK3                 _SBF(8,0)
#define IOCON_MUX11_D19                 _SBF(8,1)
#define IOCON_MUX11_PD2                 _SBF(6,0)
#define IOCON_MUX11_D10                 _SBF(6,1)
#define IOCON_MUX11_PK2                 _SBF(4,0)
#define IOCON_MUX11_D18                 _SBF(4,1)
#define IOCON_MUX11_PK1                 _SBF(2,0)
#define IOCON_MUX11_D17                 _SBF(2,1)
#define IOCON_MUX11_PD1                 _SBF(0,0)
#define IOCON_MUX11_D9                  _SBF(0,1)

#define IOCON_MUX12_PK0                 _SBF(14,0)
#define IOCON_MUX12_D16                 _SBF(14,1)
#define IOCON_MUX12_PD0                 _SBF(12,0)
#define IOCON_MUX12_D8                  _SBF(12,1)

#define IOCON_MUX14_CS3                 _SBF(14,0)
#define IOCON_MUX14_PM3                 _SBF(14,1)
#define IOCON_MUX14_CS2                 _SBF(12,0)
#define IOCON_MUX14_PM2                 _SBF(12,1)
#define IOCON_MUX14_CS1                 _SBF(10,0)
#define IOCON_MUX14_PM1                 _SBF(10,1)
#define IOCON_MUX14_CS0                 _SBF(8,0)
#define IOCON_MUX14_PM0                 _SBF(8,1)
#define IOCON_MUX14_BLE3                _SBF(4,0)
#define IOCON_MUX14_PM7                 _SBF(4,1)
#define IOCON_MUX14_BLE2                _SBF(2,0)
#define IOCON_MUX14_PM6                 _SBF(2,1)
#define IOCON_MUX14_BLE1                _SBF(0,0)
#define IOCON_MUX14_PM5                 _SBF(0,1)

#define IOCON_MUX15_BLE0                _SBF(0,0)
#define IOCON_MUX15_PM4                 _SBF(0,1)

#define IOCON_MUX19_PE7                 _SBF(14,0)
#define IOCON_MUX19_WAIT                _SBF(14,1)
#define IOCON_MUX19_DEOT                _SBF(14,2)
#define IOCON_MUX19_PE6                 _SBF(12,0)
#define IOCON_MUX19_LCDVEEN             _SBF(12,1)
#define IOCON_MUX19_LCDMOD              _SBF(12,2)
#define IOCON_MUX19_PL7                 _SBF(10,0)
#define IOCON_MUX19_D31                 _SBF(10,1)
#define IOCON_MUX19_PE5                 _SBF(8,0)
#define IOCON_MUX19_LCDVDDEN            _SBF(8,1)
#define IOCON_MUX19_PL6                 _SBF(6,0)
#define IOCON_MUX19_D30                 _SBF(6,1)
#define IOCON_MUX19_PE4                 _SBF(4,0)
#define IOCON_MUX19_LCDSPLEN            _SBF(4,1)
#define IOCON_MUX19_LCDREV              _SBF(4,2)
#define IOCON_MUX19_PE3                 _SBF(2,0)
#define IOCON_MUX19_LCDCLS              _SBF(2,1)
#define IOCON_MUX19_PL5                 _SBF(0,0)
#define IOCON_MUX19_D29                 _SBF(0,1)

#define IOCON_MUX20_PE2                 _SBF(14,0)
#define IOCON_MUX20_LCDPS               _SBF(14,1)
#define IOCON_MUX20_PL4                 _SBF(12,0)
#define IOCON_MUX20_D28                 _SBF(12,1)
#define IOCON_MUX20_PE1                 _SBF(10,0)
#define IOCON_MUX20_LCDDCLK             _SBF(10,1)
#define IOCON_MUX20_PN1                 _SBF(8,0)
#define IOCON_MUX20_D27                 _SBF(8,1)
#define IOCON_MUX20_PE0                 _SBF(6,0)
#define IOCON_MUX20_LCDLP               _SBF(6,1)
#define IOCON_MUX20_LCDHRLP             _SBF(6,2)
#define IOCON_MUX20_PN0                 _SBF(4,0)
#define IOCON_MUX20_D26                 _SBF(4,1)
#define IOCON_MUX20_PF7                 _SBF(2,0)
#define IOCON_MUX20_LCDFP               _SBF(2,1)
#define IOCON_MUX20_LCDSPS              _SBF(2,2)
#define IOCON_MUX20_PF6                 _SBF(0,0)
#define IOCON_MUX20_LCDEN               _SBF(0,1)
#define IOCON_MUX20_LCDSPL              _SBF(0,2)

#define IOCON_MUX21_PF5                 _SBF(10,0)
#define IOCON_MUX21_LCDVD11             _SBF(10,1)
#define IOCON_MUX21_PL3                 _SBF(8,0)
#define IOCON_MUX21_LCDVD13             _SBF(8,1)
#define IOCON_MUX21_PF4                 _SBF(6,0)
#define IOCON_MUX21_LCDVD10             _SBF(6,1)
#define IOCON_MUX21_PL2                 _SBF(4,0)
#define IOCON_MUX21_LCDVD12             _SBF(4,1)
#define IOCON_MUX21_PF3                 _SBF(2,0)
#define IOCON_MUX21_LCDVD9              _SBF(2,1)
#define IOCON_MUX21_PF2                 _SBF(0,0)
#define IOCON_MUX21_LCDVD8              _SBF(0,1)

#define IOCON_MUX22_PF1                 _SBF(14,0)
#define IOCON_MUX22_LCDVD7              _SBF(14,1)
#define IOCON_MUX22_PF0                 _SBF(12,0)
#define IOCON_MUX22_LCDVD6              _SBF(12,1)
#define IOCON_MUX22_PG7                 _SBF(10,0)
#define IOCON_MUX22_LCDVD5              _SBF(10,1)
#define IOCON_MUX22_PG6                 _SBF(8,0)
#define IOCON_MUX22_LCDVD4              _SBF(8,1)
#define IOCON_MUX22_PG5                 _SBF(6,0)
#define IOCON_MUX22_LCDVD3              _SBF(6,1)
#define IOCON_MUX22_PG4                 _SBF(4,0)
#define IOCON_MUX22_LCDVD2              _SBF(4,1)
#define IOCON_MUX22_PG3                 _SBF(2,0)
#define IOCON_MUX22_LCDVD1              _SBF(2,1)
#define IOCON_MUX22_PG2                 _SBF(0,0)
#define IOCON_MUX22_LCDVD0              _SBF(0,1)

#define IOCON_MUX23_PG1                 _SBF(14,0)
#define IOCON_MUX23_ETHERTXCLK          _SBF(14,1)
#define IOCON_MUX23_PG0                 _SBF(12,0)
#define IOCON_MUX23_ETHERTXEN           _SBF(12,1)
#define IOCON_MUX23_PH7                 _SBF(10,0)
#define IOCON_MUX23_ETHERTX3            _SBF(10,1)
#define IOCON_MUX23_PH6                 _SBF(8,0)
#define IOCON_MUX23_ETHERTX2            _SBF(8,1)
#define IOCON_MUX23_PH5                 _SBF(6,0)
#define IOCON_MUX23_ETHERTX1            _SBF(6,1)
#define IOCON_MUX23_PH4                 _SBF(4,0)
#define IOCON_MUX23_ETHERTX0            _SBF(4,1)
#define IOCON_MUX23_PH3                 _SBF(2,0)
#define IOCON_MUX23_ETHERTXER           _SBF(2,1)
#define IOCON_MUX23_PH2                 _SBF(0,0)
#define IOCON_MUX23_ETHERRXCLK          _SBF(0,1)


#define IOCON_MUX24_PH1                 _SBF(12,0)
#define IOCON_MUX24_ETHERRXDV           _SBF(12,1)
#define IOCON_MUX24_PH0                 _SBF(10,0)
#define IOCON_MUX24_ETHERRX3            _SBF(10,1)
#define IOCON_MUX24_PI7                 _SBF(8,0)
#define IOCON_MUX24_ETHERRX2            _SBF(8,1)
#define IOCON_MUX24_PI6                 _SBF(6,0)
#define IOCON_MUX24_ETHERRX1            _SBF(6,1)
#define IOCON_MUX24_PI5                 _SBF(4,0)
#define IOCON_MUX24_ETHERRX0            _SBF(4,1)
#define IOCON_MUX24_PI4                 _SBF(2,0)
#define IOCON_MUX24_ETHERRXER           _SBF(2,1)
#define IOCON_MUX24_PI3                 _SBF(0,0)
#define IOCON_MUX24_ETHERCRS            _SBF(0,1)

#define IOCON_MUX25_AN6                 _SBF(14,0)
#define IOCON_MUX25_PJ7                 _SBF(14,1)
#define IOCON_MUX25_INT7                _SBF(14,2)
#define IOCON_MUX25_AN7                 _SBF(12,0)
#define IOCON_MUX25_PJ6                 _SBF(12,1)
#define IOCON_MUX25_INT6                _SBF(12,2)
#define IOCON_MUX25_AN5                 _SBF(10,0)
#define IOCON_MUX25_PJ5                 _SBF(10,1)
#define IOCON_MUX25_INT5                _SBF(10,2)
#define IOCON_MUX25_AN8                 _SBF(8,0)
#define IOCON_MUX25_PJ4                 _SBF(8,1)
#define IOCON_MUX25_AN2_LL              _SBF(6,0)
#define IOCON_MUX25_PJ3                 _SBF(6,1)
#define IOCON_MUX25_AN9                 _SBF(4,0)
#define IOCON_MUX25_PJ2                 _SBF(4,1)
#define IOCON_MUX25_AN4_WIPER           _SBF(2,0)
#define IOCON_MUX25_PJ1                 _SBF(2,1)
#define IOCON_MUX25_AN3_LR              _SBF(0,0)
#define IOCON_MUX25_PJ0                 _SBF(0,1)
    
/* Macro pointing to IOCON registers */
#define IOCON    ((IOCON_REGS_T *)(IOCON_BASE))

#endif /* LH79524_IOCON_H */ 

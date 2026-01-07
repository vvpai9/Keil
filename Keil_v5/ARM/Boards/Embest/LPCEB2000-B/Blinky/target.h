#ifndef	LPC_target_H
#define	LPC_target_H

#include  "lpc22XX.h"
#include  "lpc_type.h"
/**********************************************************************************************
*File:		target.h
*Author:	Embest w.h.xie	2005.02.05
*Desc:		cortrol define
*History:	
*		
*comment:
**********************************************************************************************/

#ifdef	LPCEB2000_I
	#define		LED_BIT_1		P10								// 1st LED cortrol
	#define		LED_BIT_2		P11								// 2nd LED cortrol
	#define		LED_BIT_3		P12								// 3rd LED cortrol
	#define		LED_BIT_4		P13								// 4th LED cortrol
	#define		LED_BIT_5		P14								// 5th LED cortrol
	#define		LED_BIT_6		P15								// 6th LED cortrol
	#define		LED_BIT_7		P16								// 7th LED cortrol
	#define		LED_BIT_8		P17								// 8th LED cortrol
	#define		LED_BIT_CON		P19								// cs  LED cortrol

	#define		LED_SEG_A		P17								// A SEG cortrol
	#define		LED_SEG_B		P15								// B SEG cortrol
	#define		LED_SEG_C		P13								// C SEG cortrol
	#define		LED_SEG_D		P11								// D SEG cortrol
	#define		LED_SEG_E		P10								// E SEG cortrol
	#define		LED_SEG_F		P16								// F SEG cortrol
	#define		LED_SEG_G		P14								// G SEG cortrol
	#define		LED_SEG_DP		P12								// DP SEG cortrol
	#define		LED_SEG_CON		P18								// SEG cortrol
	#define		LED_OUT_CON		(P10 | P11 | P12 | P13 | P14 | P15 | P16 | P17)
	
	#define		LED_CON			P29								// LED show cortrol
	#define		UART1_CON		P22								// UART1 cortrol
	#define		BEEP_CON		P7								// beep  cortrol
	#define		SPI_CON			P20								// 595 cs
	#define		KEY_ROW			0x00F00000						// key row
	#define		KEY_ROW0		P20								// row0  cortrol
	#define		KEY_ROW1		P21								// row1  cortrol
	#define		KEY_ROW2		P22								// row2  cortrol
	#define		KEY_ROW3		P23								// row3  cortrol

	const		uint32		lKeyRow[4] = { KEY_ROW0, KEY_ROW1 ,KEY_ROW2, KEY_ROW3 };
	#define		KEY_COL			0x000F0000						// col   cortrol

	#define		PLL_VPBDIV		0x00							// VPB = 1/4 CCLK
	#define		PLL_CFG			0x23							// 4 multiple 
	#define		MAM_TIM			0x03							// read code 2 clock
	

	#define		LED_CHAR_0	LED_SEG_A + LED_SEG_B + LED_SEG_C + LED_SEG_D + LED_SEG_E + LED_SEG_F
																//0
	#define		LED_CHAR_1	LED_SEG_B + LED_SEG_C
																//1
	#define		LED_CHAR_2	LED_SEG_A + LED_SEG_B + LED_SEG_D + LED_SEG_E + LED_SEG_G
																//2
	#define		LED_CHAR_3	LED_SEG_A + LED_SEG_B + LED_SEG_C + LED_SEG_D + LED_SEG_G
																//3
	#define		LED_CHAR_4	LED_SEG_B + LED_SEG_C + LED_SEG_F + LED_SEG_G 
																//4
	#define		LED_CHAR_5	LED_SEG_A + LED_SEG_C + LED_SEG_D + LED_SEG_F + LED_SEG_G
																//5
	#define		LED_CHAR_6	LED_SEG_A + LED_SEG_C + LED_SEG_D + LED_SEG_E + LED_SEG_F + LED_SEG_G
																//6
	#define		LED_CHAR_7	LED_SEG_A + LED_SEG_B + LED_SEG_C
																//7	 
	#define		LED_CHAR_8	LED_SEG_A + LED_SEG_B + LED_SEG_C + LED_SEG_D + LED_SEG_E+LED_SEG_F+LED_SEG_G
																//8
	#define		LED_CHAR_9	LED_SEG_A + LED_SEG_B + LED_SEG_C + LED_SEG_D + LED_SEG_F + LED_SEG_G
																//9
	#define		LED_CHAR_A	LED_SEG_A + LED_SEG_B + LED_SEG_C + LED_SEG_E + LED_SEG_F + LED_SEG_G
																//A
	#define		LED_CHAR_B	LED_SEG_C + LED_SEG_D + LED_SEG_E + LED_SEG_F + LED_SEG_G
																//B
	#define		LED_CHAR_C	LED_SEG_A + LED_SEG_D + LED_SEG_E + LED_SEG_F
																//C
	#define		LED_CHAR_D	LED_SEG_B + LED_SEG_C + LED_SEG_D + LED_SEG_E + LED_SEG_G
																//D
	#define		LED_CHAR_E	LED_SEG_A + LED_SEG_D + LED_SEG_E + LED_SEG_F + LED_SEG_G
																//E
	#define		LED_CHAR_F	LED_SEG_A + LED_SEG_E + LED_SEG_F + LED_SEG_G
																//F
	#define		LED_DEC	  LED_SEG_G
																//-

	  
  #endif 

  #endif 





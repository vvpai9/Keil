/******************** (C) COPYRIGHT 2005 STMicroelectronics ********************
* File Name          : buzzer.h
* Author             : MCD Application Team
* Date First Issued  : 09/27/2005 :  V1.0
* Description        : Header for the buzzer.c file.
********************************************************************************
* History:
* 09/27/2005 :  V1.0
********************************************************************************
 THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS WITH
 CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
 AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
 OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __BUZZER_H
#define __BUZZER_H

/* Standard include ----------------------------------------------------------*/
#include "73x_lib.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define o1 1
#define o2 2
#define o3 3
#define cut 136

#define Tempo225  2250
#define Tempo200  2000
#define Tempo180  1800
#define Tempo160  1600
#define Tempo140  1400
#define Tempo125  1250
#define Tempo112  1120
#define Tempo100  1000
#define Tempo90   900
#define Tempo80   800
#define Tempo70   700
#define Tempo50   500

#define _qq  64
#define _oq  32
#define _sq  16
#define _q   8
#define _qp  (16/3)
#define _c   4
#define _cp  (8/3)
#define _m   2
#define _sb  1
#define _b   (1/2)

/* Module private variables --------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define Do(o)  (30532 >> (o)) //0x7744
#define Dod(o) (28818 >> (o)) //0x7092
#define Re(o)  (27201 >> (o)) //0x6A41
#define Mib(o) (25674 >> (o)) //0x644A
#define Mi(o)  (24233 >> (o)) //0x5EA9
#define Fa(o)  (22873 >> (o)) //0x5959
#define Fad(o) (21589 >> (o)) //0x5455
#define Sol(o) (20378 >> (o)) //0x4F9A
#define Sod(o) (19234 >> (o)) //0x4B22
#define La(o)  (18154 >> (o)) //0x46EA
#define Sib(o) (17136 >> (o)) //0x42F0
#define Si(o)  (16174 >> (o)) //0x3F2E

#define split(data) (((data) >> 8) & 0xFF), ((data) & 0xFF)
#define _Do(o)  split(Do(o))
#define _Dod(o) split(Dod(o))
#define _Re(o)  split(Re(o))
#define _Mib(o) split(Mib(o))
#define _Mi(o)  split(Mi(o))
#define _Fa(o)  split(Fa(o))
#define _Fad(o) split(Fad(o))
#define _Sol(o) split(Sol(o))
#define _Sod(o) split(Sod(o))
#define _La(o)  split(La(o))
#define _Sib(o) split(Sib(o))
#define _Si(o)  split(Si(o))
#define _cut    split(cut)

/* Private functions ---------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Melody_Init(void);
void StopMelody(void);
void SaveMusicAlarmToI2C(void);
void SaveAlarmMelodyToI2C(void);
void SaveMusicToSPI(void);
void SaveMelodyToSPI(void);
void Single(void);
void SingleRepeat(void);
void PlayNextTone(void);
void PlayMelody1(void);
void PlayMelody2(void);
void PlayMelody3(void);
void PlayAlarmMelody(void);
void TB_SetPeriodValue(TB_TypeDef *TBx, u16 Time);

#endif /* __BUZZER_H */

/******************* (C) COPYRIGHT 2005 STMicroelectronics *****END OF FILE****/



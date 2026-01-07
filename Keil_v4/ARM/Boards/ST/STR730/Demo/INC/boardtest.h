/******************** (C) COPYRIGHT 2005 STMicroelectronics ********************
* File Name          : boardtest.h
* Author             : MCD Application Team
* Date First Issued  : 09/27/2005 :  V1.0
* Description        : Header for the boardtest.c file.
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
#ifndef __BOARDTEST_H
#define __BOARDTEST_H

/* Includes ------------------------------------------------------------------*/
#include "73x_lib.h"

/* Exported types ------------------------------------------------------------*/
typedef u8* string;
typedef enum { FAIL = 0, PASS = !FAIL } TestStatus;

/* Exported constants --------------------------------------------------------*/
#define NEXTmsg             "  Press ^NEXT^  "
#define SELmsg              "  Press ^SEL^   "
#define PREVmsg             "  Press ^PREV^  "
#define BACKmsg             "  Press ^BACK^  "
#define WAKEUPmsg           "Press ^WAKE-UP^ "
#define Passmsg             " ^SEL^ : Passed "
#define Failmsg             " ^BACK^: Failed "
#define Passedmsg           "***Passed***"
#define Failedmsg           "!!!Failed!!!"
#define TestFailedmsg       "Test failed "
#define Overalltestmsg      "  Overall test  "
#define Bordtestnotdonemsg  " Board test not   done yet!!!!  "

/* Module private variables --------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
TestStatus PushButtonsTest(void);
TestStatus RedLedsTest(void);
TestStatus PWMLedsTest(void);
TestStatus LM35Test(void);
TestStatus VarResistTest(void);
TestStatus Buzzer12Test(void);
TestStatus Buzzer23Test(void);
TestStatus UARTTest(void);
TestStatus I2CTest(void);
TestStatus BSPITest(void);
void BoardTest(void);
void TestReport(void);
TestStatus msgcmp(u8* Tx_msg, u8* Rx_msg, u16 msglength);
TestStatus IsTestOk(void);

#endif /* __BOARDTEST_H */

/******************* (C) COPYRIGHT 2005 STMicroelectronics *****END OF FILE****/

/*
 * Copyright 2006, ZiLOG Inc.
 * All Rights Reserved
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of ZiLOG Inc., and might
 * contain proprietary, confidential and trade secret information of
 * ZiLOG, our partners and parties from which this code has been licensed.
 * 
 * The contents of this file may not be disclosed to third parties, copied or
 * duplicated in any form, in whole or in part, without the prior written
 * permission of ZiLOG Inc.
 */
#ifndef _ZA9_SEC_H_
#define _ZA9_SEC_H_

#include "za9_defines.h"



/*
 * SEC Registers
 */
#define SEC_CFG1_REG      		  			(SEC_BASE | 0x00)
#define SEC_CFG2_REG      		  			(SEC_BASE | 0x04)
#define SEC_CTRL_REG      		  			(SEC_BASE | 0x08)
#define SEC_STA_REG      		  			(SEC_BASE | 0x0C)
#define SEC_DSBL_REG      		  			(SEC_BASE | 0x10)
#define SEC_LOGSTAMP1_REG              (SEC_BASE | 0x14)
#define SEC_LCK1_REG      		  			(SEC_BASE | 0x0694)
#define SEC_LCK2_REG      		  			(SEC_BASE | 0x0968)

#define SEC_SRAM_SIZE_BYTES				4096

 

/*
 * SEC_CFG1_REG bit definitions
 */
#define SEC_ENRC_TIME_20               0
#define SEC_ENRC_TIME_40               1
#define SEC_ENRC_TIME_60               2
#define SEC_ENRC_TIME_80               3
#define SEC_ENRC_TIME_100              4
#define SEC_ENRC_TIME_120              5
#define SEC_ENRC_TIME_140              6
#define SEC_ENRC_TIME_160              7

#define SEC_ENRC_DELAY_MASK            (BIT27 | BIT26 | BIT25)
#define SEC_ENRC_DELAY_SHIFT           25

#define SEC_CHRG_TIME_20  					0
#define SEC_CHRG_TIME_40  					1
#define SEC_CHRG_TIME_80               2
#define SEC_CHRG_TIME_160  				3
#define SEC_CHRG_TIME_320  				4
#define SEC_CHRG_TIME_640              5
#define SEC_CHRG_TIME_960              6

#define SEC_SW_CHRG_TIME_MASK			   (BIT24 | BIT23 | BIT22)
#define SEC_SW_CHRG_TIME_SHIFT			22
#define SEC_WIRE_CHRG_TIME_MASK			(BIT18 | BIT17 | BIT16)
#define SEC_WIRE_CHRG_TIME_SHIFT			16

#define SEC_ISRC_WIRE_DISABLE          BIT14
#define SEC_ISRC_WIRE_ENABLE           0

#define SEC_RES_THRESH_DISABLED			0
#define SEC_RES_THRESH_85 					1
#define SEC_RES_THRESH_100					2
#define SEC_RES_THRESH_150					3

#define SEC_SW_OVER_THRESH_MASK			(BIT13 | BIT12)
#define SEC_SW_OVER_THRESH_SHIFT			12
#define SEC_WIRE_OVER_THRESH_MASK		(BIT11 | BIT10)
#define SEC_WIRE_OVER_THRESH_SHIFT		10
#define SEC_SW_UNDER_THRESH_MASK			(BIT9 | BIT8)
#define SEC_SW_UNDER_THRESH_SHIFT		8
#define SEC_WIRE_UNDER_THRESH_MASK		(BIT7 | BIT6)
#define SEC_WIRE_UNDER_THRESH_SHIFT		6


#define SEC_TEMP_OVER_85               (6 << 3)
#define SEC_TEMP_OVER_90               (5 << 3)
#define SEC_TEMP_OVER_95               (4 << 3)
#define SEC_TEMP_OVER_100              (3 << 3)
#define SEC_TEMP_OVER_105              (2 << 3)

#define SEC_OVER_TEMP_THRESH_MASK		(BIT5 | BIT4 | BIT3)


#define SEC_TEMP_UNDER_n20             6
#define SEC_TEMP_UNDER_n25             5
#define SEC_TEMP_UNDER_n30             4

#define SEC_UNDER_TEMP_THRESH_MASK		(BIT2 | BIT1 | BIT0)




/*
 * SEC_CFG2_REG bit definitions
 */
#define SEC_CCO_TRIM_MASK					(BIT31 | BIT30 | BIT29 | BIT28 | BIT27)
#define SEC_TEMP_TRIM_MASK					(BIT26 | BIT25 | BIT24)
#define SEC_IBG_TRIM_MASK					(BIT23 | BIT22 | BIT21 | BIT20)
#define SEC_VBG_TRIM_MASK					(BIT19 | BIT18 | BIT17 | BIT16)
#define SEC_BJT_TRIM_MASK					(BIT15 | BIT14 | BIT13 | BIT12)

#define SEC_DEBOUNCE_COUNT_0				0
#define SEC_DEBOUNCE_COUNT_1				1
#define SEC_DEBOUNCE_COUNT_2				2
#define SEC_DEBOUNCE_COUNT_3				3
#define SEC_DEBOUNCE_COUNT_4				4
#define SEC_DEBOUNCE_COUNT_5				5
#define SEC_DEBOUNCE_COUNT_6				6
#define SEC_DEBOUNCE_COUNT_DISABLE		7

#define SEC_TEMP_DEBOUNCE_MASK			(BIT11 | BIT10 | BIT9)
#define SEC_TEMP_DEBOUNCE_SHIFT			9
#define SEC_WIRE_DEBOUNCE_MASK			(BIT8 | BIT7 | BIT6)
#define SEC_WIRE_DEBOUNCE_SHIFT			6
#define SEC_SW_DEBOUNCE_MASK				(BIT5 | BIT4 | BIT3)
#define SEC_SW_DEBOUNCE_SHIFT				3

#define SEC_SAMP_PERIOD_28					0
#define SEC_SAMP_PERIOD_56					1
#define SEC_SAMP_PERIOD_112				2
#define SEC_SAMP_PERIOD_225				3
#define SEC_SAMP_PERIOD_450				4
#define SEC_SAMP_PERIOD_901				5
#define SEC_SAMP_PERIOD_1802				6
#define SEC_SAMP_PERIOD_3604				7
#define SEC_SAMP_PERIOD_MASK				(BIT2 | BIT1 | BIT0)


/*
 * SEC_CTRL_REG bit definitions
 */
#define SEC_CTRL_RTC_SEL               BIT22
#define SEC_CTRL_OV_POR_TRIM_MASK      (BIT21 | BIT20 | BIT19)
#define SEC_CTRL_UV_POR_TRIM_MASK      (BIT18 | BIT17 | BIT16)
#define SEC_CTRL_TE_DSBL					BIT3
#define SEC_CTRL_JTAG_DSBL					BIT2
#define SEC_CTRL_JTAG_ENBL					BIT1
#define SEC_CTRL_TAMP_FORC					BIT0


/*
 * SEC_STA_REG, SEC_LOGSTAMP1_REG bit definitions
 */
#define SEC_STA_APB_UNLK    				BIT31
#define SEC_STA_SW7_FLAG               BIT18
#define SEC_STA_SW6_FLAG               BIT17
#define SEC_STA_SW5_FLAG               BIT16
#define SEC_STA_SW4_FLAG               BIT15
#define SEC_STA_SW3_FLAG               BIT14
#define SEC_STA_SW2_FLAG               BIT13
#define SEC_STA_JTAG_FLAG    				BIT12
#define SEC_STA_WIRE_01_FLAG 				BIT11
#define SEC_STA_SW1_FLAG    				BIT10
#define SEC_STA_SW0_FLAG    				BIT9
#define SEC_STA_ILLGL_STATE_FLAG    	BIT8
#define SEC_STA_TAMP_FORC_FLAG    		BIT7
#define SEC_STA_MAIN_OVER_FLAG    		BIT6
#define SEC_STA_DVDD_UNDER_FLAG    		BIT5
#define SEC_STA_TEMP_OVER_FLAG    		BIT4
#define SEC_STA_TEMP_UNDER_FLAG    		BIT3
#define SEC_STA_BATT_OVER_FLAG    		BIT2
#define SEC_STA_BATT_UNDER_FLAG    		BIT1
#define SEC_STA_GLBL_TMPR_FLAG			BIT0


/*
 * SEC_DSBL_REG bit definitions
 */
#define SEC_DSBL_SRAM_PWDN					BIT31
#define SEC_DSBL_MAIN_UNDER_RST			BIT29
#define SEC_DSBL_MAIN_OVER_RST			BIT22
#define SEC_DSBL_VBATT_OVER_RST			BIT18
#define SEC_DSBL_GLBL_RST					BIT16
#define SEC_DSBL_SW7                   BIT15
#define SEC_DSBL_SW6                   BIT14
#define SEC_DSBL_SW5                   BIT13
#define SEC_DSBL_SW4                   BIT12
#define SEC_DSBL_SW3                   BIT11
#define SEC_DSBL_SW2                   BIT10
#define SEC_DSBL_SW1                   BIT9
#define SEC_DSBL_SW0                   BIT8
#define SEC_DSBL_MAIN_OVER_ALRM			BIT6
#define SEC_DSBL_DVDD_UNDER_ALRM			BIT5
#define SEC_DSBL_VBATT_OVER_ALRM			BIT2


/*
 * SEC_LCK1_REG bit definitions
 */
#define SEC_UNLOCK1							0x89ABCDEF


/*
 * SEC_LCK2_REG bit definitions
 */
#define SEC_UNLOCK2							0x76543210



#endif


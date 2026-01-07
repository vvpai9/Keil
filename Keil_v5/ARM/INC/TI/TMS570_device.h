/**********************************************************DMA***********************************************************************/
#define  DMA 	 		0xFFFFF000                                /*DMA Address*/
#define  DMA_RAM 		0xFFF80000                                /*DMA RAM Address*/
#define  DMA_FTC_INT 	33                                                /*Frame Transfer Complete Intr*/
#define  DMA_LFS_INT 	34                                                /*Last Frame Transfer Started Intr*/
#define  DMA_HBC_INT 	39                                                /*First Half of Block Complete Intr*/
#define  DMA_BTC_INT 	40                                                /*Block Transfer Complete Intr*/
#define  DMA_BER_INT 	41                                                /*Bus Error Intr*/
#define  NUM_DMA_REQUESTS_32                                              /*Total Number Of Peripheral DMA Requests*/
#define  DMA_CNTL_PKTS 16                                                 /*DMA Control Packets*/
#define  DMA_RAM_INIT 1							  /*DMA Memory Initialization Channel*/
#define BER_ERROR_ADDR	0x1B00C300					  //0x0401FFF0
#define BMM_SLAVE_ADDR	0xff460000                                       




/********************************************************RTI***********************************************************************/
#define  NUM_RTI1_COMP0_INT 2                                            /*Interrupt Channel For Compare 0*/
#define  NUM_RTI1_COMP1_INT 3                                            /*Interrupt Channel For Compare 1*/
#define  NUM_RTI1_COMP2_INT 4                                            /*Interrupt Channel For Compare 2*/
#define  NUM_RTI1_COMP3_INT 5                                            /*Interrupt Channel For Compare 3*/
#define  NUM_RTI1_OVL0_INT  6                                            /*Interrupt Channel For FRC0*/
#define  NUM_RTI1_OVL1_INT  7                                            /*Interrupt Channel For FRC1*/
#define  NUM_RTI1_TBASE_INT 8                                            /*Timebase Interrupt Channel*/
#define  NUM_RTI1_DMA_REQ0  12                                           /*DMAREQ number for Compare 0*/
#define  NUM_RTI1_DMA_REQ1  13                                           /*DMAREQ number for Compare 1*/
#define  NUM_RTI1_DMA_REQ2  18                                           /*DMAREQ number for Compare 2*/
#define  NUM_RTI1_DMA_REQ3  19                                           /*DMAREQ number for Compare 3*/


#define SOURCEADDRESS  		0x00002000				 /* Source Address for Transfer data */
#define DESTINATIONADDRESS 	0x00002500				 /* Destination Addresss for transfer data */

#define RAM_DMA_CH       3						 /* DMA Channel No */


/*******************************************************FLASH************************************************************************/
#define FLASH             	0xFFF87000				/* Starting Address for FLASH */				
#define FLASH_VOlTAGE      	0xFFF87000
#define FLASH_CMD          	0xFFF87000

#define ESM_Mapping							/* Flash errors are being mapped to ESM */
#define FWM_ECC_INTERNAL    						/* Antares has internal ECC i.e R4 has ECC enabled */

									/* channnel used by DMA in order to read flash */
#define DOUBLE_ERROR_INT 1 						/* this is required to make test backward compatible */

#define FLASH_ERROR2 0 							/* This is required in order to make the testcases backward compatible */
#define FLASH_ERROR1 -1

#define Bank_busy 0xF0 							/* Register reset values - only 4 banks are available */
#define FWM_REV_ID 0x1467
#define FIQnIRQ 1

/* Since in Antares the number of sectors is more we are using Bank's starting & ending address */

#define MAX_SEC 10

/* Bank zero */
#define Bzero_SecOpt_start 0x8000000
#define Bzero_SecOpt_End   0x8008000

/* Bank one */
#define Bzero_SecZero_start 0x8008000
#define Bzero_SecZero_End   0x8010000

/* Bank two */
#define Bzero_SecOne_start 0x8010000
#define Bzero_SecOne_End   0x8018000

/* Bank three */
#define Bzero_SecTwo_start 0x8018000
#define Bzero_SecTwo_End   0x801A000

#define Bzero_SecThree_start 0x801A000
#define Bzero_SecThree_End   0x801C000

#define Bzero_SecFour_start 0x801C000
#define Bzero_SecFour_End   0x8020000

#define Bzero_SecFive_start 0x8020000
#define Bzero_SecFive_End   0x8030000

#define Bzero_SecSix_start  0x8030000
#define Bzero_SecSix_End    0x8040000

#define Bzero_SecSeven_start 0x8040000
#define Bzero_SecSeven_End   0x8060000

#define Bzero_SecEight_start 0x8060000
#define Bzero_SecEight_End   0x8080000


/* Initializing the other constants of the test to zero - as they are not used */
 
#define Bzero_SecNine_start 0x00
#define Bzero_SecNine_End 0x00

#define data_int  0x88888888
#define data_sh   0x8888
#define data_char 0x88

#define FLASH_ILLEGAL	0x08200000
/**********************************************************************************************************************************/
/*	 					MODULE ADDRESS		   							  */
/**********************************************************************************************************************************/
/* This Adress is kept for Compilation	*/
#define Dummy_Address 		0xffffffff
#define MCRC             	0xFE000000
#define CORESIGHT_TPIU  	0xFFA03000
#define ETM_R4          	0xFFA02000 
#define CORTEX_R4       	0xFFA01000 
#define CORESIGHT_DBG_ROM       0xFFA00000 
#define PCR             	0xFFFFE000
#define SYSTEM          	0xFFFFFF00 
#define CPU_SLFTST      	0xFFFFE600 
#define DMA             	0xFFFFF000 
#define ESM             	0xFFFFF500 
#define CCMR4           	0xFFFFF600
#define DMM             	0xFFFFF700 
#define RAM_ECC_EVN     	0xFFFFF800 
#define RAM_ECC_ODD     	0xFFFFF900 
#define RTP             	0xFFFFFA00
#define RTI             	0xFFFFFC00
#define VIM             	0xFFFFFE00
#define MIBSPI1        		0xFFF7F400
#define MIBSPI3        		0xFFF7F800
#define MIBSPIP5        	0xFFF7FC00
#define LIN             	0xFFF7E400      /* LIN0 */
#define LIN1             	0xFFF7E500	/* LIN1 */
#define LIN2             	Dummy_Address   /* LIN2 */
#define LIN3             	Dummy_Address   /* LIN3 */
#define DCAN3            	0xFFF7E000
#define DCAN2            	0xFFF7DE00
#define DCAN1            	0xFFF7DC00
#define FRAY            	0xFFF7C800
#define FRAYTU          	0xFFF7A000
#define MIBADC1          	0xFFF7C000
#define MIBADC2          	0xFFF7C200
#define GIO1             	0xFFF7BC00
#define NHET             	0xFFF7B800
#define HTU             	0xFFF7A400



#define VIM_PARITY              0xFFFFFDEC      /*  The parity registers starts from offset 0xEC */

/****************************************************************************************************************/
/*				 MODULE RAM ADDDRESS						     		*/
/****************************************************************************************************************/
#define MIBSPIP5_RAM    	0xFF0A0000
#define MIBSPI3_RAM    		0xFF0C0000
#define MIBSPI1_RAM    		0xFF0E0000
#define DCAN3_RAM        	0xFF1A0000
#define DCAN2_RAM        	0xFF1C0000
#define DCAN1_RAM        	0xFF1E0000
#define MIBADC1_RAM      	0xFF3E0000
#define MIBADC2_RAM      	0xFF3A0000
#define NHET_RAM         	0xFF460000
#define HTU_RAM         	0xFF4E0000
#define VIM_RAM         	0xFFF82000
#define FRAYTU_RAM      	0xFF500000
#define DMA_RAM         	0xFFF80000
#define RTP_RAM_MEM        	0xFFF83000 


/*    For Device which has pheripheral    with parity   */
#define FRAYTU_PARITY 	 	YES
#define MIBSPIP1_PARITY  	YES
#define MIBSPIP3_PARITY	 	YES
#define MIBSPIP5_PARITY  	YES
#define FTU_PARITY		YES



/****************************************************************************************************************/
/*	                            VIM				                     	     			*/
/****************************************************************************************************************/
#define REG_COUNT			52
#define VIM_RAM_SIZE			64


#define VIM_RAM_PARITY			0xfff82400
#define VIM_PARITYBIT_SWIINT_LOC 	0xFFF82458

#define INTREQ 		0x3F3F3F3F           /* no of interrupt request channels */
#define CAPEVNTREQ  	0x003F003F 


/****************************************************************************************************************/
/*	 			VIM CHANNELS / INTERRUPT LINES					     		*/
/****************************************************************************************************************/
#define VIM_CHANNELS			64		/* No of Channels in VIM */ 
#define NO_NMI_RESV			 2 		/* No of revserved or NMI interrupts*/
#define PHANTOM_INT			-1 		// to be used in main as (PHANTOM_INT + 1)
							/* ESM LINES */
#define ESM_INT              		 0
#define ESM_LVL0_INT        		20
							/* RTI LINES */
#define RTI_COMP0_INT		 	 2
#define RTI_COMP1_INT		 	 3
#define RTI_COMP2_INT		 	 4 
#define RTI_COMP3_INT		 	 5 
#define RTI_OVL0_INT			 6 
#define RTI_OVL1_INT		 	 7
#define RTI_TBASE_INT        	 	 8
									/*GIO LINES*/
#define GIO1_LVL0_INT        		 9
#define GIO1_LVL1_INT       		23
									/*NHET LINES */
#define NHET_LVL0_INT       		10
#define NHET_LVL1_INT       		24
									/*HTU LINES*/
#define HTU_LVL0_INT        		11
#define HTU_LVL1_INT        		25
									/*MIBSPI #1*/
#define MIBSPI1_LVL0_INT    		12
#define MIBSPI1_LVL1_INT    		26
									/*MIBSPI #3*/		
#define MIBSPI3_LVL0_INT		37
#define MIBSPI3_LVL1_INT		38
									/*MIBSPI #5*/
#define MIBSPIP5_LVL0_INT		53
#define MIBSPIP5_LVL1_INT		56
									/*SPI # 1*/
#define SPI1_LVL0_INT    		12
#define SPI1_LVL1_INT      		26
									/*SPI # 3*/
#define SPI3_LVL0_INT			37                                     
#define SPI3_LVL1_INT			38				

#define SPI5_LVL0_INT			53                                     
#define SPI5_LVL1_INT			56				/*SPI # 5*/

#define RESERVED       			17
#define RESERVED1       		30
				
									/* LIN LINES*/
#define LIN_LVL0_INT        		13
#define LIN_LVL1_INT        		27

#define LIN1_LVL0_INT       		49
#define LIN1_LVL1_INT       		54

									/*ADM1 LINES*/
#define ADM1_EV_INT	   		14
#define ADM1_GP1_INT        		15
#define ADM1_MTCI_INT       		31
#define ADM1_GP2_INT        		28
									/*ADM2 LINES*/
#define ADM2_EV_INT	    		50
#define ADM2_GP1_INT        		51
#define ADM2_MTCI_INT       		59
#define ADM2_GP2_INT        		57
					
									/*DCAN LINES #1*/
#define DCAN1_LVL0_INT      		16
#define DCAN1_LVL1_INT      		29

									/*DCAN LINES #1*/
#define DCAN2_LVL0_INT			35
#define DCAN2_LVL1_INT			42

									/*DCAN LINES #1*/
#define DCAN3_LVL0_INT			45
#define DCAN3_LVL1_INT			55

									/*FLEXRAY LINES*/
//#define FRAY_T1C_INT			62
//#define FRAY_TOC_INT			52
//#define FRAY_LVL1_INT       		32
//#define FRAY_LVL0_INT       		18
	
									/*FLEXRAY TU LINES*/
//#define FRAY_TU_ERR_INT			58
//#define RESERVED3			61
//#define FRAY_TU_TRSFR_ST_INT 		48

									/* CRC LINES*/
#define CRC_LVL0_INT        		19

									/*SYSTEM */
#define SYS_SW_INT          		21
#define PMU_INT            		22


									/*DMM LINES*/
#define DMM_LVL0_INT			36
#define DMM_LVL1_INT			43



/*************************************************************************************************************************/
/*					RAM ADDRESS DEFINITIONS								 */ 				
/*************************************************************************************************************************/
								
#define RAM_BASE 0x00001100				/* RAM BASE ADDRESS */
#define ECC_BASE 0x00401103				/* ECC BASE ADDRESS */

#define ECC_INTERNAL					/* When ECC is calculated by CPU */


							/* BIT access Address */
#define DATA_Addr_EVN  0x00000000
#define SET_Addr_EVN   0x00080000
#define CLR_Addr_EVN   0x00100000
#define DATA_Addr_ODD  0x00000004
#define SET_Addr_ODD   0x00080004
#define CLR_Addr_ODD   0x00100004

							/* Define ESM Present */
#define ESM_PRESENT 1

/**********************************************************************************************************************/
/*	 				DMA REQUEST LINES							      */
/**********************************************************************************************************************/
#define	MIBSPI1_TG1_DMA_REQ		 0

#define	MIBSPI1_TG0_DMA_REQ		 1
#define NUM_DMA_CHANNELS		16


#define	MIBSPI1_TG2_DMA_REQ		 4
#define	MIBSPI3_TG2_DMA_REQ		 4
#define	DCAN2_IF3_DMA_REQ		 4

#define	MIBSPI1_TG3_DMA_REQ		 5
#define	MIBSPI3_TG3_DMA_REQ		 5
#define	DCAN2_IF2_DMA_REQ		 5

#define	MIBSPIP5_TG2_DMA_REQ		 6
#define	DCAN1_IF2_DMA_REQ		 6

#define MIBADC1_EV_DMA_REQ		 7
#define	MIBSPIP5_TG3_DMA_REQ		 7

#define	MIBSPI1_TG4_DMA_REQ	 	 8
#define	MIBSPI3_TG4_DMA_REQ		 8
#define	DCAN1_IF1_DMA_REQ		 8

#define	MIBSPI1_TG5_DMA_REQ	 	 9
#define	MIBSPI3_TG5_DMA_REQ		 9
#define	DCAN2_IF1_DMA_REQ		 9

#define	MIBADC1_G1_DMA_REQ		10
#define	MIBSPIP5_TG4_DMA_REQ		10

#define	MIBADC1_G2_DMA_REQ		11
#define	MIBSPIP5_TG5_DMA_REQ		11

#define RTI_DMA_REQ0			12
#define	MIBSPI1_TG6_DMA_REQ		12
#define	MIBSPI3_TG6_DMA_REQ		12

#define RTI_DMA_REQ1			13
#define	MIBSPI1_TG7_DMA_REQ		13
#define	MIBSPI3_TG7_DMA_REQ		13

#define	MIBSPI3_TG1_DMA_REQ		14
#define	MIBSPIP5_TG6_DMA_REQ		14
#define MIBADC2_EV_DMA_REQ		14

#define	MIBSPI3_TG0_DMA_REQ		15
#define	MIBSPIP5_TG7_DMA_REQ		15

#define	MIBSPI1_TG8_DMA_REQ		16
#define	MIBSPI3_TG8_DMA_REQ		16
#define	MIBADC2_G1_DMA_REQ		16
#define	DCAN1_IF3_DMA_REQ		16

#define	MIBSPI1_TG9_DMA_REQ		17
#define	MIBSPI3_TG9_DMA_REQ		17
#define	MIBADC2_G2_DMA_REQ		17
#define	DCAN3_IF1_DMA_REQ		17

#define RTI_DMA_REQ2			18
#define	MIBSPIP5_TG8_DMA_REQ		18

#define RTI_DMA_REQ3			19
#define	MIBSPIP5_TG9_DMA_REQ		19

#define HET_DMA_REQ4			20    
#define LIN1_RX_DMA_REQ 		20
#define	DCAN3_IF2_DMA_REQ		20

#define LIN1_TX_DMA_REQ 		21
#define HET_DMA_REQ5	 		21
#define	DCAN3_IF3_DMA_REQ		21

#define	MIBSPI1_TG10_DMA_REQ		22
#define	MIBSPI3_TG10_DMA_REQ		22
#define	MIBSPIP5_TG10_DMA_REQ		22

#define	MIBSPI1_TG11_DMA_REQ		23
#define	MIBSPI3_TG11_DMA_REQ		23

#define	MIBSPIP5_TG11_DMA_REQ		23

#define HET_DMA_REQ6 			24
#define	MIBSPIP5_TG12_DMA_REQ		24

#define HET_DMA_REQ7 			25
#define	MIBSPIP5_TG13_DMA_REQ		25

#define CRC_DMA_REQ0			26
#define	MIBSPI1_TG12_DMA_REQ		26
#define	MIBSPI3_TG12_DMA_REQ		26

#define CRC_DMA_REQ1			27    
#define	MIBSPI1_TG13_DMA_REQ		27
#define	MIBSPI3_TG13_DMA_REQ		27

#define LIN_RX_DMA_REQ 			28
#define	MIBSPIP5_TG14_DMA_REQ		28

#define LIN_TX_DMA_REQ 			29
#define	MIBSPIP5_TG15_DMA_REQ		29

#define	MIBSPI1_TG14_DMA_REQ		30
#define	MIBSPI3_TG14_DMA_REQ		30
#define	MIBSPIP5_TG1_DMA_REQ		30

#define	MIBSPI1_TG15_DMA_REQ		31
#define	MIBSPI3_TG15_DMA_REQ		31
#define	MIBSPIP5_TG0_DMA_REQ		31


/******************************************************************************************************************/
/*				Defined CLK Source for ALL valid Channels 					  */
/* 			    done by 'or' all aviabale CLK channels 0|1|4|5|6    				  */
/******************************************************************************************************************/
#define CLK_SRC_CHANNELS   0x73


/******************************************************************************************************************/
/*	 			MEMORY AUTO_INITIALISATION						          */
/******************************************************************************************************************/
#define CPU_RAM_INIT		 0
#define MIBSPIP5_RAM_INIT	12
#define MIBSPI3_RAM_INIT	11
#define MIBSPI1_RAM_INIT	 7
#define DCAN3_RAM_INIT		10
#define DCAN2_RAM_INIT		 6
#define DCAN1_RAM_INIT		 5
#define AWM1_RAM_INIT		 8
#define NHET_RAM_INIT		 3
#define HTU_RAM_INIT		 4
#define DMA_RAM_INIT		 1
#define VIM_RAM_MEM_INIT	 2
#define FTU_RAM_INIT		13
#define AWM2_RAM_INIT		14

//Channel lines for Memory tests
 
#define YES 		1
#define NO 		0

//MEMORY AUTO-INITIALIZATION CHANNELS
#define DMA_ch		YES
#define ADC_ch		YES
#define DCAN1_ch	YES
#define DCAN2_ch	YES
#define DCAN3_ch	YES
#define VIM_ch		YES
#define NHET_ch		YES
#define SPI_ch		YES
#define HET_ch 		NO
#define HETTU_ch	YES
#define MIBSPI2_ch 	YES
#define MIBSPI3_ch  	YES
#define ADC2_ch     	YES
#define FTU_RAM_ch  	YES



#ifdef SPI
#undef SPI
#define SPI MIBSPIP1
#endif



/* RAM LOWER & UPPER BOUNDARY TEST */
#define SRAM_LB  0x00001000
#define SRAM_UB  0x00002ef0

#define MIBSPI_LB 0xFF0E0000
#define MIBSPI_UB 0xFF0E0200


/* CRC channels */
#define NUM_CRC_CHANNELS_2



/************************************************************************************************************************/
/*	 				ESM  CHANNELS							     		*/
/************************************************************************************************************************/

#define ESM_G1_MIBADC2_PARITY		 	 1		  
#define ESM_G1_DMA_MPV				 2		  
#define ESM_G1_DMA_PARITY			 3
#define ESM_G1_SYS_DMA_TRAN			 5
#define ESM_G1_FLASH_SINGLE_ECC		 	 6
#define ESM_G1_HET_PARITY			 7
#define ESM_G1_HET_TU_PARITY		 	 8
#define ESM_G1_HET_TU_MPV			 9
#define ESM_G1_PLL_SLIP				10
#define ESM_G1_CLK_MONITOR			11
#define ESM_G1_FLEXRAY_PARITY			12
#define ESM_G1_IMPRECISE_ERR			13
#define ESM_G1_FLEXRAY_TU_PARITY		14
#define ESM_G1_VIM_PARITY			15
#define ESM_G1_FLEXRAY_TU_MPV			16
#define ESM_G1_MIBSPI1_PARITY			17
#define ESM_G1_MIBSPI3_PARITY			18
#define ESM_G1_MIBADC1_PARITY			19
#define RESERVED4				20
#define ESM_G1_CAN1_PARITY			21
#define ESM_G1_CAN3_PARITY			22
#define ESM_G1_CAN2_PARITY			23
#define ESM_G1_MIBSPIP5_PARITY			24
#define RESERVED5				25
#define ESM_G1_RAM_SINGLE_EVEN			26
#define ESM_G1_CPU_SELFTEST			27
#define ESM_G1_RAM_SINGLE_ODD			28
#define ESM_G1_PBIST_SELFTEST			29
#define RESERVED6				30
#define ESM_G1_CCMR4_SELFTEST			31
#define ESM_G2_CCMR4_COMPARE			34
#define ESM_G2_FLASH_ECC			36
#define ESM_G2_RAM_DOUBLE_EVEN			38
#define ESM_G2_RAM_DOUBLE_ODD			40
#define ESM_G2_RAM_ADDR_PARITY_EVEN		42
#define ESM_G2_RAM_ADDR_PARITY_ODD		44
//#define ESM_G3_RAM_ECC_DOUBLE_EVEN		66
//#define ESM_G3_RAM_ECC_DOUBLE_ODD		68
#define ESM_G3_FLASH_ECC				70
#define ESM_G3_CHAN_3					03
#define ESM_G3_CHAN_5					05


/***************************************END IF ESM CHANNELS******************************************************************/


/****************************************************************************************************************************/
/*					 MODULE CONFIGURATION						     		    */
/****************************************************************************************************************************/
								/* RTI Configuration */
#define NUM_RTI_COUNTERS_2 
#define NUM_RTI_CMP_INT_4
#define RTI_NODWD

								/* MIBSPI1 Configuration */
#define NUM_MIBSPI1_CS_4
#define NUM_MIBSPI1_ENA
#define NUM_TRNSFR_GROUPS			8


								/* MIBSPI3 Configuration */
#define NUM_MIBSPI3_CS_4
#define NUM_MIBSPI3_ENA
#define NUM_TRNSFR_GROUPS			8


								/* MIBSPIP5 Configuration */
#define NUM_MIBSPIP5_SIMO_PINS			4
#define NUM_MIBSPIP5_SOMI_PINS			4
#define NUM_MIBSPIP5_CS_4
#define NUM_MIBSPIP5_ENA
#define NUM_TRNSFR_GROUPS			8

								/* GIO Configuration */
#define NUM_GIO_PORTS				2
#define GIO1_Pins_on_PortA			8
#define GIO1_Pins_on_PortB			8
#define GIO1_Pins_on_PortC			0
#define GIO1_Pins_on_PortD			0
#define GIO1_Pins_on_PortE			0
#define GIO1_Pins_on_PortF			0
#define GIO1_Pins_on_PortG			0
#define GIO1_Pins_on_PortH			0
#define GIO1_Interrupt_capable_pins_on_PortA 	8 
#define GIO1_Interrupt_capable_pins_on_PortB 	0
#define GIO1_Interrupt_capable_pins_on_PortC 	0
#define GIO1_Interrupt_capable_pins_on_PortD 	0

								/* NHET Configuration */
#define NUM_NHET_PINS				32

								/* DCAN1 Configuration */
#define NUM_DCAN1_MESSAGES			64

								/* DCAN2 Configuration */
#define NUM_DCAN2_MESSAGES			64

								/* DCAN3 Configuration */
#define NUM_DCAN3_MESSAGES			32

								/*RTP Configuration */
#define NUM_RTPDATA_PINS 			16

								/*DMM Configuration */
#define NUM_DMMDATA_PINS 			16

								/*ETM Configuration */
#define NUM_ETMDATA_PINS_31

								/* ADM1 configurations */
#define ADM1_NUM_OF_CHAN			16
#define ADM1_NUM_OF_MAGTHR   			 6              /* no. of Magnitude threshold registers */

								/* ADM2 configurations */
#define ADM2_NUM_OF_CHAN    			16
#define ADM2_NUM_OF_MAGTHR   			 6    	       //no. of Magnitude threshold registers

								/* AWM1 No of channels */
#define AWM1_NUM_OF_CHAN			16

/**************************************MEMORY Range Testing definitions**************************************************/

#define MIBSPIP1_RAM_WORDS 128
#define MIBSPIP3_RAM_WORDS 128
#define MIBSPIP5_RAM_WORDS 128
#define NHET_RAM_INSTRCTNS 128
#define DCAN1_MSG_SIZE     NUM_DCAN1_MESSAGES
#define DCAN2_MSG_SIZE     NUM_DCAN2_MESSAGES
#define DCAN3_MSG_SIZE     NUM_DCAN#_MESSAGES
#define HETTU_DCP_PCKTS      8
#define DMA_CNTL_PCKTS     NUM_DMA_CHANNELS
#define ADC1_RAM_WORDS 	    64
#define ADC2_RAM_WORDS 	    64
#define VIM_CHNLS	   VIM_CHANNELS
#define FRAYTU_MSG_RAM	    64 



/*************************************VIM INTERRUPT REMAP channels********************************************************/

#define INT_REMAP_CH1	MIBSPI1_LVL0_INT	//12
#define INT_REMAP_CH2	LIN_LVL0_INT		//13
#define INT_REMAP_CH3	ADM1_EV_INT		//14
#define INT_REMAP_CH4	ADM1_GP1_INT		//15
                                                    
/*********************************NOTE::   Plesae add channels 12, 13,14,15 to the defines on the Lft hand side                                           
					   END OF VIM INTERRUPT REMAP CHANNELS********************************************/

/* Pull Functionality */
#define PULLDIS_TIEOFF		  	  0

#define NO_PULL				  0
#define PULL_DOWN			  1
#define PULL_UP				1<<1
#define INPUT				  0
#define OUTPUT				1<<2

/*#define INPUT_PULL_UP	2*/

#define HET_PULL			INPUT|PULL_DOWN
#define CAN1_PULL			INPUT|PULL_UP
#define CAN2_PULL			INPUT|PULL_UP
#define GIOA_PULL			INPUT|PULL_DOWN
#define ADC1_PULL			INPUT|PULL_DOWN
#define ADC2_PULL			INPUT|PULL_DOWN
#define SCI1_PULL			INPUT|PULL_UP
#define SCI2_PULL			INPUT|PULL_UP

#define MIBSPI1_PULL 			INPUT|PULL_UP 	//..Momin
#define CAN1_OPNDRN        	 	DISABLE
#define CAN2_OPNDRN        		 DISABLE
#define LIN_PULL			INPUT|PULL_UP

//For SYS module
#define DISABLE_ON_RESET    		2
#define ENABLE_ON_RESET     		2
#define ENABLE  			1
#define ECLK_PULL       		INPUT & PULL_DOWN
#define LPO_HFRQ_CLK			DISABLE_ON_RESET
#define CLK_DOMAIN 			DISABLE_ON_RESET
#define CLK_SRC_DOMAIN			ENABLE_ON_RESET
#define CLK_SRC_VALID			ENABLE_ON_RESET
#define PLL_CTL				ENABLE


//For VIM module
#define VIM_NMI_DEFINE3 2  

//For MEMINIT testcases in SYSTEM module

#define MEM_CH_DMARAM		0x02		/*Channel number is 1*/
#define MEM_CH_VIMRAM		0x04		/*Channel number is 2*/
#define MEM_CH_NHETRAM		0x08		/*Channel number is 3*/
#define MEM_CH_HETTURAM		0x10		/*Channel number is 4*/
#define MEM_CH_DCAN1RAM		0x20		/*Channel number is 5*/
#define MEM_CH_DCAN2RAM		0x40		/*Channel number is 6*/
#define MEM_CH_DCAN3RAM		0x400		/*Channel number is 10*/
#define MEM_CH_MIBSPI1RAM	0x80		/*Channel number is 7*/
#define MEM_CH_MIBSPI2RAM	0x800		/*Channel number is 11*/
#define MEM_CH_MIBSPI3RAM	0x1000		/*Channel number is 12*/
#define MEM_CH_MIBADC1RAM	0x100		/*Channel number is 8*/
#define MEM_CH_MIBADC2RAM	0x4000		/*channel number is 14*/
#define MEM_CH_FTURAM		0x2000		/*channel number is 13*/
#define MEM_CH_RAMWRAPPER	0x01		/*channel number is 0*/


#define ALL_channels		0x7DFE

#define RAM_ILL_ADDRESS	    	0x28000         //ANTARES 160KB of RAM
#define VBUS_ILL_ADDRESS	0xFFF70000      //ANTARES 
#define FLASH_ILL_ADDRESS   	0x08200000      //ANTARES FLASH END ADDRESS(2MB)


//Device specific Parameters FOR SYSTEM Register Testcase
//#define CSDIS_VALUE 		0x000000CE    // Commented because of conflict with TMS570_system.h file
//#define PLLCTL1     		0x2F025F00
//#define PLLCTL2     		0x7FC07200
//#define CSVSTAT     		0x00000073

//For Memory Initialization of RAM testcase ran from FLASH
#define RAM_ADDR		0x08000000

//DeviceID of the ANTARES
#define DEVICE_ID 		0x80206D0D


//Variables for TCRAMW module
#define RAM_EVEN_LOCATION  	0x1100
#define RAM_ODD_LOCATION   	0x1108


//Chip selects for MIBSPI for MEMINIT testcases
#define NUMBER_MIBSPI1_CS 4  //4 chip selects for MIBSPI1 
#define NUMBER_MIBSPI3_CS 4  //4 chip selects for MIBSPI2
#define NUMBER_MIBSPI5_CS 4  //4 chip selects for MIBSPI3


//Definition for Number of bits for ADC module (MEMINIT testcase)
#define NO_OF_BITS_ADC1 12 	//For ANTARES ADC1 =12 bits
#define NO_OF_BITS_ADC2 12  	//For ANTARES ADC2 =12 bits

//RTP DMM Memory Tracing regions
#define RTP_DMM_RAM_REG1 	0x2800
#define RTP_DMM_RAM_REG2	0x2C00
#define RTP_DMM_DMA_RAM_REG1	0x4000
#define RTP_DMM_DMA_RAM_REG2	0x4400


//Mster ID values
#define DMA_MASTER_ID 		2
#define DMM_MASTER_ID 		3
#define DAP_MASTER_ID 		4

/********************************************POM********************************************************************/

#define POM	     			0xFFA04000 
#define NUM_POM_REG     		32	                  /*No of regions*/
#define POM_ADDRMAP_START		0x60000000
#define POM_ADDRMAP_END			0x603FFFFC



/****************************************PBIST Entires**************************************************************/


#define PBIST 				0xFFFFE500 		/* Base Address of PBIST - As the address from offset 0x400 - 0x500 are reserved,the PBIST configaration register starts only from 0xFFFFE500 onwards */

#define PBIST_CH1_ALGO 			0x01			/*PBIST  ROM */
#define PBIST_CH1 			0x0001

#define PBIST_CH2_ALGO 			0x1554			/* STC MEM  Single Port*/	
#define PBIST_CH2 			0x0002

#define PBIST_CH3_ALGO 			0x1554			/* DCAN1- Single port*/
#define PBIST_CH3 			0x0004

#define PBIST_CH4_ALGO 			0x1554     		/* DCAN2-Single port */
#define PBIST_CH4 			0x0008

#define PBIST_CH5_ALGO 			0x1554			/*DCAN3-Single port */
#define PBIST_CH5 			0x00010

#define PBIST_CH6_ALGO 			0x1554			/*ESRAM - single Port*/
#define PBIST_CH6 			0x0020

#define PBIST_CH7_ALGO 			0x1554			/* MIBSPI -Single port*/
#define PBIST_CH7 			0x0040

#define PBIST_CH8_ALGO 			0x1554			/* VIM  Single port */
#define PBIST_CH8 			0x0080

#define PBIST_CH9_ALGO 			0x2AA8			/* MIBADC - Two port*/
#define PBIST_CH9 			0x0100

#define PBIST_CH10_ALGO 		0x400	 		/* DMA Two port Only sliced algo */
#define PBIST_CH10 			0x0200

#define PBIST_CH11_ALGO 		0x2AA8			/* HET Two port */
#define PBIST_CH11 			0x0400

#define PBIST_CH12_ALGO 		0x2AA8			/* HTU  Two port */
#define PBIST_CH12 			0x0800


#define PBIST_CH13_ALGO 		0x2AA8			/* RTP Two port */
#define PBIST_CH13 			0x1000


#define PBIST_CH14_ALGO 		0x0F			/* FLEXRAY  single port */
#define PBIST_CH14 			0x0001

#define PBIST_CH15_ALGO 		0x0F			/* ESRAM single port*/
#define PBIST_CH15 			0x0001



//For DEVICE RAM with PARITY Generation
#define MIBADC1_PARITY    	YES
#define MIBADC2_PARITY    	YES
#define DMA_PARITY 		YES
#define DCAN1_PARITY 		YES
#define DCAN2_PARITY 		YES
#define DCAN3_PARITY 		YES
#define HTU_PARITY		YES
#define NHET_PARITY  		YES

#define DMA_RAM_PARITY 		0xfff80A00
#define HET_RAM_PARITY 		0xff4e0200
#define NHET_RAM_PARITY 	0xff462000
#define FRAYTU_RAM_PARITY 	0xff500200


/*****************************************EMIF*****************************************************************************/
#define EMIF     		0xFFFFE800 
#define NUM_EMIF_CS     	4	                  /*No of Chip Select*/
#define EMIF_CS0_ADDRMAP_START	0x60000000
#define EMIF_CS0_ADDRMAP_END	0x63FFFFFC
#define EMIF_CS1_ADDRMAP_START	0x64000000
#define EMIF_CS1_ADDRMAP_END	0x67FFFFFC
#define EMIF_CS2_ADDRMAP_START	0x68000000
#define EMIF_CS2_ADDRMAP_END	0x6BFFFFFC
#define EMIF_CS3_ADDRMAP_START	0x6C000000
#define EMIF_CS3_ADDRMAP_END	0x6FFFFFFC
/**************************************************************************************************************************/


/************************************************* FTU ********************************************************************/

#define FTU1			0xFFF7A000
#define FTU1_END		0xFFF7A400
#define FTU1_RAM		0xFF500000
#define FTU1_ERR_INT		58
#define FTU1_TRSFR_ST_INT	48
#define FTU1_RAM_INIT		05
#define ESM_G1_FTU1_PARITY	14
#define ESM_G1_FTU1_MPV		18
#define FTU1_RAM_WORDS		64


#define FRAY            	0xFFF7C800
#define FRAY_T1C_INT		62		    /*FLEXRAY LINES*/
#define FRAY_TOC_INT		52
#define FRAY_LVL1_INT       	45
#define FRAY_LVL0_INT           43
//#define FRAY1_TU_MPU_INT		16		    	/*ESM Interrupt line for FTU - MPU*/
//#define FRAY1_TU_PARITY_INT		14	            /*ESM Interupt line for FTU - Parity*/



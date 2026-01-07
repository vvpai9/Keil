
/*************************************************GIO1***********************************************/
#define GIO1                                      0xFFF7BC00                              /*GIO Address*/
#define GIO1_LVL0_INT                              9                                      /*VIM channel number for Level 0 Interrupt*/
#define GIO1_LVL1_INT                              23                                     /*VIM channel number for Level 1 Interrupt*/
#define GIO1_Pins_on_PortA                         8                                      /*Number of Pins Port A*/
#define GIO1_Pins_on_PortB                         8                                      /*Number of Pins Port B*/
#define GIO1_Interrupt_capable_pins_on_PortA       8                                      /*Number of Intr Capable Pins Port A*/


/***********************SPI1*************************/
#define SPI1                       0xFFF7F400                         /*SPI Memory Map : Base Address*/
#define SPI1_LVL0_INT               12                                /*SPI Level 0 interrupt*/
#define SPI1_LVL1_INT               26                                /*SPI Level 1 interrupt*/
#define SPI1_RX_DMA_REQ             0                                 /*SPI RX DMA Request Line*/
#define SPI1_TX_DMA_REQ             1                                 /*SPI TX DMA Request Line*/
#define NUM_SPI1_CS_PINS            4                                 /*No of SPI Chip Select Pins*/
#define NUM_SPI1_ENA_PINS           1                                 /*Is Enable Pin Available*/
#define SPI1_PULLDIS_TIEOFF        0x01010F0F                         /*Reset SPI PULL Disable Value*/
#define SPI1_PULLSEL_TIEOFF        0x00000000                         /*Reset SPI PULL Select Value*/


/***********************LIN*************************/
#define LIN1                       0xFFF7E400                         /*LIN Base Address*/
#define LIN1_LVL0_INT               13                                /*VIM Line LIN Level 0 Interrupt*/
#define LIN1_LVL1_INT               27                                /*VIM Line LIN Level 1 interrupt*/
#define LIN1_RX_DMA_REQ             28                                /*Channel ID for LIN RX DMA Request*/
#define LIN1_TX_DMA_REQ             29                                /*Channel ID for LIN TX DMA Request*/


/***********************NHET1*************************/
#define NHET1                      0xFFF7B800                         /*NHET Base Address*/
#define NHET1_END                  0xFFF7B8FF                         /*NHET End Address (Calculated: 0xFF From NHET Base Address) */
#define NHET1_RAM                  0xFF460000                         /*NHET RAM Base Address*/
#define NHET1_LVL0_INT              10                                /*VIM Line NHET Level 0 Interrupt*/
#define NHET1_LVL1_INT              24                                /*VIM Line NHET Level 1 interrupt*/
#define NHET1_RAM_INIT              3                                 /*NHET Auto-initialization Line*/
#define MEM_CH_NHET1_RAM           0x0008                             /*NHET Auto-initialization Line*/
#define NHET1_RAM_NUMWORDS          127                               /*Implemented NHET RAM*/
#define NUM_NHET1_PINS              24                                /*Number of NHET pins*/
#define NHET1_DMA_REQ4              20                                /*Channel ID for NHET DMA Request(4)*/
#define NHET1_DMA_REQ5              21                                /*Channel ID for NHET DMA Request(5)*/
#define NHET1_DMA_REQ6              24                                /*Channel ID for NHET DMA Request(6)*/
#define NHET1_DMA_REQ7              25                                /*Channel ID for NHET DMA Request(7)*/


/***********************RTI*************************/
#define RTI1                       0xFFFFFC00                         /*RTI Memory Map Address*/
#define RTI1_NODWD                 1                                  /*Digital WatchDog Not Available*/
#define NUM_RTI1_COUNTERS_2        1                                  /*No of FRC OverFlow Interrupts is 2*/
#define NUM_RTI1_CMP_INT_4         1                                  /*No of Compare Units is 4*/
#define RTI1_COMP0_INT             2                                  /*Interrupt Channel For Compare 0*/
#define RTI1_COMP1_INT             3                                  /*Interrupt Channel For Compare 1*/
#define RTI1_COMP2_INT             4                                  /*Interrupt Channel For Compare 2*/
#define RTI1_COMP3_INT             5                                  /*Interrupt Channel For Compare 3*/
#define RTI1_OVL0_INT              6                                  /*Interrupt Channel For FRC0*/
#define RTI1_OVL1_INT              7                                  /*Interrupt Channel For FRC1*/
#define RTI1_TBASE_INT             8                                  /*Timebase Interrupt Channel*/
#define RTI1_DMA_REQ0              12                                 /*DMAREQ number for Compare 0*/
#define RTI1_DMA_REQ1              13                                 /*DMAREQ number for Compare 1*/
#define RTI1_DMA_REQ2              18                                 /*DMAREQ number for Compare 2*/
#define RTI1_DMA_REQ3              19                                 /*DMAREQ number for Compare 3*/


/***********************VIM1*************************/
#define VIM                        0xFFFFFE00                         /*VIM Address In Memory Map*/
#define VIM_RAM                    0xFFF82000                         /*VIM RAM Address*/
#define VIM_PARITY                 0xFFFFFDEC                         /*VIM PARITY Address*/
#define VIM_CHANNELS                64                                /*Total Number of VIM Channels*/
#define PHANTOM_INT                -1                                 /*To be used in VIM_FIQ/VIM_IRQ functions as (PHANTOM_INT + 1)*/
#define VIM_RAM_MEM_INIT            2                                 /*VIM RAM Initialisation line*/
#define NO_NMI_RESV                 2                                 /*Total number of Reserved NMIs*/
#define VIM_NMI_DEFINE              2                                 /*Total number of Reserved NMIs*/
#define VIM_RAM_SIZE               VIM_CHANNELS                       /*Size of VIM RAM Implemented*/
#define INT_REMAP_CH1              12                                 /*VIM Channel 1 Re-mapping*/
#define INT_REMAP_CH2              13                                 /*VIM Channel 2 Re-mapping*/
#define INT_REMAP_CH3              14                                 /*VIM Channel 3 Re-mapping*/
#define INT_REMAP_CH4              15                                 /*VIM Channel 4 Re-mapping*/


/***********************DCAN1*************************/
#define DCAN1                      0xFFF7DC00                         /*DCAN1 Peripheral Select Memory Map: Base Address*/
#define DCAN1_END                  0xFFF7DDFF                         /*DCAN1 Peripheral Select Memory Map: Ending Address*/
#define DCAN1_RAM                  0xFF1E0000                         /*DCAN1 Peripheral RAM: Base Address*/
#define DCAN1_LVL0_INT              16                                /*DCAN1 Request Assignment For Level 0 Interrupt*/
#define DCAN1_LVL1_INT              29                                /*DCAN1 Request Assignment For Level 1 Interrupt*/
#define DCAN1_IF3_INT               44                                /*DCAN1 Request Assignment For Interface Register 3 Interrupt*/
#define DCAN1_IF1_DMA_REQ           8                                 /*DCAN1 DMA request assignment For Interface Register 1*/
#define DCAN1_IF2_DMA_REQ           6                                 /*DCAN1 DMA request assignment For Interface Register 2*/
#define DCAN1_IF3_DMA_REQ           16                                /*DCAN1 DMA request assignment For Interface Register 3*/
#define DCAN1_RAM_INIT              5                                 /*DCAN1 RAM Select (Memory Initialization)*/
#define MEM_CH_DCAN1RAM            0x0020                             /*DCAN1 Bitmap representation of DCAN RAM Select*/
#define DCAN1_MSG_SIZE              64                                /*DCAN1 Total Number of Mailboxes/CAN Messages*/
#define NUM_DCAN1_MESSAGES          64                                /*DCAN1 Total Number of Mailboxes/CAN Messages*/


/***********************DCAN2*************************/
#define DCAN2                      0xFFF7DE00                         /*DCAN2 Peripheral Select Memory Map: Base Address*/
#define DCAN2_END                  0xFFF7DFFF                         /*DCAN2 Peripheral Select Memory Map: Ending Address*/
#define DCAN2_RAM                  0xFF1C0000                         /*DCAN2 Peripheral RAM: Base Address*/
#define DCAN2_LVL0_INT              35                                /*DCAN2 Request Assignment For Level 0 Interrupt*/
#define DCAN2_LVL1_INT              42                                /*DCAN2 Request Assignment For Level 1 Interrupt*/
#define DCAN2_IF3_INT               46                                /*DCAN2 Request Assignment For Interface Register 3 Interrupt*/
#define DCAN2_IF1_DMA_REQ           9                                 /*DCAN2 DMA request assignment For Interface Register 1*/
#define DCAN2_IF2_DMA_REQ           5                                 /*DCAN2 DMA request assignment For Interface Register 2*/
#define DCAN2_IF3_DMA_REQ           4                                 /*DCAN2 DMA request assignment For Interface Register 3*/
#define DCAN2_RAM_INIT              6                                 /*DCAN2 RAM Select (Memory Initialization)*/
#define MEM_CH_DCAN2RAM            0x0040                             /*DCAN2 Bitmap representation of DCAN RAM Select*/
#define DCAN2_MSG_SIZE              64                                /*DCAN2 Total Number of Mailboxes/CAN Messages*/
#define NUM_DCAN2_MESSAGES          64                                /*DCAN2 Total Number of Mailboxes/CAN Messages*/


/***********************MCRC1*************************/
#define MCRC1                      0xFE000000                         /*MCRC Memory Map Address*/
#define NUM_CRC1_CHANNELS_2                                           /*Two Channels : Assumption Chan 0 must be 'All Modes' and Chan 1 must be 'FULL+SEMI+AUTO'*/
#define CRC1_LVL0_INT               19                                /*MCRC Level 0 Interrupt*/
#define CRC1_DMA_REQ0               26                                /*MCRC DMA Request For Channel 0*/
#define CRC1_DMA_REQ1               27                                /*MCRC DMA Request For Channel 1*/


/***********************HTU1*************************/
#define HTU1                       0xFFF7A400                         /*HTU Base Address*/
#define HTU1_RAM                   0xFF4E0000                         /*HTU RAM Base Address*/
#define HTU1_LVL0_INT               11                                /*VIM Line for HTU Level 0 Interrupt*/
#define HTU1_LVL1_INT               25                                /*VIM Line for HTU Level 1 Interrupt*/
#define HTU1_RAM_INIT               4                                 /*HTU RAM Memory Auto-initialization Line*/
#define HTU1_END                   0xFFF7A4FF                         /*HTU End Address (Calculated: 0xFF From HTU Base Address) */
#define HTU1_RAM_PARITY            0xFF4E0200                         /*HTU Parity Memory (Calculated: 0x200 From HTU RAM Base Address) */


/***********************MPU1*************************/


/***********************ESM*************************/
#define ESM                        0xFFFFF500                         /*ESM Memory Map Address*/
#define ESM_HIGH_PRIORITY_INT      0                                  /*VIM Line for ESM High Priority Interrupt*/
#define ESM_LOW_PRIORITY_INT       20                                 /*VIM Line for ESM Low Priority Interrupt*/

//CHANNEL MAPPING FOR ESM GROUP 1
#define ESM_G1_CHAN_2              2                                  /*ESM Chan Reserved For DMA - Memory Protection Violation Error*/
#define ESM_G1_CHAN_3              3                                  /*ESM Chan Reserved For DMA - Parity error*/
#define ESM_G1_CHAN_5              5                                  /*ESM Chan Reserved For DMA/AHB-AP imprecise read error*/
#define ESM_G1_CHAN_6              6                                  /*ESM Chan Reserved For FLASH correctable error*/
#define ESM_G1_CHAN_7              7                                  /*ESM Chan Reserved For NHET parity error*/
#define ESM_G1_CHAN_8              8                                  /*ESM Chan Reserved For HET TU T parity error*/
#define ESM_G1_CHAN_9              9                                  /*ESM Chan Reserved For HET TU- Memory Protection Violation Error*/
#define ESM_G1_CHAN_10             10                                 /*ESM Chan Reserved For PLL slip error*/
#define ESM_G1_CHAN_11             11                                 /*ESM Chan Reserved For Clock Monitor interrupt*/
#define ESM_G1_CHAN_13             13                                 /*ESM Chan Reserved For DMA/AHB-AP imprecise write error*/
#define ESM_G1_CHAN_15             15                                 /*ESM Chan Reserved For VIM RAM parity error*/
#define ESM_G1_CHAN_17             17                                 /*ESM Chan Reserved For MIBSPI1 parity error*/
#define ESM_G1_CHAN_18             18                                 /*ESM Chan Reserved For MIBSPI3 parity error*/
#define ESM_G1_CHAN_19             19                                 /*ESM Chan Reserved For MIBADC parity error*/
#define ESM_G1_CHAN_21             21                                 /*ESM Chan Reserved For DCAN1 parity error*/
#define ESM_G1_CHAN_23             23                                 /*ESM Chan Reserved For DCAN2 parity error*/
#define ESM_G1_CHAN_26             26                                 /*ESM Chan Reserved For RAM even Bank correctable error*/
#define ESM_G1_CHAN_27             27                                 /*ESM Chan Reserved For CPU selftest error*/
#define ESM_G1_CHAN_28             28                                 /*ESM Chan Reserved For RAM odd Bank correctable error*/
#define ESM_G1_CHAN_31             31                                 /*ESM Chan Reserved For CCM-R4 selftest error*/
//CHANNEL MAPPING FOR ESM GROUP 2
#define ESM_G2_CHAN_2              2                                  /*ESM Chan Reserved For  CCM-R4 compare fail*/
#define ESM_G2_CHAN_4              4                                  /*ESM Chan Reserved For FLASH uncorrectable error*/
#define ESM_G2_CHAN_6              6                                  /*ESM Chan Reserved For  RAM even Bank uncorrectable error*/
#define ESM_G2_CHAN_8              8                                  /*ESM Chan Reserved For   RAM odd Bank uncorrectable error*/
#define ESM_G2_CHAN_10             10                                 /*ESM Chan Reserved For  RAM even Bank address bus parity error*/
#define ESM_G2_CHAN_12             12                                 /*ESM Chan Reserved For   RAM odd Bank address bus parity error*/
#define ESM_G2_CHAN_16             16                                 /*ESM Chan Reserved For  FLASH ECC livelock detect*/
//CHANNEL MAPPING FOR ESM GROUP 3
#define ESM_G3_CHAN_3              3                                  /*ESM Chan Reserved For   RAM even Bank ECC  uncorrectable error*/
#define ESM_G3_CHAN_5              5                                  /*ESM Chan Reserved For  RAM odd Bank ECC  uncorrectable error*/
#define ESM_G3_CHAN_7              7                                  /*ESM Chan Reserved For  FLASH ECC uncorrectable error*/


/***********************DMA*************************/
#define DMA                        0xFFFFF000                         /*DMA Memory Map Address*/
#define DMA_RAM                    0xFFF80000                         /*DMA RAM Memory Map Address*/
#define DMA_FTC_INT                 33                                /*Interrupt for FTC (Frame Transfer Complete)*/
#define DMA_LFS_INT                 34                                /*Interrupt for LFS (Last Frame Transfer Started)*/
#define DMA_HBC_INT                 39                                /*Interrupt for HBC (First Half of Block Complete)*/
#define DMA_BTC_INT                 40                                /*Interrupt for BTC (Block Transfer Complete)*/
#define NUM_DMA_CHANNELS            16                                /*Total Number of DMA Channels Available*/
#define NUM_DMA_REQUESTS            32                                /*Total Number of DMA Requests*/
#define DMA_RAM_INIT                1                                 /*Memory Initialization Channel Number*/
#define MEM_CH_DMARAM              0x0002                             /*Memory Initialization Channel Hex Bit Mapped*/
#define DMA_MASTER_ID              2                                  /*DMA Master ID*/


/***********************CCM1*************************/
#define CCM1                       0xFFFFF600                         /*CCM Memory Map Address*/


/***********************ADM1*************************/
#define ADM1                       0xFFF7C000                         /*ADM1 Peripheral Select Memory Map: Base Address*/
#define MIBADC1_END                0xFFF7C1FF                         /*ADM1 Peripheral Select Memory Map: Ending Address*/
#define MIBADC1_RAM                0xFF3E0000                         /*ADM1 Peripheral RAM: Base Address*/
#define ADM1_EV_INT                 14                                /*ADM1 Event Group Interrupt*/
#define ADM1_GP1_INT                15                                /*ADM1 SW Group1 Interrupt*/
#define ADM1_GP2_INT                28                                /*ADM1 SW Group2 Interrupt*/
#define ADM1_MTCI_INT               31                                /*ADM1 Magnitude Threshold Interrupt*/
#define ADM1_EV_DMA_REQ             7                                 /*ADM1 DMA request assignment For Event Group*/
#define ADM1_G1_DMA_REQ             10                                /*ADM1 DMA request assignment For Group 1*/
#define ADM1_G2_DMA_REQ             11                                /*ADM1 DMA request assignment For Group 2*/
#define ADM1_RAM_INIT               8                                 /*ADM1 RAM Select (Memory Initialization)*/
#define MEM_CH_MIBADC1RAM          0x0100                             /*ADM1 BitMap of RAM Select (Memory Initialization)*/
#define ADM1_NUM_OF_CHAN            20                                /*ADM1 Number Of Channels*/
#define ADM1_NUM_OF_MAGTHR          3                                 /*ADM1 Number of Magnitude Threshold registers*/
#define ADM1_RAM_WORDS              64                                /*ADM1 Number of Words Per Channel*/


/***********************TCRAMW*************************/
#define RAM_ECC_ODD                0xFFFFF900                         /*Base Address of RAM ECC ODD*/
#define RAM_ECC_EVN                0xFFFFF800                         /*Base Address of RAM ECC EVN*/


/***********************FWM_ECC*************************/
#define FLASH                      0xFFF87000                         /*FWM ECC Base Address In Memory Map*/
#define FLASH_ILLEGAL		     0x08140000				    /*Flash Illegal Address*/


/***********************SYS*************************/
#define DEVICE_ID                  0x802A6D05                         /*Device ID*/
#define SYSTEM                     0xFFFFFF00                         /*Memory Map Address of SYS Module*/
#define SYS_SW_INT                 21                                 /*VIM Request Mapping For SSI (System SW interrupt)*/
#define ECLK_PULL                  0                                  /*ECLK Default Pull Up/Down State (1- Up 0-Down)*/
#define ALL_channels               0x000009FE                         /*Bit Mapped Representation Of All Channels*/
#define RAM_ILL_ADDRESS            0x00014000                         /*RAM Illegal Address (Check Illegal Transactions)*/
#define VBUS_ILL_ADDRESS           0xFF1A0000                         /*Illegal Peripheral Address (Check Illegal Transactions)*/
#define PCR                        0xFFFFE000                         /*Memory Map Address of PCR Module*/
#define SRAM_LB                    0x1000                             /*SRAM Lower Boundary (Start Address of RAM + .text sec)*/
#define SRAM_UB                    0x00013FF6                         /*SRAM Upper Boundary (Last Address of RAM - 0xA)*/
#define PMU_INT						22


/***********************MIBSPI3*************************/
#define MIBSPI3                    0xFFF7F800                         /*MIBSPI Memory Map : Base Address*/
#define MIBSPI3_LVL0_INT            37                                /*MIBSPI Level 0 interrupt*/
#define MIBSPI3_LVL1_INT            38                                /*MIBSPI Level 1 interrupt*/
#define MIBSPI3_RAM                0xFF0C0000                         /*MIBSPI RAM Base Address*/
#define MIBSPI3_RAM_WORDS           64                                /*Number of MIBSPI RAM words*/
#define NUM_MIBSPI3_DMA_SOURCES     16                                /*No of MIBSPI DMA Sources Supported*/
#define MIBSPI3_SRC0_DMA_REQ        15                                /*MIBSPI DMA Source 0 Request line*/
#define MIBSPI3_SRC1_DMA_REQ        14                                /*MIBSPI DMA Source 1 Request line*/
#define MIBSPI3_SRC2_DMA_REQ        4                                 /*MIBSPI DMA Source 2 Request line*/
#define MIBSPI3_SRC3_DMA_REQ        5                                 /*MIBSPI DMA Source 3 Request line*/
#define MIBSPI3_SRC4_DMA_REQ        8                                 /*MIBSPI DMA Source 4 Request line*/
#define MIBSPI3_SRC5_DMA_REQ        9                                 /*MIBSPI DMA Source 5 Request line*/
#define MIBSPI3_SRC6_DMA_REQ        12                                /*MIBSPI DMA Source 6 Request line*/
#define MIBSPI3_SRC7_DMA_REQ        13                                /*MIBSPI DMA Source 7 Request line*/
#define MIBSPI3_SRC8_DMA_REQ        16                                /*MIBSPI DMA Source 8 Request line*/
#define MIBSPI3_SRC9_DMA_REQ        17                                /*MIBSPI DMA Source 9 Request line*/
#define MIBSPI3_SRC10_DMA_REQ       22                                /*MIBSPI DMA Source 10 Request line*/
#define MIBSPI3_SRC11_DMA_REQ       23                                /*MIBSPI DMA Source 11 Request line*/
#define MIBSPI3_SRC12_DMA_REQ       26                                /*MIBSPI DMA Source 12 Request line*/
#define MIBSPI3_SRC13_DMA_REQ       27                                /*MIBSPI DMA Source 13 Request line*/
#define MIBSPI3_SRC14_DMA_REQ       30                                /*MIBSPI DMA Source 14 Request line*/
#define MIBSPI3_SRC15_DMA_REQ       31                                /*MIBSPI DMA Source 15 Request line*/
#define SPI3_RX_DMA_REQ             14                                /*MIBSPI(Compatibility Mode) RX DMA Request line*/
#define SPI3_TX_DMA_REQ             15                                /*MIBSPI(Compatibility Mode) TX DMA Request line*/
#define MIBSPI3_RAM_INIT            11                                /*MIBSPI RAM memory auto-initialization*/
#define NUM_MIBSPI3_SIMO_PINS       1                                 /*No of MIBSPI SIMO Pins*/
#define NUM_MIBSPI3_SOMI_PINS       1                                 /*No of MIBSPI SOMI Pins*/
#define NUM_MIBSPI3_CS_PINS         4                                 /*No of MIBSPI Chip Select Pins*/
#define NUM_MIBSPI3_ENA_PINS        1                                 /*Is Enable Pin Available*/
#define NUM_MIBSPI3_TRNSFR_GROUPS   8                                 /*No of Transfer Groups Supported*/


/***********************SPI2*************************/
#define SPI2                       0xFFF7F600                         /*SPI Memory Map : Base Address*/
#define SPI2_LVL0_INT               17                                /*SPI Level 0 interrupt*/
#define SPI2_LVL1_INT               30                                /*SPI Level 1 interrupt*/
#define SPI2_RX_DMA_REQ             2                                 /*SPI RX DMA Request Line*/
#define SPI2_TX_DMA_REQ             3                                 /*SPI TX DMA Request Line*/
#define NUM_SPI2_CS_PINS            1                                 /*No of SPI Chip Select Pins*/
#define NUM_SPI2_ENA_PINS           1                                 /*Is Enable Pin Available*/
#define SPI2_PULLDIS_TIEOFF         0x00000000                        /*Reset SPI PULL Disable Value*/
#define SPI2_PULLSEL_TIEOFF        0x01010F01                         /*Reset SPI PULL Select Value*/


/***********************MIBSPI1*************************/
#define MIBSPI1                    0xFFF7F400                         /*MIBSPI Memory Map : Base Address*/
#define MIBSPI1_LVL0_INT            12                                /*MIBSPI Level 0 interrupt*/
#define MIBSPI1_LVL1_INT            26                                /*MIBSPI Level 1 interrupt*/
#define MIBSPI1_RAM                0xFF0E0000                         /*MIBSPI RAM Base Address*/
#define MIBSPI1_RAM_WORDS           128                               /*Number of MIBSPI RAM words*/
#define NUM_MIBSPI1_DMA_SOURCES     16                                /*No of MIBSPI DMA Sources Supported*/
#define MIBSPI1_SRC0_DMA_REQ        1                                 /*MIBSPI DMA Source 0 Request line*/
#define MIBSPI1_SRC1_DMA_REQ        0                                 /*MIBSPI DMA Source 1 Request line*/
#define MIBSPI1_SRC2_DMA_REQ        4                                 /*MIBSPI DMA Source 2 Request line*/
#define MIBSPI1_SRC3_DMA_REQ        5                                 /*MIBSPI DMA Source 3 Request line*/
#define MIBSPI1_SRC4_DMA_REQ        8                                 /*MIBSPI DMA Source 4 Request line*/
#define MIBSPI1_SRC5_DMA_REQ        9                                 /*MIBSPI DMA Source 5 Request line*/
#define MIBSPI1_SRC6_DMA_REQ        12                                /*MIBSPI DMA Source 6 Request line*/
#define MIBSPI1_SRC7_DMA_REQ        13                                /*MIBSPI DMA Source 7 Request line*/
#define MIBSPI1_SRC8_DMA_REQ        16                                /*MIBSPI DMA Source 8 Request line*/
#define MIBSPI1_SRC9_DMA_REQ        17                                /*MIBSPI DMA Source 9 Request line*/
#define MIBSPI1_SRC10_DMA_REQ       22                                /*MIBSPI DMA Source 10 Request line*/
#define MIBSPI1_SRC11_DMA_REQ       23                                /*MIBSPI DMA Source 11 Request line*/
#define MIBSPI1_SRC12_DMA_REQ       26                                /*MIBSPI DMA Source 12 Request line*/
#define MIBSPI1_SRC13_DMA_REQ       27                                /*MIBSPI DMA Source 13 Request line*/
#define MIBSPI1_SRC14_DMA_REQ       30                                /*MIBSPI DMA Source 14 Request line*/
#define MIBSPI1_SRC15_DMA_REQ       31                                /*MIBSPI DMA Source 15 Request line*/
#define SPI1_RX_DMA_REQ             0                                 /*MIBSPI(Compatibility Mode) RX DMA Request line*/
#define SPI1_TX_DMA_REQ             1                                 /*MIBSPI(Compatibility Mode) TX DMA Request line*/
#define MIBSPI1_RAM_INIT            7                                 /*MIBSPI RAM memory auto-initialization*/
#define NUM_MIBSPI1_SIMO_PINS       1                                 /*No of MIBSPI SIMO Pins*/
#define NUM_MIBSPI1_SOMI_PINS       1                                 /*No of MIBSPI SOMI Pins*/
#define NUM_MIBSPI1_CS_PINS         4                                 /*No of MIBSPI Chip Select Pins*/
#define NUM_MIBSPI1_ENA_PINS        1                                 /*Is Enable Pin Available*/
#define NUM_MIBSPI1_TRNSFR_GROUPS   8                                 /*No of Transfer Groups Supported*/


/***********************FWM_ECC*************************/
#define FLASH                      0xFFF87000                         /*FWM ECC Base Address In Memory Map*/


/***********************BMM1*************************/
#define RAM_DMA_CH                  2                                 /*RAM DMA Channel Number*/


/***********************SPI3*************************/
#define SPI3                       0xFFF7F800                         /*SPI Memory Map : Base Address*/
#define SPI3_LVL0_INT               37                                /*SPI Level 0 interrupt*/
#define SPI3_LVL1_INT               38                                /*SPI Level 1 interrupt*/
#define SPI3_RX_DMA_REQ             14                                /*SPI RX DMA Request Line*/
#define SPI3_TX_DMA_REQ             15                                /*SPI TX DMA Request Line*/
#define NUM_SPI3_CS_PINS            4                                 /*No of SPI Chip Select Pins*/
#define NUM_SPI3_ENA_PINS           1                                 /*Is Enable Pin Available*/
#define SPI3_PULLDIS_TIEOFF        0x00000000                         /*Reset SPI PULL Disable Value*/
#define SPI3_PULLSEL_TIEOFF        0x01010F0F                         /*Reset SPI PULL Select Value*/

/******************************************************************************************************************************/

#define PBIST 				0xFFFFE500  	/*Base Address*/

#define PBIST_CH1_ALGO 			0x03			/*PBIST  ROM */
#define PBIST_CH1 			0x0001

#define PBIST_CH2_ALGO 			0x03			/* STC MEM  - ROM*/	
#define PBIST_CH2 			0x0002

#define PBIST_CH3_ALGO 			0x1554			/* DCAN1- Single port*/
#define PBIST_CH3 			0x0004

#define PBIST_CH4_ALGO 			0x1554     		/* DCAN2-Single port */
#define PBIST_CH4 			0x0008

#define PBIST_CH5_ALGO 			0x1554			/* DCAN3 - Reserved-Single port */
#define PBIST_CH5 			0x00010

#define PBIST_CH6_ALGO 			0x1554			/*ESRAM - single Port*/
#define PBIST_CH6 			0x0020

#define PBIST_CH7_ALGO 			0x1554			/* MIBSPI -Single port*/
#define PBIST_CH7 			0x0040

#define PBIST_CH8_ALGO 			0x1554			/* VIM  Single port */
#define PBIST_CH8 			0x0080

#define PBIST_CH9_ALGO 			0x2AA8			/* MIBADC - Two port*/
#define PBIST_CH9 			0x0100

#define PBIST_CH10_ALGO 		0xCAA8	 		/* DMA Two port Only sliced algo */
#define PBIST_CH10 		0x0200

#define PBIST_CH11_ALGO 		0x2AA8			/* HET Two port */
#define PBIST_CH11 		0x0400

#define PBIST_CH12_ALGO 		0x2AA8			/* HTU  Two port */
#define PBIST_CH12 		0x0800


#define PBIST_CH13_ALGO 		0x2AA8			/* RTP two port  - reserved*/
#define PBIST_CH13 		0x1000

/******************************************************************************************************************************/
#define DCC  0xFFFFEC00


/***********************SCI*************************/
#define SCI1                       0xFFF7E400                         /*SCI Base Address*/
#define SCI1_LVL0_INT               13                                /*VIM Line SCI Level 0 Interrupt*/
#define SCI1_LVL1_INT               27                                /*VIM Line SCI Level 1 interrupt*/
#define SCI1_RX_DMA_REQ             28                                /*Channel ID for SCI RX DMA Request*/
#define SCI1_TX_DMA_REQ             29                                /*Channel ID for SCI TX DMA Request*/


/*************Module Header File For SCI********************/
#define SCI                        SCI1                               /*SCI Base Address*/
#define SCI_LVL0_INT               SCI1_LVL0_INT                      /*VIM Line SCI Level 0 Interrupt*/
#define SCI_LVL1_INT               SCI1_LVL1_INT                      /*VIM Line SCI Level 1 interrupt*/
#define SCI_A_RX_DMA_REQ           SCI1_RX_DMA_REQ                    /*Channel ID for SCI RX DMA Request*/
#define SCI_A_TX_DMA_REQ           SCI1_TX_DMA_REQ                    /*Channel ID for SCI TX DMA Request*/
#define SCI_TOTAL_REGS              37                                /*Total Number of SCI Registers*/
#define SCI_PROT_REGS               15                                /*Number of SCI Protocol Control Registers*/
#define PRIVI_REGS                  3                                 /*Number of SCI Priviledge Registers*/

/* Added for silicon validation - Poomathy */
#define RESET_SCI_PULLDIS           0x0
#define RESET_SCI_PULLSEL           0x7
#define SCI_GIO_IN 		    0x6
#define LIN_SCI

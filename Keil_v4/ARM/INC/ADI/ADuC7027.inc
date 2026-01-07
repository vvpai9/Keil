; ===============================================																
; ADuC7027 HEADER FILE REV 1.4																				
; ===============================================																
Z_BASE                         EQU       0xFFFF0000
F_BASE                         EQU       0xFFFFF000
MMR_BASE                       EQU       0xFFFF0000
MMR_BASE_LOW                   EQU       0xFFFF0000
MMR_BASE_HIGH                  EQU       0xFFFFF000

; INTERRUPT CONTROLLER

IRQBASE                        EQU       0xFFFF0000
IRQSTA                         EQU       0xFFFF0000
IRQSIG                         EQU       0xFFFF0004
IRQEN                          EQU       0xFFFF0008
IRQCLR                         EQU       0xFFFF000C
SWICFG                         EQU       0xFFFF0010
FIQSTA                         EQU       0xFFFF0100
FIQSIG                         EQU       0xFFFF0104
FIQEN                          EQU       0xFFFF0108
FIQCLR                         EQU       0xFFFF010C
Z_IRQSTA                       EQU       IRQSTA    -Z_BASE
Z_IRQSIG                       EQU       IRQSIG    -Z_BASE
Z_IRQEN                        EQU       IRQEN     -Z_BASE
Z_IRQCLR                       EQU       IRQCLR    -Z_BASE
Z_SWICFG                       EQU       SWICFG    -Z_BASE
Z_FIQSTA                       EQU       FIQSTA    -Z_BASE
Z_FIQSIG                       EQU       FIQSIG    -Z_BASE
Z_FIQEN                        EQU       FIQEN     -Z_BASE
Z_FIQCLR                       EQU       FIQCLR    -Z_BASE

T_IRQSTA                       EQU       IRQSTA    -IRQBASE   
T_IRQSIG                       EQU       IRQSIG    -IRQBASE   
T_IRQEN                        EQU       IRQEN     -IRQBASE   
T_IRQCLR                       EQU       IRQCLR    -IRQBASE   
T_SWICFG                       EQU       SWICFG    -IRQBASE   
T_FIQSTA                       EQU       FIQSTA    -IRQBASE   
T_FIQSIG                       EQU       FIQSIG    -IRQBASE   
T_FIQEN                        EQU       FIQEN     -IRQBASE   
T_FIQCLR                       EQU       FIQCLR    -IRQBASE   

IRQSTA_OFFSET                  EQU       0x0000
IRQSIG_OFFSET                  EQU       0x0004
IRQEN_OFFSET                   EQU       0x0008
IRQCLR_OFFSET                  EQU       0x000C
SWICFG_OFFSET                  EQU       0x0010
FIQSTA_OFFSET                  EQU       0x0100
FIQSIG_OFFSET                  EQU       0x0104
FIQEN_OFFSET                   EQU       0x0108
FIQCLR_OFFSET                  EQU       0x010C

; REMAP AND SYSTEM CONTROL

REMAPBASE                      EQU       0xFFFF0200
REMAP                          EQU       0xFFFF0220
RSTSTA                         EQU       0xFFFF0230
RSTCLR                         EQU       0xFFFF0234
Z_REMAP                        EQU       REMAP     -Z_BASE
Z_RSTSTA                       EQU       RSTSTA    -Z_BASE
Z_RSTCLR                       EQU       RSTCLR    -Z_BASE

T_REMAP                        EQU       REMAP     -REMAPBASE 
T_RSTSTA                       EQU       RSTSTA    -REMAPBASE 
T_RSTCLR                       EQU       RSTCLR    -REMAPBASE 

REMAP_OFFSET                   EQU       0x0220
RSTSTA_OFFSET                  EQU       0x0230
RSTCLR_OFFSET                  EQU       0x0234

; TIMER 0

T0BASE                         EQU       0xFFFF0300
T0LD                           EQU       0xFFFF0300
T0VAL                          EQU       0xFFFF0304
T0CON                          EQU       0xFFFF0308
T0CLRI                         EQU       0xFFFF030C
Z_T0LD                         EQU       T0LD      -Z_BASE
Z_T0VAL                        EQU       T0VAL     -Z_BASE
Z_T0CON                        EQU       T0CON     -Z_BASE
Z_T0CLRI                       EQU       T0CLRI    -Z_BASE

T_T0LD                         EQU       T0LD      -T0BASE    
T_T0VAL                        EQU       T0VAL     -T0BASE    
T_T0CON                        EQU       T0CON     -T0BASE    
T_T0CLRI                       EQU       T0CLRI    -T0BASE    

T0LD_OFFSET                    EQU       0x0300
T0VAL_OFFSET                   EQU       0x0304
T0CON_OFFSET                   EQU       0x0308
T0CLRI_OFFSET                  EQU       0x030C

; GENERAL PURPOSE TIMER

T1BASE                         EQU       0xFFFF0320
T1LD                           EQU       0xFFFF0320
T1VAL                          EQU       0xFFFF0324
T1CON                          EQU       0xFFFF0328
T1CLRI                         EQU       0xFFFF032C
T1CAP                          EQU       0xFFFF0330
Z_T1LD                         EQU       T1LD      -Z_BASE
Z_T1VAL                        EQU       T1VAL     -Z_BASE
Z_T1CON                        EQU       T1CON     -Z_BASE
Z_T1CLRI                       EQU       T1CLRI    -Z_BASE
Z_T1CAP                        EQU       T1CAP     -Z_BASE

T_T1LD                         EQU       T1LD      -T1BASE    
T_T1VAL                        EQU       T1VAL     -T1BASE    
T_T1CON                        EQU       T1CON     -T1BASE    
T_T1CLRI                       EQU       T1CLRI    -T1BASE    
T_T1CAP                        EQU       T1CAP     -T1BASE    

T1LD_OFFSET                    EQU       0x0320
T1VAL_OFFSET                   EQU       0x0324
T1CON_OFFSET                   EQU       0x0328
T1CLRI_OFFSET                  EQU       0x032C
T1CAP_OFFSET                   EQU       0x0330

; WAKE UP TIMER

T2BASE                         EQU       0xFFFF0340
T2LD                           EQU       0xFFFF0340
T2VAL                          EQU       0xFFFF0344
T2CON                          EQU       0xFFFF0348
T2CLRI                         EQU       0xFFFF034C
Z_T2LD                         EQU       T2LD      -Z_BASE
Z_T2VAL                        EQU       T2VAL     -Z_BASE
Z_T2CON                        EQU       T2CON     -Z_BASE
Z_T2CLRI                       EQU       T2CLRI    -Z_BASE

T_T2LD                         EQU       T2LD      -T2BASE    
T_T2VAL                        EQU       T2VAL     -T2BASE    
T_T2CON                        EQU       T2CON     -T2BASE    
T_T2CLRI                       EQU       T2CLRI    -T2BASE    

T2LD_OFFSET                    EQU       0x0340
T2VAL_OFFSET                   EQU       0x0344
T2CON_OFFSET                   EQU       0x0348
T2CLRI_OFFSET                  EQU       0x034C

; WATCHDOG TIMER

T3BASE                         EQU       0xFFFF0360
T3LD                           EQU       0xFFFF0360
T3VAL                          EQU       0xFFFF0364
T3CON                          EQU       0xFFFF0368
T3CLRI                         EQU       0xFFFF036C
Z_T3LD                         EQU       T3LD      -Z_BASE
Z_T3VAL                        EQU       T3VAL     -Z_BASE
Z_T3CON                        EQU       T3CON     -Z_BASE
Z_T3CLRI                       EQU       T3CLRI    -Z_BASE

T_T3LD                         EQU       T3LD      -T3BASE    
T_T3VAL                        EQU       T3VAL     -T3BASE    
T_T3CON                        EQU       T3CON     -T3BASE    
T_T3CLRI                       EQU       T3CLRI    -T3BASE    

T3LD_OFFSET                    EQU       0x0360
T3VAL_OFFSET                   EQU       0x0364
T3CON_OFFSET                   EQU       0x0368
T3CLRI_OFFSET                  EQU       0x036C

; PLL AND OSCILLATOR CONTROL

PLLBASE                        EQU       0xFFFF0400
PLLSTA                         EQU       0xFFFF0400
POWKEY1                        EQU       0xFFFF0404
POWCON                         EQU       0xFFFF0408
POWKEY2                        EQU       0xFFFF040C
PLLKEY1                        EQU       0xFFFF0410
PLLCON                         EQU       0xFFFF0414
PLLKEY2                        EQU       0xFFFF0418
Z_PLLSTA                       EQU       PLLSTA    -Z_BASE
Z_POWKEY1                      EQU       POWKEY1   -Z_BASE
Z_POWCON                       EQU       POWCON    -Z_BASE
Z_POWKEY2                      EQU       POWKEY2   -Z_BASE
Z_PLLKEY1                      EQU       PLLKEY1   -Z_BASE
Z_PLLCON                       EQU       PLLCON    -Z_BASE
Z_PLLKEY2                      EQU       PLLKEY2   -Z_BASE

T_PLLSTA                       EQU       PLLSTA    -PLLBASE   
T_POWKEY1                      EQU       POWKEY1   -PLLBASE   
T_POWCON                       EQU       POWCON    -PLLBASE   
T_POWKEY2                      EQU       POWKEY2   -PLLBASE   
T_PLLKEY1                      EQU       PLLKEY1   -PLLBASE   
T_PLLCON                       EQU       PLLCON    -PLLBASE   
T_PLLKEY2                      EQU       PLLKEY2   -PLLBASE   

PLLSTA_OFFSET                  EQU       0x0400
POWKEY1_OFFSET                 EQU       0x0404
POWCON_OFFSET                  EQU       0x0408
POWKEY2_OFFSET                 EQU       0x040C
PLLKEY1_OFFSET                 EQU       0x0410
PLLCON_OFFSET                  EQU       0x0414
PLLKEY2_OFFSET                 EQU       0x0418

; POWER SUPPLY MONITOR

PSMBASE                        EQU       0xFFFF0440
PSMCON                         EQU       0xFFFF0440
CMPCON                         EQU       0xFFFF0444
Z_PSMCON                       EQU       PSMCON    -Z_BASE
Z_CMPCON                       EQU       CMPCON    -Z_BASE

T_PSMCON                       EQU       PSMCON    -PSMBASE   
T_CMPCON                       EQU       CMPCON    -PSMBASE   

PSMCON_OFFSET                  EQU       0x0440
CMPCON_OFFSET                  EQU       0x0444

; Band Gap Reference

REFBASE                        EQU       0xFFFF0480
REFCON                         EQU       0xFFFF048C
Z_REFCON                       EQU       REFCON    -Z_BASE

T_REFCON                       EQU       REFCON    -REFBASE   

REFCON_OFFSET                  EQU       0x048C

; ADC INTERFACE REGISTERS

ADCBASE                        EQU       0xFFFF0500
ADCCON                         EQU       0xFFFF0500
ADCCP                          EQU       0xFFFF0504
ADCCN                          EQU       0xFFFF0508
ADCSTA                         EQU       0xFFFF050C
ADCDAT                         EQU       0xFFFF0510
ADCRST                         EQU       0xFFFF0514
ADCGN                          EQU       0xFFFF0530
ADCOF                          EQU       0xFFFF0534
Z_ADCCON                       EQU       ADCCON    -Z_BASE
Z_ADCCP                        EQU       ADCCP     -Z_BASE
Z_ADCCN                        EQU       ADCCN     -Z_BASE
Z_ADCSTA                       EQU       ADCSTA    -Z_BASE
Z_ADCDAT                       EQU       ADCDAT    -Z_BASE
Z_ADCRST                       EQU       ADCRST    -Z_BASE
Z_ADCGN                        EQU       ADCGN     -Z_BASE
Z_ADCOF                        EQU       ADCOF     -Z_BASE

T_ADCCON                       EQU       ADCCON    -ADCBASE   
T_ADCCP                        EQU       ADCCP     -ADCBASE   
T_ADCCN                        EQU       ADCCN     -ADCBASE   
T_ADCSTA                       EQU       ADCSTA    -ADCBASE   
T_ADCDAT                       EQU       ADCDAT    -ADCBASE   
T_ADCRST                       EQU       ADCRST    -ADCBASE   
T_ADCGN                        EQU       ADCGN     -ADCBASE   
T_ADCOF                        EQU       ADCOF     -ADCBASE   

ADCCON_OFFSET                  EQU       0x0500
ADCCP_OFFSET                   EQU       0x0504
ADCCN_OFFSET                   EQU       0x0508
ADCSTA_OFFSET                  EQU       0x050C
ADCDAT_OFFSET                  EQU       0x0510
ADCRST_OFFSET                  EQU       0x0514
ADCGN_OFFSET                   EQU       0x0530
ADCOF_OFFSET                   EQU       0x0534



; EXTERNAL MEMORY REGISTERS

XMBASE                         EQU       0xFFFFF000
XMCFG                          EQU       0xFFFFF000
XM0CON                         EQU       0xFFFFF010
XM1CON                         EQU       0xFFFFF014
XM2CON                         EQU       0xFFFFF018
XM3CON                         EQU       0xFFFFF01C
XM0PAR                         EQU       0xFFFFF020
XM1PAR                         EQU       0xFFFFF024
XM2PAR                         EQU       0xFFFFF028
XM3PAR                         EQU       0xFFFFF02C
Z_XMCFG                        EQU       XMCFG     -Z_BASE
Z_XM0CON                       EQU       XM0CON    -Z_BASE
Z_XM1CON                       EQU       XM1CON    -Z_BASE
Z_XM2CON                       EQU       XM2CON    -Z_BASE
Z_XM3CON                       EQU       XM3CON    -Z_BASE
Z_XM0PAR                       EQU       XM0PAR    -Z_BASE
Z_XM1PAR                       EQU       XM1PAR    -Z_BASE
Z_XM2PAR                       EQU       XM2PAR    -Z_BASE
Z_XM3PAR                       EQU       XM3PAR    -Z_BASE

T_XMCFG                        EQU       XMCFG     -XMBASE    
T_XM0CON                       EQU       XM0CON    -XMBASE    
T_XM1CON                       EQU       XM1CON    -XMBASE    
T_XM2CON                       EQU       XM2CON    -XMBASE    
T_XM3CON                       EQU       XM3CON    -XMBASE    
T_XM0PAR                       EQU       XM0PAR    -XMBASE    
T_XM1PAR                       EQU       XM1PAR    -XMBASE    
T_XM2PAR                       EQU       XM2PAR    -XMBASE    
T_XM3PAR                       EQU       XM3PAR    -XMBASE    

XMCFG_OFFSET                   EQU       0x0000
XM0CON_OFFSET                  EQU       0x0010
XM1CON_OFFSET                  EQU       0x0014
XM2CON_OFFSET                  EQU       0x0018
XM3CON_OFFSET                  EQU       0x001C
XM0PAR_OFFSET                  EQU       0x0020
XM1PAR_OFFSET                  EQU       0x0024
XM2PAR_OFFSET                  EQU       0x0028
XM3PAR_OFFSET                  EQU       0x002C

; 450 COMPATIABLE UART CORE REGISTERS

UARTBASE                       EQU       0xFFFF0700
COMTX                          EQU       0xFFFF0700
COMRX                          EQU       0xFFFF0700
COMDIV0                        EQU       0xFFFF0700
COMIEN0                        EQU       0xFFFF0704
COMDIV1                        EQU       0xFFFF0704
COMIID0                        EQU       0xFFFF0708
COMCON0                        EQU       0xFFFF070C
COMCON1                        EQU       0xFFFF0710
COMSTA0                        EQU       0xFFFF0714
COMSTA1                        EQU       0xFFFF0718
COMSCR                         EQU       0xFFFF071C
COMIEN1                        EQU       0xFFFF0720
COMIID1                        EQU       0xFFFF0724
COMADR                         EQU       0xFFFF0728
COMDIV2                        EQU       0xFFFF072C
Z_COMTX                        EQU       COMTX     -Z_BASE
Z_COMRX                        EQU       COMRX     -Z_BASE
Z_COMDIV0                      EQU       COMDIV0   -Z_BASE
Z_COMIEN0                      EQU       COMIEN0   -Z_BASE
Z_COMDIV1                      EQU       COMDIV1   -Z_BASE
Z_COMIID0                      EQU       COMIID0   -Z_BASE
Z_COMCON0                      EQU       COMCON0   -Z_BASE
Z_COMCON1                      EQU       COMCON1   -Z_BASE
Z_COMSTA0                      EQU       COMSTA0   -Z_BASE
Z_COMSTA1                      EQU       COMSTA1   -Z_BASE
Z_COMSCR                       EQU       COMSCR    -Z_BASE
Z_COMIEN1                      EQU       COMIEN1   -Z_BASE
Z_COMIID1                      EQU       COMIID1   -Z_BASE
Z_COMADR                       EQU       COMADR    -Z_BASE
Z_COMDIV2                      EQU       COMDIV2   -Z_BASE

T_COMTX                        EQU       COMTX     -UARTBASE  
T_COMRX                        EQU       COMRX     -UARTBASE  
T_COMDIV0                      EQU       COMDIV0   -UARTBASE  
T_COMIEN0                      EQU       COMIEN0   -UARTBASE  
T_COMDIV1                      EQU       COMDIV1   -UARTBASE  
T_COMIID0                      EQU       COMIID0   -UARTBASE  
T_COMCON0                      EQU       COMCON0   -UARTBASE  
T_COMCON1                      EQU       COMCON1   -UARTBASE  
T_COMSTA0                      EQU       COMSTA0   -UARTBASE  
T_COMSTA1                      EQU       COMSTA1   -UARTBASE  
T_COMSCR                       EQU       COMSCR    -UARTBASE  
T_COMIEN1                      EQU       COMIEN1   -UARTBASE  
T_COMIID1                      EQU       COMIID1   -UARTBASE  
T_COMADR                       EQU       COMADR    -UARTBASE  
T_COMDIV2                      EQU       COMDIV2   -UARTBASE  

COMTX_OFFSET                   EQU       0x0700
COMRX_OFFSET                   EQU       0x0700
COMDIV0_OFFSET                 EQU       0x0700
COMIEN0_OFFSET                 EQU       0x0704
COMDIV1_OFFSET                 EQU       0x0704
COMIID0_OFFSET                 EQU       0x0708
COMCON0_OFFSET                 EQU       0x070C
COMCON1_OFFSET                 EQU       0x0710
COMSTA0_OFFSET                 EQU       0x0714
COMSTA1_OFFSET                 EQU       0x0718
COMSCR_OFFSET                  EQU       0x071C
COMIEN1_OFFSET                 EQU       0x0720
COMIID1_OFFSET                 EQU       0x0724
COMADR_OFFSET                  EQU       0x0728
COMDIV2_OFFSET                 EQU       0x072C

; I2C BUS PERIPHERAL DEVICE

I2CBASE                        EQU       0xFFFF0800
I2CMSTA                        EQU       0xFFFF0800
I2CSSTA                        EQU       0xFFFF0804
I2CSRX                         EQU       0xFFFF0808
I2CSTX                         EQU       0xFFFF080C
I2CMRX                         EQU       0xFFFF0810
I2CMTX                         EQU       0xFFFF0814
I2CCNT                         EQU       0xFFFF0818
I2CADR                         EQU       0xFFFF081C
I2CBYTE                        EQU       0xFFFF0824
I2CALT                         EQU       0xFFFF0828
I2CCFG                         EQU       0xFFFF082C
I2CDIV                         EQU       0xFFFF0830
I2CID0                         EQU       0xFFFF0838
I2CID1                         EQU       0xFFFF083C
I2CID2                         EQU       0xFFFF0840
I2CID3                         EQU       0xFFFF0844
I2CCCNT                        EQU       0xFFFF0848
I2CFSTA                        EQU       0xFFFF084C
Z_I2CMSTA                      EQU       I2CMSTA   -Z_BASE
Z_I2CSSTA                      EQU       I2CSSTA   -Z_BASE
Z_I2CSRX                       EQU       I2CSRX    -Z_BASE
Z_I2CSTX                       EQU       I2CSTX    -Z_BASE
Z_I2CMRX                       EQU       I2CMRX    -Z_BASE
Z_I2CMTX                       EQU       I2CMTX    -Z_BASE
Z_I2CCNT                       EQU       I2CCNT    -Z_BASE
Z_I2CADR                       EQU       I2CADR    -Z_BASE
Z_I2CBYTE                      EQU       I2CBYTE   -Z_BASE
Z_I2CALT                       EQU       I2CALT    -Z_BASE
Z_I2CCFG                       EQU       I2CCFG    -Z_BASE
Z_I2CDIV                       EQU       I2CDIV    -Z_BASE
Z_I2CID0                       EQU       I2CID0    -Z_BASE
Z_I2CID1                       EQU       I2CID1    -Z_BASE
Z_I2CID2                       EQU       I2CID2    -Z_BASE
Z_I2CID3                       EQU       I2CID3    -Z_BASE
Z_I2CCCNT                      EQU       I2CCCNT   -Z_BASE
Z_I2CFSTA                      EQU       I2CFSTA   -Z_BASE

T_I2CMSTA                      EQU       I2CMSTA   -I2CBASE   
T_I2CSSTA                      EQU       I2CSSTA   -I2CBASE   
T_I2CSRX                       EQU       I2CSRX    -I2CBASE   
T_I2CSTX                       EQU       I2CSTX    -I2CBASE   
T_I2CMRX                       EQU       I2CMRX    -I2CBASE   
T_I2CMTX                       EQU       I2CMTX    -I2CBASE   
T_I2CCNT                       EQU       I2CCNT    -I2CBASE   
T_I2CADR                       EQU       I2CADR    -I2CBASE   
T_I2CBYTE                      EQU       I2CBYTE   -I2CBASE   
T_I2CALT                       EQU       I2CALT    -I2CBASE   
T_I2CCFG                       EQU       I2CCFG    -I2CBASE   
T_I2CDIV                       EQU       I2CDIV    -I2CBASE   
T_I2CID0                       EQU       I2CID0    -I2CBASE   
T_I2CID1                       EQU       I2CID1    -I2CBASE   
T_I2CID2                       EQU       I2CID2    -I2CBASE   
T_I2CID3                       EQU       I2CID3    -I2CBASE   
T_I2CCCNT                      EQU       I2CCCNT   -I2CBASE   
T_I2CFSTA                      EQU       I2CFSTA   -I2CBASE   

I2CMSTA_OFFSET                 EQU       0x0800
I2CSSTA_OFFSET                 EQU       0x0804
I2CSRX_OFFSET                  EQU       0x0808
I2CSTX_OFFSET                  EQU       0x080C
I2CMRX_OFFSET                  EQU       0x0810
I2CMTX_OFFSET                  EQU       0x0814
I2CCNT_OFFSET                  EQU       0x0818
I2CADR_OFFSET                  EQU       0x081C
I2CBYTE_OFFSET                 EQU       0x0824
I2CALT_OFFSET                  EQU       0x0828
I2CCFG_OFFSET                  EQU       0x082C
I2CDIV_OFFSET                  EQU       0x0830
I2CID0_OFFSET                  EQU       0x0838
I2CID1_OFFSET                  EQU       0x083C
I2CID2_OFFSET                  EQU       0x0840
I2CID3_OFFSET                  EQU       0x0844
I2CCCNT_OFFSET                 EQU       0x0848
I2CFSTA_OFFSET                 EQU       0x084C

; I2C BUS PERIPHERAL DEVICE 0

I2C0BASE                       EQU       0xFFFF0800
I2C0MSTA                       EQU       0xFFFF0800
I2C0SSTA                       EQU       0xFFFF0804
I2C0SRX                        EQU       0xFFFF0808
I2C0STX                        EQU       0xFFFF080C
I2C0MRX                        EQU       0xFFFF0810
I2C0MTX                        EQU       0xFFFF0814
I2C0CNT                        EQU       0xFFFF0818
I2C0ADR                        EQU       0xFFFF081C
I2C0BYTE                       EQU       0xFFFF0824
I2C0ALT                        EQU       0xFFFF0828
I2C0CFG                        EQU       0xFFFF082C
I2C0DIV                        EQU       0xFFFF0830
I2C0ID0                        EQU       0xFFFF0838
I2C0ID1                        EQU       0xFFFF083C
I2C0ID2                        EQU       0xFFFF0840
I2C0ID3                        EQU       0xFFFF0844
I2C0CCNT                       EQU       0xFFFF0848
I2C0FSTA                       EQU       0xFFFF084C
Z_I2C0MSTA                     EQU       I2C0MSTA  -Z_BASE
Z_I2C0SSTA                     EQU       I2C0SSTA  -Z_BASE
Z_I2C0SRX                      EQU       I2C0SRX   -Z_BASE
Z_I2C0STX                      EQU       I2C0STX   -Z_BASE
Z_I2C0MRX                      EQU       I2C0MRX   -Z_BASE
Z_I2C0MTX                      EQU       I2C0MTX   -Z_BASE
Z_I2C0CNT                      EQU       I2C0CNT   -Z_BASE
Z_I2C0ADR                      EQU       I2C0ADR   -Z_BASE
Z_I2C0BYTE                     EQU       I2C0BYTE  -Z_BASE
Z_I2C0ALT                      EQU       I2C0ALT   -Z_BASE
Z_I2C0CFG                      EQU       I2C0CFG   -Z_BASE
Z_I2C0DIV                      EQU       I2C0DIV   -Z_BASE
Z_I2C0ID0                      EQU       I2C0ID0   -Z_BASE
Z_I2C0ID1                      EQU       I2C0ID1   -Z_BASE
Z_I2C0ID2                      EQU       I2C0ID2   -Z_BASE
Z_I2C0ID3                      EQU       I2C0ID3   -Z_BASE
Z_I2C0CCNT                     EQU       I2C0CCNT  -Z_BASE
Z_I2C0FSTA                     EQU       I2C0FSTA  -Z_BASE

T_I2C0MSTA                     EQU       I2C0MSTA  -I2C0BASE  
T_I2C0SSTA                     EQU       I2C0SSTA  -I2C0BASE  
T_I2C0SRX                      EQU       I2C0SRX   -I2C0BASE  
T_I2C0STX                      EQU       I2C0STX   -I2C0BASE  
T_I2C0MRX                      EQU       I2C0MRX   -I2C0BASE  
T_I2C0MTX                      EQU       I2C0MTX   -I2C0BASE  
T_I2C0CNT                      EQU       I2C0CNT   -I2C0BASE  
T_I2C0ADR                      EQU       I2C0ADR   -I2C0BASE  
T_I2C0BYTE                     EQU       I2C0BYTE  -I2C0BASE  
T_I2C0ALT                      EQU       I2C0ALT   -I2C0BASE  
T_I2C0CFG                      EQU       I2C0CFG   -I2C0BASE  
T_I2C0DIV                      EQU       I2C0DIV   -I2C0BASE  
T_I2C0ID0                      EQU       I2C0ID0   -I2C0BASE  
T_I2C0ID1                      EQU       I2C0ID1   -I2C0BASE  
T_I2C0ID2                      EQU       I2C0ID2   -I2C0BASE  
T_I2C0ID3                      EQU       I2C0ID3   -I2C0BASE  
T_I2C0CCNT                     EQU       I2C0CCNT  -I2C0BASE  
T_I2C0FSTA                     EQU       I2C0FSTA  -I2C0BASE  

I2C0MSTA_OFFSET                EQU       0x0800
I2C0SSTA_OFFSET                EQU       0x0804
I2C0SRX_OFFSET                 EQU       0x0808
I2C0STX_OFFSET                 EQU       0x080C
I2C0MRX_OFFSET                 EQU       0x0810
I2C0MTX_OFFSET                 EQU       0x0814
I2C0CNT_OFFSET                 EQU       0x0818
I2C0ADR_OFFSET                 EQU       0x081C
I2C0BYTE_OFFSET                EQU       0x0824
I2C0ALT_OFFSET                 EQU       0x0828
I2C0CFG_OFFSET                 EQU       0x082C
I2C0DIV_OFFSET                 EQU       0x0830
I2C0ID0_OFFSET                 EQU       0x0838
I2C0ID1_OFFSET                 EQU       0x083C
I2C0ID2_OFFSET                 EQU       0x0840
I2C0ID3_OFFSET                 EQU       0x0844
I2C0CCNT_OFFSET                EQU       0x0848
I2C0FSTA_OFFSET                EQU       0x084C

; I2C BUS PERIPHERAL DEVICE 1

I2C1BASE                       EQU       0xFFFF0900
I2C1MSTA                       EQU       0xFFFF0900
I2C1SSTA                       EQU       0xFFFF0904
I2C1SRX                        EQU       0xFFFF0908
I2C1STX                        EQU       0xFFFF090C
I2C1MRX                        EQU       0xFFFF0910
I2C1MTX                        EQU       0xFFFF0914
I2C1CNT                        EQU       0xFFFF0918
I2C1ADR                        EQU       0xFFFF091C
I2C1BYTE                       EQU       0xFFFF0924
I2C1ALT                        EQU       0xFFFF0928
I2C1CFG                        EQU       0xFFFF092C
I2C1DIV                        EQU       0xFFFF0930
I2C1ID0                        EQU       0xFFFF0938
I2C1ID1                        EQU       0xFFFF093C
I2C1ID2                        EQU       0xFFFF0940
I2C1ID3                        EQU       0xFFFF0944
I2C1CCNT                       EQU       0xFFFF0948
I2C1FSTA                       EQU       0xFFFF094C
Z_I2C1MSTA                     EQU       I2C1MSTA  -Z_BASE
Z_I2C1SSTA                     EQU       I2C1SSTA  -Z_BASE
Z_I2C1SRX                      EQU       I2C1SRX   -Z_BASE
Z_I2C1STX                      EQU       I2C1STX   -Z_BASE
Z_I2C1MRX                      EQU       I2C1MRX   -Z_BASE
Z_I2C1MTX                      EQU       I2C1MTX   -Z_BASE
Z_I2C1CNT                      EQU       I2C1CNT   -Z_BASE
Z_I2C1ADR                      EQU       I2C1ADR   -Z_BASE
Z_I2C1BYTE                     EQU       I2C1BYTE  -Z_BASE
Z_I2C1ALT                      EQU       I2C1ALT   -Z_BASE
Z_I2C1CFG                      EQU       I2C1CFG   -Z_BASE
Z_I2C1DIV                      EQU       I2C1DIV   -Z_BASE
Z_I2C1ID0                      EQU       I2C1ID0   -Z_BASE
Z_I2C1ID1                      EQU       I2C1ID1   -Z_BASE
Z_I2C1ID2                      EQU       I2C1ID2   -Z_BASE
Z_I2C1ID3                      EQU       I2C1ID3   -Z_BASE
Z_I2C1CCNT                     EQU       I2C1CCNT  -Z_BASE
Z_I2C1FSTA                     EQU       I2C1FSTA  -Z_BASE

T_I2C1MSTA                     EQU       I2C1MSTA  -I2C1BASE  
T_I2C1SSTA                     EQU       I2C1SSTA  -I2C1BASE  
T_I2C1SRX                      EQU       I2C1SRX   -I2C1BASE  
T_I2C1STX                      EQU       I2C1STX   -I2C1BASE  
T_I2C1MRX                      EQU       I2C1MRX   -I2C1BASE  
T_I2C1MTX                      EQU       I2C1MTX   -I2C1BASE  
T_I2C1CNT                      EQU       I2C1CNT   -I2C1BASE  
T_I2C1ADR                      EQU       I2C1ADR   -I2C1BASE  
T_I2C1BYTE                     EQU       I2C1BYTE  -I2C1BASE  
T_I2C1ALT                      EQU       I2C1ALT   -I2C1BASE  
T_I2C1CFG                      EQU       I2C1CFG   -I2C1BASE  
T_I2C1DIV                      EQU       I2C1DIV   -I2C1BASE  
T_I2C1ID0                      EQU       I2C1ID0   -I2C1BASE  
T_I2C1ID1                      EQU       I2C1ID1   -I2C1BASE  
T_I2C1ID2                      EQU       I2C1ID2   -I2C1BASE  
T_I2C1ID3                      EQU       I2C1ID3   -I2C1BASE  
T_I2C1CCNT                     EQU       I2C1CCNT  -I2C1BASE  
T_I2C1FSTA                     EQU       I2C1FSTA  -I2C1BASE  

I2C1MSTA_OFFSET                EQU       0x0900
I2C1SSTA_OFFSET                EQU       0x0904
I2C1SRX_OFFSET                 EQU       0x0908
I2C1STX_OFFSET                 EQU       0x090C
I2C1MRX_OFFSET                 EQU       0x0910
I2C1MTX_OFFSET                 EQU       0x0914
I2C1CNT_OFFSET                 EQU       0x0918
I2C1ADR_OFFSET                 EQU       0x091C
I2C1BYTE_OFFSET                EQU       0x0924
I2C1ALT_OFFSET                 EQU       0x0928
I2C1CFG_OFFSET                 EQU       0x092C
I2C1DIV_OFFSET                 EQU       0x0930
I2C1ID0_OFFSET                 EQU       0x0938
I2C1ID1_OFFSET                 EQU       0x093C
I2C1ID2_OFFSET                 EQU       0x0940
I2C1ID3_OFFSET                 EQU       0x0944
I2C1CCNT_OFFSET                EQU       0x0948
I2C1FSTA_OFFSET                EQU       0x094C

; SERIAL PORT INTERFACE PERIPHERAL

SPIBASE                        EQU       0xFFFF0A00
SPISTA                         EQU       0xFFFF0A00
SPIRX                          EQU       0xFFFF0A04
SPITX                          EQU       0xFFFF0A08
SPIDIV                         EQU       0xFFFF0A0C
SPICON                         EQU       0xFFFF0A10
Z_SPISTA                       EQU       SPISTA    -Z_BASE
Z_SPIRX                        EQU       SPIRX     -Z_BASE
Z_SPITX                        EQU       SPITX     -Z_BASE
Z_SPIDIV                       EQU       SPIDIV    -Z_BASE
Z_SPICON                       EQU       SPICON    -Z_BASE

T_SPISTA                       EQU       SPISTA    -SPIBASE   
T_SPIRX                        EQU       SPIRX     -SPIBASE   
T_SPITX                        EQU       SPITX     -SPIBASE   
T_SPIDIV                       EQU       SPIDIV    -SPIBASE   
T_SPICON                       EQU       SPICON    -SPIBASE   

SPISTA_OFFSET                  EQU       0x0A00
SPIRX_OFFSET                   EQU       0x0A04
SPITX_OFFSET                   EQU       0x0A08
SPIDIV_OFFSET                  EQU       0x0A0C
SPICON_OFFSET                  EQU       0x0A10

; PROGRAMABLE LOGIC ARRAY

PLABASE                        EQU       0xFFFF0B00
PLAELM0                        EQU       0xFFFF0B00
PLAELM1                        EQU       0xFFFF0B04
PLAELM2                        EQU       0xFFFF0B08
PLAELM3                        EQU       0xFFFF0B0C
PLAELM4                        EQU       0xFFFF0B10
PLAELM5                        EQU       0xFFFF0B14
PLAELM6                        EQU       0xFFFF0B18
PLAELM7                        EQU       0xFFFF0B1C
PLAELM8                        EQU       0xFFFF0B20
PLAELM9                        EQU       0xFFFF0B24
PLAELM10                       EQU       0xFFFF0B28
PLAELM11                       EQU       0xFFFF0B2C
PLAELM12                       EQU       0xFFFF0B30
PLAELM13                       EQU       0xFFFF0B34
PLAELM14                       EQU       0xFFFF0B38
PLAELM15                       EQU       0xFFFF0B3C
PLACLK                         EQU       0xFFFF0B40
PLAIRQ                         EQU       0xFFFF0B44
PLAADC                         EQU       0xFFFF0B48
PLADIN                         EQU       0xFFFF0B4C
PLADOUT                        EQU       0xFFFF0B50
PLALCK                         EQU       0xFFFF0B54
Z_PLAELM0                      EQU       PLAELM0   -Z_BASE
Z_PLAELM1                      EQU       PLAELM1   -Z_BASE
Z_PLAELM2                      EQU       PLAELM2   -Z_BASE
Z_PLAELM3                      EQU       PLAELM3   -Z_BASE
Z_PLAELM4                      EQU       PLAELM4   -Z_BASE
Z_PLAELM5                      EQU       PLAELM5   -Z_BASE
Z_PLAELM6                      EQU       PLAELM6   -Z_BASE
Z_PLAELM7                      EQU       PLAELM7   -Z_BASE
Z_PLAELM8                      EQU       PLAELM8   -Z_BASE
Z_PLAELM9                      EQU       PLAELM9   -Z_BASE
Z_PLAELM10                     EQU       PLAELM10  -Z_BASE
Z_PLAELM11                     EQU       PLAELM11  -Z_BASE
Z_PLAELM12                     EQU       PLAELM12  -Z_BASE
Z_PLAELM13                     EQU       PLAELM13  -Z_BASE
Z_PLAELM14                     EQU       PLAELM14  -Z_BASE
Z_PLAELM15                     EQU       PLAELM15  -Z_BASE
Z_PLACLK                       EQU       PLACLK    -Z_BASE
Z_PLAIRQ                       EQU       PLAIRQ    -Z_BASE
Z_PLAADC                       EQU       PLAADC    -Z_BASE
Z_PLADIN                       EQU       PLADIN    -Z_BASE
Z_PLADOUT                      EQU       PLADOUT   -Z_BASE
Z_PLALCK                       EQU       PLALCK    -Z_BASE

T_PLAELM0                      EQU       PLAELM0   -PLABASE   
T_PLAELM1                      EQU       PLAELM1   -PLABASE   
T_PLAELM2                      EQU       PLAELM2   -PLABASE   
T_PLAELM3                      EQU       PLAELM3   -PLABASE   
T_PLAELM4                      EQU       PLAELM4   -PLABASE   
T_PLAELM5                      EQU       PLAELM5   -PLABASE   
T_PLAELM6                      EQU       PLAELM6   -PLABASE   
T_PLAELM7                      EQU       PLAELM7   -PLABASE   
T_PLAELM8                      EQU       PLAELM8   -PLABASE   
T_PLAELM9                      EQU       PLAELM9   -PLABASE   
T_PLAELM10                     EQU       PLAELM10  -PLABASE   
T_PLAELM11                     EQU       PLAELM11  -PLABASE   
T_PLAELM12                     EQU       PLAELM12  -PLABASE   
T_PLAELM13                     EQU       PLAELM13  -PLABASE   
T_PLAELM14                     EQU       PLAELM14  -PLABASE   
T_PLAELM15                     EQU       PLAELM15  -PLABASE   
T_PLACLK                       EQU       PLACLK    -PLABASE   
T_PLAIRQ                       EQU       PLAIRQ    -PLABASE   
T_PLAADC                       EQU       PLAADC    -PLABASE   
T_PLADIN                       EQU       PLADIN    -PLABASE   
T_PLADOUT                      EQU       PLADOUT   -PLABASE   
T_PLALCK                       EQU       PLALCK    -PLABASE   

PLAELM0_OFFSET                 EQU       0x0B00
PLAELM1_OFFSET                 EQU       0x0B04
PLAELM2_OFFSET                 EQU       0x0B08
PLAELM3_OFFSET                 EQU       0x0B0C
PLAELM4_OFFSET                 EQU       0x0B10
PLAELM5_OFFSET                 EQU       0x0B14
PLAELM6_OFFSET                 EQU       0x0B18
PLAELM7_OFFSET                 EQU       0x0B1C
PLAELM8_OFFSET                 EQU       0x0B20
PLAELM9_OFFSET                 EQU       0x0B24
PLAELM10_OFFSET                EQU       0x0B28
PLAELM11_OFFSET                EQU       0x0B2C
PLAELM12_OFFSET                EQU       0x0B30
PLAELM13_OFFSET                EQU       0x0B34
PLAELM14_OFFSET                EQU       0x0B38
PLAELM15_OFFSET                EQU       0x0B3C
PLACLK_OFFSET                  EQU       0x0B40
PLAIRQ_OFFSET                  EQU       0x0B44
PLAADC_OFFSET                  EQU       0x0B48
PLADIN_OFFSET                  EQU       0x0B4C
PLADOUT_OFFSET                 EQU       0x0B50
PLALCK_OFFSET                  EQU       0x0B54

; GPIO AND SERIAL PORT MUX

GPIOBASE                       EQU       0xFFFFF400
GP0CON                         EQU       0xFFFFF400
GP1CON                         EQU       0xFFFFF404
GP2CON                         EQU       0xFFFFF408
GP3CON                         EQU       0xFFFFF40C
GP4CON                         EQU       0xFFFFF410
GP0DAT                         EQU       0xFFFFF420
GP0SET                         EQU       0xFFFFF424
GP0CLR                         EQU       0xFFFFF428
GP0PAR                         EQU       0xFFFFF42C
GP1DAT                         EQU       0xFFFFF430
GP1SET                         EQU       0xFFFFF434
GP1CLR                         EQU       0xFFFFF438
GP1PAR                         EQU       0xFFFFF43C
GP2DAT                         EQU       0xFFFFF440
GP2SET                         EQU       0xFFFFF444
GP2CLR                         EQU       0xFFFFF448
GP3DAT                         EQU       0xFFFFF450
GP3SET                         EQU       0xFFFFF454
GP3CLR                         EQU       0xFFFFF458
GP3PAR                         EQU       0xFFFFF45C
GP4DAT                         EQU       0xFFFFF460
GP4SET                         EQU       0xFFFFF464
GP4CLR                         EQU       0xFFFFF468
Z_GP0CON                       EQU       GP0CON    -Z_BASE
Z_GP1CON                       EQU       GP1CON    -Z_BASE
Z_GP2CON                       EQU       GP2CON    -Z_BASE
Z_GP3CON                       EQU       GP3CON    -Z_BASE
Z_GP4CON                       EQU       GP4CON    -Z_BASE
Z_GP0DAT                       EQU       GP0DAT    -Z_BASE
Z_GP0SET                       EQU       GP0SET    -Z_BASE
Z_GP0CLR                       EQU       GP0CLR    -Z_BASE
Z_GP0PAR                       EQU       GP0PAR    -Z_BASE
Z_GP1DAT                       EQU       GP1DAT    -Z_BASE
Z_GP1SET                       EQU       GP1SET    -Z_BASE
Z_GP1CLR                       EQU       GP1CLR    -Z_BASE
Z_GP1PAR                       EQU       GP1PAR    -Z_BASE
Z_GP2DAT                       EQU       GP2DAT    -Z_BASE
Z_GP2SET                       EQU       GP2SET    -Z_BASE
Z_GP2CLR                       EQU       GP2CLR    -Z_BASE
Z_GP3DAT                       EQU       GP3DAT    -Z_BASE
Z_GP3SET                       EQU       GP3SET    -Z_BASE
Z_GP3CLR                       EQU       GP3CLR    -Z_BASE
Z_GP3PAR                       EQU       GP3PAR    -Z_BASE
Z_GP4DAT                       EQU       GP4DAT    -Z_BASE
Z_GP4SET                       EQU       GP4SET    -Z_BASE
Z_GP4CLR                       EQU       GP4CLR    -Z_BASE

T_GP0CON                       EQU       GP0CON    -GPIOBASE  
T_GP1CON                       EQU       GP1CON    -GPIOBASE  
T_GP2CON                       EQU       GP2CON    -GPIOBASE  
T_GP3CON                       EQU       GP3CON    -GPIOBASE  
T_GP4CON                       EQU       GP4CON    -GPIOBASE  
T_GP0DAT                       EQU       GP0DAT    -GPIOBASE  
T_GP0SET                       EQU       GP0SET    -GPIOBASE  
T_GP0CLR                       EQU       GP0CLR    -GPIOBASE  
T_GP0PAR                       EQU       GP0PAR    -GPIOBASE  
T_GP1DAT                       EQU       GP1DAT    -GPIOBASE  
T_GP1SET                       EQU       GP1SET    -GPIOBASE  
T_GP1CLR                       EQU       GP1CLR    -GPIOBASE  
T_GP1PAR                       EQU       GP1PAR    -GPIOBASE  
T_GP2DAT                       EQU       GP2DAT    -GPIOBASE  
T_GP2SET                       EQU       GP2SET    -GPIOBASE  
T_GP2CLR                       EQU       GP2CLR    -GPIOBASE  
T_GP3DAT                       EQU       GP3DAT    -GPIOBASE  
T_GP3SET                       EQU       GP3SET    -GPIOBASE  
T_GP3CLR                       EQU       GP3CLR    -GPIOBASE  
T_GP3PAR                       EQU       GP3PAR    -GPIOBASE  
T_GP4DAT                       EQU       GP4DAT    -GPIOBASE  
T_GP4SET                       EQU       GP4SET    -GPIOBASE  
T_GP4CLR                       EQU       GP4CLR    -GPIOBASE  

GP0CON_OFFSET                  EQU       0x0400
GP1CON_OFFSET                  EQU       0x0404
GP2CON_OFFSET                  EQU       0x0408
GP3CON_OFFSET                  EQU       0x040C
GP4CON_OFFSET                  EQU       0x0410
GP0DAT_OFFSET                  EQU       0x0420
GP0SET_OFFSET                  EQU       0x0424
GP0CLR_OFFSET                  EQU       0x0428
GP0PAR_OFFSET                  EQU       0x042C
GP1DAT_OFFSET                  EQU       0x0430
GP1SET_OFFSET                  EQU       0x0434
GP1CLR_OFFSET                  EQU       0x0438
GP1PAR_OFFSET                  EQU       0x043C
GP2DAT_OFFSET                  EQU       0x0440
GP2SET_OFFSET                  EQU       0x0444
GP2CLR_OFFSET                  EQU       0x0448
GP3DAT_OFFSET                  EQU       0x0450
GP3SET_OFFSET                  EQU       0x0454
GP3CLR_OFFSET                  EQU       0x0458
GP3PAR_OFFSET                  EQU       0x045C
GP4DAT_OFFSET                  EQU       0x0460
GP4SET_OFFSET                  EQU       0x0464
GP4CLR_OFFSET                  EQU       0x0468

; FLASH CONTROL INTERFACE

FLASHBASE                      EQU       0xFFFFF800
FEESTA                         EQU       0xFFFFF800
FEEMOD                         EQU       0xFFFFF804
FEECON                         EQU       0xFFFFF808
FEEDAT                         EQU       0xFFFFF80C
FEEADR                         EQU       0xFFFFF810
FEESIGN                        EQU       0xFFFFF818
FEEPRO                         EQU       0xFFFFF81C
FEEHIDE                        EQU       0xFFFFF820
Z_FEESTA                       EQU       FEESTA    -Z_BASE
Z_FEEMOD                       EQU       FEEMOD    -Z_BASE
Z_FEECON                       EQU       FEECON    -Z_BASE
Z_FEEDAT                       EQU       FEEDAT    -Z_BASE
Z_FEEADR                       EQU       FEEADR    -Z_BASE
Z_FEESIGN                      EQU       FEESIGN   -Z_BASE
Z_FEEPRO                       EQU       FEEPRO    -Z_BASE
Z_FEEHIDE                      EQU       FEEHIDE   -Z_BASE

T_FEESTA                       EQU       FEESTA    -FLASHBASE 
T_FEEMOD                       EQU       FEEMOD    -FLASHBASE 
T_FEECON                       EQU       FEECON    -FLASHBASE 
T_FEEDAT                       EQU       FEEDAT    -FLASHBASE 
T_FEEADR                       EQU       FEEADR    -FLASHBASE 
T_FEESIGN                      EQU       FEESIGN   -FLASHBASE 
T_FEEPRO                       EQU       FEEPRO    -FLASHBASE 
T_FEEHIDE                      EQU       FEEHIDE   -FLASHBASE 

FEESTA_OFFSET                  EQU       0x0800
FEEMOD_OFFSET                  EQU       0x0804
FEECON_OFFSET                  EQU       0x0808
FEEDAT_OFFSET                  EQU       0x080C
FEEADR_OFFSET                  EQU       0x0810
FEESIGN_OFFSET                 EQU       0x0818
FEEPRO_OFFSET                  EQU       0x081C
FEEHIDE_OFFSET                 EQU       0x0820

; PWM

PWMBASE                        EQU       0xFFFFFC00
PWMCON                         EQU       0xFFFFFC00
PWMSTA                         EQU       0xFFFFFC04
PWMDAT0                        EQU       0xFFFFFC08
PWMDAT1                        EQU       0xFFFFFC0C
PWMCFG                         EQU       0xFFFFFC10
PWMCH0                         EQU       0xFFFFFC14
PWMCH1                         EQU       0xFFFFFC18
PWMCH2                         EQU       0xFFFFFC1C
PWMEN                          EQU       0xFFFFFC20
PWMDAT2                        EQU       0xFFFFFC24
Z_PWMCON                       EQU       PWMCON    -Z_BASE
Z_PWMSTA                       EQU       PWMSTA    -Z_BASE
Z_PWMDAT0                      EQU       PWMDAT0   -Z_BASE
Z_PWMDAT1                      EQU       PWMDAT1   -Z_BASE
Z_PWMCFG                       EQU       PWMCFG    -Z_BASE
Z_PWMCH0                       EQU       PWMCH0    -Z_BASE
Z_PWMCH1                       EQU       PWMCH1    -Z_BASE
Z_PWMCH2                       EQU       PWMCH2    -Z_BASE
Z_PWMEN                        EQU       PWMEN     -Z_BASE
Z_PWMDAT2                      EQU       PWMDAT2   -Z_BASE

T_PWMCON                       EQU       PWMCON    -PWMBASE   
T_PWMSTA                       EQU       PWMSTA    -PWMBASE   
T_PWMDAT0                      EQU       PWMDAT0   -PWMBASE   
T_PWMDAT1                      EQU       PWMDAT1   -PWMBASE   
T_PWMCFG                       EQU       PWMCFG    -PWMBASE   
T_PWMCH0                       EQU       PWMCH0    -PWMBASE   
T_PWMCH1                       EQU       PWMCH1    -PWMBASE   
T_PWMCH2                       EQU       PWMCH2    -PWMBASE   
T_PWMEN                        EQU       PWMEN     -PWMBASE   
T_PWMDAT2                      EQU       PWMDAT2   -PWMBASE   

PWMCON_OFFSET                  EQU       0x0C00
PWMSTA_OFFSET                  EQU       0x0C04
PWMDAT0_OFFSET                 EQU       0x0C08
PWMDAT1_OFFSET                 EQU       0x0C0C
PWMCFG_OFFSET                  EQU       0x0C10
PWMCH0_OFFSET                  EQU       0x0C14
PWMCH1_OFFSET                  EQU       0x0C18
PWMCH2_OFFSET                  EQU       0x0C1C
PWMEN_OFFSET                   EQU       0x0C20
PWMDAT2_OFFSET                 EQU       0x0C24

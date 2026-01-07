Stack   EQU     96

        AREA    STACK, NOINIT, READWRITE, ALIGN=3
StackMem
        SPACE   Stack

        ALIGN

        PRESERVE8
        AREA Init, CODE, READONLY
        THUMB

        EXPORT  __main
        EXPORT  exit
        EXPORT  _main

Vectors
        DCD     StackMem + Stack            ; Top of Stack
        DCD     __main                      ; Reset vector
        DCD     dummyHandler                ; NMI
        DCD     dummyHandler                ; Hard Fault
        DCD     dummyHandler                ; MPU Fault
        DCD     dummyHandler                ; Bus Fault
        DCD     dummyHandler                ; Usage Fault
        DCD     dummyHandler                ; Reserved
        DCD     dummyHandler                ; Reserved
        DCD     dummyHandler                ; Reserved
        DCD     dummyHandler                ; Reserved
        DCD     dummyHandler                ; SVC
        DCD     dummyHandler                ; Debug Monitor
        DCD     dummyHandler                ; Reserved
        DCD     dummyHandler                ; PendSV
        DCD     dummyHandler                ; SysTick

dummyHandler
        B       dummyHandler

__main
_main                                   ; This symbol prevents linking default startup

        ENTRY                           ; Entry point for the application
        EXPORT  Entry
Entry

; Initialize memory required by C code

        IMPORT  |Image$$ER_IROM1$$RO$$Limit|      ; End of ROM code (=start of ROM data)
        IMPORT  |Image$$RW_IRAM1$$RW$$Base|       ; Base of RAM to initialize
        IMPORT  |Image$$RW_IRAM1$$ZI$$Base|       ; Base and limit of area
        IMPORT  |Image$$RW_IRAM1$$ZI$$Limit|      ; to zero initialize

        LDR     r0, =|Image$$ER_IROM1$$RO$$Limit| ; Get pointer to ROM data
        LDR     r1, =|Image$$RW_IRAM1$$RW$$Base|  ; and RAM copy
        LDR     r3, =|Image$$RW_IRAM1$$ZI$$Base|  ; Zero init base => top of initialized data
        CMP     r0, r1                  ; Check that they are different
        BEQ     %F1
0       CMP     r1, r3                  ; Copy init data
        LDRCC   r2, [r0], #4
        STRCC   r2, [r1], #4
        BCC     %B0
1       LDR     r1, =|Image$$RW_IRAM1$$ZI$$Limit| ; Top of zero init segment
        MOV     r2, #0
2       CMP     r3, r1                  ; Zero init
        STRCC   r2, [r3], #4
        BCC     %B2

; Enter the C code

        LDR     SP, =StackMem + Stack            ; Set SP explicit in case the program does not start from POR.

        ; Enter the C code
        IMPORT  main
        BL      main

exit    B       exit

        ALIGN

        END

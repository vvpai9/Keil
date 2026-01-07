                  PRESERVE8

                  AREA    PSA, CODE, READONLY
                  ARM

                  EXPORT  __Flash_API_Version_U16

__Flash_API_Version_U16
        MOV R0,#con0
        MOV       PC,LR

con0    EQU 0x0031

        END

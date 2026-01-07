@echo off
set x=%~dp0
set x=%x:~0,-1%
@if /I "%PROCESSOR_ARCHITECTURE%" == "AMD64" (
     "%~dp0/DPInst_x64.exe" /LM /PATH "%x%/x64"
) else if /I "%PROCESSOR_ARCHITECTURE%" == "X86" (
    @if /I "%PROCESSOR_ARCHITEW6432%" == "AMD64" (
         "%~dp0/DPInst_x64.exe" /LM /PATH "%x%/x64"
        ) else (
         "%~dp0/DPInst_x86.exe" /LM /PATH "%x%/x86"
    )
)

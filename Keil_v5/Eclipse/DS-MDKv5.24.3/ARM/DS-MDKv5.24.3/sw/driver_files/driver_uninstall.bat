@echo off
set x=%~dp0
set x=%x:~0,-1%
@if /I "%PROCESSOR_ARCHITECTURE%" == "AMD64" (
     "%~dp0/DPInst_x64.exe" /S /U  "%x%/x64/arm_rvi_usb.inf"
     "%~dp0/DPInst_x64.exe" /S /U  "%x%/x64/arm_dstream_trace_usb.inf"
     "%~dp0/DPInst_x64.exe" /S /U  "%x%/x64/arm_dstream_usb.inf"
     "%~dp0/DPInst_x64.exe" /S /U  "%x%/x64/keilulx.inf"
) else if /I "%PROCESSOR_ARCHITECTURE%" == "X86" (
    @if /I "%PROCESSOR_ARCHITEW6432%" == "AMD64" (
         "%~dp0/DPInst_x64.exe" /S /U  "%x%/x64/arm_rvi_usb.inf"
         "%~dp0/DPInst_x64.exe" /S /U  "%x%/x64/arm_dstream_trace_usb.inf"
         "%~dp0/DPInst_x64.exe" /S /U  "%x%/x64/arm_dstream_usb.inf"
         "%~dp0/DPInst_x64.exe" /S /U  "%x%/x64/keilulx.inf"
        ) else (
         "%~dp0/DPInst_x86.exe" /S /U  "%x%/x86/arm_rvi_usb.inf"
         "%~dp0/DPInst_x86.exe" /S /U  "%x%/x86/arm_dstream_trace_usb.inf"
         "%~dp0/DPInst_x86.exe" /S /U  "%x%/x86/arm_dstream_usb.inf"
         "%~dp0/DPInst_x86.exe" /S /U  "%x%/x86/keilulx.inf"
    )
)

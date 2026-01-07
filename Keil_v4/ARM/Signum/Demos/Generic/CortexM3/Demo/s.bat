@echo off

rem Save original path
if "%PATH0%" == "" set PATH0=%PATH%

rem Set directory with Keil UV3 installation

set _COMP=%1
@rem old: if "%_COMP%" == "" set _COMP=C:\tools\KeilMDK3.20\ARM\BIN31
if "%_COMP%" == "" set _COMP=C:\tools\KeilMDK3.24\ARM\BIN31

if not exist %_COMP%\armcc.exe goto error

rem Add it to path
PATH=%_COMP%;%PATH0%

echo Compiler armcc.exe available for use.

goto exit
:error

echo armcc.exe do not exist in %_COMP% directory.

:exit
set _COM=

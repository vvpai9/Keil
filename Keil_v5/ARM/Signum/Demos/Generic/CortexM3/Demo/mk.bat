@rem Compiled with:ARM/Thumb C/C++ Compiler, RVCT3.1 [Build 939] for uVision [Standard]
@rem It is taken from Keil MDK 3.24
@rem ** NOTE ** Code is same as compiled by uV3 GUI, but AXF files are different,
@rem            since -I options are not used

@if exist *.o   del *.o
@if exist *.axf del *.axf
@if exist *.stf del *.stf
@if exist *.idb del *.idb
@if exist *.dep del *.dep
@if exist *.plg del *.plg

armasm --device DLM -g --apcs=interwork                                      init.s
armcc -c -g -O0 --device DLM --apcs=interwork --signed_chars     %PARAMS%    demo.c
armcc -c -g -O0 --device DLM --apcs=interwork --signed_chars     %PARAMS%    delayfun.c
armcc -c -g -O0 --device DLM --apcs=interwork --signed_chars     %PARAMS%    led.c

armlink init.o demo.o delayfun.o led.o --device DLM --scatter Demo_0.sct        -o Demo_0.axf 
armlink init.o demo.o delayfun.o led.o --device DLM --scatter Demo_08000000.sct -o Demo_08000000.axf 
armlink init.o demo.o delayfun.o led.o --device DLM --scatter Demo_20000000.sct -o Demo_20000000.axf 
armlink init.o demo.o delayfun.o led.o --device DLM --scatter Demo_0_08000000.sct -o Demo_0_08000000.axf 
armlink init.o demo.o delayfun.o led.o --device DLM --scatter Demo_0_20000000.sct -o Demo_0_20000000.axf 
armlink init.o demo.o delayfun.o led.o --device DLM --scatter Demo_08000000_20000000.sct -o Demo_08000000_20000000.axf 

@if exist *.o   del *.o
@if exist *.dep del *.dep
@if exist *.plg del *.plg
dir *.axf

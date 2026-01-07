ECHO OFF
ECHO Generating HEX-386 with Wave Blocks...
cd AudioData
del Audio.h86
BIN2HEX /L65536 /O65536 /4 /T /Q     Block1.wav Audio.h86
BIN2HEX /L65536 /O131072 /4 /A /T /Q Block2.wav Audio.h86
BIN2HEX /L65536 /O196608 /4 /A /T /Q Block3.wav Audio.h86
BIN2HEX /L65536 /O262144 /4 /A /T /Q Block4.wav Audio.h86
BIN2HEX /L65536 /O327680 /4 /A /T /Q Block5.wav Audio.h86
BIN2HEX /L65536 /O393216 /4 /A /T /Q Block6.wav Audio.h86
BIN2HEX /L53248 /O458752 /4 /A /Q    Block7.wav Audio.h86

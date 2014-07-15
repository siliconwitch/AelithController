:: Using this make.bat from Sublime text 2. Create a new build with:
:: {
::		"cmd": "$project_path/_make.bat",
::		"working_dir": "$project_path"
:: }

:: Clear out the output folder
del /Q /F output\*

:: Compile our source and headers. Various options enabled here
arm-none-eabi-gcc -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wall -Wno-unused-function -ffunction-sections -g -O0 -c -DSTM32F405RG -DSTM32F4XX -D__FPU_USED -DUSE_STDPERIPH_DRIVER -D__ASSEMBLY__ ^
-Isource\application\include ^
-Isource\cmsis ^
-Isource\boot ^
-Isource\stdlibs\include ^
-I..\Controller\fuzzyController_ert_rtw ^
source\application\source\*.c ^
source\boot\*.c ^
source\stdlibs\source\*.c ^
..\Controller\fuzzyController_ert_rtw\*.c

:: Move all out object files to the output folder where we'll do linking
move *.o output

:: Link our object files, note various options like -lm to link math libs
arm-none-eabi-gcc -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -g -nostartfiles -Wl,-Map=output\output.map -O0 -Wl,--gc-sections -Lsource -Wl,-Tsource/arm-gcc-link.ld -g -o output\output.elf output\*.o -lm

:: Make a hex file from our elf output
arm-none-eabi-objcopy -O ihex output\output.elf "output\output.hex"

:: Fire up the st-link tool and upload our .hex file
ST-LINK_CLI -c -Q -P "output\output.hex" -V "while_programming" -Run

:: start the GDB server and link to our elf file
start st-util
start arm-none-eabi-gdb output\output.elf -ex "target extended-remote localhost:4242"
:: Using this make.bat from Sublime text 2. Create a new build with:
:: {
::		"cmd": "$project_path/_make.bat",
::		"working_dir": "$project_path"
:: }

del /Q /F output\*

arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Wall -ffunction-sections -g -O0 -c -DSTM32F407VG -DSTM32F4XX -DUSE_STDPERIPH_DRIVER -D__ASSEMBLY__ ^
-Isource\application\include ^
-Isource\cmsis ^
-Isource\boot ^
-Isource\stdlibs\include ^
source\application\source\*.c ^
source\boot\*.c ^
source\stdlibs\source\*.c


move *.o output

arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -g -nostartfiles -Wl,-Map=output\output.map -O0 -Wl,--gc-sections -Lconfigs -Wl,-Tsource\arm-gcc-link.ld -g -o output\output.elf output\*

arm-none-eabi-objcopy -O ihex output\output.elf "output\output.hex"

ST-LINK_CLI -c -Q -P "output\output.hex" -V "while_programming" -Run

start st-util
start arm-none-eabi-gdb output\output.elf -ex "target extended-remote localhost:4242"
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F411VETx -DSTM32F411E_DISCO 
CFLAGS += -DDEBUG -DSTM32F411xE -DUSE_STDPERIPH_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP

LFLAGS = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T"LinkerScript.ld" -Wl,-Map=out.map -Wl,--gc-section -g

help:
	@echo -ARM PROGRAMMING-

all:
	$(CC) $(CFLAGS) main.c
	$(CC) $(CFLAGS) startup.s
	$(LD) $(LFLAGS) -o out.elf main.o startup.o
	$(OBJCOPY) -O binary out.elf out.bin
	arm-none-eabi-objdump -d -S out.elf > out_dis.s

bin:
	$(OBJCOPY) -O binary "out.elf" "out.bin"

boot_for_debug:	
	qemu-system-gnuarmeclipse --verbose --verbose --board STM32F4-Discovery --mcu STM32F407VG --gdb tcp::51234 -d unimp,guest_errors --semihosting-config enable=on,target=native --semihosting-cmdline out		

clean:
	rm -rf *.o *.bin *.elf *.swp *.~

SHELL = /bin/sh
CC = i686-elf-gcc
AS = i686-elf-as
GRUB_CHECK = grub-file --is-x86-multiboot
QEMU = qemu-system-x86_64 -kernel
CFLAGS = -c -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -ffreestanding -O2 -nostdlib
CRTBEGIN_OBJ = $(shell $(CC) $(CFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ = $(shell $(CC) $(CFLAGS) -print-file-name=crtend.o)
LIBS = -lgcc
BUILD = build/
SRC = src/

csrc = $(wildcard $(SRC)*.c)
asmsrc = $(wildcard $(SRC)*.s)
_obj = $(csrc:.c=.o) $(asmsrc:.s=.o)
obj = $(patsubst $(SRC)%,$(BUILD)%,$(_obj))
OBJ_LINK_LIST = $(obj) $(CRTBEGIN_OBJ) $(CRTEND_OBJ)

$(BUILD)%.o: $(SRC)%.s
	$(AS) -o $@ $<

$(BUILD)%.o: $(SRC)%.c
	$(CC) -o $@ $< $(CFLAGS)

$(BUILD)os.bin: linker.ld $(OBJ_LINK_LIST)
	$(CC) -T $^ -o $@ $(LDFLAGS) $(LIBS)

all: $(BUILD)os.bin

run: $(BUILD)os.bin
	$(GRUB_CHECK) $< && $(QEMU) $<

$(shell mkdir -p build)

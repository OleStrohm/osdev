#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

extern "C" void outb(unsigned char, unsigned char);

extern "C" void enablePIT() {
	printf("Enabling PIT\n");
	outb(0x43, 0x34); // pit 0: binary-based rate generator 0b00 11 010 0 = 0x34
	uint16_t reload_value = 11931;
	outb(0x40, reload_value & 0xFF);
	outb(0x40, (reload_value >> 8) & 0xFF);
}

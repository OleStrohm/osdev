#include <kernel/interrupt.h>
#include <stdio.h>

int counter = 100;
int seconds = 0;

void irq0_handler(void) {
	if (!--counter) {
		printf("seconds: %i\n", seconds++);
		counter = 100;
	}
	outb(0x20, 0x20); //EOI
}

void irq1_handler(void) {
	extern unsigned char inb(unsigned char);
	unsigned char scan_code = inb(0x60);
	printf("Scan code: %i\n", scan_code);
	outb(0x20, 0x20); //EOI
}

void irq2_handler(void) {
	outb(0x20, 0x20); //EOI
}

void irq3_handler(void) {
	outb(0x20, 0x20); //EOI
}

void irq4_handler(void) {
	outb(0x20, 0x20); //EOI
}

void irq5_handler(void) {
	outb(0x20, 0x20); //EOI
}

void irq6_handler(void) {
	outb(0x20, 0x20); //EOI
}

void irq7_handler(void) {
	outb(0x20, 0x20); //EOI
}

void irq8_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI          
}

void irq9_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

void irq10_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

void irq11_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

void irq12_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

void irq13_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

void irq14_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

void irq15_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

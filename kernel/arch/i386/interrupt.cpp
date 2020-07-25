#include <kernel/interrupt.h>
#include <stdio.h>
#include <kernel/keyboard.h>

int counter = 100;
int seconds = 0;

extern "C" void irq0_handler() {
	if (!--counter) {
		//printf("seconds: %i\n", seconds++);
		counter = 100;
	}
	outb(0x20, 0x20); //EOI
}

extern "C" void irq1_handler(void) {
	keyboard_interrupt();
	outb(0x20, 0x20); //EOI
}

extern "C" void irq2_handler(void) {
	outb(0x20, 0x20); //EOI
}

extern "C" void irq3_handler(void) {
	outb(0x20, 0x20); //EOI
}

extern "C" void irq4_handler(void) {
	outb(0x20, 0x20); //EOI
}

extern "C" void irq5_handler(void) {
	outb(0x20, 0x20); //EOI
}

extern "C" void irq6_handler(void) {
	outb(0x20, 0x20); //EOI
}

extern "C" void irq7_handler(void) {
	outb(0x20, 0x20); //EOI
}

extern "C" void irq8_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI          
}

extern "C" void irq9_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

extern "C" void irq10_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

extern "C" void irq11_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

extern "C" void irq12_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

extern "C" void irq13_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

extern "C" void irq14_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

extern "C" void irq15_handler(void) {
	outb(0xA0, 0x20);
	outb(0x20, 0x20); //EOI
}

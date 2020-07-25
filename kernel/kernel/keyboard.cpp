#include <kernel/keyboard.h>
#include <stdio.h>

bool isDown(enum Key key) {
	return key == S;
}

void keyboard_interrupt() {
	extern unsigned char inb(unsigned char);
	unsigned char scan_code = inb(0x60);
	printf("Scan code: %i\n", scan_code);
}

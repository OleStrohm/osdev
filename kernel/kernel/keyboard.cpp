#include <kernel/keyboard.h>
#include <stdio.h>

bool isDown(Key key) {
	return key == S;
}

void keyboard_interrupt() {
	unsigned char scan_code = inb(0x60);
	printf("Scan code: %i\n", scan_code);
}

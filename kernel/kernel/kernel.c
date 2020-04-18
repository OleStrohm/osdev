#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) {
	printf("Hello, kernel World!\n");
	printf("This one scrolls A lot\n");
	printf("%i is a number\n", 123456789);
	printf("%X is a hex number\n", 0x123ABC);

	for (;;) {
		asm("hlt");
	}
}

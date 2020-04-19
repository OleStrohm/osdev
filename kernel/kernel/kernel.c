#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) {
	printf("\nEntered kernel\n");

	for(;;)
		asm("hlt");

	printf("Exiting Kernel\n");
}

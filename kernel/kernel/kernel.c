#include <stdio.h>
#include <kernel/tty.h>
#include <kernel/keyboard.h>

struct Fig {
	int x;
	int y;
};

void kernel_main(void) {
	printf("yeeehhh\n");
	struct Fig r = {4, 7};
	printf("x: %i", r.x);

	if(isDown(S)) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	printf("\n");
	for(;;)
		asm("hlt");

}

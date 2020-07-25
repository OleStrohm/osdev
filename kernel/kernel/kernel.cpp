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
	printf("fig: %ix%i", r.x, r.y);

	printf("\n");
	while(1) {
		if(isDown(S)) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
}

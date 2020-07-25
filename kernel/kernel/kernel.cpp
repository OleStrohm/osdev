#include <stdio.h>
#include <kernel/tty.h>
#include <kernel/keyboard.h>

struct Fig {
	int x;
	int y;
};

extern "C" void kernel_main(void);

void kernel_main(void) {
	printf("Started DevOS\n");

	struct Fig r = { 4, 7 };
	printf("Figure struct: %ix%i\n", r.x, r.y);

	printf("\n");
	while(1) {
		if(isDown(Key::S)) {
			printf("yaaaas\n");
		} else {
			printf("no\n");
		}
	}
}

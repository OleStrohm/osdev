#include <kernel/gdt.h>

extern void reloadSegments();
extern void setGdt(uint8_t *gdt, uint16_t size);

void setupGDT(void) {
	uint32_t gdt[] = {
		0x00000000, 0x00000000, 
		0x0000FFFF, 0x00CF9A00, 
		0x0000FFFF, 0x00CF9200, 
		0x0000FFFF, 0x00CFFA00, 
		0x0000FFFF, 0x00CFF200, 
	};
	setGdt((uint8_t*)gdt, sizeof(gdt));
	reloadSegments();
}

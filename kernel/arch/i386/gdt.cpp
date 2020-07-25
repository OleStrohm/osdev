#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define ACCESS_RW 2
#define ACCESS_DC 4
#define ACCESS_EXECUTABLE 8
#define ACCESS_RING0 0
#define ACCESS_RING1 16
#define ACCESS_RING2 32
#define ACCESS_RING3 48
#define ACCESS_PRESENT 128

#define FLAG_32BIT 64
#define FLAG_PAGEGRAN 128

#define GDT_ENTRIES 5

extern "C" void reloadSegments();
extern "C" void setGdt(uint32_t desc);

typedef struct
{
	uint16_t limit_lo;
	uint16_t base_lo;
	uint8_t base_mid;
	uint8_t access;
	uint8_t flags;
	uint8_t base_hi;
} __attribute__((packed)) GDT_Entry;

typedef struct
{
	uint16_t limit;
	uint32_t base;
} __attribute__((packed)) GDT_Descriptor;

static GDT_Entry GDT[GDT_ENTRIES];

void registerEntry(uint8_t i, uint32_t limit, uint32_t base, uint8_t access, uint8_t flags)
{
	GDT[i].limit_lo = limit & 0xFFFF;
	GDT[i].base_lo = base & 0xFFFF;
	GDT[i].base_mid = (base >> 16) & 0xFF;
	GDT[i].base_hi = (base >> 24) & 0xFF;
	GDT[i].access = access | 0x10;

	GDT[i].flags = (limit >> 16) & 0x0F;
	GDT[i].flags |= flags & 0xF0;
}

extern "C" void setupGDT(void) {
	printf("Setting up GDT\n");
	/*uint32_t GDT[] = {
	  0x00000000, 0x00000000, 
	  0x0000FFFF, 0x00CF9A00, 
	  0x0000FFFF, 0x00CF9200, 
	  0x0000FFFF, 0x00CFFA00, 
	  0x0000FFFF, 0x00CFF200, 
	  }; */
	registerEntry(0, 0, 0, 0, 0);
	registerEntry(1, (uint32_t) 0xFFFF, 0, ACCESS_PRESENT | ACCESS_RING0 | ACCESS_EXECUTABLE | ACCESS_RW, FLAG_32BIT | FLAG_PAGEGRAN);
	registerEntry(2, (uint32_t) 0xFFFF, 0, ACCESS_PRESENT | ACCESS_RING0 | ACCESS_RW, FLAG_32BIT | FLAG_PAGEGRAN);
	registerEntry(3, (uint32_t) 0xFFFF, 0, ACCESS_PRESENT | ACCESS_RING3 | ACCESS_EXECUTABLE | ACCESS_RW, FLAG_32BIT | FLAG_PAGEGRAN);
	registerEntry(4, (uint32_t) 0xFFFF, 0, ACCESS_PRESENT | ACCESS_RING3 | ACCESS_RW, FLAG_32BIT | FLAG_PAGEGRAN);

	GDT_Descriptor desc = { .limit = sizeof(GDT) - 1, .base = (uint32_t) GDT};
	printf("GDT: %X, %i\n", desc.base, desc.limit);
	setGdt((uint32_t) &desc);
	reloadSegments();
}

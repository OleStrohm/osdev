#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

extern "C" void outb(uint8_t, uint8_t);
extern "C" int load_idt(uint32_t);

extern "C" int ex0();
extern "C" int ex1();
extern "C" int ex2();
extern "C" int ex3();
extern "C" int ex4();
extern "C" int ex5();
extern "C" int ex6();
extern "C" int ex7();
extern "C" int ex8();
extern "C" int ex9();
extern "C" int ex10();
extern "C" int ex11();
extern "C" int ex12();
extern "C" int ex13();
extern "C" int ex14();
extern "C" int ex15();
extern "C" int ex16();
extern "C" int ex17();
extern "C" int ex18();
extern "C" int ex19();
extern "C" int ex20();
extern "C" int ex21();
extern "C" int ex22();
extern "C" int ex23();
extern "C" int ex24();
extern "C" int ex25();
extern "C" int ex26();
extern "C" int ex27();
extern "C" int ex28();
extern "C" int ex29();
extern "C" int ex30();
extern "C" int ex31();
extern "C" int irq0();
extern "C" int irq1();
extern "C" int irq2();
extern "C" int irq3();
extern "C" int irq4();
extern "C" int irq5();
extern "C" int irq6();
extern "C" int irq7();
extern "C" int irq8();
extern "C" int irq9();
extern "C" int irq10();
extern "C" int irq11();
extern "C" int irq12();
extern "C" int irq13();
extern "C" int irq14();
extern "C" int irq15();

struct __attribute__((__packed__)) IDT_entry{
	uint16_t offset_lowerbits;
	uint16_t selector;
	uint8_t zero;
	uint8_t type_attr;
	uint16_t offset_higherbits;
};

struct IDT_entry IDT[256];

struct __attribute__((__packed__)) IDT_header {
	uint16_t size;
	uint32_t offset;
};

void registerGateInterrupt(uint8_t interrupt, uint32_t base, uint16_t selector) {
	IDT[interrupt].offset_lowerbits = base & 0xffff;
	IDT[interrupt].selector = selector; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[interrupt].zero = 0;
	IDT[interrupt].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[interrupt].offset_higherbits = (base & 0xffff0000) >> 16;
}

extern "C" void idt_init(void) {
	printf("Setting up IDT\n");

	/* Null out all interrupts */
	memset(IDT, 0, sizeof(IDT));

	/* Remapping the PIC */
	/* 0x20 - master command
	 * 0x21 - master data
	 * 0xA0 - slave command
	 * 0xA1 - slave data */
	outb(0x20, 0x11); // Initialize master PIC
	outb(0xA0, 0x11); // Initialize slave PIC
	outb(0x21, 0x20); // Set master PIC vector offset to 0x20 = 32,
	// To stop conflicting with error interrupts
	outb(0xA1, 40);   // Set slave PIC vector offset to 40 (32+8)
	outb(0x21, 0x4);  // Tell master PIC the slave PIC is at IRQ2 (0000 0100)
	outb(0xA1, 0x2);  // Tell slave PIC its cascade identity (0000 0010)
	outb(0x21, 0x1);  // Set 8086/88 mode
	outb(0xA1, 0x1);  // Set 8086/88 mode     
	outb(0x21, 0);  // Master PIC interrupt masks
	outb(0xA1, 0xFF);  // Slave PIC interrupt masks

	registerGateInterrupt(0, (uint32_t) ex0, 0x8);
	registerGateInterrupt(1, (uint32_t) ex1, 0x8);
	registerGateInterrupt(2, (uint32_t) ex2, 0x8);
	registerGateInterrupt(3, (uint32_t) ex3, 0x8);
	registerGateInterrupt(4, (uint32_t) ex4, 0x8);
	registerGateInterrupt(5, (uint32_t) ex5, 0x8);
	registerGateInterrupt(6, (uint32_t) ex6, 0x8);
	registerGateInterrupt(7, (uint32_t) ex7, 0x8);
	registerGateInterrupt(8, (uint32_t) ex8, 0x8);
	registerGateInterrupt(9, (uint32_t) ex9, 0x8);
	registerGateInterrupt(10, (uint32_t) ex10, 0x8);
	registerGateInterrupt(11, (uint32_t) ex11, 0x8);
	registerGateInterrupt(12, (uint32_t) ex12, 0x8);
	registerGateInterrupt(13, (uint32_t) ex13, 0x8);
	registerGateInterrupt(14, (uint32_t) ex14, 0x8);
	registerGateInterrupt(15, (uint32_t) ex15, 0x8);
	registerGateInterrupt(16, (uint32_t) ex16, 0x8);
	registerGateInterrupt(17, (uint32_t) ex17, 0x8);
	registerGateInterrupt(18, (uint32_t) ex18, 0x8);
	registerGateInterrupt(19, (uint32_t) ex19, 0x8);
	registerGateInterrupt(20, (uint32_t) ex20, 0x8);
	registerGateInterrupt(21, (uint32_t) ex21, 0x8);
	registerGateInterrupt(22, (uint32_t) ex22, 0x8);
	registerGateInterrupt(23, (uint32_t) ex23, 0x8);
	registerGateInterrupt(24, (uint32_t) ex24, 0x8);
	registerGateInterrupt(25, (uint32_t) ex25, 0x8);
	registerGateInterrupt(26, (uint32_t) ex26, 0x8);
	registerGateInterrupt(27, (uint32_t) ex27, 0x8);
	registerGateInterrupt(28, (uint32_t) ex28, 0x8);
	registerGateInterrupt(29, (uint32_t) ex29, 0x8);
	registerGateInterrupt(30, (uint32_t) ex30, 0x8);
	registerGateInterrupt(31, (uint32_t) ex31, 0x8);
	registerGateInterrupt(32, (uint32_t) irq0, 0x8);
	registerGateInterrupt(33, (uint32_t) irq1, 0x8);
	registerGateInterrupt(34, (uint32_t) irq2, 0x8);
	registerGateInterrupt(35, (uint32_t) irq3, 0x8);
	registerGateInterrupt(36, (uint32_t) irq4, 0x8);
	registerGateInterrupt(37, (uint32_t) irq5, 0x8);
	registerGateInterrupt(38, (uint32_t) irq6, 0x8);
	registerGateInterrupt(39, (uint32_t) irq7, 0x8);
	registerGateInterrupt(40, (uint32_t) irq8, 0x8);
	registerGateInterrupt(41, (uint32_t) irq9, 0x8);
	registerGateInterrupt(42, (uint32_t) irq10, 0x8);
	registerGateInterrupt(43, (uint32_t) irq11, 0x8);
	registerGateInterrupt(44, (uint32_t) irq12, 0x8);
	registerGateInterrupt(45, (uint32_t) irq13, 0x8);
	registerGateInterrupt(46, (uint32_t) irq14, 0x8);
	registerGateInterrupt(47, (uint32_t) irq15, 0x8);

	/* fill the IDT descriptor */
	struct IDT_header idt_header;
	idt_header.size = sizeof(IDT[0]) * 256 - 1;
	idt_header.offset = (uint32_t) IDT;
	printf("IDT: %X, %i\n", idt_header.offset, idt_header.size);
	printf("IDT header size: %i\n", sizeof(idt_header));

	load_idt((uint32_t) &idt_header);
}

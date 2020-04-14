/* Declare cosntants for the multiboot header. */
.set ALIGN,		1<<0 /* Align loaded modules on page boundaries */
.set MEMINFO,	1<<1 /* Porivde memory map */
.set FLAGS,		ALIGN | MEMINFO /* This is the multiboot 'flag' field */
.set MAGIC,		0x1BADB002	/* 'Magic number' lets bootloader find the header */
.set CHECKSUM,	-(MAGIC + FLAGS) /* Checksum of above, to prove we are multiboot */

/* Declare a multiboot header */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/* Assigning stack */
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

/* _start is the entry point of the kernel */
.section .text
.global _start
.type _start, @function
_start:
	/* We are in:
		- 32-bit protected mode
		- Interrupts are disabled
		- Paging is disabled
	*/
	
	/* Setting up stack */
	mov $stack_top, %esp

	/* Here we should enable floating point instructions, GDT and paging. */

	/* Enter the high-level kernel. The ABI requires the stack to be 16-byte aligned when called */
	call kernel_main

	/* When done, disable interrupts and halt */
	cli
1:  hlt
	jmp 1b

/* Setting the size of the _start symbol with '.' - the starting location */
.size _start, . - _start

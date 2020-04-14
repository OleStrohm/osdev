/* Specify the entry point to the executable */
ENTRY(_start)

/* Specify where the sections should go in the final image */
SECTIONS
{
	/* Start putting sections at 1 MiB, a conventional place for kernels to be loaded */
	. = 1M;

	/* Put the multiboot header first, as this is required to be put early
	 * so the bootloader will recognize the file format */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

	/* Read-only data */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	/* Read-write data (initialized) */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/* Read-write data (uninitialized) and stack */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}

	/* The compiler by default puts a section in the segment with the same name.
	 * Add more segments as necessary */
}

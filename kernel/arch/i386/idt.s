.intel_syntax noprefix

.globl exception_handler

.globl irq0
.globl irq1
.globl irq2
.globl irq3
.globl irq4
.globl irq5
.globl irq6
.globl irq7
.globl irq8
.globl irq9
.globl irq10
.globl irq11
.globl irq12
.globl irq13
.globl irq14
.globl irq15

.globl load_idt

.globl inb
inb:
	mov dx, [esp+1]
	in ax, dx
	ret

.globl outb
outb:
	mov al, [esp+1]
	mov dx, [esp+2]
	out dx, al
	ret

exception_handler:
	pusha
	popa
	iret

irq0:
	pusha
	call irq0_handler
	popa
	iret

irq1:
	pusha
	call irq1_handler
	popa
	iret

irq2:
	pusha
	call irq2_handler
	popa
	iret

irq3:
	pusha
	call irq3_handler
	popa
	iret

irq4:
	pusha
	call irq4_handler
	popa
	iret

irq5:
	pusha
	call irq5_handler
	popa
	iret

irq6:
	pusha
	call irq6_handler
	popa
	iret

irq7:
	pusha
	call irq7_handler
	popa
	iret

irq8:
	pusha
	call irq8_handler
	popa
	iret

irq9:
	pusha
	call irq9_handler
	popa
	iret

irq10:
	pusha
	call irq10_handler
	popa
	iret

irq11:
	pusha
	call irq11_handler
	popa
	iret

irq12:
	pusha
	call irq12_handler
	popa
	iret

irq13:
	pusha
	call irq13_handler
	popa
	iret

irq14:
	pusha
	call irq14_handler
	popa
	iret

irq15:
	pusha
	call irq15_handler
	popa
	iret

load_idt:
	mov eax, [esp + 4]
	lidt [eax]
	ret

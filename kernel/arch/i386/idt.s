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
	mov dx, [esp+4]
	in ax, dx
	ret

.globl outb
outb:
	mov al, [esp+8]
	mov dx, [esp+4]
	out dx, al
	ret

load_idt:
	mov eax, [esp + 4]
	lidt [eax]
	ret

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

.globl ex0
ex0:
	pusha
	call ex0_handler
	popa
	iret

.globl ex1
ex1:
	pusha
	call ex1_handler
	popa
	iret

.globl ex2
ex2:
	pusha
	call ex2_handler
	popa
	iret

.globl ex3
ex3:
	pusha
	call ex3_handler
	popa
	iret

.globl ex4
ex4:
	pusha
	call ex4_handler
	popa
	iret

.globl ex5
ex5:
	pusha
	call ex5_handler
	popa
	iret

.globl ex6
ex6:
	pusha
	call ex6_handler
	popa
	iret

.globl ex7
ex7:
	pusha
	call ex7_handler
	popa
	iret

.globl ex8
ex8:
	pusha
	call ex8_handler
	popa
	iret

.globl ex9
ex9:
	pusha
	call ex9_handler
	popa
	iret

.globl ex10
ex10:
	pusha
	call ex10_handler
	popa
	iret

.globl ex11
ex11:
	pusha
	call ex11_handler
	popa
	iret

.globl ex12
ex12:
	pusha
	call ex12_handler
	popa
	iret

.globl ex13
ex13:
	pusha
	call ex13_handler
	popa
	iret

.globl ex14
ex14:
	pusha
	call ex14_handler
	popa
	iret

.globl ex15
ex15:
	pusha
	call ex15_handler
	popa
	iret

.globl ex16
ex16:
	pusha
	call ex16_handler
	popa
	iret

.globl ex17
ex17:
	pusha
	call ex17_handler
	popa
	iret

.globl ex18
ex18:
	pusha
	call ex18_handler
	popa
	iret

.globl ex19
ex19:
	pusha
	call ex19_handler
	popa
	iret

.globl ex20
ex20:
	pusha
	call ex20_handler
	popa
	iret

.globl ex21
ex21:
	pusha
	call ex21_handler
	popa
	iret

.globl ex22
ex22:
	pusha
	call ex22_handler
	popa
	iret

.globl ex23
ex23:
	pusha
	call ex23_handler
	popa
	iret

.globl ex24
ex24:
	pusha
	call ex24_handler
	popa
	iret

.globl ex25
ex25:
	pusha
	call ex25_handler
	popa
	iret

.globl ex26
ex26:
	pusha
	call ex26_handler
	popa
	iret

.globl ex27
ex27:
	pusha
	call ex27_handler
	popa
	iret

.globl ex28
ex28:
	pusha
	call ex28_handler
	popa
	iret

.globl ex29
ex29:
	pusha
	call ex29_handler
	popa
	iret

.globl ex30
ex30:
	pusha
	call ex30_handler
	popa
	iret

.globl ex31
ex31:
	pusha
	call ex31_handler
	popa
	iret

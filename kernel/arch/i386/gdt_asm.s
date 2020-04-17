.intel_syntax noprefix

gdtr: .word 0 # for limit (size)
	  .long 0 # for base (offset)

.globl setGdt
.type setGdt, @function
setGdt:
	MOV EAX, [esp + 4]
	MOV [gdtr + 2], EAX
	MOV AX, [ESP + 8]
	MOV [gdtr], AX
	LGDT [gdtr]
	RET

.globl reloadSegments
.type reloadSegments, @function
reloadSegments:
	# Reload CS register containing code selector:
	JMP 0x08:reload_CS # 0x08 points at the new code selector
reload_CS:
	# Reload data segment registers:
	MOV AX, 0x10 # 0x10 points at the new data selector
	MOV DS, AX
	MOV ES, AX
	MOV FS, AX
	MOV GS, AX
	MOV SS, AX
	RET


section .text
	global ft_strcmp

ft_strcmp:
	XOR rax, rax
	XOR r15, r15
.loop:
	CMP [rdi + r15], byte 0x00
	JZ .return
	CMP [rsi + r15], byte 0x00
	JZ .return
	MOV al, [rdi + r15]
	SUB al, [rsi + r15]
	CMP al, byte 0x00
	JNE .return
	INC r15
	JMP .loop
.return:
	MOVSX rax, al
	RET

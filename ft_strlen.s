section .text
	global ft_strlen

ft_strlen:
	XOR rax, rax
.loop:
	CMP [rdi + rax], byte 0x00
	JZ .return
	INC rax
	JMP .loop
.return:
	RET

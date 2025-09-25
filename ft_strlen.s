section .text
	global ft_strlen

ft_strlen:
	XOR rax, rax
.loop:
	CMP [rdi], byte 0x00
	JZ .return
	INC rax
	INC rdi
	JMP .loop
.return:
	ret

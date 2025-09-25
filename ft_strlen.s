section .text
	global ft_strlen

ft_strlen:
	XOR eax, eax
.loop:
	CMP [rdi], byte 0x00
	JZ .return
	INC eax
	INC rdi
	JMP .loop
.return:
	MOVSX rax, eax
	ret

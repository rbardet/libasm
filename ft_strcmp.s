section .text
	global ft_strcmp

ft_strcmp:
	XOR rax, rax
	XOR rcx, rcx
.loop:
	CMP [rdi], byte 0x00
	CMP [rsi], byte 0x00
	JZ .return
	JMP .loop
.return:
	ret

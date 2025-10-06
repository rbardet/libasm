section .text
	global ft_list_size

ft_list_size:
	XOR rax, rax
.loop:
	CMP rdi, byte 0x00
	JZ .return
	INC rax
	MOV rdi, [rdi + 8]
	JMP .loop
.return:
	RET

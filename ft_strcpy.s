section .text
	global ft_strcpy

ft_strcpy:
	XOR rax, rax
	XOR rcx, rcx
.loop:
	MOV al, [rsi + rcx]
	MOV [rdi + rcx], al
	CMP al, byte 0x00
	JZ .return
	INC rcx
	JMP .loop
.return:
	MOV rax, rdi
	ret

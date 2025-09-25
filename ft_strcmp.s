section .text
	global ft_strcmp

ft_strcmp:
	XOR rax, rax
.loop:
	CMP [rdi], byte 0x00
	JZ .return
	CMP [rsi], byte 0x00
	JZ .return
	MOV al, [rdi]
	SUB al, [rsi]
	CMP al, byte 0x00
	JNE .return
	INC rdi
	INC rsi
	JMP .loop
.return:
	MOVSX rax, al
	ret

extern malloc
extern ft_strlen
extern ft_strcpy
extern __errno_location

section .text
	global ft_strdup

ft_strdup:
	XOR bl, bl
	PUSH rdi
	CALL ft_strlen
	MOV rdi, rax
	INC rdi
	CALL malloc
	POP rsi
	CMP rax, 0
	JL .err
	MOV rdi, rax
	CALL ft_strcpy
	RET
.err:
	NEG rax
	MOV rcx, rax
	CALL __errno_location
	MOV [rax], rcx
	MOV rax, -1
	RET

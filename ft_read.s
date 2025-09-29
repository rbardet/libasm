extern __errno_location

section .text
	global ft_read

ft_read:
	MOV rax, 0
	SYSCALL

	CMP rax, 0
	JL .err
	RET
.err:
	NEG rax
	MOV rcx, rax
	CALL __errno_location
	MOV [rax], rcx
	MOV rax, -1
	RET

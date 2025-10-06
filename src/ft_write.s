extern __errno_location
section .text
	global ft_write

ft_write:
	MOV rax, 1
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

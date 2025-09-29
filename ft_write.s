extern __errno_location
section .text
	global ft_write

ft_write:
	MOV rax, 1
	SYSCALL

	CMP rax, 0
	JL .err
	MOV rax, rdx
	RET
.err:
	NEG rax
	MOV rdi, rax
	CALL __errno_location
	MOV [rax], rdi
	MOV rax, -1
	RET

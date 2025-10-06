extern malloc
extern __errno_location
section .text
	global ft_list_push_front
ft_list_push_front:
	PUSH rsi
	MOV rbx, rdi
	MOV rdi, 16
	CALL malloc
	POP rsi
	CMP rax, 0
	JL .err
	MOV [rax], rsi
	MOV rcx, [rbx]
	MOV [rax + 8], rcx
	MOV [rbx], rax
	RET
.err:
	NEG rax
	MOV rcx, rax
	CALL __errno_location
	MOV [rax], rcx
	MOV rax, -1
	RET

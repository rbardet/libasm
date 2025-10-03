extern malloc
section .text
	global ft_list_push_front
ft_list_push_front:
	PUSH rsi
	MOV rbx, rdi
	MOV rdi, 16
	CALL malloc
	POP rsi
	MOV [rax], rsi
	MOV rcx, [rbx]
	MOV [rax + 8], rcx
	MOV [rbx], rax
	RET

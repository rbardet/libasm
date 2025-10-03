extern malloc
section .text
	global ft_list_push_front

ft_list_push_front:
	MOV rbx, [rdi]
	MOV rdi, 16
	CALL malloc
	MOV [rax], rsi
	MOV [rax + 8], rbx
	MOV [rdi], rax
	RET
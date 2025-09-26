section .text
    global ft_write

ft_write:
    XOR rax, rax
    XOR ebx, ebx
    XOR ecx, ecx
    XOR edx, edx

    MOVSXD edx, rdx
    MOVSXD ecx, rsi
    MOVSXD ebx, rdi
    MOV eax, 4
    SYSCALL

    MOV rax, rdx
    RET
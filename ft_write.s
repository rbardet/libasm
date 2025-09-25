section .text
    global ft_write

ft_write:
    XOR rax, rax
.loop:
    CMP rdx, rax
    JZ .return
    INC rax
    JMP .loop
.return:
    RET
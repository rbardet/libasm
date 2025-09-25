section .text
    global ft_write

ft_write:
    XOR rax, rax
.loop:
    CMP rdx, rax
    JMP .return
    INC rax
    JMP .loop
.return:
    RET
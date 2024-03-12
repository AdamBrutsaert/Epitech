bits 64

section .text
    global strlen

    strlen:
        xor rax, rax

        .loop:
            cmp byte [rdi + rax], 0
            je .end

            inc rax
            jmp .loop

        .end:
            ret

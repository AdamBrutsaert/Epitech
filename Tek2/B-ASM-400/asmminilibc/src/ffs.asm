bits 64

section .text
    global ffs

    ffs:
        mov rax, 1

        .loop:
            cmp rax, 33
            je .not_found

            test rdi, 1
            jnz .return

            shr rdi, 1
            inc rax
            jmp .loop

        .not_found:
            mov rax, 0

        .return:
            ret
bits 64

section .text
    global memset

    memset:
        mov r10, rdi

        .loop:
            cmp rdx, 0
            je .end

            mov byte [rdi], sil
            inc rdi
            dec rdx
            jmp .loop

        .end:
            mov rax, r10
            ret

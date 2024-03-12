bits 64

section .text
    global strrchr
    global rindex

    rindex:
    strrchr:
        mov rax, 0

        .loop:
            cmp byte [rdi], sil
            je .found

            cmp byte [rdi], 0
            je .end

            inc rdi
            jmp .loop

        .found:
            mov rax, rdi

            cmp byte [rdi], 0
            je .end

            inc rdi
            jmp .loop

        .end:
            ret

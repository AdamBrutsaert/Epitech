bits 64

section .text
    global strchr
    global index

    index:
    strchr:
        mov rax, rdi

        .loop:
            cmp byte [rax], sil
            je .found

            cmp byte [rax], 0
            je .not_found

            inc rax
            jmp .loop

        .not_found:
            mov rax, 0

        .found:
            ret

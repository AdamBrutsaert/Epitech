bits 64

section .text
    global strstr

    match:
        mov r10, 0

        .loop:
            mov al, [rsi + r10]
            cmp al, 0
            je .match

            cmp al, [rdi + r10]
            jne .no_match

            inc r10
            jmp .loop

        .match:
            mov rax, 1
            ret

        .no_match:
            mov rax, 0
            ret

    strstr:
        cmp byte [rsi], 0
        je .found

        .loop:
            cmp byte [rdi], 0
            je .not_found

            call match
            cmp rax, 1
            je .found

            inc rdi
            jmp .loop

        .found:
            mov rax, rdi
            ret

        .not_found:
            mov rax, 0
            ret

bits 64

section .text
    global strcmp

    strcmp:
        mov rax, 0
        mov r10, 0
        mov r11, 0

        .loop:
            mov al, byte [rdi + r10]
            cmp al, 0
            jz .end

            cmp al, byte [rsi + r10]
            jne .end

            inc r10
            jmp .loop

        .end:
            mov r11b, byte [rsi + r10]
            sub rax, r11
            ret

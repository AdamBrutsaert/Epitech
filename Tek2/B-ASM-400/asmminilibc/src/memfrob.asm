bits 64

section .text
    global memfrob

    ; Parameters:
    ; rdi: destination pointer
    ; rsi: number of bytes to encrypt
    ; Returns:
    ; rax: destination pointer
    memfrob:
        mov rax, rdi

        .loop:
            test rsi, rsi
            jz .return

            dec rsi
            xor byte [rdi + rsi], 42
            jmp .loop

        .return:
            ret
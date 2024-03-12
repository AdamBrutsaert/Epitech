bits 64

section .text
    global strncmp

    strncmp:
        mov rax, 0
        mov rcx, 0

        ; If we want to compare 0 character, return 0
        test rdx, rdx
        jz .end

        .compare_byte:
            mov r8b, byte [rdi]

            mov al, r8b
            mov cl, byte [rsi]

            ; If the characters are different, return the difference
            sub rax, rcx
            jnz .end

            ; If we reached the end of the first string, return the difference
            test r8b, r8b
            jz .end

            inc rdi
            inc rsi

            ; If we haven't compared all requested bytes, continue
            dec rdx
            jnz .compare_byte

        .end:
            ret

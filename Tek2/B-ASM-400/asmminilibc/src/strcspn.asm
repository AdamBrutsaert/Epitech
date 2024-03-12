bits 64

section .text
    global strcspn

    strcspn:
        mov rax, rdi

        ; Increment rdi as long as the byte at [rdi] is not in the reject string
        .haystack_loop:
            mov dl, byte [rdi]

            ; If we reached the end of the haystack
            test dl, dl
            jz .end

            mov rcx, 0

        .reject_loop:
            mov r8b, byte [rsi + rcx]

            ; If we reached the end of the reject string
            test r8b, r8b
            jz .haystack_next_char

            ; If the current byte in the haystack is in the reject string
            cmp dl, r8b
            je .end

            inc rcx
            jmp .reject_loop

        .haystack_next_char:
            inc rdi
            jmp .haystack_loop

        .end:
            sub rdi, rax
            mov rax, rdi
            ret

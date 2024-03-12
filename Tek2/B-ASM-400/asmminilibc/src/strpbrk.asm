bits 64

section .text
    global strpbrk

    strpbrk:
        .haystack_loop:
            mov al, byte [rdi]

            cmp al, 0
            je .not_found

            mov r10, 0

        .needle_char_loop:
            mov r11b, byte [rsi + r10]
            cmp r11b, 0
            je .end_needle_char_loop

            cmp al, r11b
            je .found

            inc r10
            jmp .needle_char_loop

        .end_needle_char_loop:
            inc rdi
            jmp .haystack_loop

        .not_found:
            mov rax, 0
            ret

        .found:
            mov rax, rdi
            ret

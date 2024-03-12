bits 64

section .text
    global strcasecmp

    strcasecmp:
        mov rax, 0
        mov r10, 0
        mov r11, 0

        .loop:
            mov al, byte [rdi + r10]
            mov r11b, byte [rsi + r10]

        .lower_al:
            cmp al, 65
            jl .lower_r11b
            cmp al, 90
            jg .lower_r11b
            add al, 32

        .lower_r11b:
            cmp r11b, 65
            jl .comparing
            cmp r11b, 90
            jg .comparing
            add r11b, 32

        .comparing:
            cmp al, 0
            jz .end

            cmp al, r11b
            jne .end

            inc r10
            jmp .loop

        .end:
            sub rax, r11
            ret

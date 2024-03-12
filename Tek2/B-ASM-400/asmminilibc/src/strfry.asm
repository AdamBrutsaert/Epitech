bits 64

section .text
    global strfry

    ; Parameters:
    ; rdi: string pointer
    ; Returns:
    ; rax: string pointer
    strfry:
        xor rsi, rsi

        .strlen:
            cmp byte [rdi + rsi], byte 0
            je .strlen_end
            inc rsi
            jmp .strlen

        .strlen_end:
            cmp rsi, 1
            jle .end

            ; rsi = length of the string
            ; rcx = current index
            xor rcx, rcx
        .loop:
            ; If we reached the end of the string
            cmp rcx, rsi
            je .end

            ; Generate a random index
            ; It will be stored in rdx
            rdrand rax
            xor rdx, rdx
            div rsi

            ; Swap the character at [rdi + rcx] with the character at [rdi + rdx]
            mov al, byte [rdi + rcx]
            mov ah, byte [rdi + rdx]
            mov byte [rdi + rcx], ah
            mov byte [rdi + rdx], al

            inc rcx
            jmp .loop

        .end:
            mov rax, rdi
            ret

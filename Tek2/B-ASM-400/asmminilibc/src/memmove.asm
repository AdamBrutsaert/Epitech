bits 64

section .text
    global memmove

    ; Parameters:
    ; rdi: destination pointer
    ; rsi: source pointer
    ; rdx: number of bytes to copy
    ; Returns:
    ; rax: destination pointer
    memmove:
        ; Set the return value to the destination pointer
        mov rax, rdi

        ; If there are no bytes to copy, return
        test rdx, rdx
        jz .return

        ; Set the number of bytes to copy
        mov rcx, rdx

        ; If rdi <= rsi, copy forward else copy backward
        cmp rdi, rsi
        jle .copy

        .setup_backward:
            dec rdx
            add rdi, rdx
            add rsi, rdx

            ; Set the direction flag to copy backward
            std

        .copy:
            rep movsb

        .return:
            ; Clear the direction flag
            cld
            ret
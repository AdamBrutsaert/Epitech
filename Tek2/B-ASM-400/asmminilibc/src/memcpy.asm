bits 64

section .text
    global memcpy

    ; Parameters:
    ; rdi: destination pointer
    ; rsi: source pointer
    ; rdx: number of bytes to copy
    ; Returns:
    ; rax: destination pointer
    memcpy:
        ; Set the return value to the destination pointer
        mov rax, rdi

        ; Set the number of time to copy
        mov rcx, rdx

        ; Copy the bytes
        rep movsb

        ; Return the destination pointer
        ret

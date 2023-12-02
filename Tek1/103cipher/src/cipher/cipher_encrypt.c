/*
** EPITECH PROJECT, 2022
** cipher_encrypt.c
** File description:
** cipher_encrypt.c
*/

#include "cipher.h"
#include <stdio.h>

void cipher_encrypt(cipher_t *cipher)
{
    matrix_t *result = matrix_mul(cipher->message, cipher->key);

    printf("Key matrix:\n");
    matrix_print(cipher->key);
    printf("\nEncrypted message:\n");
    for (uint32_t line = 0; line < result->lines; line++) {
        for (uint32_t column = 0; column < result->columns; column++) {
            printf("%u", (uint32_t)result->matrix[line][column]);
            if (!(line + 1 == result->lines && column + 1 == result->columns))
                printf(" ");
        }
    }
    printf("\n");
    matrix_destroy(result);
}

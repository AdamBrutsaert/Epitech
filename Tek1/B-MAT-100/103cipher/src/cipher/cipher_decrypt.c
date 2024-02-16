/*
** EPITECH PROJECT, 2022
** cipher_encrypt.c
** File description:
** cipher_encrypt.c
*/

#include "cipher.h"
#include <stdio.h>
#include <math.h>

void cipher_decrypt(cipher_t *cipher)
{
    matrix_t *result = matrix_mul(cipher->message, cipher->key);

    printf("Key matrix:\n");
    matrix_printf(cipher->key);
    printf("\nDecrypted message:\n");
    for (uint32_t line = 0; line < result->lines; line++) {
        for (uint32_t column = 0; column < result->columns; column++) {
            if ((char)round(result->matrix[line][column]) != 0)
                printf("%c", (char)round(result->matrix[line][column]));
        }
    }
    printf("\n");
    matrix_destroy(result);
}

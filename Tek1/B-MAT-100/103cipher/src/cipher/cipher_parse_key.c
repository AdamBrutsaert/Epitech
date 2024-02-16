/*
** EPITECH PROJECT, 2022
** cipher_parse_key.c
** File description:
** cipher_parse_key.c
*/

#include "cipher.h"
#include <string.h>

static uint32_t get_matrix_size(uint64_t length)
{
    uint32_t size = 0;

    while (size * size < length)
        size++;
    return size;
}

static uint32_t get_number(char const *key, uint64_t length, uint64_t index)
{
    if (index >= length)
        return 0;
    return (uint32_t)key[index];
}

int32_t cipher_parse_key(cipher_t *cipher, char const *key)
{
    uint64_t length = strlen(key);
    uint32_t size = get_matrix_size(length);
    uint64_t index = 0;

    if (length == 0)
        return 84;
    cipher->key = matrix_create(size, size);
    for (uint32_t line = 0; line < size; line++) {
        for (uint32_t column = 0; column < size; column++) {
            cipher->key->matrix[line][column] =
                get_number(key, length, index);
            index++;
        }
    }
    if (cipher->flag == DECRYPT)
        matrix_move(cipher->key, matrix_inverse(cipher->key));
    return 0;
}

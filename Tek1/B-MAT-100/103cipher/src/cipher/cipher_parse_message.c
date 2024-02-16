/*
** EPITECH PROJECT, 2022
** cipher_parse_message.c
** File description:
** cipher_parse_message.c
*/

#include "cipher.h"
#include <string.h>

static uint32_t get_lines(uint64_t length, uint32_t columns)
{
    uint32_t lines = 0;

    while (lines * columns < length)
        lines++;
    return lines;
}

static uint32_t get_number(char const *message, uint64_t length, uint64_t index)
{
    if (index >= length)
        return 0;
    return (uint32_t)message[index];
}

void cipher_parse_message(cipher_t *cipher, char const *message)
{
    uint64_t length = strlen(message);
    uint32_t columns = cipher->key->lines;
    uint32_t lines = get_lines(length, columns);
    uint64_t index = 0;

    cipher->message = matrix_create(lines, columns);
    for (uint32_t line = 0; line < lines; line++) {
        for (uint32_t column = 0; column < columns; column++) {
            cipher->message->matrix[line][column] =
                get_number(message, length, index);
            index++;
        }
    }
}

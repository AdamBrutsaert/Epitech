/*
** EPITECH PROJECT, 2022
** cipher_parse_encrypted_message.c
** File description:
** cipher_parse_encrypted_message.c
*/

#include "cipher.h"
#include <stdlib.h>

static int32_t parse_one_number(char const **str, uint32_t *value)
{
    *value = 0;
    for (; **str >= '0' && **str <= '9'; (*str)++)
        *value = *value * 10 + (**str - '0');
    if (**str == ' ') {
        (*str)++;
        return 0;
    }
    if (**str == '\0')
        return 1;
    return 84;
}

static uint32_t get_lines(uint64_t length, uint32_t columns)
{
    uint32_t lines = 0;

    while (lines * columns < length)
        lines++;
    return lines;
}

static uint32_t get_number(uint32_t *numbers, uint64_t length, uint64_t index)
{
    if (index >= length)
        return 0;
    return numbers[index];
}

static void fill_matrix(cipher_t *cipher, uint32_t *numbers, uint32_t length)
{
    uint32_t columns = cipher->key->lines;
    uint32_t lines = get_lines(length, columns);
    uint64_t index = 0;

    cipher->message = matrix_create(lines, columns);
    for (uint32_t line = 0; line < lines; line++) {
        for (uint32_t column = 0; column < columns; column++) {
            cipher->message->matrix[line][column] =
                get_number(numbers, length, index);
            index++;
        }
    }
}

int32_t cipher_parse_encrypted_message(cipher_t *cipher, char const *message)
{
    uint32_t value;
    int32_t code;
    uint32_t *numbers = NULL;
    uint32_t length = 0;
    uint32_t capacity = 0;

    while ((code = parse_one_number(&message, &value)) <= 1) {
        if (length == capacity) {
            capacity = capacity * 2 + !capacity;
            numbers = realloc(numbers, capacity * sizeof(uint32_t));
        }
        numbers[length++] = value;
        if (code == 1)
            break;
    }
    if (code == 84) {
        free(numbers);
        return 84;
    }
    fill_matrix(cipher, numbers, length);
    free(numbers);
    return 0;
}

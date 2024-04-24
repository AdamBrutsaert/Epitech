/*
** EPITECH PROJECT, 2024
** parse_address.c
** File description:
** parse_address.c
*/

#include "utils/parsing.h"

#include <string.h>
#include <stdlib.h>

static char *next_word(const char **string)
{
    const char *begin = *string;
    const char *end;

    while (**string != '\0' && **string != ',')
        (*string)++;
    end = *string;
    if (**string == ',')
        (*string)++;
    return strndup(begin, end - begin);
}

static bool parse_byte(const char *string, uint8_t *byte)
{
    size_t length = strlen(string);
    int value;

    for (size_t i = 0; i < length; i++) {
        if (string[i] < '0' || string[i] > '9')
            return false;
    }
    value = atoi(string);
    if (value < 0 || value > 255)
        return false;
    *byte = value;
    return true;
}

static bool parse_next_byte(const char **string, uint8_t *byte)
{
    char *word = next_word(string);

    if (word == NULL)
        return false;
    if (!parse_byte(word, byte))
        return false;
    free(word);
    return true;
}

bool parse_address(ipv4_address_t *address, const char *string)
{
    uint8_t bytes[6];
    size_t index = 0;

    for (; index < 6 && *string != '\0'; index++) {
        if (!parse_next_byte(&string, &bytes[index]))
            return false;
    }
    if (index != 6 || *string != '\0')
        return false;
    address->address =
        (bytes[0] << 24)
        | (bytes[1] << 16)
        | (bytes[2] << 8)
        | bytes[3];
    address->port = (bytes[4] << 8) | bytes[5];
    return true;
}

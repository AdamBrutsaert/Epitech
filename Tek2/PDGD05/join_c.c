/*
** EPITECH PROJECT, 2024
** join_c.c
** File description:
** join_c.c
*/

#include "string.h"

#include <stdlib.h>
#include <string.h>

static size_t get_total_length(const char *const *array)
{
    size_t length = 0;

    for (size_t i = 0; array[i]; i++) {
        length += strlen(array[i]);
        if (array[i + 1])
            length++;
    }
    return length;
}

void join_c(string_t *self, char delim, const char *const *array)
{
    size_t total_length = get_total_length(array);
    size_t length = 0;

    free(self->str);
    self->str = calloc(total_length + 1, sizeof(char));
    if (self->str == NULL)
        return;
    self->str[total_length] = '\0';
    for (size_t i = 0; array[i]; i++) {
        strcat(self->str, array[i]);
        if (array[i + 1]) {
            length = strlen(self->str);
            self->str[length] = delim;
            self->str[length + 1] = '\0';
        }
    }
}

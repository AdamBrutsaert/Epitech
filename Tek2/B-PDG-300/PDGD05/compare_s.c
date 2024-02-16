/*
** EPITECH PROJECT, 2024
** compare_s.c
** File description:
** compare_s.c
*/

#include "string.h"

#include <string.h>

int compare_s(const string_t *self, const string_t *str)
{
    if (str == NULL)
        return self->compare_c(self, NULL);
    return self->compare_c(self, str->str);
}

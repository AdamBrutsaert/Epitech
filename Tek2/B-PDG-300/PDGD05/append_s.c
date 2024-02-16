/*
** EPITECH PROJECT, 2024
** append_s.c
** File description:
** append_s.c
*/

#include "string.h"

#include <string.h>
#include <stdlib.h>

void append_s(string_t *self, const string_t *ap)
{
    if (ap != NULL)
        self->append_c(self, ap->str);
}

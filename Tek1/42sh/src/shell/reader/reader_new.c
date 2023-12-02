/*
** EPITECH PROJECT, 2023
** reader_new.c
** File description:
** reader_new.c
*/

#include "shell/reader_impl.h"

#include <stdlib.h>

reader_t *reader_new(void)
{
    return calloc(1, sizeof(reader_t));
}

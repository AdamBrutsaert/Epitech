/*
** EPITECH PROJECT, 2023
** my_error_throw.c
** File description:
** my_error_throw.c
*/

#include "my/error.h"

#include <stddef.h>

void *my_error_throw(int64_t type)
{
    my_error_get()->type = type;
    return NULL;
}

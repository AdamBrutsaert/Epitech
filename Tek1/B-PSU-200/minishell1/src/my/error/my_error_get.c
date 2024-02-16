/*
** EPITECH PROJECT, 2023
** my_error_get.c
** File description:
** my_error_get.c
*/

#include "my/error.h"

error_t *my_error_get(void)
{
    static error_t error = { .type = ERROR_NONE };

    return &error;
}

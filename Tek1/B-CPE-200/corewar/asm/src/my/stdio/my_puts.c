/*
** EPITECH PROJECT, 2023
** my_puts.c
** File description:
** my_puts.c
*/

#include "my/stdio.h"

#include <unistd.h>

void my_puts(string_t *string)
{
    write(STDOUT_FILENO, string_get_raw(string), string_get_length(string));
}

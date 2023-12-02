/*
** EPITECH PROJECT, 2023
** my_eputs.c
** File description:
** my_eputs.c
*/

#include "my/stdio.h"

#include <unistd.h>

void my_eputs(string_t *string)
{
    write(STDERR_FILENO, string_get_raw(string), string_get_length(string));
}

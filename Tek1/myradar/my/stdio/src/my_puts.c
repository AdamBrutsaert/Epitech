/*
** EPITECH PROJECT, 2022
** my_puts.c
** File description:
** my_puts.c
*/

#include "my/stdio.h"

#include <unistd.h>
#include <my/string.h>

void my_puts(char const *string)
{
    write(STDOUT_FILENO, string, my_strlen(string));
}

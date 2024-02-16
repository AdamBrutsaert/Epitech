/*
** EPITECH PROJECT, 2023
** stdio.c
** File description:
** stdio.c
*/

#include "my/stdio.h"
#include "my/string.h"

#include <unistd.h>

void my_puts(char const *string)
{
    write(STDOUT_FILENO, string, my_strlen(string));
}

void my_putc(char character)
{
    write(STDOUT_FILENO, &character, 1);
}

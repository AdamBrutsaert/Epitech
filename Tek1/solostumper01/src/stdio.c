/*
** EPITECH PROJECT, 2023
** stdio.c
** File description:
** stdio.c
*/

#include "string.h"

#include <unistd.h>

void my_putc(char c)
{
    write(STDOUT_FILENO, &c, 1);
}

void my_puts(char const *string)
{
    write(STDOUT_FILENO, string, my_strlen(string));
}

void my_eputs(char const *string)
{
    write(STDERR_FILENO, string, my_strlen(string));
}

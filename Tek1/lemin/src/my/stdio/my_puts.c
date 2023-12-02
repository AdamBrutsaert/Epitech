/*
** EPITECH PROJECT, 2023
** my_puts.c
** File description:
** my_puts.c
*/

#include "my/stdio.h"
#include "my/string.h"

#include <unistd.h>

void my_puts(const char *string)
{
    write(STDOUT_FILENO, string, my_strlen(string));
}

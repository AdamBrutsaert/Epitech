/*
** EPITECH PROJECT, 2023
** my_puts.c
** File description:
** my_puts.c
*/

#include "my/string.h"
#include "my/stdio.h"

#include <unistd.h>

void my_puts(char *str)
{
    write(STDOUT_FILENO, str, my_strlen(str));
}

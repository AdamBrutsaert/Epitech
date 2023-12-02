/*
** EPITECH PROJECT, 2023
** my_puts.c
** File description:
** my_puts.c
*/

#include "my.h"

#include <unistd.h>

void my_puts(char const *string)
{
    write(STDOUT_FILENO, string, my_strlen(string));
}

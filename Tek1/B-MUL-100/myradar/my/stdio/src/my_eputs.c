/*
** EPITECH PROJECT, 2022
** my_eputs.c
** File description:
** my_eputs.c
*/

#include "my/stdio.h"

#include <unistd.h>
#include <my/string.h>

void my_eputs(char const *string)
{
    write(STDERR_FILENO, string, my_strlen(string));
}

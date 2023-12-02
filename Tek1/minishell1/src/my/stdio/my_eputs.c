/*
** EPITECH PROJECT, 2023
** my_eputs.c
** File description:
** my_eputs.c
*/

#include "my/stdio.h"
#include "my/string.h"

#include <unistd.h>

void my_eputs(char const *string)
{
    write(STDERR_FILENO, string, my_strlen(string));
}

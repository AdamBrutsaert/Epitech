/*
** EPITECH PROJECT, 2023
** my_putcs.c
** File description:
** my_putcs.c
*/

#include "my/stdio.h"
#include "my/string.h"

#include <unistd.h>

void my_putcs(const char *string)
{
    write(STDOUT_FILENO, string, my_strlen(string));
}

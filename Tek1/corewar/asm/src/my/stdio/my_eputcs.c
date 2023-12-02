/*
** EPITECH PROJECT, 2023
** my_eputcs.c
** File description:
** my_eputcs.c
*/

#include "my/stdio.h"
#include "my/string.h"

#include <unistd.h>

void my_eputcs(const char *string)
{
    write(STDERR_FILENO, string, my_strlen(string));
}

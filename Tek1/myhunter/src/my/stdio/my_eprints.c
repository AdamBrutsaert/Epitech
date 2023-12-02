/*
** EPITECH PROJECT, 2022
** my_eprints.c
** File description:
** my_eprints.c
*/

#include "my/stdio.h"

#include <my/string.h>
#include <unistd.h>

void my_eprints(char const *string)
{
    write(STDERR_FILENO, string, my_strlen(string));
}

/*
** EPITECH PROJECT, 2022
** my_eprints.c
** File description:
** my_eprints.c
*/

#include "my/stdio.h"
#include "my/string.h"

#include <unistd.h>

int64_t my_eprints(char const *str)
{
    return write(STDERR_FILENO, str, my_strlen(str));
}

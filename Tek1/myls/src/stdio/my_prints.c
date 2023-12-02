/*
** EPITECH PROJECT, 2022
** my_prints.c
** File description:
** my_prints.c
*/

#include "my/stdio.h"
#include "my/string.h"

#include <unistd.h>

int64_t my_prints(char const *str)
{
    return write(STDOUT_FILENO, str, my_strlen(str));
}

/*
** EPITECH PROJECT, 2022
** my_putstr_err.c
** File description:
** Implementation of my_putstr_err
*/

#include <unistd.h>

#include "my.h"

void my_putstr_err(char const *str)
{
    write(STDERR_FILENO, str, my_strlen(str));
}

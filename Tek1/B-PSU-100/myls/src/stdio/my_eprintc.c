/*
** EPITECH PROJECT, 2022
** my_eprintc.c
** File description:
** my_eprintc.c
*/

#include "my/stdio.h"

#include <unistd.h>

int64_t my_eprintc(char c)
{
    return write(STDERR_FILENO, &c, 1);
}

/*
** EPITECH PROJECT, 2022
** my_printc.c
** File description:
** my_printc.c
*/

#include "my/stdio.h"

#include <unistd.h>

int64_t my_printc(char c)
{
    return write(STDOUT_FILENO, &c, 1);
}

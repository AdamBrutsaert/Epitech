/*
** EPITECH PROJECT, 2022
** my_putc.c
** File description:
** my_putc.c
*/

#include "my/stdio.h"

#include <unistd.h>

void my_putc(char c)
{
    write(STDOUT_FILENO, &c, 1);
}

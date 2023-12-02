/*
** EPITECH PROJECT, 2023
** my_putc.c
** File description:
** my_putc.c
*/

#include "my/stdio.h"

#include <unistd.h>

void my_putc(char character)
{
    write(STDOUT_FILENO, &character, 1);
}

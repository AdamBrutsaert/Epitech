/*
** EPITECH PROJECT, 2022
** my_eputc.c
** File description:
** my_eputc.c
*/

#include "my/stdio.h"

#include <unistd.h>

void my_eputc(char c)
{
    write(STDERR_FILENO, &c, 1);
}

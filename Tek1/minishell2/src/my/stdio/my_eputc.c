/*
** EPITECH PROJECT, 2023
** my_eputc.c
** File description:
** my_eputc.c
*/

#include "my/stdio.h"

#include <unistd.h>

void my_eputc(char character)
{
    write(STDERR_FILENO, &character, 1);
}

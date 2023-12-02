/*
** EPITECH PROJECT, 2022
** my_eprintc.c
** File description:
** my_eprintc.c
*/

#include "my/stdio.h"

#include <unistd.h>

void my_eprintc(char character)
{
    write(STDERR_FILENO, &character, 1);
}

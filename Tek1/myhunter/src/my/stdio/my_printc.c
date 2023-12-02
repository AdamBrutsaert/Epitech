/*
** EPITECH PROJECT, 2022
** my_printc.c
** File description:
** my_printc.c
*/

#include "my/stdio.h"

#include <unistd.h>

void my_printc(char character)
{
    write(STDOUT_FILENO, &character, 1);
}

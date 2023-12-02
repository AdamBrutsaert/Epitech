/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** Implementation of my_putchar
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(STDOUT_FILENO, &c, 1);
}

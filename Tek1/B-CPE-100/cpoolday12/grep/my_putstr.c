/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** Implementation of my_putstr
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

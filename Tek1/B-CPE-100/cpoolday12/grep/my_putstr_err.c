/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** Implementation of my_putstr
*/

#include <unistd.h>
#include "my.h"

int my_putstr_err(char const *str)
{
    write(2, str, my_strlen(str));
    return 0;
}

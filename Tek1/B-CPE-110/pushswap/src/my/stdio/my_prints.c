/*
** EPITECH PROJECT, 2022
** my_prints.c
** File description:
** my_prints.c
*/

#include "my/stdio.h"
#include "my/string.h"

#include <unistd.h>

void my_prints(char const *string)
{
    write(STDOUT_FILENO, string, my_strlen(string));
}

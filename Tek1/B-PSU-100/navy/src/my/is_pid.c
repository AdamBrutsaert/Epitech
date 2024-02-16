/*
** EPITECH PROJECT, 2023
** is_pid.c
** File description:
** is_pid.c
*/

#include "my.h"

int8_t is_pid(char const *string)
{
    for (; *string; string++)
        if (*string < '0' || *string > '9')
            return 0;
    return 1;
}

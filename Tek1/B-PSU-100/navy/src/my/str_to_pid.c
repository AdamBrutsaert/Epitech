/*
** EPITECH PROJECT, 2023
** str_to_pid.c
** File description:
** str_to_pid.c
*/

#include "my.h"

pid_t str_to_pid(char const *string)
{
    pid_t pid = 0;

    for (; *string >= '0' && *string <= '9'; string++)
        pid = pid * 10 + *string - '0';
    return pid;
}

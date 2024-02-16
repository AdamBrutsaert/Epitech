/*
** EPITECH PROJECT, 2022
** my_eprinti.c
** File description:
** my_eprinti.c
*/

#include "my/stdio.h"

#include <my/math.h>

void my_eprinti(int64_t number)
{
    if (number < 0)
        my_eprintc('-');
    if (number <= -10 || number >= 10)
        my_eprinti(my_i64_abs(number / 10));
    my_eprintc('0' + my_i64_abs(number % 10));
}

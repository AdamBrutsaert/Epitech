/*
** EPITECH PROJECT, 2022
** my_printi.c
** File description:
** my_printi.c
*/

#include "my/stdio.h"
#include "my/math.h"

void my_printi(i64_t number)
{
    if (number < 0)
        my_printc('-');
    if (number <= -10 || number >= 10)
        my_printi(my_i64_abs(number / 10));
    my_printc('0' + my_i64_abs(number % 10));
}

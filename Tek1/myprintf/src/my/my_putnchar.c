/*
** EPITECH PROJECT, 2022
** print_ap_char
** File description:
** Implementation of print_ap_char
*/

#include "my.h"

int my_putnchar(char c, int n)
{
    int size = 0;

    for (int i = 0; i < n; i++) {
        my_putchar(c);
        size++;
    }
    return size;
}

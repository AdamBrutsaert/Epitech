/*
** EPITECH PROJECT, 2022
** print_ap_string
** File description:
** Implementation of print_ap_string
*/

#include "miniprintf.h"
#include <unistd.h>

int print_ap_string(va_list *ap)
{
    char const *str = va_arg(*ap, char const *);
    int length = my_strlen(str);

    write(STDOUT_FILENO, str, length);
    return length;
}

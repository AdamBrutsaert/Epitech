/*
** EPITECH PROJECT, 2022
** miniprintf
** File description:
** Header of miniprintf
*/

#pragma once

#include <stdarg.h>

int mini_printf(char const *format, ...);
void my_putchar(char c);
int my_strlen(char const *str);
int print_ap_int(va_list *ap);
int print_ap_char(va_list *ap);
int print_ap_string(va_list *ap);
int print_ap_percentage(va_list *ap);

static const char ap_tokens[] = {
    'd',
    'i',
    'c',
    's',
    '%',
    0
};

static const int (*ap_functions[])(va_list *) = {
    &print_ap_int,
    &print_ap_int,
    &print_ap_char,
    &print_ap_string,
    &print_ap_percentage,
    0
};

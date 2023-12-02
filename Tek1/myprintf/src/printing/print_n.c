/*
** EPITECH PROJECT, 2022
** print_n.c
** File description:
** Implementation of print_n.c
*/

#include "printing/printing.h"

int print_n(format_t *format)
{
    *(int*)format->value->as_pointer = format->length;
    return 0;
}

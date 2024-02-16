/*
** EPITECH PROJECT, 2023
** intmax_to_big_endian.c
** File description:
** intmax_to_big_endian.c
*/

#include "asm/conversion.h"

intmax_t intmax_to_big_endian(intmax_t nb)
{
    if (is_big_endian())
        return nb;
    swap_endianness((int8_t *)&nb, sizeof(intmax_t));
    return nb;
}

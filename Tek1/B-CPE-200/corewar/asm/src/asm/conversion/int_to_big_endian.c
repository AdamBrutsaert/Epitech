/*
** EPITECH PROJECT, 2023
** int_to_big_endian.c
** File description:
** int_to_big_endian.c
*/

#include "asm/conversion.h"
#include "my/memory.h"

int int_to_big_endian(int nb)
{
    if (is_big_endian())
        return nb;
    swap_endianness((int8_t *)&nb, sizeof(int));
    return nb;
}

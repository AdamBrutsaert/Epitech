/*
** EPITECH PROJECT, 2023
** swap_endianness.c
** File description:
** swap_endianness.c
*/

#include "asm/conversion.h"

void swap_endianness(int8_t *bytes, size_t length)
{
    int8_t temp;

    for (size_t i = 0; i < length / 2; i++) {
        temp = bytes[i];
        bytes[i] = bytes[length - i - 1];
        bytes[length - i - 1] = temp;
    }
}

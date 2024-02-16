/*
** EPITECH PROJECT, 2023
** conversion.h
** File description:
** conversion.h
*/

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

bool is_big_endian(void);
void swap_endianness(int8_t *bytes, size_t length);

int int_to_big_endian(int nb);
intmax_t intmax_to_big_endian(intmax_t nb);

/*
** EPITECH PROJECT, 2022
** operation.h
** File description:
** operation.h
*/

#pragma once

#include <stdint.h>

void *my_memcpy(void *dest, void const *src, uint64_t bytes);
void *my_memmove(void *dest, void const *src, uint64_t bytes);
void *my_memset(void *dest, int8_t value, uint64_t bytes);

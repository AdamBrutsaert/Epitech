/*
** EPITECH PROJECT, 2022
** memory.h
** File description:
** memory.h
*/

#pragma once

#include <stdint.h>

void *my_memmove(void *dest, void const *src, uint64_t n);
void *my_memcpy(void *dest, void const *src, uint64_t n);
void *my_realloc(void *src, uint64_t new_length, uint64_t prev_length);

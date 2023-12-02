/*
** EPITECH PROJECT, 2023
** memory.h
** File description:
** memory.h
*/

#pragma once

#include <stdint.h>
#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t bytes);
void *my_memmove(void *dest, const void *src, size_t bytes);
void *my_memset(void *dest, uint8_t value, size_t bytes);

void my_freearr(void *arr);

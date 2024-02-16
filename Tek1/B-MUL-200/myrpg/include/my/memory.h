/*
** EPITECH PROJECT, 2023
** memory.h
** File description:
** memory.h
*/

#pragma once

#include <stddef.h>
#include <stdint.h>

void *my_memset(void *ptr, int8_t value, size_t bytes);
void *my_calloc(size_t bytes);
void *my_memcpy(void *dest, const void *src, size_t bytes);

void my_freearr(void *arr);
size_t my_arrlen(void *arr);

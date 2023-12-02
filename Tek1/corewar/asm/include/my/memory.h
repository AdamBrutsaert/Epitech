/*
** EPITECH PROJECT, 2023
** arena.h
** File description:
** arena.h
*/

#pragma once

#include <stddef.h>
#include <stdint.h>

void *my_malloc(size_t bytes);
void *my_calloc(size_t bytes);
void *my_realloc(void *ptr, size_t bytes);
void my_free(void *ptr);

void *my_memset(void *dest, int8_t value, size_t bytes);
void *my_memcpy(void *dest, const void *src, size_t bytes);
void *my_memmove(void *dest, const void *src, size_t bytes);

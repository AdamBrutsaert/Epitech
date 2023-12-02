/*
** EPITECH PROJECT, 2022
** memory.h
** File description:
** memory.h
*/

#pragma once

#include "types.h"

void *my_malloc(u64_t n);
void *my_calloc(u64_t n);
void *my_realloc(void *ptr, u64_t n);
void my_free(void *ptr);

u64_t my_memlen(void *ptr);
void *my_memmove(void *dest, void const *src, u64_t n);
void *my_memcpy(void *dest, void const *src, u64_t n);
void *my_memset(void *dest, i8_t value, u64_t n);
status_t my_memcmp(void *a, void *b, u64_t n);

void swap_i32(i32_t *a, i32_t *b);
void swap_u32(u32_t *a, u32_t *b);

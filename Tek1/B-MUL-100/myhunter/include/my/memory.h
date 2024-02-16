/*
** EPITECH PROJECT, 2022
** math.h
** File description:
** math.h
*/

#pragma once

#include <stdint.h>

#ifndef NULL
    #define NULL ((void*)0)
#endif

void *my_malloc(uint64_t n);
void *my_calloc(uint64_t n);
void *my_realloc(void *src, uint64_t n);
void my_free(void *ptr);

uint64_t my_memlen(void *ptr);
void *my_memmove(void *dest, void const *src, uint64_t n);
void *my_memcpy(void *dest, void const *src, uint64_t n);
void *my_memset(void *dest, int8_t value, uint64_t n);
int8_t my_memcmp(void *a, void *b, uint64_t n);

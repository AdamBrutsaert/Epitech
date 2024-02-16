/*
** EPITECH PROJECT, 2022
** allocation.h
** File description:
** allocation.h
*/

#pragma once

#include <stddef.h>
#include <stdint.h>

void *my_malloc(uint64_t bytes);
void *my_calloc(uint64_t bytes);
void *my_realloc(void *ptr, uint64_t bytes);
void my_free(void *ptr);

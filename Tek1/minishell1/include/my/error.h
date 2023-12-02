/*
** EPITECH PROJECT, 2023
** error.h
** File description:
** error.h
*/

#pragma once

#include <stdint.h>

#define ERROR (my_error_get()->type)
#define THROW_NULL(type) return my_error_throw(type)
#define THROW_ZERO(type) return (long)my_error_throw(type)
#define THROW_VOID(type) return (void)my_error_throw(type)

#define ERROR_NONE       0x0
#define OK               ERROR_NONE
#define ERROR_ALLOCATION 0x1

typedef struct {
    int64_t type;
} error_t;

error_t *my_error_get(void);
void *my_error_throw(int64_t type);

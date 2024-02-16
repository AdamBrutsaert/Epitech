/*
** EPITECH PROJECT, 2022
** variant.h
** File description:
** Header of variant
*/

#pragma once

#include <stdint.h>
#include <wchar.h>
#include <unistd.h>
#include <stddef.h>

typedef enum {
    TYPE_UNDEFINED,
    TYPE_CHAR,
    TYPE_UNSIGNED_CHAR,
    TYPE_SHORT,
    TYPE_UNSIGNED_SHORT,
    TYPE_INT,
    TYPE_UNSIGNED_INT,
    TYPE_WINT,
    TYPE_LONG_INT,
    TYPE_UNSIGNED_LONG_INT,
    TYPE_LONG_LONG_INT,
    TYPE_UNSIGNED_LONG_LONG_INT,
    TYPE_SIZE,
    TYPE_SSIZE,
    TYPE_INT_MAX,
    TYPE_UNSIGNED_INT_MAX,
    TYPE_DOUBLE,
    TYPE_LONG_DOUBLE,
    TYPE_STRING,
    TYPE_WSTRING,
    TYPE_POINTER,
    TYPE_CHAR_POINTER,
    TYPE_PTRDIFF
} type_t;

typedef union {
    intmax_t as_int_max;
    uintmax_t as_unsigned_int_max;
    long double as_long_double;
    char const *as_string;
    wchar_t const *as_wstring;
    void *as_pointer;
} value_t;

typedef struct {
    type_t type;
    value_t value;
} variant_t;

typedef struct {
    variant_t *vars;
    uint32_t length;
    uint32_t capacity;
} variant_array_t;

variant_array_t *variant_array_create(void);
void variant_array_destroy(variant_array_t *array);
int32_t variant_array_push(variant_array_t *array, variant_t *variant);

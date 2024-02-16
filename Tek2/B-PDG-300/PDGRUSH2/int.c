/*
** EPITECH PROJECT, 2024
** int.c
** File description:
** int.c
*/

#define _GNU_SOURCE

#include "new.h"
#include <stdio.h>
#include "int.h"

typedef struct {
    Class base;
    int x;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
}

static char *Int_to_string(IntClass *this)
{
    char *str = calloc(100, sizeof(char));

    if (!str)
        raise("Out of memory");
    sprintf(str, "<Int (%d)>", this->x);
    return str;
}

static IntClass *Int_add(const IntClass *this, const IntClass *other)
{
    return new(Int, this->x + other->x);
}

static IntClass *Int_sub(const IntClass *this, const IntClass *other)
{
    return new(Int, this->x - other->x);
}

static IntClass *Int_mul(const IntClass *this, const IntClass *other)
{
    return new(Int, this->x * other->x);
}

static IntClass *Int_div(const IntClass *this, const IntClass *other)
{
    if (other->x == 0)
        raise("Division by zero");
    return new(Int, this->x / other->x);
}

static bool Int_eq(const IntClass *this, const IntClass *other)
{
    return this->x == other->x;
}

static bool Int_gt(const IntClass *this, const IntClass *other)
{
    return this->x > other->x;
}

static bool Int_lt(const IntClass *this, const IntClass *other)
{
    return this->x < other->x;
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_to_string,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;

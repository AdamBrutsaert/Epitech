/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Float
*/

#include "new.h"
#include "float.h"

#include <stdio.h>

typedef struct {
    Class base;
    float x;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
}

static char *Float_to_string(FloatClass *this)
{
    char *str = calloc(100, sizeof(char));

    if (!str)
        raise("Out of memory");
    sprintf(str, "<Float (%f)>", this->x);
    return str;
}

static Object *Float_add(FloatClass *v1, FloatClass *v2)
{
    return new(Float, v1->x + v2->x);
}

static Object *Float_sub(FloatClass *v1, FloatClass *v2)
{
    return new(Float, v1->x - v2->x);
}

static Object *Float_mul(FloatClass *v1, FloatClass *v2)
{
    return new(Float, v1->x * v2->x);
}

static Object *Float_div(FloatClass *v1, FloatClass *v2)
{
    if (v2->x == 0)
        raise("Division by zero");
    return new(Float, v1->x / v2->x);
}

static bool Float_eq(FloatClass *v1, FloatClass *v2)
{
    return (v1->x == v2->x);
}

static bool Float_gt(FloatClass *v1, FloatClass *v2)
{
    return (v1->x > v2->x);
}

static bool Float_lt(FloatClass *v1, FloatClass *v2)
{
    return (v1->x < v2->x);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_to_string,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt,
    },
    .x = 0.,
};

const Class *Float = (const Class *)&_description;

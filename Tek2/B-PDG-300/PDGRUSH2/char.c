/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include "new.h"
#include "char.h"

#include <stdio.h>

typedef struct
{
    Class base;
    char c;
}   CharClass;

static void char_ctor(CharClass *this, va_list *args)
{
    this->c = (char) va_arg(*args, int);
}

static void char_dtor(CharClass *this)
{
}

static char *char_to_string(CharClass *this)
{
    char *str = calloc(100, sizeof(char));

    if (!str)
        raise("Out of memory");
    sprintf(str, "<Char (%c)>", this->c);
    return str;
}

static Object *char_add(CharClass *v1, CharClass *v2)
{
    return new(Char, v1->c + v2->c);
}

static Object *char_sub(CharClass *v1, CharClass *v2)
{
    return new(Char, v1->c - v2->c);
}

static Object *char_mul(const Object *self, const Object *other)
{
    return new(Char, ((CharClass *)self)->c * ((CharClass *)other)->c);
}

static Object *char_div(const Object *self, const Object *other)
{
    if (((CharClass *)other)->c == 0)
        raise("Division by zero");
    return new(Char, ((CharClass *)self)->c / ((CharClass *)other)->c);
}

static bool char_eq(const Object *self, const Object *other)
{
    return ((CharClass *)self)->c == ((CharClass *)other)->c;
}

static bool char_gt(const Object *self, const Object *other)
{
    return ((CharClass *)self)->c > ((CharClass *)other)->c;
}

static bool char_lt(const Object *self, const Object *other)
{
    return ((CharClass *)self)->c < ((CharClass *)other)->c;
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "char",
        .__ctor__ = (ctor_t)&char_ctor,
        .__dtor__ = (dtor_t)&char_dtor,
        .__str__ = (to_string_t)&char_to_string,
        .__add__ = (binary_operator_t)&char_add,
        .__sub__ = (binary_operator_t)&char_sub,
        .__mul__ = (binary_operator_t)&char_mul,
        .__div__ = (binary_operator_t)&char_div,
        .__eq__ = (binary_comparator_t)&char_eq,
        .__gt__ = (binary_comparator_t)&char_gt,
        .__lt__ = (binary_comparator_t)&char_lt
    },
    .c = 0
};

const Class *Char = (const Class *)&_description;

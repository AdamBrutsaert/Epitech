/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include "new.h"
#include "point.h"

#include <stdio.h>

typedef struct
{
    Class base;
    int x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
}

static char *Point_to_string(PointClass *this)
{
    char *str = calloc(100, sizeof(char));

    if (!str)
        raise("Out of memory");
    sprintf(str, "<Point (%d, %d)>", this->x, this->y);
    return str;
}

static Object *Point_add(PointClass *v1, PointClass *v2)
{
    return new(Point, v1->x + v2->x, v1->y + v2->y);
}

static Object *Point_sub(PointClass *v1, PointClass *v2)
{
    return new(Point, v1->x - v2->x, v1->y - v2->y);
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_to_string,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;

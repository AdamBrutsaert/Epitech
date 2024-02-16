/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#define _GNU_SOURCE

#include "new.h"

#include <stdio.h>
#include "vertex.h"

typedef struct {
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
}

static char *Vertex_to_string(VertexClass *this)
{
    char *str;
    int r = asprintf(&str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);

    if (r == -1)
        raise("Out of memory");
    return str;
}

static Object *Vertex_add(VertexClass *v1, VertexClass *v2)
{
    return new(Vertex, v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
}

static Object *Vertex_sub(VertexClass *v1, VertexClass *v2)
{
    return new(Vertex, v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_to_string,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Vertex = (const Class *)&_description;

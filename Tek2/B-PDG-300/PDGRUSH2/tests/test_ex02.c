/*
** EPITECH PROJECT, 2024
** test_ex02.c
** File description:
** test_ex02.c
*/

#include "../new.h"
#include "../point.h"
#include "../vertex.h"

#include <criterion/criterion.h>

Test(point, test1)
{
    Object *point = new(Point, 42, -42);
    char *repr = str(point);

    cr_assert_str_eq(repr, "<Point (42, -42)>");
    delete(point);
    free(repr);
}

Test(point, test2)
{
    Object *point = new(Point, 0, 0);
    char *repr = str(point);

    cr_assert_str_eq(repr, "<Point (0, 0)>");
    delete(point);
    free(repr);
}

Test(vertex, test1)
{
    Object *point = new(Vertex, 0, 1, 2);
    char *repr = str(point);

    cr_assert_str_eq(repr, "<Vertex (0, 1, 2)>");
    delete(point);
    free(repr);
}

Test(vertex, test2)
{
    Object *point = new(Vertex, 0, 0, -42);
    char *repr = str(point);

    cr_assert_str_eq(repr, "<Vertex (0, 0, -42)>");
    delete(point);
    free(repr);
}

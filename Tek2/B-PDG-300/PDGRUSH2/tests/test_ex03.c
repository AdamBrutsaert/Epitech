/*
** EPITECH PROJECT, 2024
** test_ex03.c
** File description:
** test_ex03.c
*/

#include "../new.h"
#include "../point.h"
#include "../vertex.h"

#include <criterion/criterion.h>

Test(point, addition)
{
    Object *point1 = new(Point, 12, 13);
    Object *point2 = new(Point, 2, 2);
    Object *point3 = addition(point1, point2);
    char *repr = str(point3);

    cr_assert_str_eq(repr, "<Point (14, 15)>");

    delete(point1);
    delete(point2);
    delete(point3);
    free(repr);
}

Test(point, substraction)
{
    Object *point1 = new(Point, 12, 13);
    Object *point2 = new(Point, 2, 2);
    Object *point3 = subtraction(point1, point2);
    char *repr = str(point3);

    cr_assert_str_eq(repr, "<Point (10, 11)>");

    delete(point1);
    delete(point2);
    delete(point3);
    free(repr);
}

Test(vertex, addition)
{
    Object *point1 = new(Vertex, 1, 2, 3);
    Object *point2 = new(Vertex, 4, 5, 6);
    Object *point3 = addition(point1, point2);
    char *repr = str(point3);

    cr_assert_str_eq(repr, "<Vertex (5, 7, 9)>");

    delete(point1);
    delete(point2);
    delete(point3);
    free(repr);
}

Test(vertex, substraction)
{
    Object *point1 = new(Vertex, 1, 2, 3);
    Object *point2 = new(Vertex, 4, 5, 6);
    Object *point3 = subtraction(point1, point2);
    char *repr = str(point3);

    cr_assert_str_eq(repr, "<Vertex (-3, -3, -3)>");

    delete(point1);
    delete(point2);
    delete(point3);
    free(repr);
}

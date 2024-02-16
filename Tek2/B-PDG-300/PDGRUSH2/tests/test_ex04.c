/*
** EPITECH PROJECT, 2024
** test_ex04.c
** File description:
** test_ex04.c
*/

#include "../new.h"
#include "../int.h"
#include "../float.h"
#include "../char.h"

#include <criterion/criterion.h>

Test(int, addition)
{
    Object *int1 = new(Int, 12);
    Object *int2 = new(Int, 2);
    Object *int3 = addition(int1, int2);
    char *repr = str(int3);

    cr_assert_str_eq(repr, "<Int (14)>");

    delete(int1);
    delete(int2);
    delete(int3);
    free(repr);
}

Test(int, substraction)
{
    Object *int1 = new(Int, 12);
    Object *int2 = new(Int, 2);
    Object *int3 = subtraction(int1, int2);
    char *repr = str(int3);

    cr_assert_str_eq(repr, "<Int (10)>");

    delete(int1);
    delete(int2);
    delete(int3);
    free(repr);
}

Test(int, mul)
{
    Object *int1 = new(Int, 12);
    Object *int2 = new(Int, 2);
    Object *int3 = multiplication(int1, int2);
    char *repr = str(int3);

    cr_assert_str_eq(repr, "<Int (24)>");

    delete(int1);
    delete(int2);
    delete(int3);
    free(repr);
}

Test(int, div)
{
    Object *int1 = new(Int, 12);
    Object *int2 = new(Int, 2);
    Object *int3 = division(int1, int2);
    char *repr = str(int3);

    cr_assert_str_eq(repr, "<Int (6)>");

    delete(int1);
    delete(int2);
    delete(int3);
    free(repr);
}

Test(int, eq)
{
    Object *int1 = new(Int, 12);
    Object *int2 = new(Int, 2);
    bool int3 = eq(int1, int2);

    cr_assert_eq(int3, false);

    delete(int1);
    delete(int2);
}

Test(int, gt)
{
    Object *int1 = new(Int, 12);
    Object *int2 = new(Int, 2);
    bool int3 = gt(int1, int2);

    cr_assert_eq(int3, true);

    delete(int1);
    delete(int2);
}

Test(int, lt)
{
    Object *int1 = new(Int, 12);
    Object *int2 = new(Int, 2);
    bool int3 = lt(int1, int2);

    cr_assert_eq(int3, false);

    delete(int1);
    delete(int2);
}

Test(float, addition)
{
    Object *float1 = new(Float, 12.0);
    Object *float2 = new(Float, 2.0);
    Object *float3 = addition(float1, float2);
    char *repr = str(float3);

    cr_assert_str_eq(repr, "<Float (14.000000)>");

    delete(float1);
    delete(float2);
    delete(float3);
    free(repr);
}

Test(float, substraction)
{
    Object *float1 = new(Float, 12.0);
    Object *float2 = new(Float, 2.0);
    Object *float3 = subtraction(float1, float2);
    char *repr = str(float3);

    cr_assert_str_eq(repr, "<Float (10.000000)>");

    delete(float1);
    delete(float2);
    delete(float3);
    free(repr);
}

Test(float, mul)
{
    Object *float1 = new(Float, 12.0);
    Object *float2 = new(Float, 2.0);
    Object *float3 = multiplication(float1, float2);
    char *repr = str(float3);

    cr_assert_str_eq(repr, "<Float (24.000000)>");

    delete(float1);
    delete(float2);
    delete(float3);
    free(repr);
}

Test(float, div)
{
    Object *float1 = new(Float, 12.0);
    Object *float2 = new(Float, 2.0);
    Object *float3 = division(float1, float2);
    char *repr = str(float3);

    cr_assert_str_eq(repr, "<Float (6.000000)>");

    delete(float1);
    delete(float2);
    delete(float3);
    free(repr);
}

Test(float, eq)
{
    Object *float1 = new(Float, 12.0);
    Object *float2 = new(Float, 2.0);
    bool float3 = eq(float1, float2);

    cr_assert_eq(float3, false);

    delete(float1);
    delete(float2);
}

Test(float, gt)
{
    Object *float1 = new(Float, 12.0);
    Object *float2 = new(Float, 2.0);
    bool float3 = gt(float1, float2);

    cr_assert_eq(float3, true);

    delete(float1);
    delete(float2);
}

Test(float, lt)
{
    Object *float1 = new(Float, 12.0);
    Object *float2 = new(Float, 2.0);
    bool float3 = lt(float1, float2);

    cr_assert_eq(float3, false);

    delete(float1);
    delete(float2);
}

Test(char, addition)
{
    Object *char1 = new(Char, 'A');
    Object *char2 = new(Char, ' ');
    Object *char3 = addition(char1, char2);
    char *repr = str(char3);

    cr_assert_str_eq(repr, "<Char (a)>");

    delete(char1);
    delete(char2);
    delete(char3);
    free(repr);
}

Test(char, substraction)
{
    Object *char1 = new(Char, 'a');
    Object *char2 = new(Char, ' ');
    Object *char3 = subtraction(char1, char2);
    char *repr = str(char3);

    cr_assert_str_eq(repr, "<Char (A)>");

    delete(char1);
    delete(char2);
    delete(char3);
    free(repr);
}

Test(char, mul)
{
    Object *char1 = new(Char, 32);
    Object *char2 = new(Char, 2);
    Object *char3 = multiplication(char1, char2);
    char *repr = str(char3);

    cr_assert_str_eq(repr, "<Char (@)>");

    delete(char1);
    delete(char2);
    delete(char3);
    free(repr);
}

Test(char, div)
{
    Object *char1 = new(Char, 64);
    Object *char2 = new(Char, 2);
    Object *char3 = division(char1, char2);
    char *repr = str(char3);

    cr_assert_str_eq(repr, "<Char ( )>");

    delete(char1);
    delete(char2);
    delete(char3);
    free(repr);
}

Test(char, eq)
{
    Object *char1 = new(Char, 12);
    Object *char2 = new(Char, 2);
    bool char3 = eq(char1, char2);

    cr_assert_eq(char3, false);

    delete(char1);
    delete(char2);
}

Test(char, gt)
{
    Object *char1 = new(Char, 12);
    Object *char2 = new(Char, 2);
    bool char3 = gt(char1, char2);

    cr_assert_eq(char3, true);

    delete(char1);
    delete(char2);
}

Test(char, lt)
{
    Object *char1 = new(Char, 12);
    Object *char2 = new(Char, 2);
    bool char3 = lt(char1, char2);

    cr_assert_eq(char3, false);

    delete(char1);
    delete(char2);
}

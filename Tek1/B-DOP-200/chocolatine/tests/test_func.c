/*
** EPITECH PROJECT, 2023
** test_func.c
** File description:
** test_func.c
*/

#include <criterion/criterion.h>

#include "func.h"

Test(add, works)
{
    cr_assert_eq(add(1, 2), 3);
}

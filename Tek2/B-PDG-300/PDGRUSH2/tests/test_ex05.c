/*
** EPITECH PROJECT, 2024
** test_ex05.c
** File description:
** test_ex05.c
*/

#include "../new.h"
#include "../array.h"
#include "../int.h"

#include <criterion/criterion.h>

Test(array, test1)
{
    Object *array = new(Array, 10, Int, -1);
    setitem(array, 5, 12);
    setitem(array, 6, 13);

    cr_assert_eq(len(array), 10);
    cr_assert_str_eq(str(getitem(array, 0)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(array, 1)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(array, 2)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(array, 3)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(array, 4)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(array, 5)), "<Int (12)>");
    cr_assert_str_eq(str(getitem(array, 6)), "<Int (13)>");
    cr_assert_str_eq(str(getitem(array, 7)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(array, 8)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(array, 9)), "<Int (-1)>");
    delete(array);
}

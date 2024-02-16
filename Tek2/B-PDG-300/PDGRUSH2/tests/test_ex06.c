/*
** EPITECH PROJECT, 2024
** test_ex05.c
** File description:
** test_ex05.c
*/

#include "../new.h"
#include "../list.h"
#include "../int.h"

#include <criterion/criterion.h>

Test(list, test1)
{
    Object *list = new(List, 10, Int, -1);
    setitem(list, 5, 12);
    setitem(list, 6, 13);

    cr_assert_eq(len(list), 10);
    cr_assert_str_eq(str(getitem(list, 0)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(list, 1)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(list, 2)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(list, 3)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(list, 4)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(list, 5)), "<Int (12)>");
    cr_assert_str_eq(str(getitem(list, 6)), "<Int (13)>");
    cr_assert_str_eq(str(getitem(list, 7)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(list, 8)), "<Int (-1)>");
    cr_assert_str_eq(str(getitem(list, 9)), "<Int (-1)>");
    delete(list);
}

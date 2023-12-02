/*
** EPITECH PROJECT, 2022
** test_my_get_color
** File description:
** Implementation of test_my_get_color
*/

#include <criterion/criterion.h>

int get_color(unsigned char red, unsigned char green, unsigned char blue);

Test(get_color, colors)
{
    cr_assert_eq(get_color(255, 255, 255), 0xFFFFFF);
    cr_assert_eq(get_color(0, 0, 0), 0);
    cr_assert_eq(get_color(255, 0, 0), 0xFF0000);
    cr_assert_eq(get_color(0, 255, 0), 0xFF00);
    cr_assert_eq(get_color(0, 0, 255), 0xFF);
    cr_assert_eq(get_color(46, 184, 119), 0x2EB877);
}

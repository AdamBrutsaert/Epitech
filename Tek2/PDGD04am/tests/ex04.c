/*
** EPITECH PROJECT, 2024
** ex04.c
** File description:
** ex04.c
*/

#include "../ex04/print.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern void print_normal(const char *str);
extern void print_reverse(const char *str);
extern void print_upper(const char *str);
extern void print_42(const char *str);
extern void do_action(action_t action, const char *str);

Test(print_normal, test1, .init = cr_redirect_stdout)
{
    print_normal("hello world");
    cr_assert_stdout_eq_str("hello world\n");
}

Test(print_reverse, test1, .init = cr_redirect_stdout)
{
    print_reverse("hello world");
    cr_assert_stdout_eq_str("dlrow olleh\n");
}

Test(print_upper, test1, .init = cr_redirect_stdout)
{
    print_upper("hello world");
    cr_assert_stdout_eq_str("HELLO WORLD\n");
}

Test(print_42, test1, .init = cr_redirect_stdout)
{
    print_42("hello world");
    cr_assert_stdout_eq_str("42\n");
}

Test(do_action, test1, .init = cr_redirect_stdout)
{
    do_action(PRINT_NORMAL, "hello world");
    do_action(PRINT_REVERSE, "hello world");
    do_action(PRINT_UPPER, "hello world");
    do_action(PRINT_42, "hello world");
    cr_assert_stdout_eq_str("hello world\ndlrow olleh\nHELLO WORLD\n42\n");
}

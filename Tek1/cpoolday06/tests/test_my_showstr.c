/*
** EPITECH PROJECT, 2022
** test_my_showstr
** File description:
** Implementation of test_my_showstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern int my_showstr(char const *str);

Test(my_showstr, show, .init = cr_redirect_stdout)
{
    char str[33];

    str[0] = 'a';
    str[32] = '\0';
    for (char c = 1; c < 32; c++)
        str[c] = c;
    my_showstr(str);
    cr_assert_stdout_eq_str("a\\01\\02\\03\\04\\05\\06\\07\\08\\09\\0a" \
                            "\\0b\\0c\\0d\\0e\\0f\\10\\11\\12\\13\\14\\15" \
                            "\\16\\17\\18\\19\\1a\\1b\\1c\\1d\\1e\\1f");
}

/*
** EPITECH PROJECT, 2022
** test_cat
** File description:
** Implementation of test_cat
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "cat.h"

Test(cat, single, .init = cr_redirect_stdout)
{
    cat("../include/cat.h");
    cr_assert_stdout_eq_str(
        "/*" "\n"
        "** EPITECH PROJECT, 2022" "\n"
        "** cat" "\n"
        "** File description:" "\n"
        "** Header of cat" "\n"
        "*/" "\n"
        "\n"
        "#pragma once" "\n"
        "\n"
        "int cat(char const *path);" "\n"
        "int cat_stdin(void);" "\n"
    );
}

Test(cat, stdin)
{
    cr_redirect_stdin();
    cr_redirect_stdout();
    fprintf(cr_get_redirected_stdin(), "Hello, world\n");
    fclose(cr_get_redirected_stdin());
    cat_stdin();
    cr_assert_stdout_eq_str("Hello, world\n");
}

Test(cat, directory, .init = cr_redirect_stderr)
{
    cat("../include");
    cr_assert_stderr_eq_str("cat: ../include: File is a directory\n");
}

Test(cat, unallowed, .init = cr_redirect_stderr)
{
    cat("/root");
    cr_assert_stderr_eq_str("cat: /root: Permission denied\n");
}

Test(cat, unexistent, .init = cr_redirect_stderr)
{
    cat("dontexist.txt");
    cr_assert_stderr_eq_str("cat: dontexist.txt: No such file or directory\n");
}

/*
** EPITECH PROJECT, 2022
** test_grep
** File description:
** Implementation of test_grep
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "grep.h"

Test(grep, single, .init = cr_redirect_stdout)
{
    grep("grep", "../include/grep.h");
    cr_assert_stdout_eq_str(
        "** grep" "\n"
        "** Header of grep" "\n"
        "int grep(char const *token, char const *path);" "\n"
        "int grep_stdin(char const *token);" "\n"
    );
}

Test(grep, stdin)
{
    cr_redirect_stdin();
    cr_redirect_stdout();
    fprintf(cr_get_redirected_stdin(), "hello\nworld\njfieihe\n");
    fclose(cr_get_redirected_stdin());
    grep_stdin("he");
    cr_assert_stdout_eq_str("hello\njfieihe\n");
}

Test(grep, directory,  .init = cr_redirect_stderr)
{
    grep("test", "../include");
    cr_assert_stderr_eq_str("grep: ../include: File is a directory\n");
}

Test(grep, unallowed, .init = cr_redirect_stderr)
{
    grep("test", "/root");
    cr_assert_stderr_eq_str("grep: /root: Permission denied\n");
}

Test(grep, unexistent, .init = cr_redirect_stderr)
{
    grep("test", "dontexist.txt");
    cr_assert_stderr_eq_str("grep: dontexist.txt: No such file or directory\n");
}

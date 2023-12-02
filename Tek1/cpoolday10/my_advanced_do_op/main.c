/*
** EPITECH PROJECT, 2022
** main
** File description:
** Implementation of main
*/

#include <unistd.h>
#include "my.h"
#include "operation.h"
#include "my_opp.h"

static unsigned int get_count_of_operators(void)
{
    return sizeof(OPERATORS_FUNCS) / sizeof(struct operator);
}

static char is_string_empty(char const *str)
{
    if (str == 0)
        return 1;
    for (; *str; str++) {
        if (*str != ' ')
            return 0;
    }
    return 1;
}

static int dispatch(int a, char const *operator, int b)
{
    char const *token = 0;
    int (*func)(int, int) = 0;
    int (*empty_func)(int, int) = 0;
    unsigned int count = get_count_of_operators();

    for (unsigned int i = 0; i < count; i++) {
        token = OPERATORS_FUNCS[i].token;
        func = OPERATORS_FUNCS[i].func;
        if (token && is_string_empty(token))
            empty_func = func;
        if (token && !is_string_empty(token)
            && my_strncmp(token, operator, my_strlen(token)) == 0)
            return func ? func(a, b) : 84;
    }
    return empty_func ? empty_func(a, b) : 84;
}

int my_usage(int a, int b)
{
    char const *token;
    unsigned int count = get_count_of_operators();

    write(2, "error: only [ ", 14);
    for (unsigned int i = 0; i < count; i++) {
        token = OPERATORS_FUNCS[i].token;
        if (token && !is_string_empty(token)) {
            write(2, token, my_strlen(token));
            write(2, " ", 1);
        }
    }
    write(2, "] are supported\n", 16);
    return 84;
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return 84;
    return dispatch(my_getnbr(argv[1]), argv[2], my_getnbr(argv[3]));
}

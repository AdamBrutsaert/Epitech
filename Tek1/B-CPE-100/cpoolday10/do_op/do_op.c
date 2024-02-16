/*
** EPITECH PROJECT, 2022
** do_op
** File description:
** Implementation do_op
*/

#include "my.h"

extern int do_add(int a, int b);
extern int do_sub(int a, int b);
extern int do_mul(int a, int b);
extern int do_div(int a, int b);
extern int do_mod(int a, int b);

static int convert_operator(char *op)
{
    switch (*op) {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '%': return 4;
        default: return 84;
    }
}

static int dispatch(int a, int op, int b)
{
    static int (*ops[5])(int a, int b) = {
        do_add, do_sub, do_mul, do_div, do_mod};
    return ops[op](a, b);
}

static int do_op(char *arg1, char *arg2, char *arg3)
{
    int a = my_getnbr(arg1);
    int op = convert_operator(arg2);
    int b = my_getnbr(arg3);

    if (op == 84) {
        my_putstr("0\n");
        return 84;
    }
    return dispatch(a, op, b);
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return 84;
    return do_op(argv[1], argv[2], argv[3]);
}

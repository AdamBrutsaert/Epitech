/*
** EPITECH PROJECT, 2022
** pushswap.c
** File description:
** pushswap.c
*/

#include "pushswap/pushswap.h"
#include "pushswap/pushswap_parser.h"

#include "my/conversion.h"
#include "my/stdio.h"

static status_t handle_0_1_number(int argc, char **argv)
{
    int32_t number;

    if (argc == 1) {
        my_printc('\n');
        return STATUS_SUCCESS;
    }
    if (strict_str_to_i32(argv[1], &number) == STATUS_ERROR)
        return STATUS_ERROR;
    my_printc('\n');
    return STATUS_SUCCESS;
}

status_t pushswap(int argc, char **argv)
{
    pushswap_t ps;

    if (argc <= 2)
        return handle_0_1_number(argc, argv);
    if (pushswap_create(&ps) == STATUS_ERROR) {
        pushswap_destroy(&ps);
        return STATUS_ERROR;
    }
    if (pushswap_parse(&ps, argc, argv) == STATUS_ERROR) {
        pushswap_destroy(&ps);
        return STATUS_ERROR;
    }
    pushswap_sort(&ps);
    pushswap_print_operations(&ps);
    pushswap_destroy(&ps);
    return STATUS_SUCCESS;
}

/*
** EPITECH PROJECT, 2022
** argp.c
** File description:
** argp.c
*/

#include "my/details/argp.h"
#include "my/stdio.h"

#include <stddef.h>

static int32_t parse_short_flag(my_argp_t *argp, char *arg, char *value,
    int *error)
{
    int32_t index;
    char *v;
    int8_t processed_value = 0;

    for (arg++; *arg; arg++) {
        v = NULL;
        index = get_key_index(argp, *arg);
        if (!arg[1] && argp->options[index].flags & MY_ARGP_FLAG_PARAMETER)
            v = value;
        if (index != -1) {
            processed_value |= v != NULL;
            (*argp->on_argument)(*arg, v, argp->configuration);
        } else {
            *error = 84;
            my_eprints("error: invalid option \"-");
            my_eprintc(*arg);
            my_eprints("\"\n");
        }
    }
    return processed_value;
}

static int32_t parse_long_flag(my_argp_t *argp, char *arg, char *value,
    int *error)
{
    int16_t key = get_long_flag_key(argp, arg + 2);
    int32_t index = get_key_index(argp, key);

    if (key && argp->options[index].flags & MY_ARGP_FLAG_PARAMETER) {
        (*argp->on_argument)(key, value, argp->configuration);
        return 1;
    }
    if (key) {
        (*argp->on_argument)(key, 0, argp->configuration);
        return 0;
    }
    *error = 84;
    my_eprints("error: invalid option \"");
    my_eprints(arg);
    my_eprints("\"\n");
    return 0;
}

int32_t my_argp_parse(my_argp_t *argp, int argc, char **argv)
{
    int32_t error = 0;
    int8_t stop_flag = 0;
    char *value;

    for (int i = 1; i < argc; i++) {
        stop_flag |= is_stop_flag(argv[i]);
        value = (i + 1 != argc && !is_flag(argv[i + 1])) ? argv[i + 1] : 0;
        if (!stop_flag && is_short_flag(argv[i])) {
            i += parse_short_flag(argp, argv[i], value, &error);
            continue;
        }
        if (!stop_flag && is_long_flag(argv[i])) {
            i += parse_long_flag(argp, argv[i], value, &error);
            continue;
        }
        (*argp->on_argument)(MY_ARGP_KEY_ARG, argv[i], argp->configuration);
    }
    return error;
}

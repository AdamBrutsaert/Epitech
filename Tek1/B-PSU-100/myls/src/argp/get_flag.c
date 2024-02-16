/*
** EPITECH PROJECT, 2022
** get_flag.c
** File description:
** get_flag.c
*/

#include "my/details/argp.h"
#include "my/string.h"

int32_t get_key_index(my_argp_t *argp, int16_t flag)
{
    for (uint16_t i = 0; argp->options[i].key; i++) {
        if (argp->options[i].key == flag)
            return i;
    }
    return -1;
}

int16_t get_long_flag_key(my_argp_t *argp, char const *flag)
{
    for (uint16_t i = 0; argp->options[i].key; i++) {
        if (argp->options->name && !my_strcmp(argp->options[i].name, flag))
            return argp->options[i].key;
    }
    return 0;
}

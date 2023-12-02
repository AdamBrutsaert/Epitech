/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "bsq.h"

static uint64_t my_stou64(char const *str)
{
    uint64_t nb = 0;

    for (; *str >= '0' && *str <= '9'; str++)
        nb = nb * 10 + (*str - '0');
    return nb;
}

int main(int argc, char **argv)
{
    if (argc == 2)
        return bsq_from_file(argv[1]);
    if (argc == 3)
        return bsq_from_pattern(my_stou64(argv[1]), argv[2]);
    return 84;
}

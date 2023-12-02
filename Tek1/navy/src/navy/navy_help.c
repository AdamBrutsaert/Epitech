/*
** EPITECH PROJECT, 2023
** navy_help.c
** File description:
** navy_help.c
*/

#include "navy.h"

#include "my.h"

void navy_help(char const *program)
{
    my_puts("USAGE\n     ");
    my_puts(program);
    my_puts(" [first_player_pid] navy_positions\n");
    my_puts("DESCRIPTION\n");
    my_puts("     first_player_pid: only for the 2nd player. pid of the ");
    my_puts("first player.\n     navy_positions: file representing the ");
    my_puts("positions of the ships.\n");
}

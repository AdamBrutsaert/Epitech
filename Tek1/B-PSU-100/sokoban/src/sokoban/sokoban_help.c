/*
** EPITECH PROJECT, 2022
** sokoban_help.c
** File description:
** sokoban_help.c
*/

#include "sokoban/sokoban.h"
#include "my/stdio.h"

status_t sokoban_help(char *program)
{
    my_prints("USAGE\n");
    my_prints("     ");
    my_prints(program);
    my_prints(" map\n");
    my_prints("DESCRIPTION\n");
    my_prints("     map  file representing the warehouse map, containing ");
    my_prints("'#' for walls,\n");
    my_prints("          'P' for the player, 'X' for boxes and 'O' for ");
    my_prints("storage locations.\n");
    return 0;
}

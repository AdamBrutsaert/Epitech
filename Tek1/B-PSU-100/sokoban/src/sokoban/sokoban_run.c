/*
** EPITECH PROJECT, 2022
** sokoban_run.c
** File description:
** sokoban_run.c
*/

#include "sokoban/sokoban.h"
#include <ncurses.h>

status_t sokoban_run(sokoban_map_t *map)
{
    status_t status;

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    sokoban_map_draw(map);
    do {
        status = sokoban_process_input(map, getch());
        if (status)
            break;
        sokoban_map_draw(map);
        status = sokoban_map_get_status(map);
    } while (status == -1);
    endwin();
    return status;
}

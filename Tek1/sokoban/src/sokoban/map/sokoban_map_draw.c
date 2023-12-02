/*
** EPITECH PROJECT, 2022
** sokoban_map_draw.c
** File description:
** sokoban_map_draw.c
*/

#include "sokoban/map/sokoban_map.h"
#include "my/string.h"

#include <ncurses.h>

static void draw_map(sokoban_map_t *map)
{
    position_t *pos;

    for (u32_t i = 0; i < map->height; i++)
        printw("%s\n", map->rows[i]);
    for (u32_t i = 0; i < map->boxes.length; i++) {
        pos = vector_get(&map->boxes, i);
        mvaddch(pos->row, pos->column, 'X');
    }
    for (u32_t i = 0; i < map->objectives.length; i++) {
        pos = vector_get(&map->objectives, i);
        if (!sokoban_map_is_obstacle(map, pos->row, pos->column))
            mvaddch(pos->row, pos->column, 'O');
    }
    mvaddch(map->player.row, map->player.column, 'P');
    move(map->player.row, map->player.column);
}

static void draw_message(u32_t rows, u32_t columns)
{
    char const *message = "Please enlarge your terminal";

    mvprintw(rows / 2, (columns - my_strlen(message)) / 2, "%s", message);
}

void sokoban_map_draw(sokoban_map_t *map)
{
    u32_t rows;
    u32_t columns;

    getmaxyx(stdscr, rows, columns);
    clear();
    if (rows < map->height || columns < map->width) {
        draw_message(rows, columns);
    } else {
        draw_map(map);
    }
    refresh();
}

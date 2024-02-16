/*
** EPITECH PROJECT, 2023
** navy_show_positions.c
** File description:
** navy_show_positions.c
*/

#include "navy.h"
#include "my.h"

static void draw_box(int8_t box)
{
    if (box == NAVY_EMPTY)
        my_putc('.');
    if (box == NAVY_SHIP_2)
        my_putc('2');
    if (box == NAVY_SHIP_3)
        my_putc('3');
    if (box == NAVY_SHIP_4)
        my_putc('4');
    if (box == NAVY_SHIP_5)
        my_putc('5');
    if (box == NAVY_HIT)
        my_putc('x');
    if (box == NAVY_MISS)
        my_putc('o');
}

static void draw_board(int8_t board[8][8])
{
    int8_t line;
    int8_t column;

    my_puts(" |A B C D E F G H\n");
    my_puts("-+---------------\n");
    for (uint8_t i = 0; i < 64; i++) {
        line = i / 8;
        column = i % 8;
        if (column == 0) {
            my_puti(line + 1);
            my_putc('|');
        }
        draw_box(board[line][column]);
        if (column == 7) {
            my_putc('\n');
        } else {
            my_putc(' ');
        }
    }
    my_putc('\n');
}

void navy_show_positions(navy_t *navy)
{
    my_puts("my positions:\n");
    draw_board(navy->self);
    my_puts("enemy's positions:\n");
    draw_board(navy->opponent);
}

/*
** EPITECH PROJECT, 2023
** navy_check_win.c
** File description:
** navy_check_win.c
*/

#include "navy.h"

int8_t navy_check_win(navy_t *navy)
{
    uint32_t count = 0;
    int8_t line;
    int8_t column;

    for (uint8_t i = 0; i < 64; i++) {
        line = i / 8;
        column = i % 8;
        if (navy->opponent[line][column] == NAVY_HIT)
            count++;
    }
    return count == 2 + 3 + 4 + 5;
}

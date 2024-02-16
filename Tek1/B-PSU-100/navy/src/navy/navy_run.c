/*
** EPITECH PROJECT, 2023
** navy_run.c
** File description:
** navy_run.c
*/

#include "navy.h"
#include "my.h"

#include "network.h"

static int8_t play_turn(navy_t *navy)
{
    if (navy->first == SELF) {
        if (navy_attack(navy) == 84)
            return 84;
        if (navy_check_win(navy))
            return WIN;
        if (navy_defend(navy) == 84)
            return 84;
        if (navy_check_lose(navy))
            return LOSE;
    } else {
        if (navy_defend(navy) == 84)
            return 84;
        if (navy_check_lose(navy))
            return LOSE;
        if (navy_attack(navy) == 84)
            return 84;
        if (navy_check_win(navy))
            return WIN;
    }
    return NONE;
}

int8_t navy_run(navy_t *navy)
{
    int8_t result;

    while (1) {
        navy_show_positions(navy);
        result = play_turn(navy);
        if (result == 84)
            return 84;
        if (result == WIN) {
            my_puts("I won\n");
            return 0;
        }
        if (result == LOSE) {
            my_puts("Enemy won\n");
            return 1;
        }
    }
}

/*
** EPITECH PROJECT, 2023
** navy_defend.c
** File description:
** navy_defend.c
*/

#include "navy.h"
#include "network.h"
#include "my.h"

int8_t navy_defend(navy_t *navy)
{
    int8_t line;
    int8_t column;

    my_puts("waiting for enemy's attack...\n");
    network_receive_position(&line, &column);
    my_putc('A' + column);
    my_putc('1' + line);
    if (navy->self[line][column] >= NAVY_SHIP_2) {
        my_puts(": hit\n\n");
        navy->self[line][column] = NAVY_HIT;
        return network_send_status(NAVY_HIT);
    }
    if (navy->self[line][column] == NAVY_HIT) {
        my_puts(": missed\n\n");
        return network_send_status(NAVY_HIT);
    }
    my_puts(": missed\n\n");
    navy->self[line][column] = NAVY_MISS;
    return network_send_status(NAVY_MISS);
}

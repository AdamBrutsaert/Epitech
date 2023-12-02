/*
** EPITECH PROJECT, 2023
** navy_attack.c
** File description:
** navy_attack.c
*/

#include "navy.h"
#include "my.h"
#include "network.h"

#include <stdio.h>
#include <stdlib.h>

static int8_t check_position(char const *position)
{
    if (my_strlen(position) != 3)
        return 84;
    if (position[0] < 'A' || position[0] > 'H')
        return 84;
    if (position[1] < '1' || position[1] > '8')
        return 84;
    return 0;
}

static int8_t process_position(navy_t *navy, char const *position)
{
    int8_t line = position[1] - '1';
    int8_t column = position[0] - 'A';
    int8_t status = navy->opponent[line][column];

    if (network_send_position(line, column) == 84)
        return 84;
    navy->opponent[line][column] = network_receive_status();
    my_putc('A' + column);
    my_putc('1' + line);
    if (navy->opponent[line][column] == NAVY_HIT
        && status != NAVY_HIT) {
        my_puts(": hit\n\n");
    } else {
        my_puts(": missed\n\n");
    }
    return 0;
}

int8_t navy_attack(navy_t *navy)
{
    char *position = NULL;
    size_t n = 0;

    my_puts("attack: ");
    if (getline(&position, &n, stdin) == -1)
        return 84;
    while (check_position(position) == 84) {
        my_puts("wrong position\n");
        my_puts("attack: ");
        if (getline(&position, &n, stdin) == -1)
            return 84;
    }
    if (process_position(navy, position) == 84) {
        free(position);
        return 84;
    }
    free(position);
    return 0;
}

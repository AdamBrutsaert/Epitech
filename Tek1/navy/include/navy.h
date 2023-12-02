/*
** EPITECH PROJECT, 2023
** navy.h
** File description:
** navy.h
*/

#pragma once

#include <stdint.h>

#define NAVY_EMPTY   0
#define NAVY_SHIP_2  2
#define NAVY_SHIP_3  3
#define NAVY_SHIP_4  4
#define NAVY_SHIP_5  5
#define NAVY_MISS   -1
#define NAVY_HIT    -2

#define SELF     0
#define OPPONENT 1

#define NONE 0
#define WIN  1
#define LOSE 2

typedef struct {
    int8_t first;
    int8_t self[8][8];
    int8_t opponent[8][8];
} navy_t;

int8_t navy_from_arguments(int argc, char **argv);

navy_t *navy_create(void);
void navy_destroy(navy_t *navy);

int8_t navy_parse_file(navy_t *navy, char const *path);
void navy_help(char const *program);

int8_t navy_run(navy_t *navy);
int8_t navy_attack(navy_t *navy);
int8_t navy_defend(navy_t *navy);
void navy_show_positions(navy_t *navy);

int8_t navy_check_win(navy_t *navy);
int8_t navy_check_lose(navy_t *navy);

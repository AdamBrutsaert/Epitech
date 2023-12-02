/*
** EPITECH PROJECT, 2023
** ant.h
** File description:
** ant.h
*/

#pragma once

#include "room.h"

#include <stddef.h>

typedef struct ant ant_t;

ant_t *ant_new(void);
void ant_delete(ant_t *ant);
size_t ant_get_id(ant_t *ant);
size_t ant_get_step(ant_t *ant);
void ant_set_step(ant_t *ant, size_t step);
void ant_print(ant_t *ant, room_t *room);

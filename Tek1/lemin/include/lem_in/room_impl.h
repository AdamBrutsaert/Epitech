/*
** EPITECH PROJECT, 2023
** room_impl.h
** File description:
** room_impl.h
*/

#pragma once

#include "room.h"

struct room {
    size_t id;
    int32_t x;
    int32_t y;
    char *name;
    bool visited;
    size_t previous_id;
};

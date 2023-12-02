/*
** EPITECH PROJECT, 2023
** path_impl.h
** File description:
** path_impl.h
*/

#pragma once

#include "path.h"
#include "ant.h"

struct path {
    room_t **rooms;
    size_t length;
    size_t capacity;
    size_t ant_count;
    ant_t **ants;
    size_t ant_capacity;
    size_t ant_length;
};

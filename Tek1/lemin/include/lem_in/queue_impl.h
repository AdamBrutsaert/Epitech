/*
** EPITECH PROJECT, 2023
** queue_impl.h
** File description:
** queue_impl.h
*/

#pragma once

#include "queue.h"

struct queue {
    room_t **rooms;
    size_t length;
    size_t capacity;
};

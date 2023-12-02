/*
** EPITECH PROJECT, 2022
** deque.h
** File description:
** deque.h
*/

#pragma once

#include "types.h"

typedef struct {
    void *values;
    u64_t capacity;
    u64_t length;
    u64_t stride;
    u64_t front;
    u64_t back;
} deque_t;

status_t deque_create(deque_t *deque, u64_t stride);
void deque_destroy(deque_t *deque);

status_t deque_push_back(deque_t *deque, void const *value);
status_t deque_push_front(deque_t *deque, void const *value);

bool_t deque_pop_back(deque_t *deque, void *value);
bool_t deque_pop_front(deque_t *deque, void *value);
void deque_clear(deque_t *deque);

void const *deque_get(deque_t *deque, u64_t index);
status_t deque_set(deque_t *deque, u64_t index, void const *value);

status_t deque_reserve(deque_t *deque, u64_t capacity);

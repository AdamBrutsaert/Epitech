/*
** EPITECH PROJECT, 2023
** view.h
** File description:
** view.h
*/

#pragma once

#include <stdint.h>

typedef struct {
    char *content;
    uint64_t back;
    uint64_t front;
    uint64_t length;
    uint64_t capacity;
} view_t;

view_t *view_create(uint64_t capacity);
void view_destroy(view_t *view);

char view_get(view_t *view, uint64_t index);
void view_append(view_t *view, char c);

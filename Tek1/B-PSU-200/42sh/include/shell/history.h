/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-yanis.zeghiche
** File description:
** history
*/

#pragma once

#include <time.h>

typedef struct {
    time_t time;
    char *cmd;
} history_t;

struct history_entry {
    size_t pos;
    history_t *entry;
};

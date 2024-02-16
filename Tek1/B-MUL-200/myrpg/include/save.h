/*
** EPITECH PROJECT, 2023
** save.h
** File description:
** save.h
*/

#pragma once


#include <stdint.h>

typedef struct {
    uint32_t has_red_pot;
    uint32_t has_blue_pot;
} state_t;

extern state_t STATE;

void save_read(void);
void save_write(void);

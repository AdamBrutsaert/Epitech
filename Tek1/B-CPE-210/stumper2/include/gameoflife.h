/*
** EPITECH PROJECT, 2023
** gameoflife.h
** File description:
** gameoflife.h
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

typedef struct {
    char *current;
    char *next;
    ssize_t width;
    ssize_t height;
} gol_t;

gol_t *gol_create(const char *file);
void gol_destroy(gol_t *gol);

bool gol_check_map(gol_t *gol);

void gol_run(gol_t *gol, uint32_t count);
void gol_print(gol_t *gol);

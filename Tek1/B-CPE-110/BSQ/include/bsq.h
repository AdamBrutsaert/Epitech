/*
** EPITECH PROJECT, 2022
** bsq.h
** File description:
** bsq.h
*/

#pragma once

#include <stdint.h>

#define IS_DIGIT(x) (x >= '0' && x <= '9')
#define MIN2(x, y) (x < y ? x : y)
#define MIN3(x, y, z) MIN2(MIN2(x, y), z)

typedef struct {
    uint64_t capacity;
    void *buffer;

    char *i8_beg_ptr;
    char *i8_end_ptr;

    uint64_t lines;
    uint64_t columns;

    uint64_t max_size;
    uint64_t max_index;
} bsq_t;

int8_t bsq_from_file(char const *path);
int8_t bsq_from_pattern(uint64_t size, char const *pattern);

int8_t bsq_run_file(bsq_t *bsq);
int8_t bsq_run_pattern(bsq_t *bsq, uint64_t size);
void bsq_show(bsq_t *bsq);

/*
** EPITECH PROJECT, 2022
** bsq_show.c
** File description:
** bsq_show.c
*/

#include "bsq.h"

#include <unistd.h>

static void convert_back_map(bsq_t *bsq)
{
    uint16_t *u16_beg_ptr = ((uint16_t*)bsq->buffer
        + bsq->capacity / 2 - bsq->lines * bsq->columns);
    uint64_t offset = 0;

    for (uint64_t i = 0; i < bsq->lines * (bsq->columns + 1); i++) {
        if ((i + 1) % (bsq->columns + 1) == 0) {
            bsq->i8_beg_ptr[i] = '\n';
            offset++;
        } else {
            bsq->i8_beg_ptr[i] = u16_beg_ptr[i - offset] ? '.' : 'o';
        }
    }
    *bsq->i8_end_ptr = '\0';
}

static void insert_biggest_square(bsq_t *bsq)
{
    uint64_t max_index = bsq->max_index
        - (bsq->capacity / 2 - bsq->lines * bsq->columns);
    uint64_t line = max_index / bsq->columns;
    uint64_t column = max_index % bsq->columns;
    uint64_t offset = line * (bsq->columns + 1) + column;

    for (uint64_t i = 0; i < bsq->max_size; i++) {
        for (uint64_t j = 0; j < bsq->max_size; j++)
            bsq->i8_beg_ptr[offset + i * (bsq->columns + 1) + j] = 'x';
    }
}

void bsq_show(bsq_t *bsq)
{
    convert_back_map(bsq);
    insert_biggest_square(bsq);
    write(STDOUT_FILENO, bsq->i8_beg_ptr, bsq->lines * (bsq->columns + 1));
}

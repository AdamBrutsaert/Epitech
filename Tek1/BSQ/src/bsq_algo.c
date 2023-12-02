/*
** EPITECH PROJECT, 2022
** bsq_algo.c
** File description:
** bsq_algo.c
*/

#include "bsq.h"

static int8_t retrieve_length(bsq_t *bsq)
{
    for (; IS_DIGIT(*bsq->i8_beg_ptr); bsq->i8_beg_ptr++)
        bsq->lines = bsq->lines * 10 + (*bsq->i8_beg_ptr - '0');
    bsq->i8_beg_ptr++;
    return IS_DIGIT(*(char*)bsq->buffer) && *(bsq->i8_beg_ptr - 1) == '\n';
}

static int8_t convert_map(bsq_t *bsq)
{
    uint64_t index = bsq->capacity / 2 - 1;
    uint64_t lines = 0;
    uint64_t columns = 0;
    char *end = bsq->i8_end_ptr - 2;

    for (; end != bsq->i8_beg_ptr - 1; end--) {
        if ((*end == '\n' && lines && columns != bsq->columns)
            || (*end != '\n' && *end != '.' && *end != 'o'))
            return 0;
        if (*end == '\n') {
            lines++;
            columns = 0;
            continue;
        }
        ((uint16_t*)bsq->buffer)[index] = (*end == '.');
        bsq->columns += (lines == 0);
        columns++;
        index--;
    }
    return bsq->lines == lines + 1;
}

static void apply_algo(bsq_t *bsq)
{
    uint16_t *buffer = (uint16_t*)bsq->buffer;
    uint64_t line;
    uint64_t column;
    uint64_t index;

    for (uint64_t i = 0; i < bsq->lines * bsq->columns; i++) {
        line = i / bsq->columns;
        column = i % bsq->columns;
        index = bsq->capacity / 2 - 1 - line * bsq->columns - column;
        if (buffer[index] == 1 && line != 0 && column != 0) {
            buffer[index] = MIN3(buffer[index + 1],
                buffer[index + bsq->columns],
                buffer[index + bsq->columns + 1]) + 1;
        }
        if (buffer[index] >= buffer[bsq->max_index]) {
            bsq->max_size = buffer[index];
            bsq->max_index = index;
        }
    }
}

int8_t bsq_run_file(bsq_t *bsq)
{
    bsq->i8_beg_ptr = (char*)bsq->buffer;
    bsq->i8_end_ptr = (char*)bsq->buffer;
    bsq->lines = 0;
    bsq->columns = 0;
    bsq->max_index = bsq->capacity / 2 - 1;
    bsq->max_size = 0;

    while (*bsq->i8_end_ptr)
        bsq->i8_end_ptr++;
    if (!retrieve_length(bsq))
        return 84;
    if (!convert_map(bsq))
        return 84;
    apply_algo(bsq);
    bsq_show(bsq);
    return 0;
}

int8_t bsq_run_pattern(bsq_t *bsq, uint64_t size)
{
    bsq->i8_beg_ptr = (char*)bsq->buffer;
    bsq->i8_end_ptr = (char*)bsq->buffer;
    bsq->lines = size;
    bsq->columns = 0;
    bsq->max_index = bsq->capacity / 2 - 1;
    bsq->max_size = 0;

    while (*bsq->i8_end_ptr)
        bsq->i8_end_ptr++;
    if (!convert_map(bsq))
        return 84;
    apply_algo(bsq);
    bsq_show(bsq);
    return 0;
}

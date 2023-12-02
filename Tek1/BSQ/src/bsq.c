/*
** EPITECH PROJECT, 2022
** bsq.c
** File description:
** bsq.c
*/

#include "bsq.h"
#include "file.h"

#include <stdlib.h>

static int8_t allocate_buffer(void **buffer, uint64_t size)
{
    *buffer = malloc(size);
    return *buffer != NULL;
}

static uint64_t my_strlen(char const *str)
{
    uint64_t length = 0;

    while (str[length])
        length++;
    return length;
}

static int8_t generate_map(uint64_t size, char const *pattern, char *buffer)
{
    uint64_t pattern_length = my_strlen(pattern);
    uint64_t offset = 0;

    if (!pattern_length)
        return 0;
    for (uint64_t i = 0; i < size * (size + 1); i++) {
        if ((i + 1) % (size + 1) == 0) {
            buffer[i] = '\n';
            offset++;
        } else {
            buffer[i] = pattern[(i - offset) % pattern_length];
        }
    }
    buffer[size * (size + 1)] = '\0';
    return 1;
}

int8_t bsq_from_file(char const *path)
{
    bsq_t bsq;
    file_t file;
    int r;

    if (!file_open(&file, path))
        return 84;
    bsq.capacity = file.length * sizeof(uint16_t);
    if (!allocate_buffer(&bsq.buffer, bsq.capacity)) {
        file_close(&file);
        return 84;
    }
    if (!file_read(&file, (char *)bsq.buffer)) {
        file_close(&file);
        free(bsq.buffer);
        return 84;
    }
    r = bsq_run_file(&bsq);
    free(bsq.buffer);
    file_close(&file);
    return r;
}

int8_t bsq_from_pattern(uint64_t size, char const *pattern)
{
    bsq_t bsq;
    int8_t r;

    bsq.capacity = size * size * sizeof(uint16_t);
    if (!allocate_buffer(&bsq.buffer, bsq.capacity))
        return 84;
    if (!generate_map(size, pattern, (char *)bsq.buffer))
        return 84;
    r = bsq_run_pattern(&bsq, size);
    free(bsq.buffer);
    return r;
}

/*
** EPITECH PROJECT, 2023
** reader.h
** File description:
** reader.h
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    char *buffer;
    size_t length;
    size_t current;
    bool eof;
} reader_t;

reader_t *reader_create(void);
void reader_destroy(reader_t *reader);

void reader_clear(reader_t *reader);
void reader_read_line(reader_t *reader);

bool reader_is_end(reader_t *reader);
bool reader_is_eof(reader_t *reader);
char reader_next(reader_t *reader);
char reader_peek(reader_t *reader);
char *reader_get_back(reader_t *reader, size_t bytes);

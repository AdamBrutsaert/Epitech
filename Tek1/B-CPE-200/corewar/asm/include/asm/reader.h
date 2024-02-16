/*
** EPITECH PROJECT, 2023
** reader.h
** File description:
** reader.h
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct reader reader_t;

reader_t *reader_new(void);
void reader_delete(reader_t *reader);

void reader_clear(reader_t *reader);
bool reader_push_file(reader_t *reader, const char *filepath);

size_t reader_get_line_number(reader_t *reader);
void reader_skip_line(reader_t *reader);
bool reader_match(reader_t *reader, const char *string);

char reader_peek(reader_t *reader, size_t offset);
char reader_next(reader_t *reader, size_t offset);

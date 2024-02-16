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
bool reader_push(reader_t *reader, const char *string);
bool reader_push_stdin(reader_t *reader);
bool reader_push_stdin_line(reader_t *reader);

char reader_peek(reader_t *reader, size_t n);
char reader_next(reader_t *reader);

char *reader_dup_previous(reader_t *reader, size_t n);

char *reader_get_buffer(reader_t *reader);

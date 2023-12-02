/*
** EPITECH PROJECT, 2022
** reader
** File description:
** Header of reader
*/

#pragma once

#define BUFFER_CAPACITY (1024 * 8)

typedef struct reader {
    char const *path;
    int file;
    char buffer[BUFFER_CAPACITY];
    long length;
    long index;
    int error;
    char end;
} reader_t;

void reader_create(reader_t *reader, char const *path);
void reader_create_stdin(reader_t *reader);
void reader_destroy(reader_t *reader);

void read_some(reader_t *reader);
void reader_print(reader_t *reader);
char reader_getchar(reader_t *reader);
char *reader_getline(reader_t *reader);

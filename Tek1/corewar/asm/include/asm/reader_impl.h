/*
** EPITECH PROJECT, 2023
** reader_impl.h
** File description:
** reader_impl.h
*/

#pragma once

#include "reader.h"

struct reader {
    char *buffer;
    size_t length;
    size_t capacity;
    size_t cursor;
    size_t line;
};

void reader_error_open(const char *path);
void reader_error_read(const char *path);

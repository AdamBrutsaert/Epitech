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
};

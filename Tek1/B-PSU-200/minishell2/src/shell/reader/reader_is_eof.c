/*
** EPITECH PROJECT, 2023
** reader_is_eof.c
** File description:
** reader_is_eof.c
*/

#include "shell/reader.h"

bool reader_is_eof(reader_t *reader)
{
    return reader->eof;
}

/*
** EPITECH PROJECT, 2022
** parser.h
** File description:
** parser.h
*/

#pragma once

#include "aircraft.h"
#include "tower.h"

#include <my/vector.h>

int8_t is_u32(char const *string);
uint32_t str_to_u32(char const *string);

int32_t parse_file(char const *filepath, vector_t *aircrafts,
    vector_t *towers);
int32_t parse_line(char const *line, vector_t *aircrafts, vector_t *towers);

int32_t parse_aircraft(char **words, uint64_t count, vector_t *aircrafts);
int32_t parse_tower(char **words, uint64_t count, vector_t *towers);

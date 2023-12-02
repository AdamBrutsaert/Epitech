/*
** EPITECH PROJECT, 2023
** antman.h
** File description:
** antman.h
*/

#pragma once

#include "antman/status.h"
#include "antman/type.h"

#include <stdint.h>

typedef struct antman_s antman_t;

int8_t antman_from_arguments(int argc, char **argv);

antman_t *antman_create(void);
void antman_destroy(antman_t *antman);

void antman_set_file(antman_t *antman, char const *filepath);
void antman_set_type(antman_t *antman, type_t type);
int8_t antman_compress(antman_t *antman);

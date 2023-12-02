/*
** EPITECH PROJECT, 2023
** giantman.h
** File description:
** giantman.h
*/

#pragma once

#include "giantman/status.h"
#include "giantman/type.h"

#include <stdint.h>

typedef struct giantman_s giantman_t;

int8_t giantman_from_arguments(int argc, char **argv);

giantman_t *giantman_create(void);
void giantman_destroy(giantman_t *giantman);

void giantman_set_file(giantman_t *giantman, char const *filepath);
void giantman_set_type(giantman_t *giantman, type_t type);
int8_t giantman_uncompress(giantman_t *giantman);

/*
** EPITECH PROJECT, 2023
** antman_destroy.c
** File description:
** antman_destroy.c
*/

#include "antman.h"
#include "antman/antman.h"

#include <stdlib.h>

void antman_destroy(antman_t *antman)
{
    free(antman);
}

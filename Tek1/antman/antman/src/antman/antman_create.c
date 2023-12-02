/*
** EPITECH PROJECT, 2023
** antman_create.c
** File description:
** antman_create.c
*/

#include "antman.h"
#include "antman/antman.h"

#include <stdlib.h>

antman_t *antman_create(void)
{
    antman_t *antman = malloc(sizeof(antman_t));

    if (antman == NULL)
        return NULL;
    antman->type = NONE;
    antman->filepath = NULL;
    return antman;
}

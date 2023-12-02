/*
** EPITECH PROJECT, 2023
** navy_create.c
** File description:
** navy_create.c
*/

#include "navy.h"

#include <stdlib.h>

navy_t *navy_create(void)
{
    navy_t *navy = malloc(sizeof(navy_t));

    if (navy == NULL)
        return NULL;
    for (uint8_t i = 0; i < 64; i++) {
        navy->self[i / 8][i % 8] = NAVY_EMPTY;
        navy->opponent[i / 8][i % 8] = NAVY_EMPTY;
    }
    return navy;
}

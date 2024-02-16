/*
** EPITECH PROJECT, 2023
** navy_destroy.c
** File description:
** navy_destroy.c
*/

#include "navy.h"

#include <stdlib.h>

void navy_destroy(navy_t *navy)
{
    free(navy);
}

/*
** EPITECH PROJECT, 2023
** context_pop.c
** File description:
** context_pop.c
*/

#include "private/engine/context.h"

void context_pop(context_t *ctx)
{
    ctx->layers_to_pop++;
}

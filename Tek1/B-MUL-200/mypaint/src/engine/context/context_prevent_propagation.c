/*
** EPITECH PROJECT, 2023
** context_prevent_propagation.c
** File description:
** context_prevent_propagation.c
*/

#include "private/engine/context.h"

void context_prevent_propagation(context_t *ctx)
{
    ctx->prevent_propagation = true;
}

/*
** EPITECH PROJECT, 2022
** architect_context_destroy.c
** File description:
** architect_context_destroy.c
*/

#include "architect.h"
#include <stdlib.h>

void architect_context_destroy(architect_context_t *ctx)
{
    transformation_vector_destroy(ctx->transformations);
    matrix_destroy(ctx->point);
    matrix_destroy(ctx->transform);
    free(ctx);
}

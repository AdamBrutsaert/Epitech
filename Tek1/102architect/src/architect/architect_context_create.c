/*
** EPITECH PROJECT, 2022
** architect_context_create.c
** File description:
** architect_context_create.c
*/

#include "architect.h"
#include <stdlib.h>

architect_context_t *architect_context_create(void)
{
    architect_context_t *ctx = malloc(sizeof(architect_context_t));

    ctx->transformations = transformation_vector_create();
    ctx->point = NULL;
    ctx->transform = matrix_create_identity(3);
    return ctx;
}

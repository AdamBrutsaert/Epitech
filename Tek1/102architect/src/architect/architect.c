/*
** EPITECH PROJECT, 2022
** architect.c
** File description:
** architect.c
*/

#include "architect.h"
#include <stddef.h>
#include <stdio.h>
#include <math.h>

static void print_result(architect_context_t *ctx)
{
    matrix_t *result = matrix_mul(ctx->transform, ctx->point);

    matrix_print(ctx->transform);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n",
        roundf(ctx->point->matrix[0][0] * 100.0f) / 100.0f,
        roundf(ctx->point->matrix[1][0] * 100.0f) / 100.0f,
        roundf(result->matrix[0][0] * 100.0f) / 100.0f,
        roundf(result->matrix[1][0] * 100.0f) / 100.0f);
    matrix_destroy(result);
}

int32_t architect(int argc, char **argv)
{
    int32_t error = 0;

    architect_context_t *ctx = architect_context_create();
    error = architect_parse_args(ctx, argc, argv);
    if (!error) {
        architect_apply_transforms(ctx);
        print_result(ctx);
    }
    architect_context_destroy(ctx);
    return error;
}

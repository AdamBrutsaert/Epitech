/*
** EPITECH PROJECT, 2022
** architect_apply_transforms.c
** File description:
** architect_apply_transforms.c
*/

#include "architect.h"
#include <stdio.h>

static void architect_apply_translation(architect_context_t *ctx,
    transformation_t *transform)
{
    matrix_t *matrix = matrix_create_2d_translation(transform->param1,
        transform->param2);
    matrix_t *result = matrix_mul(matrix, ctx->transform);
    printf("Translation along vector (%.f, %.f)\n", transform->param1,
        transform->param2);

    matrix_destroy(matrix);
    matrix_destroy(ctx->transform);
    ctx->transform = result;
}

static void architect_apply_scale(architect_context_t *ctx,
    transformation_t *transform)
{
    matrix_t *matrix = matrix_create_2d_scale(transform->param1,
        transform->param2);
    matrix_t *result = matrix_mul(matrix, ctx->transform);
    printf("Scaling by factors %.f and %.f\n", transform->param1,
        transform->param2);

    matrix_destroy(matrix);
    matrix_destroy(ctx->transform);
    ctx->transform = result;
}

static void architect_apply_rotation(architect_context_t *ctx,
    transformation_t *transform)
{
    matrix_t *matrix = matrix_create_2d_rotation(transform->param1);
    matrix_t *result = matrix_mul(matrix, ctx->transform);
    printf("Rotation by a %.f degree angle\n", transform->param1);

    matrix_destroy(matrix);
    matrix_destroy(ctx->transform);
    ctx->transform = result;
}

static void architect_apply_reflection(architect_context_t *ctx,
    transformation_t *transform)
{
    matrix_t *matrix = matrix_create_2d_reflection(transform->param1);
    matrix_t *result = matrix_mul(matrix, ctx->transform);
    printf("Reflection over an axis with an inclination angle of %.f "
        "degrees\n", transform->param1);

    matrix_destroy(matrix);
    matrix_destroy(ctx->transform);
    ctx->transform = result;
}

void architect_apply_transforms(architect_context_t *ctx)
{
    for (uint32_t i = 0; i < ctx->transformations->length; i++) {
        if (ctx->transformations->transformations[i].type == TRANSLATION)
            architect_apply_translation(ctx,
                &ctx->transformations->transformations[i]);
        if (ctx->transformations->transformations[i].type == SCALE)
            architect_apply_scale(ctx,
                &ctx->transformations->transformations[i]);
        if (ctx->transformations->transformations[i].type == ROTATION)
            architect_apply_rotation(ctx,
                &ctx->transformations->transformations[i]);
        if (ctx->transformations->transformations[i].type == REFLECTION)
            architect_apply_reflection(ctx,
                &ctx->transformations->transformations[i]);
    }
}

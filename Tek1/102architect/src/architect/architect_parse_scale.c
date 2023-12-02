/*
** EPITECH PROJECT, 2022
** architect_parse_scale.c
** File description:
** architect_parse_scale.c
*/

#include "architect.h"

int8_t architect_parse_scale(architect_context_t *ctx, int *argc,
    char ***argv)
{
    float param1, param2;

    if (architect_parse_two_params(argc, argv, &param1, &param2))
        return 84;
    transformation_vector_push(ctx->transformations, SCALE, param1,
        param2);
    return 0;
}

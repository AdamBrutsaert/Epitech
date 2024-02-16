/*
** EPITECH PROJECT, 2022
** architect_parse_rotation.c
** File description:
** architect_parse_rotation.c
*/

#include "architect.h"

int8_t architect_parse_rotation(architect_context_t *ctx, int *argc,
    char ***argv)
{
    float param1;

    if (architect_parse_one_param(argc, argv, &param1))
        return 84;
    transformation_vector_push(ctx->transformations, ROTATION, param1, 0);
    return 0;
}

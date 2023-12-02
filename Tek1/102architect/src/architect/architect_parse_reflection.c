/*
** EPITECH PROJECT, 2022
** architect_parse_reflection.c
** File description:
** architect_parse_reflection.c
*/

#include "architect.h"

int8_t architect_parse_reflection(architect_context_t *ctx, int *argc,
    char ***argv)
{
    float param1;

    if (architect_parse_one_param(argc, argv, &param1))
        return 84;
    transformation_vector_push(ctx->transformations, REFLECTION, param1, 0);
    return 0;
}

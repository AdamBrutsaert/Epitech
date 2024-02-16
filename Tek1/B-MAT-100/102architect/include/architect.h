/*
** EPITECH PROJECT, 2022
** architect.h
** File description:
** architect.h
*/

#pragma once

#include "matrix.h"
#include "transformation.h"

typedef struct {
    transformation_vector_t *transformations;
    matrix_t *point;
    matrix_t *transform;
} architect_context_t;

int32_t architect(int argc, char **argv);

architect_context_t *architect_context_create(void);
void architect_context_destroy(architect_context_t *ctx);

int8_t architect_parse_args(architect_context_t *ctx, int argc, char **argv);
int8_t architect_parse_point(architect_context_t *ctx, int *argc, char ***argv);
int8_t architect_parse_transformation(architect_context_t *ctx, int *argc,
    char ***argv);
int8_t architect_parse_translation(architect_context_t *ctx, int *argc,
    char ***argv);
int8_t architect_parse_scale(architect_context_t *ctx, int *argc,
    char ***argv);
int8_t architect_parse_rotation(architect_context_t *ctx, int *argc,
    char ***argv);
int8_t architect_parse_reflection(architect_context_t *ctx, int *argc,
    char ***argv);
int8_t architect_parse_one_param(int *argc, char ***argv, float *param1);
int8_t architect_parse_two_params(int *argc, char ***argv, float *param1,
    float *param2);
void architect_apply_transforms(architect_context_t *ctx);

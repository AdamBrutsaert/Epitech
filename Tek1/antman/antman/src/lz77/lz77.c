/*
** EPITECH PROJECT, 2023
** lz77.c
** File description:
** lz77.c
*/

#include "lz77.h"
#include "lz77/lz77.h"
#include "file.h"

#include <stdlib.h>
#include <unistd.h>

static void find(lz77_t *ctx, uint64_t i, uint8_t *distance, uint8_t *length)
{
    uint64_t distance_tmp = 0;

    *length = 0;
    while (i + *length + 1 < ctx->length && distance_tmp != ctx->view->length
        && *length < 255) {
        *distance = distance_tmp;
        distance_tmp = view_find(ctx->view, &ctx->buffer[i], *length + 1);
        *length += distance_tmp != ctx->view->length;
    }
    if (distance_tmp != ctx->view->length)
        *distance = distance_tmp;
}

static void append(lz77_t *ctx, uint64_t *i, uint8_t length)
{
    view_append(ctx->view, ctx->buffer[*i]);
    for (; length; length--) {
        *i += 1;
        view_append(ctx->view, ctx->buffer[*i]);
    }
}

static void compress_buffer(lz77_t *ctx)
{
    uint8_t distance;
    uint8_t length;

    for (uint64_t i = 0; i < ctx->length; i++) {
        find(ctx, i, &distance, &length);
        append(ctx, &i, length);
        write(STDOUT_FILENO, &distance, 1);
        write(STDOUT_FILENO, &length, 1);
        write(STDOUT_FILENO, &ctx->buffer[i], 1);
    }
}

int8_t lz77(file_t *file, uint64_t capacity)
{
    lz77_t ctx;

    ctx.view = view_create(capacity);
    ctx.length = file_length(file);
    ctx.buffer = malloc(ctx.length * sizeof(char));
    if (!ctx.view || !ctx.buffer) {
        view_destroy(ctx.view);
        free(ctx.buffer);
        return 84;
    }
    file_read(file, ctx.buffer, ctx.length);
    compress_buffer(&ctx);
    view_destroy(ctx.view);
    free(ctx.buffer);
    return 0;
}

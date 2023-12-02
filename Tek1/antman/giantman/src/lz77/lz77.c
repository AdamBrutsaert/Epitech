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
#include <stdio.h>
#include <unistd.h>

static void output_pattern(view_t *view, uint8_t distance, uint8_t length)
{
    char pattern;

    if (length != 0) {
        for (uint8_t i = 0; i < length; i++) {
            pattern = view_get(view, view->length - 1 - distance + i);
            write(STDOUT_FILENO, &pattern, 1);
        }
        for (uint8_t i = 0; i < length; i++)
            view_append(view, view_get(view, view->length - 1 - distance));
    }
}

static void output(view_t *view, char c)
{
    write(STDOUT_FILENO, &c, 1);
    view_append(view, c);
}

static void uncompress_buffer(lz77_t *ctx)
{
    for (uint64_t i = 0; i + 2 < ctx->length; i += 3) {
        output_pattern(ctx->view, ctx->buffer[i], ctx->buffer[i + 1]);
        output(ctx->view, ctx->buffer[i + 2]);
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
    uncompress_buffer(&ctx);
    view_destroy(ctx.view);
    free(ctx.buffer);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** eraser_create.c
** File description:
** eraser_create.c
*/

#include "private/paint/components/tools/eraser.h"
#include "my/memory.h"

static bool create(eraser_t *eraser)
{
    eraser->shape = sfCircleShape_create();
    eraser->rect = sfRectangleShape_create();

    return eraser->shape && eraser->rect;
}

static void set(eraser_t *eraser, canvas_t *canvas)
{
    eraser->canvas = canvas;
    sfCircleShape_setRadius(eraser->shape, 5);
    sfCircleShape_setFillColor(eraser->shape, sfTransparent);
    sfRectangleShape_setSize(eraser->rect, (sfVector2f){10, 10});
    sfRectangleShape_setFillColor(eraser->rect, sfTransparent);
}

eraser_t *eraser_create(__attribute__((unused)) context_t *ctx,
    canvas_t *canvas)
{
    eraser_t *eraser = my_calloc(sizeof(eraser_t));

    if (!eraser)
        return NULL;
    if (!create(eraser)){
        eraser_destroy(eraser);
        return NULL;
    }
    set(eraser, canvas);
    return eraser;
}

/*
** EPITECH PROJECT, 2023
** pencil_create.c
** File description:
** pencil_create.c
*/

#include "private/paint/components/tools/pencil.h"
#include "my/memory.h"

static bool create(pencil_t *pencil)
{
    pencil->shape = sfCircleShape_create();
    pencil->rect = sfRectangleShape_create();

    return pencil->shape && pencil->rect;
}

static void set(pencil_t *pencil, canvas_t *canvas)
{
    pencil->canvas = canvas;
    sfCircleShape_setRadius(pencil->shape, 5);
    sfCircleShape_setFillColor(pencil->shape, sfBlack);
    sfRectangleShape_setFillColor(pencil->rect, sfBlack);
    sfRectangleShape_setSize(pencil->rect, (sfVector2f){10, 10});
}

pencil_t *pencil_create(__attribute__((unused)) context_t *ctx,
    canvas_t *canvas)
{
    pencil_t *pencil = my_calloc(sizeof(pencil_t));

    if (!pencil)
        return NULL;
    if (!create(pencil)){
        pencil_destroy(pencil);
        return NULL;
    }
    set(pencil, canvas);
    return pencil;
}

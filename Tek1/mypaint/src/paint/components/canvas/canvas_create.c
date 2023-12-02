/*
** EPITECH PROJECT, 2023
** canvas_create.c
** File description:
** canvas_create.c
*/

#include "private/paint/components/canvas.h"
#include "my/memory.h"

static bool create(canvas_t *canvas)
{
    canvas->texture = sfRenderTexture_create(500, 500, sfTrue);
    canvas->sprite = sfSprite_create();
    canvas->view = sfView_create();
    canvas->bg_texture = sfTexture_createFromFile("res/transparent.png", NULL);
    canvas->bg = sfVertexArray_create();
    return canvas->texture && canvas->sprite && canvas->view
        && canvas->bg_texture && canvas->bg;
}

static void set(canvas_t *canvas, context_t *ctx)
{
    sfVector2u size = sfRenderTexture_getSize(canvas->texture);

    canvas->zoom = 1;
    canvas->center = (sfVector2f){size.x / 2.0f, size.y / 2.0f};
    canvas_update_view(canvas, ctx);
    sfSprite_setTexture(canvas->sprite, sfRenderTexture_getTexture(
        canvas->texture), sfTrue);
    sfRenderTexture_clear(canvas->texture, sfWhite);
}

static void set_bg(canvas_t *canvas)
{
    sfVertex *vertex;
    sfVector2u size = sfRenderTexture_getSize(canvas->texture);

    sfTexture_setRepeated(canvas->bg_texture, sfTrue);
    sfVertexArray_setPrimitiveType(canvas->bg, sfQuads);
    sfVertexArray_resize(canvas->bg, 4);
    vertex = sfVertexArray_getVertex(canvas->bg, 0);
    vertex->position = (sfVector2f){0, 0};
    vertex->texCoords = (sfVector2f){0, 0};
    vertex = sfVertexArray_getVertex(canvas->bg, 1);
    vertex->position = (sfVector2f){size.x, 0};
    vertex->texCoords = (sfVector2f){size.x, 0};
    vertex = sfVertexArray_getVertex(canvas->bg, 2);
    vertex->position = (sfVector2f){size.x, size.y};
    vertex->texCoords = (sfVector2f){size.x, size.y};
    vertex = sfVertexArray_getVertex(canvas->bg, 3);
    vertex->position = (sfVector2f){0, size.y};
    vertex->texCoords = (sfVector2f){0, size.y};
}

canvas_t *canvas_create(context_t *ctx)
{
    canvas_t *canvas = my_calloc(sizeof(canvas_t));

    if (!canvas)
        return NULL;
    if (!create(canvas)) {
        canvas_destroy(canvas);
        return NULL;
    }
    set(canvas, ctx);
    set_bg(canvas);
    return canvas;
}

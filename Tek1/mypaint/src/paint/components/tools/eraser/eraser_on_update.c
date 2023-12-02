/*
** EPITECH PROJECT, 2023
** eraser_on_update.c
** File description:
** eraser_on_update.c
*/

#include "private/paint/components/tools/eraser.h"

#include <math.h>

static void draw_circle(eraser_t *eraser, float x, float y)
{
    sfRenderStates states = { sfBlendNone, sfTransform_Identity, NULL, NULL };
    float thickness = sfCircleShape_getRadius(eraser->shape);

    if (eraser->is_rect) {
        sfRectangleShape_setPosition(eraser->rect, (sfVector2f){x - thickness,
            y - thickness});
        sfRenderTexture_drawRectangleShape(canvas_get_texture(eraser->canvas),
            eraser->rect, &states);
    } else {
        sfCircleShape_setPosition(eraser->shape, (sfVector2f){x - thickness,
            y - thickness});
        sfRenderTexture_drawCircleShape(canvas_get_texture(eraser->canvas),
            eraser->shape, &states);
    }
}

static void draw_between(eraser_t *eraser, sfVector2f *last,
    sfVector2f *current)
{
    sfVector2f direction;
    float length;

    direction.x = last->x - current->x;
    direction.y = last->y - current->y;
    length = sqrtf(direction.x * direction.x + direction.y * direction.y);
    if (length > 0) {
        direction.x = direction.x / length;
        direction.y = direction.y / length;
    }
    draw_circle(eraser, current->x, current->y);
    for (float i = 0; i < length; i++)
        draw_circle(eraser, current->x + direction.x * i,
            current->y + direction.y * i);
}

bool eraser_on_update(context_t *ctx, eraser_t *eraser,
    __attribute__((unused)) float dt)
{
    sfVector2f current = sfRenderWindow_mapPixelToCoords(
        context_get_window(ctx),
        sfMouse_getPositionRenderWindow(context_get_window(ctx)),
        canvas_get_view(eraser->canvas)
    );

    if (eraser->is_pressing) {
        draw_between(eraser, &eraser->last_position, &current);
        eraser->last_position = current;
    }
    return true;
}

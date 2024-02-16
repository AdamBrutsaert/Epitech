/*
** EPITECH PROJECT, 2023
** pencil_on_update.c
** File description:
** pencil_on_update.c
*/

#include "private/paint/components/tools/pencil.h"

#include <math.h>

static void draw_circle(pencil_t *pencil, float x, float y)
{
    float thickness = sfCircleShape_getRadius(pencil->shape);

    if (pencil->is_rect) {
        sfRectangleShape_setPosition(pencil->rect, (sfVector2f){x - thickness,
            y - thickness});
        sfRenderTexture_drawRectangleShape(canvas_get_texture(pencil->canvas),
            pencil->rect, NULL);
    } else {
        sfCircleShape_setPosition(pencil->shape, (sfVector2f){x - thickness,
            y - thickness});
        sfRenderTexture_drawCircleShape(canvas_get_texture(pencil->canvas),
            pencil->shape, NULL);
    }
}

static void draw_between(pencil_t *pencil, sfVector2f *last,
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
    draw_circle(pencil, current->x, current->y);
    for (float i = 0; i < length; i++)
        draw_circle(pencil, current->x + direction.x * i,
            current->y + direction.y * i);
}

bool pencil_on_update(context_t *ctx, pencil_t *pencil,
    __attribute__((unused)) float dt)
{
    sfVector2f current = sfRenderWindow_mapPixelToCoords(
        context_get_window(ctx),
        sfMouse_getPositionRenderWindow(context_get_window(ctx)),
        canvas_get_view(pencil->canvas)
    );

    if (pencil->is_pressing) {
        draw_between(pencil, &pencil->last_position, &current);
        pencil->last_position = current;
    }
    return true;
}

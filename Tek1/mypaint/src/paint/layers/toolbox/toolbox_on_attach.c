/*
** EPITECH PROJECT, 2023
** toolbox_on_attach.c
** File description:
** toolbox_on_attach.c
*/

#include "private/paint/layers/toolbox.h"

static bool create(toolbox_t *toolbox, context_t *ctx)
{
    toolbox->font = sfFont_createFromFile("res/JetBrainsMono-Regular.ttf");
    toolbox->grow = button_create(ctx, toolbox->font);
    toolbox->shrink = button_create(ctx, toolbox->font);
    toolbox->rect = button_create(ctx, toolbox->font);
    toolbox->circle = button_create(ctx, toolbox->font);
    toolbox->circle_shape = sfCircleShape_create();
    toolbox->rect_shape = sfRectangleShape_create();
    return toolbox->font && toolbox->grow && toolbox->shrink
        && toolbox->rect && toolbox->circle && toolbox->circle_shape
        && toolbox->rect_shape;
}

static void set(toolbox_t *toolbox, context_t *ctx)
{
    sfVector2u size = sfRenderWindow_getSize(context_get_window(ctx));

    button_set_text(toolbox->grow, "+");
    button_set_size(toolbox->grow, (sfVector2f){50, 50});
    button_set_text_position(toolbox->grow, (sfVector2f) {20, 15});
    button_set_position(toolbox->grow, (sfVector2f){size.x / 2.0f - 100, 0});
    button_set_text(toolbox->shrink, "-");
    button_set_size(toolbox->shrink, (sfVector2f){50, 50});
    button_set_text_position(toolbox->shrink, (sfVector2f) {20, 15});
    button_set_position(toolbox->shrink, (sfVector2f){size.x / 2.0f - 50, 0});
    button_set_size(toolbox->rect, (sfVector2f){50, 50});
    button_set_text_position(toolbox->rect, (sfVector2f) {20, 15});
    button_set_position(toolbox->rect, (sfVector2f){size.x / 2.0f, 0});
    button_set_size(toolbox->circle, (sfVector2f){50, 50});
    button_set_text_position(toolbox->circle, (sfVector2f) {20, 15});
    button_set_position(toolbox->circle, (sfVector2f){size.x / 2.0f + 50, 0});
    button_set_color(toolbox->circle, sfColor_fromRGB(24, 50, 75));
    button_set_outline_color(toolbox->circle, sfColor_fromRGB(8, 85, 162));
}

void set2(toolbox_t *toolbox, context_t *ctx)
{
    sfVector2u size = sfRenderWindow_getSize(context_get_window(ctx));

    sfCircleShape_setRadius(toolbox->circle_shape, 10);
    sfCircleShape_setFillColor(toolbox->circle_shape, sfTransparent);
    sfCircleShape_setOutlineThickness(toolbox->circle_shape, 2);
    sfCircleShape_setOutlineColor(toolbox->circle_shape, sfWhite);
    sfCircleShape_setPosition(toolbox->circle_shape, (sfVector2f)
        {size.x / 2.0f + 50 + 15, 15});
    sfRectangleShape_setFillColor(toolbox->rect_shape, sfTransparent);
    sfRectangleShape_setOutlineThickness(toolbox->rect_shape, 2);
    sfRectangleShape_setOutlineColor(toolbox->rect_shape, sfWhite);
    sfRectangleShape_setSize(toolbox->rect_shape, (sfVector2f){20, 20});
    sfRectangleShape_setPosition(toolbox->rect_shape, (sfVector2f)
        {size.x / 2.0f + 15, 15});
}

bool toolbox_on_attach(context_t *ctx, void *data)
{
    toolbox_t *toolbox = data;

    if (!create(toolbox, ctx))
        return false;
    set(toolbox, ctx);
    set2(toolbox, ctx);
    return true;
}

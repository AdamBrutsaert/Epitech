/*
** EPITECH PROJECT, 2023
** layer_settings_on_attach.c
** File description:
** layer_settings_on_attach.c
*/

#include "layers/settings_impl.h"

static void set_view(layer_t *layer)
{
    sfVector2u size = sfRenderWindow_getSize(layer_get_window(layer));
    sfView *view = layer_get_view(layer);

    sfView_setCenter(view, (sfVector2f){size.x / 2.0f, size.y / 2.0f});
    sfView_setSize(view, (sfVector2f){size.x, size.y});
}

static bool load_font(layer_t *layer)
{
    layer_settings_t *settings = layer_get_data(layer);
    sfFont *font = sfFont_createFromFile("res/font/dogica.ttf");

    if (!font)
        return false;
    settings->font = font;
    return true;
}

bool layer_settings_on_attach(layer_t *layer)
{
    set_view(layer);
    return load_font(layer) && layer_settings_add_buttons(layer);
}

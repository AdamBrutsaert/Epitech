/*
** EPITECH PROJECT, 2023
** engine_on_render.c
** File description:
** engine_on_render.c
*/

#include "engine_impl.h"

void engine_on_render(engine_t *engine)
{
    sfRenderWindow_clear(engine->window, sfColor_fromRGB(56, 35, 43));
    for (size_t i = 0; i < engine->layers_length; i++)
        layer_on_render(engine->layers[i]);
    for (size_t i = 0; engine->show_hitboxes && i < engine->layers_length; i++)
        layer_render_hitboxes(engine->layers[i]);
    sfRenderWindow_display(engine->window);
}

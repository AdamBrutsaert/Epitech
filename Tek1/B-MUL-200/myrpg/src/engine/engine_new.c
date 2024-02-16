/*
** EPITECH PROJECT, 2023
** engine_new.c
** File description:
** engine_new.c
*/

#include "engine_impl.h"
#include "my/memory.h"

engine_t *engine_new(uint32_t width, uint32_t height, const char *title)
{
    engine_t *engine = my_calloc(sizeof(engine_t));

    if (engine == NULL)
        return NULL;
    engine->window = sfRenderWindow_create(
        (sfVideoMode){ width, height, 32},
        title,
        sfDefaultStyle,
        NULL
    );
    engine->fullscreen = false;
    engine->states.blendMode = sfBlendAlpha;
    engine->states.transform = sfTransform_Identity;
    engine->states.texture = NULL;
    engine->states.shader = NULL;
    return engine;
}

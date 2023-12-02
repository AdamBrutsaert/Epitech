/*
** EPITECH PROJECT, 2023
** engine_set_fullscreen.c
** File description:
** engine_set_fullscreen.c
*/

#include "engine_impl.h"

bool engine_set_fullscreen(engine_t *engine, bool fullscreen)
{
    sfRenderWindow_destroy(engine->window);

    if (fullscreen) {
        engine->window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
            "MyRPG", sfFullscreen, NULL);
    } else {
        engine->window = sfRenderWindow_create((sfVideoMode) {1280, 720, 32},
            "MyRPG", sfDefaultStyle, NULL);
    }
    engine->fullscreen = fullscreen;
    return engine->window != NULL;
}

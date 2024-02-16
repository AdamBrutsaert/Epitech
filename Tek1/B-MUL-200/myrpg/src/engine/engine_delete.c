/*
** EPITECH PROJECT, 2023
** engine_delete.c
** File description:
** engine_delete.c
*/

#include "engine_impl.h"

#include <stdlib.h>

void engine_delete(engine_t *engine)
{
    if (engine == NULL)
        return;
    for (size_t i = engine->layers_length; i > 0; i--) {
        layer_on_detach(engine->layers[i - 1]);
        layer_delete(engine->layers[i - 1]);
    }
    free(engine->layers);
    free(engine->events);
    sfRenderWindow_destroy(engine->window);
    free(engine);
}

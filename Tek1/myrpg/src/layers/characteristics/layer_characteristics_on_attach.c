/*
** EPITECH PROJECT, 2023
** layer_characteristics_on_attach.c
** File description:
** layer_characteristics_on_attach.c
*/

#include "layers/characteristics_impl.h"
#include "my/memory.h"

bool layer_characteristics_on_attach(layer_t *layer)
{
    layer_characteristics_t *characteristics = layer_get_data(layer);
    sfVector2u size = sfRenderWindow_getSize(layer_get_window(layer));
    sfView *view = layer_get_view(layer);

    sfView_setSize(view, (sfVector2f){size.x, size.y});
    sfView_setCenter(view, (sfVector2f){size.x / 2.0f, size.y / 2.0f});
    characteristics->texture = sfTexture_createFromFile(
        "res/hearts.png", NULL);
    return characteristics->texture;
}

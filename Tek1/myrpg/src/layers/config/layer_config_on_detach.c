/*
** EPITECH PROJECT, 2023
** layer_config_on_detach.c
** File description:
** layer_config_on_detach.c
*/

#include "layers/config_impl.h"

void layer_config_on_detach(layer_t *layer)
{
    layer_config_t *config = layer_get_data(layer);

    sfFont_destroy(config->font);
}

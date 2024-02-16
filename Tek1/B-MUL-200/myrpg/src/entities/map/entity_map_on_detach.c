/*
** EPITECH PROJECT, 2023
** entity_map_on_detach.c
** File description:
** entity_map_on_detach.c
*/

#include "entities/map_impl.h"

void entity_map_on_detach(entity_t *entity)
{
    entity_map_t *data = entity_get_data(entity);

    sfTexture_destroy(data->texture);
    sfSprite_destroy(data->sprite);
}

/*
** EPITECH PROJECT, 2023
** entity_map_on_attach.c
** File description:
** entity_map_on_attach.c
*/

#include "entities/map_impl.h"

bool entity_map_on_attach(entity_t *entity)
{
    entity_map_t *data = entity_get_data(entity);

    data->texture = sfTexture_createFromFile(data->map, NULL);
    data->sprite = sfSprite_create();
    if (data->texture == NULL || data->sprite == NULL)
        return false;
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    return entity_map_parse_collisions(entity);
}

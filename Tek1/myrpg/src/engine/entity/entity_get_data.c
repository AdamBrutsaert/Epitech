/*
** EPITECH PROJECT, 2023
** entity_get_data.c
** File description:
** entity_get_data.c
*/

#include "engine/entity_impl.h"

void *entity_get_data(entity_t *entity)
{
    return entity->data;
}

/*
** EPITECH PROJECT, 2023
** entity_get_type.c
** File description:
** entity_get_type.c
*/

#include "engine/entity_impl.h"

const char *entity_get_type(entity_t *entity)
{
    return entity->type;
}

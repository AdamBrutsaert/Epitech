/*
** EPITECH PROJECT, 2023
** entity_set_type.c
** File description:
** entity_set_type.c
*/

#include "engine/entity_impl.h"

void entity_set_type(entity_t *entity, const char *type)
{
    entity->type = type;
}

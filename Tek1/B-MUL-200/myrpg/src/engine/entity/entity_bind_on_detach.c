/*
** EPITECH PROJECT, 2023
** entity_bind_on_detach.c
** File description:
** entity_bind_on_detach.c
*/

#include "engine/entity_impl.h"

void entity_bind_on_detach(entity_t *entity, entity_on_detach_t on_detach)
{
    entity->on_detach = on_detach;
}

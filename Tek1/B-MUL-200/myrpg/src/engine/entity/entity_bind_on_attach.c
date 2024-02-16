/*
** EPITECH PROJECT, 2023
** entity_bind_on_attach.c
** File description:
** entity_bind_on_attach.c
*/

#include "engine/entity_impl.h"

void entity_bind_on_attach(entity_t *entity, entity_on_attach_t on_attach)
{
    entity->on_attach = on_attach;
}

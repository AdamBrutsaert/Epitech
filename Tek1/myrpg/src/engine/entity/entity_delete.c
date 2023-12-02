/*
** EPITECH PROJECT, 2023
** entity_delete.c
** File description:
** entity_delete.c
*/

#include "engine/entity_impl.h"

#include <stdlib.h>

void entity_delete(entity_t *entity)
{
    if (entity == NULL)
        return;
    free(entity->hitboxes);
    free(entity->data);
    free(entity);
}

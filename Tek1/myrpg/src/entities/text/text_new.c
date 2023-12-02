/*
** EPITECH PROJECT, 2023
** button_new.c
** File description:
** button_new.c
*/

#include "entities/text_impl.h"

entity_t *text_new(sfFont *font)
{
    entity_t *entity = entity_new(sizeof(text_t));
    text_t *text;

    if (entity == NULL)
        return NULL;
    text = entity_get_data(entity);
    text->font = font;
    entity_bind_on_attach(entity, text_on_attach);
    entity_bind_on_detach(entity, text_on_detach);
    entity_bind_on_event(entity, text_on_event);
    entity_bind_on_render(entity, text_on_render);
    return entity;
}

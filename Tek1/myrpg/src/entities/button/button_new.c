/*
** EPITECH PROJECT, 2023
** button_new.c
** File description:
** button_new.c
*/

#include "entities/button_impl.h"
#include "my/memory.h"

static bool init_vect(button_t *button)
{
    button->middle_sprites = my_calloc(sizeof(sfSprite *) * button->parts);
    if (button->middle_sprites == NULL)
        return false;
    button->middle_capacity = button->parts;
    button->middle_length = 0;
    return true;
}

entity_t *button_new(callback_t callback,
    button_skin_t skin,
    uint16_t parts,
    sfFont *font)
{
    entity_t *entity = entity_new(sizeof(button_t));

    if (entity == NULL)
        return NULL;
    button_t *button = entity_get_data(entity);
    button->parts = parts;
    if (!init_vect(button)) {
        entity_delete(entity);
        return NULL;
    }
    button->skin = skin;
    button->font = font;
    button->callback = callback;
    entity_bind_on_attach(entity, button_on_attach);
    entity_bind_on_detach(entity, button_on_detach);
    entity_bind_on_event(entity, button_on_event);
    entity_bind_on_update(entity, button_on_update);
    entity_bind_on_render(entity, button_on_render);
    return entity;
}

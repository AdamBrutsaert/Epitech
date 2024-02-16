/*
** EPITECH PROJECT, 2023
** button_on_update.c
** File description:
** button_on_update.c
*/

#include "entities/button_impl.h"

bool button_on_update(entity_t *entity, float delta)
{
    button_t *button = entity_get_data(entity);

    if (button->call_callback) {
        button->cooldown += delta;
        if (button->cooldown >= COOLDOWN) {
            button->cooldown = 0;
            button->call_callback = false;
            button->callback(entity, NULL);
        }
    }
    return true;
}

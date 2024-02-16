/*
** EPITECH PROJECT, 2023
** button_on_event.c
** File description:
** button_on_event.c
*/

#include "entities/button_impl.h"

static void inside_one(entity_t *entity, button_t *button, float x, float y)
{
    if (button->status == IDLE) {
        button->status = HOVERING;
        sfSprite_setTextureRect(button->left_sprite,
            (sfIntRect) {0, 42, 12, 42});
        sfSprite_setTextureRect(button->right_sprite,
            (sfIntRect) {0, 42, 12, 42});
        for (size_t i = 0; i < button->middle_length; i++)
            sfSprite_setTextureRect(button->middle_sprites[i],
                (sfIntRect) {0, 42, 49, 42});
    }
}

static void on_mouse_move(entity_t *entity, button_t *button, float x, float y)
{
    if (button_is_inside(entity, (sfVector2f) {x, y})) {
        inside_one(entity, button, x, y);
    } else {
        if (button->status == HOVERING) {
            button->status = IDLE;
            sfSprite_setTextureRect(button->left_sprite,
                (sfIntRect) {0, 0, 12, 42});
            sfSprite_setTextureRect(button->right_sprite,
                (sfIntRect) {0, 0, 12, 42});
            for (size_t i = 0; i < button->middle_length; i++)
                sfSprite_setTextureRect(button->middle_sprites[i],
                    (sfIntRect) {0, 0, 49, 42});
        }
    }
}

static void on_mouse_press(entity_t *entity, float x, float y)
{
    button_t *button = entity_get_data(entity);

    if (button_is_inside(entity, (sfVector2f) {x, y})) {
        button->status = PRESSING;
        sfSprite_setTextureRect(button->left_sprite,
            (sfIntRect) {0, 42 * 2, 12, 42});
        sfSprite_setTextureRect(button->right_sprite,
            (sfIntRect) {0, 42 * 2, 12, 42});
        for (size_t i = 0; i < button->middle_length; i++)
            sfSprite_setTextureRect(button->middle_sprites[i],
                (sfIntRect) {0, 42 * 2, 49, 42});
    }
}

static void on_mouse_release(entity_t *entity, button_t *button,
    float x, float y)
{
    if (!button_is_inside(entity, (sfVector2f) {x, y})
        && button->status != PRESSING)
        return;
    button->status = IDLE;
    sfSprite_setTextureRect(button->left_sprite, (sfIntRect) {0, 0, 12, 42});
    sfSprite_setTextureRect(button->right_sprite, (sfIntRect) {0, 0, 12, 42});
    for (size_t i = 0; i < button->middle_length; i++)
        sfSprite_setTextureRect(button->middle_sprites[i],
            (sfIntRect) {0, 0, 49, 42});
    if (button_is_inside(entity, (sfVector2f) {x, y})
        && button->callback != NULL) {
        sfSound_play(button->sound);
        button->call_callback = true;
    }
}

bool button_on_event(entity_t *entity, sfEvent *event)
{
    button_t *button = entity_get_data(entity);

    if (button->call_callback)
        return true;
    if (event->type == sfEvtMouseMoved)
        on_mouse_move(entity, button, event->mouseMove.x, event->mouseMove.y);
    if (event->type == sfEvtMouseButtonPressed)
        on_mouse_press(entity, event->mouseButton.x, event->mouseButton.y);
    if (event->type == sfEvtMouseButtonReleased)
        on_mouse_release(entity, button,
            event->mouseButton.x, event->mouseButton.y);
    return true;
}

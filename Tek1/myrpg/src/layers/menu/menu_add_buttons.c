/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu_add_buttons
*/

#include "rpg.h"
#include "layers/menu_impl.h"

static bool add_resume_button(layer_t *layer, menu_t *menu, sfVector2u size)
{
    entity_t *resume = button_new(button_menu_resume_clicked,
        BUTTON_SKIN_BROWN, 8, menu->font);

    if (!resume || !layer_add_entity(layer, resume))
        return false;
    button_set_position(resume, size.x / 2.0f - 203, size.y / 2.0f - 71);
    button_set_string(resume, "Resume");
    menu->resume = resume;
    return true;
}

static bool add_play_button(layer_t *layer, menu_t *menu, sfVector2u size)
{
    entity_t *play = button_new(button_menu_play_clicked,
        BUTTON_SKIN_BROWN, 8, menu->font);

    if (!play || !layer_add_entity(layer, play))
        return false;
    button_set_position(play, size.x / 2.0f - 203, size.y / 2.0f - 21);
    button_set_string(play, "Play");
    menu->play = play;
    return true;
}

static bool add_config_button(layer_t *layer, menu_t *menu, sfVector2u size)
{
    entity_t *config = button_new(button_menu_config_clicked,
        BUTTON_SKIN_BROWN, 8, menu->font);

    if (!config || !layer_add_entity(layer, config))
        return false;
    button_set_position(config, size.x / 2.0f - 203, size.y / 2.0f + 29);
    button_set_string(config, "Configuration");
    menu->config = config;
    return true;
}

static bool add_quit_button(layer_t *layer, menu_t *menu, sfVector2u size)
{
    entity_t *quit = button_new(button_menu_quit_clicked,
        BUTTON_SKIN_BROWN, 8, menu->font);

    if (!quit || !layer_add_entity(layer, quit))
        return false;
    button_set_position(quit, size.x / 2.0f - 203, size.y / 2.0f + 79.0f);
    button_set_string(quit, "Quit");
    menu->quit = quit;
    return true;
}

bool menu_add_buttons(layer_t *layer, menu_t *menu)
{
    sfVector2u size = sfRenderWindow_getSize(layer_get_window(layer));

    return add_resume_button(layer, menu, size)
        && add_play_button(layer, menu, size)
        && add_config_button(layer, menu, size)
        && add_quit_button(layer, menu, size);
}

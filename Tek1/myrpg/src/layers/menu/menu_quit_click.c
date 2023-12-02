/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu_play_click
*/

#include "rpg.h"
#include "entities/button.h"

void button_menu_quit_clicked(entity_t *entity, void *data)
{
    sfRenderWindow *window = entity_get_window(entity);

    sfRenderWindow_close(window);
}

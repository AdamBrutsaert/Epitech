/*
** EPITECH PROJECT, 2023
** entity_npc_on_render.c
** File description:
** entity_npc_on_render.c
*/

#include "entities/npc_impl.h"

void entity_npc_on_render(entity_t *entity)
{
    entity_npc_t *npc = entity_get_data(entity);
    sfRenderWindow *window = entity_get_window(entity);

    sfRenderWindow_drawSprite(window, npc->sprite, NULL);
    if (npc->show_text)
        sfRenderWindow_drawText(window, npc->text, NULL);
}

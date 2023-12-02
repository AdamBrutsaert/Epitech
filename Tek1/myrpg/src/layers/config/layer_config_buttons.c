/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** layer_config_buttons
*/

#include "rpg.h"
#include "layers/config_impl.h"

void button_config_1280_clicked(entity_t *entity, void *data)
{
    sfRenderWindow *window = entity_get_window(entity);

    sfRenderWindow_setSize(window, (sfVector2u){1280, 720});
}

void button_config_800_clicked(entity_t *entity, void *data)
{
    sfRenderWindow *window = entity_get_window(entity);

    sfRenderWindow_setSize(window, (sfVector2u){1920, 1080});
}

void button_config_fullscreen_clicked(entity_t *entity, void *data)
{
    engine_t *engine = entity_get_engine(entity);

    engine_set_fullscreen(engine, !engine_is_fullscreen(engine));
}

void button_config_previous_clicked(entity_t *entity, void *data)
{
    engine_t *engine = entity_get_engine(entity);

    engine_pop_layer(engine);
}

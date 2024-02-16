/*
** EPITECH PROJECT, 2022
** peashooter_on_event.c
** File description:
** peashooter_on_event.c
*/

#include "hunter.h"
#include "my.h"

static void push_pea(scene_t *scene, float x, float y)
{
    peashooter_data_t *data = scene->data;
    pea_args_t *args = my_malloc(sizeof(pea_args_t));

    args->texture = data->pea_texture;
    args->direction = (sfVector2f){x - 424, y - 512};
    args->impact = data->impact;
    if (data->pea_vector.length == data->pea_vector.capacity) {
        data->pea_vector.capacity *= 2;
        data->pea_vector.capacity += !data->pea_vector.capacity;
        data->pea_vector.peas = my_realloc(data->pea_vector.peas,
            sizeof(scene_t *) * data->pea_vector.capacity);
    }
    data->pea_vector.peas[data->pea_vector.length] = scene_add_child(scene,
        pea_create(scene->app, args));
    data->pea_vector.length++;
    sfSound_play(data->sound);
}

void peashooter_on_event(scene_t *scene, sfEvent *event)
{
    sfVector2i mouse_pos;
    sfVector2f position;

    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft) {
        mouse_pos.x = event->mouseButton.x;
        mouse_pos.y = event->mouseButton.y;
        position = sfRenderWindow_mapPixelToCoords(scene->app->window,
            mouse_pos, NULL);
        if (position.y < 370.0f)
            push_pea(scene, position.x - 8, position.y - 8);
    }
}

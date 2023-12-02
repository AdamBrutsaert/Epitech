/*
** EPITECH PROJECT, 2022
** radar_run.c
** File description:
** radar_run.c
*/

#include "radar.h"

static void handle_events(radar_t *radar)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(radar->window, &event)) {
        if (event.type == sfEvtClosed
            || (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
            sfRenderWindow_close(radar->window);
        radar_on_event(radar, &event);
    }
}

void radar_run(radar_t *radar)
{
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(radar->window)) {
        handle_events(radar);
        radar_on_update(radar, sfTime_asSeconds(sfClock_restart(clock)));
        sfRenderWindow_clear(radar->window, sfColor_fromRGB(26, 26, 26));
        radar_on_render(radar);
        sfRenderWindow_display(radar->window);
    }
    sfClock_destroy(clock);
}

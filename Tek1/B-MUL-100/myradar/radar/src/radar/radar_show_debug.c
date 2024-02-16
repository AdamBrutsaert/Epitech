/*
** EPITECH PROJECT, 2023
** radar_show_debug.c
** File description:
** radar_show_debug.c
*/

#include "radar.h"

#include <my/string.h>
#include <my/memory.h>

static uint32_t get_digits_count(uint32_t value)
{
    uint32_t count = value == 0;

    for (; value != 0; value /= 10)
        count++;
    return count;
}

static void utostr(char *string, uint32_t value)
{
    uint32_t count = get_digits_count(value);

    string += count;
    do {
        string--;
        *string = value % 10 + '0';
        value /= 10;
    } while (value != 0);
}

static sfText *create_text(radar_t *radar, char const *prefix, uint32_t value)
{
    char *string = my_calloc(my_strlen(prefix) + get_digits_count(value) + 1);
    sfText *text = sfText_create();

    my_strncpy(string, prefix, my_strlen(prefix));
    utostr(string + my_strlen(prefix), value);
    sfText_setFont(text, radar->font);
    sfText_setFillColor(text, sfYellow);
    sfText_setCharacterSize(text, 40);
    sfText_setString(text, string);
    my_free(string);
    return text;
}

void radar_show_debug(radar_t *radar)
{
    sfText *timer = create_text(radar, "", radar->timer);
    sfText *fps = create_text(radar, "FPS: ", radar->fps);

    sfText_setPosition(timer,
        (sfVector2f){1920.0f - sfText_getGlobalBounds(timer).width - 5, -5});
    sfText_setPosition(fps, (sfVector2f){5, -5});
    sfRenderWindow_drawText(radar->window, timer, NULL);
    sfRenderWindow_drawText(radar->window, fps, NULL);
    sfText_destroy(timer);
}

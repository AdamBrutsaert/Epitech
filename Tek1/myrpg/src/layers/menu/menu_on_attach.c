/*
** EPITECH PROJECT, 2023
** menu_on_attach.c
** File description:
** menu_on_attach.c
*/

#include "layers/menu_impl.h"
#include "entities/button.h"
#include "entities/text.h"

static bool load_font(menu_t *menu)
{
    menu->font = sfFont_createFromFile(ENTITY_MENU_FONT_PATH);

    if (menu->font == NULL)
        return false;
    return true;
}

static bool init_main_text(layer_t *layer, menu_t *menu)
{
    entity_t *text = text_new(menu->font);
    sfVector2u size = sfRenderWindow_getSize(layer_get_window(layer));

    if (!text || !layer_add_entity(layer, text))
        return false;
    text_set(text, "MY_RPG", sfWhite, 26);
    text_set_position(text, (sfVector2f) {TEXT_CENTER, 0.2 * size.y});
    menu->title = text;
    return true;
}

static void create_view(layer_t *layer, menu_t *menu)
{
    sfRenderWindow *window = engine_get_window(layer_get_engine(layer));
    sfVector2u size = sfRenderWindow_getSize(window);
    sfView *view = layer_get_view(layer);

    sfView_setSize(view, (sfVector2f) {size.x, size.y});
    sfView_setCenter(view, (sfVector2f) {size.x / 2.0f, size.y / 2.0f});
}

bool menu_on_attach(layer_t *layer)
{
    menu_t *menu = layer_get_data(layer);
    entity_t *text;

    menu->music = sfMusic_createFromFile("res/sounds/menu_music.ogg");
    if (menu->music == NULL)
        return false;
    sfMusic_setLoop(menu->music, true);
    sfMusic_play(menu->music);
    sfMusic_setVolume(menu->music, 25);
    if (!load_font(menu) || !init_main_text(layer, menu))
        return false;
    text = text_new(menu->font);
    if (!text)
        return false;
    if (!menu_add_buttons(layer, menu))
        return false;
    create_view(layer, menu);
    return true;
}

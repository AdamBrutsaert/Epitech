/*
** EPITECH PROJECT, 2023
** menu_on_attach.c
** File description:
** menu_on_attach.c
*/

#include "private/paint/layers/menu.h"

static bool create(context_t *ctx, menu_t *menu)
{
    menu->font = sfFont_createFromFile("res/JetBrainsMono-Regular.ttf");
    menu->file = button_create(ctx, menu->font);
    menu->edition = button_create(ctx, menu->font);
    menu->help = button_create(ctx, menu->font);
    menu->file_new = button_create(ctx, menu->font);
    menu->file_open = button_create(ctx, menu->font);
    menu->file_save = button_create(ctx, menu->font);
    menu->edition_pencil = button_create(ctx, menu->font);
    menu->edition_eraser = button_create(ctx, menu->font);
    menu->edition_hand = button_create(ctx, menu->font);

    return menu->font && menu->file && menu->edition && menu->help;
}

static void set(menu_t *menu)
{
    button_set_text(menu->file, "File");
    button_set_text_size(menu->file, 16);
    button_set_text_position(menu->file, (sfVector2f){ 10, 5 });
    button_set_size(menu->file, (sfVector2f){60, 30});
    button_set_text(menu->edition, "Edition");
    button_set_text_size(menu->edition, 16);
    button_set_text_position(menu->edition, (sfVector2f){ 10, 5 });
    button_set_position(menu->edition, (sfVector2f){ 60, 0 });
    button_set_size(menu->edition, (sfVector2f){90, 30});
    button_set_text(menu->help, "Help");
    button_set_text_position(menu->help, (sfVector2f){ 10, 5 });
    button_set_position(menu->help, (sfVector2f){ 150, 0 });
    button_set_size(menu->help, (sfVector2f){60, 30});
}

static void set2(menu_t *menu)
{
    button_set_text(menu->file_new, "New");
    button_set_text_position(menu->file_new, (sfVector2f){10, 5});
    button_set_position(menu->file_new, (sfVector2f){0, 30});
    button_set_size(menu->file_new, (sfVector2f){100, 30});
    button_set_text(menu->file_open, "Open");
    button_set_text_position(menu->file_open, (sfVector2f){10, 5});
    button_set_position(menu->file_open, (sfVector2f){0, 60});
    button_set_size(menu->file_open, (sfVector2f){100, 30});
    button_set_text(menu->file_save, "Save");
    button_set_text_position(menu->file_save, (sfVector2f){10, 5});
    button_set_position(menu->file_save, (sfVector2f){0, 90});
    button_set_size(menu->file_save, (sfVector2f){100, 30});
}

static void set3(menu_t *menu)
{
    button_set_text(menu->edition_pencil, "Pencil (P)");
    button_set_text_position(menu->edition_pencil, (sfVector2f){10, 5});
    button_set_position(menu->edition_pencil, (sfVector2f){ 60, 30 });
    button_set_size(menu->edition_pencil, (sfVector2f) { 120, 30 });
    button_set_text(menu->edition_eraser, "Eraser (E)");
    button_set_text_position(menu->edition_eraser, (sfVector2f){10, 5});
    button_set_position(menu->edition_eraser, (sfVector2f){ 60, 60 });
    button_set_size(menu->edition_eraser, (sfVector2f) { 120, 30 });
    button_set_text(menu->edition_hand, "Hand   (H)");
    button_set_text_position(menu->edition_hand, (sfVector2f){10, 5});
    button_set_position(menu->edition_hand, (sfVector2f){ 60, 90 });
    button_set_size(menu->edition_hand, (sfVector2f) { 120, 30 });
}

bool menu_on_attach(context_t *ctx, void *data)
{
    menu_t *menu = data;

    if (!create(ctx, menu))
        return false;
    set(menu);
    set2(menu);
    set3(menu);
    return true;
}

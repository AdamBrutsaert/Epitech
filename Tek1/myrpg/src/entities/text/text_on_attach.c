/*
** EPITECH PROJECT, 2023
** text_on_attach.c
** File description:
** text_on_attach.c
*/

#include "entities/text_impl.h"

#include <stdio.h>

bool text_on_attach(entity_t *entity)
{
    text_t *text = entity_get_data(entity);

    text->text = sfText_create();
    if (text->text == NULL)
        return false;
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, "");
    return true;
}

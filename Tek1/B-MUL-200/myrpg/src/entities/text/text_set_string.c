/*
** EPITECH PROJECT, 2023
** text_on_attach.c
** File description:
** text_on_attach.c
*/

#include "entities/text_impl.h"

#include <stdio.h>

void text_set_string(entity_t *entity, char *string)
{
    text_t *text = entity_get_data(entity);

    sfText_setString(text->text, string);
}

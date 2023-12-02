/*
** EPITECH PROJECT, 2023
** text_on_attach.c
** File description:
** text_on_attach.c
*/

#include "entities/text_impl.h"

#include <stdio.h>

void text_set_size(entity_t *entity, u_int16_t size)
{
    text_t *text = entity_get_data(entity);

    sfText_setCharacterSize(text->text, size);
}

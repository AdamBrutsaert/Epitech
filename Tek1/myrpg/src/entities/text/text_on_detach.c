/*
** EPITECH PROJECT, 2023
** text_on_detach.c
** File description:
** text_on_detach.c
*/

#include "entities/text_impl.h"

#include <stdio.h>

void text_on_detach(entity_t *entity)
{
    text_t *text = entity_get_data(entity);

    sfText_destroy(text->text);
}

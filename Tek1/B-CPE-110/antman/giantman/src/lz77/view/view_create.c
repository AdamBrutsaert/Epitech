/*
** EPITECH PROJECT, 2023
** view_create.c
** File description:
** view_create.c
*/

#include "lz77/view.h"

#include <stdlib.h>

view_t *view_create(uint64_t capacity)
{
    view_t *view = malloc(sizeof(view_t));

    if (view == NULL)
        return NULL;
    view->capacity = capacity + !capacity;
    view->length = 0;
    view->back = 0;
    view->front = 0;
    view->content = malloc(view->capacity * sizeof(char));
    if (view->content == NULL) {
        free(view);
        return NULL;
    }
    return view;
}

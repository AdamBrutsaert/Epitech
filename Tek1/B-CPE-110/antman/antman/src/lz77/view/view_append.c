/*
** EPITECH PROJECT, 2023
** view_append.c
** File description:
** view_append.c
*/

#include "lz77/view.h"

void view_append(view_t *view, char c)
{
    if (view->length == view->capacity) {
        view->front = (view->front + 1) % view->capacity;
        view->length--;
    }
    view->content[view->back] = c;
    view->back = (view->back + 1) % view->capacity;
    view->length++;
}

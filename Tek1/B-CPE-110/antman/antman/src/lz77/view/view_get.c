/*
** EPITECH PROJECT, 2023
** view_get.c
** File description:
** view_get.c
*/

#include "lz77/view.h"

char view_get(view_t *view, uint64_t index)
{
    if (index >= view->length)
        return 0;
    return view->content[(view->front + index) % view->capacity];
}

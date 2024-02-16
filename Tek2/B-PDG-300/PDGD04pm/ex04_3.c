/*
** EPITECH PROJECT, 2024
** ex04_3.c
** File description:
** ex04_3.c
*/

#include "list.h"

#include <stdlib.h>
#include <stdio.h>

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *node = *front_ptr;

    if (node == NULL)
        return false;
    *front_ptr = node->next;
    free(node);
    return true;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    list_t *node = *front_ptr;

    if (node == NULL)
        return false;
    while (node->next != NULL && node->next->next != NULL)
        node = node->next;
    if (node->next) {
        free(node->next);
        node->next = NULL;
    } else {
        free(node);
        *front_ptr = NULL;
    }
    return true;
}

bool list_del_elem_at_position(
    list_t **front_ptr,
    unsigned int position
)
{
    list_t *node = *front_ptr;
    list_t *tmp = NULL;

    if (node == NULL)
        return false;
    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    for (unsigned int i = 1; node != NULL && i < position; i++)
        node = node->next;
    if (node == NULL || node->next == NULL)
        return false;
    tmp = node->next;
    node->next = node->next->next;
    free(tmp);
    return true;
}

void list_clear(list_t **front_ptr)
{
    if (*front_ptr == NULL)
        return;
    list_clear(&(*front_ptr)->next);
    free(*front_ptr);
    *front_ptr = NULL;
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    for (; list != NULL; list = list->next)
        val_disp(list->value);
}

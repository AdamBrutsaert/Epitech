/*
** EPITECH PROJECT, 2024
** ex04.c
** File description:
** ex04.c
*/

#include "list.h"

#include <stdlib.h>

unsigned int list_get_size(list_t *list)
{
    unsigned int length = 0;

    for (; list != NULL; list = list->next)
        length++;
    return length;
}

bool list_is_empty(list_t *list)
{
    return list == NULL;
}

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *node = calloc(1, sizeof(list_t));

    if (node == NULL)
        return false;
    node->value = elem;
    node->next = *front_ptr;
    *front_ptr = node;
    return true;
}

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *list = calloc(1, sizeof(list_t));
    list_t *ptr = *front_ptr;

    if (list == NULL)
        return false;
    list->value = elem;
    list->next = NULL;
    if (ptr == NULL) {
        *front_ptr = list;
    } else {
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = list;
    }
    return true;
}

bool list_add_elem_at_position(
    list_t **front_ptr,
    void *elem,
    unsigned int position
)
{
    list_t *node;
    list_t *list = *front_ptr;

    if (position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    node = calloc(1, sizeof(list_t));
    if (node == NULL)
        return false;
    for (size_t i = 1; i < position && list; i++)
        list = list->next;
    if (list == NULL) {
        free(node);
        return false;
    }
    node->next = list->next;
    node->value = elem;
    list->next = node;
    return true;
}

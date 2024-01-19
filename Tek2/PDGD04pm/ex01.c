/*
** EPITECH PROJECT, 2024
** ex01.c
** File description:
** ex01.c
*/

#include "int_list.h"

#include <stdlib.h>

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *node = calloc(1, sizeof(int_list_t));

    if (node == NULL)
        return false;
    node->value = elem;
    node->next = *front_ptr;
    *front_ptr = node;
    return true;
}

bool int_list_add_elem_at_position(
    int_list_t **front_ptr,
    int elem,
    unsigned int position
)
{
    int_list_t *node;
    int_list_t *list = *front_ptr;

    if (position == 0)
        return int_list_add_elem_at_front(front_ptr, elem);
    node = calloc(1, sizeof(int_list_t));
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

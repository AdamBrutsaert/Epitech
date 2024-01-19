/*
** EPITECH PROJECT, 2024
** ex03.c
** File description:
** ex03.c
*/

#include "int_list.h"

#include <stdlib.h>

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *node = *front_ptr;

    if (node == NULL)
        return false;
    *front_ptr = node->next;
    free(node);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    int_list_t *node = *front_ptr;

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

bool int_list_del_elem_at_position(
    int_list_t **front_ptr,
    unsigned int position
)
{
    int_list_t *node = *front_ptr;
    int_list_t *tmp = NULL;

    if (node == NULL)
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
    for (unsigned int i = 1; node != NULL && i < position; i++)
        node = node->next;
    if (node == NULL || node->next == NULL)
        return false;
    tmp = node->next;
    node->next = node->next->next;
    free(tmp);
    return true;
}

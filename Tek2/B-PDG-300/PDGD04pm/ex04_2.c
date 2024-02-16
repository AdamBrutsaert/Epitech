/*
** EPITECH PROJECT, 2024
** ex04_2.c
** File description:
** ex04_2.c
*/

#include "list.h"

#include <stdlib.h>

void *list_get_elem_at_front(list_t *list)
{
    return list == NULL ? NULL : list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    if (list == NULL)
        return 0;
    while (list->next)
        list = list->next;
    return list->value;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    for (; list != NULL && position != 0; position--)
        list = list->next;
    return list == NULL ? 0 : list->value;
}

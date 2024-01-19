/*
** EPITECH PROJECT, 2024
** ex02.c
** File description:
** ex02.c
*/

#include "int_list.h"

#include <stddef.h>

int int_list_get_elem_at_front(int_list_t *list)
{
    return list == NULL ? 0 : list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    if (list == NULL)
        return 0;
    while (list->next)
        list = list->next;
    return list->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    for (; list != NULL && position != 0; position--)
        list = list->next;
    return list == NULL ? 0 : list->value;
}

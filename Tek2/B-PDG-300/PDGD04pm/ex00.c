/*
** EPITECH PROJECT, 2024
** int_list.c
** File description:
** int_list.c
*/

#include "int_list.h"

#include <stdlib.h>
#include <stdio.h>

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *list = calloc(1, sizeof(int_list_t));
    int_list_t *ptr = *front_ptr;

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

void int_list_dump(int_list_t *list)
{
    for (; list; list = list->next)
        printf("%d\n", list->value);
}

unsigned int int_list_get_size(int_list_t *list)
{
    unsigned int length = 0;

    for (; list != NULL; list = list->next)
        length++;
    return length;
}

bool int_list_is_empty(int_list_t *list)
{
    return list == NULL;
}

void int_list_clear(int_list_t **front_ptr)
{
    if (*front_ptr == NULL)
        return;
    int_list_clear(&(*front_ptr)->next);
    free(*front_ptr);
    *front_ptr = NULL;
}

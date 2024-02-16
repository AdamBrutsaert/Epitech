/*
** EPITECH PROJECT, 2022
** my_delete_nodes
** File description:
** Implementation of my_delete_nodes
*/

#include <stdlib.h>
#include "mylist.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *previous;
    linked_list_t *current;
    linked_list_t *next;

    if (begin == 0)
        return 0;
    while (*begin && (*cmp)((*begin)->data, data_ref) == 0)
        *begin = (*begin)->next;
    previous = *begin;
    current = previous->next;
    while (current) {
        next = current->next;
        if ((*cmp)(current->data, data_ref) == 0) {
            free(current);
            previous->next = next;
        } else
            previous = current;
        current = next;
    }
    return 0;
}

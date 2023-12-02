/*
** EPITECH PROJECT, 2022
** my_add_in_sorted_list
** File description:
** Implementation of my_add_in_sorted_list
*/

#include <stdlib.h>
#include "mylist.h"

static void insert(linked_list_t **begin, linked_list_t *previous,
    linked_list_t *current, void *data)
{
    if (previous) {
        previous->next = malloc(sizeof(linked_list_t));
        previous->next->data = data;
        previous->next->next = current;
    } else {
        *begin = malloc(sizeof(linked_list_t));
        (*begin)->data = data;
        (*begin)->next = current;
    }
}

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    linked_list_t *previous = 0;
    linked_list_t *current;
    char lower = 0;
    char higher = 0;

    if (!begin)
        return;
    for (current = *begin; current; current = current->next) {
        if ((*cmp)(data, current->data) > 0)
            higher = 1;
        if ((*cmp)(data, current->data) <= 0)
            lower = 1;
        if ((lower && higher) || (lower && current == *begin))
            break;
        previous = current;
    }
    insert(begin, previous, current, data);
}

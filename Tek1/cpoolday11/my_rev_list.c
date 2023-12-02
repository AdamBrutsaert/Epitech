/*
** EPITECH PROJECT, 2022
** my_rev_list
** File description:
** Implementation of my_rev_list
*/

#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *previous = 0;
    linked_list_t *current = 0;
    linked_list_t *next = 0;

    if (begin == 0)
        return;
    current = *begin;
    while (current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *begin = previous;
}

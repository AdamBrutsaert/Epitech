/*
** EPITECH PROJECT, 2022
** my_concat_list
** File description:
** Implementation of my_concat_list
*/

#include "mylist.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *tail;

    if (!begin1)
        return;
    tail = *begin1;
    while (tail->next)
        tail = tail->next;
    tail->next = begin2;
}

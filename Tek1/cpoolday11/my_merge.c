/*
** EPITECH PROJECT, 2022
** my_merge
** File description:
** Implementation of my_merge
*/

#include "mylist.h"

extern void my_add_in_sorted_list(linked_list_t **begin, void *data,
    int (*cmp)());

void my_merge(linked_list_t **begin1, linked_list_t *begin2, int (*cmp)())
{
    for (; begin2; begin2 = begin2->next)
        my_add_in_sorted_list(begin1, begin2->data, cmp);
}

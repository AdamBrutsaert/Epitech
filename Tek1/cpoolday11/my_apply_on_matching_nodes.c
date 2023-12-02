/*
** EPITECH PROJECT, 2022
** my_apply_on_matching_nodes
** File description:
** Implementation of apply_on_matching_nodes
*/

#include "mylist.h"

int my_apply_on_matching_nodes(
    linked_list_t *begin, int (*f)(), void const *data_ref, int (*cmp)())
{
    for (; begin; begin = begin->next) {
        if ((*cmp)(begin->data, data_ref) == 0)
            (*f)(begin->data);
    }
    return 0;
}

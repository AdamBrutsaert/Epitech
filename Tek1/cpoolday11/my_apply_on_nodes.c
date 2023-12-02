/*
** EPITECH PROJECT, 2022
** my_apply_on_nodes
** File description:
** Implementation of my_apply_on_nodes
*/

#include "mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    for (; begin; begin = begin->next)
        (*f)(begin->data);
    return 0;
}

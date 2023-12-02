/*
** EPITECH PROJECT, 2022
** my_find_node
** File description:
** Implementation of my_find_node
*/

#include "mylist.h"

linked_list_t *my_find_node(
    linked_list_t const *begin, void const *data_ref, int (*cmp)())
{
    for (linked_list_t const *ptr = begin; ptr; ptr = ptr->next) {
        if ((*cmp)(ptr->data, data_ref) == 0)
            return (linked_list_t *) ptr;
    }
    return 0;
}

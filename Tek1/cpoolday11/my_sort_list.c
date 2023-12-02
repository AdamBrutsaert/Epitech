/*
** EPITECH PROJECT, 2022
** my_sort_list
** File description:
** Implementation of my_sort_list
*/

#include "my.h"
#include "mylist.h"

extern int my_list_size(linked_list_t const *begin);

static void swap_node(linked_list_t *begin, unsigned int i, unsigned int j)
{
    linked_list_t *node = begin;
    linked_list_t *node2 = begin;
    void *data;

    for (; i; i--)
        node = node->next;
    for (; j; j--)
        node2 = node2->next;
    data = node->data;
    node->data = node2->data;
    node2->data = data;
}

static unsigned int find_minimum(linked_list_t *begin, int (*cmp)())
{
    unsigned int min_index = 0;
    void *data = begin->data;

    for (unsigned int i = 0; begin; begin = begin->next) {
        if ((*cmp)(begin->data, data) < 0) {
            min_index = i;
            data = begin->data;
        }
        i++;
    }
    return min_index;
}

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    linked_list_t *list;
    int size;

    if (!begin)
        return;
    list = *begin;
    size = my_list_size(list);
    for (int i = 0; i < size; i++) {
        swap_node(list, 0, find_minimum(list, cmp));
        list = list->next;
    }
}

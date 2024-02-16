/*
** EPITECH PROJECT, 2022
** my_params_to_list
** File description:
** Implementation of my_params_to_list
*/

#include <stdlib.h>
#include "mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *head = 0;

    for (int i = 0; i < ac; i++) {
        linked_list_t *node = malloc(sizeof(linked_list_t));
        node->data = av[i];
        node->next = head;
        head = node;
    }
    return head;
}

/*
** EPITECH PROJECT, 2022
** my_list_size
** File description:
** Implementation of my_list_size
*/

#include <stdio.h>
#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int size = 0;

    for (; begin; begin = begin->next)
        size++;
    return size;
}

/*
** EPITECH PROJECT, 2024
** utils.c
** File description:
** utils.c
*/

#include "utils.h"

bool compare_int_list(int_list_t *list, int *expected, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (list == NULL)
            return false;
        if (list->value != expected[i])
            return false;
        list = list->next;
    }
    return list == NULL;
}

bool compare_list(list_t *list, void **expected, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (list == NULL)
            return false;
        if (list->value != expected[i])
            return false;
        list = list->next;
    }
    return list == NULL;
}

/*
** EPITECH PROJECT, 2023
** path_new.c
** File description:
** path_new.c
*/

#include "lem_in/path_impl.h"
#include "my/memory.h"

path_t *path_new(void)
{
    return my_calloc(sizeof(path_t));
}

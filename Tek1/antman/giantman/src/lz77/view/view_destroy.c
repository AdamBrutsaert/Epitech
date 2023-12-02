/*
** EPITECH PROJECT, 2023
** view_destroy.c
** File description:
** view_destroy.c
*/

#include "lz77/view.h"

#include <stdlib.h>

void view_destroy(view_t *view)
{
    free(view->content);
    free(view);
}

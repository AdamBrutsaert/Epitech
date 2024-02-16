/*
** EPITECH PROJECT, 2023
** view_find.c
** File description:
** view_find.c
*/

#include "lz77/view.h"

static uint64_t match(view_t *view, uint64_t index, char const *pattern,
    uint64_t length)
{
    uint64_t count = 0;

    while (count < length && pattern[count] == view_get(view, index + count))
        count++;
    return count;
}

uint64_t view_find(view_t *view, const char *pattern, uint64_t length)
{
    if (length == 0)
        return 0;
    for (uint64_t distance = length - 1; distance < view->length; distance++)
        if (match(view, view->length - 1 - distance, pattern, length) == length)
            return distance;
    return view->length;
}

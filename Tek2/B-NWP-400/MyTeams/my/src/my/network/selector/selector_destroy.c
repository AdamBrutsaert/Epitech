/*
** EPITECH PROJECT, 2024
** selector_deinit.c
** File description:
** selector_deinit.c
*/

#include "my/network/selector.h"
#include "my/memory/allocation.h"

void selector_destroy(selector_t *self)
{
    deallocate(self);
}

/*
** EPITECH PROJECT, 2023
** hand_destroy.c
** File description:
** hand_destroy.c
*/

#include "private/paint/components/tools/hand.h"
#include "my/memory.h"

void hand_destroy(hand_t *hand)
{
    if (!hand)
        return;
    my_free(hand);
}

/*
** EPITECH PROJECT, 2023
** hand_create.c
** File description:
** hand_create.c
*/

#include "private/paint/components/tools/hand.h"
#include "my/memory.h"

hand_t *hand_create(__attribute__((unused)) context_t *ctx,
    canvas_t *canvas)
{
    hand_t *hand = my_calloc(sizeof(hand_t));

    if (!hand)
        return NULL;
    hand->canvas = canvas;
    return hand;
}

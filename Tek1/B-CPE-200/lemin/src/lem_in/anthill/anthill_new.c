/*
** EPITECH PROJECT, 2023
** anthill_new.c
** File description:
** anthill_new.c
*/

#include "lem_in/anthill_impl.h"
#include "my/memory.h"

anthill_t *anthill_new(void)
{
    anthill_t *anthill = my_calloc(sizeof(anthill_t));

    if (anthill == NULL)
        return NULL;
    anthill->rooms = my_calloc(sizeof(room_t *) * ROOMS_HASHMAP_SIZE);
    if (anthill->rooms == NULL) {
        anthill_delete(anthill);
        return NULL;
    }
    anthill->matrix = matrix_new(0);
    if (anthill->matrix == NULL) {
        anthill_delete(anthill);
        return NULL;
    }
    return anthill;
}

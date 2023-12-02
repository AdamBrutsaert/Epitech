/*
** EPITECH PROJECT, 2022
** peashooter_destroy_pea.c
** File description:
** peashooter_destroy_pea.c
*/

#include "hunter.h"

void peashooter_destroy_pea(scene_t *scene, scene_t *pea)
{
    pea_destroy(pea);
    peashooter_pop_pea(scene, pea);
}

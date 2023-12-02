/*
** EPITECH PROJECT, 2022
** wave_destroy_zombie.c
** File description:
** wave_destroy_zombie.c
*/

#include "hunter.h"

void wave_destroy_zombie(scene_t *scene, scene_t *zombie)
{
    zombie_destroy(zombie);
    wave_pop_zombie(scene, zombie);
}

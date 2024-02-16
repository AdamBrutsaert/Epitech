/*
** EPITECH PROJECT, 2022
** peashooter_on_signal.c
** File description:
** peashooter_on_signal.c
*/

#include "hunter.h"
#include "my.h"

void peashooter_on_signal(scene_t *scene, scene_t *sender, char const *name)
{
    if (!my_strcmp(name, "pea_out_of_map")) {
        peashooter_pop_pea(scene, sender);
        scene_remove_child(scene, sender);
        scene_send_signal(scene, "lose_heart");
    }
    if (!my_strcmp(name, "pea_destroyed"))
        scene_remove_child(scene, sender);
}

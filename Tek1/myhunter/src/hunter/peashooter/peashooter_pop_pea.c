/*
** EPITECH PROJECT, 2022
** peashooter_pop_pea.c
** File description:
** peashooter_pop_pea.c
*/

#include "hunter.h"
#include "my.h"

void peashooter_pop_pea(scene_t *scene, scene_t *pea)
{
    peashooter_data_t *data = scene->data;
    uint32_t i = 0;

    while (i < data->pea_vector.length && data->pea_vector.peas[i] != pea)
        i++;
    if (i == data->pea_vector.length)
        return;
    my_memmove(&data->pea_vector.peas[i], &data->pea_vector.peas[i + 1],
        sizeof(scene_t *) * (data->pea_vector.length - i - 1));
    data->pea_vector.length--;
}

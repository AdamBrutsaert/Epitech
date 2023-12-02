/*
** EPITECH PROJECT, 2022
** parse_tower.c
** File description:
** parse_tower.c
*/

#include "parser.h"

static int8_t check_ranges(uint32_t *values)
{
    if (values[0] > 1920 || values[1] > 1080)
        return 84;
    if (values[2] == 0)
        return 84;
    return 0;
}

int32_t parse_tower(char **words, uint64_t count, vector_t *towers)
{
    tower_t tower;
    uint32_t values[3];

    if (count != 4)
        return 84;
    if (!is_u32(words[1]) || !is_u32(words[2]) || !is_u32(words[3]))
        return 84;
    for (uint8_t i = 0; i < 3; i++)
        values[i] = str_to_u32(words[i + 1]);
    if (check_ranges(values) == 84)
        return 84;
    tower.position = (vec2f_t){values[0], values[1]};
    tower.range = values[2];
    vector_push(towers, &tower);
    return 0;
}

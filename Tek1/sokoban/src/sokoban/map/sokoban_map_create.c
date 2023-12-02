/*
** EPITECH PROJECT, 2022
** sokoban_map_create.c
** File description:
** sokoban_map_create.c
*/

#include "sokoban/map/sokoban_map.h"
#include "sokoban/map/sokoban_map_parser.h"
#include "my/file.h"
#include "my/memory.h"
#include "my/string.h"
#include "my/math.h"

static u64_t get_height(char const *content)
{
    u64_t line = 1;

    for (; *content; content++)
        if (*content == '\n')
            line++;
    return line;
}

static u64_t get_width(sokoban_map_t *map)
{
    u64_t max = my_strlen(map->rows[0]);

    for (uint64_t i = 1; i < map->height; i++)
        max = my_u64_max(max, my_strlen(map->rows[i]));
    return max;
}

status_t sokoban_map_create(sokoban_map_t *map, char const *name)
{
    file_t file;
    char *content;

    map->name = name;
    if (file_create(&file, name))
        return 84;
    content = file_read(&file);
    map->height = get_height(content);
    map->rows = my_calloc(map->height * sizeof(char *));
    vector_create(&map->objectives, sizeof(position_t));
    vector_create(&map->boxes, sizeof(position_t));
    if (sokoban_map_parse(map, content)) {
        sokoban_map_destroy(map);
        return 84;
    }
    map->width = get_width(map);
    file_destroy(&file);
    return 0;
}

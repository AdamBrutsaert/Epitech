/*
** EPITECH PROJECT, 2023
** entity_map_parse_collisions.c
** File description:
** entity_map_parse_collisions.c
*/

#include "entities/map_impl.h"
#include "my/stdio.h"
#include "my/string.h"
#include "my/memory.h"
#include "my/conversion.h"

#include <stdlib.h>

static bool add_hitbox(entity_t *entity, char **array)
{
    sfFloatRect rect;

    rect.left = string_to_integer(array[0]);
    rect.top = string_to_integer(array[1]);
    rect.width = string_to_integer(array[2]);
    rect.height = string_to_integer(array[3]);
    return entity_add_hitbox(entity, rect) != -1;
}

static bool parse_line(entity_t *entity, char *line)
{
    char **array;

    if (line[0] == '#')
        return true;
    array = my_strsplit(line, ',');
    if (array == NULL)
        return false;
    if (my_arrlen(array) != 4 || !string_is_integer(array[0])
        || !string_is_integer(array[1]) || !string_is_integer(array[2])
        || !string_is_integer(array[3])) {
        my_freearr(array);
        return false;
    }
    if (!add_hitbox(entity, array)) {
        my_freearr(array);
        return false;
    }
    my_freearr(array);
    return true;
}

static bool process_content(entity_t *entity, char *content)
{
    char **array = my_strsplit(content, '\n');

    if (array == NULL)
        return false;
    for (size_t i = 0; array[i]; i++) {
        if (!parse_line(entity, array[i])) {
            my_freearr(array);
            return false;
        }
    }
    my_freearr(array);
    return true;
}

bool entity_map_parse_collisions(entity_t *entity)
{
    entity_map_t *map = entity_get_data(entity);
    char *content;

    if (map->collisions == NULL)
        return true;
    content = read_file(map->collisions);
    if (content == NULL)
        return false;
    if (!process_content(entity, content)) {
        free(content);
        return false;
    }
    free(content);
    return true;
}

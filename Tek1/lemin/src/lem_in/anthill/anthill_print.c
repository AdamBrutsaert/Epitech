/*
** EPITECH PROJECT, 2023
** anthill_print.c
** File description:
** anthill_print.c
*/

#include "lem_in/anthill_impl.h"
#include "my/stdio.h"

static void print_tunnel(anthill_t *anthill, size_t i, size_t j)
{
    room_t *room1;
    room_t *room2;

    if (!matrix_get(anthill->matrix, i, j))
        return;
    room1 = anthill_get_room_from_id(anthill, i);
    room2 = anthill_get_room_from_id(anthill, j);
    my_puts(room_get_name(room1));
    my_putc('-');
    my_puts(room_get_name(room2));
    my_putc('\n');
}

static void print_tunnels(anthill_t *anthill)
{
    size_t count = matrix_get_size(anthill->matrix);

    my_puts("#tunnels\n");
    for (size_t i = 0; i < count; i++) {
        for (size_t j = i + 1; j < count; j++)
            print_tunnel(anthill, i, j);
    }
}

static void print_room(anthill_t *anthill, room_t *room)
{
    if (room == anthill->start)
        my_puts("##start\n");
    if (room == anthill->end)
        my_puts("##end\n");
    my_puts(room_get_name(room));
    my_putc(' ');
    my_puti(room_get_x(room));
    my_putc(' ');
    my_puti(room_get_y(room));
    my_putc('\n');
}

static void print_rooms(anthill_t *anthill)
{
    room_node_t *node;

    my_puts("#rooms\n");
    for (size_t i = 0; i < ROOMS_HASHMAP_SIZE; i++) {
        node = anthill->rooms[i];
        while (node != NULL) {
            print_room(anthill, node->room);
            node = node->next;
        }
    }
}

void anthill_print(anthill_t *anthill)
{
    my_puts("#number_of_ants\n");
    my_putu(anthill->ant_count);
    my_putc('\n');
    print_rooms(anthill);
    print_tunnels(anthill);
}

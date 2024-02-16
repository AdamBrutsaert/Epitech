/*
** EPITECH PROJECT, 2023
** ant_print.c
** File description:
** ant_print.c
*/

#include "lem_in/ant_impl.h"
#include "my/stdio.h"

void ant_print(ant_t *ant, room_t *room)
{
    my_putc('P');
    my_putu(ant->id);
    my_putc('-');
    my_puts(room_get_name(room));
}

/*
** EPITECH PROJECT, 2024
** team_destroy.c
** File description:
** team_destroy.c
*/

#include "protocol/entities/team.h"

#include "my/memory/allocation.h"

void team_destroy(team_t *team)
{
    string_destroy(team->uuid);
    string_destroy(team->name);
    string_destroy(team->description);
    deallocate(team);
}

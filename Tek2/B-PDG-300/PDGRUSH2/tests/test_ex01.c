/*
** EPITECH PROJECT, 2024
** test_ex01.c
** File description:
** test_ex01.c
*/

#include "../new.h"
#include "../player.h"

#include <criterion/criterion.h>

Test(player, does_not_crash)
{
    Object *player = new(Player);
    delete(player);
}

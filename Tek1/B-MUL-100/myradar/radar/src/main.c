/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "radar.h"

#include <my/stdio.h>

int main(int argc, char **argv, char **env)
{
    if (!env[0]) {
        my_eputs("[MyRadar] Error: missing environement variables!\n");
        return 84;
    }
    return exec_radar(argc, argv);
}

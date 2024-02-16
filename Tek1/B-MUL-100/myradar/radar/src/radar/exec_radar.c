/*
** EPITECH PROJECT, 2022
** exec_radar.c
** File description:
** exec_radar.c
*/

#include "radar.h"
#include "parser.h"

#include <my/string.h>
#include <my/stdio.h>

static void print_help(char *program)
{
    my_eputs("Air traffic simulation panel\n\n");
    my_eputs("USAGE\n");
    my_eputs("    ");
    my_eputs(program);
    my_eputs(" [OPTIONS] path_to_script\n\n");
    my_eputs("    path_to_script    The path to the script file.\n\n");
    my_eputs("OPTIONS\n");
    my_eputs("    -h                Print the usage and quit.\n\n");
    my_eputs("USER INTERACTIONS\n");
    my_eputs("    <F11>             enable/disable fullscreen.\n");
    my_eputs("    <ESCAPE>          quit the program.\n");
    my_eputs("    <SPACE>           pause/unpause the simulation.\n");
    my_eputs("    <U>               cap/uncap framerate.\n");
    my_eputs("    <L>               enable/disable hitboxes and areas.\n");
    my_eputs("    <S>               enable/disable sprites.\n");
    my_eputs("    <G>               show/hide grid.\n");
    my_eputs("    <D>               show/hide debug informations.\n");
}

static int8_t handle_arguments(int argc, char **argv, vector_t **aircrafts,
    vector_t **towers)
{
    if (argc != 2) {
        my_eputs("[MyRadar] Error: invalid number of arguments!\n");
        my_eputs("[MyRadar] Info: Try again with -h for more information.\n");
        return 84;
    }
    if (!my_strcmp(argv[1], "-h")) {
        print_help(argv[0]);
        return 1;
    }
    *aircrafts = vector_create(sizeof(aircraft_t));
    *towers = vector_create(sizeof(tower_t));
    if (parse_file(argv[1], *aircrafts, *towers) == 84) {
        vector_destroy(*aircrafts);
        vector_destroy(*towers);
        return 84;
    }
    return 0;
}

int32_t exec_radar(int argc, char **argv)
{
    vector_t *aircrafts;
    vector_t *towers;
    radar_t *radar;
    int8_t result;

    if (radar_check_resources() == 84) {
        my_eputs("[MyRadar] Error: some resources are missing!\n");
        return 84;
    }
    result = handle_arguments(argc, argv, &aircrafts, &towers);
    if (result == 84)
        return 84;
    if (result == 1)
        return 0;
    radar = radar_create(aircrafts, towers);
    radar_run(radar);
    radar_destroy(radar);
    return 0;
}

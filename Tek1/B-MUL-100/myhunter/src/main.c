/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "hunter.h"
#include "my.h"

static int8_t my_hunter(void)
{
    app_t *app = app_create(1280, 720, "My Hunter");

    if (game_test_resources())
        return 84;
    app_set_scene(app, menu_create(app));
    app_run(app);
    app_destroy(app);
    return 0;
}

static int8_t help(char *prog)
{
    my_prints("My Hunter\n");
    my_prints("USAGE\n");
    my_prints("\t");
    my_prints(prog);
    my_prints(" [-h]\n");
    my_prints("DESCRIPTION\n");
    my_prints("\tThis is a game where you have to shoot zombies with peas.\n");
    my_prints("\tPress the left mouse button to shoot peas at zombiess.\n");
    my_prints("\tYou have 3 lives, you lose one when a zombie ");
    my_prints("get out of the map.\n");
    my_prints("\tYou win when you finish the 30th wave.\n");
    my_prints("\tEach second your score is increased by one.\n");
    my_prints("\tEach zombie you kill rewards you 10 points.\n");
    my_prints("\tEach wave you finish rewards you 100 points.\n");
    my_prints("OPTIONS\n");
    my_prints("\t-h\tPrint the usage and quit.\n");
    return 0;
}

int main(int argc, char **argv, char **env)
{
    if (!env[0])
        return 84;
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return help(argv[0]);
    if (argc == 1)
        return my_hunter();
    return 84;
}

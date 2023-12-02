/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "rpg.h"
#include "my/stdio.h"
#include "my/string.h"
#include "save.h"

static int help(char *program)
{
    my_puts("USAGE :\n    ");
    my_puts(program);
    my_puts(" [-h]");
    my_puts("\n\nDESCRIPTION :\n");
    my_puts("    In this CSFML RPG game, you play as a mage who can shoot");
    my_puts(" fireballs. \n    Your objective is to complete quests ");
    my_puts("to search for");
    my_puts(" four potions by \n    navigating through different rooms and");
    my_puts(" defeating enemies.\n");
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return help(argv[0]);
    if (envp[0] == NULL)
        return 84;
    return rpg();
}

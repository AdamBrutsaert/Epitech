/*
** EPITECH PROJECT, 2023
** rpg.c
** File description:
** rpg.c
*/

#include "rpg.h"
#include "save.h"

int rpg(void)
{
    engine_t *engine = engine_new(WINDOW_WIDTH, WINDOW_HEIGHT, "MyRPG");

    if (engine == NULL)
        return 84;
    if (!rpg_switch_to_menu(engine)) {
        engine_delete(engine);
        return 84;
    }
    if (!engine_run(engine)) {
        engine_delete(engine);
        return 84;
    }
    engine_delete(engine);
    return 0;
}

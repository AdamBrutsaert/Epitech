/*
** EPITECH PROJECT, 2023
** menu_resume_clicked.c
** File description:
** menu_resume_clicked.c
*/

#include "rpg.h"
#include "save.h"

void button_menu_resume_clicked(entity_t *entity, void *data)
{
    save_read();
    rpg_switch_to_level(entity_get_engine(entity));
}

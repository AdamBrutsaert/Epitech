/*
** EPITECH PROJECT, 2023
** antman_set_file.c
** File description:
** antman_set_file.c
*/

#include "antman.h"
#include "antman/antman.h"

void antman_set_file(antman_t *antman, const char *filepath)
{
    antman->filepath = filepath;
}

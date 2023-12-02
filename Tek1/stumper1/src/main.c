/*
** EPITECH PROJECT, 2023
** B-CPE-210-stumper-adam.brutsaert
** File description:
** main.c
*/

#include "head.h"

int main(__attribute__((unused)) int argc, char **argv)
{
    head_t *head = head_create();
    int status;

    if (!head)
        return 84;
    head_parse(head, argv + 1);
    status = head_process(head);
    head_destroy(head);
    return status;
}

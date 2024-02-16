/*
** EPITECH PROJECT, 2023
** head.c
** File description:
** head.c
*/

#include "head.h"

#include <stdlib.h>

head_t *head_create(void)
{
    head_t *head = malloc(sizeof(head_t));

    if (head == NULL)
        return NULL;
    head->flags = FLAG_LINES;
    head->files = malloc(sizeof(char *));
    if (head->files == NULL) {
        free(head);
        return NULL;
    }
    head->files[0] = NULL;
    head->bytes = 0;
    head->lines = 10;
    return head;
}

void head_destroy(head_t *head)
{
    free(head->files);
    free(head);
}

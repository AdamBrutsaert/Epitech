/*
** EPITECH PROJECT, 2022
** mylist
** File description:
** Header of mylist
*/

#pragma once

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

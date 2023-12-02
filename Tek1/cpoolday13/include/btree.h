/*
** EPITECH PROJECT, 2022
** btree
** File description:
** Header of btree
*/

#pragma once

#include <stddef.h>

typedef struct btree {
    struct btree *left;
    struct btree *right;
    void *item;
} btree_t;

typedef struct btree_level {
    size_t current;
    size_t target;
    char first;
    void (*func)(void *, int, int);
} btree_level_t;

btree_t *btree_create_node(void *item);
void btree_apply_prefix(btree_t *root, int (*applyf)(void *));
void btree_apply_infix(btree_t *root, int (*applyf)(void *));
void btree_apply_suffix(btree_t *root, int (*applyf)(void *));
void btree_insert_data(btree_t **root, void *item, int (*cmpf)());
void *btree_search_item(btree_t *root, void const *data_ref, int (*cmpf)());
size_t btree_level_count(btree_t const *root);
void btree_apply_by_level(
    btree_t *root, void (*applyf)(void *item, int level, int is_first_elem));

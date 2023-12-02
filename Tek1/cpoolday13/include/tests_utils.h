/*
** EPITECH PROJECT, 2022
** tests_utils
** File description:
** Header of tests_utils
*/

#pragma once

#include "btree.h"

void free_tree(btree_t *root);
btree_t *create_empty_node(void);
btree_t *create_empty_tree(void);
void print_tree(btree_t *root, int level);

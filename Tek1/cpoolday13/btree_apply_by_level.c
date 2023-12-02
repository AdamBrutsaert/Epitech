/*
** EPITECH PROJECT, 2022
** btree_apply_by_level
** File description:
** Implementation of btree_apply_by_level
*/

#include <stdio.h>
#include "btree.h"

static int apply_to_level(btree_t *root, btree_level_t level)
{
    if (root == 0)
        return 0;
    if (level.target == level.current) {
        (*level.func)(root->item, level.current, level.first);
        return 1;
    }
    level.current += 1;
    if (apply_to_level(root->left, level))
        level.first = 0;
    apply_to_level(root->right, level);
    return !level.first;
}

void btree_apply_by_level(
    btree_t *root, void (*applyf)(void *item, int level, int is_first_elem))
{
    size_t height = btree_level_count(root);

    for (unsigned int i = 0; i < height; i++)
        apply_to_level(root, (btree_level_t){0, i, 1, applyf});
}

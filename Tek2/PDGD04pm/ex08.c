/*
** EPITECH PROJECT, 2024
** ex08.c
** File description:
** ex08.c
*/

#include "tree.h"

#include <stdlib.h>

bool tree_is_empty(tree_t *tree)
{
    return tree == NULL;
}

void tree_node_dump(tree_t *node, dump_func_t dump_func)
{
    if (node != NULL)
        dump_func(node->data);
}

bool init_tree(tree_t **tree_ptr, void *data)
{
    *tree_ptr = malloc(sizeof(tree_t));
    if (*tree_ptr == NULL)
        return false;
    (*tree_ptr)->data = data;
    (*tree_ptr)->children = NULL;
    return true;
}

tree_t *tree_add_child(tree_t *node, void *data)
{
    tree_t *new_node;

    if (!init_tree(&new_node, data))
        return NULL;
    if (!list_add_elem_at_back(&node->children, new_node)) {
        free(new_node);
        return NULL;
    }
    return new_node;
}

bool tree_destroy(tree_t **tree_ptr)
{
    if (*tree_ptr == NULL)
        return false;
    for (list_t *node = (*tree_ptr)->children; node != NULL; node = node->next)
        tree_destroy((tree_t **)&node->value);
    list_clear(&(*tree_ptr)->children);
    free(*tree_ptr);
    *tree_ptr = NULL;
    return true;
}

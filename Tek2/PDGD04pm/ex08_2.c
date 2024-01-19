/*
** EPITECH PROJECT, 2024
** ex08_2.c
** File description:
** ex08_2.c
*/

#include "tree.h"

#include <stdlib.h>
#include <stdio.h>

static void add_its_children(tree_t *node, container_t *container)
{
    for (list_t *child = node->children; child != NULL; child = child->next)
        container->push_func(container->container, child->value);
}

void tree_traversal(
    tree_t *tree,
    container_t *container,
    dump_func_t dump_func
)
{
    if (tree == NULL)
        return;
    container->push_func(container->container, tree);
    for (tree_t *node = container->pop_func(container->container);
        node != NULL; node = container->pop_func(container->container)) {
        dump_func(node->data);
        add_its_children(node, container);
    }
}

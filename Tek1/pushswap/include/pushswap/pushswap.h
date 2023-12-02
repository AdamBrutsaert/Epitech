/*
** EPITECH PROJECT, 2022
** pushswap.h
** File description:
** pushswap.h
*/

#pragma once

#include "my/deque.h"
#include "my/vector.h"

typedef struct {
    vector_t numbers;
    vector_t operations;
    deque_t l_a;
    deque_t l_b;
} pushswap_t;

status_t pushswap(int argc, char **argv);

status_t pushswap_create(pushswap_t *ps);
void pushswap_destroy(pushswap_t *ps);

status_t pushswap_simple(pushswap_t *ps);
void pushswap_sort(pushswap_t *ps);
void pushswap_sort_2(pushswap_t *ps);
void pushswap_sort_3(pushswap_t *ps);
void pushswap_sort_4_5(pushswap_t *ps);
void pushswap_radix_sort(pushswap_t *ps);
void pushswap_bubble_sort(pushswap_t *ps);

void pushswap_print_operations(pushswap_t *ps);

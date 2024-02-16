/*
** EPITECH PROJECT, 2022
** operations.h
** File description:
** operations.h
*/

#pragma once

#include "pushswap.h"

typedef enum operation {
    SA = 0,
    SB = 1,
    SC = 2,
    PA = 3,
    PB = 4,
    RA = 5,
    RB = 6,
    RR = 7,
    RRA = 8,
    RRB = 9,
    RRR = 10
} operation_t;

void pushswap_apply_sa(pushswap_t *ps);
void pushswap_apply_sb(pushswap_t *ps);
void pushswap_apply_sc(pushswap_t *ps);

void pushswap_apply_pa(pushswap_t *ps);
void pushswap_apply_pb(pushswap_t *ps);

void pushswap_apply_ra(pushswap_t *ps);
void pushswap_apply_rb(pushswap_t *ps);
void pushswap_apply_rr(pushswap_t *ps);

void pushswap_apply_rra(pushswap_t *ps);
void pushswap_apply_rrb(pushswap_t *ps);
void pushswap_apply_rrr(pushswap_t *ps);

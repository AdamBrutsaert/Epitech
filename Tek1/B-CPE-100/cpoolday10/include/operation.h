/*
** EPITECH PROJECT, 2022
** operator
** File description:
** Header of operator
*/

#pragma once

struct operator {
    char const *token;
    int (*func)(int, int);
};

int my_add(int, int);
int my_sub(int, int);
int my_div(int, int);
int my_mul(int, int);
int my_mod(int, int);
int my_usage(int, int);

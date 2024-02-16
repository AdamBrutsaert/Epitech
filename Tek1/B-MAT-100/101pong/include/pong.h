/*
** EPITECH PROJECT, 2022
** pong.h
** File description:
** pong.h
*/

#pragma once

typedef struct {
    double x0;
    double y0;
    double z0;
    double x1;
    double y1;
    double z1;
    int n;
} parameters_t;

int pong(parameters_t *parameters);

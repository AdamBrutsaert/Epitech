/*
** EPITECH PROJECT, 2022
** pong.c
** File description:
** pong.c
*/

#include "pong.h"

#include <stdio.h>
#include <math.h>

static void print_velocity(parameters_t *params)
{
    double vx = params->x1 - params->x0;
    double vy = params->y1 - params->y0;
    double vz = params->z1 - params->z0;

    puts("The velocity vector of the ball is:");
    printf("(%.2f, %.2f, %.2f)\n", vx, vy, vz);
}

static void print_future_position(parameters_t *params)
{
    double fx = params->x1 + params->n * (params->x1 - params->x0);
    double fy = params->y1 + params->n * (params->y1 - params->y0);
    double fz = params->z1 + params->n * (params->z1 - params->z0);

    printf("At time t + %d, ball coordinates will be:\n", params->n);
    printf("(%.2f, %.2f, %.2f)\n", fx, fy, fz);
}

static void print_incident_angle(parameters_t *params)
{
    double vx = params->x1 - params->x0;
    double vy = params->y1 - params->y0;
    double vz = params->z1 - params->z0;
    double angle;

    if (params->z1 == 0.0) {
        puts("The incidence angle is:");
        puts("0.00 degrees");
    } else if ((params->z1 < 0 && vz <= 0) || (params->z1 >= 0 && vz >= 0)
        || (vx == 0 && vy == 0 && vz == 0)) {
        puts("The ball won't reach the paddle.");
    } else {
        angle = acos(sqrt((vx * vx + vy * vy) / (vx * vx + vy * vy + vz * vz)));
        angle *= 180.0 / 3.14159265358979323846;
        puts("The incidence angle is:");
        printf("%.2f degrees\n", angle);
    }
}

int pong(parameters_t *params)
{
    if (params->n < 0) {
        fputs("Error: invalid time shift, must be an integer greater than"
            " or equal to zero\n", stderr);
        return 84;
    }
    print_velocity(params);
    print_future_position(params);
    print_incident_angle(params);
    return 0;
}

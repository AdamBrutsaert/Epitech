/*
** EPITECH PROJECT, 2022
** aircraft_intersects.c
** File description:
** aircraft_intersects.c
*/

#include "aircraft.h"

static float min(float a, float b, float c, float d)
{
    if (a <= b && a <= c && a <= d)
        return a;
    if (b <= a && b <= c && b <= d)
        return b;
    if (c <= a && c <= b && c <= d)
        return c;
    return d;
}

static float max(float a, float b, float c, float d)
{
    if (a >= b && a >= c && a >= d)
        return a;
    if (b >= a && b >= c && b >= d)
        return b;
    if (c >= a && c >= b && c >= d)
        return c;
    return d;
}

vec2f_t get_projection(vec2f_t axis, vec2f_t point)
{
    if (axis.x == 0 && axis.y == 0)
        return ((vec2f_t){0, 0});

    return (vec2f_t){
        (axis.x * point.x + axis.y * point.y)
            / (axis.x * axis.x + axis.y * axis.y) * axis.x,
        (axis.x * point.x + axis.y * point.y)
            / (axis.x * axis.x + axis.y * axis.y) * axis.y
    };
}

int8_t is_overlapping(vec2f_t axis, aircraft_t *aircraft, aircraft_t *other)
{
    float dot1 = vec2f_dot(get_projection(axis, aircraft->ul), axis);
    float dot2 = vec2f_dot(get_projection(axis, aircraft->ur), axis);
    float dot3 = vec2f_dot(get_projection(axis, aircraft->bl), axis);
    float dot4 = vec2f_dot(get_projection(axis, aircraft->br), axis);
    float dot5 = vec2f_dot(get_projection(axis, other->ul), axis);
    float dot6 = vec2f_dot(get_projection(axis, other->ur), axis);
    float dot7 = vec2f_dot(get_projection(axis, other->bl), axis);
    float dot8 = vec2f_dot(get_projection(axis, other->br), axis);

    return min(dot5, dot6, dot7, dot8) <= max(dot1, dot2, dot3, dot4)
        && max(dot5, dot6, dot7, dot8) >= min(dot1, dot2, dot3, dot4);
}

int8_t aircraft_intersects(aircraft_t *aircraft, aircraft_t *other)
{
    if (!is_overlapping(vec2f_sub(aircraft->ur, aircraft->ul), aircraft, other))
        return 0;
    if (!is_overlapping(vec2f_sub(aircraft->ur, aircraft->br), aircraft, other))
        return 0;
    if (!is_overlapping(vec2f_sub(aircraft->ul, aircraft->bl), aircraft, other))
        return 0;
    if (!is_overlapping(vec2f_sub(aircraft->ul, aircraft->br), aircraft, other))
        return 0;
    return 1;
}

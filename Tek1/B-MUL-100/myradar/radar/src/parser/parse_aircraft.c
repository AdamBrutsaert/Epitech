/*
** EPITECH PROJECT, 2022
** parse_aircraft.c
** File description:
** parse_aircraft.c
*/

#include "parser.h"

#include <math.h>

static void init_transform(aircraft_t *aircraft, vec2f_t center,
    vec2f_t arrival)
{
    vec2f_t movement = vec2f_sub(arrival, center);
    float angle = 0.0f;

    if (movement.x != 0 || movement.y != 0) {
        angle = acosf(vec2f_dot((vec2f_t){0, -1}, movement)
            / vec2f_length(movement));
    }
    if (movement.x < 0)
        angle = -angle;
    aircraft_init_transform(aircraft, center, angle);
}

static void init_physics(aircraft_t *aircraft, vec2f_t arrival, float speed,
    float delay)
{
    vec2f_t velocity = vec2f_sub(arrival, aircraft->center);
    float distance = vec2f_length(velocity);

    velocity = vec2f_mul(vec2f_normalize(velocity), speed);
    aircraft_init_physics(aircraft, velocity, distance, delay);
}

static int8_t check_ranges(uint32_t *values)
{
    if (values[0] > 1920 || values[1] > 1080)
        return 84;
    if (values[2] > 1920 || values[3] > 1080)
        return 84;
    if (values[4] == 0)
        return 84;
    return 0;
}

int32_t parse_aircraft(char **words, uint64_t count, vector_t *aircrafts)
{
    aircraft_t aircraft;
    uint32_t values[6];

    if (count != 7)
        return 84;
    if (!is_u32(words[1]) || !is_u32(words[2]) || !is_u32(words[3]) ||
        !is_u32(words[4]) || !is_u32(words[5]) || !is_u32(words[6]))
        return 84;
    for (uint8_t i = 0; i < 6; i++)
        values[i] = str_to_u32(words[i + 1]);
    if (check_ranges(values) == 84)
        return 84;
    init_transform(&aircraft, (vec2f_t){values[0], values[1]},
        (vec2f_t){values[2], values[3]});
    init_physics(&aircraft, (vec2f_t){values[2], values[3]}, values[4],
        values[5]);
    vector_push(aircrafts, &aircraft);
    return 0;
}

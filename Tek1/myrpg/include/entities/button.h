/*
** EPITECH PROJECT, 2023
** button.h
** File description:
** button.h
*/

#pragma once

#include "engine.h"

#define BUTTON_PART_LENGTH 48
#define BUTTON_CALC_PARTS(width) ((width) / BUTTON_PART_LENGTH)

typedef void (*callback_t)(entity_t *, void *);

typedef struct button button_t;

typedef enum {
    BUTTON_SKIN_BROWN = 0
} button_skin_t;

/**
 * @brief Create a new button entity
 *
 * @param skin the button skin
 * @param parts the number of body parts to use (> 0)
 * @param font the font to use
 * @return entity_t* the entity
 */
entity_t *button_new(callback_t callback,
    button_skin_t skin,
    uint16_t parts,
    sfFont *font);

/**
 * @brief Set the button position
 *
 * @param entity the entity
 * @param x the x coordinate
 * @param y the y coordinate
 */
void button_set_position(entity_t *entity, float x, float y);

/**
 * @brief Check if the given position is inside the button
 * @param entity the entity
 * @param pos the position
*/
bool button_is_inside(entity_t *entity, sfVector2f pos);

/**
 * @brief Set the button text label value
 *
 * @param entity the entity
 * @param string the string
*/
void button_set_string(entity_t *entity, char *string);

void button_hcenter(entity_t *entity);

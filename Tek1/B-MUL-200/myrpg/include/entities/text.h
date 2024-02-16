/*
** EPITECH PROJECT, 2023
** text.h
** File description:
** text.h
*/

#pragma once

#include "engine.h"

#define TEXT_CENTER 0x1

typedef struct text text_t;

/**
 * @brief Create a new text entity
 *
 * @return entity_t* the entity
 */
entity_t *text_new(sfFont *font);

/**
 * @brief Set the text value
 *
 * @param entity the entity
 * @param string the value
 */
void text_set_string(entity_t *entity, char *string);

/**
 * @brief Set the text color
 *
 * @param entity the entity
 * @param color the color
 */
void text_set_color(entity_t *entity, sfColor color);

/**
 * @brief Set the text size
 *
 * @param entity the entity
 * @param size the size
*/
void text_set_size(entity_t *entity, uint16_t size);

/**
 * @brief Set the text position
 *
 * @param entity the entity
 * @param position the position. If the x or y is set to TEXT_CENTER,
 * the text will be centered on the provided axis.
*/
void text_set_position(entity_t *entity, sfVector2f position);

/**
 * @brief Set the text, color and size of the text
 *
 * @param entity the entity
 * @param text the text
 * @param color the color
 * @param size the size
*/
void text_set(entity_t *entity, char *text, sfColor color, uint16_t size);

/**
 * @brief Center the entity on the x axis
 *
 * @param entity the entity
*/
void text_pos_hcenter(entity_t *entity);

/**
 * @brief Center the entity on the y axis
 *
 * @param entity the entity
*/
void text_pos_vcenter(entity_t *entity);

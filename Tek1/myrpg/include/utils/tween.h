/*
** EPITECH PROJECT, 2023
** tween.h
** File description:
** tween.h
*/

#pragma once

#include <stdbool.h>

typedef struct tween tween_t;

/**
 * @brief Allocate a new tween
 *
 * @param start the start value
 * @param end the end value
 * @param speed the speed
 * @param repeat whether it should repeat
 * @return tween_t* the new tween
 */
tween_t *tween_new(float start, float end, float speed, bool repeat);

/**
 * @brief Free the tween
 *
 * @param tween the tween to free
 */
void tween_delete(tween_t *tween);

/**
 * @brief Update the tween
 *
 * @param tween the tween to update
 * @param dt the delta time
 * @return float the new value
 */
float tween_update(tween_t *tween, float dt);

/**
 * @brief Set bounds of the tween
 *
 * @param tween the tween
 * @param start the start value
 * @param end the end value
 */
void tween_set_bounds(tween_t *tween, float start, float end);

/**
 * @brief Set whether the tween should repeat or not
 *
 * @param tween the tween
 * @param repeat whether the tween should repeat or not
 */
void tween_set_repeat(tween_t *tween, bool repeat);

/**
 * @brief Set the speed of the tween
 *
 * @param tween the tween
 * @param speed the speed
 */
void tween_set_speed(tween_t *tween, float speed);

/**
 * @brief Reset the tween
 *
 * @param tween the tween
 */
void tween_reset(tween_t *tween);

bool tween_is_over(tween_t *tween);

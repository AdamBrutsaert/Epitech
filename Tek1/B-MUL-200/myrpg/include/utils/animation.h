/*
** EPITECH PROJECT, 2023
** animation.h
** File description:
** animation.h
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct animation animation_t;

/**
 * @brief Allocate a new animation
 *
 * @return animation_t* the animation
 */
animation_t *animation_new(void);

/**
 * @brief Free an animation
 *
 * @param animation the animation to free
 */
void animation_delete(animation_t *animation);

/**
 * @brief Add a frame to an animation
 *
 * @param animation the animation
 * @param rect the rect of the frame
 * @return true if the frame was added
 * @return false if the frame was not added
 */
bool animation_add_frame(animation_t *animation, sfIntRect rect);

/**
 * @brief Set the speed of the animation
 *
 * @param animation the animation
 * @param speed the speed
 */
void animation_set_speed(animation_t *animation, float speed);

/**
 * @brief Set whether the animation should repeat or not
 *
 * @param animation the animation
 * @param repeat whether the animation should repeat or not
 */
void animation_set_repeat(animation_t *animation, bool repeat);

/**
 * @brief Reset the animation
 *
 * @param animation the animation
 */
void animation_reset(animation_t *animation);

/**
 * @brief Update the animation
 *
 * @param animation the animation
 * @param dt the delta time
 * @return sfIntRect* the rect of the current frame
 */
sfIntRect *animation_update(animation_t *animation, float dt);

bool animation_is_over(animation_t *animation);

/*
** EPITECH PROJECT, 2023
** queue.h
** File description:
** queue.h
*/

#pragma once

#include "room.h"

typedef struct queue queue_t;

/**
 * @brief Allocate a new queue
 *
 * @return queue_t* the queue
 */
queue_t *queue_new(void);

/**
 * @brief Free a queue
 *
 * @param queue the queue
 */
void queue_delete(queue_t *queue);

/**
 * @brief Get the length of the queue
 *
 * @param queue the queue
 * @return size_t the length
 */
size_t queue_get_length(queue_t *queue);

/**
 * @brief Pop the first element of the queue
 *
 * @param queue the queue
 * @return room_t* the first element
 */
room_t *queue_pop(queue_t *queue);

/**
 * @brief Push an element at the end of the queue
 *
 * @param queue the queue
 * @param room the room
 * @return true if the element was pushed
 * @return false if the element was not pushed
 */
bool queue_push(queue_t *queue, room_t *room);

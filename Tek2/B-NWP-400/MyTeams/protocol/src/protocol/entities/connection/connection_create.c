/*
** EPITECH PROJECT, 2024
** connection_create.c
** File description:
** connection_create.c
*/

#include "protocol/entities/connection.h"

#include "my/memory/allocation.h"

connection_t *connection_create(stream_t *stream, user_t *user)
{
    connection_t *connection = allocate(sizeof(connection_t));

    connection->stream = stream;
    connection->user = user;
    return connection;
}

/*
** EPITECH PROJECT, 2024
** stream_update.c
** File description:
** stream_update.c
*/

#include "protocol/stream.h"

static bool stream_has_packet_in_buffer(stream_t *self)
{
    uint32_t length;

    if (VEC_LEN(self->read_buffer) < 4)
        return false;
    length = ntohl(*(uint32_t *)VEC_AT(self->read_buffer, 0));
    return VEC_LEN(self->read_buffer) >= length + 4;
}

static bool stream_try_convert_to_packet(stream_t *self)
{
    uint32_t length = ntohl(*(uint32_t *)VEC_AT(self->read_buffer, 0));
    packet_t *packet = packet_create_from_buffer(
        VEC_AT(self->read_buffer, 4),
        length
    );

    vec_push_back(self->packets, &packet);
    vec_pop_some_front(self->read_buffer, length + 4);
    return true;
}

static bool stream_read_some(stream_t *self)
{
    char data[1024];
    ssize_t bytes = socket_read(self->socket, data, 1024);

    if (bytes <= 0)
        return false;
    vec_push_back_some(self->read_buffer, data, bytes);
    while (stream_has_packet_in_buffer(self)) {
        if (!stream_try_convert_to_packet(self))
            return false;
    }
    return true;
}

static bool stream_write_some(stream_t *self)
{
    ssize_t bytes = socket_write(
        self->socket,
        VEC_DATA(self->write_buffer),
        VEC_LEN(self->write_buffer)
    );

    if (bytes <= 0)
        return false;
    vec_pop_some_front(self->write_buffer, bytes);
    return true;
}

bool stream_update(stream_t *self, selector_t *selector)
{
    if (selector_can_read(selector, self->socket) && !stream_read_some(self))
        return false;
    if (selector_can_write(selector, self->socket) && !stream_write_some(self))
        return false;
    return true;
}

/*
** EPITECH PROJECT, 2024
** tcp_stream_read.c
** File description:
** tcp_stream_read.c
*/

#include "network/tcp_stream.h"

#include <unistd.h>

ssize_t tcp_stream_read(tcp_stream_t *self, void *buffer, size_t size)
{
    return read(*self, buffer, size);
}

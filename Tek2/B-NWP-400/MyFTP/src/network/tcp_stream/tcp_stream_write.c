/*
** EPITECH PROJECT, 2024
** tcp_stream_write.c
** File description:
** tcp_stream_write.c
*/

#include "network/tcp_stream.h"

#include <unistd.h>

ssize_t tcp_stream_write(tcp_stream_t *self, const void *buffer, size_t size)
{
    return write(*self, buffer, size);
}

/*
** EPITECH PROJECT, 2024
** packet_push_message_vec.c
** File description:
** packet_push_message_vec.c
*/

#include "protocol/entities/message.h"

void packet_push_message_vec(packet_t *self, const vec_t *messages)
{
    for (size_t i = 0; i < VEC_LEN(messages); i++)
        packet_push_message(self, *(message_t **)VEC_AT(messages, i));
    packet_push_u64(self, VEC_LEN(messages));
}

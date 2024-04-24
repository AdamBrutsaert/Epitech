/*
** EPITECH PROJECT, 2024
** state_get_messages_between.c
** File description:
** state_get_messages_between.c
*/

#include "state.h"

vec_t *state_get_messages_between(state_t *self, user_t *user1, user_t *user2)
{
    vec_t *messages = vec_create(sizeof(message_t *));
    message_t *message;

    for (size_t i = 0; i < VEC_LEN(self->messages); i++) {
        message = *(message_t **)VEC_AT(self->messages, i);
        if (!string_compare(message->from_uuid, user1->uuid)
            && !string_compare(message->to_uuid, user2->uuid)) {
            vec_push_back(messages, &message);
            continue;
        }
        if (!string_compare(message->from_uuid, user2->uuid)
            && !string_compare(message->to_uuid, user1->uuid))
            vec_push_back(messages, &message);
    }
    return messages;
}

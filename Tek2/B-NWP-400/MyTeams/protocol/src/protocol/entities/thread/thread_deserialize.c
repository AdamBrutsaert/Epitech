/*
** EPITECH PROJECT, 2024
** thread_deserialize.c
** File description:
** thread_deserialize.c
*/

#include "protocol/entities/thread.h"

#include "my/memory/cstr.h"

thread_t *thread_deserialize(const string_t *data)
{
    vec_t *parts = string_split_escaped(data, ',');
    thread_t *thread;
    uint64_t ts;

    if (VEC_LEN(parts) != 6
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 0)))
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 1)))
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 2)))
        || !cstr_to_u64(STRING_CDATA(*(string_t **)VEC_AT(parts, 3)), &ts)) {
        string_destroy_vec(parts);
        return nullptr;
    }
    thread = thread_load(
        *(string_t **)VEC_AT(parts, 0),
        &(thread_create_args_t){*(string_t **)VEC_AT(parts, 1),
            *(string_t **)VEC_AT(parts, 2), ts, *(string_t **)VEC_AT(parts, 4),
            *(string_t **)VEC_AT(parts, 5)}
    );
    string_destroy_vec(parts);
    return thread;
}

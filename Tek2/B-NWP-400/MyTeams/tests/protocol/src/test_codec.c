/*
** EPITECH PROJECT, 2024
** test_protocol.c
** File description:
** test_protocol.c
*/

#include "protocol/codec.h"
#include "my/memory/allocation.h"

#include <criterion/criterion.h>

// Test(server, user_logged_in)
// {
//     cl_user_logged_in_packet_t *packet = allocate(sizeof(cl_user_logged_in_packet_t));
//     packet_t *raw = packet_create();

//     // Initializes the packet
//     packet->type = PACKET_TYPE_CL_USER_LOGGED_IN;
//     packet->name = string_create_from_cstr("adam");

//     // Encoding
//     cr_assert(packet_encode_protocol(raw, (protocol_packet_t *)packet));

//     // Destroys the packet
//     protocol_packet_destroy((protocol_packet_t *)packet);
//     packet = nullptr;

//     // Decoding
//     cr_assert(packet_decode_protocol(raw, (protocol_packet_t **)&packet));

//     // Checks
//     cr_assert_eq(packet->type, PACKET_TYPE_CL_USER_LOGGED_IN);
//     cr_assert_str_eq(STRING_DATA(packet->name), "adam");

//     // Destroys the packets
//     protocol_packet_destroy((protocol_packet_t *)packet);
//     packet_destroy(raw);
// }

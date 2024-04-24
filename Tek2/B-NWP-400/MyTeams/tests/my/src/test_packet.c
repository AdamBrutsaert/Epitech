/*
** EPITECH PROJECT, 2024
** test_packet.c
** File description:
** test_packet.c
*/

#include "my/network/packet.h"

#include <criterion/criterion.h>

Test(packet, one)
{
    packet_t *packet = packet_create();
    string_t *string = string_create_from_cstr("Hello, world!");

    packet_push_u8(packet, 43);
    packet_push_u16(packet, 1337);
    packet_push_u8(packet, 32);
    packet_push_u32(packet, 2147000);
    packet_push_string(packet, string);
    packet_push_u16(packet, 7898);
    packet_push_u32(packet, 16730000);

    cr_assert_eq(PACKET_LEN(packet), 35);

    uint8_t u8;
    uint16_t u16;
    uint32_t u32;

    cr_assert(packet_pop_u32(packet, &u32));
    cr_assert_eq(u32, 16730000);
    cr_assert_eq(PACKET_LEN(packet), 31);

    cr_assert(packet_pop_u16(packet, &u16));
    cr_assert_eq(u16, 7898);
    cr_assert_eq(PACKET_LEN(packet), 29);

    string_destroy(string);
    string = nullptr;
    cr_assert(packet_pop_string(packet, &string));
    cr_assert_str_eq(STRING_CDATA(string), "Hello, world!");
    cr_assert_eq(PACKET_LEN(packet), 8);

    cr_assert(packet_pop_u32(packet, &u32));
    cr_assert_eq(u32, 2147000);
    cr_assert_eq(PACKET_LEN(packet), 4);

    cr_assert(packet_pop_u8(packet, &u8));
    cr_assert_eq(u8, 32);
    cr_assert_eq(PACKET_LEN(packet), 3);

    cr_assert(packet_pop_u16(packet, &u16));
    cr_assert_eq(u16, 1337);
    cr_assert_eq(PACKET_LEN(packet), 1);

    cr_assert(packet_pop_u8(packet, &u8));
    cr_assert_eq(u8, 43);
    cr_assert_eq(PACKET_LEN(packet), 0);

    string_destroy(string);
    packet_destroy(packet);
}

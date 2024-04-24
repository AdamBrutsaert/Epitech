/*
** EPITECH PROJECT, 2024
** packet.h
** File description:
** packet.h
*/

#pragma once

#include "my/memory/string.h"

/*********************************** Types ***********************************/

/// Represents a packet
typedef vec_t packet_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a packet
packet_t *packet_create(void);

/// Creates a packet from a buffer
packet_t *packet_create_from_buffer(const void *buffer, size_t size);

/// Destroys a packet
void packet_destroy(packet_t *self);

/*****************************************************************************/

/********************************** Getters **********************************/

#define PACKET_DATA(self) VEC_DATA(self)
#define PACKET_CDATA(self) VEC_CDATA(self)
#define PACKET_LEN(self) VEC_LEN(self)

/*****************************************************************************/

/*********************************** Push ************************************/

/// Pushes an u8 to a packet
void packet_push_u8(packet_t *self, uint8_t value);

/// Pushes an u16 to a packet
void packet_push_u16(packet_t *self, uint16_t value);

/// Pushes an u32 to a packet
void packet_push_u32(packet_t *self, uint32_t value);

/// Pushes an u64 to a packet
void packet_push_u64(packet_t *self, uint64_t value);

/// Pushes a string to a packet
void packet_push_string(packet_t *self, const string_t *string);

/*****************************************************************************/

/************************************ Pop ************************************/

/// Pops an u8 from a packet
bool packet_pop_u8(packet_t *self, uint8_t *value);

/// Pops an u16 from a packet
bool packet_pop_u16(packet_t *self, uint16_t *value);

/// Pops an u32 from a packet
bool packet_pop_u32(packet_t *self, uint32_t *value);

/// Pops an u64 from a packet
bool packet_pop_u64(packet_t *self, uint64_t *value);

/// Pops a string from a packet
bool packet_pop_string(packet_t *self, string_t **string);

/*****************************************************************************/

/*
** EPITECH PROJECT, 2024
** cstr.h
** File description:
** cstr.h
*/

#pragma once

#include <stdint.h>

/********************************** CSTR To **********************************/

/// Converts a cstr to an IPv4 address
bool cstr_to_ipv4_addr(const char *cstr, uint32_t *addr);

/// Converts a cstr to an uint64_t
bool cstr_to_u64(const char *cstr, uint64_t *value);

/// Converts a cstr to an uint32_t
bool cstr_to_u32(const char *cstr, uint32_t *value);

/// Converts a cstr to an uint16_t
bool cstr_to_u16(const char *cstr, uint16_t *value);

/// Converts a cstr to an uint8_t
bool cstr_to_u8(const char *cstr, uint8_t *value);

/*****************************************************************************/

/******************************** CSTR Is ************************************/

/// Checks if a cstr is an unsigned number
bool cstr_is_unsigned(const char *cstr);

/// Checks if a cstr is a valid UUID
bool cstr_is_uuid(const char *cstr);

/*****************************************************************************/

/***************************** Miscellaneous *********************************/

/// Checks if a cstr null-terminated array contains a '-help'
bool cstr_array_contains_help(char **array);

/*****************************************************************************/

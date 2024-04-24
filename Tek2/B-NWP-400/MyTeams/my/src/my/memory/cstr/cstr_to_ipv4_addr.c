/*
** EPITECH PROJECT, 2024
** cstr_to_ipv4_addr.c
** File description:
** cstr_to_ipv4_addr.c
*/

#include "my/memory/cstr.h"

#include <arpa/inet.h>

bool cstr_to_ipv4_addr(const char *cstr, uint32_t *addr)
{
    uint32_t value = inet_addr(cstr);

    if (value == INADDR_NONE)
        return false;
    *addr = ntohl(value);
    return true;
}

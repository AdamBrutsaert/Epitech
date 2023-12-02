/*
** EPITECH PROJECT, 2022
** cipher.h
** File description:
** cipher.h
*/

#pragma once

#include "matrix.h"

typedef enum {
    ENCRYPT,
    DECRYPT,
} flag_t;

typedef struct {
    matrix_t *message;
    matrix_t *key;
    flag_t flag;
} cipher_t;

int32_t cipher(int argc, char **argv);
int32_t cipher_help(char *program);

void cipher_encrypt(cipher_t *cipher);
void cipher_decrypt(cipher_t *cipher);

int32_t cipher_parse_arguments(cipher_t *cipher, int argc, char **argv);
void cipher_parse_message(cipher_t *cipher, char const *message);
int32_t cipher_parse_encrypted_message(cipher_t *cipher, char const *message);
int32_t cipher_parse_key(cipher_t *cipher, char const *key);
int32_t cipher_parse_flag(cipher_t *cipher, char const *flag);

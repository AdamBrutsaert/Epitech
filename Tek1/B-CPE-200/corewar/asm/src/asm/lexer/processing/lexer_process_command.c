/*
** EPITECH PROJECT, 2023
** lexer_process_command.c
** File description:
** lexer_process_command.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

static bool process_command(
    lexer_t *lexer,
    reader_t *reader,
    char *command
)
{
    size_t length = my_strlen(command);
    string_t *str = string_new(lexer->arena);

    for (size_t i = 0; i < length; i++)
        str = string_append_char(lexer->scratch, str, reader_next(reader, 1));
    if (!lexer_is_valid_end_character(reader_peek(reader, 0))) {
        lexer_error_character(lexer, reader, reader_peek(reader, 0));
        return false;
    }
    lexer_push_token(lexer, reader, TOKEN_COMMAND, str);
    return true;
}

bool lexer_process_command(lexer_t *lexer, reader_t *reader)
{
    if (reader_match(reader, NAME_CMD_STRING))
        return process_command(lexer, reader, NAME_CMD_STRING);
    if (reader_match(reader, COMMENT_CMD_STRING))
        return process_command(lexer, reader, COMMENT_CMD_STRING);
    return false;
}

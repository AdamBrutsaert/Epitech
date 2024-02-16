/*
** EPITECH PROJECT, 2023
** compiler_process_header.c
** File description:
** compiler_process_header.c
*/

#include "asm/compiler_impl.h"
#include "my/memory.h"

static char *remove_quotes(char *string)
{
    size_t length = my_strlen(string);

    if (length >= 2) {
        my_memmove(string, string + 1, length - 2);
        string[length - 2] = '\0';
        string[length - 1] = '\0';
    }
    return string;
}

static bool check_end_of_line(compiler_t *compiler, lexer_t *lexer)
{
    if (lexer_is_end_of_line(lexer))
        return true;
    compiler_error_token(compiler, lexer_peek(lexer, 0));
    return false;
}

static char *compiler_process_command(
    compiler_t *compiler,
    lexer_t *lexer,
    const char *command
)
{
    token_t *token = lexer_peek(lexer, 0);

    lexer_skip_newlines(lexer);
    if (lexer_peek_type(lexer, 0) != TOKEN_COMMAND) {
        compiler_error_token(compiler, lexer_peek(lexer, 0));
        return NULL;
    }
    if (my_strcmp(string_to_cstr(compiler->scratch,
            lexer_next_value(lexer)), command)) {
        compiler_error_command(compiler, token);
        return NULL;
    }
    if (lexer_peek_type(lexer, 0) != TOKEN_STRING) {
        compiler_error_token(compiler, lexer_peek(lexer, 0));
        return NULL;
    }
    token = lexer_next(lexer);
    if (!check_end_of_line(compiler, lexer))
        return NULL;
    return remove_quotes(string_to_cstr(compiler->scratch, token->value));
}

static bool check_length(compiler_t *compiler, lexer_t *lexer,
    char *command, size_t length)
{
    if (my_strlen(command) > length) {
        compiler_error(compiler, lexer_peek(lexer, 0), "command too long");
        return false;
    }
    return true;
}

bool compiler_process_header(compiler_t *compiler, lexer_t *lexer)
{
    char *name = compiler_process_command(compiler, lexer, NAME_CMD_STRING);
    char *comment;

    compiler->header.magic = COREWAR_EXEC_MAGIC;
    compiler->header.prog_size = 0;
    if (name == NULL)
        return false;
    comment = compiler_process_command(compiler, lexer, COMMENT_CMD_STRING);
    if (!check_length(compiler, lexer, name, PROG_NAME_LENGTH)
        || (comment && !check_length(compiler, lexer, comment, COMMENT_LENGTH)))
        return false;
    my_strncpy(compiler->header.prog_name, name, PROG_NAME_LENGTH);
    compiler->header.prog_name[PROG_NAME_LENGTH] = '\0';
    if (comment != NULL) {
        my_strncpy(compiler->header.comment, comment, COMMENT_LENGTH);
        compiler->header.comment[COMMENT_LENGTH] = '\0';
    } else {
        my_memset(compiler->header.comment, 0, COMMENT_LENGTH + 1);
    }
    return true;
}

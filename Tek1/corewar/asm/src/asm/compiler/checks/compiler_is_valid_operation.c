/*
** EPITECH PROJECT, 2023
** compiler_is_valid_operation.c
** File description:
** compiler_is_valid_operation.c
*/

#include "asm/compiler_impl.h"

static int8_t get_arg_type(token_t *token)
{
    token_type_t type;

    if (token == NULL)
        return 0;
    type = token->type;
    if (type == TOKEN_REGISTER)
        return T_REG;
    if (type == TOKEN_DIRECT_VALUE || type == TOKEN_DIRECT_LABEL)
        return T_DIR;
    if (type == TOKEN_INDIRECT_VALUE || type == TOKEN_INDIRECT_LABEL)
        return T_IND;
    return 0;
}

static bool check_types(compiler_t *compiler, operation_t *operation,
    op_t *op)
{
    for (int8_t i = 0; i < op->nbr_args; i++) {
        if (!(get_arg_type(operation->args[i]) & op->type[i])) {
            compiler_error(compiler, operation->args[i],
                "invalid argument type");
            return false;
        }
    }
    return true;
}

bool compiler_is_valid_operation(compiler_t *compiler, operation_t *operation)
{
    op_t *op = NULL;
    char *mnemonic = string_to_cstr(compiler->scratch,
        operation->instruction->value);

    for (size_t i = 0; op_tab[i].mnemonique; i++) {
        if (!my_strcmp(op_tab[i].mnemonique, mnemonic)) {
            op = &op_tab[i];
            break;
        }
    }
    if (op == NULL)
        return false;
    if (op->nbr_args != operation->args_count) {
        compiler_error(compiler, operation->instruction,
            "invalid number of arguments");
        return false;
    }
    return check_types(compiler, operation, op);
}

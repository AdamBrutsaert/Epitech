##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := asm
SRC := 	src/asm/asm_delete.c \
		src/asm/asm_from_args.c \
		src/asm/asm_help.c \
		src/asm/asm_new.c \
		src/asm/asm_process.c \
		src/asm/compiler/checks/compiler_is_valid_operation.c \
		src/asm/compiler/compiler_delete.c \
		src/asm/compiler/compiler_get_operation_size.c \
		src/asm/compiler/compiler_get_output_path.c \
		src/asm/compiler/compiler_new.c \
		src/asm/compiler/errors/compiler_error.c \
		src/asm/compiler/errors/compiler_error_command.c \
		src/asm/compiler/errors/compiler_error_token.c \
		src/asm/compiler/processing/compiler_process.c \
		src/asm/compiler/processing/compiler_process_arguments.c \
		src/asm/compiler/processing/compiler_process_header.c \
		src/asm/compiler/processing/compiler_process_instruction.c \
		src/asm/compiler/processing/compiler_process_label.c \
		src/asm/compiler/processing/compiler_process_operation.c \
		src/asm/compiler/writing/compiler_write.c \
		src/asm/compiler/writing/compiler_write_arguments.c \
		src/asm/compiler/writing/compiler_write_direct_label.c \
		src/asm/compiler/writing/compiler_write_direct_value.c \
		src/asm/compiler/writing/compiler_write_header.c \
		src/asm/compiler/writing/compiler_write_indirect_label.c \
		src/asm/compiler/writing/compiler_write_indirect_value.c \
		src/asm/compiler/writing/compiler_write_instruction.c \
		src/asm/compiler/writing/compiler_write_operations.c \
		src/asm/compiler/writing/compiler_write_register.c \
		src/asm/compiler/writing/compiler_write_types.c \
		src/asm/conversion/intmax_to_big_endian.c \
		src/asm/conversion/int_to_big_endian.c \
		src/asm/conversion/is_big_endian.c \
		src/asm/conversion/swap_endianness.c \
		src/asm/lexer/checks/lexer_is_command.c \
		src/asm/lexer/checks/lexer_is_indirect_value.c \
		src/asm/lexer/checks/lexer_is_instruction.c \
		src/asm/lexer/checks/lexer_is_register.c \
		src/asm/lexer/checks/lexer_is_valid_end_character.c \
		src/asm/lexer/errors/lexer_error.c \
		src/asm/lexer/errors/lexer_error_character.c \
		src/asm/lexer/errors/lexer_error_token.c \
		src/asm/lexer/lexer_clear.c \
		src/asm/lexer/lexer_create_breakpoint.c \
		src/asm/lexer/lexer_debug.c \
		src/asm/lexer/lexer_delete.c \
		src/asm/lexer/lexer_is_end_of_line.c \
		src/asm/lexer/lexer_new.c \
		src/asm/lexer/lexer_next.c \
		src/asm/lexer/lexer_next_value.c \
		src/asm/lexer/lexer_peek.c \
		src/asm/lexer/lexer_peek_type.c \
		src/asm/lexer/lexer_push_token.c \
		src/asm/lexer/lexer_restore_breakpoint.c \
		src/asm/lexer/lexer_skip_newlines.c \
		src/asm/lexer/processing/lexer_process.c \
		src/asm/lexer/processing/lexer_process_character.c \
		src/asm/lexer/processing/lexer_process_command.c \
		src/asm/lexer/processing/lexer_process_comment.c \
		src/asm/lexer/processing/lexer_process_default.c \
		src/asm/lexer/processing/lexer_process_direct.c \
		src/asm/lexer/processing/lexer_process_direct_label.c \
		src/asm/lexer/processing/lexer_process_direct_value.c \
		src/asm/lexer/processing/lexer_process_indirect_label.c \
		src/asm/lexer/processing/lexer_process_indirect_value.c \
		src/asm/lexer/processing/lexer_process_instruction.c \
		src/asm/lexer/processing/lexer_process_label.c \
		src/asm/lexer/processing/lexer_process_newline.c \
		src/asm/lexer/processing/lexer_process_register.c \
		src/asm/lexer/processing/lexer_process_separator.c \
		src/asm/lexer/processing/lexer_process_string.c \
		src/asm/lexer/processing/lexer_process_whitespace.c \
		src/asm/map/map_delete.c \
		src/asm/map/map_find_node.c \
		src/asm/map/map_get.c \
		src/asm/map/map_new.c \
		src/asm/map/map_set.c \
		src/asm/op.c \
		src/asm/reader/reader_clear.c \
		src/asm/reader/reader_delete.c \
		src/asm/reader/reader_error_open.c \
		src/asm/reader/reader_error_read.c \
		src/asm/reader/reader_get_line_number.c \
		src/asm/reader/reader_match.c \
		src/asm/reader/reader_new.c \
		src/asm/reader/reader_next.c \
		src/asm/reader/reader_peek.c \
		src/asm/reader/reader_push_file.c \
		src/asm/reader/reader_skip_line.c \
		src/main.c \
		src/my/arena/arena_calloc.c \
		src/my/arena/arena_clear.c \
		src/my/arena/arena_delete.c \
		src/my/arena/arena_malloc.c \
		src/my/arena/arena_new.c \
		src/my/arena/region_new.c \
		src/my/memory/my_calloc.c \
		src/my/memory/my_free.c \
		src/my/memory/my_malloc.c \
		src/my/memory/my_memcpy.c \
		src/my/memory/my_memmove.c \
		src/my/memory/my_memset.c \
		src/my/memory/my_realloc.c \
		src/my/stdio/my_eputc.c \
		src/my/stdio/my_eputcs.c \
		src/my/stdio/my_eputs.c \
		src/my/stdio/my_eputu.c \
		src/my/stdio/my_putc.c \
		src/my/stdio/my_putcs.c \
		src/my/stdio/my_puts.c \
		src/my/stdio/my_putu.c \
		src/my/string/my_strcmp.c \
		src/my/string/my_strcontains.c \
		src/my/string/my_strhash.c \
		src/my/string/my_strlen.c \
		src/my/string/my_strncmp.c \
		src/my/string/my_strncpy.c \
		src/my/string/string_append.c \
		src/my/string/string_append_char.c \
		src/my/string/string_concat.c \
		src/my/string/string_duplicate.c \
		src/my/string/string_equal.c \
		src/my/string/string_from.c \
		src/my/string/string_from_char.c \
		src/my/string/string_get.c \
		src/my/string/string_get_length.c \
		src/my/string/string_get_raw.c \
		src/my/string/string_new.c \
		src/my/string/string_slice.c \
		src/my/string/string_to_cstr.c \
		src/my/string/string_to_int.c \
		src/my/vector/vec_clear.c \
		src/my/vector/vec_delete.c \
		src/my/vector/vec_get.c \
		src/my/vector/vec_get_data.c \
		src/my/vector/vec_get_length.c \
		src/my/vector/vec_new.c \
		src/my/vector/vec_pop.c \
		src/my/vector/vec_push.c \
		src/my/vector/vec_set.c \
		src/my/vector/vec_set_deleter.c
OBJ := $(SRC:src/%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS := -std=c99 -Wall -Wextra -g

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)
	@rm -f ../bonus/discord_app_converter/src/assets/$(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@cp $(NAME) ../bonus/discord_app_converter/src/assets/

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

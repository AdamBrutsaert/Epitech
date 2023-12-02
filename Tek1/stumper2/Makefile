##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := gameoflife
SRC := src/gol/gol_check_map.c \
       src/gol/gol_create.c \
       src/gol/gol_print.c \
       src/gol/gol_destroy.c \
       src/gol/gol_run.c \
       src/main.c \
       src/my/memory/my_memset.c \
       src/my/memory/my_memmove.c \
       src/my/memory/my_memcpy.c \
       src/my/memory/my_free.c \
       src/my/memory/my_malloc.c \
       src/my/memory/my_calloc.c \
       src/my/memory/my_realloc.c \
       src/my/stdio/my_putc.c \
       src/my/stdio/my_eputc.c \
       src/my/stdio/my_readfd.c \
       src/my/stdio/my_readfile.c \
       src/my/stdio/my_eputs.c \
       src/my/stdio/my_puts.c \
       src/my/string/my_strcpy.c \
       src/my/string/my_strncpy.c \
       src/my/string/my_strncmp.c \
       src/my/string/my_strlen.c \
       src/my/string/my_strcat.c \
       src/my/string/my_strdup.c \
       src/my/string/my_strcmp.c \
       src/my/string/my_strndup.c
OBJ := $(SRC:src/%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS := -Wall -Wextra

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

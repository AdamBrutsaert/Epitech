##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := head
SRC := src/basic_functions.c \
    src/main.c \
    src/my/string.c \
    src/my/stdio.c \
    src/my/conversion.c \
    src/head/parse_long.c \
    src/head/parse_short.c \
    src/head/parse.c \
    src/head/head.c \
    src/head/process.c \
    src/head/parse_arg.c
OBJ := $(SRC:src/%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS := -Wall -Wextra -g

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@gcc -o $@ $^

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

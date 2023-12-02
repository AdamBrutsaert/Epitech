##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := corewar
SRC := src/main.c
OBJ := $(SRC:src/%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS := -std=c99 -Wall -Wextra -g

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

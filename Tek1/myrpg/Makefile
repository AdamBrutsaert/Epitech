##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := my_rpg
SRC := $(shell find src -type f -name "*.c")
OBJ := $(SRC:src/%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS := -Wall -Wextra -Wno-unused-parameter

LDLIBS := -lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

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
	@gcc -o $@ -c $< $(CPPFLAGS) $(CFLAGS) -g

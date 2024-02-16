##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := navy
SRC := $(shell find src -type f -name "*.c")
OBJ := $(SRC:%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS := -W -Wall -Wextra -Wpedantic

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

love:
	@bear --append -- $(MAKE) -s

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME := myftp
SRC  := $(shell find src -name "*.c")
OBJ  := $(SRC:src/%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS   := -Wall -Wextra -Werror -g
LDFLAGS  :=
LDLIBS   :=

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@gcc $^ -o $@ $(LDFLAGS) $(LDLIBS)

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

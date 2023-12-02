##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := giantman
SRC := $(shell find src/ -type f -name "*.c")
OBJ := $(SRC:%.c=build/%.o)

CFLAGS := -Wall -Wextra -Wpedantic
CPPFLAGS := -Iinclude

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(CFLAGS) $(CPPFLAGS)

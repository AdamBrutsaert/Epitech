##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := 107transfer
SRC := $(shell find src -type f -name "*.cpp")
OBJ := $(SRC:%.c=build/%.o)

CFLAGS := -Wall -Wextra -g

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ)
	@g++ -o $@ $^

build/%.o: %.c
	@mkdir -p $(dir $@)
	@g++ -o $@ -c $<

##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := sort_words
SRC := src/main.c src/string.c src/split.c src/split2.c src/sort.c
SRC += src/stdio.c
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
	@gcc -o $(NAME) $(OBJ)

build/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re

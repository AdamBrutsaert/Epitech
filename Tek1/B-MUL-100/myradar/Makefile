##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME := my_radar
SRC := $(shell find . -type f -name "*.c")
OBJ := $(SRC:%.c=build/%.o)

CFLAGS := -Wall -Wextra -Wpedantic
CPPFLAGS := -Iradar/include -Imy/math/include -Imy/memory/include
CPPFLAGS += -Imy/stdio/include -Imy/string/include -Imy/vector/include

LDLIBS := -lm -lcsfml-graphics -lcsfml-window -lcsfml-system

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f my_radar

re: fclean all

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDLIBS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re

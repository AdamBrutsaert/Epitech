##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := mysh
SRC := $(shell find src -type f -name "*.c")
OBJ := $(SRC:%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS := -Wall -Wextra

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

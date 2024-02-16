##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for Final Stumper
##

NAME := rush3
SRC  := main.c rush3.c my_memmove.c my_realloc.c parser.c detector.c
SRC  += my_put_nbr.c
OBJ  := $(SRC:.c=.o)

CPPFLAGS := -Iinclude
CFLAGS   := -std=c99 -W -Wall -Wextra -Wpedantic

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@..."
	@$(CC) -o $@ $(OBJ)

%.o: %.c
	@echo "Compiling $@..."
	@$(CC) -c -o$@ $^ $(CFLAGS) $(CPPFLAGS)

clean:
	@echo "Removing intermediates files..."
	@rm -f $(OBJ)

fclean: clean
	@echo "Removing binary..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME = z
SRC = z.c
OBJ = z.o

CFLAGS = --std=gnu17 -Wall -Wextra

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)

%.o: %.c
	@gcc -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC = ex01/mul_div.c \
      ex02/concat.c \
      ex03/array_1d_to_2d.c \
      ex04/print.c \
      ex05/sort.c ex05/disp.c ex05/uniq.c
SRC += $(shell find tests -name "*.c")
NAME = test

all:

clean:
	@rm -f *.gcda
	@rm -f *.gcno

fclean: clean
	@rm -f $(NAME)

re: fclean all

tests_run: fclean
	@gcc $(SRC) -o $(NAME) --coverage -g -lgcov -lcriterion
	@./$(NAME)

.PHONY: all clean fclean re tests_run

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME = pushswap_checker
SRC = app/Main.hs src/Checker.hs

all: $(NAME)

tests_run:
	@stack test --coverage --verbosity silent
	@mkdir -p test/coverage
	@stack hpc report --all --destdir test/coverage

clean:
	@rm -rf build
	@rm -rf test/coverage

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(SRC)
	@mkdir -p build
	@ghc -o $@ $(SRC) -odir build -hidir build

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME := MyGKrellm

all:
	@cmake -S . -B build
	@cmake --build build
	@cp build/$(NAME) .

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run

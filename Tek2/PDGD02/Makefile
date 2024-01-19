##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME = doop
SRC = $(shell find . -name "*.hs")
OBJ = $(SRC:%.hs=build/%.o)

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@ghc -o $@ $^

build/%.o: %.hs
	@mkdir -p build
	@ghc -c $< -o $@ -ohi $(@:%.o=%.hi)

##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := my_ptit_pain
SRC := $(shell find src -type f -name "*.c")
OBJ := $(SRC:%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS := -Wall -Wextra

all: $(NAME)

clean:
	@rm -rf build
	@rm -f *.gcno
	@rm -f *.gcda

fclean: clean
	@rm -f $(NAME)
	@rm -f test

re: fclean all

tests_run:
	@gcc -o test src/func.c tests/test_func.c -Iinclude -lcriterion -lgcov \
		--coverage -g
	@./test

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

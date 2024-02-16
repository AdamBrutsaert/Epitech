##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

TESTS_NAME = test

TESTS_SRC = $(shell find . -type f -name "*.c")
TESTS_OBJ = $(TESTS_SRC:%.c=build/%.o)

TESTS_CPPFLAGS = -Itests/include
TESTS_CFLAGS = -Wall -Wextra --coverage -g
TESTS_LDLIBS = -lgcov -lcriterion

all:

clean:
	@rm -rf build

fclean: clean
	@rm -f $(TESTS_NAME)

re: fclean all

tests: $(TESTS_NAME)

tests_run: tests
	@./$(TESTS_NAME)

.PHONY: all clean fclean re tests_run

$(TESTS_NAME): $(TESTS_OBJ)
	@gcc -o $@ $^ $(TESTS_LDFLAGS) $(TESTS_LDLIBS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(TESTS_CPPFLAGS) $(TESTS_CFLAGS)

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME := a.out
SRC := $(shell find . -maxdepth 1 -name "*.c" )
OBJ := $(SRC:%.c=build/release/%.o)
CFLAGS := -Wall -Wextra -std=gnu17 -Wno-unused-parameter

TESTS_NAME := unit_tests
TESTS_SRC := $(shell find . -name "*.c" -not -path "./bonus/*")
TESTS_OBJ := $(TESTS_SRC:%.c=build/tests/%.o)
TESTS_CFLAGS := -Wall -Wextra -std=gnu17 --coverage -Wno-unused-parameter
TESTS_LDLIBS := -lcriterion -lgcov

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re: fclean all

tests_run: $(TESTS_NAME)
	@./$(TESTS_NAME)

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(TESTS_NAME): $(TESTS_OBJ)
	@gcc -o $@ $^ $(TESTS_LDFLAGS) $(TESTS_LDLIBS)

build/release/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

build/tests/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(TESTS_CPPFLAGS) $(TESTS_CFLAGS)

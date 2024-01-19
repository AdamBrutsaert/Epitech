##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME = libstring.a
SRC = $(shell find . -maxdepth 1 -type f -name "*.c")
OBJ = $(SRC:%.c=build/release/%.o)
CFLAGS = -Wall -Wextra  -g

TESTS_NAME = libstring_tests
TESTS_SRC = $(shell find . -type f -name "*.c")
TESTS_OBJ = $(TESTS_SRC:%.c=build/tests/%.o)
TESTS_CFLAGS = -Wall -Wextra -g --coverage
TESTS_LDLIBS = -lgcov -lcriterion

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TESTS_NAME)

re: fclean all

tests: $(TESTS_NAME)

tests_run: tests
	@./$(TESTS_NAME)

.PHONY: all clean fclean re tests tests_run

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(TESTS_NAME): $(TESTS_OBJ)
	@gcc -o $@ $^ $(TESTS_LDFLAGS) $(TESTS_LDLIBS)

build/tests/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(TESTS_CPPFLAGS) $(TESTS_CFLAGS)

build/release/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

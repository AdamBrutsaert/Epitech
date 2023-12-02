##
## EPITECH PROJECT, 2022
## do_op Makefile
## File description:
## do_op Makefile
##

# Directories
INCLUDE_DIR             := ../include
LIB_DIR                 := ../lib

# Target
NAME := grep
SRC  := my_strlen.c my_putstr.c my_putstr_err.c my_strstr.c my_memmove.c
SRC  += reader.c reader2.c grep.c main.c
OBJ  := $(SRC:%.c=%.o)

# Tests
TEST_NAME := grep_test
TEST_SRC  := $(filter-out main.c,$(SRC)) ../tests/test_grep.c
TEST_OBJ  := $(TEST_SRC:%.c=%.o)

# Compiler
CFLAGS   += -std=c99 -W -Wall -Wextra -Wpedantic
CPPFLAGS += -I$(INCLUDE_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@..."
	@$(CC) -o$@ $^ $(LDFLAGS) $(LDLIBS)

tests_run: LDLIBS += -lcriterion -lgcov
tests_run: CFLAGS += --coverage -g
tests_run: $(TEST_NAME)
	@./$(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ)
	@echo "Linking $@..."
	@$(CC) -o$@ $^ $(LDFLAGS) $(LDLIBS)

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) -c $(CPPFLAGS) $(CFLAGS) -I$(INCLUDE_DIR) -o$@ $<

clean:
	@echo "Removing intermediates files..."
	@rm -f *.o
	@rm -f $(TEST_OBJ)

fclean: clean
	@echo "Removing executables..."
	@rm -f $(NAME)
	@rm -f $(TEST_NAME)
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f ../tests/*.gcda
	@rm -f ../tests/*.gcno

re: fclean all

.PHONY: all tests_run clean fclean re

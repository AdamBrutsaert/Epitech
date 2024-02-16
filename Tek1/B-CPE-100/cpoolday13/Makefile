##
## EPITECH PROJECT, 2022
## btree
## File description:
## btree Makefile
##

# Directories
INCLUDE_DIR             := ./include
BUILD_INTERMEDIATES_DIR := ./build-intermediates

# Target
NAME := libbtree.a
SRC  := btree_create_node.c btree_apply_prefix.c btree_apply_infix.c
SRC  += btree_apply_suffix.c btree_insert_data.c btree_search_item.c
SRC  += btree_level_count.c btree_apply_by_level.c
OBJ  := $(SRC:%.c=$(BUILD_INTERMEDIATES_DIR)/%.o)

# Tests
TESTS_NAME := test_libbtree
TESTS_SRC  := tests/tests_utils.c
TESTS_SRC  += tests/test_btree_create_node.c tests/test_btree_apply_prefix.c
TESTS_SRC  += tests/test_btree_apply_infix.c tests/test_btree_apply_suffix.c
TESTS_SRC  += tests/test_btree_insert_data.c tests/test_btree_search_item.c
TESTS_SRC  += tests/test_btree_level_count.c tests/test_btree_apply_by_level.c
TESTS_OBJ  := $(TESTS_SRC:%.c=$(BUILD_INTERMEDIATES_DIR)/%.o)

# Compiler
CFLAGS   += -std=c99 -W -Wall -Wextra -Wpedantic
CPPFLAGS += -I$(INCLUDE_DIR)

all: $(NAME)

tests_run: LDFLAGS += -L./
tests_run: LDLIBS  += -lbtree -lcriterion
tests_run: $(NAME) $(TESTS_NAME)

$(NAME): $(OBJ)
	@echo "Compressing $@..."
	@ar rcs $@ $(OBJ)

$(TESTS_NAME): $(TESTS_OBJ)
	@echo "Linking $@"
	@gcc -o$@ $^ $(LDFLAGS) $(LDLIBS)
	@./$(TESTS_NAME)

$(BUILD_INTERMEDIATES_DIR)/%.o: %.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@$(CC) -c -o$@ $< $(CPPFLAGS) $(CFLAGS)

clean:
	@echo "Removing intermediates files..."
	@rm -rf $(BUILD_INTERMEDIATES_DIR)

fclean: clean
	@echo "Removing binary..."
	@rm -f $(NAME)
	@rm -f $(TESTS_NAME)

re: fclean all

.PHONY: all tests_run clean fclean re

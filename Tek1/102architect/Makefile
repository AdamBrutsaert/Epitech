##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

# Directories
BUILD_OBJ_DIR := build-obj
INCLUDE_DIR   := include
SRC_DIR       := src

# Target
NAME := 102architect

SRC := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ := $(SRC:$(SRC_DIR)/%.c=$(BUILD_OBJ_DIR)/%.o)

# Compiler
CFLAGS   := -std=c99 -W -Wall -Wextra -Wpedantic -g
CPPFLAGS := -I$(INCLUDE_DIR)
LDLIBS   := -lm

# Phony Rules
all: $(NAME)

clean:
	@rm -rf $(BUILD_OBJ_DIR)
	@rm -rf $(BUILD_DEP_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run

# Rules
$(NAME): $(OBJ)
	@$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(BUILD_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

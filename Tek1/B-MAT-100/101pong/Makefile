##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

# Directories
BUILD_OBJ_DIR := ./build-obj
SRC_DIR       := ./src
INCLUDE_DIR   := ./include

# Target
NAME := 101pong
SRC  := main.c pong.c
OBJ  := $(SRC:%.c=$(BUILD_OBJ_DIR)/%.o)

# Compiler
CPPFLAGS := -I$(INCLUDE_DIR)
CFLAGS   := -std=c99 -W -Wall -Wextra -Wpedantic
LDFLAGS  :=
LDLIBS   := -lm

# Phony Rules
all: $(NAME)

clean:
	@echo "Removing intermediates files..."
	@rm -rf $(BUILD_OBJ_DIR)

fclean: clean
	@echo "Removing binary..."
	@rm -f $(NAME)

re: fclean all

# Rules
$(NAME): $(OBJ)
	@echo "Linking $@..."
	@gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(BUILD_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@gcc -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

# Directories
BUILD_OBJ_DIR := build-obj
BUILD_DEP_DIR := build-dep
INCLUDE_DIR   := include
SRC_DIR       := src

# Target
NAME := my_hunter

SRC := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ := $(SRC:$(SRC_DIR)/%.c=$(BUILD_OBJ_DIR)/%.o)
DEP := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DEP_DIR)/%.d)

# Compiler
CFLAGS   := -W -Wall -Wextra -Wpedantic
CPPFLAGS := -I$(INCLUDE_DIR)
LDLIBS   := -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

# Phony Rules
all: $(NAME)

clean:
	@rm -rf $(BUILD_OBJ_DIR)
	@rm -rf $(BUILD_DEP_DIR)

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run

# Rules
$(NAME): $(DEP) $(OBJ)
	@$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(BUILD_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

$(BUILD_DEP_DIR)/%.d: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $< $(CPPFLAGS) $(CFLAGS) -MM -MP -MQ \
		$(BUILD_OBJ_DIR)/$(patsubst %.c,%.o,$(notdir $<))
	@sed -i "1s/^/$(subst /,\/,$@) /" $@

-include $(wildcard $(DEP))

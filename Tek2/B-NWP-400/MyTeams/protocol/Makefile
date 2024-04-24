##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

################################### Shared ####################################

SHARED_BUILD_DIR := ../build/protocol
SHARED_OBJ_DIR   := $(SHARED_BUILD_DIR)/objects
SHARED_DEP_DIR   := $(SHARED_BUILD_DIR)/dependencies

SHARED_CPPFLAGS := -iquote include -iquote ../my/include
SHARED_CFLAGS   := -std=gnu2x -Wall -Wextra -Werror

###############################################################################

################################### Release ###################################

RELEASE_NAME := ../libprotocol.a

RELEASE_SRC_DIR := src
RELEASE_OBJ_DIR := $(SHARED_OBJ_DIR)/release
RELEASE_DEP_DIR := $(SHARED_DEP_DIR)/release

RELEASE_SRC := $(shell find $(RELEASE_SRC_DIR) -name "*.c")
RELEASE_OBJ := $(RELEASE_SRC:$(RELEASE_SRC_DIR)/%.c=$(RELEASE_OBJ_DIR)/%.o)
RELEASE_DEP := $(RELEASE_SRC:$(RELEASE_SRC_DIR)/%.c=$(RELEASE_DEP_DIR)/%.d)

RELEASE_CPPFLAGS :=
RELEASE_CFLAGS   :=

###############################################################################

#################################### Debug ####################################

DEBUG_NAME  := ../libprotocol-debug.a

DEBUG_SRC_DIR := src
DEBUG_OBJ_DIR := $(SHARED_OBJ_DIR)/debug
DEBUG_DEP_DIR := $(SHARED_DEP_DIR)/debug

DEBUG_SRC := $(shell find $(DEBUG_SRC_DIR) -name "*.c")
DEBUG_OBJ := $(DEBUG_SRC:$(DEBUG_SRC_DIR)/%.c=$(DEBUG_OBJ_DIR)/%.o)
DEBUG_DEP := $(DEBUG_SRC:$(DEBUG_SRC_DIR)/%.c=$(DEBUG_DEP_DIR)/%.d)

DEBUG_CPPFLAGS :=
DEBUG_CFLAGS   := -g --coverage -fprofile-abs-path

###############################################################################

#################################### Tests ####################################

TESTS_NAME := ../libprotocol-unit_tests

TESTS_SRC_DIR := ../tests/protocol/src
TESTS_OBJ_DIR := $(SHARED_OBJ_DIR)/tests
TESTS_DEP_DIR := $(SHARED_DEP_DIR)/tests

TESTS_SRC := $(shell find $(TESTS_SRC_DIR) -name "*.c")
TESTS_OBJ := $(TESTS_SRC:$(TESTS_SRC_DIR)/%.c=$(TESTS_OBJ_DIR)/%.o)
TESTS_OBJ += $(filter-out $(DEBUG_OBJ_DIR)/main.o, $(DEBUG_OBJ))
TESTS_DEP := $(TESTS_SRC:$(TESTS_SRC_DIR)/%.c=$(TESTS_DEP_DIR)/%.d)

TESTS_CPPFLAGS := -iquote ../tests/protocol/include
TESTS_CFLAGS   :=
TESTS_LDFLAGS  := -L..
TESTS_LDLIBS   := -lmy-debug -luuid -lgcov -lcriterion

###############################################################################

################################# Phony Rules #################################

all: release

clean:
	@rm -rf $(SHARED_BUILD_DIR)

fclean: clean
	@rm -f $(RELEASE_NAME) $(DEBUG_NAME) $(TESTS_NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all

release: $(RELEASE_NAME)

debug: $(DEBUG_NAME)

tests: $(TESTS_NAME)

tests_run: tests
	@./$(TESTS_NAME)

.PHONY: all clean fclean re release debug tests tests_run

###############################################################################

################################ Release Rules ################################

$(RELEASE_NAME): $(RELEASE_OBJ)
	@printf "%b\n" "\033[35mArchiving $@...\033[0m"
	@ar rc $@ $^

$(RELEASE_OBJ_DIR)/%.o: $(RELEASE_SRC_DIR)/%.c $(RELEASE_DEP_DIR)/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(RELEASE_DEP_DIR)/$*.d)
	@printf "%b\n" "\033[34mCompiling $<...\033[0m"
	@gcc -c $< -o $@ \
		$(SHARED_CPPFLAGS) $(RELEASE_CPPFLAGS) \
		$(SHARED_CFLAGS) $(RELEASE_CFLAGS) \
		-MT $@ -MMD -MP -MF $(RELEASE_DEP_DIR)/$*.d

$(RELEASE_DEP):

-include $(RELEASE_DEP)

###############################################################################

################################# Debug Rules #################################

$(DEBUG_NAME): $(DEBUG_OBJ)
	@printf "%b\n" "\033[35mArchiving $@...\033[0m"
	@ar rc $@ $^

$(DEBUG_OBJ_DIR)/%.o: $(DEBUG_SRC_DIR)/%.c $(DEBUG_DEP_DIR)/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEBUG_DEP_DIR)/$*.d)
	@printf "%b\n" "\033[34mCompiling $<...\033[0m"
	@gcc -c $< -o $@ \
		$(SHARED_CPPFLAGS) $(DEBUG_CPPFLAGS) \
		$(SHARED_CFLAGS) $(DEBUG_CFLAGS) \
		-MT $@ -MMD -MP -MF $(DEBUG_DEP_DIR)/$*.d

$(DEBUG_DEP):

-include $(DEBUG_DEP)

###############################################################################

################################# Tests Rules #################################

$(TESTS_NAME): $(TESTS_OBJ)
	@printf "%b\n" "\033[35mLinking $@...\033[0m"
	@gcc $^ -o $@ \
		$(SHARED_LDFLAGS) $(TESTS_LDFLAGS) \
		$(SHARED_LDLIBS) $(TESTS_LDLIBS)

$(TESTS_OBJ_DIR)/%.o: $(TESTS_SRC_DIR)/%.c $(TESTS_DEP_DIR)/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(TESTS_DEP_DIR)/$*.d)
	@printf "%b\n" "\033[34mCompiling $<...\033[0m"
	@gcc -c $< -o $@ \
		$(SHARED_CPPFLAGS) $(TESTS_CPPFLAGS) \
		$(SHARED_CFLAGS) $(TESTS_CFLAGS) \
		-MT $@ -MMD -MP -MF $(TESTS_DEP_DIR)/$*.d

$(TESTS_DEP):

-include $(TESTS_DEP)

###############################################################################

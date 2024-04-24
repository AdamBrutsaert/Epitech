##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

################################### Shared ####################################

SHARED_BUILD_DIR := ../build/cli
SHARED_OBJ_DIR   := $(SHARED_BUILD_DIR)/objects
SHARED_DEP_DIR   := $(SHARED_BUILD_DIR)/dependencies

SHARED_CPPFLAGS := -iquote include -iquote ../my/include \
                   -iquote ../protocol/include -iquote ../libs
SHARED_CFLAGS   := -std=gnu2x -Wall -Wextra -Werror
SHARED_LDFLAGS  := -L.. -L../libs/myteams
SHARED_LDLIBS   := -lmyteams

###############################################################################

################################### Release ###################################

RELEASE_NAME := ../myteams_cli

RELEASE_SRC_DIR := src
RELEASE_OBJ_DIR := $(SHARED_OBJ_DIR)/release
RELEASE_DEP_DIR := $(SHARED_DEP_DIR)/release

RELEASE_SRC := $(shell find $(RELEASE_SRC_DIR) -name "*.c")
RELEASE_OBJ := $(RELEASE_SRC:$(RELEASE_SRC_DIR)/%.c=$(RELEASE_OBJ_DIR)/%.o)
RELEASE_DEP := $(RELEASE_SRC:$(RELEASE_SRC_DIR)/%.c=$(RELEASE_DEP_DIR)/%.d)

RELEASE_CPPFLAGS :=
RELEASE_CFLAGS   :=
RELEASE_LDFLAGS  :=
RELEASE_LDLIBS   := -lprotocol -lmy

###############################################################################

#################################### Debug ####################################

DEBUG_NAME  := ../myteams_cli-debug

DEBUG_SRC_DIR := src
DEBUG_OBJ_DIR := $(SHARED_OBJ_DIR)/debug
DEBUG_DEP_DIR := $(SHARED_DEP_DIR)/debug

DEBUG_SRC := $(shell find $(DEBUG_SRC_DIR) -name "*.c")
DEBUG_OBJ := $(DEBUG_SRC:$(DEBUG_SRC_DIR)/%.c=$(DEBUG_OBJ_DIR)/%.o)
DEBUG_DEP := $(DEBUG_SRC:$(DEBUG_SRC_DIR)/%.c=$(DEBUG_DEP_DIR)/%.d)

DEBUG_CPPFLAGS :=
DEBUG_CFLAGS   := -g --coverage -fprofile-abs-path
DEBUG_LDFLAGS  :=
DEBUG_LDLIBS   := -lprotocol-debug -lmy-debug -lgcov -lcriterion

###############################################################################

#################################### Tests ####################################

TESTS_NAME := ../myteams_cli-unit_tests

TESTS_SRC_DIR := ../tests/cli/src
TESTS_OBJ_DIR := $(SHARED_OBJ_DIR)/tests
TESTS_DEP_DIR := $(SHARED_DEP_DIR)/tests

TESTS_SRC := $(shell find $(TESTS_SRC_DIR) -name "*.c")
TESTS_OBJ := $(TESTS_SRC:$(TESTS_SRC_DIR)/%.c=$(TESTS_OBJ_DIR)/%.o)
TESTS_OBJ += $(filter-out $(DEBUG_OBJ_DIR)/main.o, $(DEBUG_OBJ))
TESTS_DEP := $(TESTS_SRC:$(TESTS_SRC_DIR)/%.c=$(TESTS_DEP_DIR)/%.d)

TESTS_CPPFLAGS := -iquote ../tests/cli/include
TESTS_CFLAGS   :=
TESTS_LDFLAGS  :=
TESTS_LDLIBS   := -lprotocol-debug -lmy-debug -lgcov -lcriterion

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
	@LD_LIBRARY_PATH=../libs/myteams ./$(TESTS_NAME)

.PHONY: all clean fclean re release debug tests tests_run

###############################################################################

################################ Release Rules ################################

$(RELEASE_NAME): $(RELEASE_OBJ)
	@printf "%b\n" "\033[35mLinking $@...\033[0m"
	@gcc $^ -o $@ \
		$(SHARED_LDFLAGS) $(RELEASE_LDFLAGS) \
		$(SHARED_LDLIBS) $(RELEASE_LDLIBS)

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
	@printf "%b\n" "\033[35mLinking $@...\033[0m"
	@gcc $^ -o $@ \
		$(SHARED_LDFLAGS) $(DEBUG_LDFLAGS) \
		$(SHARED_LDLIBS) $(DEBUG_LDLIBS)

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

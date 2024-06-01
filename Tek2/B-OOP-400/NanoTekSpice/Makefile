##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

################################### Global ####################################

# Directories
BUILD_DIR := build

###############################################################################

################################### Release ###################################

# Name
RELEASE_NAME := nanotekspice

# Directories
RELEASE_SRC_DIR   := src
RELEASE_BUILD_DIR := $(BUILD_DIR)/release
RELEASE_OBJ_DIR   := $(RELEASE_BUILD_DIR)/objects
RELEASE_DEP_DIR   := $(RELEASE_BUILD_DIR)/dependencies

# Files
RELEASE_SRC := $(shell find $(RELEASE_SRC_DIR) -name "*.cpp" -type f)
RELEASE_OBJ := $(RELEASE_SRC:$(RELEASE_SRC_DIR)/%.cpp=$(RELEASE_OBJ_DIR)/%.o)
RELEASE_DEP := $(RELEASE_SRC:$(RELEASE_SRC_DIR)/%.cpp=$(RELEASE_DEP_DIR)/%.d)

# Flags
RELEASE_CPPFLAGS := -iquote include
RELEASE_CXXFLAGS := -std=c++20 -Wall -Wextra -Werror
RELEASE_LDFLAGS  :=
RELEASE_LDLIBS   :=

###############################################################################

#################################### Debug ####################################

# Name
DEBUG_NAME := nanotekspice_debug

# Directories
DEBUG_SRC_DIR   := src
DEBUG_BUILD_DIR := $(BUILD_DIR)/debug
DEBUG_OBJ_DIR   := $(DEBUG_BUILD_DIR)/objects
DEBUG_DEP_DIR   := $(DEBUG_BUILD_DIR)/dependencies

# Files
DEBUG_SRC := $(shell find $(DEBUG_SRC_DIR) -name "*.cpp" -type f)
DEBUG_OBJ := $(DEBUG_SRC:$(DEBUG_SRC_DIR)/%.cpp=$(DEBUG_OBJ_DIR)/%.o)
DEBUG_DEP := $(DEBUG_SRC:$(DEBUG_SRC_DIR)/%.cpp=$(DEBUG_DEP_DIR)/%.d)

# Flags
DEBUG_CPPFLAGS := -iquote include
DEBUG_CXXFLAGS := -std=c++20 -Wall -Wextra -Werror -g --coverage
DEBUG_LDFLAGS  :=
DEBUG_LDLIBS   := -lgcov

###############################################################################

#################################### Tests ####################################

# Name
TESTS_NAME := unit_tests

# Directories
TESTS_SRC_DIR   := tests
TESTS_BUILD_DIR := $(BUILD_DIR)/tests
TESTS_OBJ_DIR   := $(TESTS_BUILD_DIR)/objects
TESTS_DEP_DIR   := $(TESTS_BUILD_DIR)/dependencies

# Files
TESTS_SRC := $(shell find $(TESTS_SRC_DIR) -name "*.cpp" -type f)
TESTS_OBJ := $(filter-out $(DEBUG_OBJ_DIR)/main.o, $(DEBUG_OBJ))
TESTS_OBJ += $(TESTS_SRC:$(TESTS_SRC_DIR)/%.cpp=$(TESTS_OBJ_DIR)/%.o)
TESTS_DEP := $(TESTS_SRC:$(TESTS_SRC_DIR)/%.cpp=$(TESTS_DEP_DIR)/%.d)

# Flags
TESTS_CPPFLAGS := -iquote include
TESTS_CXXFLAGS := -std=c++20 -Wall -Wextra -Werror -g --coverage
TESTS_LDFLAGS  :=
TESTS_LDLIBS   := -lgcov -lcriterion

###############################################################################

################################# Phony Rules #################################

all: release

tests_run: tests
	@./$(TESTS_NAME)

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(RELEASE_NAME) $(DEBUG_NAME) $(TESTS_NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all

release: $(RELEASE_NAME)

debug: $(DEBUG_NAME)

tests: $(TESTS_NAME)

.PHONY: all tests_run clean fclean re release debug tests

###############################################################################

################################ Release Rules ################################

$(RELEASE_NAME): $(RELEASE_OBJ)
	@g++ -o $@ $^ $(RELEASE_LDFLAGS) $(RELEASE_LDLIBS)

$(RELEASE_OBJ_DIR)/%.o: $(RELEASE_SRC_DIR)/%.cpp $(RELEASE_DEP_DIR)/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(RELEASE_DEP_DIR)/$*.d)
	@g++ -c -o $@ $< $(RELEASE_CPPFLAGS) $(RELEASE_CXXFLAGS) \
		-MT $@ -MMD -MP -MF $(RELEASE_DEP_DIR)/$*.d

$(RELEASE_DEP):

include $(RELEASE_DEP)

###############################################################################

################################# Debug Rules #################################

$(DEBUG_NAME): $(DEBUG_OBJ)
	@g++ -o $@ $^ $(DEBUG_LDFLAGS) $(DEBUG_LDLIBS)

$(DEBUG_OBJ_DIR)/%.o: $(DEBUG_SRC_DIR)/%.cpp $(DEBUG_DEP_DIR)/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEBUG_DEP_DIR)/$*.d)
	@g++ -c -o $@ $< $(DEBUG_CPPFLAGS) $(DEBUG_CXXFLAGS) \
		-MT $@ -MMD -MP -MF $(DEBUG_DEP_DIR)/$*.d

$(DEBUG_OBJ_DIR) $(DEBUG_DEP_DIR):
	@mkdir -p $@

$(DEBUG_DEP):

include $(DEBUG_DEP)

###############################################################################

################################# Tests Rules #################################

$(TESTS_NAME): $(TESTS_OBJ)
	@g++ -o $@ $^ $(TESTS_LDFLAGS) $(TESTS_LDLIBS)

$(TESTS_OBJ_DIR)/%.o: $(TESTS_SRC_DIR)/%.cpp $(TESTS_DEP_DIR)/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(TESTS_DEP_DIR)/$*.d)
	@g++ -c -o $@ $< $(TESTS_CPPFLAGS) $(TESTS_CXXFLAGS) \
		-MT $@ -MMD -MP -MF $(TESTS_DEP_DIR)/$*.d

$(TESTS_OBJ_DIR) $(TESTS_DEP_DIR):
	@mkdir -p $@

$(TESTS_DEP):

include $(TESTS_DEP)

###############################################################################

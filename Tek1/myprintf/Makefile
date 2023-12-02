##
## EPITECH PROJECT, 2022
## my_printf
## File description:
## Makefile for my_printf
##

###############################################################################
#                                                                             #
#                                  .-------.                                  #
#                                 _|~~ ~~  |_                                 #
#                               =(_|_______|_)=                               #
#                                 |:::::::::|                                 #
#                                 |:::::::[]|                                 #
#                                 |o=======.|                                 #
#                                 `"""""""""`                                 #
#              _                                  _ _                         #
#             | |                                (_) |                        #
#             | |_ _   _ _ __   _____      ___ __ _| |_ ___ _ __              #
#             | __| | | | '_ \ / _ \ \ /\ / / '__| | __/ _ \ '__|             #
#             | |_| |_| | |_) |  __/\ V  V /| |  | | ||  __/ |                #
#              \__|\__, | .__/ \___| \_/\_/ |_|  |_|\__\___|_|                #
#                   __/ | |                                                   #
#                  |___/|_|                                                   #
#                                                                             #
#                                                                             #
#                            ma_machine_à_écrire_f                            #
#                                                                             #
#                       Adam Brutsaert - Yanis Zeghiche                       #
#                                                                             #
###############################################################################

###############################  CONFIGURATION  ###############################

# Directories
BUILD_INT_DIR := ./build-int
INCLUDE_DIR   := ./include
SRC_DIR       := ./src
TESTS_DIR     := ./tests

# Target
NAME := libmy.a
SRC  := my_printf.c
SRC  += $(addprefix my/my_, memmove.c realloc.c strlen.c strncmp.c putchar.c)
SRC  += $(addprefix my/my_, putstr_err.c putnchar.c putnbr_base.c)
SRC  += $(addprefix my/my_, min.c max.c putnbr_base_precision.c abs.c)
SRC  += $(addprefix my/my_, digit_count.c pow.c)
SRC  += $(addprefix parsing/, argument.c format.c variant.c context.c)
SRC  += $(addprefix parsing/parse_, string.c format.c positional_arg.c)
SRC  += $(addprefix parsing/parse_, character_flag.c width.c precision.c)
SRC  += $(addprefix parsing/parse_, length_modifier.c conversion.c)
SRC  += $(addprefix parsing/resolve_, arguments.c formats.c)
SRC  += $(addprefix printing/print_, di.c u.c f.c f_maj.c e.c e_maj.c g.c)
SRC  += $(addprefix printing/print_, g_maj.c b.c o.c x.c x_maj.c a.c a_maj.c)
SRC  += $(addprefix printing/print_, c.c lc.c s.c ls.c s_maj.c ls_maj.c n.c)
SRC  += $(addprefix printing/print_, p.c percentage.c error.c utils.c)

TESTS_NAME := libmytests
TESTS_SRC  := $(addprefix conversions/test_, simple_string.c)
TESTS_SRC  += $(addprefix conversions/test_conv_, c.c d.c e.c f.c g.c i.c)
TESTS_SRC  += $(addprefix conversions/test_conv_, n.c o.c p.c error.c)
TESTS_SRC  += $(addprefix conversions/test_conv_, percentage.c s.c u.c x.c b.c)
TESTS_SRC  += $(addprefix conversions/test_conv_, S.c)
TESTS_SRC  += $(addprefix modifiers/test_mod_, dash.c zero.c space.c diez.c)
TESTS_SRC  += $(addprefix modifiers/test_mod_, plus.c)
TESTS_SRC  += $(addprefix format/test_format_, l.c ll.c)
TESTS_SRC  += $(addprefix precision/test_, precision.c)
TESTS_SRC  += $(addprefix padding/test_, padding.c padding2.c)

###############################################################################

###############################  MISCELLANEOUS  ###############################

# Directories
BUILD_REGULAR_INT_DIR := $(BUILD_INT_DIR)/regular
BUILD_COVER_INT_DIR   := $(BUILD_INT_DIR)/coverage
BUILD_TESTS_INT_DIR   := $(BUILD_INT_DIR)/tests

# Target
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(BUILD_REGULAR_INT_DIR)/%.o)

TESTS_SRC := $(addprefix $(TESTS_DIR)/, $(TESTS_SRC))
TESTS_OBJ := $(TESTS_SRC:$(TESTS_DIR)/%.c=$(BUILD_TESTS_INT_DIR)/%.o)
TESTS_OBJ += $(SRC:$(SRC_DIR)/%.c=$(BUILD_COVER_INT_DIR)/%.o)

# Compiler
CFLAGS   += -std=c99 -W -Wall -Wextra -Wpedantic -Wno-unused-parameter
CPPFLAGS += -I$(INCLUDE_DIR)

###############################################################################

################################  PHONY RULES  ################################

all: $(NAME)

clean:
	@echo "Cleaning temporary files..."
	@rm -rf $(BUILD_REGULAR_INT_DIR)
	@rm -rf $(BUILD_COVERAGE_INT_DIR)
	@rm -rf $(BUILD_TESTS_INT_DIR)
	@$(if $(filter-out ., $(BUILD_INT_DIR)), rm -rf $(BUILD_INT_DIR))

fclean: clean
	@echo "Cleaning binary files..."
	@rm -f $(NAME)
	@rm -f $(TESTS_NAME)
	@$(if $(filter-out ., $(BUILD_DIR)), rm -rf $(BUILD_DIR))

re: fclean all

unit_tests: $(TESTS_NAME)

run_tests: unit_tests
	@./$(TESTS_NAME)

.PHONY: all clean fclean re unit_tests run_tests

###############################################################################

###################################  RULES  ###################################

# Binaries
$(NAME): $(OBJ)
	@echo "Compressing $@..."
	@mkdir -p $(dir $@)
	@ar rcs $@ $^

$(TESTS_NAME): LDLIBS += -lgcov -lcriterion
$(TESTS_NAME): $(TESTS_OBJ)
	@echo "Linking $@..."
	@mkdir -p $(dir $@)
	@gcc $^ -o $@ $(LDFLAGS) $(LDLIBS)

# Intermediates
$(BUILD_REGULAR_INT_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

$(BUILD_COVER_INT_DIR)/%.o: CFLAGS += --coverage -g
$(BUILD_COVER_INT_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $< with coverage enabled..."
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

$(BUILD_TESTS_INT_DIR)/%.o: $(TESTS_DIR)/%.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

###############################################################################

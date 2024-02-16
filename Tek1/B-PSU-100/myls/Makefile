##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

###############################################################################
#                                    _                                        #
#                           /\      | |                                       #
#                          /  \   __| | __ _ _ __ ___                         #
#                         / /\ \ / _` |/ _` | '_ ` _ \                        #
#                        / ____ \ (_| | (_| | | | | | |                       #
#                       /_/    \_\__,_|\__,_|_| |_| |_|                       #
#                                                                             #
#                 ____             _                       _                  #
#                |  _ \           | |                     | |                 #
#                | |_) |_ __ _   _| |_ ___  __ _  ___ _ __| |_                #
#                |  _ <| '__| | | | __/ __|/ _` |/ _ \ '__| __|               #
#                | |_) | |  | |_| | |_\__ \ (_| |  __/ |  | |_                #
#                |____/|_|   \__,_|\__|___/\__,_|\___|_|   \__|               #
#                                                                             #
#                             _                                               #
#                             \`*-.                                           #
#                              )  _`-.                                        #
#                             .  : `. .                                       #
#                             : _   '  \                                      #
#                             ; *` _.   `*-._                                 #
#                             `-.-'          `-.                              #
#                               ;       `       `.                            #
#                               :.       .        \                           #
#                               . \  .   :   .-'   .                          #
#                               '  `+.;  ;  '      :                          #
#                               :  '  |    ;       ;-.                        #
#                               ; '   : :`-:     _.`* ;                       #
#                            .*' /  .*' ; .*`- +'  `*'                        #
#                            `*-*   `*-*  `*-*'                               #
#                                                                             #
###############################################################################

################################ Configuration ################################

# Directories
BUILD_OBJ_DIR := ./build-obj
BUILD_DEP_DIR := ./build-dep

INCLUDE_DIR := ./include
SRC_DIR     := ./src

# Target
NAME := my_ls
SRC  := main.c
SRC  += $(addprefix memory/, my_memcpy.c my_memmove.c my_realloc.c)
SRC  += $(addprefix string/, my_strcmp.c my_strcpy.c my_strdup.c my_strlen.c)
SRC  += $(addprefix string/, my_strcat.c)
SRC  += $(addprefix stdio/, my_printc.c my_prints.c my_eprintc.c my_eprints.c)
SRC  += $(addprefix stdio/, my_putunbr.c)
SRC  += $(addprefix argp/, argp.c flag.c get_flag.c)
SRC  += $(addprefix ls/, configuration.c ls.c process.c print.c)
SRC  += $(addprefix file/, file.c file_vector.c file_cmp.c file_vector_sort.c)

###############################################################################

################################ Miscellaneous ################################

# Target
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
DEP := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DEP_DIR)/%.d)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(BUILD_OBJ_DIR)/%.o)

# Compiler
CPPFLAGS := -I$(INCLUDE_DIR) -D_XOPEN_SOURCE=500 -D__USE_XOPEN
CFLAGS   := -std=c99 -W -Wall -Wextra -Wpedantic -g

LDFLAGS  :=
LDLIBS   :=

###############################################################################

################################# Phony Rules #################################

all: $(NAME)

clean:
	@echo -e "\033[31m[$(NAME)] Removing temporary files...\033[0m"
	@rm -rf $(BUILD_DEP_DIR)
	@rm -rf $(BUILD_OBJ_DIR)

fclean: clean
	@echo -e "\033[31m[$(NAME)] Removing binary...\033[0m"
	@rm -f $(NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run

###############################################################################

#################################### Rules ####################################

$(NAME): $(DEP) $(OBJ)
	@echo -e "\033[32m[$(NAME)] Linking $@...\033[0m"
	@$(CC) -o $(NAME) $(filter-out %.d requirements, $^) $(LDFLAGS) $(LDLIBS)

$(BUILD_DEP_DIR)/%.d: $(SRC_DIR)/%.c
	@echo -e "\033[35m[$(NAME)] Retrieving dependencies of $<...\033[0m"
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $< $(CPPFLAGS) -MM -MP -MQ \
		$(BUILD_OBJ_DIR)/$(patsubst %.c,%.o,$(notdir $<))
	@sed -i "1s/^/$(subst /,\/,$@) /" $@

$(BUILD_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo -e "\033[34m[$(NAME)] Compiling $<...\033[0m"
	@mkdir -p $(dir $@)
	@$(CC) -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

-include $(wildcard $(DEP))

###############################################################################

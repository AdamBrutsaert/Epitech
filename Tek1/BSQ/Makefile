##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for BSQ
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

# Directories
OBJ_DIR       := ./obj
SRC_DIR       := ./src
INCLUDE_DIR   := ./include

# Target
NAME := bsq
SRC  := main.c file.c bsq.c bsq_algo.c bsq_show.c

# Miscellaneous
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler
CPPFLAGS := -I$(INCLUDE_DIR)
CFLAGS   := -std=c99 -W -Wall -Wextra -Wpedantic -fno-builtin-function -g

# Phony rules
all: $(NAME)

clean:
	@echo "Removing object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Removing binary..."
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run

# Rules
$(NAME): $(OBJ)
	@echo "Linking $@..."
	@$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

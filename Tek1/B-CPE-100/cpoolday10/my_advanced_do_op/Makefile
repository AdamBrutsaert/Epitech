##
## EPITECH PROJECT, 2022
## my_advanced_do_op Makefile
## File description:
## my_advanced_do_op Makefile
##

# Directories
INCLUDE_DIR             := ../include
LIB_DIR                 := ../lib

# Target
NAME := my_advanced_do-op
SRC  := main.c operation.c
OBJ  := $(SRC:%.c=%.o)

# Compiler
CFLAGS   += -std=c99 -W -Wall -Wextra -Wpedantic
CPPFLAGS += -I$(INCLUDE_DIR)
LDFLAGS  += -L$(LIB_DIR)
LDLIBS   += -lmy

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@..."
	@$(CC) -o$@ $^ $(LDFLAGS) $(LDLIBS)

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) -c $(CPPFLAGS) $(CFLAGS) -I$(INCLUDE_DIR) -o$@ $<

clean:
	@echo "Removing intermediates files..."
	@rm -f *.o

fclean: clean
	@echo "Removing executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

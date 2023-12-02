##
## EPITECH PROJECT, 2022
## do_op Makefile
## File description:
## do_op Makefile
##

# Directories
INCLUDE_DIR             := ../include
LIB_DIR                 := ../lib

# Target
NAME := do-op
SRC  := do_op.c calculation.c
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

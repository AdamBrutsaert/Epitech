##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

NAME := corewar_global

all: $(NAME)

clean:
	make clean -C asm/
	make clean -C corewar/

fclean:
	make fclean -C asm/
	make fclean -C corewar/

re:
	make re -C asm/
	make re -C corewar/

$(NAME):
	make -C asm/
	make -C corewar/

.PHONY: all clean fclean re

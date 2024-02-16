##
## EPITECH PROJECT, 2022
## my Makefile
## File description:
## my Makefile
##

all:
	@gcc -c *.c
	@ar rcs libmy.a *.o
	@cp libmy.a ../
	@mkdir -p ../../include
	@cp my.h ../../include

clean:
	@rm -f *.o

.PHONY: all clean

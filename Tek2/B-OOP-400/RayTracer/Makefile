##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

all:
	@cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
	@cmake --build build -j16

debug:
	@cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build
	@cmake --build build -j16

clean:
	@rm -rf build

fclean: clean
	@rm -f raytracer

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all debug clean fclean re

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

LIBRARIES := libraries/sfml libraries/ncurses libraries/sdl2
GAMES     := games/snake games/nibbler

all: core games graphicals

clean:
	@for dir in core $(LIBRARIES) $(GAMES); do \
		$(MAKE) -s -C $$dir clean; \
	done
	@rm -rf build

fclean:
	@for dir in core $(LIBRARIES) $(GAMES); do \
		$(MAKE) -s -C $$dir fclean; \
	done
	@rm -rf build
	@rm -rf lib

re:
	@for dir in core $(LIBRARIES) $(GAMES); do \
		$(MAKE) -s -C $$dir re; \
	done

core:
	@$(MAKE) -s -C core

games:
	@for dir in $(GAMES); do \
		$(MAKE) -s -C $$dir; \
	done

graphicals:
	@for dir in $(LIBRARIES); do \
		$(MAKE) -s -C $$dir; \
	done

.PHONY: all clean fclean re core games graphicals
